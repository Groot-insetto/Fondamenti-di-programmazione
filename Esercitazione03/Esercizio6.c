/*
Name: Giovanni R.
Exercise text: Implementare in C un programma che stampi i primi N numeri di Fibonacci, con N definito dall’utente. I 
 numeri di Fibonacci sono una sequenza di valori interi che inizia con i due valori fissi 1 e 1 e ogni successivo 
 valore è la somma dei due precedenti.
*/
#include <stdio.h>

//Prototipo
void serieFibonacci(int n);

void main(void){

    unsigned int numeri;
    numeri = 0;

    do{
        printf("Inserisci quanti numeri della serie di Fibonacci vuoi visualizzare (deve essere >=2): ");
        scanf("%d",&numeri);
    }while(!(numeri>=2));

    serieFibonacci(numeri);   

}


//Stampa serie di Fibonacci
void serieFibonacci(int n){

    int Fn_1, Fn_2, prossimoTermine;
    prossimoTermine = Fn_1 = 0;
    Fn_2 = 1;

    printf("0\n1\n");
    
    for(int i = 2; i<=n; i++){
        prossimoTermine = Fn_1 + Fn_2;
        printf("%d\n",prossimoTermine);
        Fn_1 = Fn_2;
        Fn_2= prossimoTermine;
        
    }

}
