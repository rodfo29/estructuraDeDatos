#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo
{
    int valor;
    struct Nodo*siguiente;
    struct Nodo*anterior;
}Nodo;


Nodo* add_end(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        head=nuevo_nodo;
        return head;
    }

    Nodo*actual=head;
    while (actual->siguiente!=NULL)
    {
        actual=actual->siguiente;
    }
    nuevo_nodo->anterior=actual;
    actual->siguiente=nuevo_nodo;
    return head;

}


Nodo*add_front(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        return nuevo_nodo;
    }

    nuevo_nodo->siguiente=head;
    head->anterior=nuevo_nodo;
    return nuevo_nodo;


}


void mostrasLista(Nodo*head){
    if (head!=NULL){
        printf("%d ",head->valor);
        mostrasLista(head->siguiente);
    }
    return;
}

Nodo* free_all(Nodo*head){
    if (head!=NULL){
        Nodo*aux=head;
        printf("\n\nELIMINANDO NODO %d ....\n",aux->valor);
        head=head->siguiente;
        free(aux);
        free_all(head);
    }
    return NULL;

}

Nodo*crearNodo(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->anterior=NULL;
    nuevo_nodo->siguiente=NULL;
    printf("\nIngresar valor del nuevo nodo: ");
    scanf("%d",&nuevo_nodo->valor);
    
    return nuevo_nodo;
    
    }



int main(){
    int bucle_cond=0,menu;
    Nodo*head=NULL;
    while(bucle_cond==0){
        printf("\n\n\n1)INSERTAR NUEVO NODO AL FINAL\n2)MOSTRAR LISTA DOBLE\n3)INSERTAR NODO AL INICIO\n4)ELIMINAR LISTA...\nINGRESAR OPCION: ");
        scanf("%d",&menu);


        if (menu==1){
            Nodo*nuevo_nodo=crearNodo();
            head=add_end(head,nuevo_nodo);

        }
        else if (menu==2){
            mostrasLista(head);
        }


        else if(menu==3){
            Nodo*nuevo_nodo=crearNodo();
            head=add_front(head,nuevo_nodo);

        }

        else if (menu==4){
            free_all(head);
            bucle_cond=1;
        }












    }


}