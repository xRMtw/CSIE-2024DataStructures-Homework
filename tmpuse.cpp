#include "MergeSort.h"
// 合併兩個已排序的子陣列
void merge( std::vector<int>& arr, int left, int mid, int right ) {
    int n1 = mid - left + 1; // 左子陣列的大小
    int n2 = right - mid;    // 右子陣列的大小

    // 建立臨時陣列
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // 複製資料到臨時陣列 L 和 R
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // 合併臨時陣列回原始陣列
    int i = 0; // 初始化左子陣列索引
    int j = 0; // 初始化右子陣列索引
    int k = left; // 初始化合併後陣列的索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 複製左子陣列的剩餘元素（如果有）
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // 複製右子陣列的剩餘元素（如果有）
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// 主函式，實作合併排序
void MergeSort(std::vector<int>& arr, int left, int right) {
    int threshold = 5;
    int size = right - left + 1; 
    if ( size < threshold ) {
        bublesort( arr, left, right );
    }
    else {
        int mid = left + (right - left) / 2; // 找出中間點

        // 遞迴排序左半部
        MergeSort(arr, left, mid);
        // 遞迴排序右半部
        MergeSort(arr, mid + 1, right);

        // 合併已排序的兩半
        merge(arr, left, mid, right);
    }
}

void bublesort ( std::vector<int>, int left, int right ) {
    for ( int i = left; i < right; i++ ) {
        for ( int k = left; k < right - i; i++ ) {
            if ( arr[i] < arr[k] ) {
                int tmp = arr[i];
                arr[i] = arr[k];
                arr[k] = arr[i];
            }
        }
    }
}