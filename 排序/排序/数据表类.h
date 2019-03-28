template<class T>
class dataList{
public:
	dataList(int maxSz=DefaultSize):maxSize(maxSz),currentSize(0){
		Vector=new Element<T>[maxSize];
	}
	void Swap(Element<T> &x,Element<T> &y){
		Element<T> temp=x; x=y; y=temp;
	}
	int Length(){  return currentSize;  }
	Element<T> &operator[](int i){ return Vector[i]; }
	Element<T> &median3(const int left,const int right);
	int Partition(const int low,const int high);
	friend istream &operator >> <>(istream &in,dataList &L);
	friend ostream &operator << <>(ostream &out,dataList &L);
private:
	Element<T> *Vector;
	int maxSize;
	int currentSize;
};
template<class T>
istream &operator >>(istream &in,dataList<T> &L){
	T data; int i=0;
	in>>data;
	while(data!=-1){
		L.Vector[i++].key=data;
		L.currentSize++;
		in>>data;
	}
	return in;
}
template<class T>
ostream &operator <<(ostream &out,dataList<T> &L){
	int i;
	for(i=0;i<L.currentSize;i++){
		out<<L.Vector[i].key<<" ";
	}
	out<<endl;
	return out;
}
template<class T>
Element<T> &dataList<T>::median3(const int left,const int right){
	int mid=(left+right)/2;   int k=left;
	if(Vector[mid]<Vector[k]) k=mid;
	if(Vector[right]<Vector[k]) k=right;
	if(k!=left) Swap(Vector[k],Vector[left]);
	if(mid!=right&&Vector[mid]<Vector[right]) Swap(Vector[mid],Vector[right]);
	return Vector[right];
}
template<class T>
int dataList<T>::Partition(const int low,const int high){
	int pivotpos=low;  Element<T> pivot=Vector[low];
	for(int i=low+1;i<=high;i++)
		if(Vector[i]<pivot){
			pivotpos++;
			if(pivotpos!=i) Swap(Vector[pivotpos],Vector[i]);
		}
	Vector[low]=Vector[pivotpos];   Vector[pivotpos]=pivot;
	return pivotpos;
}