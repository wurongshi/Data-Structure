
const int DefaultPQSize=50;
#define DefaultSize 10
template<class K>
class MinHeap{
	public:
		MinHeap(int sz=DefaultSize);
		MinHeap(K arr[],int n);
		~MinHeap(){ delete []heap;  }
		bool Insert(const K &x);
		bool RemoveMin(K &x);
		bool IsEmpty()const{
			return (currentSize==0)? true:false;
		}
		bool IsFull()const{
			return (currentSize==maxHeapSize)? true:false;
		}
		void MakeEmpty(){ currentSize=0; }
		friend ostream &operator << <>(ostream &out,MinHeap<K> &mh);
	private:
		K *heap;
		int currentSize;
		int maxHeapSize;
		void siftDown(int start,int m);
		void siftUp(int start);
}; 
template<class K>
MinHeap<K>::MinHeap(int sz){
	maxHeapSize=(DefaultSize<sz)? sz:DefaultSize;
	heap=new K[maxHeapSize];
	if(heap==NULL){
		cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl;
		exit(1);
	}
	currentSize=0;
}
template<class K>
MinHeap<K>::MinHeap(K arr[],int n){
	maxHeapSize=(DefaultSize<n)? n:DefaultSize;
	heap=new K[maxHeapSize];
	if(heap==NULL){
		cout<<"´æ´¢·ÖÅäÊ§°Ü£¡"<<endl;
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
template<class K>
void MinHeap<K>::siftDown(int start,int m){
	int i=start,j=2*i+1;
	K temp=heap[i];
	while(j<=m){
		if(j<m&&heap[j]>heap[j+1]) j++;
		if(temp<=heap[j]) break;
		else{
			heap[i]=heap[j]; i=j; j=2*j+1;
		}
	}
	heap[i]=temp;
}
template<class K>
void MinHeap<K>::siftUp(int start){
	int j=start,i=(j-1)/2; K temp=heap[j];
	while(j>0){
		if(heap[i]<=temp) break;
		else{
			heap[j]=heap[i];
			j=i; i=(i-1)/2;
		}
	}
	heap[j]=temp;
} 
template<class K>
bool MinHeap<K>::Insert(const K &x){
	if(currentSize==maxHeapSize){
		cout<<"Heap Full!"<<endl; exit(1);
	}
	heap[currentSize]=x;
	siftUp(currentSize);
	currentSize++;
	return true;
}
template<class K>
bool MinHeap<K>::RemoveMin(K &x){
	if(!currentSize){
		cout<<"Heap Empty!"<<endl;  return false;
	}
	x=heap[0]; heap[0]=heap[currentSize-1];
	currentSize--;
	siftDown(0,currentSize-1);
	return true;
}
template<class K>
ostream &operator <<(ostream &out,MinHeap<K> &mh){
	for(int i=0;i<mh.currentSize;i++){
		out<<mh.heap[i]<<' ';
	}
	cout<<endl;
	return out;
}