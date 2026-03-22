/*
Name: Giovanni R.
Exercise text: Esercizio 3 
Implementare in C un programma che chieda all’utente di inserire tre numeri interi (n1, n2, n3) e li ordini in 
 modo crescente e stampi i nuovi valori delle tre variabili.
*/
#include <stdio.h>

//Prototipo
void ordinamentoCrescente(int n1, int n2, int n3);

void main(void){

    int num1, num2, num3;
    num1 = num2 = num3 = 0;

    printf("Inserisci numero 1: ");
    scanf("%d",&num1);

    printf("Inserisci numero 2: ");
    scanf("%d",&num2);

    printf("Inserisci numero 3: ");
    scanf("%d",&num3);

    ordinamentoCrescente(num1, num2, num3);

}

void ordinamentoCrescente(int n1, int n2, int n3){

    int aux;
    aux = 0;
    while(!(n1<n2 && n2<n3)){
        if(n1>n2){
            aux = n1;
            n1 = n2;
            n2 = aux;
        }

        if(n2>n3){
            aux = n2;
            n2 = n3;
            n3 = aux;
        }
    }

    printf ("n1: %d; n2: %d; n3: %d\n", n1, n2, n3);
}
