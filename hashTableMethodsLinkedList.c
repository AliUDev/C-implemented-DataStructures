#include "include/hashTableLL.h"
// helper methods to craete a node, set it's next pointer to null and assign the data
node *createNode(const char *key, int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;   //new node will not point to anything
    newNode->key = key;
    newNode->val = val;
}
// initialize our linked list
void initLinkedList(linked_list *list){
    list->empty = 1; // flag list as empty
    list->head = list->tail = NULL;
    list->size = 0;
}
//inserts a value at head (front)
void insertHead(linked_list *list, const char *key, int val){
    if(list->empty){
        list->head = list->tail = createNode(key, val);
        list->empty = 0;
    }else{  
        node *temp = createNode(key, val);
        temp->next = list->head;
        list->head = temp;
    }
    list->size++;
}
//inserts a value at tail (end)
void insertTail(linked_list *list, const char *key, int val){
    if(list->empty)
        insertHead(list, key, val);
    else{
        list->tail->next = createNode(key, val);
        list->tail = list->tail->next;
    }
    list->size++;
}
//prints out our complete linked list with each nodes data
void printLinkedList(linked_list *list){
    if(list->empty){
        printf("Empty");
    }else{
        node *temp = list->head;
        printf("[\n");
        while(temp != NULL){
            printf("{%s, %d}\n", temp->key, temp->val);
            temp = temp->next;
        }
        printf("]");
    }
}
//removes the element at the front 
void removeHead(linked_list *list){
    if(list->empty)
        printf("Cannot remove from an empty list\n");
    else if(list->head == list->tail){
        free(list->head);
        list->head = list->tail = NULL;
        list->size = 0;
        list->empty = 1;
    }else{
        node *temp = list->head->next;
        free(list->head);
        list->head = temp;
        list->size--;
    }
}
//removes element at the end of the list
void removeTail(linked_list *list){
    if(list->empty)
        printf("Cannot remove from an empty list\n");
    else if(list->head == list->tail){
        removeHead(list);
    }else{
        node *temp = list->head;
        while(temp->next != list->tail){
            temp = temp->next;
        }
        free(list->tail);
        list->tail = temp;
    }
}
// returns a pointer to the key as a string at the tail (end)
const char *peekTailKey(linked_list *list){
    return list->tail->key;
}
//returns the integer value stored at the tail 
int peekTailVal(linked_list *list){
    return list->tail->val;
}
// returns a pointer to the key as a string at the head (front)
const char *peekHeadKey(linked_list *list){
    return list->head->key;
}
//returns the integer value stored at the head
int peekHeadVal(linked_list *list){
    return list->head->val;
}