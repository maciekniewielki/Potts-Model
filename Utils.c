
#include "Utils.h"

void printUsage(char* scriptName)
{
    printf("Usage: Potts-Model <N> <T_max> [T_min]=0.01 [T_delta]=0.01 [result_file]=result.txt");
}

int getRandom(void)
{
	static int check = 0;
	if(!check)
    {
		check =1;
		srand(time(NULL));
	}
	return rand();
}

float getRandomFloat(void)
{
    return ((float)getRandom())/RAND_MAX;
}

bool isSuccessful(float probability)
{
    return getRandomFloat()<probability;
}

int saveDataToFile(char* fileName, float* column1, float* column2, int n, char* column1_name, char* column2_name)
{
    FILE* file = fopen(fileName, "w");
    if(!file)
    {
        fprintf(stderr, "Cannot open file %s", fileName);
        return 1;
    }
    fprintf(file, "%s %s", column1_name, column2_name);

    for(int i=0; i<n; i++)
        fprintf(file, "\n%f %f", column1[i], column2[i]);

    return 0;
}
