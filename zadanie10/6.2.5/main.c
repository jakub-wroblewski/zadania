#include <stdio.h>
#include <stdlib.h>

int*** foo(unsigned int n, unsigned int m,unsigned int b)
{
    int *** tab = (int ***) malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        tab[i] = malloc(m*sizeof(int));
        *(tab+2) = malloc(b*sizeof(int));
    }
    return tab;


}


void foo2(unsigned int n,unsigned int m, unsigned int b, int *** tab)
{
    for(int i=0;i<n;i++)
    {
        free(tab[i]);
    }
    free(tab+2);

}


int main()
{
    int tab2[2][3][4] = {{{3,4,2,3},{3,4,2,3},{3,4,2,3}},
    {{3,4,2,3},{3,4,2,3},{3,4,2,3}}};
   printf("%d\n", foo(2,3,4));
   foo2(2,3,4,***tab2);
    return 0;
}
