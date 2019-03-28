template <class T>
struct LinkNode {
	T data;
	LinkNode<T> *link; 
	LinkNode<T>(LinkNode<T> *ptr=NULL){link=ptr;}
	LinkNode<T>(const T &item,LinkNode<T> *ptr=NULL){link=ptr; data=item;}
}; 
template <class T>
class List{
	public:
		List(){  first=new LinkNode<T>;  }
		List(T &x){  first=new LinkNode<T>(x);  }
		List(List<T> &L);
		~List(){makeEmpty();}
		void makeEmpty();
		int Length()const;
		LinkNode<T> *getHead(){return first;}
		LinkNode<T> *Search(T &x);
		LinkNode<T> *Locate(int i);
		void inputFront(T endTag);  //用前插法建立单链表 
		void inputRear(T endTag);   //用后插法建立单链表
		bool getData(int i,T &x);
		bool setData(int i,T &x);
		bool Insert(int i,T &x);
		bool Remove(int i,T &x);
		bool IsEmpty(){ return first->link==NULL?true:false; }
		bool IsFull();
		void Sort();
		void input();
		void output();
		List<T> operator=(List<T> &L);
	protected:
		LinkNode<T> *first; 
		
};
template<class T>
List<T>::List(List<T> &L){
	T value;
	LinkNode<T> *srcptr=L.getHead();
	LinkNode<T> *destptr=first=new LinkNode<T>;
	while(srcptr->link!=NULL){
		value=srcptr->link->data;
		destptr->link=new LinkNode<T>(value);
		destptr=destptr->link;
		srcptr=srcptr->link;
	}
	destptr->link=NULL;
}
template<class T>
void List <T>::makeEmpty(){
	LinkNode<T> *q;
	while(first->link!=NULL){
		q=first->link;
		first->link=q->link;
		delete q;
	}
}
template<class T>
int List<T>::Length()const{
	int count=0;
	LinkNode<T> *p=first->link;
	while(p!=NULL){
		p=p->link; count++;
	}
	return count;
}
template<class T>
LinkNode<T>  *List<T>::Search(T &x){
	LinkNode <T> *current=first->link;
	while(current!=NULL){
		if(current->data==x) break;
		else current=current->link;
	}
	return current;
}
template<class T>
LinkNode<T> *List<T>:: Locate(int i){
	int j=0;
	LinkNode<T> *current=first->link;
	if(i<0) return NULL;
	while(current!=NULL&&j<i){ current=current->link; j++; }
	return current;
}
template<class T>
bool List<T>::getData(int i,T &x){
    if(i<0) return false;
    LinkNode<T> *current= Locate(i);
    if(current==NULL) return false;
    else { x=current->data; return true; }
    
}
template<class T>
bool List<T>:: setData(int i,T &x){
	if(i<0) return false;
	LinkNode<T> *current=Locate(i);
	if(current==NULL) return false;
	current->data=x; return true;
}
template<class T>
bool List<T>::Insert(int i,T &x){
	LinkNode<T> *current=Locate(i-1);
	if(current==NULL) return false;
	LinkNode<T> *newNode=new LinkNode<T>(x);
	if(newNode==NULL) cout<<"存储分配错误！"<<endl; 
	newNode->link=current->link;
	current->link=newNode;
	return true;
}
template<class T>
bool List<T>::Remove(int i,T &x){
	LinkNode<T> *current=Locate(i-1);
	if(current==NULL||current->link==NULL) return false;
	LinkNode<T> *del=current->link; x=del->data;
	current->link=del->link; delete del;
	return true;
	
}
template<class T>
bool List<T>::IsFull(){
	if(Length()>=defaultSize) return true;
	else return false;
}
//void Sort();
template<class T>
void List<T>::input(){
	int N; T x;
	cout<<"开始建立单链表，请输入表中元素个数：";
	while(1){
		cin>>N; 
		if(N<=defaultSize) break;
	    cout<<"表元素个数输入有误，范围不能超过"<<defaultSize<<endl;
	}
	LinkNode<T> *p=first;
	for(int i=0;i<N;i++){
		cin>>x;
		LinkNode<T> *newNode=new LinkNode<T>(x);
		if(newNode==NULL) { cout<<"存储分配错误！"<<endl; return; } 
		p->link=newNode; newNode->link=NULL; p=p->link;
	}
}
template<class T>
void List<T>::output(){
	int i=0;
	LinkNode<T> *current=first->link;
	while(current!=NULL){ cout<<'#'<<i++<<" : "<<current->data<<endl; current=current->link; } 
}
template<class T>
void List<T>::inputFront(T endTag){   //用前插法建立单链表 
	LinkNode<T>*newNode; T val;
	makeEmpty();
	cin>>val;
	while(val!=endTag){
		newNode=new LinkNode<T>(val);
		if(newNode==NULL) cout<<"存储分配错误！";
		newNode->link=first->link; first->link=newNode;
		cin>>val; 
	}
}
template<class T>
void List<T>::inputRear(T endTag){   // 用后插法建立单链表 
	LinkNode<T> *newNode,*last; T val;
	cin>>val; last=first; 
	while(val!=endTag){
		newNode=new LinkNode<T>(val);
		if(newNode==NULL) cout<<"存储分配错误！"<<endl;
		last->link=newNode; last=newNode;
		cin>>val; 
	}
	last->link=NULL;
} 
template<class T>
List<T> List<T>::operator=(List<T> &L){
	T value;
	LinkNode<T> *srcptr=L.getHead();
	LinkNode<T> *destptr=first=new LinkNode<T>;
	while(srcptr->link!=NULL){
		value=srcptr->link->data;
		destptr->link =new LinkNode<T>(value);
		srcptr=srcptr->link; destptr=destptr->link;
	}
	destptr->link=NULL;
	return *this;
}