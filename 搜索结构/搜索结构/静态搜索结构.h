template<class E,class K>
class dataList;
template<class E,class K>
//-----------------------------------------
//----------数据表类----------------------- 
class dataNode{
	public:
		friend class dataList<E,K>;
		dataNode(const K x=0):key(x){}
		K getKey()const{ return key;  }
		void setKey(K k){ key=k; }
	private:
		K key;
};
//------------------------------------------------------------------
//-------------数据表类--------------------------------------------- 
template<class E,class K>
class dataList{
	public:
		dataList(int sz=defaultSize):ArraySize(sz),CurrentSize(0){
			Elements=new dataNode<E,K>[sz];
			assert(Elements!=NULL);
		}
		dataList(dataList<E,K> &R);
		virtual ~dataList(){  delete []Elements;  }
		virtual int Length(){  return CurrentSize; }
		virtual K getKey(int i)const{
			assert(i>0&&i<=CurrentSize);
			return Elements[i-1].key;
		} 
		virtual void setKey(K x,int i){
			assert(i>0&&i<=CurrentSize);
			Elements[i-1].key=x;
		}
		virtual int SeqSearch(const K x)const;
		virtual bool Insert(E &e1);
		virtual bool Remove(const K x,E &e1);
		friend ostream &operator << <>(ostream &out,const dataList<E,K> &OutList);
		friend istream &operator >> <>(istream &in,dataList<E,K> &InList);
	protected:
		dataNode<E,K> *Elements;
		int ArraySize,CurrentSize;
};

