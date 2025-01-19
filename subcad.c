#include <stdio.h>


int len(char*cadena){
    int i=0;
    while (cadena[i]!='\0')
    {
        i++;
    }
    return i;
}







int cont_subcadena(char*cadena,char*subcad){
    int LongitudCadena=len(cadena);
    int LongitudSubcadena=len(subcad);

    int PosicionesValidas=LongitudCadena-LongitudSubcadena; // determinamos el número de posiciones válidas.
    
    int ContadorApariciones=0;
    int*PtrContApariciones=&ContadorApariciones;


    for (int i=0;i<=PosicionesValidas;i++){
        char*PtrCadena=cadena+i;
        char*PtrSubcadena=(subcad);
        printf("serie :%d\n",i);
        while ((*PtrCadena==*PtrSubcadena) && *PtrSubcadena!='\0')
        {
            printf("caracter actual del puntero PtrSubcadena: %c\n",*PtrSubcadena);
            PtrCadena++;
            PtrSubcadena++;

        }

            // martin\0;
            // martin pinto\0;
        if (*PtrSubcadena=='\0'){
            printf("subcadena encontrada: \n");
            *PtrContApariciones+=1;
            
        }


    }
    return ContadorApariciones;
        




}



int main(){

    char nombre[]="martin";
    char nombre2[]="martin pinto";

    int cantidad_apariciones=cont_subcadena(nombre2,nombre);
    printf("La cantidad de apariciones de la subcadena en la cadena principal es de: %d\n", cantidad_apariciones);




}

// significa que si i es la posición inicial, la última posición que puedes usar es N−M. ya que independientemente el índice que estes en ese momento tendrás en la cadena principal los suficientes caracteres para hacer la comparación. 
// la ecuaciones de n-m lo que permite es eso, que independientemente el indice en el que estes vas a tener m caracteres ( que representan la cantidad de caracteres de la subcadena) restantes para poder hacer la comparación.