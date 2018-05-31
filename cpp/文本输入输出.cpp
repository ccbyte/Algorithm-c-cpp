#include "iostream.h"
#include "fstream.h"
#include "stdlib.h"
#include "time.h"
#include "string"
using std::string;
typedef int Elemtype;
#define maxsize 100
typedef struct 
{
	Elemtype* elem;
	int length;
}LNode;
int Initlist(LNode &l)
{ 
	if(!l.elem) return 0;
	l.elem=new Elemtype[maxsize];
	l.length=maxsize;
	return 1;
}
void main()
{
	int c;
	srand((int)time(0));
	c = rand()%21-10;
	//string str;
	//str ="hxc";
	//split()
//	cout<<str<<endl;
	cout<<c<<endl;
	int i=1,x;
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	LNode L;
	Initlist(L);
	while(!infile.eof())
	{
		infile>>L.elem[i];
		i++;
	}
	int n=i-1;
	infile.close();
	cout<<"设置输出时一行多少数据:"<<endl;
	cin>>x;
	for(int j=1;j<=n;j++)
	{
		
		outfile<<L.elem[j]<<" ";
		if(j%x==0)
		{
		outfile<<endl;
		}
	}
	cout<<"输出成功"<<endl;
}
