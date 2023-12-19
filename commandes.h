#ifndef COMMANDES_H_
#define COMMANDES_H_

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

void PING(int client_fd);
void SET(int client_fd, char* buff, hash_table* ht, int fd);
void GET(int client_fd, char* buff, hash_table* ht);
void DEL(int client_fd, char* buff, hash_table* ht, int fd);
void ACL_USERS(int client_fd);
void HELP(int client_fd, char* buff);
void COPY(int client_fd, char* buff, hash_table* ht, int fd);
void ECHO(int client_fd, char* buff);
void EXIT(int client_fd);

#endif