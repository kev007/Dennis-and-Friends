#include <stdio.h>
#include <stdlib.h>

int main()
{
	readFile("input.xml");
	//writeFile("output.txt");
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
	}
	fclose(fp);
}

void writeFile(char filename[FILENAME_MAX])
{
	printf("writing to file: %s\n", filename);
	FILE *fp;
	fp = fopen(filename, "w");
	fprintf(fp, "Testing...\n");


	fclose(fp);
	printf("file closed. \n");
}
