template<class T>
struct LinkQueueNode{
	T data;
	LinkQueueNode<T> *link;
	LinkQueueNode(LinkQueueNode<T> *ptr=NULL){ link=ptr; }
	LinkQueueNode(T &item,LinkQueueNode<T> *ptr=NULL){ data=item; link=ptr; }
};
template<class T>
class LinkedQueue{
	public:
		LinkedQueue():rear(NULL),front(NULL){}
		~LinkedQueue(){ makeEmpty(); }
		bool EnQueue(T &x);
		bool DeQueue(T &x);
		bool getFront(T &x)const;
		void makeEmpty();
		bool IsEmpty()const{ return (front==NULL)?true:false; }
		int getSize()const;
		void input();
		friend istream &operator>> <>(istream &in,LinkedQueue<T> &Q);
		friend ostream &operator<< <>(ostream &os,LinkedQueue<T> &Q);
	protected:
		LinkQueueNode<T> *front,*rear;
};
template<class T>
void LinkedQueue<T>::makeEmpty(){
	LinkQueueNode<T> *p;
	while(front!=NULL){
		p=front; front=front->link; delete p;
	}
}
template<class T>
bool LinkedQueue<T>::EnQueue(T &x){
	if(front==NULL){
		front=rear=new LinkQueueNode<T>(x);
		if(front==NULL){
			cout<<"存储分配失败！"<<endl;
			return false;
		}
	}
	else{
		rear->link=new LinkQueueNode<T>(x);
	    if(rear->link==NULL){
	    	cout<<"存储分配失败！"<<endl;
	    	return false;
		}
		rear=rear->link;
	}
	return true;
}
template<class T>
bool LinkedQueue<T>::DeQueue(T &x){
	if(IsEmpty()) return false;
	LinkQueueNode<T> *p=front;
	x=p->data;
	front=front->link;
	delete p;
	return true;
}
template<class T>
bool LinkedQueue<T>::getFront(T &x)const{
    if(IsEmpty()) return false;
    x=front->data; return true;
} 
template<class T>
int LinkedQueue<T>::getSize()const{
    LinkQueueNode<T> *p=front; int k=0;
    while(p!=NULL){
    	k++; p=p->link;
	}
	return k;
}
template<class T>
istream &operator>>(istream &in,LinkedQueue<T> &Q){
	int n,x;
	cout<<"输入元素个数：";
	in>>n; 
	cout<<"输入"<<n<<"个元素："<<endl; 
	for(int i=0;i<n;i++){
		in>>x;
		Q.EnQueue(x);
	}
	return in;
}
template<class T>
ostream &operator<<(ostream &out,LinkedQueue<T> &Q){
	out<<"队列中的元素有"<<Q.getSize()<<"个"<<endl;
	LinkQueueNode<T> *p=Q.front; int i=0;
	while(p!=NULL){
		out<<++i<<" : "<<p->data<<endl;
		p=p->link;
	} 
	return out;
}