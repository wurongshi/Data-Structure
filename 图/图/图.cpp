// 图.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "队列.h"
#include "最小堆.h"
#include "并查集.h"
#include "图的模板基类.h"
#include "用邻接矩阵表示无向图.h"
#include "用邻接矩阵表示有向图.h"
#include "无向图的邻接表表示.h"
#include "图的遍历.h"
#include "最小生成树.h"
#include "最短路径.h"
#include "AOV(拓扑排序).h"
#include "AOE(关键路径).h"
int dist[100]={0};
int path[100]={0};

int _tmain()
{
	//Graphmtx<int,int> g(10);
	//cin>>g;
	//cout<<g;
	int a[100][100]={0};
    int Path[100][100]={0};
	GraphmtxD<int,int> G(20);
	cin>>G;
	CriticalPath(G);
	TopologicalSort(G);
	//Floyd<int,int>(G);
	//ShortestPath(G,0,dist,path);
	//Bellman_Ford(G,0,dist,path);
	//Graphmtx<int,int> gl(10);
	//MinSpanTree<int,int> MST0,MST1;
	//cin>>gl;
	//cout<<gl;
	//Kruskal<int,int>(gl,MST0);
	//cout<<"输出Kruskal最小生成树："<<endl;
	//cout<<MST0;
	//Prim(gl,0,MST1);
	//cout<<"输出Prim最小生成树："<<endl;
	//cout<<MST1;
	//int loc=0;
	//DFS(gl,loc);
	//BFS(gl,1);
	//Graphmtx<char,int> gl2(20);
	//cin>>gl2;
	//Components(gl2);
	return 0;
}

