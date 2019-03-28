template<class T>
class LinkedDeque:public LinkedQueue<T>,public Deque<T>{
	LinkedDeque();
	bool getHead(T &x)const;
	bool getTail(T &x)const;
	bool EnQueueHead(const T &x);
	bool EnQueueTail(const T &x);
	bool DeQueueHead(T &x);
	bool DeQueueTail(T &x);
};
template<class T>
LinkedDeque<T>::LinkedDeque():LinkedQueue<T>(){
	
}
template<class T>
bool LinkedDeque<T>::getHead(T &x)const{
	T temp;
	bool tag=LinkedQueue<T>::getFront(temp);
	x=temp; return tag;
}
template<class T>
bool LinkedDeque<T>::EnQueueTail(const T &x){
	return LinkedQueue<T>::EnQueue(x);
}
template<class T>
bool LinkedDeque<T>::DeQueueHead(T &x){
	T temp;
	bool tag=LinkedQueue<T>::DeQueue(temp);
	x=temp; return tag;
}
template<class T>
bool LinkedDeque<T>::getTail(T &x)const{
	if(LinkedQueue<T>::front==NULL) return false;
	x=LinkedQueue<T>::rear->data;
	return true;
}
template<class T>
bool LinkedDeque<T>::EnQueueHead(const T &x){
	LinkNode<T> *p=new LinkNode<T>(x);
	if(p==NULL) return false;
	p->link=LinkedQueue<T>::front;
	LinkedQueue<T>::front=p;
	return true;
}
template<class T>
bool LinkedDeque<T>::DeQueueTail(T &x){
	if(LinkedQueue<T>::front==NULL) return false;
	LinkNode<T> *p=LinkedQueue<T>::front;
	while(p->link!=LinkedQueue<T>::rear){
		p=p->link;
	}
	p->link=NULL; delete LinkedQueue<T>::rear;
	LinkedQueue<T>::rear=p;
	return true;
}