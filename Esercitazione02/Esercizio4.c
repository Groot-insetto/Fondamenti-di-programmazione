/*
Name: Giovanni R.
Exercise text: Scrivere un programma in linguaggio C che, dato un numero intero a tre cifre inserito dall'utente (compreso 
 tra 100 e 999), estragga e stampi separatamente la cifra delle centinaia, delle decine e delle unità.
*/
#include <stdio.h>


//Funzione main
void main (void){

	int num;
	num = 0;

	printf("Inserisci un numero di tre crifre (100-999): ");
	scanf("%d",&num);

	printf("La cifra delle centinaria e\': %d; la cifra delle decine e\': %d; la cifra delle unita\' e\': %d\n", (num/100), ((num/10)%10), (num%10));

}
