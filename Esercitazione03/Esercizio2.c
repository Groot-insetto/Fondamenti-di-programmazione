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