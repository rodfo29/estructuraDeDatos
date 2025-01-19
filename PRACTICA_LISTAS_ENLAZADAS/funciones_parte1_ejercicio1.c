#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valor;
    struct Nodo*siguiente;
}Nodo;


// implementamos de forma recursiva

Nodo*add_endd(Nodo*head,Nodo*nuevo_nodo){

    
    if (head==NULL){
        return nuevo_nodo;
    }

    head->siguiente=add_endd(head->siguiente,nuevo_nodo);
    return head;



}



Nodo*insert(Nodo*head,Nodo*nuevo_nodo){
     
     if (head==NULL || nuevo_nodo->valor<head->valor){
        nuevo_nodo->siguiente=head;
        return nuevo_nodo;
     }
     head->siguiente=insert(head->siguiente,nuevo_nodo);
     return head;
}



Nodo*delete_item(Nodo*head, int value){
    
    if (head==NULL){
        return head;
    }
    if (head->valor==value){
        Nodo*aux=head;
        head=head->siguiente;
        free (aux);
        return head;

        // Nodo*aux=head;
        // head=head->siguiente;
        // free(aux);
        // return head;
    }

    head->siguiente=delete_item(head->siguiente,value);
    
    return head;


}




Nodo*search(Nodo*head,int valor){
    if (head==NULL || head->valor==valor){
        return head;
    }
    return search(head->siguiente,valor);

}


void free_all(Nodo*head){
    if (head!=NULL){
        Nodo*aux=head;
        printf("CHAO NODO CON VALOR %d\n",head->valor);
        head=head->siguiente;
        free(aux);
        return free_all(head);
    }
    return;
}


void print(Nodo*head){
    if (head==NULL){
        return;
    }
    printf("%d ",head->valor);
    return print(head->siguiente);

}

void print_reverse(Nodo*head){
    if (head==NULL){
        return;
    }

    if (head->siguiente==NULL){
        printf("\n%d ",head->valor);
        return;
    }
    print_reverse(head->siguiente);
    printf("%d ",head->valor);

}

int lenght(Nodo*head){
    if (head==NULL){
        return 0;
    }
    return 1+lenght(head->siguiente);
}


int main(){



}