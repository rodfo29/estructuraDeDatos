#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo
{
    char nombre[50];
    int edad;
    int sueldo;
    struct Nodo*siguiente;


}Nodo;

typedef struct NodoEspecial
{
    int valor;
    struct NodoEspecial*siguiente;
}NodoEspecial;





typedef struct Pila
{
    Nodo*tope;
}Pila;


Nodo*crearNodo(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    printf("Ingresar nombre de la persona: ");
    fgets(nuevo_nodo->nombre,50,stdin);
    printf("Ingresar edad de la persona: ");
    scanf("%d",&nuevo_nodo->edad);
    getchar(); // Capturamos el salto de línea.
    printf("Ingresar Sueldo de la persona: ");
    scanf("%d",&nuevo_nodo->sueldo);
    getchar();// tomamos el salto de línea.
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;

}

Pila crearPila(){
    Pila p;
    p.tope=NULL;
    return p;
}

// 
void push(Pila*pila,Nodo*nuevo_nodo){
    nuevo_nodo->siguiente=pila->tope;
    pila->tope=nuevo_nodo;
    
}

// void pushEspecial(Pila*pila,int valor){
//     NodoEspecial*nuevo_nodo=(NodoEspecial*)malloc(sizeof(NodoEspecial));
//     nuevo_nodo-> valor=valor;
//     nuevo_nodo->siguiente=pila->tope;
//     pila->tope=nuevo_nodo;

// }


Nodo*pop(Pila*pila){
    if (pila->tope==NULL){
        return -1;
    }

    Nodo*aux=pila->tope;
    // int valor=aux->sueldo;
    
    pila->tope=pila->tope->siguiente;
    // free(aux);
    return aux;

}

int peek(Pila*pila){
    if (pila->tope==NULL){
        return -1;
    }
    return pila->tope->sueldo;
}

int isEmpty(Pila*pila){
    if (pila->tope==NULL){
        return 1;
    }
    return -1;
}


void vaciarPila(Pila*pila){
    if (pila->tope==NULL){
        printf("\n\nLa pila se encuentra vacia..\n\n");
        return;
    }
    Nodo*aux;
    while(pila->tope!=NULL){
        aux=pila->tope;
        printf("Eliminando nodo ( %s )",aux->nombre);
        pila->tope=pila->tope->siguiente;
        free(aux);
    }
}

void mostrarPila(Pila*pila){
    if (pila->tope==NULL){
        printf("\n\nLa lista se encuentra vacia..\n\n");
        return;
    }

    Nodo*actual=pila->tope;
    while (actual!=NULL)
    {
        printf("%s",actual->nombre);
        actual=actual->siguiente;
    }
    

}

// recordar que como ya estamos trabajando con la dirección de memoria de la pila original, no debemos usar el & a la hora de pasarla a una función.

int sueldomayor(Pila*pilaOriginal){
    Pila pilaAux=crearPila();
    Pila pilaMayor=crearPila();
    while (pilaOriginal->tope!=NULL)
    {
        push(&pilaMayor,pop(pilaOriginal));
        while (pilaOriginal->tope!=NULL){
            // si el tope de la lista originale es mayor al tope de la lista de mayores entonces pasamos el tope de mayores a la lista aux y luego hacemos push del tope de la lista Original
            if (peek(pilaOriginal)>peek(&pilaMayor)){
                push(&pilaAux,pop(&pilaMayor));
                push(&pilaMayor,pop(pilaOriginal));

            }else{
                push(&pilaAux,pop(pilaOriginal));

            }
        
        
        }
        
    }
    return peek(&pilaMayor);
    


}

int main(){

    Pila pila=crearPila();

    int condicion_bucle=1;
    
    while(condicion_bucle==1){
        int menu;
        printf("\n\n----------------- MENU--------------\n\n1)AGREGAR USUARIO\n2)ELIMINAR ULTIMO USUARIO\n3)MOSTRAR ELEMENTOS PILA\n4)ELIMINAR PILA\n5)VERIFICAR SI LA PILA ESTA VACIA\n6)SUELDO MAYOR\nINGRESAR OPCION: ");
        scanf("%d",&menu);
        getchar(); // Tomamos el salto de línea.


        if (menu==1){
            Nodo*nuevo_nodo=crearNodo();
            push(&pila,nuevo_nodo);
        }

        // else if (menu==2){
        //     int ultimo_nodo=pop(&pila);
        //     printf("\nEl sueldo del nodo eliminado es: %d",ultimo_nodo);

        // }
        else if (menu==3){
            mostrarPila(&pila);

        }
        else if (menu==4){
            vaciarPila(&pila);
            condicion_bucle=0;
        }
        // else if (menu==5){
        //     int vacia=isEmpty(&pila);
        //     printf("\n\n%d\n\n",vacia);
        // }
        else if (menu==6){
            int sueldo=sueldomayor(&pila);
            printf("\nEl sueldo mayor es: %d\n\n",sueldo);
        }
    }

}