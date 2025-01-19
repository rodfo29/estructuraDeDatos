#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo{
    int valor;
    struct Nodo*siguiente;
    struct Nodo*anterior;
}Nodo;


Nodo*crearNodo(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    printf("\nIngresar valor del nodo: ");
    scanf("%d",&nuevo_nodo->valor);
    nuevo_nodo->anterior=NULL;
    nuevo_nodo->anterior=NULL;
    return nuevo_nodo;
}




Nodo*addEnd(Nodo*head,Nodo*nuevo_nodo){
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


Nodo*addFront(Nodo*head,Nodo*nuevo_nodo){
    if (head==NULL){
        return nuevo_nodo;
    }

    nuevo_nodo->siguiente=head;
    head->anterior=nuevo_nodo;
    return nuevo_nodo;
}

Nodo*eliminarNodo(Nodo*head,int buscado){
    if (head==NULL){
        return NULL;
    }

    Nodo*actual=head;
    
    while(actual!=NULL && actual->valor!=buscado){

        actual=actual->siguiente;
    }

    // No hemos encontrado el elemento ingresado.
    if (actual==NULL){
        return NULL;
    }

    // El elemento buscado es el primer nodo.
    if (actual->anterior==NULL){
        Nodo*aux=actual->siguiente; // Tomamos el nodo siguiente si llega a haber
        // Validamos el caso de que el elemento siguiente al primer Nodo no sea NULL
        if (aux!=NULL){
            aux->anterior=NULL; // inicializams el campo anterior como nulo.
        }

        free(actual); // Liberamos el primer nodo.
        return aux;
    }
    
    
    else{
        actual->anterior->siguiente=actual->siguiente; // Hacemos que el nodo anterior apunte al nodo que le sigue al nodo actual.

        // Verificamos que el siguiente al nodo que queresmoe eliminar no sea NULL
        if (actual->siguiente!=NULL){
            actual->siguiente->anterior=actual->anterior;
        }
        free(actual);
        return head;
    }
}


void mostrarLista(Nodo*head){
    if (head!=NULL){
        printf("%d ",head->valor);
        return mostrarLista(head->siguiente);
    }
}
    
        

void vaciarLista(Nodo*head){
    if (head!=NULL){
        Nodo*aux=head;
        head=head->siguiente;
        printf("\nEliminando Nodo con valor : %d \n",aux->valor);
        free(aux);
        vaciarLista(head);
        return;
    }
    return;
}



int longitud(Nodo*head){
    if (head==NULL){
        return 0;
    }

    return 1+longitud(head->siguiente);
}

Nodo* insertar_ramdom(Nodo*head,Nodo*nuevo_nodo){
    if (head== NULL){
        return NULL;
    }

    // Obtenemos la longitud de la lista.
    int longLista=longitud(head);

    mostrarLista(head);
    printf("\nLongitud : %d\n",longLista);

    int indice,contadorElementos=1;
    printf("\nIngresar pocición del nuevo Nodo : ");
    scanf("%d",&indice);

    // Validamos que el índice del usuario nosea ni el priemro elemento ni el último.
    if (indice==1){
        head=addFront(head,nuevo_nodo);
        return head;
    }else if(indice==longLista){
        head=addEnd(head,nuevo_nodo);
        return head;

    }



    if (indice<=longLista){
        Nodo*actual=head;
        while(actual!=NULL){
            
            if (contadorElementos==(indice-1)){
                nuevo_nodo->siguiente=actual->siguiente;
                nuevo_nodo->anterior=actual;
                actual->siguiente->anterior=nuevo_nodo;
                actual->siguiente=nuevo_nodo;
            }
            actual=actual->siguiente;
            contadorElementos+=1;
        }

    }

    return head;


}









int main(){

    int bucle_condicion=0,menu,buscado;
    Nodo*head=NULL;

    while (bucle_condicion==0)
    {
        printf("\n1)INGRESAR NODO AL FINAL DE LA LISTA\n2)INGRESAR NODO AL PRINCIPIO DE LA LISTA\n3)MOSTRAR LISTA\n4)ELIMINAR NODO\n5)INSERTAR RAMDOM\n6)VACIAR LISTA\nINGRESAR OPCION: ");
        scanf("%d",&menu);

        if (menu==1){
            Nodo*nuevo_nodo=crearNodo();
            head=addEnd(head,nuevo_nodo);

        }

        else if(menu==2){
            Nodo*nuevo_nodo=crearNodo();
            head=addFront(head,nuevo_nodo);
        }


        else if(menu==3){
            mostrarLista(head);

        }
        else if (menu==4) {
            printf("\nIngresar valor del nodo a eliminar: ");
            scanf("%d",&buscado);

            head=eliminarNodo(head,buscado);
            if (head==NULL){
                printf("\n\nEl elemento ingresado no ha sigo encontrado\n\n");
            }

        }
        else if (menu==5){
            Nodo*nuevo_nodo=crearNodo();
            head=insertar_ramdom(head,nuevo_nodo);
        }
        else{
            bucle_condicion=1;
            vaciarLista(head);
        }

    }
    
}