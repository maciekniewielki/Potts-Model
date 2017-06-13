#include "Utils.h"
#include "Potts.h"

#define SMOOTH 1000
#define N_STATES 3

int main(int argc, char** argv)
{
    if(argc<3)
    {
        printUsage();
        return 1;
    }
    int N = atoi(argv[1]);
    float T_max = atof(argv[2]);
    float T_min = argc>3 ? atof(argv[3]) : 0.01f;
    float T_delta = argc>4 ? atof(argv[4]) : 0.01f;
    char out_file[100];
    argc>5 ? strcpy(out_file, argv[5]) : strcpy(out_file, "result.txt");
    float KB = 1.0f;


    FILE* file = fopen(out_file, "w");
    if(!file)
    {
        fprintf(stderr, "Cannot open file %s", out_file);
        return 1;
    }
    fprintf(file, "N=%d\n%s %s", N, "Temperature", "Abs(Magnetisation)");

    for(float T = T_min; T<T_max; T+=T_delta)
    {
        float smoothSum = 0;
        for(int j=0; j<SMOOTH; j++)
            smoothSum += simulateChain(KB*T, N, 0.2f);
        fprintf(file, "\n%f %f", T, smoothSum/SMOOTH);
    }
    fclose(file);
    return 0;
}
//z polem zewnêtrzynym
//z wartoœci¹ || i bez
