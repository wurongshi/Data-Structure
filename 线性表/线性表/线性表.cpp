// 线性表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "顺序表.h"
#include "单链表.h"
#include "循环单链表.h"
#include "双链表.h"
#include "双循环链表.h"
#include "静态链表.h"
#include "多项式.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int v=-1,mis=-1; 
	int i,j,x,y;
	List<int> li(v);
    li.input();
    cout<<"插入一个元素,请输入插入位置及元素：";
	cin>>i>>x; 
    li.Insert(i,x);
    li.output();
    cout<<"删除一个元素，请输入所删除元素的位置：";
    cin>>j; 
    li.Remove(j,y);
    cout<<"所删除的元素为："<<y<<endl;
	li.output(); 
	//cout<<"对表中元素进行排序：" <<endl;
	//sq.Sort();	
	cout<<"利用运算符重载复制原表："<<endl; 
	cout<<"新表中的元素为："<<endl;	
	List <int> sli=li;
	sli.output();	
	cout<< "用前插法建立单链表 :"<<endl;
	li.inputFront(mis);
	li.output();
	cout<< "用后插法建立单链表 :"<<endl;
	li.inputRear(mis);
	li.output();
	//---------------------------------
    SeqList <int> sq(20);
    sq.input();
    cout<<"插入一个元素,请输入插入位置及元素：";
	cin>>i>>x; 
    sq.Insert(i,x);
    sq.output();
    cout<<"删除一个元素，请输入所删除元素的位置：";
    cin>>j; 
    sq.Remove(j,y);
    cout<<"所删除的元素为："<<y<<endl;
	sq.output(); 
	cout<<"对表中元素进行排序：" <<endl;
	sq.Sort();	
	cout<<"利用运算符重载复制原表："<<endl; 
	cout<<"新表中的元素为："<<endl;	
	SeqList <int>sl=sq;
	sl.output();
	//-------------------------------------------
	int N;
	cout<<"创建一个单循环链表,请输入单链表的长度："<<endl;
	cin>>N; 
	CireList <int> cirel (N);
	cirel.input();
	cirel.output();
	cout<<"插入一个元素，输入插入元素的位置及值："<<endl;
	cin>>i>>x;
	cirel.Insert(i,x);
	cirel.output();
	cout<<"删除一个元素，输入删除的位置：";
	cin>>j; 
	cirel.Remove(j,y);
	cout<<"所删除的元素为：#"<<j<<": "<<y<<endl;
	cirel.output();
	cout<<endl<<endl<<endl<<"用单循环链表解决约瑟夫环问题："<<endl; 
	int n,m;
	cout<<"创建一个约瑟夫环,输入参加人数："<<endl; 
	cin>>n;
	CireList<int> js(n);
	js.input();
	cout<<"约瑟夫环创建成功，输入报数值："; //从 1 开始 
	cin>>m;
	cout<<endl<<"结果："<<endl;
	Josephus(js,n,m);
	//-------------------------------------------------------------
	cout<<"新建一个双链表，输入双链表的长度：";
	cin>>n;
	DbList<int> db(n);
	db.input();
	int d,value;
	cout<<endl<<"插入一个元素，输入插入位置、值及方向："; 
	cin>>i>>value>>d;
	db.Insert(i,value,d);
	db.output();
	cout<<"删除一个元素，输入删除位置及方向：";
	cin>>i>>d;
	db.Remove(i,x,d);
	cout<<"删除的元素为："<<x<<endl;
	db.output(); 
	//------------------------------------------------
	cout<<"新建一个双循环链表，输入双链表的长度：";
	cin>>n;
	DbCireList<int> dbl(n);
	dbl.input();
	cout<<endl<<"插入一个元素，输入插入位置、值及方向："; 
	cin>>i>>value>>d;
	dbl.Insert(i,value,d);
	dbl.output();
	cout<<"删除一个元素，输入删除位置及方向：";
	cin>>i>>d;
	dbl.Remove(i,x,d);
	cout<<"删除的元素为："<<x<<endl;
	dbl.output();
	//---------------------------------------------------
	StaticList<int> stl;
	stl.input();
	stl.output();
	cout<<"在尾部新加一个结点，输入新加元素：" ;
	cin>>x; 
	stl.Append(x);
	stl.output();
	cout<<"插入一个元素，输入插入位置及值：";
	cin>>i>>x;
	stl.Insert(i,x);
	stl.output();
	cout<<"删除一个元素，请输入删除位置：";
	cin>>i;
	stl.Remove(i);
	stl.output(); 
	//------------------------------------------------
	Polynomal p,p1,p2;
	cout<<"输入P："<<endl;
	cin>>p;
	cout<<"输出P："<<endl;
	cout<<p;
	cout<<"复制P到Q："<<endl;
	Polynomal q(p);
	cout<<"输出Q："<<endl;
	cout<<q;
    cout<<"输入P1："<<endl;
	cin>>p1;
	cout<<"输入P2："<<endl;
	cin>>p2;
	cout<<"输出P1+P2："<<endl;
	cout<<p1+p2<<endl; 
	cout<<"输出P1*P2："<<endl;
	cout<<p1*p2<<endl;
	return 0;
}

