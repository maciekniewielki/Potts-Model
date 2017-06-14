#include "Potts.h"
#include "Utils.h"


float calculateEnergyDiff(float prevState, float currentState, int q)
{
    float JThetaij = cos(prevState - currentState);
    return 1 - JThetaij;
}

float calculateEnergyDiffIsing(float prevState, float currentState, float h)
{
    return -(prevState + h)*(-2 * currentState);
}

float simulateChain(float KB_T, int N, float h)
{
    int prevSpin = getRandomSpin();
    int currentSpin;
    int spinSum = 0;

    spinSum += prevSpin;
    for(int i=1; i<N; i++)
    {
        currentSpin = getRandomSpin();

        double energyDiff = calculateEnergyDiffIsing(prevSpin, currentSpin, h);
        float exponens = exp(-energyDiff/(KB_T));

        if (energyDiff < 0)
            currentSpin = -currentSpin;
        else
            currentSpin = getRandomFloat() < exponens ? -currentSpin : currentSpin;

        spinSum += currentSpin;
        prevSpin = currentSpin;
    }
    return ((float)spinSum)/N;
}

float simulatePottsChain(float KB_T, int N, int q, float h)
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
    return ((float)spinSum)/N;
}

