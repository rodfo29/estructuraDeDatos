#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int valor;
    struct Nodo*next;
}Nodo;





int main(){
    Nodo*nuevo_nodo=(Nodo*)malloc(sizeof(Nodo));
    nuevo_nodo->next=NULL;
    printf("\nDirección del nodo: %p\nDirección del campo next: %p\n",nuevo_nodo,nuevo_nodo->next);
    printf("%d\n",nuevo_nodo==nuevo_nodo->next);


}