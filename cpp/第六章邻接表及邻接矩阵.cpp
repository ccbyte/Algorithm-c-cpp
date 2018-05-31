#include "iostream"
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXInt 32767
#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef int Status;

typedef struct
{//邻接矩阵
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum,arcnum;//点数，边数
}AMGraph;

//邻接表
typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;
typedef struct
{
	VerTexType data;
	ArcNode* firstarc;
}VNode,AdjList[MVNum];
typedef struct
{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

Status CreateUDN(AMGraph &G)
{//创矩阵
	int i,j;
	cout<<"请输入边数和顶点数"<<endl;
	cin>>G.arcnum>>G.vexnum;
	cout<<"请顺序输入顶点内信息（char）"<<endl;
	for(i=0;i<G.vexnum;++i)
		cin>>G.vexs[i];
	cout<<"请录入边信息(邻接矩阵)"<<endl;
	for(i=0;i<G.vexnum;i++)  
    {  
            for(j=0;j<G.vexnum;j++)  
            {  
                    cin>>G.arcs[i][j];
            }
    }
	return OK;
}

Status CreateUDG(ALGraph* &G)
{//创邻接表
	ArcNode* p1;
	int i,k;
	G=new ALGraph;
	cout<<"请输入边数和顶点数"<<endl;
	cin>>G->arcnum>>G->vexnum;
	for(i=0;i<G->vexnum;++i)
	{
		cout<<"请顺序输入第"<<(i+1)<<"个顶点内信息（char）"<<endl;
		cin>>G->vertices[i].data;
		G->vertices[i].firstarc=NULL;
	}
	cout<<"请录入边信息"<<endl;
	for(k=0;k<G->vexnum;++k)
	{
		cout<<"请输入第"<<(k+1)<<"个顶点指向的顶点（以-1结束）"<<endl;
		for(cin>>i;i!=-1;cin>>i)
		{
		    p1=new ArcNode;
			p1->adjvex=i;
			p1->nextarc=G->vertices[k].firstarc;
			G->vertices[k].firstarc=p1;
		};
	}
	return OK;
}
void ChangeToUDG(AMGraph g,ALGraph* &G)  
//将邻接矩阵g转换成邻接表G  
    {   int i,j;  
        ArcNode* p;  
        G=new ALGraph;  
        for (i=0;i<g.vexnum;i++)                  
            G->vertices[i].firstarc=NULL;  
        for (i=0;i<g.vexnum;i++)                    
            for (j=g.vexnum-1;j>=0;j--)  
                if (g.arcs[i][j]!=0)      
                {   
					p=new ArcNode;
                    p->adjvex=j;
                    p->nextarc=G->vertices[i].firstarc;
                    G->vertices[i].firstarc=p;
                }  
        G->vexnum=g.vexnum;G->arcnum=g.arcnum;
    }

void ChangeToUDN(ALGraph* G,AMGraph &g)  
//将邻接表G转换成邻接矩阵g 
    {   int i,j;  
        ArcNode* p;
		for(i=0;i<G->vexnum;i++)
			for(j=0;j<G->vexnum;j++)
				g.arcs[i][j]=0;//初始化邻接矩阵
        for(i=0;i<G->vexnum;i++)
		{
			p=G->vertices[i].firstarc;
				while(p!=NULL)
				{
					g.arcs[i][p->adjvex]=1;
					p=p->nextarc;
				}
		}
		g.vexnum=G->vexnum;g.arcnum=G->arcnum;
    }

void ShowUDN(AMGraph g)  
//输出邻接矩阵g  
{  
    int i,j;  
    for (i=0;i<g.vexnum;i++)  
    {  
        for (j=0;j<g.vexnum;j++)  
			cout<<g.arcs[i][j]<<"  ";
        cout<<endl;  
    }  
}

void ShowUDG(ALGraph *G)  
//输出邻接表G  
    {  
        int i;  
        ArcNode *p;
        for (i=0;i<G->vexnum;i++)  
        {  
            p=G->vertices[i].firstarc;  
            
            cout<<i<<"=>";  
            while (p!=NULL)  
            {
                cout<<p->adjvex<<" ";  
                p=p->nextarc;  
            }  
            printf("\n");  
        }  
    }  

void main()
{
	int x;
	AMGraph G1;
	ALGraph* G2;
	cout<<"第六章——邻接表及邻接矩阵"<<endl;
	cout<<"1.创建邻接矩阵"<<endl;
	cout<<"2.创建邻接表"<<endl;
	cout<<"3.邻接矩阵==>>邻接表"<<endl;
	cout<<"4.邻接表==>>邻接矩阵"<<endl;
	cout<<"5.输出邻接表"<<endl;
	cout<<"6.输出邻接矩阵"<<endl;
	cin>>x;
	switch(x)
	{
	case 1:{
		CreateUDN(G1);
		break;
		   }
	case 2:{
		CreateUDG(G2);
		break;
		   }
	case 3:{
		CreateUDN(G1);
		ChangeToUDG(G1,G2);
		cout<<"转化成邻接表后:"<<endl;
		ShowUDG(G2);
		break;
		   }
	case 4:{
		CreateUDG(G2);
		ChangeToUDN(G2,G1);
		cout<<"转化成邻接矩阵后:"<<endl;
		ShowUDN(G1);
		break;
		   }
	case 5:{
		ShowUDN(G1);
		break;
		   }
	case 6:{
		ShowUDG(G2);
		break;
		   }
	}
}