// Codigo creado por Cisneros Alejos Maria Cristina 402

#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *izquierda;
    struct Nodo *derecha;
};

struct Nodo *nuevoNodo(int dato) {
    size_t tamanioNodo = sizeof(struct Nodo);
    struct Nodo *nodo = (struct Nodo *) malloc(tamanioNodo);
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

void insertar(struct Nodo *nodo, int dato) {

    if (dato > nodo->dato) {
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            insertar(nodo->derecha, dato);
        }
    } else {
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            insertar(nodo->izquierda, dato);
        }
    }
}

int validar(struct Nodo *nodo, int dato_min, int dato_max){
	if(nodo == NULL){
		return 1;
	}
	if(nodo->dato<dato_min || nodo->dato>dato_max){
		return 0;
	}
	return validar(nodo->izquierda, dato_min, nodo->dato - 1) && validar(nodo->derecha, nodo->dato + 1, dato_max);
}

void validarllamar(struct Nodo *raiz) {
    if (validar(raiz, 6, 17) == 1) {
        printf("El arbol esta correcto.\n");
    } else {
        printf("El arbol no esta correcto.\n");
    }
}

void preorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        printf("%d,", nodo->dato);
        preorden(nodo->izquierda);
        preorden(nodo->derecha);
    }
}

void inorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        inorden(nodo->izquierda);
        printf("%d,", nodo->dato);
        inorden(nodo->derecha);
    }
}

void postorden(struct Nodo *nodo) {
    if (nodo != NULL) {
        postorden(nodo->izquierda);
        postorden(nodo->derecha);
        printf("%d,", nodo->dato);
    }
}

void buscarNodo(struct Nodo *raiz, int dato) {
    if (raiz == NULL) {
        printf("No se encontro el nodo\n");
        return;
    }

    if (dato < raiz->dato) {
        buscarNodo(raiz->izquierda, dato);
    } else if (dato > raiz->dato) {
        buscarNodo(raiz->derecha, dato);
    } else {
        printf("Nodo padre: %d\n", raiz->dato);
        if (raiz->izquierda != NULL) {
            printf("Nodo izquierdo: %d\n", raiz->izquierda->dato);
        } else {
            printf("No tiene nodo izquierdo.\n");
        }
        if (raiz->derecha != NULL) {
            printf("Nodo derecho: %d\n", raiz->derecha->dato);
        } else {
            printf("No tiene nodo derecho.\n");
        }
    }
}

int main(void) {
    struct Nodo *raiz = nuevoNodo(10);
    insertar(raiz, 7);
    insertar(raiz, 6);
    insertar(raiz, 8);
    insertar(raiz, 6);
    insertar(raiz, 13);
    insertar(raiz, 16);
    insertar(raiz, 17);
    
    validarllamar(raiz);
    
    printf("\nPreorden:\n");
    preorden(raiz);
    printf("\nInorden:\n");
    inorden(raiz);
    printf("\nPostorden:\n");
    postorden(raiz);
    printf("\nBusqueda:\n");
    int nodoABuscar = 100;
    buscarNodo(raiz, nodoABuscar);
}



