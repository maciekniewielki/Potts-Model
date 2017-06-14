#ifndef POTTS_H_INCLUDED
#define POTTS_H_INCLUDED


float calculateEnergyDiff(float, float, int);
float simulateChain(float T, int N, float h);
float simulatePottsChain(float KB_T, int N, int q, float h);

#endif // POTTS_H_INCLUDED
