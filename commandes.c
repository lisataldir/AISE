#include "commandes.h"

// Commande PING
void PING(int client_fd){
    write(client_fd, "PONG\n", 5);
    write(client_fd, "> ", 2);
}

// Commande SET
void SET(int client_fd, char* buff, hash_table* ht){
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
    write(client_fd, "> ", 2);
}

// Commande GET
void GET(int client_fd, char* buff, hash_table* ht){
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
    write(client_fd, "> ", 2);
}


// Commande DEL
void DEL(int client_fd, char* buff, hash_table* ht){
    char key[32];
    int i = 4;
    int j = 0;
    while (buff[i] != 10) key[j++] = buff[i++];
        
    key[j] = '\0';
    del(ht, key);
            
    write(client_fd, "OK\n", 3);
    write(client_fd, "> ", 2);
}

// Commande ACL USERS
void ACL_USERS(int client_fd){
    char buff[50];
    int n = 1;

    // On récupère le contenu du fichier et on le passe a client_fd
    FILE* fd = fopen("../clients/noms.txt", "r");
    while (fgets(buff, 50, fd) != 0){
        char tmp[100];
        snprintf(tmp, 100, "%d) %s",n, buff);
        write(client_fd, tmp, strlen(tmp));
        n++;
    }
    write(client_fd, "> ", 2);
}

// Commande COPY
void COPY(int client_fd, char* buff, hash_table* ht){

    // On récupère la clé et puis la valeur
    char key[32];
    int i = 5;
    int j = 0;
    while (buff[i] != '\0' && buff[i] != ' ') key[j++] = buff[i++];

    key[j] = '\0';
    char* value = search(ht, key);

    if (value != NULL) {
        while (buff[i] == ' ') i++;
        // On récupère ensuite la nouvelle clé et on l'insère dans la hash table et dans le fichier
        j = 0;

        char keybis[32];
        while (buff[i] != '\n' && buff[i] != '\0') keybis[j++] = buff[i++];
        keybis[j] = '\0';

        insert(ht, keybis, value);
        write(client_fd, "OK\n", 3);
        write(client_fd, "> ", 2);
    } else {
        write(client_fd, "Clé non trouvée\n", strlen("Clé non trouvée\n"));    
    }
}

// Commande ECHO
void ECHO(int client_fd, char* buff){
    char echo[200];
    for(int i=5; i < strlen(buff) + 1; i++) echo[i-5] = buff[i];
    write(client_fd, echo, strlen(echo));
    write(client_fd, "> ", 2);
}

// Commande INCR
void INCR(int client_fd, char* buff, hash_table* ht){
    char key[32];
    int i = 5;
    int j = 0;
    while (buff[i] != '\0' && buff[i] != '\n' && buff[i] != ' ') key[j++] = buff[i++];
    key[j] = '\0';

    char* value = search(ht, key);

    if (value != NULL) {
        int incrementedValue = atoi(value) + 1;  
        char updatedValue[12]; 
        sprintf(updatedValue, "%d", incrementedValue);
        insert(ht, key, updatedValue);
        write(client_fd, updatedValue, strlen(updatedValue) + 1);
    } else {
        write(client_fd, "Clé non trouvée\n", strlen("Clé non trouvée\n"));  
    }
    write(client_fd, "\n> ", 3);
}

void SAVE(int client_fd, hash_table* ht, struct th_info* ctx){
    // Création du fichier où l'on va stocker les variables, un par client
    char fichier[128];
    snprintf(fichier, 128, "../clients/variables%d.txt", ctx->i);
    int fd = open(fichier, O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd < 0){
        perror("open");
    }
    save(ht, fd);
    write(client_fd, "> ", 2);
    close(fd);
}

// Commande HELP
void HELP(int client_fd, char* buff){
    write(client_fd, "Commandes disponibles :\n", strlen("Commandes disponibles :\n"));
    write(client_fd, "PING\n", 6);
    write(client_fd, "SET [clé] [valeur]\n", strlen("SET [clé] [valeur]\n"));
    write(client_fd, "GET [clé]\n", strlen("GET [clé]\n"));
    write(client_fd, "DEL [clé]\n", strlen("DEL [clé]\n"));
    write(client_fd, "ACL USERS\n", 11);
    write(client_fd, "COPY [clé 1] [clé 2]\n", strlen("COPY [clé 1] [clé 2]\n"));
    write(client_fd, "ECHO [chaine de caractères]\n", strlen("ECHO [chaine de caractères]\n"));
    write(client_fd, "INCR [clé]\n", strlen("INCR [clé]\n"));
    write(client_fd, "SAVE\n", 6);
    write(client_fd, "SHUTDOWN\n", 10);
    write(client_fd, "> ", 2);
}
        

