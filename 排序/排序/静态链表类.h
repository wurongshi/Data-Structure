template<class T>
struct Elements{
	T key;
	int link;
	Elements():link(0){ }
	Elements(T x,int next=0):key(x),link(next){ }
};
template<class T>
class staticLinkedList{
public:
	staticLinkedList(int sz=DefaultSize):maxSize(sz),n(0){
			Vector=new Elements<T>[sz];
	}
	Elements<T> &operator[](int i){  return Vector[i];  }
	int Length(){ return n;  }
	friend istream &operator >> <>(istream &in,staticLinkedList<T> &L);
	friend ostream &operator << <>(ostream &out,staticLinkedList<T> &L);
private:
	Elements<T> *Vector;
	int maxSize,n;
};
template<class T>
istream &operator >> <>(istream &in,staticLinkedList<T> &L){
	T key; 
	in>>key;
	while(key!=-1){
		L[++L.n].key=key;
		in>>key;
	}
	return in;
}
template<class T>
ostream &operator << <>(ostream &out,staticLinkedList<T> &L){
	int i=L[0].link;
	while(i!=0){
		out<<L[i].key<<" ";
		i=L[i].link;
	}
	out<<endl;  
	return out;
}
