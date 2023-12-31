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
#include "serveur.h"


int main(int argc, char const *argv[])
{
    // Ici on crée le fichier où l'on va stocker le nom des clients
    int create = open("../clients/noms.txt", O_RDWR | O_CREAT, 0666);
    if (create < 0){
        perror("open");
    }

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
        fprintf(stderr, "PAS DE SERVEUR PRES");
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