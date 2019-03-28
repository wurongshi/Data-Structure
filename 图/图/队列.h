#include <iostream>
using namespace std;
const int maxSize=50;
template<class K>
class Queue{
	public:
		Queue(){}
		~Queue(){}
		virtual bool EnQueue(const K&x)=0;
		virtual bool DeQueue(K &x)=0;
		virtual bool getFront(K &x)=0;
		virtual bool IsEmpty()const=0;
		virtual bool IsFull()const=0;
		virtual int getSize()const=0;
}; 
template<class K>
class SeqQueue:public Queue<K>{
	public:
		SeqQueue();
		~SeqQueue(){}
	    bool EnQueue(const K &x);
	    bool DeQueue(K &x);
	    bool getFront(K &x);
	    bool IsEmpty()const;
	    bool IsFull()const;
	    int getSize()const;
	    void input();
	    void output();
	private:
		K *elements;
		int front,rear;
};
template<class K>
SeqQueue<K>::SeqQueue(){
	elements=new K[maxSize];
	front=rear=0;
}
template<class K>
bool SeqQueue<K>::EnQueue(const K &x){
	if(rear>=maxSize-1) return false;
	elements[rear++]=x;
	return true;
}
template<class K>
bool SeqQueue<K>::DeQueue(K &x){
	if(IsEmpty()) return false;
	x=elements[front++];
	return true;
}
template<class K>
bool SeqQueue<K>::getFront(K &x){
	if(IsEmpty()) return false;
	x=elements[front];
	return true;
}
template<class K>
bool SeqQueue<K>::IsEmpty()const{
	if(front==rear) return true;
	return false;
}
template<class K>
bool SeqQueue<K>::IsFull()const{
	if(rear>=maxSize-1) return true;
	return false;
}
template<class K>
int SeqQueue<K>::getSize()const{
	return rear-front;
}