/*
Name: Giovanni R.
Exercise text: Scrivere un programma in linguaggio C che, dato un importo espresso in centesimi (numero intero positivo), 
 calcoli il numero minimo di monete necessarie per rappresentarlo. Le monete disponibili sono da 50, 20, 10, 
 5, 2 e 1 centesimo. 
*/
# include <stdio.h>



//Funzione main
void main (void){

	unsigned int soldi;
	soldi = 0;

	printf("Inserisci valore in centesimi: ");
	scanf("%ud",&soldi);

	printf("Servono: %d monete da 50, ",soldi/50);
	soldi -= (50*(soldi/50));
	printf("%d monete da 20, ", soldi/20);
	soldi -= (20*(soldi/20));
	printf("%d monete da 10, ", soldi/10);
	soldi-= (10*(soldi/10));
	printf("%d monete da 5, ", soldi/5);
	soldi -= (5*(soldi/5));
	printf("%d onete da 2, ", soldi/2);
	soldi -= (2*(soldi/2));
	printf("e %d monete da 1.\n", soldi/1);

}
