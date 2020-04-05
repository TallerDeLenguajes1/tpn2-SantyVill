#include <stdio.h>
#define N 4
#define M 5

int main(){
    int f,c;
    double mt[N][M]= {{ 4,5,6,2,1},
                      { 1,8,3,5,7}, 
                      { 7,2,9,8,3},
                      { 6,9,1,5,2}};
    double *pmat=&mt[0][0];
    for(f = 0;f<N; f++)
    {
        for(c = 0;c<M; c++)
        {
            printf("%lf  ",*(pmat+f*M+c));
        }
        printf("\n");
    }
    getchar();
    return 0;
}