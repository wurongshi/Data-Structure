// 树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "栈.h"
#include "队列.h"
#include "二叉树.h"
#include "树与森林及其遍历.h"
#include "线索二叉树.h"
#include "堆.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//--------------二叉树--------------------------
	BinaryTree<char> Btree('#');
	cout<<"建立一棵二叉树！"<<endl;
	cin>>Btree;
	cout<<"按前序输出二叉树！";
	cout<<Btree;
	cout<<endl<<"以广义表的形式输出二叉树！"<<endl;
	PrintBTree(Btree.getRoot());
	cout<<endl<<"前序遍历递归！"<<endl;
	Btree.PreOrder(visit); cout<<endl;
	cout<<endl<<"中序遍历递归！"<<endl;
	Btree.InOrder(visit);  cout<<endl;
	cout<<endl<<"后序遍历递归！"<<endl;
	Btree.PostOrder(visit);  cout<<endl;
	cout<<endl<<"前序遍历非递归！"<<endl; 
	Btree.preOrder1(visit); 
	cout<<endl<<"前序遍历非递归！"<<endl;
	Btree.preOrder2(visit);
	cout<<endl<<"中序遍历非递归！"<<endl;
	Btree.inOrder(visit);
	cout<<endl<<"后序遍历非递归！"<<endl;
	Btree.postOrder(visit);
	cout<<"层次遍历！"<<endl; 
	Btree.LevelOrder(visit); 
	cout<<endl;
	//--------------树与森林及其遍历-------------------------
	Tree<char> tree,tree1;
	cout<<"用二叉树构造树："<<endl;
	cin>>tree;
	cout<<tree;
    cout<<endl<<"用广义表构造树："<<endl;
    tree1.create_tree();
    tree.show_tree(tree1.getRoot());
	//----------------线索二叉树--------------------- 
	ThreadTree<char> Thtree;
	cin>>Thtree;
	Thtree.createInThread();
	cout<<"前序遍历！"<<endl;
	Thtree.PreOrder(visit);
	cout<<endl<<"中序遍历！"<<endl;
	Thtree.InOrder(visit);
	cout<<endl<<"后序遍历！"<<endl;
	Thtree.PostOrder(visit);
	cout<<endl;
	//-------------------堆--------------------
	int n,i,a[50],data;
	cout<<"用数组建立堆，输入数组元素的个数："<<endl;
	cin>>n; 
	cout<<"输入 "<<n<<" 个数组元素："<<endl; 
	for(i=0;i<n;i++) cin>>a[i];
	MinHeap<int> mheap(a,n);
	cout<<"堆建立完毕！"<<endl;
	cout<<"输出堆中元素:"<<endl; 
	cout<<mheap;
	cout<<"插入一个元素，输入插入元素："<<endl;
	cin>>data;
	mheap.Insert(data);
	cout<<"插入完毕，输入插入后堆中元素："<<endl;
	cout<<mheap; 
	cout<<"删除堆中最小元素："<<endl;
	mheap.RemoveMin(data);
	cout<<"删除完毕，删除的最小元素为："<<data<<endl;
	cout<<"输出删除后堆中的元素："<<endl;
	cout<<mheap; 
	return 0;
}

