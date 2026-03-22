/*
Name: Giovanni R.
Exercise text: Implementare in C un programma che chieda all’utente di inserire un numero intero N da tastiera e stampi il 
 valore del fattoriale di N.
*/
#include <stdio.h>

//Prototipo
long double calcoloFattoriale(long double n);


void main(void){

    long double num;
    num = 0;
    
    //Controllo input critico (non esiste il fattoriale di un numero negativo)
    do{
    printf("Inserisci numero: ");
    scanf("%Lf",&num);
    }while(!(num>=0));

    printf("Il fattoriale di %.0Lf e\': %.0Lf\n", num, calcoloFattoriale(num));

}

//Funzione per il calcolo de fattoriale di un numero
long double calcoloFattoriale(long double n){

    if(n <= 1){
        return 1;
    } else {
        int index;
        index = n;
        while(index>1){
            n*=(index-1);
            index--;
        }
        return n;
    }

}
