// ���Ա�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "˳���.h"
#include "������.h"
#include "ѭ��������.h"
#include "˫����.h"
#include "˫ѭ������.h"
#include "��̬����.h"
#include "����ʽ.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int v=-1,mis=-1; 
	int i,j,x,y;
	List<int> li(v);
    li.input();
    cout<<"����һ��Ԫ��,���������λ�ü�Ԫ�أ�";
	cin>>i>>x; 
    li.Insert(i,x);
    li.output();
    cout<<"ɾ��һ��Ԫ�أ���������ɾ��Ԫ�ص�λ�ã�";
    cin>>j; 
    li.Remove(j,y);
    cout<<"��ɾ����Ԫ��Ϊ��"<<y<<endl;
	li.output(); 
	//cout<<"�Ա���Ԫ�ؽ�������" <<endl;
	//sq.Sort();	
	cout<<"������������ظ���ԭ��"<<endl; 
	cout<<"�±��е�Ԫ��Ϊ��"<<endl;	
	List <int> sli=li;
	sli.output();	
	cout<< "��ǰ�巨���������� :"<<endl;
	li.inputFront(mis);
	li.output();
	cout<< "�ú�巨���������� :"<<endl;
	li.inputRear(mis);
	li.output();
	//---------------------------------
    SeqList <int> sq(20);
    sq.input();
    cout<<"����һ��Ԫ��,���������λ�ü�Ԫ�أ�";
	cin>>i>>x; 
    sq.Insert(i,x);
    sq.output();
    cout<<"ɾ��һ��Ԫ�أ���������ɾ��Ԫ�ص�λ�ã�";
    cin>>j; 
    sq.Remove(j,y);
    cout<<"��ɾ����Ԫ��Ϊ��"<<y<<endl;
	sq.output(); 
	cout<<"�Ա���Ԫ�ؽ�������" <<endl;
	sq.Sort();	
	cout<<"������������ظ���ԭ��"<<endl; 
	cout<<"�±��е�Ԫ��Ϊ��"<<endl;	
	SeqList <int>sl=sq;
	sl.output();
	//-------------------------------------------
	int N;
	cout<<"����һ����ѭ������,�����뵥����ĳ��ȣ�"<<endl;
	cin>>N; 
	CireList <int> cirel (N);
	cirel.input();
	cirel.output();
	cout<<"����һ��Ԫ�أ��������Ԫ�ص�λ�ü�ֵ��"<<endl;
	cin>>i>>x;
	cirel.Insert(i,x);
	cirel.output();
	cout<<"ɾ��һ��Ԫ�أ�����ɾ����λ�ã�";
	cin>>j; 
	cirel.Remove(j,y);
	cout<<"��ɾ����Ԫ��Ϊ��#"<<j<<": "<<y<<endl;
	cirel.output();
	cout<<endl<<endl<<endl<<"�õ�ѭ��������Լɪ�����⣺"<<endl; 
	int n,m;
	cout<<"����һ��Լɪ��,����μ�������"<<endl; 
	cin>>n;
	CireList<int> js(n);
	js.input();
	cout<<"Լɪ�򻷴����ɹ������뱨��ֵ��"; //�� 1 ��ʼ 
	cin>>m;
	cout<<endl<<"�����"<<endl;
	Josephus(js,n,m);
	//-------------------------------------------------------------
	cout<<"�½�һ��˫��������˫����ĳ��ȣ�";
	cin>>n;
	DbList<int> db(n);
	db.input();
	int d,value;
	cout<<endl<<"����һ��Ԫ�أ��������λ�á�ֵ������"; 
	cin>>i>>value>>d;
	db.Insert(i,value,d);
	db.output();
	cout<<"ɾ��һ��Ԫ�أ�����ɾ��λ�ü�����";
	cin>>i>>d;
	db.Remove(i,x,d);
	cout<<"ɾ����Ԫ��Ϊ��"<<x<<endl;
	db.output(); 
	//------------------------------------------------
	cout<<"�½�һ��˫ѭ����������˫����ĳ��ȣ�";
	cin>>n;
	DbCireList<int> dbl(n);
	dbl.input();
	cout<<endl<<"����һ��Ԫ�أ��������λ�á�ֵ������"; 
	cin>>i>>value>>d;
	dbl.Insert(i,value,d);
	dbl.output();
	cout<<"ɾ��һ��Ԫ�أ�����ɾ��λ�ü�����";
	cin>>i>>d;
	dbl.Remove(i,x,d);
	cout<<"ɾ����Ԫ��Ϊ��"<<x<<endl;
	dbl.output();
	//---------------------------------------------------
	StaticList<int> stl;
	stl.input();
	stl.output();
	cout<<"��β���¼�һ����㣬�����¼�Ԫ�أ�" ;
	cin>>x; 
	stl.Append(x);
	stl.output();
	cout<<"����һ��Ԫ�أ��������λ�ü�ֵ��";
	cin>>i>>x;
	stl.Insert(i,x);
	stl.output();
	cout<<"ɾ��һ��Ԫ�أ�������ɾ��λ�ã�";
	cin>>i;
	stl.Remove(i);
	stl.output(); 
	//------------------------------------------------
	Polynomal p,p1,p2;
	cout<<"����P��"<<endl;
	cin>>p;
	cout<<"���P��"<<endl;
	cout<<p;
	cout<<"����P��Q��"<<endl;
	Polynomal q(p);
	cout<<"���Q��"<<endl;
	cout<<q;
    cout<<"����P1��"<<endl;
	cin>>p1;
	cout<<"����P2��"<<endl;
	cin>>p2;
	cout<<"���P1+P2��"<<endl;
	cout<<p1+p2<<endl; 
	cout<<"���P1*P2��"<<endl;
	cout<<p1*p2<<endl;
	return 0;
}

