#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

using namespace std;

int main()
{
    char propozitie[1000], cuvant[100][50], * p, aux[50];
    int nr_cuvinte, i, j, k;
    bool ordonat, aceeasi_lungime;
 
    printf("Dati propozitia:");
    scanf("%[^\n]s", propozitie);
    
    nr_cuvinte = 0;
    p = strtok(propozitie, " ");
    while (p != NULL)
    {
        nr_cuvinte++;
        strcpy(cuvant[nr_cuvinte], p);
        p = strtok(NULL, " ");
    }
    
    do
    {
        ordonat = true;
        for (i = 1; i < nr_cuvinte; i++)
            if (strlen(cuvant[i]) < strlen(cuvant[i + 1]))
            {
                ordonat = false;
                strcpy(aux, cuvant[i]);
                strcpy(cuvant[i], cuvant[i + 1]);
                strcpy(cuvant[i + 1], aux);
            }
    } while (!ordonat);
    
    i = 1;
    while (i <= nr_cuvinte)
    {
        
        j = i;
        aceeasi_lungime = true;
        while (aceeasi_lungime && j <= nr_cuvinte)
            if (strlen(cuvant[j]) != strlen(cuvant[i]))
                aceeasi_lungime = false;
            else
                j++;
        j--;
        
        do
        {
            ordonat = true;
            for (k = i; k < j; k++)
                if (strcmp(cuvant[k], cuvant[k + 1]) > 0)
                {
                    ordonat = false;
                    strcpy(aux, cuvant[k]);
                    strcpy(cuvant[k], cuvant[k + 1]);
                    strcpy(cuvant[k + 1], aux);
                }
        } while (!ordonat);
        i = j + 1;
    }
    
    for (i = 1; i <= nr_cuvinte; i++)
        printf("%s\n", cuvant[i]);
    return 0;
}
