#include <stdio.h>

//Prototipo
void caratterizzazioneCarattere(char a);

void main(void){

    unsigned char carattere;
    carattere = 0;

    //Controllo su input critico
    do{
    printf("Inserisci carattere: ");
    scanf("%c",&carattere);
    }while(!((carattere >= 65 && carattere <= 90) || (carattere >= 95 && carattere <= 122)));

    caratterizzazioneCarattere(carattere);
    
}


void caratterizzazioneCarattere (char a){

    if ((a == 65 || a == 97) ||
        (a == 69 || a == 101) ||
        (a == 73 || a == 105) ||
        (a == 79 || a == 111) || 
        (a == 85 || a == 117)  ){

            printf("Il carattere %c e\' una vocale\n",a);
    } else {
        printf("Il carattere %c e\' una consonate\n",a);
    }

}