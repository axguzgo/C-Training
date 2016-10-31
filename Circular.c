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

 * Circular double linked list implementation

 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node 
{
    int value;
    struct Node *prev;
    struct Node *next;
} node_t;

typedef struct List
{
    struct Node *head;
} list_t;


/*Inserts an elmeent at  end of  given list.Returns 0 if succesful, -1 otherwise.*/
int add (list_t *list, int val){
    node_t * new = malloc(sizeof(node_t));

    /*If  malloc error, must stop*/
    if (new == NULL)
    {
        return -1;  
    }
    /*Set value of new node*/
    new->value=val;                 
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

/*Prints a list*/
void showList(list_t *list){
    if (list->head!=NULL)
    {
        node_t *pointer=list->head;
        printf("%d\n",pointer->value);
        pointer=pointer->next;
        while ( pointer != list->head) 
        {
            printf("%d\n",pointer->value);
            pointer=pointer->next;
        }
    }
}
/*Return a pointer to first ocurrence of  given element. Returns NULL if not exists.*/
struct Node *findElement(list_t *list, int element){
    bool found=false;
    node_t *aux=NULL;

    /*If not empty list*/
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
/*Removes first ocurrence of specified element in a list*/
int removeElement(list_t *list, int element){
    bool ret = false;
    node_t *aux=findElement(list,element);
    
    if(aux != NULL)
    {
        if (aux == list->head)
        {   
            /*One element list*/
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

void main(void){
    printf("Creating new list\n");
    list_t * list1 = malloc(sizeof(list_t));
    list_t * list2 = malloc(sizeof(list_t));
    //list1->head=NULL;-->Preguntar DUDA
    printf("Adding elements 1,2,3.. to list 1\n");
    add(list1,1);
    add(list1,2);
    add(list1,3);
    printf("Adding elements 10,21,31.. to list 2\n");
    add(list2,10);
    add(list2,21);
    add(list2,31);
    printf("Show list 1:\n");
    showList(list1);
    printf("Show list 2:\n");
    showList(list2);
    printf("Let's delete number 3 in list 1\n");
    removeElement(list1,3);
    showList(list1);
    printf("Let's delete number 31 in list 2\n");
    removeElement(list2,31);
    showList(list2);
    printf("Let's delete number 21 in list 2\n");
    removeElement(list2,21);
    showList(list2);
    printf("Let's delete number 10 in list 2\n");
    removeElement(list2,10);
    showList(list2);

}
