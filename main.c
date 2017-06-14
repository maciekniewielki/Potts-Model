#include "Utils.h"
#include "Potts.h"

int main(int argc, char** argv)
{
    if(argc<4)
    {
        printUsage();
        return 1;
    }
    int N = atoi(argv[1]);
    int q = atoi(argv[2]);
    float h = atof(argv[3]);
    int SMOOTH = argc>4 ? atoi(argv[4]) : 100;
    float T_max = argc>5 ? atof(argv[5]) : 3.0f;
    float T_min = argc>6 ? atof(argv[6]) : 0.01f;
    float T_delta = argc>7 ? atof(argv[7]) : 0.01f;
    char out_file[100];
    argc>8 ? strcpy(out_file, argv[8]) : strcpy(out_file, "result.txt");
    float KB = 1.0f;


    FILE* file = fopen(out_file, "w");
    if(!file)
    {
        fprintf(stderr, "Cannot open file %s", out_file);
        return 1;
    }
    fprintf(file, "N=%d\tq=%d\th=%f\n%s %s", N, q, h, "Temperature", "Abs(Magnetisation)");

    for(float T = T_min; T<T_max; T+=T_delta)
    {
        float smoothSum = 0;
        for(int j=0; j<SMOOTH; j++)
            if(q == 2)
                smoothSum += simulateChain(KB*T, N, h);
            else
                smoothSum += simulatePottsChain(KB*T, N, q, h);
        fprintf(file, "\n%f %f", T, smoothSum/SMOOTH);
    }
    fclose(file);
    return 0;
}
//z polem zewnêtrzynym
//z wartoœci¹ || i bez
