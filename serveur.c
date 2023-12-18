#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <fcntl.h>

#include "hachage.h"
#include "prime.h"

struct th_info{
	int fd;
	int i;
};

void * handle_client(void * pctx){

    // déclaration de la hash table et du fichier où l'on va stocker les variables de nos clients
    hash_table* ht = ht_new();
    int fd = open("./file.dat", O_RDWR | O_CREAT, 0600);
    if (fd < 0){
        perror("open");
    }

	struct th_info * ctx = (struct th_info *)pctx;
	int client_fd = ctx->fd;
    printf("Client %d\n", ctx->i);

    char name[30];
    write(client_fd, "$ NOM : ", 8); 
    int rd = read(client_fd, name, sizeof(name) - 1);
    name[rd] = '\0';

    char buff[128];
    snprintf(buff, 128, "BIENVENUE %s", name);
    write(client_fd, buff, strlen(buff));

    int ret;
    write(client_fd, "$ ", 2);
    while((ret = read(client_fd, buff, 128)) != 0){

        // On actualise notre fichier à chaque boucle
        save(ht, fd);

        // Commande PING
        if (strncasecmp(buff, "ping", 4) == 0) {
            write(client_fd, "PONG\n", 5);
            write(client_fd, "$ ", 2);

        // Commande SET
        } else if (strncasecmp(buff, "set ", 4) == 0) {
            int i = 4;
            int j = 0;
            char key[32], value[128];
            while (buff[i] != ' ' && buff[i] != '\0') key[j++] = buff[i++];
            key[j] = '\0';

            while (buff[i] == ' ') i++;

            j = 0;
            while (buff[i] != '\n' && buff[i] != '\0') value[j++] = buff[i++];
            value[j] = '\0';

            insert(ht, key, value);
            write(client_fd, "OK\n", 3);
            write(client_fd, "$ ", 2);

        // Commande GET
        } else if (strncasecmp(buff, "get ", 4) == 0) {
            char key[32];
            int i = 4;
            int j = 0;
            while (buff[i] != 10) key[j++] = buff[i++];
            key[j] = '\0';

            const char* value = search(ht, key);
            if (value != NULL) {
                write(client_fd, value, strlen(value));
                write(client_fd, "\n", 1);
            } else {
                write(client_fd, "Clé non trouvée\n", strlen("Clé non trouvée\n"));    
            }
            write(client_fd, "$ ", 2);

        // Commande DEL
        } else if (strncasecmp(buff, "del ", 4) == 0) {
            char key[32];
            int i = 4;
            int j = 0;
            while (buff[i] != 10) key[j++] = buff[i++];
            key[j] = '\0';
            del(ht, key);
            write(client_fd, "OK\n", 3);
            write(client_fd, "$ ", 2);

        // Sortie du programme
        } else if (strncasecmp(buff, "exit", 4) == 0) {
            break; 
        } else {
            write(client_fd, "Commande introuvable\n", strlen("Commande introuvable\n"));
            write(client_fd, "$ ", 2);
        }
    }
    close(client_fd);

    free(ctx);
    del_hash_table(ht);
    close(fd);

	return NULL;
}



int main(int argc, char const *argv[])
{
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    struct addrinfo * result = NULL;
    int ret = getaddrinfo(NULL, argv[1], &hints, &result);

    if(ret < 0)
    {
        herror("getaddrinfo");
        return 1;
    }

    int sock = 0;
    int server_ready = 0;

    struct addrinfo *tmp;
    for(tmp = result; tmp != NULL; tmp=tmp->ai_next)
    {
        sock = socket(tmp->ai_family, tmp->ai_socktype, tmp->ai_protocol);

        if(sock < 0)
        {
            perror("socket");
            continue;
        }

        if( bind(sock, tmp->ai_addr, tmp->ai_addrlen) < 0)
        {
            perror("bind");
            continue;
        }

        if( listen(sock, 10) < 0)
        {
            perror("listen");
            continue;
        }

        server_ready = 1;
        break;
    }

    if(server_ready == 0)
    {
        fprintf(stderr, "PAS SERVER READY :-'(");
        return 1;
    }


    int client_fd = -1;

    int i = 0;
    struct sockaddr_storage client_addr;  
    socklen_t client_addr_len = sizeof(client_addr); 

    while(1)
    {
        client_fd = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len);

        if(client_fd < 0)
        {
            perror("accept");
            break;
        }
	
	struct th_info * ctx = malloc(sizeof(struct th_info));
	if(ctx == NULL)
	{
		perror("malloc");
	}
	ctx->fd = client_fd;
	ctx->i = i++;

	pthread_t th;
	pthread_create(&th, NULL, handle_client, (void*)ctx);

    }

    close(sock);

    return 0;
}

