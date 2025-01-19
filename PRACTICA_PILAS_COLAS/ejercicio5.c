#include <stdio.h>
#define N 10  // Para este ejemplo he decidido que el arreglo tendrá un tamaño de 10 elementos como máximo.

typedef struct {
    int datos[N];
    int frente;
    int final;
    int tamano;
} Bicola;

void CrearBicola(Bicola *bicola) {
    bicola->frente = -1;
    bicola->final = -1;
    bicola->tamano = 0;
}

int BicolaVacia(Bicola *bicola) {
    return bicola->tamano == 0;
}

int PonerFrente(Bicola *bicola, int elemento) {
    if (bicola->tamano == N) {
        return 0; // La bicola está llena
    }
    if (bicola->frente == -1) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->frente = (bicola->frente - 1 + N) % N;
    }
    bicola->datos[bicola->frente] = elemento;
    bicola->tamano++;
    return 1;
}

int PonerFinal(Bicola *bicola, int elemento) {
    if (bicola->tamano == N) {
        return 0; // La bicola está llena
    }
    if (bicola->final == -1) {
        bicola->frente = bicola->final = 0;
    } else {
        bicola->final = (bicola->final + 1) % N;
    }
    bicola->datos[bicola->final] = elemento;
    bicola->tamano++;
    return 1;
}

int QuitarFrente(Bicola *bicola) {
    if (BicolaVacia(bicola)) {
        return -1; // La bicola está vacía
    }
    int elemento = bicola->datos[bicola->frente];
    bicola->frente = (bicola->frente + 1) % N;
    bicola->tamano-=1;
    if (bicola->tamano == 0) {
        bicola->frente = bicola->final = -1;
    }
    return elemento;
}



int Frente(Bicola *bicola) {
    if (BicolaVacia(bicola)) {
        return -1; // La bicola está vacía
    }
    return bicola->datos[bicola->frente];
}

int Final(Bicola *bicola) {
    if (BicolaVacia(bicola)) {
        return -1; // La bicola está vacía
    }
    return bicola->datos[bicola->final];
}

void ImprimirBicola(Bicola *bicola) {
    if (BicolaVacia(bicola)) {
        printf("La bicola está vacía.\n");
        return;
    }
    printf("Elementos en la bicola: ");
    for (int i = 0; i < bicola->tamano; i++) {
        printf("%d ", bicola->datos[(i)]);
    }
    printf("\n");
}


int QuitarFinal(Bicola *bicola) {
    if (BicolaVacia(bicola)) {
        return -1; // La bicola está vacía
    }
    int elemento = bicola->datos[bicola->final];
    bicola->final = (bicola->final - 1 + N) % N;
    bicola->tamano-=1;
    if (bicola->tamano == 0) {
        bicola->frente = bicola->final = -1;
    }
    return elemento;
}

int main() {
    Bicola bicola;
    CrearBicola(&bicola);

    PonerFinal(&bicola, 5);
    PonerFinal(&bicola, 10);
    PonerFinal(&bicola, 15);
    PonerFinal(&bicola, 20);
    PonerFinal(&bicola, 10);
    PonerFrente(&bicola,1);

    ImprimirBicola(&bicola);
        
    printf("Elemento en el frente: %d\n", Frente(&bicola));
    printf("Elemento en el final: %d\n", Final(&bicola));

    QuitarFrente(&bicola);
    QuitarFinal(&bicola);
    printf("Bicola vacía: %d\n", BicolaVacia(&bicola));

    return 0;
}