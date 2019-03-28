template<class T>
class SeqQueue{
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