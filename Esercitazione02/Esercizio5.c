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
