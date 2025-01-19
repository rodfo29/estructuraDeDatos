#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor, altura;
    struct nodo *izq, *der;
} nodo_t;

int obtenerAltura(nodo_t *nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

nodo_t *rotacionDerecha(nodo_t *nodoDesbalanceado) {
    nodo_t *nuevaRaiz = nodoDesbalanceado->izq;
    nodo_t *subarbolDerecho = nuevaRaiz->der;

    nuevaRaiz->der = nodoDesbalanceado;
    nodoDesbalanceado->izq = subarbolDerecho;

    nodoDesbalanceado->altura = max(obtenerAltura(nodoDesbalanceado->izq), obtenerAltura(nodoDesbalanceado->der)) + 1;
    nuevaRaiz->altura = max(obtenerAltura(nuevaRaiz->izq), obtenerAltura(nuevaRaiz->der)) + 1;

    return nuevaRaiz;
}

nodo_t *rotacionIzquierda(nodo_t *nodoDesbalanceado) {
    nodo_t *nuevaRaiz = nodoDesbalanceado->der;
    nodo_t *subarbolIzquierdo = nuevaRaiz->izq;

    nuevaRaiz->izq = nodoDesbalanceado;
    nodoDesbalanceado->der = subarbolIzquierdo;

    nodoDesbalanceado->altura = max(obtenerAltura(nodoDesbalanceado->izq), obtenerAltura(nodoDesbalanceado->der)) + 1;
    nuevaRaiz->altura = max(obtenerAltura(nuevaRaiz->izq), obtenerAltura(nuevaRaiz->der)) + 1;

    return nuevaRaiz;
}

int obtenerFactorEquilibrio(nodo_t *nodo) {
    if (nodo == NULL)
        return 0;
    return obtenerAltura(nodo->izq) - obtenerAltura(nodo->der);
}

nodo_t *insertar(nodo_t *raiz, int valor) {
    if (raiz == NULL) {
        nodo_t *nuevoNodo = (nodo_t *)malloc(sizeof(nodo_t));
        nuevoNodo->valor = valor;
        nuevoNodo->izq = nuevoNodo->der = NULL;
        nuevoNodo->altura = 1;
        return nuevoNodo;
    }

    if (valor < raiz->valor)
        raiz->izq = insertar(raiz->izq, valor);
    else if (valor > raiz->valor)
        raiz->der = insertar(raiz->der, valor);
    else
        return raiz;

    raiz->altura = 1 + max(obtenerAltura(raiz->izq), obtenerAltura(raiz->der));

    int balance = obtenerFactorEquilibrio(raiz);

    if (balance > 1 && valor < raiz->izq->valor)
        return rotacionDerecha(raiz);

    if (balance < -1 && valor > raiz->der->valor)
        return rotacionIzquierda(raiz);

    if (balance > 1 && valor > raiz->izq->valor) {
        raiz->izq = rotacionIzquierda(raiz->izq);
        return rotacionDerecha(raiz);
    }

    if (balance < -1 && valor < raiz->der->valor) {
        raiz->der = rotacionDerecha(raiz->der);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

nodo_t *nodoMinimo(nodo_t *nodo) {
    nodo_t *actual = nodo;

    while (actual->izq != NULL)
        actual = actual->izq;

    return actual;
}

nodo_t *eliminar(nodo_t *raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->izq = eliminar(raiz->izq, valor);
    else if (valor > raiz->valor)
        raiz->der = eliminar(raiz->der, valor);
    else {
        if ((raiz->izq == NULL) || (raiz->der == NULL)) {
            nodo_t *temp = raiz->izq ? raiz->izq : raiz->der;

            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else
                *raiz = *temp;

            free(temp);
        } else {
            nodo_t *temp = nodoMinimo(raiz->der);

            raiz->valor = temp->valor;

            raiz->der = eliminar(raiz->der, temp->valor);
        }
    }

    if (raiz == NULL)
        return raiz;

    raiz->altura = 1 + max(obtenerAltura(raiz->izq), obtenerAltura(raiz->der));

    int balance = obtenerFactorEquilibrio(raiz);

    if (balance > 1 && obtenerFactorEquilibrio(raiz->izq) >= 0)
        return rotacionDerecha(raiz);

    if (balance > 1 && obtenerFactorEquilibrio(raiz->izq) < 0) {
        raiz->izq = rotacionIzquierda(raiz->izq);
        return rotacionDerecha(raiz);
    }

    if (balance < -1 && obtenerFactorEquilibrio(raiz->der) <= 0)
        return rotacionIzquierda(raiz);

    if (balance < -1 && obtenerFactorEquilibrio(raiz->der) > 0) {
        raiz->der = rotacionDerecha(raiz->der);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

void imprimirArbol(nodo_t *raiz, int espacio) {
    if (raiz == NULL)
        return;

    espacio += 10;

    imprimirArbol(raiz->der, espacio);

    printf("\n");
    for (int i = 10; i < espacio; i++)
        printf(" ");
    printf("%d\n", raiz->valor);

    imprimirArbol(raiz->izq, espacio);
}

int main() {
    nodo_t *raiz = NULL;
    int opcion = 0;
    int valor;

    while (opcion != 4) {
        printf("\nMenu:\n");
        printf("1. Insertar\n");
        printf("2. Eliminar\n");
        printf("3. Imprimir\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion == 1) {
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &valor);
            raiz = insertar(raiz, valor);
        } else if (opcion == 2) {
            printf("Ingrese el valor a eliminar: ");
            scanf("%d", &valor);
            raiz = eliminar(raiz, valor);
        } else if (opcion == 3) {
            imprimirArbol(raiz, 0);
        } else if (opcion == 4) {
            printf("Saliendo...\n");
        } else {
            printf("Opcion invalida\n");
        }
    }

    return 0;
}
