#include "pch.h"
#include <iostream>
/*Ввести одномерный массив из n элементов. Вычислить сумму всех отрицательных чисел , их количество и сумму всех положительных чисел.*/
using namespace std;
int main()
{
	setlocale(0, "");
	int n, suminus, sumplus, a;
	cout << "Введите размер массива: " << endl;
	cout << "n = ";
	cin >> n;
	int* A = new int[n];
	cout << "Введите данные массива:  " << endl;
	suminus = sumplus = a = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if (A[i] < 0)
		{
			suminus += A[i];
			a++;
		}
		if (A[i] > 0)
			sumplus += A[i];
	}
	cout << "Сумма отрицательных чисел: " << suminus << endl;
	cout << "Количество отрицательных чисел: " << a << endl;
	cout << "Сумма положительных чисел: " << sumplus << endl;
	delete[] A;
	system("pause");
	return 0;
}