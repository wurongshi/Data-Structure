// ջ�Ͷ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ջ\ջ\˳��ջ.h"
#include "ջ\ջ\��ʽջ.h"
#include "ջ\ջ��Ӧ��\���ʽ����.h"
#include "ջ\ջ��Ӧ��\����ƥ��.h"
#include "ջ\ջ��ݹ�\�ݹ�.h"
#include "ջ\ջ��ݹ�\�Թ�����.h"
#include "����\����\˳�����.h"
#include "����\����\��ʽ����.h"
#include "����\����\ѭ������.h"
#include "����\����\˫�˶���\����.h"
#include "����\����\˫�˶���\��ʽ.h"
#include "����\����\���ȼ�����.h"
#include "����\���е�Ӧ��\���е�Ӧ��.h"
int _tmain(int argc, _TCHAR* argv[])
{
	//-------------˳��ջ-----------------------
	int max,n;
	cout<<"����һ��ջ������ջ�����������";
	cin>>max;
	SeqStack<int>st(max);
	cout<<"����Ԫ�صĸ�����";
	cin>>n;
	cout<<endl<<"���� "<<n<<" ��Ԫ�أ�"<<endl; 
	st.input(n);
	cout<<"���ջ��Ԫ�أ�"<<endl;
	cout<<st;
	//--------------��ʽջ-----------------------------
	LinkedStack<int> ls;
	int x;
	ls.input();
	cout<<ls;
	ls.Pop(x);
	cout<<"ɾ����Ԫ��Ϊ��"<<x<<endl;
	cout<<ls;
	ls.getTop(x);
	cout<<"ջ��Ԫ��Ϊ�� "<<x<<endl; 
	//---------------���ʽ����-----------------------
	Calculator s(50);
	s.Run();
	s.output();
	cout<<endl<<"����׺��ʾת��Ϊ��׺��ʾ��"<<endl;
	postfix();
	//--------------����ƥ��-----------------------------
	char *str; int i;
	str=new char[maxLength];
	cout<<"���ʽ���ȣ�"; 
	cin>>n;
	for(i=0;i<n;i++){
		cin>>str[i];
	}
	PrintMatchedPairs<char>(str);
	//-------------------------�׳�---------------------
	cout<<Factorial(8)<<endl;  // 8! 
	Hanoi(3,'A','B','C');
	cout<<Fib(8)<<endl;
	cout<<FibIter(8)<<endl;
	cout<<Fibnacci(8)<<endl;
	//-----------------------�Թ�����-----------------------
	int j;
	for(i=0;i<5;i++)
	    for(j=0;j<5;j++)
	        mark[i][j]=0;
	for(i=0;i<m+2;i++){
		for(j=0;j<p+2;j++){
			cin>>Maze[i][j];
		}
	}
	mark[1][1]=1;
	if(SeekPath(1,1)){
		cout<<"("<<1<<","<<1<<");  "<<"Direction:  "<<"E"<<endl;
	}
	//-----------------------˳�����------------------------------------
	SeqQueue<int> sq;
	sq.input();
	sq.output();
	cout<<"����һ��Ԫ�أ��������Ԫ�أ�"<<endl;
	cin>>x;
	sq.EnQueue(x);
	sq.output();
	sq.DeQueue(x);
	cout<<"ɾ��һ��Ԫ�أ�ɾ����Ԫ��Ϊ��"<<x<<endl;
	sq.output();
	//------------------��ʽ����------------------------------
	LinkedQueue<int> q; 
	cin>>q;
	cout<<q;
	cout<<"����һ��Ԫ�أ�����Ԫ�أ�"<<endl;
	cin>>x; 
	q.EnQueue(x);
	cout<<q;
	q.DeQueue(x);
	cout<<"ɾ����Ԫ��Ϊ��"<<x<<endl;
	cout<<q;
	//----------------ѭ������---------------------
	CireQueue<int> cq(50);
	cq.input();
	cout<<cq;
	//--------------���ȼ�����--------------------------
	PQueue pq(50);
	cin>>pq;
	cout<<pq;
	//----------------���е�Ӧ��--------------------------
	cin>>n;
	YANGVI(n);
	cout<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			cin>>grid[i][j];
		}
	}
	Position *path,start,finish; int PathLen;
	path=new Position[m*m];
	start.row=3; start.col=2;
	finish.row=4; finish.col=6;
	FindPath(start,finish,PathLen,path);
	cout<<"·������Ϊ�� "<<PathLen<<endl;
	cout<<"( "<<start.row<<" , "<<start.col<<" )"<<endl;
	for(int k=1;k<PathLen;k++){
		cout<<"( "<<path[k].row<<" , "<<path[k].col<<" )"<<endl;
	}
	return 0;
}

