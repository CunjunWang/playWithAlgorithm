#include <iostream>
#include "SortTestHelper.h"

// 插入排序 Insertion Sort
// 时间复杂度：O(n^2)
// 原理：
// 每个元素与它之前的所有元素依次比较大小，若小则交换位置

// 插入排序可以提前终止内循环
// 对于几乎排序好的array，效率要远远高于seletionSort

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {

    // 第0个元素不用考虑
    for (int i = 1; i < n; i++) {
        // 寻找arr[i]合适的插入位置
        // j=1是最后一次比较 所以到j>0
        // 先复制一份房钱元素
        T e = arr[i];
        int j; // 保存e应该插入的位置
        // 替换swap函数
        // 一次swap就有三次赋值
        for (j = i; j > 0 && arr[j-1] > e; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }

}

int main() {

    int n = 10000;
    int *arr = SortTestHelper::generateNearlySortedArray(n,0);
//    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);

    delete[] arr;
//    delete[] arr2;

    return 0;
}