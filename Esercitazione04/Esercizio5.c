/*
Name: Giovanni R.
Exercise text: 
 Un numero primo è un intero maggiore di 1 divisibile solo per sé stesso e per 1. Il Setaccio di Eratostene è 
 un metodo classico per trovare tutti i numeri primi fino a un dato limite, e si articola in due fasi.
 
 Nella prima fase si crea un array di N elementi, tutti inizializzati a 1 (vero): se l'elemento in posizione i vale 1, 
 il numero i è considerato primo; se vale 0, non lo è. Gli indici 0 e 1 non vengono considerati, poiché 0 e 1 non 
 sono numeri primi per definizione.
 
 Nella seconda fase, a partire dall'indice 2, si scorre l'array: ogni volta che si trova un elemento con valore 1, si 
 pongono a 0 tutti gli elementi successivi il cui indice è un multiplo di quello corrente.
 Ad esempio, dall'indice 2 si azzerano gli indici 4, 6, 8, …; dall'indice 3 si azzerano 6, 9, 12, …; e così via.
 Al termine, gli indici degli elementi rimasti a 1 corrispondono ai numeri primi.
 
 Scrivere un programma C che usi un array di 1000 elementi per trovare e stampare tutti i numeri primi compresi 
 tra 2 e 999.
*/

#include <stdio.h>

//Mraco
#define N 1000    //Lunghezza array

//Prototyoes
void cercaNumPrimi(int v[], size_t dim_array);

int main (void){

    int vett[N];

    vett[0] = vett[1] = 0;  //Sappiamo già che 0 e 1 NON sono numeri primi

    //Load vector (based on the exercise text)
    printf("--- LOAD VETT ----\n");
    for(size_t i = 2; i < N; i++){
        vett[i] = 1;
    }

    printf("--- SEARCHING ---\n");
    cercaNumPrimi(vett, N);

    printf("\nI primi %d numeri primi sono:\n",N);
    for( size_t i = 2; i < N; i++){
        if(vett[i] == 1){
            printf("%lu\n",i);
        }
    }


    return 0;
}

//Search primary number function (Con il "Setaccio di Eratostene")
void cercaNumPrimi(int v[], size_t dim_array){
    for(size_t i = 2; (i*i) < dim_array; i++){      //i*i mi è stato suggerito dal professore, per un'ottimizzazione massima. (Ciò è giustificato matematicamente)
        if(v[i] == 1){

            for(size_t j = (i*i); j < dim_array; j += i){
                v[j] = 0;   //Azzeramento dei multimi della posizione i-esima
            }

        }
    }
}