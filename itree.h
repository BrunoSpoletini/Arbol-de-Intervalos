#ifndef __ITREE_H__
#define __ITREE_H__

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _intervalo{
  double inicio;
  double final;
}intervalo;


typedef struct _iNodo{
  intervalo *dato;
  int altura;
  struct _iNodo *ant;
  struct _iNodo *sig;
} iNodo;

typedef iNodo *iTree;

// Crea un arbol de intervalos vacio
iTree itree_crear();

// Destruye un arbol de intervalos
void itree_destruir(iTree raiz);

// Inserta un intervalo en un arbol de intervalos
iTree itree_insertar(iTree raiz, intervalo dato);

// Elimina un intervalo de un arbol de intervalos
iTree itree_eliminar(iTree raiz, intervalo dato);

// Determina si un intervalo se interseca con alguno de los intervalos del arbol y, en caso afirmativo,
// retorna un apuntador al nodo correspondiente.
iTree itree_intersecar(iTree raiz, intervalo intersecar);

// Recorrido primero en profundidad del arbol de intervalos
void itree_recorrer_dfs(iTree raiz);

// Recorrido primero a lo ancho del arbol de intervalos
void itree_recorrer_bfs(iTree raiz);

#endif /* __ITREE_H__ */
