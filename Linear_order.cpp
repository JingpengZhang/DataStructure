//
// Created by Jingpeng Zhang on 2021/8/1.
//
#include "stdio.h"
#include "malloc.h"
#define MAXSIZE 100//定义顺序表最多存放的元素个数
typedef int ElementType;//定义顺序表存放的元素的数据类型
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];//存放数据元素的数组
    int Last;//最后一个元素的下标（可以反映该线性表的长度）
};

//初始化一个空线性表L
List MakeEmpty(){
    List L;
    L = (List)malloc(sizeof (struct LNode));
    L->Last = -1;
    return L;
}

//根据位序K，返回对应元素
ElementType FindKth(int K,List L){
    if ( K < 1 || K > L->Last+1 ){
        printf("位序不合法");
        return -1;
    } else {
        return L->Data[K-1];
    }
}

//在线性表L中查找X的第一次出现位置
int Find(ElementType X,List L){
    int i = 0;
    while ( i <= L->Last && L->Data[i] != X )
        i++;
    if ( i > L->Last)//如果没找到，返回-1
        return -1;
    else//找到后返回的是存储位置
        return i;
}
//在位序i前插入一个新元素X
void Insert(ElementType X,int i,List L){
    int j;
    if ( L->Last == MAXSIZE-1 ){//表空间已满，不能插入
        printf("表满");
        return;
    }
    if ( i < 1 || i > L->Last+2 ){
        printf("位置不合法");
        return;
    }
    for ( j = L->Last;  j >= i-1; j--) {//将ai~an倒序向后移动
        L->Data[j+1] = L->Data[j];
    }
    L->Data[i-1] = X;//新元素插入
    L->Last++;//Last仍指向最后元素
    return;
}
//删除指定位序i的元素
void Delete(int i,List L){
    int j;
    if ( i<1 || i > L->Last+1 ){
        printf("不存在第%d个元素",i);
        return;
    }
    for (j = i; j <= L->Last; j++) {
        L->Data[j-1] = L->Data[j];//将ai~an顺序向前移动
    }
    L->Last--;//Last仍指向最后元素
    return;
}
//返回线性表L的长度n
int Length(List L){
    return L->Last+1;
}

int main(void){
    List L1 = MakeEmpty();
    //向表L1中插入元素
    int a[8] = {2,0,2,1,0,8,0,2};
    for (int i = 0; i < 8; i++) {
        Insert(a[i],i+1,L1);
    }
    //输出表长
    int length = Length(L1);
    printf("表L1的长度为：%d\n",length);
    //遍历表L1
    printf("表L1中的元素为：");
    for (int i = 1; i <= L1->Last+1; i++) {
        printf("%d ", FindKth(i,L1));
    }
    //查找表中0第一次出现的位置
    printf("\n元素“0“在表L1中第一次出现的元素下标为：%d", Find(0,L1));
    //删除表L1中的第5个元素之后打印表内的所有元素
    printf("\n删除表L1中第5个元素后，表L1中的元素为：");
    Delete(5,L1);
    for (int i = 1; i <= L1->Last+1; ++i) {
        printf("%d ", FindKth(i,L1));
    }
    printf(",此时表L1的长度为：%d", Length(L1));
    return 0;
}