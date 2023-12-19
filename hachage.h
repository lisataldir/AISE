#ifndef HACHAGE_H_
#define HACHAGE_H_

#define HT_PRIME_1 151
#define HT_PRIME_2 163
#define HT_INITIAL_BASE_SIZE 50

typedef struct {
    char* key;
    char* value;
} pair;

typedef struct {
    int size;
    int count;
    pair** p;
    int base_size;

} hash_table;

// fonctions de base d'une hash table
static pair* new_pair(const char* k, const char* v);
hash_table* ht_new();

static hash_table* new_sized(const int base_size);
static void resize(hash_table* ht, const int base_size);
static void resize_up(hash_table* ht);
static void resize_down(hash_table* ht);

static void del_pair(pair* p);
void del_hash_table(hash_table* ht);

static int hash(const char* s, const int a, const int n);
static int get_hash(const char* s, const int num_buckets, const int attempt);

void insert(hash_table* ht, const char* key, const char* value);
char* search(hash_table* ht, const char* key);
void del(hash_table* ht, const char* key);

// stockage sur le disque
void save(hash_table* ht, int fd);

#endif
