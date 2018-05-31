#include"iostream.h"  
#include"math.h"
#include"stdlib.h"
#include"ctime"
int a[100];
inline int Random(int x, int y)  
{  
     int ran_num = rand() % (y - x) + x;  
     return ran_num;  
}  
void main(){
	srand((unsigned)time(0));  
  
    for(int i=0; i<20; i++)  
    {  
        a[i] = Random(0,100);  
        cout<<"a["<<i<<"]:"<<a[i]<<" ";  
    }  
    cout<<endl; 
	int temp;
	for(i=0;i<20;i++)
		for(int j=0;j<19;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	
	for(i=0; i<20; i++)  
    {  
        cout<<"a["<<i<<"]:"<<a[i]<<" ";  
    }  
    cout<<endl;
}