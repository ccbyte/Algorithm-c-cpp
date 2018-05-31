#include <iostream.h>
#define TRUE  1
#define FALSE 0
#define OK   1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 100
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
    int data;
    struct LNode *next;
}LNode,*LinkList;
Status InitList(LinkList &L)
{
    L=new LNode;
	if(!L) return 0;
    L->next=NULL;
	return OK;
}
Status CreateList_R(LinkList &L)
{
    LNode *p;
    LNode *r;
    L=new LNode;                                                     
    L->next=NULL;                         
    r=L;
	p=new LNode;                                   
    for(cin>>p->data;p->data!=-1;)
	{   
		p=new LNode;
		cin>>p->data;
        p->next=NULL;                     
        r->next=p;                        
        r=p;                             
    }
	return OK;
}
Status ListLength(LinkList L,int &i)
{
    LNode *p;
    p=L->next;
    while(p)
	{
        p=p->next;
		i++;
	}
	return OK;
}
void main()
{
    int i=0;
    LinkList L;
    InitList(L);
    cout<<"Create List(ÒÔ-1½áÎ²):"<<endl;
    CreateList_R(L);
    cout<<endl;
	ListLength(L,i);
	cout<<"The length of list: "<<i<<endl;
}
