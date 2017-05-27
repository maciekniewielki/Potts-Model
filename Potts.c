#include "Potts.h"
#include "Utils.h"

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
