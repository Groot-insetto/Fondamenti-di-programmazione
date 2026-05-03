/*
Name: Giovanni R.
Text exercise: Un palindromo è una sequenza di caratteri che, letta al contrario, rimane invariata. Ad esempio, "anna", 
"radar" e "onorarono" sono palindromi. 
Anche intere frasi possono essere palindrome: ignorando gli spazi, "i topi non avevano nipoti" è una frase palindroma.

Scrivere una funzione che accetti una stringa come argomento e che restituisca 1 se la stringa è palindroma, 0 se non lo è. 
La funzione deve ignorare gli spazi e il confronto deve essere case-sensitive.
Scrivere poi un programma C che chieda all’utente di inserire una stringa (massimo 100 caratteri) 
e che utilizzi la funzione appena definita per determinare se la stringa è palindroma o meno.
*/

#include <stdio.h>
#include <string.h>
#define MAX_CARATTERI 101   //Lunghezza stringa

//Prototype
int verificaPalindromo(char string[], size_t dim_eff_string);

int main(void){
 
    int verifica_input, verifica_palindromo;   //Dichiarazione
    char str[MAX_CARATTERI];   //Dichiarazione

    verifica_input = verifica_palindromo = 0;  //Inizializzazione

    //Caricamento vettore
    do{
        printf("Inserisci stringa (massimo 100 caratteri): ");
        verifica_input = scanf("%100[^\n]",str);
        if(verifica_input != 1){
            while(getchar() != '\n');
        }
    }while(!(verifica_input == 1));
 
    //Chiamata a funzione per la verifica del palindromo
    verifica_palindromo = verificaPalindromo(str, strlen(str));

    if(verifica_palindromo == 0){
        printf("La stringa NON e\' un palindromo\n");
    }else if(verifica_palindromo == 1){
        printf("La stringa e\' un palindromo\n");
    }

    return 0;
}

//Implementation verify palindrom function
int verificaPalindromo(char string[], size_t dim_eff_string){

    //Ritorno preventivo
    if(dim_eff_string == 0) { return 0; }
    if(dim_eff_string == 1) { return 1; }

    //Dichiarazione cursori:
    size_t i, j;

    //Inizializzazione cursori:
    i = 0;
    j = dim_eff_string -1;

    //Verifica efettiva:
    while(i<j){

        //Controllo sugli spazi
        if(string[i] == ' '){
            i++;
            continue;
        }else if(string[j] == ' '){
            j--;
            continue;
        }

        //Verifica disuguagnaza tra caratteri (oss: è case-sensitive)
        if(string[i] != string[j]){
            return 0;
        }

        i++;
        j--;

    }

    return 1;
}