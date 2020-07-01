#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

extern double ave_online(double val, double ave);
extern double var_online(double val, double ave, double square_ave);

int N;

int main(void)
{
    double val, est_var, est_ave;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE *fp;
    double ave = 0;
    double var = 0;
    double square_ave = 0;

    printf("input the filename of sample:");
    fgets(fname, sizeof(fname), stdin);
    fname[strlen(fname) - 1] = '\0';
    printf("the filename of sample: %s\n", fname);

    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        fputs("File open error\n", stderr);
        exit(EXIT_FAILURE);
    }

    N = 0;

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        sscanf(buf, "%lf", &val);

        N = N + 1;

        var = var_online(val, ave, square_ave);

        square_ave = ave_online(val * val, square_ave);

        ave = ave_online(val, ave);
    }

    printf("ave = %lf\n", ave);
    printf("var = %lf\n", var);

    est_var = N * var / (N - 1);
    est_ave = ave;

    printf("母集団の平均 = %lf\n", est_ave);
    printf("母集団の分散 = %lf\n", est_var);

    if (fclose(fp) == EOF)
    {
        fputs("file close error\n", stderr);
        exit(EXIT_FAILURE);
    }

    return 0;
}

double ave_online(double val, double ave)
{
    double ave2;

    ave2 = (N - 1) * ave / N + val / N;

    return ave2;
}

double var_online(double val, double ave, double square_ave)
{
    double var;

    var = ((N - 1) * square_ave / N + val * val / N) - ((N - 1) * ave / N + val / N) * ((N - 1) * ave / N + val / N);

    return var;
}
