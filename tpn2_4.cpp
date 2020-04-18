#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct 
{
    int velocidad,anio,cantidad;
    char *tipo_cpu;
}compu;

char tipos[6][10]={"Intel","AMD","Celeron","Athlon","Core","Pentium"};

void crearPC(compu *pc);
void cargarPC(compu *pc,int n);
void mostrarLista(compu *pc,int n);
void mostrarVieja(compu *pc,int n);
void mostrarVayorVelocidad(compu *pc,int n);

int main(){
    int n;    
    srand(time(NULL));
    printf("Ingrese la cantidad de pc: ");
    scanf("%d",&n);
    compu *pc= (compu*)calloc(n,sizeof(compu));
    cargarPC(pc , n);
    /*int i;
    for (i = 0; i < n; i++)
    {
        *(pc+i)=crearPC(*(tipos+rand()%6));
    }*/
    mostrarLista(&pc[0],n);
    mostrarVieja(pc, n);
    mostrarVayorVelocidad(pc, n);
    getchar();
    getchar();
    return 0;
}

void crearPC(compu *pc){
    pc->velocidad=rand()%3+1;
    pc->anio=rand()%18+2000;
    pc->cantidad=rand()%4+1;
    pc->tipo_cpu=*(tipos+rand()%6);
}

void cargarPC(compu *pc,int n){
    int i;
    for (i = 0; i < n; i++)
    {
        crearPC(pc+i);
    }
}

void mostrarLista(compu *pc,int n){
    int i;
    for ( i = 0; i < n; i++)
    {
        printf("\n\nCaracteristicas de pc %d:",i+1);
        printf("\nVelocidad: %dGhz",(pc+i)->velocidad);
        printf("\nAnio: %d",(pc+i)->anio);
        printf("\nCantidad de nucleos: %d",(pc+i)->cantidad);
        printf("\nTipo de procesador: %s",pc[i].tipo_cpu);
    }
}
void mostrarVieja(compu *pc,int n){
    int i,num=0,anio;
    anio=pc->anio;
    for ( i = 1; i < n; i++)
    {
        if (anio>((pc+i)->anio))
        {
            anio=(pc+i)->anio;
            num=i;
        }
    }
    printf("\n\n==========Pc mas vieja: ===========");
    printf("\nVelocidad: %dGhz",(pc+num)->velocidad);
    printf("\nAnio: %d",(pc+num)->anio);
    printf("\nCantidad de nucleos: %d",(pc+num)->cantidad);
    printf("\nTipo de procesador: %s",pc[num].tipo_cpu);
}
void mostrarVayorVelocidad(compu *pc,int n){
    int i,num=0,vel;
    vel=pc->velocidad;
    for ( i = 1; i < n; i++)
    {
        if (vel<((pc+i)->velocidad))
        {
            vel=(pc+i)->velocidad;
            num=i;
        }
    }
    printf("\n\n========Pc con mayor velocidad: =========");
    printf("\nVelocidad: %dGhz",(pc+num)->velocidad);
    printf("\nAnio: %d",(pc+num)->anio);
    printf("\nCantidad de nucleos: %d",(pc+num)->cantidad);
    printf("\nTipo de procesador: %s",pc[num].tipo_cpu);
}