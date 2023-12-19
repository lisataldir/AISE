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
void SET(int client_fd, char* buff, hash_table* ht);
void GET(int client_fd, char* buff, hash_table* ht);
void DEL(int client_fd, char* buff, hash_table* ht);
void ACL_USERS(int client_fd);
void HELP(int client_fd, char* buff);
void COPY(int client_fd, char* buff, hash_table* ht);
void ECHO(int client_fd, char* buff);
void INCR(int client_fd, char* buff, hash_table* ht);
void SAVE(int client_fd, hash_table* ht, struct th_info* ctx);

#endif