/*
Name: Giovanni R.
Esercise text: Scrivere un programma che chieda all'utente la lunghezza desiderata per una password (tra 8 e 50 caratteri) e 
generi una password casuale di quella lunghezza, utilizzando come alfabeto lettere maiuscole, minuscole, cifre 
e caratteri speciali (! @ # $ % ^ & *).
Extra: generare password che passino il controllo della funzione verificaPassword definita nell'esercizio 2.
*/

//Librerie
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

//Macro
#define MIN_PASSWORD_LENGHT 9
#define MAX_PASSWORD_LENGHT 51

//prototypes
void generaPasswordCasuale(char string[], size_t dim_eff_string);
int verificaPassword(char string[], size_t dim_string);
int isSpecialChar(char c);  //Serve alla funzione verificaPassword

//main function
int main(void){

    //Dichiarazione
    char password[MAX_PASSWORD_LENGHT];
    size_t lunghezza_password, verifica_input, verifica_password;

    //Inizializzazione
    lunghezza_password = verifica_input = verifica_password = 0;

    do{
        if(! (lunghezza_password >= (MIN_PASSWORD_LENGHT -1) && lunghezza_password <= (MAX_PASSWORD_LENGHT-1))){
            //Controllo input
            printf("Inserisci la lunghezza della password da generare: ");
            verifica_input = scanf("%zu", &lunghezza_password); 

            if(verifica_input != 1){
                printf("ERROR: invalid input, try again!\n");
                while(getchar() != '\n');   //svuota buffer
            }
        }

        //Controllo sulla lunghezza della password
        if(lunghezza_password >= (MIN_PASSWORD_LENGHT -1) && lunghezza_password <= (MAX_PASSWORD_LENGHT-1)){         

            //Chiamata a funzione per generare la password
            //printf("\n---- Generazione della password ----\n");
            generaPasswordCasuale(password, lunghezza_password);
            //printf("--- Password generata ----\n");

            //Chiamata a funzione per verificare la password:
            //printf("\n---- Verifica della password ----\n");
            verifica_password = verificaPassword(password, strlen(password));

            switch(verifica_password){
                case 1:
                    printf("Generazione completata con successo!!\n");
                    printf("La password generata e\': %s\n", password);
                break;

                case 0:
                    //Non fa niente perchè il programma si ferma solo quando avrà generato una password che ha superato il testo
                break;
            }

        }else{
            printf("ERROR: invalid password lenght, try again!\n");
        }

    }while(verifica_password == 0);

    return 0;
}


//Implementation random-password function
void generaPasswordCasuale(char string[], size_t dim_eff_password){
    
    //Creazione dell'alfabeto da seguire
    char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";
    size_t grandezza_alfabeto = strlen(alfabeto);

    //Seed setting
    srand(time(NULL));

    for(size_t i = 0; i < dim_eff_password; i++){
        size_t indice_casuale = rand() % grandezza_alfabeto;
        string[i] = alfabeto[indice_casuale];
    }

    string[dim_eff_password] = '\0';
}

///Implementation verify password function
int verificaPassword(char string[], size_t dim_eff_password){

    //Controllo numero di caratteri
    if(dim_eff_password < MIN_PASSWORD_LENGHT){     //Osservazione: in questo esercizio, questo controllo è superfluo per via del controllo nel main
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
