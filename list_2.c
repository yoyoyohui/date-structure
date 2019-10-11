/*动态栈*/
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
typedef struct Node{
    int data;
    struct Node * pNext;
}NODE, * PNODE;
/*定义栈*/
typedef struct Stack{
    PNODE pTop;//指向栈的顶部
    PNODE pBottom;//指向栈的底部
}STACK, * PSTACK;

void init(PSTACK);//初始化
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
void clear(PSTACK);
bool empty(PSTACK);

int main(){
    STACK S; //空间S有顶部和底部
    int val;

    init(&S);//清除垃圾值,造一个空栈
    push(&S, 89);//压栈
    push(&S, 7);
    push(&S, 3);
    push(&S, 9);
    push(&S, 22);
    push(&S, 66);
    traverse(&S);//遍历输出

    clear(&S);
    traverse(&S);//遍历输出

    if( pop(&S, &val) ){
        printf("出栈成功, 出栈元素是%d\n", val);
    }
    else{
        printf("出栈失败!\n");
    }
    traverse(&S);//遍历输出

    return 0;
}
/*造出了一个空栈*/
void init(PSTACK pS){//令顶和低都指向相当于头结点的地方
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if(NULL == pS->pTop){
        printf("动态内存分布失败!\n");
        exit(-1);
    }
    else{
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;//pS->pBottom->pNext = NULL
    }
}

void push(PSTACK pS, int val){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop; //定义指向下一个元素,因为pS->pTop一开始是指向初始化的空栈
    pS->pTop = pNew;//令pTop指向新的结点

    return;
}

void traverse(PSTACK pS){
    PNODE p = pS->pTop;//定义指针p永远指向栈顶,所以会一直指向栈顶元素
    while(p != pS->pBottom){//当指向栈底了就停止
            printf("%d ", p->data);
            p = p->pNext;
    }
    printf("\n");
    return;
}

bool empty(PSTACK pS){
    if(pS->pTop == pS->pBottom){
        return true;
    }
    else{
        return false;
    }
}
/*把pS所指向的栈出栈一次,
并把出栈的元素存入pVal形参所指向的变量中,
如果出栈失败,返回false, 否则返回true*/
bool pop(PSTACK pS, int * pVal){
    if(empty(pS)){//pS本身就是存放S的地址
        return false;
    }
    else{
        PNODE r = pS->pTop; //出栈,就是从顶开始删除,定义一个r指向顶部
        *pVal = r->data;
        pS->pTop = r->pNext;
        free(r);
        r = NULL;
    }
    return 0;
}
//清空
void clear(PSTACK pS){
    if( empty(pS) ){
        return;
    }
    else{
        PNODE p = pS->pTop;
        PNODE q = NULL;

        while(p != pS->pBottom){
            q = p->pNext;
            free(p);
            p = q;
        }
        pS->pTop = pS->pBottom;
    }
}
