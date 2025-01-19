#include <stdio.h>

typedef struct 
{
    int tope;
    int arreglo[50];
}Pila;

Pila crearPila();
int pilaVacia(Pila);
void addElement(Pila*,int);
int pop(Pila*);
int top(Pila);


Pila crearPila(){
    Pila p;
    p.tope=0;
    return p;
}

int pilaVacia(Pila pila){
    if (pila.tope==0){
        return 1;
    }
    return -1;
}

void addElement(Pila*pila,int elemento){
    pila->arreglo[pila->tope]=elemento;
    pila->tope=pila->tope+1;
}
int pop(Pila*pila){
    int aux=pila->arreglo[pila->tope-1];
    pila->arreglo[pila->tope-1]=NULL;
    pila->tope-=1;
    return aux;
}

int top(Pila pila){
    // validamos que la pila no este vacía
    if (pilaVacia(pila)==1){
        printf("\nLa pila se encuentra vacia...\n");
        return 404;
    }
    return pila.arreglo[pila.tope-1];
}



int main(){
    Pila pila=crearPila();
    addElement(&pila,1);
    addElement(&pila,2);
    addElement(&pila,3);
    addElement(&pila,4);
    int tope=top(pila);
    printf("El valor del tope es: %d\n",tope);
    int popp=pop(&pila);
    pop(&pila);
    pop(&pila);
    pop(&pila);
    printf("El elemento eliminado es: %d\n",tope);
    int topp=top(pila);
    printf("Resulado de si la pila esta o no vacia %d\n",topp);





}