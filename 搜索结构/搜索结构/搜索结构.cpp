// �����ṹ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "��̬�����ṹ.h"
#include "����������.h"
#include "AVL ��.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//------------��̬�����ṹ----------------
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
	//----------------����������---------------
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

