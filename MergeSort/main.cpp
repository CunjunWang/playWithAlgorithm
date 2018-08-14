#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "InsertionSort.h"

// 归并排序 MergeSort
// 时间复杂度：O(n*log(n))
// 空间复杂度：O(n) 需要额外空间

// 归并时 用3个索引来追踪
// 进行递归

using namespace std;

// 讲arr[l...mid]和arr[mid+1...r]两部分进行合并
template<typename T>
void __merge(T arr[], int l, int mid, int r) {

    T aux[r - l + 1];
    for (int i = l; i <= r; i++) {
        // 注意偏移量
        // arr从l开始, aux从0开始
        aux[i - l] = arr[i];
    }

    int i = l, j = mid + 1;

    for (int k = l; k <= r; k++) {

        // 先考虑索引合法性
        if (i > mid) {
            arr[k] = aux[j - l];
            j++;
        } else if (j > r) {
            arr[k] = aux[i - l];
            i++;
        }
            // 再考虑索引位置
        else if (aux[i - l] < aux[j - l]) {
            arr[k] = aux[i - l];
            i++;
        } else {
            arr[k] = aux[j - l];
            j++;
        }
    }

}

// 递归使用归并排序 对arr[l...r]区间进行排序
template<typename T>
void __mergeSort(T arr[], int l, int r) {

    // 第二个优化
    // 当递归到比较小的时候 可以转用插入排序
//    if (l >= r) return;
    if (r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    // l + r 非常大时 可能溢出
    int mid = (l + r) / 2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid + 1, r);

    // 第一个优化
    if (arr[mid] > arr[mid + 1])
        __merge(arr, l, mid, r);
}


template<typename T>
void mergeSort(T arr[], int n) {

    // __ 开头表示私有概念
    __mergeSort(arr, 0, n - 1);

}

int main() {

    int n = 50000;

    cout << "Test for Random Array, size = " << n << ", random range [0, " << n << "]" << endl;

    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("MergeSort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    int swapTimes = 10;
    cout << "Test for Random Nearly Ordered Array, size = " << n << "swaptime = " << swapTimes << " random range [0, "
         << n << "]" << endl;

    arr1 = SortTestHelper::generateNearlySortedArray(n, swapTimes);
    arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("MergeSort", mergeSort, arr2, n);

    delete[] arr1;
    delete[] arr2;

    return 0;
}