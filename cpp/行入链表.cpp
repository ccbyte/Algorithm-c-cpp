#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#define TRUE  1
#define FALSE 0
#define OK   1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef char ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
LinkList p;
Status InitList(LinkList &L)//³õÊ¼»¯
{
	L=new LNode;
	L->next=NULL;
	return OK;
}
Status GetElem(LinkList L,int i,ElemType &e)
{
	p=L->next;int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i) return ERROR;
	e=p->data;
	return OK;
}
LNode *LocateElem(LinkList L,ElemType e)
{
	p=L->next;
	while(p && p->data!=e)
		p=p->next;
	return p;
}

Status ListInsert(LinkList &L,int i,ElemType e)
{
	p=L;int j=0;
	while(p && (j<i-1))
	{p=p->next;++j;}
	if(!p||j>i-1) return ERROR;
	LinkList s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;
}

Status ListDelete(LinkList &L,int i)
{
	p=L;int j=0;
	while((p->next)&&(j<i-1))
	{
		p=p->next;++j;
	}
	if(!(p->next)||(j>i-1)) return ERROR;
	LinkList q=p->next;
	p->next=q->next;
	delete q;
	return OK;
}
void CreateList_H(LinkList &L,int n)
{
	for(int i=0;i<n;++i)
	{
		p=new LNode;
		cin>>p->data;
		p->next=L->next;
		L->next=p;
	}
}

void CreateList_R(LinkList &L,int n)
{
	LinkList r=L;
	for(int i=0;i<n;++i)
	{
		p=new LNode;
		cin>>p->data;
		p->next=NULL;
		r->next=p;
		r=p;
	}
}
void output(LinkList L)
{
	p=L;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->data<<endl;
	}
}
void main()
{
	char c;
	LinkList L;
	InitList(L);
	LinkList px;
	LinkList r=L;
	while(c!='\n')
	{
		px=new LNode;
		c=getchar();
		px->data=c;
		px->next=NULL;
		r->next=px;
		r=px;
		
		
	}
	output(L);
}