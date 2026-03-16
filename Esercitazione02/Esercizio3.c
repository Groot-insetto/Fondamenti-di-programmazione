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
