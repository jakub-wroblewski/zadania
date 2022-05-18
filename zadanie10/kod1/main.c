#include <stdio.h>
#include <stdlib.h>

struct trojkat
{
    float a,b,c;
};
float foo(struct trojkat arg)
{
    return arg.a+arg.b+arg.c;
}
int main()
{
    struct trojkat t1 ={3.4,4.2,5.1};
    printf("%f\n",foo(t1));
    return 0;
}
