/**

 * @file ${FILE}

 *

 * ${DESCRIPTION}

 *

 * @author ${AUTHOR NAME} ${EMAIL}

 *

 * @copyright

 * Copyright 2016 Fent Innovative Software Solutions (FENTISS).

 * All rights reserved. Read LICENSE.txt file for the license terms.

 *

 * Changelog:

 *

 * [dd/mm/yyyy] [author]

 * [brief description]

 *

 * ${DATE} ${AUTHOR}

 * Generic  list implementation 

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef void (*printfunction)(void *);

typedef struct Node 
{
    void *data;
    struct Node *prev;
    struct Node *next;
} node_t;

typedef struct List
{
    struct Node *head;
    int elementSize; 
    printfunction print;
} list_t;


/*Creates a nwe Generic list with the specified data type*/
void new_List(list_t * list, size_t size,printfunction print ){
    list->head=NULL;
    list->elementSize=size;
    list->print=print;
}

/*Inserts an elmeent at  end of  given list.Returns 0 if succesful, -1 otherwise.*/
int add (list_t *list, void * data){
    node_t * new = malloc(sizeof(node_t));
    new->data=NULL;
    /*If  malloc error, must stop*/
    if (new == NULL)
    {
        return -1;  
    }
    /*Set value of new node*/
    new->data = malloc(list->elementSize);
    if (new ==NULL)
    {
        return -1;
    }
    
    memcpy(new->data, data,list->elementSize);                 
    /*Empty list*/  
    if (list->head == NULL)
    {
        list->head=new;             /*New node is the head of list*/
        new->prev=new;          
        new->next=new;
    }
    /*General case*/
    else
    {
        node_t *aux=list->head->prev;       /*Temp varibale. Holds  last elmeent in the list*/
        aux->next=new;              /*Last element now points to  new element */
        new->prev=aux;              /*New element points to the last in the list*/
        list->head->prev=new;           /*Head prev set to the new added elmeent*/
        new->next=list->head;           /*New element points to head, so it becomes the last in the list*/
    }
    return 0;       
}

/*Return next element on a list*/
struct Node *getNext(node_t *node){
    node_t *aux=NULL;
    aux=node->next;
    return aux;
}

/*Return previous element on a list*/
struct Node *getPrev(node_t *node){
    node_t *aux=NULL;
    aux=node->prev;
}
/*Prints a list*/
void showList(list_t *list){
    if (list->head!=NULL)
    {
        node_t *pointer=list->head;
        list->print(pointer->data);
        pointer=pointer->next;
        while ( pointer != list->head) 
        {
            list->print(pointer->data);
            pointer=pointer->next;
        }
    }
}


/*Return a pointer to first ocurrence of  given element. Returns NULL if not exists.
struct Node *findElement(list_t *list, int element){
    bool found=false;
    node_t *aux=NULL;

    /*If not empty list
    if (list->head != NULL)
    {   aux=list->head;
        
        if(aux->value==element)
        {   found=true;
        }
        for(aux=aux->next; aux != list->head; aux=aux->next)
        {   
            if (aux->value==element)
            {   found=true;
                break;
            }

        }
        if(!found)
        {    aux=NULL;
        }
    }
    return aux;
}
*/


/*Removes first ocurrence of specified element in a list
int removeElement(list_t *list, int element){
    bool ret = false;
    node_t *aux=findElement(list,element);
    
    if(aux != NULL)
    {
        if (aux == list->head)
        {   
            /*One element list
            if(aux->next==aux)
            {list->head=NULL;
            }
            else
            {
            list->head=aux->next;
            }
        }
        aux->prev->next=aux->next;
        aux->next->prev=aux->prev;
        free(aux);
        ret=true;
    }
    
    return ret;
}
*/

void printInt(void *data){
    printf ("Value: %d\n",*(int *)data);
}


void main(void){
    printf("Creating new int list\n");
    list_t *list1=malloc(sizeof(list_t));
    new_List(list1,sizeof(int),&printInt);
    int a=1;
    int b=2;
    int c=3; 
    printf("Adding elements 1,2,3.. to list 1\n");
    add(list1,&a);
    add(list1,&b);
    add(list1,&c);
    printf("Print list acordding print function specified...\n");  
    showList(list1);
}
