/*
Name: Giovanni R.
Text exercise: Scrivere una funzione valida_password che accetti una stringa come argomento e verifichi se la password 
rispetta tutti i seguenti criteri:
• lunghezza di almeno 8 caratteri;
• almeno una lettera maiuscola, una lettera minuscola e una cifra;
• almeno un carattere speciale tra i seguenti: ! @ # $ % ^ & *
La funzione deve restituire 1 se la password è valida, 0 altrimenti. Scrivere poi un programma C che chieda 
all'utente di inserire una stringa (massimo 50 caratteri) e stampi se la password è valida o meno.

Osservazione: la funzione "verificaPassword" ritorna un determianto valore per ogni determinata violazione.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGHT 51    //Max password lenght
#define MIN_PASSWORD_LENGHT 8
#define SPEC_CAR_TO_USE "!@#$%^&*"

//Prototypes
int verificaPassword(char string[], size_t dim_eff_password);
int isSpecialChar(char c);

//Main function
int main (void){

    int verifica_input, verifica_password; 
    char password[MAX_PASSWORD_LENGHT];

    verifica_input = verifica_password = 0;

    do{
        //Controllo input
        printf("Inserisci password: ");
        verifica_input = scanf("%50[^\n]", password); 
        if(verifica_input != 1){
            printf("ERROR: invalid input, try again!\n");
            while(getchar() != '\n');
        }

        //Chiamata a funzione per verificare la password:
        verifica_password = verificaPassword(password, strlen(password));

        switch(verifica_password){
            case 1:
                printf("Valid password, good!\n");
            break;

            case 0:
                printf("ERROR: invalid password, try again!\n");
            break;
        }

    }while(verifica_password == 0);

    return 0;
}

//Implementation verify password function
int verificaPassword(char string[], size_t dim_eff_password){

    //Controllo numero di caratteri
    if(dim_eff_password < MIN_PASSWORD_LENGHT){
        return 0;
    }

    int flag_maiuscola, flag_minuscola, flag_cifra, flag_carattere_speciale;
    flag_maiuscola = flag_minuscola = flag_cifra = flag_carattere_speciale = 0;

    for(size_t i = 0; i< dim_eff_password; i++){

        //Ritrno preventivo
        if(flag_maiuscola == 1 && flag_minuscola == 1 && flag_cifra == 1 && flag_carattere_speciale == 1){
            return 1;
        }

        if(isupper(string[i]) != 0){
            flag_maiuscola = 1;
            continue;
        }
        if(islower(string[i]) != 0){
            flag_minuscola = 1;
            continue;
        }
        if(isdigit(string[i]) != 0){
            flag_cifra = 1;
            continue;
        }
        if(isSpecialChar(string[i]) == 1){
            flag_carattere_speciale = 1;
            continue;
        }
    
    }

    return 0;
}

//Special char function
int isSpecialChar(char c){
    if(c == '!' || c == '@' || c == '#' || c == '$' || 
       c == '%' || c == '^' || c == '&' || c == '*'){
        return 1; // Vero
    }
    return 0;     // Falso
}