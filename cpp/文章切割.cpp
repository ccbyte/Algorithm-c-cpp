#include "iostream.h"
#include "fstream.h"

void main(){
	ifstream infile("wenzhang.txt");
	ofstream outfile("result.txt",ios::ate);
	
	char ch;
	int i=1;
	outfile<<i<<" ";
	while(!infile.eof()){
		ch=infile.get();
		outfile<<ch;
		if(ch==char('.')||ch==char(',')||ch==char('?')){
			i++;
			outfile<<endl;
		}
		if(peek())
	}
}