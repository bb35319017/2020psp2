#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double p_stdnorm(double z);

int main(void)
{
    double val;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    double L1=1,L2=1;
    double thetaA, thetaB;
    double max_val, min_val;
    double muA=170.8, muB=169.7;
    double sigmaA=5.43*5.43, sigmaB=5.5*5.5;



    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL)
    {
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL)
    {
        sscanf(buf,"%lf",&val);

        thetaA = (val-muA)/sigmaA;
        thetaB = (val-muB)/sigmaB;

        L1 = L1 * p_stdnorm(thetaA);
        L2 = L2 * p_stdnorm(thetaB);

    }

    max_val = L1;
    min_val = L2;

    if(fclose(fp) == EOF)
    {
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("L_A: %f\n",max_val);
    printf("L_B: %f\n",min_val);

    return 0;


}

double p_stdnorm(double z)
{
    
    return 1/sqrt(2*M_PI) * exp(-z*z/2);
}

