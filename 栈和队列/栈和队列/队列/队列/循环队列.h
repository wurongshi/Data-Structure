template<class T>
class CireQueue:public Queue<T>{
	public:
		CireQueue(int sz=10);
		~CireQueue(){delete []elements; }
	    bool EnQueue(const T &x);
	    bool DeQueue(T &x);
	    bool getFront(T &x);
	    bool IsEmpty()const{ return front==rear?true:false; }
	    bool IsFull()const{ return (rear+1)%maxSize==front?true:false; }
	    int getSize()const;
	    void makeEmpty(){ front=rear=0; }
	    void input();
	    void output();
	    friend ostream &operator<< <>(ostream &os,CireQueue<T> &sq);
	private:
		T *elements;
		int front,rear;
		int maxSize;
};
template<class T>
CireQueue<T>::CireQueue(int sz):front(0),rear(0),maxSize(sz){
	elements=new T[maxSize];
	assert(elements!=NULL);
}
template<class T>
bool CireQueue<T>::EnQueue(const T &x){
	if(IsFull()) return false;
	elements[rear]=x;
	rear=(rear+1)%maxSize;
	return true;
}
template<class T>
bool CireQueue<T>::DeQueue(T &x){
	if(IsEmpty()) return false;
	x=elements[front];
	front=(front+1)%maxSize;
	return true;
}
template<class T>
bool CireQueue<T>::getFront(T &x){
	if(IsEmpty()) return false;
	x=elements[front];
	return true;
}
template<class T>
int CireQueue<T>::getSize()const{
	return (rear-front+maxSize)%maxSize;
}
template<class T>
void CireQueue<T>::input(){
	int n;  T x;
	cout<<"建立一个队列，输入队列元素的个数："<<endl;
	cin>>n;
	cout<<"输入"<<n<<"个队列元素:"<<endl;
	for(int i=1;i<=n;i++){
		cin>>x;
		EnQueue(x);
	} 
}
template<class T>
ostream &operator<<(ostream &out,CireQueue<T> &sq){
	out<<"输出队列中元素"<<endl;
	out<<"队列长度为："<<sq.getSize()<<endl; 
	for(int p=sq.front;p!=sq.rear;p=(p+1)%maxSize){
		out<<'#'<<p<<':'<<sq.elements[p]<<endl;
	}
	return out;
}