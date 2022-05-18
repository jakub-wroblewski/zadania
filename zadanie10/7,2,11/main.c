#include <stdio.h>
#include <stdlib.h>

union liczba
{
int a;
float b;
};
struct Dane
{
    int tp;
    union Liczba zaw;
};

struct Dane wczytaj()
{

    struct Dane temp;
    printf("Podaj 0 jesli calk lub 1 jesli wym\n");
    scanf("%d", &temp.tp);
    if(temp.tp==0)
    {

        printf("podaj liczbe calk\n");
        scanf("%f",&temp.zaw.a);
    }
    else
    {
        printf("Podaj liczbe wym\n");
        scanf("%f",&temp.zaw.b);
    }
    return temp;
};
void wyswietl(struct dane arg)
{
    if(arg.tp==0)
    {
        printf("%d\n",arg.zaw.a);
    }
    else
    {
        printf("%f\n",arg.zaw.b);
    }
}

int main()
{
   struct Dane zmienna = wczytaj();
   wyswietl(zmienna);
   return 0;
}
