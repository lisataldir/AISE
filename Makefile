CC=gcc
LFLAGS=-lm

all: serveur

serveur: serveur.o prime.o hachage.o
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) -c -o $@ $<

serveur.o: hachage.h prime.h
hachage.o: hachage.h prime.h
prime.o: prime.h

clean:
	rm -rf serveur *.o

.PHONY: clean