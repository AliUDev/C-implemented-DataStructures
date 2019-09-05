#include "hashTable.h"

void init_bucketList(bucket_list *list){
    list->empty = 1;
    list->size = 0;
    list->head = list->tail = NULL;
}

bucket_node *createNode_bucketNode(const char *data){
    bucket_node *node = (bucket_node*)malloc(sizeof(bucket_node));
    node->data = data;
    return node;
}
void insert_head_bucketList(bucket_list *list, const char *data){
    if(list->empty){
        list->head = list->tail = createNode_bucketNode(data);
        list->empty = 0;
    }else{
        bucket_node *temp = createNode_bucketNode(data);
        temp->next = list->head;
        list->head = temp;
    }
    list->size++;
}
void insert_tail_bucketList(bucket_list *list, const char *data){
    if(list->empty)
        insert_head_bucketList(list, data);
    else{
        bucket_node *temp = createNode_bucketNode(data);
        list->tail->next = temp;
        list->tail = temp;
        list->size++;
    }
}
const char* remove_tail_bucketList(bucket_list *list){
    static const char *retVal;
    if(list->empty)
        retVal = NULL;
    else if(list->head == list->tail){
        retVal = list->head->data;
        free(list->head);
        list->head = list->tail = NULL;
        list->size--;
    }else{
        bucket_node *curr = list->head;
        bucket_node *prev = NULL;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        free(list->tail);
        list->tail = prev;
    }
    list->empty = list->size == 0;
}

const char* remove_head_bucketList(bucket_list *list){
    static const char *retVal;
    if(list->empty)
        retVal = NULL;
    else if(list->head == list->tail){
        retVal = list->head->data;
        free(list->head);
        list->head = list->tail = NULL;
        list->size--;
    }else{
        
    }
    list->empty = list->size == 0;
}