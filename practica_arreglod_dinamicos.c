#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[40];
    int edad;
}Persona;


typedef struct 
{
    Persona*arreglo_personas;
    int cant_personas;
}Arreglo;


Arreglo crear_arreglo(){
    Persona*array=(Persona*)malloc(sizeof(Persona));
    Arreglo arreglo={array,0};
    return arreglo;

    
}


void crear_persona(Arreglo*array){
    printf("Ingresar nombre del usuario: ");
    fgets(array->arreglo_personas[array->cant_personas].nombre,40,stdin);
    printf("Ingresar edad del usuario: ");
    scanf("%d",&array->arreglo_personas[array->cant_personas].edad);

    getchar();

    array->cant_personas+=1;

}

void imprimir_elementos(Arreglo*array){
    for (int i=0;i<array->cant_personas;i++){
        printf("Nombre: %s",array->arreglo_personas[i].nombre);
        printf("Edad: %d\n",array->arreglo_personas[i].edad);
    }


}


int main(){

    Arreglo array=crear_arreglo();
    crear_persona(&array);
    imprimir_elementos(&array);




}