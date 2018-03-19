#include "modul.h"
#include <stdio.h>
#include <stdlib.h>

/* funkcja push pozwalajaca na umieszczenie na stosie elementu int */

void push(t_elem **stos,int elem)
{
  t_elem *pom;
  pom=(t_elem*)malloc(sizeof(t_elem));
  pom->dana=elem;
  pom->nast=*stos;
  *stos=pom;
}

/* funkcja pop zdejmujaca element int ze stosu, zwraca ten element */

int pop(t_elem **stos)
{
  t_elem *pom;
  int elem;

  if(stos==NULL)
    fprintf(stderr,"stos pusty!");
  else{
    elem=(*stos)->dana;
    pom=*stos;
    *stos=(*stos)->nast;
    free(pom);
    return elem;
  }
}

/* funkcja empty sprawdzajaca czy stos jest pusty, zlicza elementy */

int empty(t_elem **stos)
{
  int licz;
  t_elem *elem;

  if(*stos==NULL)
    return 0;
  elem=*stos;
  for(licz=0;elem!=NULL;licz++)
    elem=elem->nast;
  return licz;
}

/* funkcja print wyswietlajaca na wyjsciu elementy stosu */

void print(t_elem **stos)
{
  t_elem *elem;
  elem=*stos;
  while(elem!=NULL){
    printf("%d",elem->dana);
    elem=elem->nast;
  }
  printf("\n");
}
