// ͼ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "����.h"
#include "��С��.h"
#include "���鼯.h"
#include "ͼ��ģ�����.h"
#include "���ڽӾ����ʾ����ͼ.h"
#include "���ڽӾ����ʾ����ͼ.h"
#include "����ͼ���ڽӱ��ʾ.h"
#include "ͼ�ı���.h"
#include "��С������.h"
#include "���·��.h"
#include "AOV(��������).h"
#include "AOE(�ؼ�·��).h"
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
	//cout<<"���Kruskal��С��������"<<endl;
	//cout<<MST0;
	//Prim(gl,0,MST1);
	//cout<<"���Prim��С��������"<<endl;
	//cout<<MST1;
	//int loc=0;
	//DFS(gl,loc);
	//BFS(gl,1);
	//Graphmtx<char,int> gl2(20);
	//cin>>gl2;
	//Components(gl2);
	return 0;
}

