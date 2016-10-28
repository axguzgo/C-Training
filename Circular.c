/*Circular double linked list implementation*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *prev;
	struct Node *next;
}Node_t;

typedef struct List{
	struct Node *head;
}List_t;


/*Inserts an elmeent at  end of  given list.Returns 0 if succesful, -1 otherwise.*/
int add (List_t *list, int val){
	Node_t * new = malloc(sizeof(Node_t));
	if (!new){					/*NULL evaluates as false, any other valor evaluates as true*/
		return -1;	
	}
	new->value=val;					/*Set value of new node*/
	/*Empty list*/	
	if (list->head==NULL){
		list->head=new;				/*New node is the head of list*/
		new->prev=new;			
		new->next=new;
	}
	/*General case*/
	else{
		Node_t *aux=list->head->prev;		/*Temp varibale. Holds  last elmeent in the list*/
		aux->next=new;				/*Last element now points to  new element */
		new->prev=aux;				/*New element points to the last in the list*/
		list->head->prev=new;			/*Head prev set to the new added elmeent*/
		new->next=list->head;			/*New element points to head, so it becomes the last in the list*/
	}
	return 0;		
}

/*Prints a list*/
void showList(List_t *list){
	Node_t *pointer=list->head;
	printf("%d\n",pointer->value);
	pointer=pointer->next;
	while(pointer!=NULL && pointer!=list->head){
		printf("%d\n",pointer->value);
		pointer=pointer->next;
	}

}

void main (void){
	printf("Crating new list\n");
	List_t * list1 = malloc(sizeof(List_t));
	List_t * list2 = malloc(sizeof(List_t));
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

}
