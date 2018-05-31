#include "iostream.h"
#include "fstream.h"
ofstream outfile("output.txt");
void Hanoi(int n,char a,char b,char c){
	if( n>0 ){
		Hanoi(n-1,a,c,b);
		cout<<a<<" "<<b<<endl;
		outfile<<a<<" "<<b<<endl;
		Hanoi(n-1,c,b,a); 
	}
}

int main(){
	int n;
	ifstream infile("input.txt");
	infile>>n;
	const x=n;
	infile.close();
	//a起始，b目标,c中转
	Hanoi(n,'A','B','C');
	return 0;
}