/*
Name: Giovanni R.
Exeecise text: Implementare in C un programma che consenta all’utente di inserire un anno e di verificare se esso è bisestile. 
 Si ricorda che un anno è bisestile se è divisibile per 4 ma non per 100, oppure se è divisibile per 400 (ad esempio 
 il 1900 non è stato bisestile, mentre il 2000 lo è stato). 
*/
#include <stdio.h>

//Prototipo
void bisesitilita(int anno);

void main (void){

    int anno;
    anno = 0;

    printf("Inserisci anno: ");
    scanf("%d",&anno);

    bisesitilita(anno);

}


void bisesitilita(int x){

    if((x%4==0 && x%100!=0) || x%400 == 0)
        printf("L'anno e\' bisesite\n");
    else 
        printf("L'anno non è bisestile\n");

}
