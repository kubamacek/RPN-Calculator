#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "rpn.h"

int main()
{
  t_elem *stos=NULL;
  int koniec=0;
  printf("KALKULATOR CZTERODZIALANIOWY RPN dla liczb calkowitych.\n\n");
  printf("-kalkulator czyta dane ze standardowego wejscia\n");
  printf("-w strumieniu wejsciowym pojawiac sie maja liczby i symbole operacji: + - * /\n");
  printf("-gdy pojawi sie liczba, zostanie ona umieszczona na stosie\n");
  printf("-gdy pojawi sie symbol operacji, zostanie wykonane dzialanie na dwoch liczbach z poczatku stosu\n");
  printf("-w razie zbyt malej liczby elementow na stosie zostanie wyswietlony blad\n");
  printf("-wynik operacji zostaje umieszczony na szczycie stosu\n\n");
  printf("KALKULATOR CZTERODZIALANIOWY RPN dla liczb całkowitych zostal wyposazony w dodatkowe funkcje:\n\n");
  printf("# - powoduje usuniecie ostatnio wprowadzonej liczby ze stosu\n");
  printf("$ - powoduje zamiane miejscami dwoch liczb na szczycie stosu\n");
  printf("& - powoduje zduplikowanie liczby znajdujacej sie na szczycie stosu\n");
  printf("? - powoduje wydruk liczb znajdujacych sie na stosie\n\n");
  printf("q - konczy prace programu\n");
  do
    {
      obslugakalkulatora(&stos,&koniec);
    }
  while(koniec==0);
  printf("\n");
}
