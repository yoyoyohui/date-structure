/* 快速排序(交换)Quick Sort */
/* 平均时间复杂度:O(nlogn) */
/* 最好时间复杂度:O(nlogn) */
/* 最坏时间复杂度:O(n^2) */
/* 平均空间复杂度:O(logn) */
/* 辅助空间复杂度:O(nlogn) */
/* 最坏空间复杂度:O(n) */
/* 稳定性:不稳定 */
/* 不适用于原本有序或基本有序 */
/* 序列越乱越好 */

#include<stdio.h>

void QuickSort(int arr[], int begin, int end){  
    int low, high;  
    if(begin < end){  
        low = begin + 1;
        high = end;        
        while(low < high){  
            if(arr[low] > arr[begin]){  
                swap(&arr[low], &arr[high]); //中枢排位 找中心点位置
                high--;  
            } 
            else{  
                low++; 
            }  
        }  
        if(arr[low] >= arr[begin]){  
            low--;  
        }  
        swap(&arr[begin], &arr[low]);      
        QuickSort(arr, begin, low);//对低子表递归排序 
        QuickSort(arr, high, end); //对高子表递归排序 
    }  
}  
 
void swap(int *a, int *b){  
    int temp;  
    temp = *a;  
    *a = *b;  
    *b = temp;  
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
    QuickSort(arr, 0, len-1);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
