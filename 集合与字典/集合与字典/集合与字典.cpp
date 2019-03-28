// 集合与字典.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "位向量实现集合.h"
#include "有序链表实现集合.h"
#include "并查集与等价类.h"
#include "字典.h"
#include "跳表.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//-----------位向量实现集合--------------
	/*bitSet<unsigned short> b(3),b1(18),b2(18);
	cin>>b;
	cout<<b;
	b.addMember(1);
	cout<<b;
	cin>>b1;
	cout<<b1;
	cin>>b2;
	cout<<b1+b2<<endl;
	//------------有序链表实现集合--------------
	LinkedSet<int> set;
	cin>>set;
	cout<<set; 
	//------------并查集与等价类--------------
	UFSets uset(10);
	cin>>uset;
	cout<<uset;
	uset.Union(0,1);
	cout<<uset<<endl ;
	cout<<uset.CollapsingFind(9); 
	//-----------------字典---------------------
	SortedChain<int,int> sc; int e;
	cin>>sc;
	cout<<sc;
	sc.Insert(6,8);
	cout<<sc;
	sc.Remove(8,e);
	cout<<sc; 
	cout<<"删除的元素为 "<<e<<endl;*/
	//------------------跳表---------------------
	SkipList<int,int> s(100,5);
    cin>>s;
    cout<<s;
	return 0;
}

