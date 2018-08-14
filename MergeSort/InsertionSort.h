//
// Created by 王存俊 on 2018/8/14.
//

#ifndef MERGESORT_INSERTIONSORT_H
#define MERGESORT_INSERTIONSORT_H

#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n){

    for( int i = 1 ; i < n ; i ++ ) {

        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }

    return;
}


#endif //MERGESORT_INSERTIONSORT_H
