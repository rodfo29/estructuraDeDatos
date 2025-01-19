#include <stdio.h>

#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo*siguiente;

}Nodo;



typedef struct Pila
{
    Nodo*tope;
}Pila;


Pila crearPila(){
    Pila p;
    p.tope=NULL;
    return p;
}

Nodo*crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

void apilar(Pila*pila,int valor){
    Nodo*nuevo_nodo=crearNodo(valor);
    if (pila->tope==NULL){
        pila->tope=nuevo_nodo;
        return;
    }

    nuevo_nodo->siguiente=pila->tope;
    pila->tope=nuevo_nodo;
}


Nodo*desapilar(Pila*pila){
    Nodo*aux=pila->tope;
    pila->tope=pila->tope->siguiente;
    return aux;

}
void vaciarPila(Pila*pila){
    Nodo*aux=pila->tope;
    while(pila->tope!=NULL){
    printf("\n\nDesapilando: %d\n",aux->valor);
    pila->tope=pila->tope->siguiente;
    free(aux);
    aux=pila->tope;

    }

}

void imprimirPila(Pila*pila){
    Nodo*actual=pila->tope;
    while(actual!=NULL){
        printf("%d ",actual->valor);
        actual=actual->siguiente;
    }

}

int main(){
    Pila pila=crearPila();
    apilar(&pila,0);
    apilar(&pila,1);
    apilar(&pila,2);
    apilar(&pila,3);
    imprimirPila(&pila);
    Nodo*nodo_desapilado=desapilar(&pila);
    printf("\n\nEl nodo desapilado es: %d\n\n",nodo_desapilado->valor);
    vaciarPila(&pila);


}