// 数组、串与广义表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "顺序表.h"
#include "矩阵的基本运算.h"
#include "字符串.h"
#include "广义表.h"

int _tmain(int argc, _TCHAR* argv[])
{
	AString s(30),s1(30);
	cout<<"输入目标字符串： "<<endl;
	cin>>s;
	cout<<"输入模式字符串： "<<endl;
	cin>>s1;
	s1.getNext();
	s.fastFind(s1,0);
	//----------------------
	SparseMatrix<int> sm(20),sm2,sm3(20);
	cin>>sm;
	cout<<sm;
	//sm.Transpose();
    //sm2=sm.Transpose();
	cin>>sm3;
	cout<<sm.Add(sm3)<<endl;
	return 0;
}

