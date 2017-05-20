#include "Utils.h"
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


    return 0;
}
