#include<stdio.h>
#define N 20
#define TRUE 1
#define INF 32766                    /*邻接矩阵中的无穷大元素*/
#define INFIN 32767                  /*比无穷大元素大的数*/

typedef struct
{ /*图的邻接矩阵*/
    int vexnum,arcnum;
    char vexs[N];
    int arcs[N][N];
}graph;

void createGraph_w(graph *g,int flag);
void prim(graph *g,int u);
void dijkstra(graph g,int v);
void showprim();
void showdij();

/*建带权图的邻接矩阵,若flag为1则为无向图，flag为0为有向图*/
void createGraph_w(graph *g,int flag)
{
    int i,j,w;
    char v;
    g->vexnum=0;
    g->arcnum=0;
    i=0;
    printf("输入顶点序列(以#结束)：\n");
    while((v=getchar())!='#')
    {
        g->vexs[i]=v;        /*读入顶点信息*/
        i++;
    }
    g->vexnum=i;
    for(i=0;i<6;i++)        /*邻接矩阵初始化*/
        for(j=0;j<6;j++)
            g->arcs[i][j]=INF;
    printf("输入边的信息：\n");
    scanf("%d,%d,%d",&i,&j,&w);  /*读入边(i,j,w)*/
    while(i!=-1)              /*读入i为－1时结束*/
    {
        g->arcs[i][j]=w;
        if(flag==1)
            g->arcs[j][i]=w;
        scanf("%d,%d,%d",&i,&j,&w);
    }
}

void prim(graph *g,int u)/*出发顶点u*/
{
    int lowcost[N],closest[N],i,j,k,min;
    for(i=0;i<g->vexnum;i++)  /*求其他顶点到出发顶点u的权*/
    {
        lowcost[i]=g->arcs[u][i];
        closest[i]=u;
    }
    lowcost[u]=0;
    for(i=1;i<g->vexnum;i++)    /*循环求最小生成树中的各条边*/
    {   min=INFIN;
        for(j=0;j<g->vexnum;j++)   /*选择得到一条代价最小的边*/
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                min=lowcost[j];
                k=j;
            }
        printf("(%c,%c)--%d\n",g->vexs[closest[k]],g->vexs[k],lowcost[k]);      /*输出该边*/
        lowcost[k]=0;       /*顶点k纳入最小生成树 */
        for(j=0;j<g->vexnum;j++)  /*求其他顶点到顶点k 的权*/
            if(g->arcs[k][j]!=0&&g->arcs[k][j]<lowcost[j])
            {
                lowcost[j]=g->arcs[k][j];
                closest[j]=k;
            }
    }
}

void printPath(graph g,int startVex,int EndVex)
{
    int stack[N],top=0;   /*堆栈*/
    int i,k,j;
    int flag[N];  /*输出路径顶点标志*/
    k=EndVex;
    for (i=0;i<g.vexnum;i++) flag[i]=0;
    j=startVex;
    printf("%c",g.vexs[j]);
    flag[j]=1;
    stack[top++]=k;
    while (top>0) /*找j到k的路径*/
    {
        for (i=0;i<g.vexnum;i++)
        {
            if (path[k][i]==1 && flag[i]==0) /*j到k的路径含有i顶点*/
            {
                if (g.arcs[j][i]!=INF )   /*j到i的路径含有中间顶点*/
                {
                    printf("-> %c(%d) ",g.vexs[i],g.arcs[j][i]); 
                            /*输出j到k的路径的顶点i*/
                    flag[i]=1;
                    j=i;
                    k=stack[--top];
                    break;
                }
                else
                {
                    if (i!=k) stack[top++]=i;  /*break;*/
                }
            }
        }
    }

void dijkstra(graph g,int v){  /*dijkstra算法求单源最短路径*/
    int path[N][N],dist[N],s[N];
    int mindis,i,j,u,k;
    for(i=0;i<g.vexnum;i++){
        dist[i]=g.arcs[v][i];
        s[i]=0;
        for(j=0;j<g.vexnum;j++)
            path[i][j]=0;
        if(dist[i]<INF){
            path[i][v]=1;
            path[i][i]=1;
        }
    }
    dist[v]=0;
    s[v]=1;
    for(i=0,u=1;i<g.vexnum;i++){
        mindis=INFIN;
        for(j=0;j<g.vexnum;j++)
            if(s[j]==0)
                if(dist[j]<mindis){
                    u=j;
                    mindis=dist[j];
                }
        s[u]=1;
        for(j=0;j<g.vexnum;j++)
            if((s[j]==0)&&dist[u]+g.arcs[u][j]<dist[j]){
                dist[j]=dist[u]+g.arcs[u][j];
                for(k=0;k<g.vexnum;k++)
                    path[j][k]=path[u][k];
                path[j][j]=1;
            }
    }
    printf("\n顶点%c->到各顶点的最短路径\n",g.vexs[v]);
    for(i=0;i<g.vexnum;i++){
        printf("\n顶点%c->顶点%c：",g.vexs[v],g.vexs[i]);
        if(dist[i]==INF||dist[i]==0)
            printf("无路径");
        else{
            printf("%d  ",dist[i]);
            printf("经过顶点：");
            printPath(g,v,i);  /*输出v到i的路径*/
        }
    }
}

void showprim()/*最小生成树prim算法演示*/
{
    graph ga;
    createGraph_w(&ga,1);
    prim(&ga,0);
}

void showdij(){   /*dijstra算法演示*/
    graph ga;
    createGraph_w(&ga,0);
    dijkstra(ga,0);
}

int main(int argc,char **argv){
    showprim(); /*prim算法演示*/
    getchar();
    showdij();  /*dijstra算法演示*/
    return 0;
}
