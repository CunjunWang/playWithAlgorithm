#include <iostream>
#include "SortTestHelper.h"

// 插入排序 Insertion Sort
// 时间复杂度：O(n^2)
// 原理：
// 每个元素与它之前的所有元素依次比较大小，若小则交换位置

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {

    // 第0个元素不用考虑
    for (int i = 1; i < n; i++) {
        // 寻找arr[i]合适的插入位置
        // j=1是最后一次比较 所以到j>0
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1])
                swap(arr[j], arr[j - 1]);
            else
                break;

        }
    }

}


int main() {

    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n,0,n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);

    delete[] arr;
    delete[] arr2;

    return 0;
}