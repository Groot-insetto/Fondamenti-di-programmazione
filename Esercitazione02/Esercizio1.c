/*
Name: Giovanni
Date: 12-03-2026
Exercise text: Scrivere un programma in linguaggio C che chieda all'utente di inserire una temperatura in gradi Celsius e la 
 converta sia in gradi Fahrenheit che in Kelvin, stampando entrambi i risultati con due cifre decimali. 
 Le formule di conversione sono le seguenti: 
	• °F = °C × 9/5 + 32 
	•  K = °C + 273.15 
*/

#include <stdio.h>

//Conversione in F
float conversioneFahrenheit(float z){
	return z*(9.0/5.0)+32;
}temeperura


//Conversione in K
float conversioneKelvin (float y){
	return y+273.15;
}

void main (void){
	float g_Celsius; //Variabile di input

	printf("Inserisci valore temperatura: ");
	scanf("%f", &g_Celsius);
	printf("La conversione in gradi Fahrenheit e\': %.4f \n", conversioneFahrenheit(g_Celsius));
	printf("La cnversione in gradi Kelvin è\': %.4f \n", conversioneKelvin(g_Celsius));

}
