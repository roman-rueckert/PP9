/*calc_GAUSS_erwartungsw_stdabw.c*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<getopt.h>
#include"staticlib_gauss.h"

int main(int argc,char *argv[])
{
	int option,std_abw,erwart_wert,anzahl=100;
	FILE*Input_stream;
	while((option=getopt(argc, argv, "h"))!= -1)
		switch (option)
		{
			case 'h' :
			printf("Version: 0.1 Alpha\n");
			printf("Programmierer: Roman Rückert und Sebastian Käwel\n");
			printf("Das Programm erstellt eine Statistik über einen übergebene Datei mit dem Namen zufall.txt im aktuellen Verzeichnis\n");
			return 0;

			default :
			abort ();
		}

		Input_stream = fopen("zufall.txt", "r");

		if(Input_stream== NULL)
		{
			printf("Datei nicht gefunden/Kann keine Werte einlesen\n");
			exit(-1);
		}
		else
		{
			print_gaussian_erwartung_stdabw(anzahl,Input_stream);
		}
		fclose(Input_stream);
		return 0;
}
