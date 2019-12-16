/*插入排序 Insertion Sort  哨兵  直接插入排序*/
/*原始数据越接近有序， 排序越快*
/*稳定性:稳定*/ 
/*空间复杂度 O(1) 一个哨兵的空间*/
/*最好的情况 O(n)*/
/*最坏的情况（输入数据逆有序） O(n^2)*/
/*平均的情况（耗时是最坏情况的一半）O(n^2)*/
#include<stdio.h>
int insert(int arr[], int n){   //从小到大排序
    int i;
    int j;
    for(i=2; i<n; i++){               //执行n-2趟插入
        if(arr[i] < arr[i-1]){              //留出arr[0]作为哨兵
            arr[0]=arr[i];                 //将要插入的数暂存arr[0] ,哨兵
            j=i-1;
            while(j>=0 && arr[0]<arr[j]){  
                arr[j+1] = arr[j]; //将a[j]后移，再将j减1
                j--;
            }                                           
            arr[j+1] = arr[0]; //将arr[0]插入到指定位置
        }
                            
    }
    return 0;
}
int main(){
    int i;
    int len;
    printf("输入数组长度:");
    scanf("%d", &len);
    int arr[len];
    for(i = 1; i < len+1; i++){ //留出arr[0]作为哨兵
        scanf("%d", &arr[i]);
    }
    //int len = sizeof(arr)/sizeof(int);     ps 计算数组长度常规方法.
    insert(arr, len+1);
    for(i = 1; i < len+1; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
