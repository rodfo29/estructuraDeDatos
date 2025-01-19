#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo*derecho;
    struct Nodo*izquierdo;
    
}Nodo;

Nodo*crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->derecho=NULL;
    nuevo_nodo->izquierdo=NULL;
    nuevo_nodo->valor=valor;
    return nuevo_nodo;
}

Nodo*insertar(Nodo*raiz,int valor){
    if (raiz==NULL){
        Nodo*nuevo_nodo=crearNodo(valor);
        return nuevo_nodo;
    }
    if (valor>raiz->derecho)


}





int main(){
    



}

