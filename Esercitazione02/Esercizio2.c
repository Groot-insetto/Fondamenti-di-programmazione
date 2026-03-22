/*
Name: Giovanni R.
Exercise text: Scrivere un programma in linguaggio C che chieda all'utente di inserire una distanza percorsa in chilometri 
 (valore reale) e un tempo espresso in ore e minuti (due valori interi distinti). Il programma deve calcolare e 
 stampare la velocità media in km/h.
*/

#include <stdio.h>


//Prototipo
double calcoloMedia (float km, float time);


//Funzione main
void main (void){

	float km, time;
	km=time=0;

	printf("Inserisici distanza in kilometri: ");
	scanf("%f",&km);

	printf("Inserisci tempo di percorrenza in ore e minuti (esempio : 1.30 = 1 ora e 30 minuti): ");
	scanf("%f",&time);

	printf("La velocita\' media e\': %.2f\n", calcoloMedia(km, time));

}


//Definizione della funzione del calcolo della media di percorrenza
double calcoloMedia (float km, float time){

	return km/time;

}
