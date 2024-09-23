
#include <stdio.h>

int particiona(int *v, int inicio, int fim)
{
    int pivo = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3;
    while (inicio < fim)
    {
        while (inicio < fim && v[inicio] <= pivo)
            inicio++;
        while (inicio < fim && v[fim] > pivo)
            fim--;
        int temp = v[inicio];
        v[inicio] = v[fim];
        v[fim] = temp;
    }
    return inicio;
}
void quicksort(int *v, int inicio, int fim)
{
    int pos;

    if (inicio < fim)
    {
        pos = particiona(v, inicio, fim);
        quicksort(v, inicio, pos - 1);
        quicksort(v, pos, fim);
    }
}

int main ()
{
    int vet[] = {45, 32, 128, 89, 12, 34, 56, 78, 90, 23};
    for (int i = 0; i < 10; i++)
        printf("%d ", vet[i]);
    quicksort(vet, 0, 9);
    printf("\n %d ", vet[i]);
    for (int i = 0; i < 10; i++)
        printf(" %d ", vet[i]);
    return 0;
}