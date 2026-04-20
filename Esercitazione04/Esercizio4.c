/*
Name: Giovanni R.
Exercise text: Scrivere un programma in C che permetta di cercare una sequenza di numeri interi (pattern) senza salti 
 all’interno di una sequenza di numeri più lunga, anch’essa inserita da tastiera. Il programma deve restituire 
 l'indice (a partire da 0) del primo elemento della sequenza principale da cui compare il pattern, oppure -1 se il 
 pattern non è presente.
*/

#include <stdio.h>

//Macro
#define N 4    //Lungheza pattern
#define M 15   //Lunghezza stringa di caratteri

//Prototypes
void loadVett(int v[], size_t dim_array, long long int n);
int searchPattern(const int v_string[], const int v_pattern[], size_t dim_array1, size_t dim_array2);

int main(void){

    int pattern, esito_input, return_search;
    int sequenza_vett[M], pattern_vett[N];
    long long int sequenza_caratteri;

    sequenza_caratteri = pattern = esito_input = 0;
    return_search = -1;

    //Controllo sull'input per la stringa di caratteri
    do{
        printf("Inserisci sequnza di caratteri (deve essere di %d cifre): ", M);
        esito_input = scanf("%lld",&sequenza_caratteri);

        if(esito_input != 1){
            printf("ERROR: invalid input, try again\n");
            while(getchar() != '\n');
        }else if(!(sequenza_caratteri > 99999999999999 && sequenza_caratteri < 1000000000000000)){
            printf("ERROR: invalid input, try again\n");
        }
    }while(!(sequenza_caratteri > 99999999999999 && sequenza_caratteri < 1000000000000000));

    //Loading del vettore della string di caratteri
    loadVett(sequenza_vett, M, sequenza_caratteri);


    //Controllo sull'input del pattern da ricercare
    esito_input = 0;    //Riassegnazione della variabile sul controllo dell'input con scanf
    do{
        printf("Inserisci sequnza del pattern (deve essere di %d cifre): ", N);
        esito_input = scanf("%d",&pattern);

        if(esito_input != 1){
            printf("ERROR: invalid input, try again\n");
            while(getchar() != '\n');
        }else if(!(pattern > 999 && pattern < 10000)){
            printf("ERROR: invalid input, try again\n");
        }
    }while(!(pattern > 999 && pattern < 10000));

    //Loading del vettore del pattern
    loadVett(pattern_vett, N, pattern);

    return_search = searchPattern(sequenza_vett, pattern_vett, M, N);

    if(return_search != -1){
        printf("Il pattern e\' pesente. Inizia nella posizione: %d\n",return_search);
    }else {
        printf("Il pattern NON e\' presente\n");
    }

    return 0;
}


void loadVett(int v[], size_t dim_array, long long int num){
    for(size_t i = dim_array; i > 0; i--){
        v[i-1] = num%10;
        num /= 10;
    }
}

//Search pattern function
int searchPattern(const int v_string[], const int v_pattern[], size_t dim_array1, size_t dim_array2){

    short int match;

    //Controllo suggerito dal prof
    if(dim_array2 > dim_array1){    //Controlla se è effettivamente possibile effettuare la ricerca
        return -1;
    }

    for(size_t i = 0; i <= (dim_array1-dim_array2); i++){

        match = 1;

        for(size_t j = 0; j < dim_array2; j++){

            if(v_string[i+j] != v_pattern[j]){
                match = 0;
                break;
            }
        }

        if(match == 1){
            return i;
        }

    }

    return -1;

}