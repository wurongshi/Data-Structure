// 排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "最大堆.h"
#include "数据元素类.h"
#include "静态链表类.h"
#include "数据表类.h"
#include "排序.h"
#include "胜利者树类.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/*int a[20]; int n;
	cout<<"输入元素的个数： ";
	cin>>n;
	cout<<"输入"<<n<<"个待排序元素："<<endl;
	for(int i=1;i<=n;i++) cin>>a[i];
	TournamentSort<int>(a,1,n);
	dataList<int> dl(50),dl2(50);
	cout<<"输入待排序的元素，以 -1 结尾："<<endl;
	cin>>dl;
	cout<<"两路归并排序！"<<endl;
	mergeSort(dl,dl2,0,dl.Length()-1);
	cout<<dl;
	cout<<"改进的两路归并排序！"<<endl;
	mergeSort2(dl,dl2,0,dl.Length()-1);
	cout<<dl;
	BubbleSort(dl,dl.Length());
	cout<<dl;
	BubbleSort_promote(dl,dl.Length());
	cout<<dl;
	SelectSort(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"快速排序！"<<endl;
	QuickSort(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"快速排序改进算法！"<<endl;
	QuickSort_Insert(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"快速排序改进算法2！"<<endl;
	QuickSort_Insert2(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"快速排序改进算法3！"<<endl;
	HybridSort2(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"三路划分快速排序！"<<endl;
	QuickSort3(dl,0,dl.Length()-1);
	cout<<dl;
	ShellSort(dl,0,dl.Length()-1);
	cout<<dl;
	BinaryInsertSort(dl,0,dl.Length()-1);
	cout<<dl;
	cout<<"直接插入排序！"<<endl;
	InsertSort(dl,0,dl.Length()-1);
	cout<<dl;
	MaxHeap<int> hp(30);
	cin>>hp;
	HeapSort(hp);*/
	staticLinkedList<int> sl(50);
	cin>>sl;
	cout<<"基于静态链表的归并排序！"<<endl;
	rMergeSort(sl,1,sl.Length());
	cout<<sl;
	ReArrange(sl);
	cout<<sl;
	ListInsertSort(sl);
	cout<<sl;
	return 0;
}

