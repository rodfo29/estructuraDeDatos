#include <stdio.h>
#include <stdlib.h>
 /* ALUMNO : MARTÍN PINTO
    CÉDULA : 31894388
    INGENIERÍA INFORMÁTICA

*/

typedef struct Nodo{
    char nombre[50];
    int edad;
    int cantEntradas; // numero de entradas que el cliente comprará.
    struct Nodo*siguiente;
}Nodo;


typedef struct Cola{
    Nodo*primero;
    Nodo*ultimo;
}Cola;


// Crear Nodo (cliente)
Nodo*crearNodo(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    
    printf("\nIngresar nombre del cliente: ");
    fgets(nuevo_nodo->nombre,50,stdin);
    
    printf("\nIngresar edad del cliente: ");
    scanf("%d",&nuevo_nodo->edad);
    getchar(); // tomamos el salto de línea.

    printf("\nIngresar cantidad de entradas a comprar: ");
    scanf("%d",&nuevo_nodo->cantEntradas);
    getchar(); // tomamos el salto de línea.

    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
    
    }


// creamos nuestra cola
Cola crearCola(){
    Cola c;
    c.primero=NULL;
    c.ultimo=NULL;
    return c;
}

// agregamos los nodos (cientes a la cola)
void encolar(Cola*cola,Nodo*nuevo_nodo){
    if (cola->primero==NULL){
        cola->primero=nuevo_nodo;
        cola->ultimo=nuevo_nodo;
        return;
    }
    
    // declaramos un puntero auxiliar
    Nodo*actual=cola->primero;
    while (actual->siguiente!=NULL)
    {
        actual=actual->siguiente;
    }
    actual->siguiente=nuevo_nodo; //  El ultimo nodo de la cola apunta al nuevo nodo
    cola->ultimo=nuevo_nodo; // El puntero último de la cola apunta al nuevo nodo.
    
}

Nodo*desencolar(Cola*cola){
    if (cola->primero!=NULL){
        // declaramos un nodo auxiliar.
        Nodo*aux=cola->primero;
        cola->primero=cola->primero->siguiente;
        // declaramos como nulo el campo siguiente del nodo que desencolaremos para que no siga apuntando a otros nodos de la cola.
        aux->siguiente=NULL;
        return aux;
    }
    cola->ultimo=NULL; // aseguramos que el puntero al último nodo sea nulo.
    return NULL;
}


// transferir los elementos de una cola a otra.
void transferir_cola(Cola*cola_destino,Cola*cola_inicio){
    if (cola_inicio!=NULL){
        while (cola_inicio->primero!=NULL)
        {
            encolar(cola_destino,desencolar(cola_inicio));
        }
        
    }
    return;
}

void mostrarCola(Cola*cola){
    if (cola->primero!=NULL){
        Nodo*aux=cola->primero;
        while (aux!=NULL)
        {
            printf("%s",aux->nombre);
            aux=aux->siguiente;
        }
        return;
    }
    printf("\nLa Taquillla no contiene clientes...\n\n");
    return;
}



// Asignar los clientes a las taquillas correspondientes.
void asignacionTaquillas(Cola*taquilla1,Cola*taquilla2,Cola*taquilla3){
    if (taquilla1->primero!=NULL){
        Cola taquillaAux=crearCola();// Declaramos una taquilla auxiliar.

       
       /* Las iteraciones del bucle son posibles ya que cada vez que desencolamos estamos haciendo que el campo (cola-> primero) avence,
       por que por así decirlo nos podemos ahorrar esa línea que es para avanzar al siguiente nodo.*/
        
        while(taquilla1->primero!=NULL){
            
            // SI ES MAYOR DE 45 AÑOS VA A LA TAQUILLA 3    TAQUILLA1--->TAQUILLA3
            if (taquilla1->primero->edad>45){
                encolar(taquilla3,desencolar(taquilla1));
            }

            // SI EL CLIENTE QUIERE COMPRAR MÁS DE 2 ENTRADAS  TAQUILLA1--->TAQUILLA2
            else if (taquilla1->primero->cantEntradas>2){
                encolar(taquilla2,desencolar(taquilla1));
            }

            else{
                encolar(&taquillaAux,desencolar(taquilla1)); // TAQUILLA 1---> TAQUILLA AUX

            }

        }

        // transferimos los elementos de la cola auxiliar a la cola original.
        transferir_cola(taquilla1,&taquillaAux);
        return;
    }
        


    printf("\nLa taquilla principal no contiene clientes\n\n...");
    return ;


}


void liberar_cola(Cola*cola){
    if (cola->primero!=NULL){
        while (cola->primero!=NULL)
        {
            Nodo*aux=cola->primero;
            printf("\nEliminando cliente : %s",aux->nombre);
            cola->primero=cola->primero->siguiente;
            free(aux);

        }
        return;
        }
    printf("\nLa taquilla no contiene clientes.....\n\n");
    return;
}


int main(){

    int bucle_cond=0,menu;
    Cola taquilla1=crearCola();

    printf("\n-------- BIENVENIDO A LA TAQUILLA #1 --------\n");
    while(bucle_cond==0){
        Nodo*cliente=crearNodo();
        encolar(&taquilla1,cliente);
        printf("\n\nDesea poder agregar un nuevo cliente? \nA)SI = 1\nB)NO = 0\nINGRESAR OPCION: ");
        scanf("%d",&menu);
        getchar(); // Tomamos el salto de línea del scanf().
        if (menu==0){
            bucle_cond=1;
        }
    }

    // Creamos las 2 taquillas adicionales : 1)TAQUILLA #2 (Personas que comparán más de 2 entradas), 2) TAQUILLA#3 (Personas mayores de 45 años).
    Cola taquilla2=crearCola();
    Cola taquilla3=crearCola();
    
    // Asignamos a los clientes a las taquillas correspondientes.
    asignacionTaquillas(&taquilla1,&taquilla2,&taquilla3);






    printf("\n\n --- TAQUILLAS CON SUS RESPECTIVOS CLIENTES ---\n\n");
    
    printf("\n\n------- TAQUILLA #1 --------\n");
    mostrarCola(&taquilla1);

    
    printf("\n\n------- TAQUILLA #2 --------\n");
    mostrarCola(&taquilla2);

    printf("\n\n------- TAQUILLA #3 --------\n");
    mostrarCola(&taquilla3);

    

    // Liberamos la memoria reservada para los nodos (clientes.)
    printf("\n\n \n|------- LIBERANDO MEMORIA -------|\n");

    printf("\n\n------- TAQUILLA #1 --------\n");
    liberar_cola(&taquilla1);


    printf("\n\n------- TAQUILLA #2 --------\n");
    liberar_cola(&taquilla2);


    printf("\n\n------- TAQUILLA #3 --------\n");
    liberar_cola(&taquilla3);



}



