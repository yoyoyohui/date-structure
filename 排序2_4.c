/*希尔排序 Shell Sort (有哨兵)简单插入排序的改进版 缩小增量排序*/
/* 一次移动位置大 */
/* 增量序列应该是互质的 最后一个必须为1 */
/* 稳定性:不稳定 */
/*空间复杂度 O(1) 一个哨兵的空间*/
/*最好的情况 O(n)*/
/*最坏的情况（输入数据逆有序） O(n^2)*/
/*平均的情况（耗时是最坏情况的一半）~O(n^1.3)*/
#include<stdio.h>

void ShellSort(int arr[], int size){   

    int i, j, increment;//增量   
    for(increment = size/ 2; increment > 0; increment /= 2) {    
        for(i = increment + 1; i <= size; i++){
            if(arr[i] < arr[i - increment]){
                arr[0] = arr[i];
                j = i - increment; 
                while(j >= 0 && arr[0] < arr[j]){  
                    arr[j + increment] = arr[j];
                    j -= increment; 
                }  
                arr[j + increment] = arr[0];
            }   
        }  
    }  
} 

int main(){
    int i;
    int len;
    printf("input the len of arr:");
    scanf("%d", &len);
    int arr[len];
    for(i = 1; i < len+1; i++){ //arr[0]为哨兵
        scanf("%d", &arr[i]);
    }
    //int len = sizeof(arr)/sizeof(int);     ps 计算数组长度常规方法.
    ShellSort(arr, len);
    for(i = 1; i < len+1; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
