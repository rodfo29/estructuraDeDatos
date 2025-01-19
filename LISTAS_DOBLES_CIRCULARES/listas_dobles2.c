#include <stdio.h>

#include <stdlib.h>


typedef struct Nodo
{
    int valor;
    struct Nodo*siguiente;
    struct Nodo*anterior;
}Nodo;


Nodo*crearNodo(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    printf("\nIngresa valor del nuevo nodo: ");
    scanf("%d",&nuevo_nodo->valor);
    nuevo_nodo->siguiente=NULL;
    nuevo_nodo->anterior=NULL;
    return nuevo_nodo;
}



Nodo*add_end(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        return nuevo_nodo;
    }

    Nodo*actual=head;
    while(actual->siguiente!=NULL){
        actual=actual->siguiente;
    }

    actual->siguiente=nuevo_nodo;
    nuevo_nodo->anterior=actual;
    return head;
}


Nodo*add_front(Nodo*head,Nodo*nuevo_nodo){
    // validamos si la lista está vacía.
    if (head==NULL){
        return nuevo_nodo;
    }

    head->anterior=nuevo_nodo;
    nuevo_nodo->siguiente=head;
    return nuevo_nodo;

}


void mostrarLista(Nodo*head){
    if (head!=NULL){
        printf("%d ",head->valor);
        mostrarLista(head->siguiente);
    }
    return;
}


void free_all(Nodo*head){
    if (head!=NULL){
        Nodo*aux=head;
        printf("\nELIMNANDO NODO CON VALOR : %d\n",aux->valor);
        head=head->siguiente;
        free(aux);
        free_all(head);
    }
    return;
}



int main(){
    int menu,bucle_cond=0;

    Nodo*head=NULL;

    while(bucle_cond==0){

        printf("\n1)INGRESAR ELEMENTO AL FINAL\n2)INGRESAR ELEMENTO AL INICIO\n3)MOSTRAR LISTA\n4)ELIMINAR LISTA\nINGRESAR OPCION: ");
        scanf("%d",&menu);

        if (menu==1){
            Nodo*nuevo_nodo=crearNodo();
            head=add_end(head,nuevo_nodo);
        }

        else if (menu==2){
            Nodo*nuevo_nodo=crearNodo();
            head=add_front(head,nuevo_nodo);

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







