#include <malloc.h>
#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
typedef int Status;
typedef double ElemType;
//-----------------------------------
//定义单向循环链表
typedef struct LNode
{
    int number;
    int data;
    struct LNode *next;
} LNode, *LinkList;
//-----------------------------------
LinkList EvaluList(int n);//对单向循环链表进行尾插入赋值
int size(LinkList L);//求链表的节点个数
Status ScanList(LinkList L);//遍历单向循环链表
Status Joseph(LinkList &L,int m);//约瑟夫环的实现
//-------------------------------------------------
int main()
{
    int m,n;
    cout<<"请输入初始密码(正整数)和人数"<<endl;
    cin>>m>>n;
    cout<<endl<<"请输入"<<n<<"个人的密码"<<endl<<endl;
    LinkList L=EvaluList(n);
    cout<<n<<"个人的密码为"<<endl;
    ScanList(L);
    cout<<n<<"个人的出列顺序为"<<endl;
    Joseph(L,m);
}
//---------对单向循环链表进行尾插入赋值----------------
LinkList EvaluList(int n)
{
    if(n==0)
        return NULL;
    int key;
    cout<<"输入第1个人的密码： ";
    cin>>key;
    LinkList L=new LNode;
    L->data=key;
    L->number=1;
    L->next=L;
    for(int i=2; i<=n; i++)
    {
        LinkList p=new LNode;
        int key;
        cout<<"输入第"<<i<<"个人的密码： ";
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
//---------------求链表的节点个数-------------------
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
//---------------遍历单向循环链表--------------------
Status ScanList(LinkList L)
{
    LinkList p=L;
    if(p==NULL)
    {
        cout<<"人数为空"<<endl;
        return FALSE;
    }
    cout<<"第1个人的密码是： ";
    cout<<p->data<<endl;
    p=p->next;
    while(p!=L)
    {
        cout<<"第"<<p->number<<"个人的密码是： ";
        cout<<p->data<<endl;
        p=p->next;
    }
    cout<<endl;
    return TRUE;
}
//----------------约瑟夫环的实现-----------------------
Status Joseph(LinkList &L,int m)
{
    if(L==NULL)
    {
        cout<<"人数为空，出列结束"<<endl;
        return FALSE;
    }
    LinkList p=L;
    cout<<"密码为: "<<m<<"       出列编号为: 0"<<endl;
    while(p->next!=L)
        p=p->next;
    for(int n=size(L); n>0 ; n--)
    {
        for(int i=1; i<=m%n-1; i++)
            p=p->next;
        m=p->next->data;
        cout<<"密码为: "<<m<<"       出列编号为: ";
        cout<<p->next->number<<endl;
        LinkList q=p->next;
        p->next=q->next;
        free(q);
    }
    return OK;
}

