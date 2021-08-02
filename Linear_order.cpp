//
// Created by Jingpeng Zhang on 2021/8/1.
//
#include "stdio.h"
#include "malloc.h"
#define MAXSIZE 100//����˳�������ŵ�Ԫ�ظ���
typedef int ElementType;//����˳����ŵ�Ԫ�ص���������
typedef struct LNode *List;
struct LNode{
    ElementType Data[MAXSIZE];//�������Ԫ�ص�����
    int Last;//���һ��Ԫ�ص��±꣨���Է�ӳ�����Ա�ĳ��ȣ�
};

//��ʼ��һ�������Ա�L
List MakeEmpty(){
    List L;
    L = (List)malloc(sizeof (struct LNode));
    L->Last = -1;
    return L;
}

//����λ��K�����ض�ӦԪ��
ElementType FindKth(int K,List L){
    if ( K < 1 || K > L->Last+1 ){
        printf("λ�򲻺Ϸ�");
        return -1;
    } else {
        return L->Data[K-1];
    }
}

//�����Ա�L�в���X�ĵ�һ�γ���λ��
int Find(ElementType X,List L){
    int i = 0;
    while ( i <= L->Last && L->Data[i] != X )
        i++;
    if ( i > L->Last)//���û�ҵ�������-1
        return -1;
    else//�ҵ��󷵻ص��Ǵ洢λ��
        return i;
}
//��λ��iǰ����һ����Ԫ��X
void Insert(ElementType X,int i,List L){
    int j;
    if ( L->Last == MAXSIZE-1 ){//��ռ����������ܲ���
        printf("����");
        return;
    }
    if ( i < 1 || i > L->Last+2 ){
        printf("λ�ò��Ϸ�");
        return;
    }
    for ( j = L->Last;  j >= i-1; j--) {//��ai~an��������ƶ�
        L->Data[j+1] = L->Data[j];
    }
    L->Data[i-1] = X;//��Ԫ�ز���
    L->Last++;//Last��ָ�����Ԫ��
    return;
}
//ɾ��ָ��λ��i��Ԫ��
void Delete(int i,List L){
    int j;
    if ( i<1 || i > L->Last+1 ){
        printf("�����ڵ�%d��Ԫ��",i);
        return;
    }
    for (j = i; j <= L->Last; j++) {
        L->Data[j-1] = L->Data[j];//��ai~an˳����ǰ�ƶ�
    }
    L->Last--;//Last��ָ�����Ԫ��
    return;
}
//�������Ա�L�ĳ���n
int Length(List L){
    return L->Last+1;
}

int main(void){
    List L1 = MakeEmpty();
    //���L1�в���Ԫ��
    int a[8] = {2,0,2,1,0,8,0,2};
    for (int i = 0; i < 8; i++) {
        Insert(a[i],i+1,L1);
    }
    //�����
    int length = Length(L1);
    printf("��L1�ĳ���Ϊ��%d\n",length);
    //������L1
    printf("��L1�е�Ԫ��Ϊ��");
    for (int i = 1; i <= L1->Last+1; i++) {
        printf("%d ", FindKth(i,L1));
    }
    //���ұ���0��һ�γ��ֵ�λ��
    printf("\nԪ�ء�0���ڱ�L1�е�һ�γ��ֵ�Ԫ���±�Ϊ��%d", Find(0,L1));
    //ɾ����L1�еĵ�5��Ԫ��֮���ӡ���ڵ�����Ԫ��
    printf("\nɾ����L1�е�5��Ԫ�غ󣬱�L1�е�Ԫ��Ϊ��");
    Delete(5,L1);
    for (int i = 1; i <= L1->Last+1; ++i) {
        printf("%d ", FindKth(i,L1));
    }
    printf(",��ʱ��L1�ĳ���Ϊ��%d", Length(L1));
    return 0;
}