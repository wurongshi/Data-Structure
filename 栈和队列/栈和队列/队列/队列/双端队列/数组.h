template<class T>
class Deque{
	virtual bool getHead(T &x)const=0;
	virtual bool getTail(T &x)const=0;
	virtual bool EnQueue(const T &x);
	virtual bool EnQueueHead(const T &x)=0;
	virtual bool EnQueueTail(const T &x)=0;
	virtual bool DeQueue(T &x);
	virtual bool DeQueueHead(T &x)=0;
	virtual bool DeQueueTail(T &x)=0;
};
template<class T>
bool Deque<T>::EnQueue(const T &x){
	return EnQueueTail(x);
}
template<class T>
bool Deque<T>::DeQueue(T &x){
	T temp;
	bool tag=DeQueueHead(x);
    x=temp; return tag;
}
template<class T>
class SeqDeque:public Deque<T>,public SeqQueue<T>{
	public:
		SeqDeque(int sz);
		bool getHead(T &x)const;
		bool EnQueueTail(T &x);
		bool DeQueueHead(T &x);
		bool getTail(T &x)const;
		bool EnQueueHead(const T &x);
		bool DeQueueTail(T &x);
};
template<class T>
SeqDeque<T>::SeqDeque(int sz):SeqQueue<T>(sz){
	    
}
template<class T> 
bool SeqDeque<T>::getHead(T &x)const{
	T temp;
	bool tag=SeqQueue<T>::getFront(temp);
	x=temp; return tag;
}
template<class T>
bool SeqDeque<T>::EnQueueTail(T &x){
	return SeqQueue<T>::EnQueue(x);
}
template<class T>
bool SeqDeque<T>::DeQueueHead(T &x){
	T temp;
	bool tag=SeqQueue<T>::DeQueue(temp);
	x=temp; return tag;
} 
template<class T>
bool SeqDeque<T>::getTail(T &x)const{
	if(SeqQueue<T>::front=SeqQueue<T>::rear) return false;
	x=SeqQueue<T>::elements[SeqQueue<T>::rear-1];
	return true;
}