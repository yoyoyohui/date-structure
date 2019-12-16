/* 快速排序(交换) (哨兵)(有错误未解决)Quick Sort */
/* 平均时间复杂度:O(nlogn) */
/* 最好时间复杂度:O(nlogn) */
/* 最坏时间复杂度:O(n^2) */
/* 平均空间复杂度:O(logn) */
/* 辅助空间复杂度:O(nlogn) */
/* 最坏空间复杂度:O(n) */
/* Quicksort O(logn) */
/* Partition O(n) */
/* 稳定性:不稳定 */
#include<stdio.h>

void QuickSort(int arr[], int low, int high){  
    int pivotloc;  
    if(low < high){  //长度大于1
        pivotloc = Partition(arr, low, high);//找中枢 一分为二   
        QuickSort(arr, low, pivotloc-1);//对低子表递归排序 
        QuickSort(arr, pivotloc+1, high); //对高子表递归排序 
    }  
}  
int Partition(int arr[], int low, int high){
    arr[0] = arr[low];
    int pivotkey = arr[low];  //中枢点的值
    while(low < high){ //low high 重合了就不执行
        while((low < high) && (arr[high] >= pivotkey)){
            high--;
        }
        arr[low] = arr[high];
        while((low < high) && (arr[low] <= pivotkey)){
            high--;
        }
        arr[high] = arr[low];
    }
    arr[low] = arr[0];
    return low; //中心点元素下标
}

int main(){
    int i;
    int len;
    printf("input the len of arr:");
    scanf("%d", &len);
    int arr[len];
    for(i = 1; i < len+1; i++){
        scanf("%d", &arr[i]);
    }
    //int len = sizeof(arr)/sizeof(int);     ps 计算数组长度常规方法.
    QuickSort(arr, 1, len);
    for(i = 1; i < len+1; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
