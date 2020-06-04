#ifndef __INTERVALO_H__
#define __INTERVALO_H__

typedef struct _intervalo{
  double inicio;
  double final;
}intervalo;

int intersecar(intervalo primero, intervalo segundo);

int intervalo_valido(intervalo dato);

#endif /* __INTERVALO_H__ */