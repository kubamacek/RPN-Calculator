#include "rpn.h"
#include <ctype.h>

/* MODUL ZAJMUJACY SIE OBSULGA KALKULATORA RPN */

/* kalkulator ma dzialac na liczbach calkowitych w odwrotnej notacji polskiej - ma standardowo pobierac liczby i znaki. 
   w przypadku pobrania liczby ma za zadanie wrzucic ja na stos.
   w przypadku pobrania znaku kalkulator zabiera ze stosu dwie ostatnie liczby, przeprowadza wskazana operacje i wynik wedruje na stos.
   
   SYMBOLE OPERACJI:
   
   + dodawanie
   - odejmowanie
   * mnozenie
   / dzielenie
 
   DODATKOWE FUNKCJE:

   # usuwa ostatnio wprowadzona liczbe(korekcja bledow przy wpisywaniu)
   $ zamiana miejscami dwoch liczb na szczycie stosu
   & zduplikowanie argumentu na szczycie stosu
   ? drukuje zawartosc calego stosu argumentow

   q KONCZY PROGRAM*/

int obslugakalkulatora(t_elem **stos, int *koniec)
{
  int i=0,j=0;
  int st1,st2;
  int pom1,pom2;
  int wynik, dodatnia, ujemna;
  char tab[100];

  while((pom1=getchar())!='\n')
    {
      if(isdigit(pom1) || pom1=='-')
      	{
	  if(pom1=='-')
	    {
	      if((pom2=getchar())==' ' || pom2=='\n') 
		{
		  if(empty(stos)<2)
		    {
		      fprintf(stderr,"Za malo liczb na stosie!\n");
		      break;
		    }
		  st1=pop(stos);
		  st2=pop(stos);
		  wynik=st2-st1;
		  printf("%d\n", wynik);
		  push(stos,wynik);
		}
	      ungetc(pom2,stdin);
	      
	      if(isdigit(pom1=getchar()));
		{
		  i=0;
		  tab[i++]=pom1; 
		  while(isdigit(tab[i++]=pom1=getchar())); 
		  tab[i]='\0';
		  dodatnia=atoi(tab);
		  ujemna=0-dodatnia;
		  push(stos,ujemna);
		}
	    }
	  else
	    {
	      i=0;
	      tab[i++]=pom1; 
	      dodatnia=atoi(tab); 
	      ujemna=0-dodatnia;
	      push(stos,dodatnia); 
	    }
	}
      switch(pom1) 
	{
	case '+': 
	  if(empty(stos)<2)
	    {
	      fprintf(stderr,"Za malo liczb na stosie!\n");
	      break;
	    }
	  st1=pop(stos);
	  st2=pop(stos);
	  wynik=st2+st1;
	  printf("%d\n",wynik);
	  push(stos,wynik);
	  break;

	case '*': 
	  if(empty(stos)<2)
	    {
	      fprintf(stderr,"Za malo liczb na stosie!\n");
	      break;
	    }
	  st1=pop(stos);
	  st2=pop(stos);
	  wynik=st2*st1;
	  printf("%d\n",wynik);
	  push(stos,wynik);
	  break;

        case '/': 
	  if(empty(stos)<2)
	    {
	      fprintf(stderr,"Za malo liczb na stosie!\n");
	      break;
	    }
	  st1=pop(stos);
	  if(st1==0)
	    {
	      fprintf(stderr,"NIE WOLNO DZIELIC PRZEZ ZERO!\n");
	      push(stos,st1);
	      break;
	    }
	  st2=pop(stos);
	  wynik=st2/st1;
	  printf("%d\n",wynik);
	  push(stos,wynik);
	  break;

	case '#': 
	  if(empty(stos)<1)
	    {
	      fprintf(stderr,"Brak liczb na stosie!\n");
	      break;
	    }
	  pop(stos);	  
	  break;
	
        case '$': 
	  if(empty(stos)<2)
	    {
	      fprintf(stderr,"Za malo liczb na stosie!\n");
	      break;
	    }
	  st1=pop(stos);
	  st2=pop(stos);
	  push(stos,st1);
	  push(stos,st2);
	  break;

	case '&': 
	  if(empty(stos)<1)
	    {
	      fprintf(stderr,"Brak liczb na stosie!\n");
	      break;
	    }
	  st1=pop(stos);
	  push(stos,st1);
	  push(stos,st1);
	  break;

	case '?': 
	  if(empty(stos)<1)
	    {
	      fprintf(stderr,"Brak liczb na stosie!\n");
	      break;
	    }
	  print(stos);
	  break;

        case 'q':
	 *koniec=1;
	 break;
	}
    }
  return 0;
}
	  
	
