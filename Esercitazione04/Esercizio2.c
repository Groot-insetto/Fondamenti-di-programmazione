/*
Name: Giovanni R.
Exercise text: Scrivere un programma in C che consenta all’utente di inserire N numeri interi in un array e poi sposti tutti gli 
 elementi di una posizione a sinistra.
 Extra: modificare il programma per permettere all’utente di specificare quante posizioni k spostare a sinistra.
*/

#include <stdio.h>

//Macro:
#define N 3 //Dimensione array

//Prototypes:
void loadingVett(int v[], size_t dim_vett);
void kLeftShift(int v[], size_t dim_vett, int k);
void printVector(int v[], size_t dim_vett);


//Main function
int main(void){

    //Dichiarazione
    int vett[N], k;
    short int scelta, esito_inserimento_main;
    
    //Inizializzazione
    k = 0;
    scelta = esito_inserimento_main = 0;

    //Start loadin vector
    printf("\n---- Inizio caricamento vettore ----\n");
    loadingVett(vett, N);
    printf("\n---- Fine caricamento vettore ----\n");


    //Menù
    printf("\nMenu\'\n");

    do{
    printf("Digita:\n- 1: per un left-shift di una singola posizione;\n- 2: per un left-shift di k-posizioni (k scelto da te\';\n- 0: terminare il programma)");
    esito_inserimento_main = scanf("%hd",&scelta);
    
    if(esito_inserimento_main != 1){
        while(getchar() != '\n'){
                scelta = 0;
        }
    }

    if(scelta != 1 && scelta != 2 && scelta != 0){
        printf("ERROR: invalid input\n");
    }
    
    }while(!(scelta == 0 || scelta == 1 || scelta == 2));
    
    switch(scelta){
        case 1: 
            kLeftShift(vett, N, 1);

            printf("\n---- Stampa dell'array shitchato ----\n");
            printVector(vett, N);
        break;

        case 2: {
            short int esito_inserimento_case_2;
            esito_inserimento_case_2 = 0;

            do{
            printf("Inserisci un numero positivo (> 0) per i k-shift");
            esito_inserimento_case_2 = scanf("%d",&k);

            if(k <= 0){
                printf("ERROR: input value is not positive");
            }

            if(esito_inserimento_case_2 != 1){
                while(getchar() != '\n'){
                    k = 0;
                }
            }
            }while(!(k > 0));

            kLeftShift(vett, N, k);

            printf("\n---- Stampa dell'array shitchato ----\n");
            printVector(vett, N);
            
            break;
        }

        default:
            //Ci dovrebbe essere una responsive che riporta alla cima del Menù
        break;
    }
    

    return 0;
}



//Loading vector function
void loadingVett(int v[], size_t dim_vett){

    short int esito_inserimento;
    esito_inserimento = 0;  //Se fallisce l'input, scanf ritorna 0

    for(size_t i = 0; i < dim_vett; i++){

        printf("Inserisci elemento della posizione %zu: ", (i+1));
        esito_inserimento = scanf("%d",&v[i]);

        if(v[i] <= 0){
            printf("ERROR: input value is not potive");
        }

        //Controllo input critico (cotrolliamo che viene effettivamente inserito un numero)
        if(esito_inserimento != 1){
            while(getchar() != '\n'){
                v[i] = 0;
            }
        }

    }

}


//k-left-shift function
void kLeftShift(int v[], size_t dim_vett, int k){

    int aux_v[dim_vett];    //Auxiliar vector

    for(size_t i = 0; i < dim_vett; i++){
        aux_v[i] = v[(i+k)%dim_vett];
    }

    for(size_t i = 0; i < dim_vett; i++){
        v[i] = aux_v[i];
    }

}


//Pint vector function
void printVector(int v[], size_t dim_vett){

    printf("Array: { ");
    for(size_t i = 0; i < dim_vett; i++){
        printf(" %d ",v[i]);
    }
    printf(" }\n");

}