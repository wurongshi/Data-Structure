template<class T>
struct CireLinkNode{
	T data;
	CireLinkNode<T> *link;
	CireLinkNode<T>(CireLinkNode<T> *next=NULL):link(next){}
	CireLinkNode<T>(T d, CireLinkNode<T> *next=NULL):data(d),link(next){}
};
template<class T>
class CireList{
	public:
		CireList( T &x){  first=new CireLinkNode<T>(x);  first->link=first;}
		CireList(CireList<T> &L);
		~CireList(){ }
		int Length();
		bool IsEmpty(){ return first->link==first?true:false; }
		CireLinkNode<T> *getHead(){ return first;}
		void setHead(CireLinkNode<T> *p);
		CireLinkNode<T> *Search(T &x);
		CireLinkNode<T> *Locate(int i);
		T *getData(int i);
		void setData(int i,T &x);
		bool Insert(int i,T &x);
		bool Remove(int i,T &x);
		void input();
		void output();
	private:
		CireLinkNode<T> *first,*last;		
};
template<class T>
CireList<T>::CireList(CireList<T> &L){
	T value;
	CireLinkNode<T> *srcptr=L.getHead();
	CireLinkNode<T> *destptr=first=new CireLinkNode<T>;
	while(srcptr->link!=L.getHead()){
		value=srcptr->link->data;
		destptr->link=new CireLinkNode<T>(value);
		destptr=destptr->link;
		srcptr=srcptr->link;
		}
	destptr->link=first;
}
template<class T>
int CireList<T>::Length(){
  int count=0;
  CireLinkNode<T> *current=first;
  while(current->link!=first){ count++; current=current->link; }
  return count;
}
template<class T>
void CireList<T>::setHead(CireLinkNode<T> *p){
	first->data=p->data;
}
template<class T>
CireLinkNode<T> *CireList <T>::Search(T &x){
	CireLinkNode <T> *current=first->link;
	while(current!=first){
		if(current->data==x) break;
		else current=current->link;
	}
	return current;
}
template<class T>
CireLinkNode<T> *CireList<T>::Locate(int i){
	int j=0;
	if(i<0) return NULL;
	CireLinkNode<T> *current=first->link;
	while(current!=first&&j<i){
		current=current->link;
		j++;
	}	
	return current;
}
template<class T>
T *CireList<T>::getData(int i){
	if(i<0) return NULL;
	CireLinkNode<T> *current=Locate(i);
	if(current==NULL) return NULL;
	return current->data;
}
template<class T>
void CireList<T>::setData(int i,T &x){
	if(i<0) return;
	CireLinkNode<T> *current=Locate(i);
	if(current==NULL) return;
	current->data=x;
}
template<class T>
bool CireList<T>::Insert(int i,T &x){
	if(i<0||i>Length()) return false;
	CireLinkNode<T> *newNode=new CireLinkNode<T> (x);
	if(newNode==NULL){ cout<<"存储分配错误！<<endl"; return false; }
	if(i==0){ newNode->link=first->link;  first->link=newNode;  return true;}
	CireLinkNode <T> *p=Locate(i-1); newNode->link= p->link; 
	p->link=newNode; return true;	
}
template<class T>
bool CireList<T>::Remove(int i,T &x){
	if(IsEmpty()) return false;
	if(i<0||i>=Length()) return false;
	if(i==0) {  
	CireLinkNode<T> *p=first->link; 
	first->link=p->link; x=p->data; 
	delete p;  return true;
	}
	CireLinkNode<T> *p=Locate(i-1); x=p->link->data;
	p->link=p->link->link;
	return true;
}
template<class T>
void CireList<T>::input(){
	T x;
	CireLinkNode<T> *p=first;
	for(int i=0;i<first->data;i++){
		cin>>x; CireLinkNode<T> *newNode=new CireLinkNode<T>(x);
		if(newNode==NULL){ cout<<"存储分配错误！"<<endl; return ; }
		newNode->link=p->link;
		p->link=newNode; p=p->link;
	}
}
template<class T>
void CireList<T>::output(){
	int i=0;
	if(IsEmpty())  return ;
	CireLinkNode<T> *p=first;
	while(p->link!=first){
		cout<<"#"<<i++<<": "<<p->link->data<<endl;
		p=p->link;
	}
}
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------- 
template<class T>
void Josephus(CireList<T> &Js,int n,int m){
	CireLinkNode<T> *p=Js.Locate(0),*pre=NULL;
	CireLinkNode<T> *q=Js.Locate(n-1),*s=Js.getHead();
	q->link=s->link; delete s;
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=1;j<m;j++){
			pre=p; p=p->link;
		}
		cout<<"出列的人员是："<<p->data<<endl;
		pre->link=p->link; delete p; p=pre->link;
	}
	cout<<"出列的人员是："<<p->data<<endl;
}