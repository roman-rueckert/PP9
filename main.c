#include"gauss.h"
#include<unistd.h>
#include<math.h>
#include<stdio.h>
#include<getopt.h>

int expected_value=10;
int std_deviation=1;
int amount_of_values = 100;
int i;


int main(int argc,char*argv[]){

int expected_value=10;
int std_deviation=1;
int amount_of_values = 100;
int option;
int i;

while((option=getopt(argc,argv,"vhe:s:a:"))!=-1)

		switch (option)
		{
			case 'v':
                                printf("Die Version ist 0.1 Alpha\n");
				printf("Programmierer: Sebastian Käwel & Roman Rückert\n");
                                return 0;
			case 'e':
				expected_value=atoi(optarg);
				printf("Erwartungswert: %i\n",expected_value);
		                break;
	                case 's':
	                        std_deviation=atoi(optarg);
			        printf("Standardabweichung: %i\n",std_deviation);
		       		break;
			case 'a':
				amount_of_values=atoi(optarg);
				printf("Anzahl Werte: %i\n",amount_of_values);
				break;
			case 'h':
				printf("Dieses Programm erstellt eine Zufallsliste von Zahlen einer Gauschenverteilung\n");
				printf("Standartwerte sind -a=100, -s=1, -e=10\n");
				printf("Optionen sind:\n");
				printf("-v	für Versionsanzeige\n");
				printf("-e	Erwartungswert {-e xxx}\n");
				printf("-s	Standartabweichung {-s xxx}\n");
				printf("-a	Anzahl an Messwerten {-a xxx}\n");
				return 0; 
		}

	FILE *output_stream;
	output_stream = fopen("zufall.txt", "w");
	if (output_stream == NULL) // test for files not existing.
	{
		printf("Error! Datei nicht gefunden\n");
		exit(-1);
	}
	for(i=1;i<=amount_of_values;i++)
	{
		print_gaussian_dist(expected_value,std_deviation,amount_of_values, output_stream);
	}
	fclose(output_stream);
	return 0;
}
