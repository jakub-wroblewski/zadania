int f(char napis[])
{
    int index = 0;
    while(napis[index]!='\0'){
        if(napis[index]>='0' && napis[index]<='9'){
            return index;
        }
        index++;
    }
    return 0;
}

int main()
{
    char napis[] = "To jest napis 123"; //14
    printf("%d\n", f(napis));
    return 0;
}
////////////////////////////////
float f(unsigned n, unsigned m, int** tab)
{
    float ilosc_elem=0, suma=0;
    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            if(tab[x][y]%2==1){
                suma+=tab[x][y];
                ilosc_elem++;
            }
        }
    }
    return suma/ilosc_elem;
}

int main()
{
    unsigned n = 2;
    unsigned m = 2;
    int** tab = malloc(m*sizeof(int*));
    * tab = malloc(n*sizeof(int));
    * (tab+1) = malloc(n*sizeof(int));
    **tab = 1;
    *(*tab+1)=3;
    *(*(tab+1))=2;
    *(*(tab+1)+1)=4;

    //powinno zworicic 2 bo (1+3)/2
    printf("%f\n", f(n, m, tab));
    return 0;
}
/////////////////////////////////////////////////////
struct osoba
{
    char *imie; //powinno być chyba char imie[20] ale nie dziala
    int wiek;
    float wzrost;
};

struct osoba f(unsigned n, struct osoba* tab)
{
    float najwiekszy_wzrost=0;
    int index_najwyzszego=0;
    for(int i=0; i<n; i++){
        if(tab[i].wzrost > najwiekszy_wzrost){
            najwiekszy_wzrost = tab[i].wzrost;
            index_najwyzszego = i;
        }
    }
    return tab[index_najwyzszego];
}

int main()
{
    unsigned n = 3;
    struct osoba tab[n];
    tab[0].imie = "Magda";
    tab[0].wiek = 20;
    tab[0].wzrost = 1.80;

    tab[1].imie = "Mateusz";
    tab[1].wiek = 20;
    tab[1].wzrost = 2.29;

    tab[2].imie = "Wiktor";
    tab[2].wiek = 21;
    tab[2].wzrost = 1.20;

    struct osoba najwyzsza = f(n, tab);
    printf("imie: %s\nwiek: %d\nwzrost: %f\n", najwyzsza.imie, najwyzsza.wiek, najwyzsza.wzrost);
    return 0;
}
////////////////////////////////////////////////////////////
struct element{
    double i;
    struct element* next;
};

void f(struct element* x){
    if (x == NULL){
        return;
    }

    struct element* przedostatni_index = NULL;
    while (x != NULL){
        if (x->next != NULL){
            if (x->next->i < 0){
                przedostatni_index = x;
            }
        }
        x = x->next;
    }

    if (przedostatni_index != NULL){
        struct element* nast = przedostatni_index->next->next;
        free(przedostatni_index->next);
        przedostatni_index->next = nast;
    }

}

int main()
{

    struct element a1 = {1.0, NULL};
    struct element a2 = {1.0, &a1};
    struct element a3 = {-1.0, &a2};
    struct element a4 = {-1.0, &a3};
    struct element a5 = {1.0, &a4};
    struct element a6 = {1.0, &a5};
    struct element tab[6];
    tab[0] = a1;
    tab[1] = a2;
    tab[2] = a3;
    tab[3] = a4;
    tab[4] = a5;
    tab[5] = a6;

    f(tab);
    struct element* x = &a6;
    while (x != NULL){
        printf("%f\n", x->i);
        x = x->next;
    }

    return 0;
}
////////////////////////////////////////////////////////////////
int** tab2d(int x, int y)
{
    int** tab = malloc(y*sizeof(int));
    for(int i=0; i<y; i++){
        tab[i] = malloc(x*sizeof(int));
    }
    return tab;
}

float f(unsigned n, unsigned m, int** tab)
{
    float ilosc_elem=0, suma=0;
    for(int y=0; y<m; y++){
        for(int x=0; x<n; x++){
            if(tab[x][y]%2==1){
                suma+=tab[x][y];
                ilosc_elem++;
            }
        }
    }
    return suma/ilosc_elem;
}

int main()
{
    unsigned n = 2;
    unsigned m = 2;

    int** tab2 = tab2d(n, m);
    tab2[0][0] = 1;
    tab2[0][1] = 3;
    tab2[1][0] = 2;
    tab2[1][1] = 4;

    //powinno zworicic 2 bo (1+3)/2
    printf("%f\n", f(n, m, tab2));
    return 0;
}

///////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **tab = (int**) malloc(sizeof(int*)*2);
    tab[0]=(int*) malloc(sizeof(int)*3);
    tab[1]=(int*) malloc(sizeof(int)*3);
    *(*(tab+0)+0) = -3;
    *(*(tab+0)+1) = 4;
    *(*(tab+0)+2) = 7;
    *(*(tab+1)+0) = 1;
    *(*(tab+1)+1) = -2;
    *(*(tab+1)+2) = 0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("[%d,%d]=%d\n",i,j,*(*(tab+i)+j));
            //printf("[%d,%d]=%d\n",i,j,tab[i][j]);
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("adres[%d,%d]=%p\n",i,j,*(tab+i)+j);
            //printf("[%d,%d]=%d\n",i,j,tab[i][j]);
        }
    }
    for(int i=0;i<2;i++)
    {
        printf("adres[%d]=%p\n",i,*(tab+i));
        printf("adres[%d]=%p\n",i,tab+i);
    }
    printf("adres tab %p\n",tab);
    return 0;
}

/////////////////////////////////////////////////////////////////
int main()
{
    char * napis = "informatyka";
    char * napis2 = malloc(12*sizeof(char)); //rozmiar liczba znaków+1
    *napis2 = 'i';
    *(napis2+1) = 'n';
    *(napis2+2) = 'f';
    *(napis2+3) = 'o';
    *(napis2+4) = 'r';
    *(napis2+5) = 'm';
    *(napis2+6) = 'a';
    *(napis2+7) = 't';
    *(napis2+8) = 'y';
    *(napis2+9) = 'k';
    *(napis2+10) = 'a';
    *(napis2+11) = '\0';
    printf("%s\n",napis2);
    return 0;
}
//////////////////////////////////////////////////////////////

