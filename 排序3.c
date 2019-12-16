/* 简单(直接)选择排序 Selection Sort */
/* 稳定性:不稳定 */
/* 平均时间复杂度:O(n^2) */
/* 最好时间复杂度:O(n^2) */
/* 最坏时间复杂度:O(n^2) */
/* 辅助空间复杂度:O(1)  temp*/
#include<stdio.h>
void SelectionSort(int arr[], int size){
    int i, j, index, tmp;
    for(i = 0; i < size - 1; i++){
        index = i; //纪录下标当前最小值
        for(j = i + 1; j < size; j++){
            if(arr[j] < arr[index]){
                index = j; //纪录最小值的位置
            }
        }
        if(index != i){ //如果第一个就是最小值就不用交换了
            tmp = arr[index];
            arr[index] = arr[i];
            arr[i] = tmp;
        }
        
    }
}
int main(){
    int i;
    int len;
    printf("input the len of arr:");
    scanf("%d", &len);
    int arr[len];
    for(i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    //int len = sizeof(arr)/sizeof(int);     ps 计算数组长度常规方法.
    SelectionSort(arr, len);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
