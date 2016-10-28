/*Circular double linked list implementation*/




#include <stdio.h>
#include <stdlib.o>




typedef struct circListNode {
int value;
struct circList *prev
struct circList *next
}circListNode_t;

typedef struct circularList{
struct circListNode *head
}circularList_t;


