#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#define EQ_EPSILON (0.0001f)
#define PI (3.1415926535897932384626433f)

#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

void printUsage();
int getRandom(void);
int getRandomSpin();
float getRandomFloat(void);
int getRandomRange(int a, int b);
bool equalFloat(float, float);
float getRandomPottsSpin(int);
bool isSuccessful(float probability);
int saveDataToFile(char* fileName, float* column1, float* column2, int n, char* column1_name, char* column2_name);


#endif // UTILS_H_INCLUDED
