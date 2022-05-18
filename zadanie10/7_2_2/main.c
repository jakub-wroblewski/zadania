#include <stdio.h>
#include <stdlib.h>

struct punktn
{
double * t;
int w;
};

void przepisz(struct punktn tab1[], struct punktn tab2 [],unsigned int n)
{
int i,j;
for (i =0 ; i<n ; i++)
    {
    tab2[i].t=malloc(tab1[i].w*sizeof(double));
    for(j=0;j<tab1[i].w;j++)
    tab2[i].t[j]=tab1[i].t[j];
    }
}
