#include <stdio.h>


float x, *px, a[5];
/*float x, *px, a[5];
¿Cuáles de las siguientes asignaciones son correctas y cuales son incorrectas?
En el caso de las correctas explique qué hacen y para las incorrectas justifique
su respuesta.*/

x = *px; // Bien, se le está asignando a la variable x el contenido de la direccion de memoria que se encuentra almacenada en el puntero px
*px = x; // Bien, Ya que el puntero px almacena la dirección de memoria de otra variable, al desreferenciar (usando el *) a la variable que le pertenece la direccion de memoria que almacena px le asignamos el valor de la variable.
px = &x; // Bien, hacemos que el puntero px almacene la dirección de memoria de la variable x.
&x = px; // Mal, Esta asignación es inválida ya que están intentado que la la dirección de memoria de la variable x sea la dirección de memoria que contiene el puntero px.


&(x+1) = x; // Mal, estamos intentando asignarle a la direccion de memoria de la variable x +1 el contenido de la variable x.
*(&(x+1)) = x; // Mal, ya que se está intentando desreferenciar la direccón de memoria de la variable x luego de sumarle  1 para asignale el valor de x lo cual es incorrecto.

&(x)+1 = x; // Mal, estamos haciendo que la direccón de memoria de que se encuentre a 1 desplazamiento de la dirección de la variable x sea igual al valor que almacena x.
*(&(x)+1) = x; //Mal, estamos accediendo al valor de la dirección de memoria que se encuentra a 1 desplazamiento con respecto a la dirección de la variable x para luego asignarle el valor de x.
    




x = a; // Mal, Al ser la variable x de tipo flotante esta solo puede contener valores que sean de dicho tipo de dato. Acá estamos asignandole a la variable x direccón de memoria del primero elemento del arreglo. por lo tanto, es inválida esta asignación.
x = a[0]; // Bien, le estamos asignando a la variable x el primero elemento del arreglo a.

x = *(a[1]);// Mal, ya que estamos intentando desreferenciar el 2do elemento del arreglo y luego asignarselo a la variable x. 
x = (*a)[2]; // Mal, estamos bàsicamente asigandole a la variable x el valor de la dirección de que almacena la variable a



x = a[3+1]; // Bien, estamos asignandole a la variable x el 5 elemento del arreglo "a".
x = a[3]+1; // Bien, estamos asignandole a la variable x el 4 elemento del arreglo +1.
x = &((a[3])+1); // Mal, Se le está asignando la dirección de memoria del 4 elemento  + 1 a la variable x (variable tipo flotante) lo cuál carece de sentido.
x = &(a[3])+1;  // Mal, se le está asignando a la variable x la dirección de memoria del 4 elemento del arreglo +1 lo que primero nos daría la dirección del 5to elemento, además sería un error ya que la variable x no puede almacenas direcciones de memoria.
x = *(&(a[3])+1); // Bien, a la variable x se le está asignando el contenido del 5to elemento del arreglo.
px = a; // Bien, ya que la variable a es un puntero al primero elemento del arreglo, lo que tiene como consecuencia que el puntero px también contenga la dirección de memoria del primer elemeto.
px = a[0]; // Mal, ya que si usamos esta sintáxis estaríamos asignandole al puntero px el valor del primero elemento del arreglo, no su dirección de memoria. 
px = &(a[4]); //Bien, estamos asignandole al puntero px la dirección de memoria del 5to elemento del arreglo.
