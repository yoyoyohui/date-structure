/*非循环单链表*/
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

typedef struct Node{  //定义链表结构体
    int date;
    struct Node * pNext;
}* PNODE, NODE;  //  struct Node *相当于 PNODE， struct Node相当于NODE

PNODE create_list(void); //创建非循环单链表
void traverse_list(PNODE ); //遍历链表
bool is_empty(PNODE );//判断链表是否为空
int length_list(PNODE );//判断链表长度
bool insert_list(PNODE, int, int);//链表插入元素
bool delete_list(PNODE, int, int *);//链表删除元素
void sort_list(PNODE );//链表排序

int main(){
    //int val;
    PNODE pHead = NULL; //初始化，定义头结点为空
    pHead = create_list(); //创建指针链表
    traverse_list(pHead);

    insert_list(pHead, 4, 33);
    traverse_list(pHead);

//    if(delete_list(pHead, 4, &val)){
//        printf("删除成功，元素是%d\n", val);
//    }
//    else{
//        printf("删除失败\n");
//    }
//    traverse_list(pHead);

    int len = length_list(pHead);
    printf("长度为%d\n",len);

    sort_list(pHead);
    traverse_list(pHead);

//    if(is_empty(pHead)){
//        printf("空！"\n);
//    }
//    else{
//        printf("不空！"\n);
//    }
    return 0;
}

PNODE create_list(){
    int len; //定义有效节点个数
    int i;
    int val; //临时存放链表值
    PNODE pHead = (PNODE)malloc(sizeof(NODE)); //分配头结点动态空间，此pHead与main的不同，到时候需返回给main
    if (NULL == pHead){
        printf("分配失败， 程序终止\n");
        exit(-1);
    }
    /*pTail永远指向尾结点*/
    PNODE pTail = pHead;//先pTail指向头结点
    pTail->pNext = NULL;

    printf("输入链表结点个数len：");
    scanf("%d", &len);
    for(i=0; i<len; i++){
            printf("输入第%d个节点的值：", i+1);
            scanf("%d", &val);
            /*循环为每一个有效结点分配空间*/
            PNODE pNew= (PNODE)malloc(sizeof(NODE));
            if (NULL == pNew){
                printf("分配失败， 程序终止\n");
                exit(-1);
            }
            pNew->date = val;
            pTail->pNext = pNew;//每生成一个结点都放到最后一个
            pNew->pNext = NULL;//新结点变成尾结点
            pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead){
    PNODE p = pHead->pNext;//p=pHead->pNext ,是地址,先指向首结点

    while(NULL != p){
        printf("%d ", p->date);//先是首结点的值
        p = p->pNext;
    }
    printf("\n");
    return;
}

bool is_empty(PNODE pHead){
    if(NULL==pHead->pNext){
        return true;
    }
    else{
        return false;
    }
}
int length_list(PNODE pHead){
    PNODE p = pHead->pNext;
    int len = 0;
    while(NULL!=p){
        len++;
        p = p->pNext;
    }
    return len;
}
void sort_list(PNODE pHead){
    int i, j, t;
    int len = length_list(pHead);
    PNODE p, q;
    /*小到大排*/
    for(i=0, p=pHead->pNext; i<len-1; i++, p=p->pNext){
        for(j=i+1, q=p->pNext; j<len; j++,q=q->pNext){
            if(p->date > q->date){
                t = p->date;
                p->date = q->date;
                q->date = t;
            }
        }
    }
    return;
}
/*头结点, 位置, 值*/
bool insert_list(PNODE pHead, int pos, int val){
    int i = 0;
    PNODE p = pHead;
//l链表不存在满的问题,不需要判断
    while(NULL != p && i<pos-1){//p指向pos-1的结点
        p = p->pNext;
        i++;
    }
    if(i>pos-1 || NULL==p){
        return false;
    }
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if(NULL == pNew){
        printf("动态分配失败\n");
        exit(-1);
    }
    pNew->date = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
    return true;
}
/*头结点, 位置, 地址*/
bool delete_list(PNODE pHead, int pos, int * pVal){
    int i = 0;
    PNODE p = pHead;

    while(NULL != p->pNext && i<pos-1){
        p = p->pNext;
        i++;
    }
    if(i>pos-1 || NULL==p->pNext){
        return false;
    }
    PNODE q = p->pNext;
    *pVal = q->date;
    p->pNext = p->pNext->pNext;
    free(q);
    q = NULL;
    return true;
}