template<class E,class K> 
dataList<E,K>::dataList(dataList<E,K> &R){
	Elements=new dataNode<E,K>[R.ArraySize];
	assert(Elements!=NULL);
	CurrentSize=R.CurrentSize;
	for(int i=0;i<CurrentSize;i++){
		Elements[i].key=R.Elements[i].key;
	}
}
template<class E,class K>
bool dataList<E,K>::Insert(E &e1){
	if(CurrentSize==ArraySize) return false;
	Elements[CurrentSize]=e1;
	CurrentSize++;   return true;
}
template<class E,class K>
bool dataList<E,K>::Remove(const K x,E &e1){
	if(CurrentSize==0) return false;    int i;
	for(i=0;i<CurrentSize&&Elements[i].key!=x;i++);
	if(i==CurrentSize) return false;
	e1=Elements[i].getKey();
	Elements[i]=Elements[CurrentSize-1];
	CurrentSize--; return true;
}
template<class E,class K>
ostream &operator <<(ostream &out,const dataList<E,K> &OutList){
	out<<"Array Contents:\n";
	for(int i=1;i<=OutList.CurrentSize;i++){
		out<<OutList.Elements[i-1].getKey()<<' ';
	}
	out<<endl;
	out<<"Array CurrentSize: "<<OutList.CurrentSize<<endl;
	return out; 
}
template<class E,class K>
istream &operator >>(istream &in,dataList<E,K> &InList){
	K data;
	cout<<"Enter array CurrentSize: ";
	in>>InList.CurrentSize;
	cout<<"Enter array elements:"<<endl;
	for(int i=1;i<=InList.CurrentSize;i++){
		cout<<"Element"<<i<<": "; 
		in>>data;
		InList.Elements[i-1].setKey(data);
		cout<<endl;
	}
	return in;
} 
template<class E,class K>
int dataList<E,K>::SeqSearch(const K x)const{
	Elements[CurrentSize].key=x;   int i=0;
	while(Elements[i].getKey()!=x) i++;
	return i+1;
}  
//-------------------------------------------------------------------------
//------------------------------搜索类-------------------------------------
template<class E,class K>
class searchList:public dataList<E,K>{
	public:
		searchList(dataList<E,K> &s):dataList<E,K>(s){ }
		searchList(int sz=defaultSize):dataList<E,K>(sz){ }
		virtual int SeqSearch(const K x)const;
	private:
	    int SeqSearch1(const K x,int loc)const;
}; 
template<class E,class K> 
int searchList<E,K>::SeqSearch(const K x)const{
	int loc=1;
	int Pos=SeqSearch1(x,loc);
	return Pos;
}   
template<class E,class K> 	
int searchList<E,K>::SeqSearch1(const K x,int loc)const{
	if(loc>dataList<E,K>::CurrentSize) return 0; 
	else if(dataList<E,K>::Elements[loc-1].getKey()==x) return loc;
	else return SeqSearch1(x,loc+1); 
}
//-----------------------------------------------------------------------------
//----------------------------顺序表类----------------------------------------- 
template <class K>
class SeqList{
	protected:
		K *data;
		int maxSize;
		int N;
		int last;
		void reSize(int newSize);
	public:
		SeqList(int sz=defaultSize);
		SeqList(SeqList  &L);//
		~SeqList(){}
		int Size()const{return maxSize;}
		int Length()const{return last+1;}
		int Search(K &x)const;//
		int Locate(int i)const;//
		bool getData(int i,K &x)const{
		    if(i>0&&i<=last+1){
		    	x=data[i-1];
				return true;
			}
			else return false;
		}
		void setData(int i,K &x){
			if(i>0&&i<=last+1){
				data[i-1]=x;
			}
		}
		bool Insert(int i,K &x);
		bool Remove(int i,K &x);
		void Sort();
		bool IsEmpty(){
			return (last==-1)?true:false;
		}
		bool IsFull(){
			return (maxSize-1==last)?true:false;
		}
		void input();
		void output();
	    SeqList operator=(SeqList<K> &L);
			
};
template <class K>
SeqList<K>::SeqList(int sz){
	if(sz>0){
		maxSize=sz; last=-1;
		data=new K[maxSize];
		if(data==NULL){ cout<<"存储分配错误！"<<endl;}
	}
}
template <class K>
SeqList<K>::SeqList(SeqList &L){
	maxSize=L.Size(); last=L.Length()-1;  int value;
	data =new int[maxSize];
	if(data==NULL){ cout<<"存储分配错误！"<<endl;}
	for(int i=1;i<=last+1;i++){
		L.getData(i,value); data[i-1]=value;
	}
}
template <class K>
void SeqList<K>::reSize(int newSize){
	if(newSize<=0){
		cout<<"无效的数组大小！"<<endl; return; 
	}
	if(newSize!=maxSize){
		K *newarray=new K[newSize];
		if(newarray==NULL){ cout<<"存储分配错误！"<<endl; }
		int n=last+1;  K *srcptr=data,*destptr=newarray; 
		while(n--)  *destptr++= *srcptr++;
		delete []data; data=newarray; maxSize=newSize;				
	}
}
template <class K>
int SeqList<K>::Search(K &x)const{
	for(int i=0;i<=last;i++)
		if(data[i]==x) return i;
	return -1;
}
template <class K>
int SeqList<K>::Locate(int i)const{
	if(i>=1&&i<=last+1) return i;
	else return 0;
}
template <class K>
bool SeqList<K>::Insert(int i,K &x){
	if(last==maxSize-1) return false;
	if(i<0||i>last+1) return false;
	for(int j=last;j>=i;j--){
		data[j+1]=data[j];
	}
	data[i]=x; last++; N++;
	return true;
}
template <class K>
bool SeqList<K>::Remove(int i,K &x){
	if(last==-1) return false;
	if(i<0||i>last) return false;
	x=data[i];
	for(int j=i;j<last;j++){
		data[j]=data[j+1];
	}
	last--; N--;
	return true;
}
template <class K>
void SeqList<K>::Sort(){
	int k,l,temp;
	cout<<"从小到大排序："<<endl; 
	for(k=0;k<N-1;k++){
		for(l=k+1;l<N;l++){
			if(data[l]<data[k]){
				temp=data[l]; data[l]=data[k]; data[k]=temp;
			}
		}
	} 
	output();
	cout<<"从大到小排序："<<endl; 
	for(k=0;k<N-1;k++){
		for(l=k+1;l<N;l++){
			if(data[l]>data[k]){
				temp=data[l]; data[l]=data[k]; data[k]=temp;
			}
		}
	} 
	output();
}
template <class K>
SeqList<K> SeqList<K>::operator=(SeqList<K> &L){
    SeqList<K> s(20);
    s.last=L.last; 
    for(int i=0;i<=L.last;i++){
    	s.data[i]=L.data[i];
	}
	return s;
}
//-----------------------------------------------------------------------
//-----------------有序顺序表类------------------------------------------
template <class E,class K>
class SortedList:public searchList<E,K>{
	public:
		SortedList(dataList<E,K> &s):searchList<E,K>(s){}
        ~SortedList(){ }
        int SequentSearch(const K x)const;
        int BinarySearch(const K x)const;
        int BinarySearch(const K x,int low,int high);
//        bool Insert(const E &e1);
        int Begin(){  return (dataList<E,K>::CurrentSize==0)? 0:1;  }
		int Next(int i){  return (i>=1&&i<=dataList<E,K>::CurrentSize)? i+1:0;  } 
}; 
template<class E,class K>
int SortedList<E,K>::SequentSearch(const K x)const{
	for(int i=1;i<=dataList<E,K>::CurrentSize;i++){
		if(dataList<E,K>::Elements[i-1].getKey()==x) return i;
		else if(dataList<E,K>::Elements[i-1].getKey()>x) break;
	}
	return 0;
}
template<class E,class K>
int SortedList<E,K>::BinarySearch(const K x)const{
	int high=CurrentSize-1,low=0,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(x>Elements[mid].getKey()) low=mid+1;
		else if(x<Elements[mid].getKey()) high=mid-1;
		else return mid+1;
	}
	return 0;
}
template<class E,class K>
int SortedList<E,K>::BinarySearch(const K x,int low,int high){
	int mid=0;
	if(low<high){
		mid=(low+high)/2;
		if(x>Elements[mid-1].getKey())
		    mid=BinarySearch(x,mid+1,high);
		else if(x<Elements[mid-1].getKey())
		    mid=BinarySearch(x,low,mid-1);
	}
	return mid;
}