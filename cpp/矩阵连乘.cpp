#include<iostream>
 using namespace std;
 const int MAX = 100;

int p[MAX+1],m[MAX][MAX],s[MAX][MAX];
int n;//�������

void matrixChain(){
    for(int i=1;i<=n;i++)m[i][i]=0;

    for(int r=2;r<=n;r++)
        for(int i=1;i<=n-r+1;i++){
            int j = r+i-1;
            m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
            s[i][j]=i;
            for(int k = i+1;k<j;k++){
                int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(temp<m[i][j]){
                    m[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
}

void traceback(int i,int j){
    if(i==j)return ;

    traceback(i,s[i][j]);
    traceback(s[i][j]+1,j);
    cout<<"Multiply A"<<i<<","<<s[i][j]<<"and A"<<s[i][j]+1<<","<<j<<endl;
}

int main(){
    cin>>n;
    for(int i=0;i<=n;i++)cin>>p[i];
    matrixChain();

    traceback(1,n);

    cout<<m[1][n]<<endl;
    return 0;
}