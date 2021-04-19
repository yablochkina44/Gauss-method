#include <iostream>
#include <locale.h>;
#include <iomanip>
#include <fstream>
#include"func.h"
using namespace std;


void main()
{
	setlocale(LC_ALL, "Rus");
	int n=4, q=0, m; int f = 0;
	double pogr;
	ifstream sis; ofstream sos;

	//cout << "Наташа лох" << endl;
	
	cout << "Выберите действие" << endl;
	cout << "1. Прочитать СЛАУ из файла" << endl;
	cout << "2. Задать СЛАУ самостоятельно" << endl;
	cin >> m;

	double** matr1 = new double* [n];
	for (int i = 0; i < n; i++)
		matr1[i] = new double[n];
	double* B1 = new double[n];
	double* X1 = new double[n];
	
	switch (m)
	{
	case 1:
		sis.open("slau1.txt", ios::in);
		sis >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				sis >> matr1[i][j];

		for (int i = 0; i < n; i++)
			sis >> B1[i];
		sis.close();
		print_slau_tim2(matr1, n, B1, X1);

		
		while (q != -1)
		{
			cout << "Выберите действие" << endl;
			cout << "1. Вывести СЛАУ" << endl;
			cout << "2. Решить СЛАУ" << endl;
			cout << "3. Записать в файл" << endl;
			cout << "4. Exit" << endl;
			cin >> q;

			switch (q)
			{
			case 1:
				if (f == 0) { print_slau_tim(matr1, n, B1); f = 1; }
				else
					print_slau_tim2(matr1, n, B1, X1);
				break;
			case 2:
				gauss(matr1, B1, X1, n);
				pogr = pogreshnost(matr1, n, X1, B1);
				cout << pogr / 1000 << endl;
				break;
			case 3:
			
				int i, j;
				sos.open("slau2.txt");

				for (int i = 0; i < n; i++)
				{

					sos.precision(2);
					sos << " " << "|" << " ";
					for (int j = 0; j < n; j++)
						sos << setw(8) << left << matr1[i][j] << " ";
					sos << "|";
					sos << "\t";

					sos << setw(5) << left << X1[i] << "\t";
					sos << "|";
					sos << setw(3) << left << B1[i];
					sos << "|";
					sos << endl;
				}

				sos.close();
				break;
			case 4:
				q = -1;
				break;
			default:
				cout << endl;
				cout << "Такой команды нет, попробуйте снова" << endl;
				cout << endl;
			}
		}

		delete[] B1;
		delete[] X1;
		for (int i = 0; i < n; i++)
			delete[] matr1[i];

		break;
	case 2:
		cout << "Введите размер матрицы:";
		cin >> n;

		double** matr = new double* [n];
		for (int i = 0; i < n; i++)
		{
			matr[i] = new double[n];
		}
		double* B = new double[n];
		double* X = new double[n];


		cout << "Выберите действие" << endl;
		cout << "1. Ввести матрицу в ручную" << endl;
		cout << "2. Рандомные вещественные числа до 10" << endl;
		cout << "3. Рандомные целые числа до 20" << endl;
		//cout << "4. Прочитать матрицу из файла" << endl;
		cin >> q;

		switch (q)
		{
		case 1:
			cout << "Введите члены матрицы" << endl;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					cin >> matr[i][j];
			cout << "Введите свободные члены" << endl;
			for (int j = 0; j < n; j++)
				cin >> B[j];
			break;
		case 2:
			rand2_float(n, n, matr, 10);
			rand1_float(n, B, 10);
			break;
		case 3:
			rand2_int(n, n, matr, 101);
			rand1_int(n, B, 101);
			break;
		default:
			cout << endl;
			cout << "Такой команды нет, попробуйте снова" << endl;
			cout << endl;
		}
		while (q != -1)
		{
			cout << "Выберите действие" << endl;
			cout << "1. Вывести СЛАУ" << endl;
			cout << "2. Решить СЛАУ" << endl;
			cout << "3. Записать в файл" << endl;
			cout << "4. Exit" << endl;
			cin >> q;
			switch (q)
			{
			case 1:
				if (f == 0) { print_slau_tim(matr, n, B); f = 1; }
				else
					print_slau_tim2(matr, n, B, X);
				break;
			case 2:
				gauss(matr, B, X, n);
				pogr = pogreshnost(matr, n, X, B);
				cout << pogr / 1000 << endl;
				break;
			
			case 3:

				int i, j;
				sos.open("slau2.txt");

				for (int i = 0; i < n; i++)
				{

					sos.precision(2);
					sos << " " << "|" << " ";
					for (int j = 0; j < n; j++)
						sos << setw(8) << left << matr1[i][j] << " ";
					sos << "|";
					sos << "\t";

					sos << setw(5) << left << X1[i] << "\t";
					sos << "|";
					sos << setw(3) << left << B1[i];
					sos << "|";
					sos << endl;
				}

				sos.close();
				break;
			case 4:
				q = -1;
				break;
			default:
				cout << endl;
				cout << "Такой команды нет, попробуйте снова" << endl;
				cout << endl;
			}
		}
		delete[] B;
		delete[] X;
		for (int i = 0; i < n; i++)
			delete[] matr[i];
		break;

	}

	
}