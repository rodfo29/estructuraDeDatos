#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo{
    int valor;
    struct Nodo*siguiente;

}Nodo;

typedef struct Pila{
    Nodo*tope;
}Pila;


// funciones push, pop, peek,crearPila,crearNodo,isEmpty,vaciar Pila;

Nodo*crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo*));
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

// Creamos la pila
Pila crearPila(){
    Pila p;
    p.tope=NULL;
    return p;
}

// Añadir elementos a la pila.
void push(Pila*pila,int valor){
    Nodo*nuevo_nodo=crearNodo(valor);

    nuevo_nodo->siguiente=pila->tope;
    pila->tope=nuevo_nodo;
}


int pop(Pila*pila){
    if (pila->tope==NULL){
        return -1;
    }

    Nodo*aux=pila->tope;
    int valor=aux->valor;
    pila->tope=pila->tope->siguiente;
    free(aux);
    return valor;

};

int peek(Pila*pila){
    if (pila->tope==NULL){
        return -1;
    }
    return pila->tope->valor;
}

int isEmpty(Pila*pila){
    if(pila->tope==NULL){
        return 1;
    }
    return -1;
}


void vaciarPila(Pila*pila){
    if (pila->tope==NULL){
        return;
    }
    Nodo*aux;
    while(pila->tope!=NULL){
        aux=pila->tope;
        printf("\nEliminando Nodo %d ",aux->valor);
        pila->tope=pila->tope->siguiente;
        free(aux);
    }
}

void mostrarPila(Pila*pila){
    if (pila->tope==NULL){
        printf("\nLa pila no tiene elementos\n");
    }

    Nodo*actual=pila->tope;
    while (actual!=NULL)
    {
        printf("%d\n",actual->valor);
        actual=actual->siguiente;
    }
    
}

int main(){

    Pila pila=crearPila();
    push(&pila,1);
    push(&pila,2);
    push(&pila,3);
    push(&pila,4);
    push(&pila,5);

    pop(&pila);
    pop(&pila);
    mostrarPila(&pila);
    vaciarPila(&pila);    




}