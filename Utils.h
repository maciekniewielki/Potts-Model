#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void printUsage();
int getRandom(void);
float getRandomFloat(void);
bool isSuccessful(float probability);
int saveDataToFile(char* fileName, float* column1, float* column2, int n, char* column1_name, char* column2_name);


#endif // UTILS_H_INCLUDED
