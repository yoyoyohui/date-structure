/*插入排序 Insertion Sort  哨兵  二分折半插入排序*/
/*原始数据越接近有序， 排序越快*
/*稳定性:稳定*/ 
/*空间复杂度 O(1) 一个哨兵的空间*/
/*平均的情况 O(n^2)*/
#include<stdio.h>
int Binsert(int arr[], int n){   //从小到大排序
    int i;
    int j;
    int low;
    int high;
    int mid;
    for(i=2; i<n; i++){      //执行n-2趟插入, 留出arr[0]作为哨兵         
        arr[0] = arr[i];     //将要插入的数暂存arr[0] ,哨兵
        low = 1; 
        high = i -1;
        while(low < high){
            mid = (low + high)/2;
            if(arr[0] < arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }    //循环结束，high+1为插入位置
        for(j = i-1; j >= high + 1; j--){
            arr[j+1] = arr[j];
        }
        arr[high+1] = arr[0];
                            
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
    Binsert(arr, len+1);
    for(i = 1; i < len+1; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
