#include <stdio.h>
#include <stdlib.h>


/*Utilizando solamente las operaciones del TAD Pila, escribir una función para
realizar la copia de una pila especificada.*/

typedef struct Nodo
{
    int valor;
    struct Nodo*siguiente;


}Nodo;

typedef struct Pila
{
    Nodo*tope;
}Pila;

Nodo*crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

Pila crearPila(){
    Pila p;
    p.tope=NULL;
    return p;
}


void push(Pila*pila,Nodo*nuevo_nodo){
    nuevo_nodo->siguiente=pila->tope;
    pila->tope=nuevo_nodo;
}

Nodo*pop(Pila*pila){
    if (pila->tope!=NULL){
        Nodo*aux=pila->tope;
        pila->tope=pila->tope->siguiente;
        return aux;
    }
    return NULL;
}

void mostrarPila(Pila*pila){
    if (pila->tope!=NULL){
        Nodo*aux=pila->tope;
        while(aux!=NULL){
            printf("\n%d",aux->valor);
            aux=aux->siguiente;
        }
        return;
    }
    printf("\nLa pila esta vacia.... \n");
    return;
}


// función encargada de copiar los elementos de una pila en otra (PILA 1 -----> PILA 2)
void copy(Pila*pila1,Pila*pila2){
    if (pila1->tope!=NULL){
        Pila pilaAux=crearPila(); // declaramos una pila auxiliar.
        
        // transferimos los nodos de la pila1 a la pila auxiliar (PILA1 ------> PILA AUX).
        while (pila1->tope!=NULL){
        push(&pilaAux,pop(pila1)); // (PILA 1 -----> PILA AUX).
        }
        
        // Devolvemos los elementos de la pilaAux a la pila1 además de también asignarle los nodos al a pila2 (PILA AUX ----> PILA1 && PILA AUX -----> PILA2)
        while (pilaAux.tope!=NULL)
        {   
            Nodo*actual=pop(&pilaAux); // obtenemos el nodo para 1)Agregarlo a la pila 1, 2)Crear un nuevo nodo que replicará el valor del nodo original para luego ser agregado a la pila 2

            push(pila1,actual);  // (PILA AUX ----> PILA1)

            Nodo*nodo_copia=crearNodo(actual->valor); // creamos un nodo el cual replicará el valor del nodo original.
            push(pila2,nodo_copia);


        }
        
        return;
    }
    printf("\n\nLa pila original no contiene elementos....\n\n");
    return;

}


void free_all(Pila*pila){
    if (pila->tope!=NULL){
        while (pila->tope!=NULL)
        {
            Nodo*aux=pop(pila);
            printf("\nEliminando nodo %d...\n",aux->valor);
            free(aux);
        }
        
    }
    printf("\nLa pila no contiene elementos...\n");
}



int main(){
    int bucle_cond=0,menu,num;
    Pila pila=crearPila();
    Pila pila2=crearPila();
    while (bucle_cond==0){
        printf("\n1)INGRESAR ELEMENTOS A LA PILA\n2)MOSTRAR PILA ORIGINAL\n3)COPIAR ELEMENTOS DE LA PILA\n4IMPRIMIR PILA ORIGINAL Y PILA COPIA\n5)BORRAR PILA ORIGINAL Y COPIA\nINGRESAR OPCION");
        scanf("%d",&menu);

    if (menu==1){
        printf("\n\nIngresar valor del nodo: ");
        scanf("%d",&num);
        Nodo*nuevo_nodo=crearNodo(num);
        push(&pila,nuevo_nodo);

    }
    else if (menu==2){
        mostrarPila(&pila);
    }
    else if (menu==3){
        copy(&pila,&pila2);
    }
    else if (menu==4){
        printf("\n\nPILA ORIGINAL\n\n");
        mostrarPila(&pila);
        printf("\n\nPILA COPIA\n\n");
        mostrarPila(&pila2);
    }
    
    else if (menu==5){
        free_all(&pila);
        free_all(&pila2);
        bucle_cond=1;
    }

    }
    return 0;


}