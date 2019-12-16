/*冒泡排序(交换)  bubble sort */
/* 稳定性:稳定 */
/*空间复杂度 O(1) temp*/
/*最好的情况 O(n)*/
/*最坏的情况（输入数据逆有序） O(n^2)*/
/*平均的情况（耗时是最坏情况的一半）O(n^2)*/
#include<stdio.h>
void bubble(int arr[], int n){
    int i, j;
    int temp;
    int flag = 1; // 作为是否有交换的标记
    for(i=0; (i < n-1) && (flag == 1); i++){
        flag = 0;
        //每一轮比较前 n-1-i 个，也就是说，已经排序好的最后 i 个不用比较
        for(j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){   //小到大排序
                flag = 1; //发生了交换
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int i;
    int len;
    printf("输入数组长度:");
    scanf("%d", &len);
    int arr[len] ;
    for(i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    //int len = sizeof(arr)/sizeof(int);     ps 计算数组长度常规方法.
    bubble(arr, len);
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
