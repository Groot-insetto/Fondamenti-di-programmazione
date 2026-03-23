/*
Name: Giovanni R.
Exeecise text: Implementare in C dei programmi per risolvere i seguenti problemi: 
	1. Calcolare il valore assoluto di un numero in input.  
	2. Permettere all’utente di inserire due numeri e un operatore tra +, -, /, * e stampare il risultato 
	dell’operazione.  
	3. Scambiare il valore di due variabili intere. 
*/
#include <stdio.h>

//Prototipi
int valoreAssluto (void);
float eseguiOperazione(void);
void scambioVariabili(int variabile1, int varabile2);

//Funzione main
void main (void){

    short int scelta;
    scelta = 0;

    printf("Inserisici:\t\n 1 -> calcolare il valore assoluto di un numro;\n 2 -> eseguire una data operazione tra due numeri;\n 3 -> scambiare il valore di due variabili\n");
    scanf("%hd",&scelta);

    //Purificazione input
    do{
        //Gestione scelta utente
        switch (scelta){
            case 1:
                int numero = valoreAssluto();
                printf("Il numero, nel suo valore assoluto, e\': %d\n",numero);
            break;

            case 2:
                float risultato = eseguiOperazione();
                printf("Il risultato dell'operaione scelta è: %0.2f\n", risultato);
            break;

            case 3:
                //Dichiarazione
                int var1, var2;
                //Inizzializzazione
                var1 = var2 = 0;

                //Fase di input
                printf("Inserisci valore prima variabile: ");
                scanf("%d",&var1);

                printf("Inserisci valore seconda variabile: ");
                scanf("%d",&var2);

                scambioVariabili(var1, var2);
                
            break;
                
            default: 
                printf("Errore: imput non valido. Riprova!");
        }
    }while(!(scelta>=1&&scelta<=3));

}


//Calcolo valore assoluto di un numero
int valoreAssluto(void){

    int numero;
    numero = 0;

    printf("Inserisci il numero:");
    scanf("%d",&numero);

    if(numero >=0)
        return numero;
    else 
        return -(numero);

}


//Scelta operazione tra due numeri
float eseguiOperazione(void){

    //dichiarazioni
    float numero1, numero2;
    short int operatore;
    //Inizializzazioni
    numero1 = numero2 = 0;
    operatore = 0;

    printf("Inserisci il primo numero: ");
    scanf("%f",&numero1);

    printf("Inserisci il secondo numero: ");
    scanf("%f",&numero2);

    //Controllo su input critico
    do{
    printf("Inserisci scelta operazione:\n 1: +;\n 2: -;\n 3: *;\n 4: /\n");
    scanf("%hd",&operatore);
    }while(!(operatore >= 1 && operatore <= 4));

    switch(operatore){

        case 1:
            return (numero1+numero2);
        break;

        case 2:
            return (numero1-numero2);
        break;

        case 3:
            return (numero1*numero2);
        break;

        case 4:
		if(numero2 == 0){
			printf("Calcolo impossibile da eseguire");
		}else {
			return (numero1/numero2); 
		}
        break;

    }    

}

//Funzione di scambio variabili
void scambioVariabili(int var1, int var2){

    int aux;

    aux = var1;
    var1 = var2;
    var2 = aux;

    printf("Valore variabile 1: %d, valore variabile 2: %d\n",var1, var2);
}
