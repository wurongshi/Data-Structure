// 栈和队列.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "栈\栈\顺序栈.h"
#include "栈\栈\链式栈.h"
#include "栈\栈的应用\表达式计算.h"
#include "栈\栈的应用\括号匹配.h"
#include "栈\栈与递归\递归.h"
#include "栈\栈与递归\迷宫问题.h"
#include "队列\队列\顺序队列.h"
#include "队列\队列\链式队列.h"
#include "队列\队列\循环队列.h"
#include "队列\队列\双端队列\数组.h"
#include "队列\队列\双端队列\链式.h"
#include "队列\队列\优先级队列.h"
#include "队列\队列的应用\队列的应用.h"
int _tmain(int argc, _TCHAR* argv[])
{
	//-------------顺序栈-----------------------
	int max,n;
	cout<<"创建一个栈，输入栈的最大容量：";
	cin>>max;
	SeqStack<int>st(max);
	cout<<"输入元素的个数；";
	cin>>n;
	cout<<endl<<"输入 "<<n<<" 个元素："<<endl; 
	st.input(n);
	cout<<"输出栈中元素："<<endl;
	cout<<st;
	//--------------链式栈-----------------------------
	LinkedStack<int> ls;
	int x;
	ls.input();
	cout<<ls;
	ls.Pop(x);
	cout<<"删除的元素为："<<x<<endl;
	cout<<ls;
	ls.getTop(x);
	cout<<"栈顶元素为： "<<x<<endl; 
	//---------------表达式计算-----------------------
	Calculator s(50);
	s.Run();
	s.output();
	cout<<endl<<"将中缀表示转换为后缀表示："<<endl;
	postfix();
	//--------------括号匹配-----------------------------
	char *str; int i;
	str=new char[maxLength];
	cout<<"表达式长度："; 
	cin>>n;
	for(i=0;i<n;i++){
		cin>>str[i];
	}
	PrintMatchedPairs<char>(str);
	//-------------------------阶乘---------------------
	cout<<Factorial(8)<<endl;  // 8! 
	Hanoi(3,'A','B','C');
	cout<<Fib(8)<<endl;
	cout<<FibIter(8)<<endl;
	cout<<Fibnacci(8)<<endl;
	//-----------------------迷宫问题-----------------------
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
	//-----------------------顺序队列------------------------------------
	SeqQueue<int> sq;
	sq.input();
	sq.output();
	cout<<"插入一个元素，输入插入元素："<<endl;
	cin>>x;
	sq.EnQueue(x);
	sq.output();
	sq.DeQueue(x);
	cout<<"删除一个元素，删除的元素为："<<x<<endl;
	sq.output();
	//------------------链式队列------------------------------
	LinkedQueue<int> q; 
	cin>>q;
	cout<<q;
	cout<<"插入一个元素，输入元素："<<endl;
	cin>>x; 
	q.EnQueue(x);
	cout<<q;
	q.DeQueue(x);
	cout<<"删除的元素为："<<x<<endl;
	cout<<q;
	//----------------循环队列---------------------
	CireQueue<int> cq(50);
	cq.input();
	cout<<cq;
	//--------------优先级队列--------------------------
	PQueue pq(50);
	cin>>pq;
	cout<<pq;
	//----------------队列的应用--------------------------
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
	cout<<"路径长度为： "<<PathLen<<endl;
	cout<<"( "<<start.row<<" , "<<start.col<<" )"<<endl;
	for(int k=1;k<PathLen;k++){
		cout<<"( "<<path[k].row<<" , "<<path[k].col<<" )"<<endl;
	}
	return 0;
}

