#include <stdio.h>
#include <stdlib.h>

int main()
{
	char filename = "input.txt";
	printf("opening file: %s\n", "input.txt");
	int i=0, length=0;;
	FILE *fp;
	if((fp = fopen("input.txt", "r+")) == NULL)
	{
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
		printf("data from file '%s' contains following co-ordinates:\n", "input.txt");
		for(i=0; i<length; i++)
		{
			printf("%f %f %f\n", array[i][0], array[i][1], array[i][2]);
		}

		printf("\n---Parsing Data---\n");

		double output[length][2];
		double minZ = 0;
		double maxZ = 5;

		for(i=0; i<length; i++)
		{
			if(array[i][2] > minZ && array[i][2] < maxZ)
			{
				output[i][0] = array[i][0];
				output[i][1] = array[i][1];
				printf("%lf %lf\n", output[i][0], output[i][1]);
			}
			else
			{
				printf("no valid data\n");
			}
		}

		printf("writing to file: %s\n", "output.txt");
		FILE *fp;
		fp = fopen("output.txt", "w");
		//fprintf(fp, "Testing...\n");
		int i = 0;
		for(i=0; i<length; i++)
		{
			fprintf(fp, "%f %f\n", array[i][0], array[i][1]);
		}
		fclose(fp);
		printf("file closed. \n");
	}
	fclose(fp);


	printf("\n---Graphing Data---\n");
	FILE *pipe = popen("pgnuplot -persist","w");
	fflush(pipe);
	fprintf(pipe, "plot 'output.txt'\n");
	fflush(pipe);
	close(pipe);


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
