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

Cola* crearCola(){
    Cola*c=(Cola*)malloc(sizeof(Cola));
    c->primero= NULL;
    c->ultimo=NULL;
    return c;
}

void poner_en_cola(Cola*cola,int x){
    Nodo*nuevo_nodo=crearNodo(x);
    if (cola->primero==NULL){
        cola->primero=nuevo_nodo;
        cola->ultimo=nuevo_nodo;
        return;
    }

    Nodo*actual=cola->primero;
    while(actual->siguiente!=NULL){
        actual=actual->siguiente;
    }
    actual->siguiente=nuevo_nodo;
    cola->ultimo=nuevo_nodo;


}

int quitar_de_cola(Cola*cola,int *x){
    if (cola->primero!=NULL){
        Nodo*actual=cola->primero;
        *x=actual->valor;
        cola->primero=cola->primero->siguiente;
        free(actual);
        return 1; // EXITO.
    }
    return 0; // Fracaso.
}

// FUNCIONES SOLICITADAS EN EL EJERCICIO: 
void push(Cola*cola,int x){
    if (cola->primero!=NULL){
        Cola*colaAux=crearCola();

        int primero=0; // Almacenar el valor del primer nodo.
        // Pasamos los nodos de la cola original a la cola auxiliar (cola original -----> cola auxiliar).
        while (cola->primero!=NULL)
        {       quitar_de_cola(cola,&primero);
                poner_en_cola(colaAux,primero);
        }

        // agregamos a la cola original el nuevo elemento.
        poner_en_cola(cola,x);

        // devolvemos a la cola original todos sus elementos

        while(colaAux->primero!=NULL){
            quitar_de_cola(colaAux,&primero);
            poner_en_cola(cola,primero);
        }
        
        // liberamos la memoria de la cola auxiliar
        free(colaAux);
        return;
    }
    poner_en_cola(cola,x);

}


int pop(Cola*cola,int*x){
    if (cola->primero!=NULL){
        Nodo*actual=cola->primero;
        *x=actual->valor;
        cola->primero=cola->primero->siguiente;
        free(actual);
        return 1; // EXITO
    }
    *x=0;
    return 0; // FRACASO
}


void mostrarCola(Cola*cola){
    if (cola->primero!=NULL){
        Nodo*actual=cola->primero;
        while(actual!=NULL){
            printf("\n%d ",actual->valor);
            actual=actual->siguiente;
        }
        return;
    }
    printf("\nLa cola se encuentra vacia...\n");
    return;
}


void free_all(Cola*cola){
    if (cola->primero!=NULL){
        while (cola->primero!=NULL)
        {
            Nodo*aux=cola->primero;
            printf("\n\nEliminando nodo con valor: %d\n", aux->valor);
            cola->primero=cola->primero->siguiente;
        }
        return;
        
    }

}


int main(){
    int bucle_cond=0,num,menu;
    Cola*cola=crearCola();

    while(bucle_cond==0){
        printf("\n1)INGRESAR ELEMENTO A LA COLA\n2)MOSTRAR COLA\n3)DESENCOLAR\n4)BORRAR COLA\nINGRESAR OPCION: ");
        scanf("%d",&menu);

        if (menu==1){
            printf("\nIngresar valor del nodo: ");
            scanf("%d",&num);
            push(cola,num);

        }
        else if (menu==2){
            mostrarCola(cola);
        }
        else if (menu==3){
            pop(cola,&num);
            (num!=0)?printf("\nDesencolamos el nodo con valor %d...\n",num):printf("\nLa cola no contiene elementos..\n");
        }
        else if (menu==4){
            bucle_cond=1;
            free_all(cola);
        }
    }
            
    return 0;


   
   



}