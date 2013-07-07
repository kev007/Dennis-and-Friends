#include <stdio.h>
#include <stdlib.h>

int main()
{
	char filename = "input.txt"; //
	printf("opening file: %s\n", "input.txt");
	int i=0, length=0;;
	FILE *fp;                                       //neuen pointer auf datei/file, addresslegung auf file
	if((fp = fopen("input.txt", "r+")) == NULL)      //input.txt soll in fp geladen werden, datei öffnen, r+ = lesen und schreiben und ändern
	{                                               //if datei nicht existiert, dann
		printf("No such file\n"); //ausgabe "no....." und programm beenden
		exit(1);
	}
	else  //andernfalls
	{
		fscanf(fp, "%d", &length);  //zeile auslesen von fp in format integer und in variable "length" abspeichern
		printf("length is: %d\n", length); //länge in console ausgeben
		double array[length][3]; //neues array erstellen vom typ double , length zeile und 3 spalten x, y und z
		while (i<length)
		{
			fscanf(fp, "%lf", &array[i][0]); //x koordinate auslesen und in spalte 0 speichern
			fscanf(fp, "%lf", &array[i][1]); //y " spalte 1 speichern
			fscanf(fp, "%lf", &array[i][2]);//z " spalte 2 speichern
			i++;
		}
		printf("data from file '%s' contains following co-ordinates:\n", "input.txt"); //gebe "" in console aus
		for(i=0; i<length; i++) //alle zeilen auslesen
		{
			printf("%f %f %f\n", array[i][0], array[i][1], array[i][2]); //ausgabe der x,y und z koordinaten
		}

		printf("\n---Parsing Data---\n"); //hinweis bearbeitung der daten

		double output[length][2]; //neue variable "output" length zeile und 2 spalten
		double minZ = 2.00000; //neue variable für minimum der entfernung von der kinect, z koordinate
		double maxZ = 2.20000; //" maximum abstand

		for(i=0; i<length; i++) //auslesen der koordinaten und ausgabe in "output.txt"
		{
			if(array[i][2] > minZ && array[i][2] < maxZ) //bedingung z koordinaten zwischen z min unbd z max
			{
				output[i][0] = array[i][0];
				output[i][1] = array[i][1];
				printf("%lf %lf\n", output[i][0], output[i][1]);
			}
			else
			{
				printf("no valid data\n"); //wenn fehlerhaft oder keine daten dann ausgabe ""
			}
		}

		printf("writing to file: %s\n", "output.txt"); // neue ausgelesenen daten in datei "output.txt" schreiben
		FILE *fp; // file pointer auf fp
		fp = fopen("output.txt", "w"); //output.txt wird in fp geladen mit schreibrechte

		int i = 0;                          //
		for(i=0; i<length; i++)             //schleife um die zeilen, koordinaten von x und y der output.txt auszugeben
		{
			fprintf(fp, "%f %f\n", array[i][0], array[i][1]); //x und y koordinate neu in fp speichern
		}
		fclose(fp); //file pointer fp output.txt schließen
		printf("file closed. \n");  //ausgabe "fp geschlossen"
	}
	fclose(fp); //file pointer fp input.txt schließen


	printf("\n---Graphing Data---\n"); //ausgabe ""
	FILE *pipe = popen("pgnuplot -persist","w"); //direkter befehl um ein anderes programm, hier gnuplot zu öffnen
	fflush(pipe); //verbindung "pipe" leeren um kollisionen zu verhindenrrn
	fprintf(pipe, "plot 'output.txt'\n"); //übergabe durch pipe befehl "plot" (daten, koordinaten, in einen graphen schreiben)
	fflush(pipe); //pipe leeren
	close(pipe); //pipe (verbindung) schließen

	while(1)
	{}
	return 0;
}















/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	readFile("input.txt");
	//writeFile("output.txt");
	graph("output.txt");
	return 0;
}

void readFile(char filename[FILENAME_MAX])
{
	printf("opening file: %s\n", filename);
	int i=0, length=0;;
	FILE *fp;
	if((fp = fopen(filename, "r+")) == NULL) {
	        printf("No such file\n");
	        exit(1);
	    }
	else
	{
		fscanf(fp, "%d", &length);
		printf("length is: %d\n", length);
		double array[length][3];
		while (i<length)
		{
			fscanf(fp, "%lf", &array[i][0]);
			fscanf(fp, "%lf", &array[i][1]);
			fscanf(fp, "%lf", &array[i][2]);
			i++;
		}
		printf("data from file '%s' contains following co-ordinates:\n", filename);
		for(i=0; i<length; i++)
		{
			printf("%f %f %f\n", array[i][0], array[i][1], array[i][2]);
		}

		parseInput(array, length);
	}
	fclose(fp);

}

void parseInput(double array[][], int length)
{
	printf("\n---Parsing Data---\n");

	double output[length][2];
	int minZ = 0;
	int maxZ = 5;
	int i = 0;

	for(i=0; i<length; i++)
	{
		if(array[i][2] >= minZ && array[i][2] <= maxZ)
		{
			output[i][0] = array[i][0];
			output[i][1] = array[i][1];
		}
	}

	writeFile("output.txt", output, length);
}

void writeFile(char filename[FILENAME_MAX], double array[][], int length)
{
	printf("writing to file: %s\n", filename);
	FILE *fp;
	fp = fopen(filename, "w");
	//fprintf(fp, "Testing...\n");
	int i = 0;
	for(i=0; i<length; i++)
	{
		fprintf("%f %f\n", array[i][0], array[i][1]);
	}


	fclose(fp);
	printf("file closed. \n");
}

void graph(char filename[FILENAME_MAX])
{
	printf("\n---Graphing Data---\n");
	int i = 0;

	FILE *pipe = popen("pgnuplot -persist","w");
	fflush(pipe);
	fprintf(pipe, "plot 'output.txt'\n");
	fflush(pipe);
	close(pipe);
}

 */
