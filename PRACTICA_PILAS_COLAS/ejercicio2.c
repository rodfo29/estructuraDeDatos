#include <stdio.h>
#include <stdlib.h>




typedef struct Nodo
{
    int valor;
    struct Nodo*siguiente;
}Nodo;

typedef struct Cola
{
    Nodo*primero;
    Nodo*ultimo;
}Cola;


Nodo*crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

Cola crearCola(){
    Cola c;
    c.primero=NULL;
    c.ultimo=NULL;
    return c;
}
void encolar(Cola*cola,Nodo*nuevo_nodo){
    if (cola->primero==NULL){
        cola->primero=nuevo_nodo;
        cola->ultimo=nuevo_nodo;
        return;
    }

    Nodo*actual=cola->primero;
    while (actual->siguiente!=NULL)
    {
        actual=actual->siguiente;
    }
    actual->siguiente=nuevo_nodo;
    cola->ultimo=nuevo_nodo;

    
}

Nodo*desencolar(Cola*cola){
    if (cola->primero!=NULL){
        Nodo*aux=cola->primero;
        cola->primero=cola->primero->siguiente;
        aux->siguiente=NULL;
        return aux;
    }
    return NULL;
}

void copy(Cola*cola1,Cola*cola2){
    if (cola1->primero!=NULL){
        Cola colaAux=crearCola();
        // pasamos los elementos de la cola principal a la cola auxiliar (cola1 -----> colaAux).
        while (cola1->primero!=NULL)
        {
            encolar(&colaAux,desencolar(cola1));
        }
        
        // los nodos de la cola auxiliar los distribuiremos entre la cola original y la cola 2
        while (colaAux.primero!=NULL)
        {
            // Nodo actual
            Nodo*actual=desencolar(&colaAux);
            encolar(cola1,actual);

            // Nodo  réplica
            Nodo*nuevo_nodo=crearNodo(actual->valor);
            encolar(cola2,nuevo_nodo);

        }
        return;

    }
    printf("\n\nLa cola original no contiene elementos...\n\n");
    return;
}





        
void mostrarCola(Cola*cola){
    if (cola->primero!=NULL){
        Nodo*actual=cola->primero;
        while (actual!=NULL)
        {
            printf("%d ",actual->valor);
            actual=actual->siguiente;
        }
        return ;
    }
    printf("\n\nLa cola esta vacia ...\n\n");
    return;
}


void free_all(Cola*cola){
    if (cola->primero!=NULL){
        while (cola->primero!=NULL)
        {
            Nodo*aux=cola->primero;
            printf("\nliberando nodo con valor %d...\n",aux->valor);
            cola->primero=cola->primero->siguiente;
            free(aux);
        }
        cola->ultimo=NULL;
        return;
    }
    printf("\nLa cola no contiene elementos\n");
    return;

}







int main(){

int bucle_cond=0,menu,num;
    Cola cola1=crearCola();
    Cola cola2=crearCola();
    while (bucle_cond==0){
        printf("\n1)INGRESAR ELEMENTOS A LA COLA\n2)MOSTRAR COLA ORIGINAL\n3)COPIAR ELEMENTOS DE LA COLA\n4IMPRIMIR COLA ORIGINAL Y COLA COPIA\n5)BORRAR COLA ORIGINAL Y COPIA\nINGRESAR OPCION: ");
        scanf("%d",&menu);

    if (menu==1){
        printf("\n\nIngresar valor del nodo: ");
        scanf("%d",&num);
        Nodo*nuevo_nodo=crearNodo(num);
        encolar(&cola1,nuevo_nodo);

    }
    else if (menu==2){
        mostrarCola(&cola1);
    }
    else if (menu==3){
        copy(&cola1,&cola2);
    }
    else if (menu==4){
        printf("\n\nCOLA ORIGINAL\n\n");
        mostrarCola(&cola1);
        printf("\n\nCOLA COPIA\n\n");
        mostrarCola(&cola2);
    }
    
    else if (menu==5){
        free_all(&cola1);
        free_all(&cola2);
        bucle_cond=1;
    }

    }
    return 0;



}