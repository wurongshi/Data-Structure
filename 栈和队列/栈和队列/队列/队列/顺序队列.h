template<class T>
class Queue{
	public:
		Queue(){}
		~Queue(){}
		virtual bool EnQueue(const T&x)=0;
		virtual bool DeQueue(T &x)=0;
		virtual bool getFront(T &x)=0;
		virtual bool IsEmpty()const=0;
		virtual bool IsFull()const=0;
		virtual int getSize()const=0;
}; 
template<class T>
class SeqQueue:public Queue<T>{
	public:
		SeqQueue();
		~SeqQueue(){}
	    bool EnQueue(const T &x);
	    bool DeQueue(T &x);
	    bool getFront(T &x);
	    bool IsEmpty()const;
	    bool IsFull()const;
	    int getSize()const;
	    void input();
	    void output();
	private:
		T *elements;
		int front,rear;
};
template<class T>
SeqQueue<T>::SeqQueue(){
	elements=new T[maxSize];
	front=rear=0;
}
template<class T>
bool SeqQueue<T>::EnQueue(const T &x){
	if(rear>=maxSize-1) return false;
	elements[rear++]=x;
	return true;
}
template<class T>
bool SeqQueue<T>::DeQueue(T &x){
	if(IsEmpty()) return false;
	x=elements[front++];
	return true;
}
template<class T>
bool SeqQueue<T>::getFront(T &x){
	if(IsEmpty()) return false;
	x=elements[front];
	return true;
}
template<class T>
bool SeqQueue<T>::IsEmpty()const{
	if(front==rear) return true;
	return false;
}
template<class T>
bool SeqQueue<T>::IsFull()const{
	if(rear>=maxSize-1) return true;
	return false;
}
template<class T>
int SeqQueue<T>::getSize()const{
	return rear-front;
}
template<class T>
void SeqQueue<T>::input(){
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
void SeqQueue<T>::output(){
	cout<<"输出队列中元素"<<endl;
	cout<<"队列长度为："<<getSize()<<endl; 
	int p=front,i=1;
	while(p!=rear){
		cout<<"#"<<i++<<"："<<elements[p]<<endl;
		p++;
	}
}