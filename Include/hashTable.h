#ifndef HASH_TABLE
#define HASH_TABLE
#include <string.h>
#include "hashTableLL.h"

/* Hash_Table implemented using an array of linked lists. Each Linked list will be a "bucket" to reduce collisions. The key_val pairs will be string->integer
    ex: "Name"->Age = 12
*/

typedef struct Table{
    linked_list *storage; // will be an array of linked lists
    unsigned int size, empty; //size will be 10 elements by default
    float percentFull; // percent value of how full our hash table is
}hash_table;

/**main methods**/
void initHashTable(hash_table *table);
void insert(hash_table *table, const char *key, int val);
void insertKey(hash_table *table, const char *key);
void insertValAtKey(hash_table *table, const char *key, int val);
void removeElement(hash_table *table, const char *key);
const char *lookupKey(hash_table *table, const char *key);
int lookupVal(hash_table *table, int val);
void displayTable(hash_table *table);

/**helper methods**/
void expandTable(hash_table *table); // reallocs the table if it's size is >= 70%
void shrinkTable(hash_table *table); // shrinks table

/*HASH FN*/
unsigned int hash(hash_table *table, const char *str, unsigned int tableSize); // hashes a string using ASCII vals and returns an array index
#endif