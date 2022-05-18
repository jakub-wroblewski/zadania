#include <stdio.h>
#include <stdlib.h>

union super_int
{
    int a;
    unsigned int b;
};

int main()
{
    union super_int zmienna;
    zmienna.a=2;
    printf("%d\n",zmienna.a);
    printf("%u\n",zmienna.a);
    printf("%d\n",zmienna.b);
    printf("%u\n",zmienna.b);
    return 0;
}
