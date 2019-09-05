#ifndef HASH_TABLE
#define HASH_TABLE
#include <stdlib.h>
/*Will be a simple hash function using the ASCII values of a string. Each element in the array will be a 
linked list bucket in order to chain collisions*/

/*LINKED LIST*/

typedef struct bucket{
    const char *data;
    struct bucket *next;
}bucket_node;

bucket_node *createNode_bucketNode(const char *data)

typedef struct bucketList{
    unsigned int size, empty;
    bucket_node *head, *tail;
}bucket_list;

void init_bucketList(bucket_list *list);
void insert_head_bucketList(bucket_list *list, const char *data);
void insert_tail_bucketList(bucket_list *list, const char *data);
const char* remove_tail_bucketList(bucket_list *list);
const char* remove_head_bucketList(bucket_list *list);

typedef struct HashMap{
    unsigned int size;
    bucket_list *storage;
}hash_map;

void init_HashMap(hash_map *map);
unsigned int hashFn(hash_map *map, const char *str);
unsigned int getSize(HashMap);

#endif