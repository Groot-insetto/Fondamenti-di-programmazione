/*
Name: Giovanni R.
Exercise text: Un palindromo è un numero o una frase di testo che, letta al contrario, rimane invariata. Ad esempio, ciascuno 
 dei seguenti numeri interi a cinque cifre è un palindromo: 12321, 55555, 45554 e 11611. Implementare in C un 
 programma che verifichi se un numero intero a 5 cifre, inserito dall’utente, è palindromo.

 PS: questo esercizio è stato fatto con moooolto più tempo e molta più fatica
*/

#include <stdio.h>

//Macros
#define N 5 //Dimensione array = grandezza numero

//Prototypes
void loadingVett(int v[], size_t dim_array, int n);
int calcPalindr(const int v[], size_t dim_array);


//Main function
int main(void){

    int vett[N], num, esito_inserimento, palindromo_result;
    num = esito_inserimento = palindromo_result = 0;

    //Controllo input critico
    do{
        printf("Inserisci numero di %d cifre: \n", N);
        esito_inserimento = scanf("%d",&num);

        if(esito_inserimento != 1){
            printf("ERROR: INVALID INPUT, TRY ANGAIN!\n");
            while(getchar() != '\n');
        }else if(!(num > 9999 && num <=99999)){
            printf("ERROR: il numero non è di %d cifre\n", N);
        }

    }while(!(num > 9999 && num <=99999));

    printf("\n---- LOADIN VECTOR ----\n");
    loadingVett(vett, N, num);
    printf("\n---- END LOADIN VECTOR ----\n");

    printf("\n---- CALCOLO PALINDROMO ----\n");
    palindromo_result = calcPalindr(vett, N);
    if(palindromo_result == 1){
        printf("Il numero e\' un palindromo\n");
    }else {
        printf("Il numero non e\' un palindromo\n");
    }
    
    return 0;
}

//Loading vector function
void loadingVett(int v[], size_t dim_array, int n){
    for(size_t i = dim_array; i > 0; i--){
        v[i-1] = n%10;
        n = n/10;
    }
}

//Palndrom control function
int calcPalindr(const int v[], size_t dim_array){
    for(size_t i = 0; i < (dim_array/2); i++){
        if(v[i] != v[dim_array -1 -i]){
            return 0;
        }
    }

    return 1;
}