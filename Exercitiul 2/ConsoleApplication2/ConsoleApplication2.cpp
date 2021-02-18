#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int convert(char s[])
{
	int num = 0;
	int n = strlen(s);
	for (int i = 0; i < n-1; i++)
		num = num * 10 + (int(s[i]) - 48);
	return num;
}

int main()
{
	FILE* fp;
	fopen_s(&fp, "ini.txt", "r");
	char numere[300];
	int sum = 0;
	while (fgets(numere, 300, fp) != NULL)
	{
		int part = convert(numere);
		sum += part;
	}
	printf("Suma numerelor este:");
	printf("%d", sum);
	fclose(fp);
}

