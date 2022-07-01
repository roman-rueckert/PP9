#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void print_gaussian_erwartung_stdabw(int anzahl,FILE*Input_stream){

int laenge=100;
double temp,temp_var,summe,erwartungw,varianz,stdabw;
char speicher [laenge];
char end;

while(fgets(speicher, laenge, Input_stream))
{
	temp=(strtod(speicher, &end))+temp;	//Summe aller Werte
	temp_var=(pow((strtod(speicher, &end)),2.0))+temp_var;
}
	summe=temp;
	printf("Summe aller Werte: %f\n",summe);

	//Berechnen des Erwartungswertes
	erwartungw=summe/anzahl;
	printf("Erwartungswert: %f\n",erwartungw);

	//Varianz
	varianz=(temp_var/anzahl)-(pow(erwartungw,2.0));
	printf("Varianz: %f\n",varianz);

	//Berechnen der Standardabweichung
	stdabw=sqrt(varianz);
	printf("Standardabweichung: %f\n",stdabw);
}
