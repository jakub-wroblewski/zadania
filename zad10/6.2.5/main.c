#include <stdio.h>
#include <stdlib.h>

int *** foo(int n, int m, int k)
{
    int ***tab = (int***) malloc(sizeof(int**)*n);
    for(int i=0;i<n;i++)
    {
        *(tab+i)=(int**) malloc(sizeof(int*)*m);
        for(int j=0;j<m;j++)
        {
            *(*(tab+i)+j)=(int*) malloc(sizeof(int)*k);
        }
    }
    return tab;
}

void zwolnij(int n, int m, int k, int ***tab)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            free(*(*(tab+i)+j));
        }
        free(*(tab+i));
    }
    free(tab);
}

int main()
{
    int *** a = foo(4,5,3);
    printf("%p\n",a);
    printf("%Iu\n",sizeof(int));
    printf("%Iu\n",sizeof(int*));
    printf("%Iu\n",sizeof(int**));
    printf("%Iu\n",sizeof(int***));
    zwolnij(4,5,3,a);
    return 0;
}
