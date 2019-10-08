//单链表
# include <stdio.h>
# include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int date;
    struct Node * pNext;
}* PNODE, NODE;

PNODE create_list(void);
void traverse_list(PNODE );
bool is_empty(PNODE );
int length_list(PNODE );
bool insert_list(PNODE, int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE );

int main(){
    //int val;
    PNODE pHead = NULL;
    pHead = create_list();
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
    int len;
    int i;
    int val;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if (NULL == pHead){
        printf("分配失败， 程序终止\n");
        exit(-1);
    }

    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("輸入鏈表結點個數len：");
    scanf("%d", &len);
    for(i=0; i<len; i++){
            printf("输入第%d个节点的值：", i+1);
            scanf("%d", &val);
            PNODE pNew= (PNODE)malloc(sizeof(NODE));
            if (NULL == pNew){
                printf("分配失败， 程序终止\n");
                exit(-1);
            }
            pNew->date = val;
            pTail->pNext = pNew;
            pNew->pNext = NULL;
            pTail = pNew;
    }
    return pHead;
}

void traverse_list(PNODE pHead){
    PNODE p = pHead->pNext;

    while(NULL != p){
        printf("%d ", p->date);
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
bool insert_list(PNODE pHead, int pos, int val){
    int i = 0;
    PNODE p = pHead;

    while(NULL != p && i<pos-1){
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
