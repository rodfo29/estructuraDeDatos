#include <stdio.h>
#include <stdlib.h>
// declaramos nuestros nodos 
typedef struct Nodo{
    int valor;
    struct Nodo*siguiente;

}Nodo;


Nodo*crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;

}


// añadimos el nodo al principio de la lista
void add_to_front(Nodo**head,int valor){

    Nodo*nuevo_nodo=crearNodo(valor);
    
    // validamos si la lista está vacía
    if (*head==NULL){
        *head=nuevo_nodo;
        return;
    }

    
    nuevo_nodo->siguiente=*head;
    *head=nuevo_nodo;


}

// añadimos los elementos al final de la lista
void add_to_end(Nodo**head,int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    
    // validamos si la lista está vacía
    if (*head==NULL){
        *head=nuevo_nodo;
        return;
    }


    Nodo *actual=*head, *anterior=NULL;
    while (actual!=NULL)
    {   
        anterior=actual;
        actual=actual->siguiente;

    }
    anterior->siguiente=nuevo_nodo;
}



void printf_lista(Nodo*head){
    Nodo*actual=head;
    if(head==NULL){
        printf("\n\nLa lista se encuentra vacia\n");
        return;
    }

    while (actual!=NULL)
    {
        printf("%d ",actual->valor);
        actual=actual->siguiente;

    }
    
}
    
void eliminar_lista(Nodo**head){
    Nodo*actual=*head, *anterior=NULL;
    while (actual!= NULL)
    {
        // siguiente=actual->siguiente;
        // free(actual);
        // actual=siguiente;

        anterior=actual;
        actual=actual->siguiente;
        free(anterior);

    }
    *head=NULL;
    
}








int main(){
    Nodo*head=NULL;
    add_to_front(&head,5);
    add_to_front(&head,4);
    add_to_front(&head,3);
    add_to_front(&head,2);
    add_to_front(&head,1);
    printf_lista(head);
    eliminar_lista(&head);
    printf_lista(head);


}