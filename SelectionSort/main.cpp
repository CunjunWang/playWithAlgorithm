#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

// 选择排序 Selection Sort
// 时间复杂度: O(n^2)
// 原理: 在数组中找出第一名的位置，把最小的和第一名进行交换
//      找剩下的数组第一名的位置，找到剩下的最小的，交换
//      ...

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {

    for (int i = 0; i < n; i++) {

        // 寻找 [i, n) 区间中的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        swap(arr[i], arr[minIndex]);
    }
}


int main() {

    int n = 10000;

    // 这里使用了new开辟了新空间
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
//    selectionSort(arr, n);
//    SortTestHelper::printArray(arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);

    // 对应的这里要delete来释放空间
    // arr开辟的是数组空间 所以释放要用delete[]
    delete[] arr;

//    float arr2[4] = {4.4, 3.3, 2.2, 1.1};
//    selectionSort(arr2, 4);
//
//    for (int i = 0; i < 4; i++)
//        cout << arr2[i] << " ";
//    cout << endl;
//
//    string arr3[4] = {"D", "C", "B", "A"};
//    selectionSort(arr3, 4);
//
//    for (int i = 0; i < 4; i++)
//        cout << arr3[i] << " ";
//    cout << endl;
//
//    Student arr4[4] = {{"D", 90},
//                       {"C", 100},
//                       {"B", 95},
//                       {"A", 95}};
//    selectionSort(arr4, 4);
//
//    for (int i = 0; i < 4; i++)
//        cout << arr4[i] << " ";
//    cout << endl;

    return 0;
}