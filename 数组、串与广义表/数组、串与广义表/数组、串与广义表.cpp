// ���顢��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "˳���.h"
#include "����Ļ�������.h"
#include "�ַ���.h"
#include "�����.h"

int _tmain(int argc, _TCHAR* argv[])
{
	AString s(30),s1(30);
	cout<<"����Ŀ���ַ����� "<<endl;
	cin>>s;
	cout<<"����ģʽ�ַ����� "<<endl;
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

