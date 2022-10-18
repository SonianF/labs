#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int lenght;
const int critical_lenght = 15;

int PROVERKA_lenght() {  //проверка введенных значений для длины массива
    cout << "Input array lenght: ";
    string lenght0 = ""; //вводим строковую переменную
    getline(cin, lenght0);
    if (lenght0.find_first_not_of("1234567890") != -1) { //если введенное значение содержит что-то кроме цифр, то выдается ошибка
        cout << "ERROR! Please, enter nonegaive inter number: " << endl;
        return PROVERKA_lenght(); //повторный ввод
    }
    else 
        return stoi(lenght0);
}

void convertHeap(vector<int> &array, int len, int x) {
    int largest = x;
    int left = 2 * x + 1;
    int right = 2 * x + 2;
    if (left < len && array[left] > array[largest])
        largest = left;
    if (right < len && array[right] > array[largest])
        largest = right;
    if (largest != x)
    {
        swap(array[x], array[largest]);
        convertHeap(array, len, largest);
    }
}

void heap_sort(vector<int> &array, int len)
{
    for (int i = len / 2 - 1; i >= 0; i--)
        convertHeap(array, len, i);
    for (int i = len - 1; i >= 0; i--)
    {
        swap(array[0], array[i]);
        convertHeap(array, i, 0);
    }
}

void heapSort(vector<int> &array) {
    for (int i = lenght / 2 - 1; i >= 0; i--) {
       heap_sort(array, lenght);
    }
    for (int i = lenght - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heap_sort(array, lenght);
    }
    return heap_sort(array, lenght);
} 

void heap_array_output(vector<int> &array) { //выводим отсортированный массив
    cout << "The array sorted by heap: ";
    if (lenght>15) {
        for (int i = 0; i < critical_lenght; i++)
        cout << array[i] << "  ";
    }
    else{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << "  ";}
    cout << "\n";
}
void generated_array_output(vector<int> &array) { //выводим массив из случайных значений
    cout << "The random generated array: ";
    if (lenght>15) {
        for (int i = 0; i < critical_lenght; i++)
        cout << array[i] << "  ";
    }
    else{
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << "  ";}
    cout << "\n";
}

int main() {
    string continuation;              //переменная для дальнейшей повторной работы алгоритма
    while (continuation != "no") {   
        lenght = PROVERKA_lenght();  //вводим переменную из функции, отвечающей за проверку ограничений на переменную
        vector<int> array;
        for (int i = 0; i < lenght; i++) {
        array.push_back(rand()%1000);}
        generated_array_output(array); //выводим неотсортированный массив
        heapSort(array); 
        heap_array_output(array); // выводим отсортированный массив
        cout << "If you want to finish type no, else click..." << endl;
        getline(cin, continuation);
    }
    cout << "Goodbye! Thank you for using our program! "<<endl;
}
