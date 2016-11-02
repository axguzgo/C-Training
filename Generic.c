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


typedef struct Node 
{
    void *data;
    struct Node *prev;
    struct Node *next;
} node_t;


typedef void (*printFunction)(void *);
typedef int  (*compareFunction)(node_t * , node_t *);

typedef struct List
{
    struct Node *head;
    int elementSize; 
    printFunction print;
    compareFunction compare;
} list_t;




/*Creates a nwe Generic list with the specified data type*/
void new_List(list_t * list, size_t size,printFunction print, compareFunction compare ){
    list->head=NULL;
    list->elementSize=size;
    list->print=print;
    list->compare=compare;
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
    new->data = malloc(list->elementSize);
    /*If  malloc error, must stop*/
    if (new ==NULL)
    {
        return -1;
    }
    /*Set value of new node*/    
    memcpy(new->data, data,list->elementSize);                 
    /*Empty list*/  
    if (list->head == NULL)
    {
        /*New node is the head of list*/
        list->head=new;             
        new->prev=new;          
        new->next=new;
    }
    /*General case*/
    else
    {
        /*Temp varibale. Holds  last elmeent in the list*/
        node_t *aux=list->head->prev;   
        /*Last element now points to  new element */          
        aux->next=new;             
        /*New element points to the last in the list*/
        new->prev=aux;                 
        /*Head prev set to the new added elmeent*/    
        list->head->prev=new; 
        /*New element points to head, so it becomes the last in the list*/
        new->next=list->head;           
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
    return aux;
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


/*Return a pointer to first ocurrence of  given element. Returns NULL if not exists.*/
struct Node *findElement(list_t *list, void * element){
    bool found=false;
    node_t *aux=NULL;

    /*If not empty list*/
    if (list->head != NULL)
    {   aux=list->head;
        
        if(list->compare(aux->data,element))
        {   
             found=true;
        }
        for(aux=aux->next; aux != list->head; aux=aux->next)
        {   
            if(list->compare(aux->data,element))
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
int removeElement(list_t *list, void * element){
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


void printInt(void *data){
    printf ("Value: %d\n",*(int *)data);
}

void printDouble(void *data){
    printf ("Value: %f\n",*(double *)(data));
}

bool compareInt(void *data1, void *data2){
        bool comp;
        comp= *(int *)data1 == *(int *)data2;
        return comp;
}

bool compareDouble(void *data1, void *data2){
    bool comp;
    comp=*(double *)data1 == *(double *)data2;
    return comp;
}

void main(void){
    printf("Creating new int list\n"); 
    list_t *list1=malloc(sizeof(list_t));
    new_List(list1,sizeof(int),&printInt,&compareInt);
    int a=1;
    int b=2;
    int c=3; 
    printf("Adding elements 1,2,3.. to list 1\n");
    add(list1,&a);
    add(list1,&b);
    add(list1,&c);
    printf("Print list acordding specified print function...\n");  
    showList(list1);

    printf("Creating new double list\n");
    list_t *list2=malloc(sizeof(list_t));
    new_List(list2,sizeof(double),&printDouble,&compareDouble);
    
    double d=1.234;
    double e=2.312;
    double f=3.141516; 

    printf("Adding elements  to list2 \n");
    add(list2,&d);
    add(list2,&e);
    add(list2,&f);
    printf("Print list acordding  specified print function...\n");  
    showList(list2); 

    void * pointA=&a;
    printf("Let's remove element 1 form list1\n");
    removeElement(list1,pointA);
    showList(list1); 

    void * pointD=&d;
    printf("Let's remove element 1.234 form list2\n");
    removeElement(list2,pointD);
    showList(list2); 
}
