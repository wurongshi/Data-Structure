// ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ջ.h"
#include "����.h"
#include "������.h"
#include "����ɭ�ּ������.h"
#include "����������.h"
#include "��.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//--------------������--------------------------
	BinaryTree<char> Btree('#');
	cout<<"����һ�ö�������"<<endl;
	cin>>Btree;
	cout<<"��ǰ�������������";
	cout<<Btree;
	cout<<endl<<"�Թ�������ʽ�����������"<<endl;
	PrintBTree(Btree.getRoot());
	cout<<endl<<"ǰ������ݹ飡"<<endl;
	Btree.PreOrder(visit); cout<<endl;
	cout<<endl<<"��������ݹ飡"<<endl;
	Btree.InOrder(visit);  cout<<endl;
	cout<<endl<<"��������ݹ飡"<<endl;
	Btree.PostOrder(visit);  cout<<endl;
	cout<<endl<<"ǰ������ǵݹ飡"<<endl; 
	Btree.preOrder1(visit); 
	cout<<endl<<"ǰ������ǵݹ飡"<<endl;
	Btree.preOrder2(visit);
	cout<<endl<<"��������ǵݹ飡"<<endl;
	Btree.inOrder(visit);
	cout<<endl<<"��������ǵݹ飡"<<endl;
	Btree.postOrder(visit);
	cout<<"��α�����"<<endl; 
	Btree.LevelOrder(visit); 
	cout<<endl;
	//--------------����ɭ�ּ������-------------------------
	Tree<char> tree,tree1;
	cout<<"�ö�������������"<<endl;
	cin>>tree;
	cout<<tree;
    cout<<endl<<"�ù����������"<<endl;
    tree1.create_tree();
    tree.show_tree(tree1.getRoot());
	//----------------����������--------------------- 
	ThreadTree<char> Thtree;
	cin>>Thtree;
	Thtree.createInThread();
	cout<<"ǰ�������"<<endl;
	Thtree.PreOrder(visit);
	cout<<endl<<"���������"<<endl;
	Thtree.InOrder(visit);
	cout<<endl<<"���������"<<endl;
	Thtree.PostOrder(visit);
	cout<<endl;
	//-------------------��--------------------
	int n,i,a[50],data;
	cout<<"�����齨���ѣ���������Ԫ�صĸ�����"<<endl;
	cin>>n; 
	cout<<"���� "<<n<<" ������Ԫ�أ�"<<endl; 
	for(i=0;i<n;i++) cin>>a[i];
	MinHeap<int> mheap(a,n);
	cout<<"�ѽ�����ϣ�"<<endl;
	cout<<"�������Ԫ��:"<<endl; 
	cout<<mheap;
	cout<<"����һ��Ԫ�أ��������Ԫ�أ�"<<endl;
	cin>>data;
	mheap.Insert(data);
	cout<<"������ϣ������������Ԫ�أ�"<<endl;
	cout<<mheap; 
	cout<<"ɾ��������СԪ�أ�"<<endl;
	mheap.RemoveMin(data);
	cout<<"ɾ����ϣ�ɾ������СԪ��Ϊ��"<<data<<endl;
	cout<<"���ɾ������е�Ԫ�أ�"<<endl;
	cout<<mheap; 
	return 0;
}

