#include <iostream.h>
#include "fstream.h"
#include <iomanip.h>
const int MAX=1000;
int w[MAX],v[MAX],best[MAX];
int V[MAX][MAX];//最大价值矩阵
int W,n;//W为背包的最大载重量，n为物品的数量
//求最大值函数
int max(int x,int y)
{
	return x>=y?x:y;
}
//求最小值函数
int min(int x,int y)
{
	return x>=y?y:x;
}
void knaspack()
{
	int Max=min(w[n]-1,W);
	for(int j=1;j<=Max;j++)
		V[n][j]=0;
	for(j=w[n];j<=W;j++)
		V[n][j]=v[n];
	for(int i=n-1;i>1;i--)
	{
		Max=min(w[i]-1,W);
		for(j=1;j<=Max;j++)
			V[i][j]=V[i+1][j];
		for(j=w[i];j<=W;j++)
			V[i][j]=max(V[i+1][j],V[i+1][j-w[i]]+v[i]);
	}
	V[1][W]=V[2][W]; //先假设第一个物品不放入
	if(W>w[1])
		V[1][W]=max(V[1][W],V[2][W-w[1]]+v[1]);
}
//生成向量数组，觉得某个物品是否应该放入背包
void traceback()
{
	for(int i=1;i<n;i++)//比较矩阵两邻两行（除最后一行），背包容量为W的最优值
	{
		if(V[i][W]==V[i+1][W])//如果当前行的最优值与下一行的最优值相等，则表明该物品不能放
		{
			best[i]=0;
		}
		else
		{
			best[i]=1;
			W-=w[i];
		}
	}
	best[n]=(V[n][W])?1:0;
}
void main()
{
	int i;
	char input[100],output[100];
    cout<<"请输入读入的文件名:"<<endl;
	cin>>input;
	cout<<"请输入输出的文件名:"<<endl;
	cin>>output;
	ifstream infile(input);
	ofstream outfile(output);
	//cout<<"输入商品的数量n和背包的容量W：";
	infile>>n;
	infile>>W;
	//cout<<"输入每件商品的重量W："<<endl;
	for(i=1;i<=n;i++)
		infile>>w[i];
	//memset(V,0,sizeof(V));
	//cout<<"输入每件商品的价值v："<<endl;
	for(i=1;i<=n;i++)
		infile>>v[i];
	infile.close();
	outfile.setf(ios::left);
	cout<<endl<<"最后结果写入输出文本中"<<endl;
	knaspack();//构造矩阵
	traceback();//求出解得向量数组
	int totalW=0;
	int totalV=0;
	//显示可以放入的物品
	outfile<<"所选择的商品如下："<<endl;
	outfile<<"商品序号i:   重量w:   价格v:  "<<endl;
	for(i=1;i<=n;i++)
	{
		if(best[i]==1)
		{
			totalW+=w[i];
			totalV+=v[i];
			outfile<<setw(5)<<i<<"        "<<w[i]<<"        "<<v[i]<<endl;
		}
	}
	outfile<<"放入的物品重量总和是："<<totalW<<"  价值最优解是："<<totalV<<endl;
}
