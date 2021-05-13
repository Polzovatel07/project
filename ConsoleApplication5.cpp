#include <iostream>
#include <Windows.h>
#include "pch.h"
using namespace std;
struct Sotr
{
	char Name[64];
	char Date[128];
	char Position[64];
	int Oklad;
};
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	Sotr* pSotr;
	printf("n=");
	scanf_s("%d", &n);
	pSotr = new Sotr[n];
	for (int i = 0; i < n; i++)
	{
		printf("Сотрудников N=%d:\n", i + 1);
		printf("Ф.И.О.: ");
		fflush(stdin);
		gets_s(pSotr[i].Name, 63);
		gets_s(pSotr[i].Name, 63);
		printf("Дата приема на работу: ");
		fflush(stdin);
		gets_s(pSotr[i].Date, 127);
		printf("Должность: ");
		fflush(stdin);
		gets_s(pSotr[i].Position, 63);
		printf("Оклад: ");
		scanf_s("%d", &pSotr[i].Oklad);
	}
	FILE *pF;
	fopen_s(&pF, "MySotr.dat", "w");
	fwrite(&n, sizeof(int), 1, pF);
	fwrite(pSotr, sizeof(Sotr), n, pF);
	fclose(pF);
	system("pause");
	return 0;
}