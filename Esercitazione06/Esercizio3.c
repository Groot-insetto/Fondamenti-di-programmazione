/*
Name: Giovanni R.
Execercise text: Definire una funzione tombola che restituisca un array con i 90 numeri della tombola, selezionando in ordine casuale (senza ripetizioni).
Tenere traccia del numero di chiamate fatte alla funzione rand (incrementare un contatore ogni volta che si chiama la funzione rand e stamparlo alla fine). Testare il codice, scrivere un programma C che utilizzi la funzione anche con più di 90 numeri (ad esempio provare con 50.000 numeri).
Extra: provare a minimizzare il numero di chiamate alla funzione rand, per rendere il programma più efficiente.
*/
/*
Name: Giovanni R.
Execercise text: Definire una funzione tombola che restituisca un array con i 90 numeri della tombola, selezionando in ordine casuale (senza ripetizioni).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TOT_TOMB 90     //Numeri estraibili

///Prototypes
void loadArray(size_t array[], size_t dim_array);
size_t estrazioneNumeri(size_t array[], size_t dim_array);

int main(void){

    size_t numeri_tombola[NUM_TOT_TOMB];
    size_t counter;

    counter = 0;

    // Estrazione numeri
    counter = estrazioneNumeri(numeri_tombola, NUM_TOT_TOMB);

    //Output dell'array dopo l'estrazione
    printf("Numeri estratti (nell'ordine casuale): { ");
    for(size_t i = 0; i < NUM_TOT_TOMB; i++){
        printf("%zu ", numeri_tombola[i]);
    }
    printf("}\n");

    printf("La funzione 'rand' e' stata chiamata %zu volte!\n", counter);

    return 0;
}

//Inizializzazione array
void loadArray(size_t array[], size_t dim_array){
    for(size_t i = 0; i < dim_array; i++){
        array[i] = 0;   //0 -> numero NON estratto; 1-> numero ià estratto
    }
}

//Implementazione estrazione
size_t estrazioneNumeri(size_t array[], size_t dim_array){

    if(dim_array == 0 || dim_array == 1) { return 0; }    //Ritorno preventivo

    //Dichiarazione array ausiliario
    size_t numeri_estratti[dim_array]; 
    size_t count, index, numero_estratto;   //'count' conta le chamate a rand. 'index' quanti numeri sono stati inseriti nell'array ausiliario
    
    //Inizializzazione dell'array ausliario
    loadArray(numeri_estratti, dim_array); 
    count = index = numero_estratto = 0;

    srand(time(NULL));  //Seed setting

    //Inizio estrazione pseudo-casuale
    while(index < dim_array){

        numero_estratto = (rand() % dim_array) + 1;
        count++;

        //Controllo se il numero è iù uscito in precedenza
        if(numeri_estratti[numero_estratto - 1] == 0){
            numeri_estratti[numero_estratto - 1] = 1; //Conferma dell'estrazione del numero
            
            array[index] = numero_estratto;     //La modifica viene fatta direttamente nell'array passato come parametro
            index++;
        }

    }

    return count;
}