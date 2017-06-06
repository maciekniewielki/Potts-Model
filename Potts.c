#include "Potts.h"
#include "Utils.h"


float calculateEnergyDiff(float prevState, float currentState, int q)
{
    float JThetaij = cos(prevState - currentState);
    return 1 - JThetaij;
}

float simulateChain(float KB_T, int N)
{
    float exponens = exp(-2/(KB_T));

    int prevSpin = getRandomFloat() > 0.5 ? 1 : -1;
    int currentSpin;
    int spinSum = 0;

    spinSum += prevSpin;
    for(int i=1; i<N; i++)
    {
        currentSpin = getRandomSpin();
        if (currentSpin * prevSpin < 0)
            currentSpin = getRandomFloat() < exponens ? currentSpin : -currentSpin;

        spinSum += currentSpin;
        prevSpin = currentSpin;
    }
    return fabs(spinSum)/N;
}

float simulatePottsChain(float KB_T, int N, int q)
{
    float prevSpin = getRandomPottsSpin(q);
    //printf("Spin: %f\n", prevSpin);
    float currentSpin;
    float spinSum = prevSpin;

    for(int i=1; i<N; i++)
    {
        currentSpin = getRandomPottsSpin(q);
        if(!equalFloat(currentSpin, prevSpin))
        {
            float energyDiff = calculateEnergyDiff(prevSpin, currentSpin, q);
            float exponens = exp(-energyDiff/(KB_T));
            currentSpin = getRandomFloat() < exponens ? currentSpin : prevSpin;
        }
        spinSum += currentSpin;
        prevSpin = currentSpin;
    }
    return fabs(spinSum)/N;
}

