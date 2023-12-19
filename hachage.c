#include "hachage.h"
#include "prime.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>


static pair HT_DELETED_p = {NULL, NULL};

static pair* new_pair(const char* k, const char* v) {
    pair* p = malloc(sizeof(pair));
    p->key = strdup(k);
    p->value = strdup(v);
    return p;
}


hash_table* ht_new() {
    return new_sized(HT_INITIAL_BASE_SIZE);
}


static hash_table* new_sized(const int base_size) {
    hash_table* ht = malloc(sizeof(hash_table));
    ht->base_size = base_size;

    ht->size = next_prime(ht->base_size);

    ht->count = 0;
    ht->p = calloc((size_t)ht->size, sizeof(pair*));
    return ht;
}


static void resize(hash_table* ht, const int base_size) {
    if (base_size < HT_INITIAL_BASE_SIZE) return;

    hash_table* new_ht = new_sized(base_size);
    for (int i = 0; i < ht->size; i++) {
        pair* p = ht->p[i];
        if (p != NULL && p != &HT_DELETED_p) insert(new_ht, p->key, p->value);
    }

    ht->base_size = new_ht->base_size;
    ht->count = new_ht->count;

    const int tmp_size = ht->size;
    ht->size = new_ht->size;
    new_ht->size = tmp_size;

    pair** tmp_pair = ht->p;
    ht->p = new_ht->p;
    new_ht->p = tmp_pair;

    del_hash_table(new_ht);
}


static void resize_up(hash_table* ht) {
    const int new_size = ht->base_size * 2;
    resize(ht, new_size);
}


static void resize_down(hash_table* ht) {
    const int new_size = ht->base_size / 2;
    resize(ht, new_size);
}


static void del_pair(pair* p) {
    free(p->key);
    free(p->value);
    free(p);
}


void del_hash_table(hash_table* ht) {
    for (int i = 0; i < ht->size; i++) {
        pair* p = ht->p[i];
        if (p != NULL) del_pair(p);
    }
    free(ht->p);
    free(ht);
}

static int hash(const char* s, const int a, const int n) {
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(a, len_s - (i+1)) * s[i];
        hash = hash % n;
    }
    return (int)hash;
}

static int get_hash(const char* s, const int num_buckets, const int attempt) {
    const int hash_a = hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void insert(hash_table* ht, const char* key, const char* value) {
    const int load = ht->count * 100 / ht->size;
    if (load > 70) resize_up(ht);

    pair* p = new_pair(key, value);
    int index = get_hash(p->key, ht->size, 0);
    pair* cur_p = ht->p[index];
    int i = 1;
    while (cur_p != NULL) {
        if (cur_p != &HT_DELETED_p) {
            if (strcmp(cur_p->key, key) == 0) {
    (cur_p);
                ht->p[index] = p;
                return;
            } else {
                index = get_hash(p->key, ht->size, i);
                cur_p = ht->p[index];
                i++;
            }
        }
    }
    ht->p[index] = p;
    ht->count++;
}


char* search(hash_table* ht, const char* key) {
    int index = get_hash(key, ht->size, 0);
    pair* p = ht->p[index];
    int i = 1;
    while (p != NULL) {
        if (p != &HT_DELETED_p){
            if (strcmp(p->key, key) == 0) return p->value;
        }
        index = get_hash(key, ht->size, i);
        p = ht->p[index];
        i++;
    }
    return NULL;
}


void del(hash_table* ht, const char* key) {
    const int load = ht->count * 100 / ht->size;
    if (load < 10) resize_down(ht);

    int index = get_hash(key, ht->size, 0);
    pair* p = ht->p[index];
    int i = 1;
    while (p != NULL) {
        if (p != &HT_DELETED_p) {
            if (strcmp(p->key, key) == 0) {
                ht->p[index] = &HT_DELETED_p;
            }
        }
        index = get_hash(key, ht->size, i);
        p = ht->p[index];
        i++;
    }
    ht->count--;
}

void save(hash_table* ht, int fd){
    for (int i=0; i < ht->size; i++){
        pair* p = ht->p[i];
        if (p != NULL && p != &HT_DELETED_p){
            write(fd, p->key, strlen(p->key));
            write(fd, " ", 1);
            write(fd, p->value, strlen(p->value));
            write(fd, "\n", 1);
        }
    }
}
