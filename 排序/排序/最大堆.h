const int DefaultPQSize=50;
template<class T>
class MaxHeap{
	public:
		MaxHeap(int sz=DefaultSize);
		MaxHeap(T arr[],int n);
		~MaxHeap(){ delete []heap;  }
		bool Insert(const T &x);
		bool RemoveMin(T &x);
		bool IsEmpty()const{
			return (currentSize==0)? true:false;
		}
		bool IsFull()const{
			return (currentSize==maxHeapSize)? true:false;
		}
		void MakeEmpty(){ currentSize=0; }
		int Length(){ return currentSize;  }
		void Swap(int a,int b){ T temp=heap[a];  heap[a]=heap[b];  heap[b]=temp; }
		friend ostream &operator << <>(ostream &out,MaxHeap<T> &mh);
		friend istream &operator >> <>(istream &in,MaxHeap<T> &mh);
		void siftDown(int start,int m);
		void siftUp(int start);
	private:
		T *heap;
		int currentSize;
		int maxHeapSize;
		
}; 
template<class T>
MaxHeap<T>::MaxHeap(int sz){
	maxHeapSize=(DefaultSize<sz)? sz:DefaultSize;
	heap=new T[maxHeapSize];
	if(heap==NULL){
		cout<<"存储分配错误！"<<endl;
		exit(1);
	}
	currentSize=0;
}
template<class T>
MaxHeap<T>::MaxHeap(T arr[],int n){
	maxHeapSize=(DefaultSize<n)? n:DefaultSize;
	heap=new T[maxHeapSize];
	if(heap==NULL){
		cout<<"存储分配失败！"<<endl;
		exit(1);
	}
	for(int i=0;i<n;i++) heap[i]=arr[i];
	currentSize=n;
	int currentPos=(currentSize-2)/2;
	while(currentPos>=0){
		siftDown(currentPos,currentSize-1);
		currentPos--;
	}
}
template<class T>
void MaxHeap<T>::siftDown(int start,int m){
	int i=start,j=2*i+1;
	T temp=heap[i];
	while(j<=m){
		if(j<m&&heap[j]<heap[j+1]) j++;
		if(temp>=heap[j]) break;
		else{
			heap[i]=heap[j]; i=j; j=2*j+1;
		}
	}
	heap[i]=temp;
}
template<class T>
void MaxHeap<T>::siftUp(int start){
	int j=start,i=(j-1)/2; T temp=heap[j];
	while(j>0){
		if(heap[i]>=temp) break;
		else{
			heap[j]=heap[i];
			j=i; i=(i-1)/2;
		}
	}
	heap[j]=temp;
} 
template<class T>
bool MaxHeap<T>::Insert(const T &x){
	if(currentSize==maxHeapSize){
		cout<<"Heap Full!"<<endl; exit(1);
	}
	heap[currentSize]=x;
	siftUp(currentSize);
	currentSize++;
	return true;
}
template<class T>
bool MaxHeap<T>::RemoveMin(T &x){
	if(!currentSize){
		cout<<"Heap Empty!"<<endl;  return false;
	}
	x=heap[0]; heap[0]=heap[currentSize-1];
	currentSize--;
	siftDown(0,currentSize-1);
	return true;
}
template<class T>
istream &operator >>(istream &in,MaxHeap<T> &mh){
	T data; int n;
	cout<<"创建最大堆，输入元素的个数：";
	in>>n;
	cout<<"输入 "<<n<<" 个元素！"<<endl;
	for(int i=0;i<n;i++){ in>>data; mh.heap[i]=data;}
	mh.currentSize=n;
 	int currentPos=(mh.currentSize-2)/2;
	while(currentPos>=0){
		mh.siftDown(currentPos,mh.currentSize-1);
		currentPos--;
	}
	return in;
}
template<class T>
ostream &operator <<(ostream &out,MaxHeap<T> &mh){
	for(int i=0;i<mh.currentSize;i++){
		out<<mh.heap[i]<<' ';
	}
	cout<<endl;
	return out;
}