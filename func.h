#ifndef func_H
#define func_H
void print_mas(int n, int* a);
void print_matrica(int n, int m, double** a);
void print_slau_tim(double** A, int n, double* B);
void print_slau_tim2(double** A, int n, double* B, double* X);
void rand2_float(int n, int m, double** a, double k);
void rand2_int(int n, int m, double** a, int k);
void rand1_int(int n, double* a, int k);
void rand1_float(int n, double* a, int k);
double pogreshnost(double** A, int n, double* x, double* b);
void gauss(double** A, double* b, double* x, int n);


#endif
