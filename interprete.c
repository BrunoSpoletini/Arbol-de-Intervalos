#include "itree.h"
#include <string.h>
#define MAX_LINEA 1001

ITree leer_entrada(ITree raiz) {
  char comando, entrada[MAX_LINEA];
  ITree nodo;
  Intervalo intervaloAux;
  int largoEntrada;

  while (strcmp(fgets(entrada, sizeof(entrada), stdin), "salir\n") != 0) {

    largoEntrada = strlen(entrada) - 1; // -1 por el \n
    if (largoEntrada > 0)
      entrada[largoEntrada] = '\0';     // reemplazo el \n por un \0

    if (largoEntrada == 3) {
      if (strcmp(entrada, "dfs") == 0) {
        itree_recorrer_dfs(raiz, imprimir_intervalo);
        printf("\n");
      } else if (strcmp(entrada, "bfs") == 0) {
        itree_recorrer_bfs(raiz, imprimir_intervalo);
        printf("\n");
      } else
          printf("Comando no reconocido\n");

    } else if (largoEntrada >= 7) {     // minima cantidad de caracteres "i [a,b]" es 7
      if (sscanf
          (entrada, "%c [%lf,%lf] \n", &comando, &intervaloAux.inicio,
           &intervaloAux.final) == 3) {

        if (intervalo_valido(intervaloAux) && entrada[1] == ' ' && entrada[2] == '[') {
          if (entrada[0] == 'i')
            raiz = itree_insertar(raiz, intervaloAux);

          else if (entrada[0] == 'e')
            raiz = itree_eliminar(raiz, intervaloAux);

          else if (entrada[0] == '?') {
            nodo = itree_intersecar(raiz, intervaloAux);
            if (nodo == NULL)
              printf("No\n");
            else {
              printf("Si, ");
              imprimir_intervalo(nodo);
              printf("\n");
            }
          } else
            printf("Comando no reconocido\n");
        } else
          printf("Intervalo invalido\n");
      } else
        printf("Entrada invalida\n");
    } else
      printf("Largo de la entrada incorrecto\n");
  }
  return raiz;
}

int main() {
  ITree raiz = itree_crear();

  printf
      ("Ingrese i para insertar, e para eliminar, ? para intersecar, dfs, bfs, salir \n");

  raiz = leer_entrada(raiz);

  itree_destruir(raiz);

  return 0;
}
