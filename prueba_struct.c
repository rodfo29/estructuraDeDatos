#include <stdio.h>
#include <stdlib.h>


typedef struct 
{
    char nombre[20];
}Persona;

Persona*crear_persona(){

    Persona*persona=(Persona*)malloc(sizeof(Persona));
    printf("Ingresar nombre de la persona: ");
    fgets(persona->nombre,20,stdin);
    return persona;



}

int main(){

    Persona*persona=crear_persona();
    printf("El nombre de la persona es: %s\n",persona->nombre);



}