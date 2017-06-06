#ifndef POTTS_H_INCLUDED
#define POTTS_H_INCLUDED


float calculateEnergyDiff(float, float, int);
float simulateChain(float T, int N);
float simulatePottsChain(float KB_T, int N, int q);

#endif // POTTS_H_INCLUDED
