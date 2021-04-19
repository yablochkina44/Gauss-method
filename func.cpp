#include <iostream>
#include <locale.h>;
#include <iomanip>
#include <fstream>
using namespace std;

void print_mas(int n, int* a)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void print_matrica(int n, int m, double** a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void print_slau_tim(double** A, int n, double* B)
{
	for (int i = 0; i < n; i++)
	{

		cout.precision(2);
		cout << " " << "|" << " ";
		for (int j = 0; j < n; j++)
			//printf("%f3", A[i][j]," ");
			cout << setw(8) << left << A[i][j] << fixed << " ";
		cout << "|";
		cout << "\t\t";
		cout << setw(2) << left << "X\t";
		cout << "|";
		cout << setw(3) << left << B[i];
		cout << "|";
		cout << endl;
	}
}
void print_slau_tim2(double** A, int n, double* B, double* X)
{
	for (int i = 0; i < n; i++)
	{

		cout.precision(2);
		cout << " " << "|" << " ";
		for (int j = 0; j < n; j++)
			cout << setw(8) << left << A[i][j] << " ";
		cout << "|";
		cout << "\t";

		cout << setw(5) << left << X[i] << "\t";
		cout << "|";
		cout << setw(3) << left << B[i];
		cout << "|";
		cout << endl;
	}
}
void rand2_float(int n, int m, double** a, double k)
{
	srand(time(NULL));
	double min = 0; double max = k; int precision = 3;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % (int)pow(10, precision);
			a[i][j] = min + (a[i][j] / pow(10, precision)) * (max - min);
		}
	a[0][0] = 0.253;
}
void rand2_int(int n, int m, double** a, int k)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = rand() % k;
}
void rand1_int(int n, double* a, int k)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % k;
	}
}
void rand1_float(int n, double* a, int k)
{
	srand(time(NULL));
	double min = 0; double max = k; int precision = 3;
	for (int j = 0; j < n; j++)
	{
		a[j] = rand() % (int)pow(10, precision);
		a[j] = min + (a[j] / pow(10, precision)) * (max - min);
	}
	//a[0][0] = 0.253;
}
double pogreshnost(double** A, int n, double* x, double* b)
{
	double summ_str = 0, max = 0; int j = 0;
	double* summ = new double[n];
	for (int i = 0; i < n; i++)
	{
		summ_str = 0;
		for (int j = 0; j < n; j++)
		{
			summ_str += A[i][j] * x[j];
			summ[i] = fabs(summ_str - b[i]);
		}
	}
	for (int i = 0; i < n; i++)
		if (summ[i] > max) max = summ[i];

	delete[] summ;
	return max; //максимальная погрешность
}
void gauss(double** A, double* b, double* x, int n)
{
	double* B = new double[n];
	for (int k = 0; k < n; k++)
		B[k] = b[k];


	print_slau_tim(A, n, B);
	for (int j = 0; j < n - 1; j++) {
		for (int i = j + 1; i < n; i++) {
			double a = -1 * (A[i][j] / A[j][j]);
			for (int k = j; k < n; k++) {
				A[i][k] += A[j][k] * a;
			}
			B[i] += B[j] * a;
		}
	}


	double s = 0;
	for (int i = n - 1; i >= 0; i--) {
		s = 0;
		for (int j = i + 1; j < n; j++) {
			s += x[j] * A[i][j];
		}
		x[i] = (B[i] - s) / A[i][i];
	}

	cout << endl; cout << endl; cout << endl;
	print_slau_tim2(A, n, b, x);

}

