#ifndef __INTERVALO_H__
#define __INTERVALO_H__

typedef struct _intervalo{
  double inicio;
  double final;
}intervalo;

// Devuelve 1 si los intervalos se intersecan, 0 si no lo hacen.
int intersecar(intervalo primero, intervalo segundo);

// Devuelve 1 si se trata de un intervalo valido, 0 si no lo es.
int intervalo_valido(intervalo dato);

// Crea un intervalo en memoria con los datos recibidos y devuelve un puntero a este.
intervalo* llenar_intervalo(intervalo dato);

#endif /* __INTERVALO_H__ */