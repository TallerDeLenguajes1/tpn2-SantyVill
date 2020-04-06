#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Filas 15

int main(){
    srand(time(NULL));
    int columnas=rand()%11+5;
    int f,c,*cantpares,pares;
    cantpares= (int *)calloc(15,sizeof(int));
    double mt[Filas][columnas];
    double *pmat=&mt[0][0];
    for(f = 0;f<Filas; f++)
    {
        for(c = 0;c<columnas; c++)
        {
            mt[f][c]=rand()%900+100;
            printf("%.2lf  ",*(pmat+f*columnas+c));
        }
        printf("\n");
    }
    for(f = 0;f<Filas; f++)
    {
        pares=0;
        for(c = 0;c<columnas; c++)
        {
            if ((int)(mt[f][c])%2==0)
            {
                pares++;
            }
        }
        *(cantpares+f)=pares;
    }
    for (f = 0; f < Filas; f++)
    {
        printf("\nCantidad de pares en la fila \"%d\": %d",f,*(cantpares+f));
    }
    free(cantpares);
    getchar();
    return 0;
}