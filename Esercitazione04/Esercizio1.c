/*
name: Giovanni R.
Exercise text: 
 Scrivere un programma in C che consenta all’utente di inserire una sequenza di numeri interi positivi in un array
 di dimensione N. Dopo aver completato l’inserimento, il programma deve permettere all’utente di effettuare 
 una serie di ricerche: per ciascun valore richiesto, il programma deve indicare se quel valore è presente nella 
 sequenza precedentemente inserita.
*/

#include <stdio.h>

//Macro:
#define N 3    //Dimensione array

//Prototypes:
void loadingVector(int v[], size_t dim_arr);
int research(const int v[], size_t dim_arr, int value);


//Main function
int main (void){

    //Dichiarazione
    int vett[N];
    int num_da_cerc, flag, risultato_ricerca;
    
    //Inizializzazione:
    flag = 1;
    risultato_ricerca = -1;


    printf("\nCaricamento vettore: \n");
    loadingVector(vett, N);

    printf("\n\nRicerca valore: \n");
    while(flag == 1){

        printf("Inserisci il valore da cercare: ");
        scanf("%d",&num_da_cerc);

        risultato_ricerca = research(vett, N, num_da_cerc);

        if(risultato_ricerca == 1)
            printf("Il valore %d e\' presente nell'array", num_da_cerc);
        else if (risultato_ricerca == -1)
            printf("Il valore %d NON e\' presente nell'array", num_da_cerc);

        do{
        printf("\nVuoi cercare un altro numero? (1 = Si, 0 = No): ");
        scanf("%d",&flag);
        }while(!(flag == 1 || flag == 0));
        
    }


    return 0;
}

//Loading array function
void loadingVector(int v[], size_t dim_arr){

    short int esito_inserimento;
    esito_inserimento = 0;

    for (size_t i = 0; i < dim_arr; i++) {
        do {
            printf("Inserisci il valore (positivo) della posizione %zu: ", (i+1));
            esito_inserimento = scanf("%d", &v[i]);   

            //Controllo input critico
            if(esito_inserimento != 1){
                while(getchar() != '\n'){
                    v[i] = 0;
                }
            }

            if (!(v[i] > 0)) {
                printf("ERROR: inserire solo numeri maggiori di zero.\n");
            }

        } while (!(v[i] > 0)); 
    }
}


//Research element function
int research(const int v[], size_t dim_arr, int value){

    for(size_t i = 0; i < dim_arr; i++){
        if(v[i] == value)
            return 1;
    }

    return -1;
}