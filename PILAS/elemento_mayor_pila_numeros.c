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


void push(Pila*pila,int valor) {
    Nodo*nuevo_nodo=crearNodo(valor);

    nuevo_nodo->siguiente=pila->tope;
    pila->tope=nuevo_nodo;
}

int pop(Pila*pila){
    if (pila->tope==NULL){
        return 404;
    }

    Nodo*aux=pila->tope;
    int valor=aux->valor;
    pila->tope=pila->tope->siguiente;
    free(aux);
    return valor;
}

int peek(Pila*pila){
    if (pila->tope==NULL){
        return 0;
    }
    return pila->tope->valor;
}

void vaciarPila(Pila*pila){
    if (pila->tope==NULL){
        printf("\n\nLa pila se encuentra vacia...\n\n");
        return;
    }
    while(pila->tope!=NULL){
        Nodo*aux=pila->tope;
        printf("\nEliminando Nodo con valor : %d\n",aux->valor);
        pila->tope=pila->tope->siguiente;
        free(aux);
    }
}



int elementoMayor(Pila*pila){
    if (pila->tope==NULL){
        return 0;
    }
    Pila pilaAux=crearPila();
    Pila pilaMayor=crearPila();

    while(pila->tope!=NULL){
        push(&pilaMayor,pop(pila));
        while (pila->tope!=NULL)
        {
            if (peek(pila)>peek(&pilaMayor)){
                push(&pilaAux,pop(&pilaMayor));
                push(&pilaMayor,pop(pila));
            }else{
                push(&pilaAux,pop(pila));
            }
            
        }
        
    }

    // tomamos el elemento mayor de la pila en una variable entera para poder vaciar las demás pilas
    int mayor=pilaMayor.tope->valor;
    vaciarPila(&pilaAux);
    vaciarPila(&pilaMayor);
    return mayor;


}



void mostrarPila(Pila*pila){
    if (pila->tope==NULL){
        printf("\nLa pila se encuentra vacia...\n\n");
        return;
    }
    Nodo*actual=pila->tope;
    while(actual!=NULL){
        printf("%d \n",actual->valor);
        actual=actual->siguiente;
    }
}


int main(){

    int menu,num,bucle_condicion=0;

    // creamos la pila 
    Pila pila=crearPila();

    while(bucle_condicion==0){
        printf("\n1)INGRESAR ELEMENTOS A LA PILA\n2)MOSTRAR LOS ELEMENTOS DE LA PILA\n3)ELEMENTO MAYOR\n4)BORRAR PILA\nINGRESAR OPCION: ");
        scanf("%d",&menu);


        if (menu==1){
            printf("\bIngresar valor: ");
            scanf("%d",&num);
            push(&pila,num);
        }

        else if (menu==2){
            mostrarPila(&pila);
        }

        else if(menu==3){
            int mayor =elementoMayor(&pila);
            printf("\nEL ELEMENTO MAYOR DE LA PILA ES %d\n",mayor);
        }

        else if (menu==4){
            vaciarPila(&pila);
            bucle_condicion=1;
        }








    }

}