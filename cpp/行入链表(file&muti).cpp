#include"iostream.h"
#include"fstream.h"
#include"string"
typedef struct LNode{
	char data;
	struct LNode* next;
}LNode,*LinkList;
void main(){
	int i,length;
	char ch;
	LNode* L;
	LNode* p;
	L=new LNode;
	L->next=NULL;
	ifstream fin("input.txt");
	
	LNode* r=L;
	while(!fin.eof()){
		p=new LNode;
		ch=fin.get();
		if(ch=='\n') break;
		else p->data=ch;
		p->next=NULL;
		r->next=p;
		r=p;
		i++;
	}
	
	length=i;
	
	p=L->next;
	while(p->next!=NULL){
		cout<<p->data<<",";
		p=p->next;
	}
	std::string strx="cc";
	cout<<sizeof("cc")<<endl;
}