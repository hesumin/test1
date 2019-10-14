#include <malloc.h>
#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
typedef int Status;
typedef double ElemType;
//-----------------------------------
//���嵥��ѭ������
typedef struct LNode
{
    int number;
    int data;
    struct LNode *next;
} LNode, *LinkList;
//-----------------------------------
LinkList EvaluList(int n);//�Ե���ѭ���������β���븳ֵ
int size(LinkList L);//������Ľڵ����
Status ScanList(LinkList L);//��������ѭ������
Status Joseph(LinkList &L,int m);//Լɪ�򻷵�ʵ��
//-------------------------------------------------
int main()
{
    int m,n;
    cout<<"�������ʼ����(������)������"<<endl;
    cin>>m>>n;
    cout<<endl<<"������"<<n<<"���˵�����"<<endl<<endl;
    LinkList L=EvaluList(n);
    cout<<n<<"���˵�����Ϊ"<<endl;
    ScanList(L);
    cout<<n<<"���˵ĳ���˳��Ϊ"<<endl;
    Joseph(L,m);
}
//---------�Ե���ѭ���������β���븳ֵ----------------
LinkList EvaluList(int n)
{
    if(n==0)
        return NULL;
    int key;
    cout<<"�����1���˵����룺 ";
    cin>>key;
    LinkList L=new LNode;
    L->data=key;
    L->number=1;
    L->next=L;
    for(int i=2; i<=n; i++)
    {
        LinkList p=new LNode;
        int key;
        cout<<"�����"<<i<<"���˵����룺 ";
        cin>>key;
        p->data=key;
        p->number=i;
        p->next=L->next;
        L->next=p;
        L=L->next;
    }
    cout<<endl;
    L=L->next;
    return L;
}
//---------------������Ľڵ����-------------------
int size(LinkList L)
{
    if(L==NULL)
        return 0;
    int i=1;
    LinkList p=L->next;
    while(p!=L)
    {
        i++;
        p=p->next;
    }
    return i;
}
//---------------��������ѭ������--------------------
Status ScanList(LinkList L)
{
    LinkList p=L;
    if(p==NULL)
    {
        cout<<"����Ϊ��"<<endl;
        return FALSE;
    }
    cout<<"��1���˵������ǣ� ";
    cout<<p->data<<endl;
    p=p->next;
    while(p!=L)
    {
        cout<<"��"<<p->number<<"���˵������ǣ� ";
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
    return TRUE;
}
//----------------Լɪ�򻷵�ʵ��-----------------------
Status Joseph(LinkList &L,int m)
{
    if(L==NULL)
    {
        cout<<"����Ϊ�գ����н���"<<endl;
        return FALSE;
    }
    LinkList p=L;
    cout<<"����Ϊ: "<<m<<"       ���б��Ϊ: 0"<<endl;
    while(p->next!=L)
        p=p->next;
    for(int n=size(L); n>0 ; n--)
    {
        for(int i=1; i<=m%n-1; i++)
            p=p->next;
        m=p->next->data;
        cout<<"����Ϊ: "<<m<<"       ���б��Ϊ: ";
        cout<<p->next->number<<endl;
        LinkList q=p->next;
        p->next=q->next;
        free(q);
    }
    return OK;
}

