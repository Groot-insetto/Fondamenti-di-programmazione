#include <stdio.h>


//Funzione main
void main (void){

	int num;
	num = 0;

	printf("Inserisci un numero di tre crifre (100-999): ");
	scanf("%d",&num);

	printf("La cifra delle centinaria e\': %d; la cifra delle decine e\': %d; la cifra delle unita\' e\': %d\n", (num/100), ((num/10)%10), (num%10));

}
