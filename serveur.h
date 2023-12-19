#ifndef SERVEUR_H_
#define SERVEUR_H_

struct th_info{
	int fd;  // descripteur de fichier de la socket client
	int i;	 // numéro du client
};

void * handle_client(void * pctx);

#endif