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
#include "commandes.h"



void * handle_client(void * pctx){

    // Création hash table pour les clés/valeurs
    hash_table* ht_key = ht_new();

    // Threads
	struct th_info * ctx = (struct th_info *)pctx;
	int client_fd = ctx->fd;
    printf("Connection client %d\n", ctx->i);

    // Création du fichier où l'on va stocker les variables, un par client
    char fichier[128];
    snprintf(fichier, 128, "../variables%d.txt", ctx->i);
    int fd = open(fichier, O_RDWR | O_CREAT, 0666);
    if (fd < 0){
        perror("open");
    }

    // Ouverture du fichier où l'on stocke les noms des clients
    int fd_bis = open("../noms.txt", O_RDWR | O_APPEND, 0666);
    char name[30];
    write(client_fd, "$ NOM : ", 8); 
    int rd = read(client_fd, name, sizeof(name) - 1);
    name[rd] = '\0';
    write(fd_bis, name, strlen(name));

    char buff[128];
    snprintf(buff, 128, "BIENVENUE %s", name);
    write(client_fd, buff, strlen(buff));

    int ret;
    write(client_fd, "> ", 2);

    while((ret = read(client_fd, buff, 128)) != 0){

        if (strncasecmp(buff, "ping", 4) == 0) {
            PING(client_fd);
        } else if (strncasecmp(buff, "set", 3) == 0) {
            SET(client_fd, buff, ht_key, fd);
        } else if (strncasecmp(buff, "get", 3) == 0) {
            GET(client_fd, buff, ht_key);
        } else if (strncasecmp(buff, "del", 3) == 0) {
            DEL(client_fd, buff, ht_key, fd);
        } else if (strncasecmp(buff, "acl users", 9) == 0) {
            ACL_USERS(client_fd);
        } else if (strncasecmp(buff, "help", 4) == 0) {
            HELP(client_fd, buff);
        } else if (strncasecmp(buff, "copy", 4) == 0) {
            COPY(client_fd, buff, ht_key, fd);
        } else if (strncasecmp(buff, "echo", 4) == 0){
            ECHO(client_fd, buff);
        } else if (strncasecmp(buff, "exit", 4) == 0){
            write(client_fd, "Connection terminée\n", strlen("Connection terminée\n"));
            break;
        } else {
            write(client_fd, "Commande introuvable (taper help)\n", strlen("Commande introuvable (taper help)\n"));
            write(client_fd, "> ", 2);
        }
    }

    printf("Déconnection client %d\n", ctx->i);
    close(client_fd);
    free(ctx);
    del_hash_table(ht_key);
    close(fd);
    close(fd_bis);
	return NULL;
}

