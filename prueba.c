#include <stdio.h>

int main(){
    
    int z=0;
    int *ptr_z=&z;
    printf("la dirección de memoria del puntero ptr es: %p \n",ptr_z );

    int b=*ptr_z++; // devuelve el contenido de la variable y luego se desplaza 1 posición.
    int b=(*ptr_z)++; // asigna el contenido, y luego le suma directamente a la variable a la que apunta
    printf("la dirección de memoria del puntero ptr es: %p \n",ptr_z);
    
    printf("El numero es: %d",z);


}


/**ptr_z++:

Desreferencia el puntero ptr_z y obtiene el valor al que apunta.
Luego incrementa el puntero ptr_z para que apunte a la siguiente dirección de memoria.
El valor de b será el valor original de z (0), y ptr_z se incrementará.
(*ptr_z)++:

Desreferencia el puntero ptr_z y obtiene el valor al que apunta.
Luego incrementa el valor al que apunta ptr_z.
El valor de b será el valor original de z (0), y z se incrementará a 1.
++*ptr_z:

Incrementa el valor al que apunta ptr_z antes de usarlo.
El valor de b será el valor incrementado de z (1), y z se incrementará a 1.*/