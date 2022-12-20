#include <iostream>
#include <Windows.h>
using namespace std;

const int n = 6;

void CreateSnake(int(*arr)[n], int* end) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int* ptr = arr[0], i = 0, x = 0, y = 0; ptr <= end + n - 1; ptr++, i++, y++) {
        if (i % n == 0 && i != 0) {
            x++;
            y = 0;
            if (x % 2 == 0)
                ptr = &arr[x][y];
            else
                ptr = &arr[x][y + n - 1];
        }
        if (x % 2 == 0) {
            destCoord.X = x * 4;
            destCoord.Y = y;
            SetConsoleCursorPosition(hStdout, destCoord);
            *ptr = 1 + rand() % (n * n);
            cout << *ptr;
            Sleep(50);
        }
        else {
            destCoord.X = x * 4;
            destCoord.Y = n - y - 1;
            SetConsoleCursorPosition(hStdout, destCoord);
            *(ptr - y - y) = 1 + rand() % (n * n);
            cout << *(ptr - y - y);
            Sleep(50);
        }
    }
    cout << "\r";
    for (int i = 0; i < n; i++)
        cout << "\n";
    system("pause");
}

void Show(int(*arr)[n]) {
    HANDLE hStdout;
    COORD destCoord;
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            destCoord.X = i * 4;
            destCoord.Y = j;
            SetConsoleCursorPosition(hStdout, destCoord);
            cout << arr[i][j];
            }
    cout << "\n\r";
}

void SwapA(int(*arr)[n]) {
    for (int i = 0; i < (n / 2); i++) 
        for (int j = 0; j < n; j++) 
            swap(arr[i][j], arr[i + (n / 2)][j]);
    for (int i = 0; i < (n / 2); i++) 
        for (int j = 0; j < (n / 2); j++) 
            swap(arr[i][j], arr[i + (n / 2)][j + (n / 2)]);
}
 
void SwapB(int(*arr)[n]){
    for (int i = 0; i < (n/2); i++)
        for (int j = 0; j < n; j++){
            if (j < (n / 2)) 
                swap (arr[i][j], arr[i + (n / 2)][j + (n / 2)]);
            else 
                swap (arr[i][j], arr[i + (n/2)][j - (n/2)]);
        }
}

void SwapC(int(*arr)[n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (n / 2); j++) 
            swap(arr[i][j], arr[i][j + (n / 2)]);
}

void SwapD(int(*arr)[n]) {
    for (int i = 0; i < (n / 2); i++)
        for (int j = 0; j < n; j++) 
            swap(arr[i][j], arr[i + (n / 2)][j]);
}

void Sort(int(*arr)[n]) {
    int* ptr = arr[0];
    int nm = n * n - 1;
    for (int i = 0; i < n * n; i++) 
        for (int j = 0; j < n * n - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1))
                swap(*(ptr + j), *(ptr + j + 1));
            if (*(ptr + nm - j) < *(ptr + nm - j - 1))
                swap(*(ptr + nm - j), *(ptr + nm - j - 1));
        }
}

void Action(int(*arr)[n], int* end) {
    int inp;
    string sign;
    cout << "Напишите через пробел желаемое действие над матрицей ('+', '-', '*', '/') и число\n";
    cout << "Пример: '+ 2'\n";
    cin >> sign >> inp;
    if (sign == "+") {
        for (int* ptr = arr[0]; ptr <= end; ptr++)
            *ptr += inp;
    }
    else if (sign == "-") {
        for (int* ptr = arr[0]; ptr <= end; ptr++)
                *ptr -= inp;
    }
    else if (sign == "*") {
        for (int* ptr = arr[0]; ptr <= end; ptr++)
            *ptr *= inp;
    }
    else if (sign == "/") {
        for (int* ptr = arr[0]; ptr <= end; ptr++)
            *ptr /= inp;
    }
}

int main() {
    setlocale(0, "");
    srand(time(NULL));
    int arr[n][n], sortarr[n][n];
    int* end = arr[0] + n * n - 1;

    //Задание 1
    cout << "\n\n\n       Задание 1";
    Sleep(1500);
    system("cls");
    CreateSnake(arr, end);
    system("cls");

    //Задание 2
    cout << "\n\n\n       Задание 2";
    Sleep(1500);
    system("cls");

    cout << "\n\n\n       Перестановка a";
    Sleep(1500);
    system("cls");
    SwapA(arr);
    Show(arr);
    Sleep(3000);
    system("cls");

    cout << "\n\n\n       Перестановка b";
    Sleep(1500);
    system("cls");
    SwapB(arr);
    Show(arr);
    Sleep(3000);
    system("cls");

    cout << "\n\n\n       Перестановка c";
    Sleep(1500);
    system("cls");
    SwapC(arr);
    Show(arr);
    Sleep(3000);
    system("cls");

    cout << "\n\n\n       Перестановка d";
    Sleep(1500);
    system("cls");
    SwapD(arr);
    Show(arr);
    system("pause");
    system("cls");

    //Задание 3
    cout << "\n\n\n       Задание 3";
    Sleep(1500);
    system("cls");
    Sort(arr);
    Show(arr);
    system("pause");
    
    //Задание 4
    cout << "\n       Задание 4\n";
    Action(arr, end);
    system("cls");
    Show(arr);
    system("pause");
}
