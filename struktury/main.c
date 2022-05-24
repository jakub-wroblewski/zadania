#include <stdio.h>
#include <stdlib.h>

struct Osoba{
    int wiek;
    char imie[10];
};

typedef struct
{
    int pole1;
    char znak;
} Nazwa;

typedef struct Name
{
    int field;
} Alias;

int main()
{
    struct Name zm;
    Alias zm2;
    struct Alias zm3;
    int a=6;
    struct Osoba o1;
    o1.wiek=6;
    struct Osoba o2 = {20, "Anna"};

    Nazwa n1;
    return 0;
}
