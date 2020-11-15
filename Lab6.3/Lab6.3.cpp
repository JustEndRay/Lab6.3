#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void checkI(int a[], const int SIZE);
void checkR(int a[], const int SIZE,int i, int k);

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    cout << "Введіть розмір масиву a[]:"; cin >> SIZE;
    int* a = new int[SIZE];

    cout << "a[] = ";
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = rand() % SIZE;
        cout << a[i] << " ";
    }
    cout << "Спосіб 1(ітераційний):" << endl;
    cout << "\nВпорядкован масив за не спаданням(чи зростає масив)? ";
    checkI(a, SIZE);
    cout << "Спосіб 2(рекурсивний):" << endl;
    cout << "\nВпорядкован масив за не спаданням(чи зростає масив)? ";
    checkR(a, SIZE, 1, 1);
}
//ітераційний спосіб
void checkI(int a[], const int SIZE)
{
    int k = 1;
    for (int i = 1; i < SIZE; i++)
    {
        if (a[i-1] <= a[i]) { k++; }
    }
    if (k == SIZE) { cout << "так" << endl; }
    else 
    {
        cout << "ні" << endl;
    }
}
void checkR(int a[], const int SIZE,int i, int k)
{
    if (a[i - 1] <= a[i]) {checkR(a, SIZE, i+1, k+1); }
    if (k == SIZE) { cout << "так" << endl; }
    else
    {
        cout << "ні" << endl;
    }
}
