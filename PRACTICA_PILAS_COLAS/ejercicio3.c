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

Nodo* crearNodo(int valor){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->valor=valor;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

Pila* crearPila(){
    Pila* pila=(Pila*)malloc(sizeof(Pila));
    pila->tope=NULL;
    return pila;
}



void push(Pila*pila,int valor){
    Nodo*nuevo_nodo=crearNodo(valor);
    nuevo_nodo->siguiente=pila->tope;
    pila->tope=nuevo_nodo;

}

int pop(Pila*pila,int*x){
    if (pila->tope!=NULL){
        Nodo*aux=pila->tope;
        *x=aux->valor;
        pila->tope=pila->tope->siguiente;
        free(aux);
        return 1;
    }
    return 0;

}

// FUNCIONES SOLICITADAS EN EL EJERCICIO: 
void poner_en_cola(Pila*pila,int x){
    if (pila->tope!=NULL){

        Pila*pilaAux=crearPila(); 
        int tope=0; // variable para almacenar el valor del tope de la pila.
        
        
        while(pila->tope!=NULL){
            pop(pila,&tope);// ahora x almacena el valor del tope de la pila original.
            push(pilaAux,tope);
        }
        
        // Ahora que la pila original está vacía agregamos el nuevo elemento a la pila original.
        push(pila,x);

        
        // Devolvemos los elementos desde la pila auxiliar a la pila original. (pila aux -----> pila original).
        while (pilaAux->tope!=NULL)
        {   pop(pilaAux,&tope);
            push(pila,tope);

        }
        
        // liberamos la memoria de pilaAux
        free(pilaAux);
        return;
    }
    push(pila,x);
}



int quitar_de_cola(Pila*pila,int*x){
    if (pila->tope!=NULL){
        pop(pila,x);
        return 1;

    }
    *x=0;
    return 0;
    }

void mostrarPila(Pila*pila){
    if (pila->tope!=NULL){
        Nodo*actual=pila->tope;
        while (actual!=NULL)
        {
            printf("%d ",actual->valor);
            actual=actual->siguiente;
        }

        return;
    }

    printf("\nLa pila esta vacia... ");
    return;
}


void free_all(Pila*pila){
    if (pila->tope!=NULL){
        while (pila->tope!=NULL)
        {
            Nodo*aux=pila->tope;
            printf("\nLiberando nodo : %d ...  \n",aux->valor);
            pila->tope=pila->tope->siguiente;
            free(aux);
        }
        return;
        
    }
    printf("\n\nLa pila esta vacia...\n\n");
   
}



int main(){
    int bucle_cond=0,menu,num;
    Pila*pila=crearPila();
    while(bucle_cond==0){
        printf("\n1)INGRESAR ELEMENTO A LA PILA\n2)MOSTRAR PILA\n3)POP\n4)BORRAR PILA\nINGRESAR OPCION: ");
        scanf("%d",&menu);

        if (menu==1){
            printf("Ingresar nuevo valor: ");
            scanf("%d",&num);
            
            poner_en_cola(pila,num);
        }

        else if (menu==2){
            mostrarPila(pila);
        }

        else if (menu==3){
            quitar_de_cola(pila,&num);
            printf("\nElemento eliminado %d",num);
        }

        else if (menu==4){
            bucle_cond=1;
            free_all(pila);
            
        }



    }
    return 0;


}