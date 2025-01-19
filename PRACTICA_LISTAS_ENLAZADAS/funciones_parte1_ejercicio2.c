#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo*siguiente;
}Nodo;

// forma iterativa
Nodo*reversa(Nodo*head){
    
    if (head==NULL){
        return NULL;
    }
    /*Osea tomando en cuenta que tenemos que tener la dirección de memoria del nodo anterior y del nodo actual,
     hacemos que el primer nodo apunte a nulo ( este será el final de la nueva lista), que el nodo "actual" apunte al 2do nodo para no perder su referencia
     ,que "anterior" apunte a la cabeza de la lista y por último un puntero auxiliar que nos servirá como puente para que el nodo actual pueda avanzar.
*/
    
    // 
    Nodo*actual=head->siguiente,*anterior=head,*aux;
    head->siguiente=NULL;
    while (actual!=NULL)
    {   aux=actual->siguiente;
        actual->siguiente=anterior;
        anterior=actual;
        actual=aux;



    }
    return anterior;
    

}


// Forma recursiva.
struct Nodo* reversa(struct Nodo* head) {
    if (head == NULL || head->siguiente == NULL) {
        return head;
    }
    
    struct Nodo* nuevoHead = reversa(head->siguiente);
    
    head->siguiente->siguiente = head;
    head->siguiente = NULL;
    
    return nuevoHead;
}











// forma iterativa

Nodo*copy(Nodo*head){
    if (head==NULL){
        return NULL;
    }

    Nodo*actual=head,*head2=NULL;
    while(actual!=NULL){
        // creamos un nuevo nodo para la lista copia usando el valor del nodo actual de la lista original.
        Nodo*nuevo_nodo=crearNodo(actual->valor);
        // agregamos el nodo a la lista copia.
        head2=add_end(head2,nuevo_nodo);
        actual=actual->siguiente;
    }
    return head2;

}

// forma recursiva
Nodo*copy(Nodo*head){
    if (head!=NULL){
        Nodo*nuevo_nodo=crearNodo(head->valor);
        nuevo_nodo->siguiente=copy(head->siguiente);
        return nuevo_nodo;
    }
    return NULL;
}



// forma iterativa
Nodo*concatenar(Nodo*head,Nodo*head2){
    if (head==NULL){
        return head2;
    }else if (head2==NULL){
        return head;
    }
    Nodo*actual=head;
    while (actual->siguiente!=NULL)
    {
        actual=actual->siguiente;
    }
    actual->siguiente=head2;
    return head;
}



// forma recursiva
Nodo*concatenar(Nodo*head,Nodo*head2){
    if (head==NULL){
        return head2;
    }else if (head2==NULL){
        return head;
    }

    head->siguiente=concatenar(head->siguiente,head2);
    return head;
}





    













int main(){



}