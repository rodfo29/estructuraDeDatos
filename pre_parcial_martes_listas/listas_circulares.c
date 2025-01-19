#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo
{
    int valor;
    struct Nodo*siguiente;
}Nodo;


Nodo*addEnd(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        nuevo_nodo->siguiente=nuevo_nodo;
        return nuevo_nodo;
    }
    Nodo*actual=head;
    while(actual->siguiente!=head)
    {
        actual=actual->siguiente;
    }
    nuevo_nodo->siguiente=actual->siguiente;
    actual->siguiente=nuevo_nodo;
    return head;
}

Nodo*addFront(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        nuevo_nodo->siguiente=nuevo_nodo;
        return nuevo_nodo;
    }

    nuevo_nodo->siguiente=head;
    // hacemos que el último elemento apunte al nuevo nodo.
    Nodo*actual=head;
    while(actual->siguiente!=head){
        actual=actual->siguiente;
    }
    actual->siguiente=nuevo_nodo;
    return nuevo_nodo;
}


void mostrarLista(Nodo*head){
    if (head==NULL){
        printf("\n\nLista vacia\n\n");
        return;
    }
    Nodo*actual=head;
    while (actual->siguiente!=head)
    {
        printf("%d ",actual->valor);
        actual=actual->siguiente;
    }
    printf("%d ",actual->valor);
    
    printf("\n");
    
}


void free_all(Nodo*head){
    if (head==NULL){
        return;
    }
    Nodo*actual=head;
    while (actual->siguiente!=head)
    {   
        Nodo*aux=actual;
        actual=actual->siguiente;
        printf("\nEliminando nodo con valor : %d\n",aux->valor);
        free(aux);
    }
    Nodo*aux=actual;
    printf("\nEliminando nodo con valor : %d\n",aux->valor);
    free(aux);
    

    
}
Nodo*crearNodo(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    printf("\nIngresasr valor del nodo : ");
    scanf("%d",&nuevo_nodo->valor);
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}


int main(){
    int bucle_cond=0,menu;
    Nodo*head=NULL;
    while (bucle_cond==0)
    {
        printf("\n1)ingresar nodo al frente\n2)ingresar nodo al final\n3)mostrar lista\n4)vaciar lista\ningresar opcion: ");
        scanf("%d",&menu);

        if (menu==1){
            Nodo*nuevo_nodo=crearNodo();
            head=addFront(head,nuevo_nodo);
        }
        else if(menu==2){
            Nodo*nuevo_nodo=crearNodo();
            head=addEnd(head,nuevo_nodo);
        }

        else if (menu==3){
            mostrarLista(head);
        }   
        else if (menu==4){
            free_all(head);
            bucle_cond=1;
        }




    }
    



}