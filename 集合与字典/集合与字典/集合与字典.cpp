// �������ֵ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "λ����ʵ�ּ���.h"
#include "��������ʵ�ּ���.h"
#include "���鼯��ȼ���.h"
#include "�ֵ�.h"
#include "����.h"

int _tmain(int argc, _TCHAR* argv[])
{
	//-----------λ����ʵ�ּ���--------------
	/*bitSet<unsigned short> b(3),b1(18),b2(18);
	cin>>b;
	cout<<b;
	b.addMember(1);
	cout<<b;
	cin>>b1;
	cout<<b1;
	cin>>b2;
	cout<<b1+b2<<endl;
	//------------��������ʵ�ּ���--------------
	LinkedSet<int> set;
	cin>>set;
	cout<<set; 
	//------------���鼯��ȼ���--------------
	UFSets uset(10);
	cin>>uset;
	cout<<uset;
	uset.Union(0,1);
	cout<<uset<<endl ;
	cout<<uset.CollapsingFind(9); 
	//-----------------�ֵ�---------------------
	SortedChain<int,int> sc; int e;
	cin>>sc;
	cout<<sc;
	sc.Insert(6,8);
	cout<<sc;
	sc.Remove(8,e);
	cout<<sc; 
	cout<<"ɾ����Ԫ��Ϊ "<<e<<endl;*/
	//------------------����---------------------
	SkipList<int,int> s(100,5);
    cin>>s;
    cout<<s;
	return 0;
}

