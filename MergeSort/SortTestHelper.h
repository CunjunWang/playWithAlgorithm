//
// Created by 王存俊 on 2018/8/14.
//

#ifndef MERGESORT_SORTTESTHELPER_H
#define MERGESORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;

namespace SortTestHelper {

    int *generateRandomArray(int n, int rangeL, int rangeR) {

        assert(rangeL <= rangeR);

        int *arr = new int[n];
        // 设置随机数种子
        srand(time(NULL));
        for (int i = 0; i < n; i++) {

            // 控制随机数生成范围
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;

        }

        return arr;
    }

    int *generateNearlySortedArray(int n, int swapTimes) {

        int *arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }

        srand(time(NULL));

        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }

        return arr;
    }

    template<typename T>
    void printArray(T arr[], int n) {

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;

        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n) {

        for (int i = 0; i < n - 1; i++)
            if (arr[i] > arr[i + 1])
                return false;

        return true;
    }

    // 第二个参数是传入函数指针
    // void 是返回值
    // *sort 是函数指针
    // 第二个括号中是参数类型
    template<typename T>
    void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {

        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        // 判定数组已经排序了
        assert(isSorted(arr, n));

        // 打印时钟周期个数来看算法效率
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;

        return;
    }

    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

}

#endif //MERGESORT_SORTTESTHELPER_H
