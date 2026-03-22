/*
Name: Giovanni R.
Exercise text: Scrivere un programma in linguaggio C che chieda all'utente di inserire un carattere maiuscolo dell'alfabeto 
 inglese (da 'A' a 'Z') e un valore intero di spostamento compreso tra 1 e 25. Il programma deve calcolare e 
 stampare il carattere ottenuto avanzando di tante posizioni nell'alfabeto quante indicate dallo spostamento, 
 con avvolgimento circolare (dopo 'Z' si riparte da 'A'). 
*/
#include <stdio.h>

//Funzione main
void main (void){

	//dichiarazione
	char carattere;
	short int spost;

	//Inizializzazione
	carattere = 65;
	spost=0;

	printf("Inserisci lettera maiuscola: ");
	scanf("%c",&carattere);

	printf("Inserisci valore di spostamento: ");
	scanf("%hd",&spost);

	printf("La lettera dopo lo spostamento e\': %c\n", ((carattere - 65 + spost)%26) + 65);

}
