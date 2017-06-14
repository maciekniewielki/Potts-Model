
#include "Utils.h"

void printUsage(char* scriptName)
{
    printf("Usage: Potts-Model <N> <q> <h> [SMOOTH]=100 [T_max]=3 [T_min]=0.01 [T_delta]=0.01 [result_file]=result.txt");
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

int getRandomSpin()
{
    return (getRandom()%2)*2-1;
}

float getRandomFloat(void)
{
    return ((float)getRandom())/RAND_MAX;
}

int getRandomRange(int a, int b)
{
    return getRandom()%(b-a) + a;
}

float getRandomPottsSpin(int q)
{
    return 2*PI/q * getRandomRange(0, q);
}

bool isSuccessful(float probability)
{
    return getRandomFloat()<probability;
}

bool equalFloat(float a, float b)
{
    return fabs(a-b)<EQ_EPSILON;
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
