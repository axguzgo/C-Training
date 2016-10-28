/*> Activitat: Implementar una llista dinàmica doblement enllaçada usant
  punters (sense màxim d'elements).
  - La llista hauria de permetre guardar enters
  - Operacions suportades:
 * Inserir element al final.
 * Buscar un element.
 * Aconseguir l'element anterior
 * Eliminar un element de la llista.
 * Aconseguir el següent element a partir d'un element que s'ha
 trobat anteriorment.
 * Recorrer la llista usant un bucle "for". Si ho necessites,
 definex funcions adicionals a les anteriors per a completar aquesta
 funcionalitat.
 - Presentar-ho com un programa en C que faça us de totes les
 operacions. I que recorrega la llista de principi a final.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int value;
	struct list *prev;
	struct list *next;
}t_list;

t_list  *first,*last;
int size=0;


/*Returns the next element of the list.*/
void get_next(t_list *element,t_list **result){
	*result=element->next;
}
/*ompletar*/
void get_prev(t_list *element,t_list **result){
	*result=element->prev;	
}

/*Method to add an element at the end of the list.*/
void add(int val){
	t_list *new;					/*Pointer to the new node*/		
	///////////////////////////////
	new = malloc (sizeof (t_list));			/*Memory reservation*/
	/*In case of an empty list*/
	if(last==NULL){
		//////////////////////////////////
		new->value=val;				/*Value anextniment*/	
		new->next=NULL;
		new->prev=NULL;				
		size++;					/*Increment size of list*/
		first=new;				/*Set first element of list*/
		last=new;				/*Set last element of list*/

	}
	/*General case non-empty list*/
	else{

		last->next=new;				/*Last element of the list now points new*/
		last->next->value=val;			/*Set vlaue of new element*/
		last->next->next=NULL;			/*New element next is NULL*/
		last->next->prev=last;
		last=new;				/*The new element is now the last in the list*/
		size++;					/*List size grows*/
	}
}
/*Returns a pointer to the element or NULL if not exists*/
struct list *find_element(struct list **ptr,int val){
	int i;
	int found=0;
	t_list *element=first;
	while(element!=NULL){
		if(element->value==val){
			found=1;
			break;	
		}
		element=element->next;
	}
	if(found){

		*ptr=element;
		return ptr;
	}
	else{
		return NULL;
	}
}

/*Show the elements contained in the list.*/
void show_List(){
	t_list *aux;
	////////////////////////
	aux=first;
	if(aux!=NULL){
		printf("%d",aux->value);
		while(aux->next!=NULL){
			aux=aux->next;
			printf("-%d",aux->value);
		}
		printf("\n");
	}
}
/*Removes the specified element of the list. Returns true if succesful and -1 otherwise*/
int remove_element(int val){
	t_list * aux =malloc(sizeof(t_list));
	find_element(&aux,val);
	if(aux!=NULL){
		/*One element List*/
		if(first==last){
			free(aux);
			first=NULL;
			last=NULL;}

		/*First element of list */
		if(aux->prev==NULL){
			first=aux->next;
			//free(aux);
		}
		/*Last element of list*/
		else{ 
			if(aux->next==NULL){
				aux=aux->prev;
				aux->next=NULL;
				last=aux;
				//free(aux);
			}
			/*General case*/
			else{
				aux=aux->prev;
				aux->next=aux->next->next;
				aux->next->prev=aux;
				//free(aux);
			}
		}
	}
}

void delete_Last(){
	t_list * temp=last;
	/*printf("Valor de last %d",last->value);*/
	if(last!=NULL){
		if(temp->prev==NULL){
			/*printf("llista de un sol element\n");*/
			last=NULL;
			first=NULL;
			free(temp);
		}
		else{	
			/*printf("Llista amb més de un element\n");*/
			last=last->prev;
			last->next=NULL;	
			free(temp);}
	}

}

void main(void){
	printf("Començant test de la llista\n");
	printf("Estat actual de la llista\n");
	show_List();
	printf("Afegir element 45\n");
	add(45);
	printf("elimina element 45\n");
	remove_element(45);
	printf("Estat actual de la llista\n");
	show_List();
	printf("Afegir element 2\n");
	add(2);
	printf("Afegir element 5\n");
	add(5);
	printf("Afegir element 20\n");
	add(20);
	printf("Afegir element 95\n");
	add(95);
	printf("Estat actual de la llista\n");
	show_List();
	printf("Eliminar element 20\n");
	remove_element(20);
	printf("Estat actual de la llista\n");
	show_List();
	printf("Eliminar element 95\n");
	remove_element(95);
	printf("Estat actual de la llista\n");
	show_List();
	printf("Eliminar element 2\n");
	remove_element(2);
	printf("Estat actual de la llista\n");
	show_List();
	printf("Eliminar element 5\n");
	remove_element(5);
	printf("Estat actual de la llista\n");
	show_List();
}
