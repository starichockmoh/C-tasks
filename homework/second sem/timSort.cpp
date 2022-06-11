#include <algorithm>
#include <cstdio>

using namespace std;
const int RUN = 32;

//Функция сортирует массив от левого индекса
// к правому индексу, который не превышает RUN
//при этом применяем сортировку вставками
void insertionSort(int arr[], int left, int right){
    for (int i = left + 1; i <= right; i++){
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// Функция для слияния двух отсортированных массивов
void merge(int arr[], int l, int m, int r){

    // Исходный массив разбивается на две части
    // левый и правый массив
    int len1 = m - l + 1, len2 = r - m; //Определили длины массивов
    int left[len1], right[len2];  //Инициализация массивов
    for (int i = 0; i < len1; i++)  //Заполняем массивы
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // После сравнения мы
    //объединяем эти два массива
    // в большем общем массиве
    while (i < len1 && j < len2){  //Реализация слияния
        if (left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // После слияния в одном из массивов могут остаться элементы,
    // которые просто добавим в конец, зная что они максимальны
    while (i < len1){
        arr[k] = left[i];
        k++;
        i++;
    }

    while (j < len2){
        arr[k] = right[j];
        k++;
        j++;
    }
}

// Реализация собственно сортировки
void timSort(int arr[], int n){

    // Сортировка отдельных подмассивов по размеру RUN.
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

    // Начинаем слияние с размера RUN.
    // Он сольется
    // для формирования размера 64, затем 128, 256 и так далее ....
    for (int size = RUN; size < n; size = 2*size){

        // выбираем начальную точку левого подмассива. Мы
        // собираемся объединить arr[left..left+size-1]
        // и arr[left+size, left+2*size-1]
        // После каждого слияния мы увеличиваем левый размер на 2*size
        for (int left = 0; left < n;left += 2*size){

            // найти конечную точку
            // левого подмассива
            // mid+1 - отправная точка
            // из правого подмассива
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),(n-1));

            // сливаем подмассив arr[left.....mid] &
            // arr[mid+1....right]
            if (mid < right) merge(arr, left, mid, right);
        }
    }
}

// Функция для вывода массива
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    int arr[] = {-2, 7, 15, -14, 0, 15, 0, 7, -7, -4, -13, 5, 8,
                 -14, 12, 0, 15, 0, 7, -7, -4, 14, 0, 15, 0,34, 23, 124};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Given Array is\n");
    printArray(arr, n);

    timSort(arr, n);

    printf("After Sorting Array is\n");
    printArray(arr, n);
    return 0;
}
