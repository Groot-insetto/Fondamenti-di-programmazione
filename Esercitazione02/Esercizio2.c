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
