#include <stdio.h>
#include <stdlib.h>

int** foo(unsigned int n, unsigned int m)
{
    int ** tab = (int **) malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        tab[i] = malloc(m*sizeof(int));
    }
    return tab;


}


int main()
{
   printf("%d\n", foo(2,3));
    return 0;
}
