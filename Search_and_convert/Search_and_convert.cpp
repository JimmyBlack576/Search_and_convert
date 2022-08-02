#include <iostream>
#include <Windows.h>

using namespace std;
//Функция вывода массива
void showarr(int* arr);
//Функция линейного поиска
void line_search(int* arr, int* key);
//Функция сортировки (для бинарного поиска)
void sort_arr(int* arr);
//функция бинарного поиска
void binary_search(int* arr, int* key);
//Функция перевода 2 сс в десятичнную
int convert(long long n);

int main()
{
    int arr[10] = { 2,5,3,7,3,9,0,4,1,6 };
    int* ptr = arr;
    int key;

    //Task 1_____________________________
    showarr(arr);
    cout << "\n\n";
    cout << "Enter the key: \n";
    cin >> key;
    line_search(arr, &key);
    system("pause");
    //Task 2_____________________________
    cout << "Sorting...\n";
    Sleep(1500);
    sort_arr(arr);
    showarr(arr);
    cout << "Enter the key: \n";
    cin >> key;
    binary_search(arr, &key);
    //Task 3_____________________________
    long long n;
    cout << "Enter a binary number: ";
    cin >> n;
    cout << n << " in binary = " << convert(n) << " in decimal";
}

void showarr(int* arr) {
    for (int i = 0; i < 10; i++) {
        cout << *(arr + i) << " ";
    }
    cout << "\n\n";
}

void line_search(int* arr, int* key) {

    for (int i = 0; i < 10; i++) {
        if (*(arr + i) == *key)
            cout << "Key " << *key << " in " << i + 1 << " element array\n";
    }
}

void sort_arr(int* arr) {
    int temp;
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = 0; j < 10 - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }
    }
    cout << "\n\n";
}

void binary_search(int* arr, int* key) {
    bool flag = false;
    int l = 0;
    int r = 9;
    int mid;

    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;
        if (arr[mid] == *key) flag = true;
        if (arr[mid] > *key) r = mid - 1;
        else l = mid + 1;
    }

    if (flag) cout << "Key " << *key << " in " << mid+1 << " element array \n";
    else cout << "This key is not in the array!\n";
    system("pause");
}

int convert(long long n) {
    int dec = 0, i = 0, temp;
    while (n != 0) {
        temp = n % 10;
        n /= 10;
        dec += temp * pow(2, i);
        ++i;
    }
    return dec;
}