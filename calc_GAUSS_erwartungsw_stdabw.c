/*calc_GAUSS_erwartungsw_stdabw.c*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<getopt.h>
#include"staticlib_gauss.h"

int main(int argc,char *argv[]) {
    int option,std_abw,erwart_wert,anzahl=100;
    FILE*Input_stream;
    while((option=getopt(argc, argv, "ha:v"))!= -1)
        switch (option) {
        case 'h':
            printf("Das Programm erstellt eine Statistik aus einem Datensatz. Der Datensatz befindet sich in der Datei zufall.txt im Programmverzeichnis\n");
            printf("Optionen sind:\n");
            printf("-a	Für die Anzahl an berücksichtigten Messwerten (Standart 100) {-a xxx}\n");
            printf("-v	Für die Anzeige der Version\n");
            printf("-h	Für die Hilfe\n");
            return 0;
        case 'a':
            anzahl=atoi(optarg);
            printf("Anzahl berücksichtigter Werte: %i\n",anzahl);
            break;
        case 'v':
            printf("Version: 0.1 Alpha\n");
            printf("Programmierer: Sebastian Käwel & Roman Rückert");
            return 0;
        default :
            abort ();
        }

    Input_stream = fopen("zufall.txt", "r");

    if(Input_stream== NULL) {
        printf("Datei nicht gefunden/Kann keine Werte einlesen\n");
        exit(-1);
    }
    else {
        print_gaussian_erwartung_stdabw(anzahl,Input_stream);
    }
    fclose(Input_stream);
    return 0;
}
