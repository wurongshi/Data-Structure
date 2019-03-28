template <class T>
class LinearList{
	public:
		//LinearList(){}
		//~LinearList();
		virtual int Size()const=0;
		virtual int Length()const=0;
		virtual int Search(T &x)const=0;
		virtual int Locate(int i)const=0;
		virtual bool getData(int i,T &x)const=0;
		virtual void setData(int i,T &x)=0;
		virtual bool Insert(int i,T &x)=0;
		virtual bool Remove(int i,T &x)=0;
		virtual bool IsEmpty()=0;
		virtual bool IsFull()=0;
		virtual void Sort()=0;
		virtual void input()=0;
		virtual void output()=0;
		//virtual LinearList operator=(LinearList &L)=0;
				
};
template <class T>
class SeqList:public LinearList<T> {
	protected:
		T *data;
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
		int Search(T &x)const;//
		int Locate(int i)const;//
		bool getData(int i,T &x)const{
		    if(i>0&&i<=last+1){
		    	x=data[i-1];
				return true;
			}
			else return false;
		}
		void setData(int i,T &x){
			if(i>0&&i<=last+1){
				data[i-1]=x;
			}
		}
		bool Insert(int i,T &x);
		bool Remove(int i,T &x);
		void Sort();
		bool IsEmpty(){
			return (last==-1)?true:false;
		}
		bool IsFull(){
			return (maxSize-1==last)?true:false;
		}
		void input();
		void output();
	    SeqList operator=(SeqList<T> &L);
			
};
template <class T>
SeqList<T>::SeqList(int sz){
	if(sz>0){
		maxSize=sz; last=-1;
		data=new T[maxSize];
		if(data==NULL){ cout<<"存储分配错误！"<<endl;}
	}
}
template <class T>
SeqList<T>::SeqList(SeqList &L){
	maxSize=L.Size(); last=L.Length()-1;  int value;
	data =new int[maxSize];
	if(data==NULL){ cout<<"存储分配错误！"<<endl;}
	for(int i=1;i<=last+1;i++){
		L.getData(i,value); data[i-1]=value;
	}
}
template <class T>
void SeqList<T>::reSize(int newSize){
	if(newSize<=0){
		cout<<"无效的数组大小！"<<endl; return; 
	}
	if(newSize!=maxSize){
		T *newarray=new T[newSize];
		if(newarray==NULL){ cout<<"存储分配错误！"<<endl; }
		int n=last+1;  T *srcptr=data,*destptr=newarray; 
		while(n--)  *destptr++= *srcptr++;
		delete []data; data=newarray; maxSize=newSize;				
	}
}
template <class T>
int SeqList<T>::Search(T &x)const{
	for(int i=0;i<=last;i++)
		if(data[i]==x) return i;
	return -1;
}
template <class T>
int SeqList<T>::Locate(int i)const{
	if(i>=1&&i<=last+1) return i;
	else return 0;
}
template <class T>
bool SeqList<T>::Insert(int i,T &x){
	if(last==maxSize-1) return false;
	if(i<0||i>last+1) return false;
	for(int j=last;j>=i;j--){
		data[j+1]=data[j];
	}
	data[i]=x; last++; N++;
	return true;
}
template <class T>
bool SeqList<T>::Remove(int i,T &x){
	if(last==-1) return false;
	if(i<0||i>last) return false;
	x=data[i];
	for(int j=i;j<last;j++){
		data[j]=data[j+1];
	}
	last--; N--;
	return true;
}
template <class T>
void SeqList<T>::Sort(){
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
template <class T>
void SeqList<T>::input(){
	cout<<"开始建立顺序表，请输入表中元素个数：";
	while(1){
		cin>>N; last=N-1;
		if(N<=maxSize) break;
	    cout<<"表元素个数输入有误，范围不能超过"<<maxSize<<endl;
	}
	for(int i=0;i<=last;i++){
		cin>>data[i];
	} 
}
template <class T>
void SeqList<T>::output(){
	cout<<"顺序表当前元素的最后位置为："<<last<<endl;
	for(int j=0;j<=last;j++){
		cout<<"#"<<j<<": "<<data[j]<<endl;
	}
}
template <class T>
SeqList<T> SeqList<T>::operator=(SeqList <T> &L){
    SeqList<T> s(20);
    s.last=L.last; 
    for(int i=0;i<=L.last;i++){
    	s.data[i]=L.data[i];
	}
	return s;
}