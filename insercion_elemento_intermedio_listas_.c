#include <stdio.h>

#include <stdlib.h>

typedef struct Nodo
{

    int valor;
    struct Nodo*siguiente;

}Nodo;


Nodo*add_end(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        return nuevo_nodo;
    }
    head->siguiente=add_end(head->siguiente,nuevo_nodo);
    return head;
}

Nodo*free_all(Nodo*head){
    if (head!=NULL){
        Nodo*aux=head;
        printf("\nEliminando Nodo %d ...\n",aux->valor);
        head=head->siguiente;
        free(aux);
        free_all(head);
    }
    return NULL;
}

Nodo*crearNodo(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    printf("\nIngresar numero: ");
    scanf("%d",&nuevo_nodo->valor);
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

int longitud_lista(Nodo*head){
    if(head==NULL){
        return 0;
    }
    return 1+longitud_lista(head->siguiente);
}


void mostrar_lista(Nodo*head){
    if (head!=NULL){
        printf("%d ",head->valor);
        mostrar_lista(head->siguiente);
    }
    return;
}

Nodo*insercion_intermedia(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        return NULL;
    }
    mostrar_lista(head); // mostramos los elementos de la lista enlazada.
    int pos,contador=1,lon=longitud_lista(head);
    printf("\n\nIngresar posicion del nuevo nodo: ");
    scanf("%d",&pos);
    
    
    Nodo*aux=head;
    if (contador<=lon){
        
        while(aux!=NULL){
            if (contador==pos-1){
            nuevo_nodo->siguiente=aux->siguiente;
            aux->siguiente=nuevo_nodo;
            printf("\nNodo actual: %d\n\n",aux->valor);
            return head;
            }
            printf("\nNodo actual: %d\n\n",aux->valor);
            aux=aux->siguiente;
            contador+=1;

            }
        
        return head;
    }
    
    
    else{
        return NULL;
    }



}


int main(){
    int cond_bucle=0,menu;
    Nodo*head=NULL;
    while (cond_bucle==0)
    {
        printf("\n1)INGRESAR ELEMENTOS A LA LISTA\n2)MOSTRAR LISTA\n3)INSERCION INTERMEDIA\n4)VACIAR LISTA\nINGRESAR OPCION: ");
        scanf("%d",&menu);

        if (menu==1){
            Nodo*nuevo_nodo=crearNodo();
            head=add_end(head,nuevo_nodo);
        }

        else if (menu==2){
            mostrar_lista(head);
        }

        else if (menu==3){
            Nodo*nuevo_nodo=crearNodo();
            head=insercion_intermedia(head,nuevo_nodo);
            printf("\nLista actual...\n");
            mostrar_lista(head);
        }

        else if (menu==4){
            free_all(head);
            cond_bucle=1;
        }





    }
    


}