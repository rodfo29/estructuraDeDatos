#include <stdio.h>
#include <stdlib.h>


typedef struct Pedido
{
    char nombre[50];
    int precio;

}Pedido;

typedef struct NodoPedido 
{
    Pedido*pedido;
    struct NodoPedido*siguiente;


}NodoPedido;



typedef struct Cola
{
    NodoPedido*primero;
    NodoPedido*ultimo;



}Cola;


// creamos los pedidos
Pedido*crearPedido(){
    Pedido*nuevo_pedido=(Pedido*)malloc(sizeof(Pedido));
    printf("\nIngresar nombre del producto: ");
    fgets(nuevo_pedido->nombre,50,stdin);
    printf("\nIngresar precio del producto: ");
    scanf("%d",&nuevo_pedido->precio);
    getchar();// tomamos el salto de línea;
    return nuevo_pedido;

}

// creamos los contenedores de los pedidos. ( ESTE REPRESENTARÍA EL NODO EN LA LISTA ENLAZADA).
NodoPedido*crearContenedorPedido(Pedido*pedido){
    NodoPedido*contenedor_nuevo_pedido=(NodoPedido*)malloc(sizeof(NodoPedido));
    contenedor_nuevo_pedido->pedido=pedido; // hacemos que el dicho contenedos guarde la referencia del nuevo pedido.
    contenedor_nuevo_pedido->siguiente=NULL;
    return contenedor_nuevo_pedido;
}



void encolar(Cola*cola,NodoPedido*contenedor_nuevo_pedido){
    
    // si el campo primero de la cola es nulo (La cola no contiene elementos) hacemos que el primero y el último apunten al nuevo_contenedor.
    if (cola->primero==NULL){
        cola->primero=contenedor_nuevo_pedido;
        cola->ultimo=contenedor_nuevo_pedido;
        return;
    }
    // El último elemento que apunte al nuevo contenedor.
    cola->ultimo->siguiente=contenedor_nuevo_pedido;
    // Establecemos el nuevo contenedor como el último nodo.
    cola->ultimo=contenedor_nuevo_pedido;


}

NodoPedido*desencolar(Cola*cola){
    // validamos si la cola está vacía o no.
    if (cola->primero!=NULL){
        NodoPedido*aux=cola->primero;
        cola->primero=cola->primero->siguiente;
        return aux;
    }

    return NULL;
}


void mostrarInfoPedido(Cola*cola){
    if (cola->primero==NULL){
        printf("\nLa cola esta vacia...\n");
        return;
    }
    NodoPedido*aux=cola->primero;
    while (aux!=NULL)
    {
        printf("\n\nNombre del producto: %s",aux->pedido->nombre);
        printf("Precio del producto:%d ",aux->pedido->precio);
        aux=aux->siguiente;
    }
    
    

}


void vaciarCola(Cola*cola){
    if (cola->primero==NULL){
        printf("\nLa cola se encuentra vacia...\n");
        return;
    }
    NodoPedido*aux;
    while (cola->primero!=NULL)
    {
        aux=cola->primero;
        printf("\nEliminando producto: Nombre: %sPrecio:%d",aux->pedido->nombre,aux->pedido->precio);
        cola->primero=cola->primero->siguiente;
        free(aux);

    }
    
}


Cola crearCola(){
    Cola c;
    c.primero=NULL;
    c.ultimo=NULL;
    return c;
}


int main(){
    Cola cola=crearCola();

    int cond_loop=0,menu;

    while(cond_loop==0){
        printf("\n1)Ingresar elementos a la cola\n2)MOSTRAR ELEMENTOS DE LA COLA\n3)QUITAR ELEMENTO DE LA COLA\n4)ELIMINAR COLA\n");
        scanf("%d",&menu);
        getchar();// tomamos el salto de linea;


        if (menu==1){
            Pedido*nuevo_pedido=crearPedido();
            NodoPedido*nuevo_contenedor_pedido=crearContenedorPedido(nuevo_pedido);
            encolar(&cola,nuevo_contenedor_pedido);
        }

        else if (menu==2){
            mostrarInfoPedido(&cola);
        }

        else if (menu==3){
            NodoPedido*Nodo_desencolado=desencolar(&cola);
            if (Nodo_desencolado!=NULL){
            printf("\n\nNombre:%sprecio: %d",Nodo_desencolado->pedido->nombre,Nodo_desencolado->pedido->precio);

            }else{
                printf("\nYa no hay elementos en la cola....\n");
            }
        }
        else if (menu==4){
            vaciarCola(&cola);
            cond_loop=1;
        }





    }


}