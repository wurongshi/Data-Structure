// 搜索结构.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "静态搜索结构.h"
#include "二叉搜索树.h"
#include "AVL 树.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//------------静态搜索结构----------------
	dataList<int,int> d;
	cin>>d;
	cout<<d;
	cout<<d.SeqSearch(5)<<endl;
	searchList<int,int> s(d);
	cout<<s.SeqSearch(5)<<endl;
	SortedList<int,int> sl(d);
	cout<<sl.SequentSearch(5)<<endl;
	cout<<sl.BinarySearch(5)<<endl;
	cout<<sl.BinarySearch(5,1,6);
	//----------------二叉搜索树---------------
	BST<int,int> b(-1),b1;
    b.PrintTree();
    cout<<endl;
    b.Remove(9);
    b.PrintTree();
	cout<<endl;
    b1=b;
    b1.PrintTree();  cout<<endl;
	return 0;
}

