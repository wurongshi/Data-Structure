// ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "����.h"
#include "����Ԫ����.h"
#include "��̬������.h"
#include "���ݱ���.h"
#include "����.h"
#include "ʤ��������.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*int a[20]; int n;
	cout<<"����Ԫ�صĸ����� ";
	cin>>n;
	cout<<"����"<<n<<"��������Ԫ�أ�"<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	TournamentSort<int>(a,1,n);
	dataList<int> dl(50),dl2(50);
	cout<<"����������Ԫ�أ��� -1 ��β��"<<endl;
	cin>>dl;
	cout<<"��·�鲢����"<<endl;
	mergeSort(dl,dl2,0,dl.Length()-1);
	cout<<dl;
	cout<<"�Ľ�����·�鲢����"<<endl;
	mergeSort2(dl,dl2,0,dl.Length()-1);
	cout<<dl;
	BubbleSort(dl,dl.Length());
	cout<<dl;
	BubbleSort_promote(dl,dl.Length());
	cout<<dl;
	SelectSort(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"��������"<<endl;
	QuickSort(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"��������Ľ��㷨��"<<endl;
	QuickSort_Insert(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"��������Ľ��㷨2��"<<endl;
	QuickSort_Insert2(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"��������Ľ��㷨3��"<<endl;
	HybridSort2(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"��·���ֿ�������"<<endl;
	QuickSort3(dl,0,dl.Length()-1);
	cout<<dl;
	ShellSort(dl,0,dl.Length()-1);
	cout<<dl;
	BinaryInsertSort(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"ֱ�Ӳ�������"<<endl;
	InsertSort(dl,0,dl.Length()-1);
	cout<<dl;
	MaxHeap<int> hp(30);
	cin>>hp;
	HeapSort(hp);*/
	staticLinkedList<int> sl(50);
	cin>>sl;
	cout<<"���ھ�̬����Ĺ鲢����"<<endl;
	rMergeSort(sl,1,sl.Length());
	cout<<sl;
	ReArrange(sl);
	cout<<sl;
	ListInsertSort(sl);
	cout<<sl;
	return 0;
}

