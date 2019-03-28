
struct Priority{
	int num;
	int prio;
};
class PQueue{
	public:
		PQueue(int sz=DefaultPQSize);
		~PQueue(){ delete []pqelements; }
		bool Insert(Priority &x);
		bool RemoveMin(Priority &x);
		bool getFront(Priority &x)const;
		void makeEmpty(){ count=0; }
        bool IsEmpty()const{
        	return (count==0)?true:false;
		}
		bool IsFull()const{
		    return (count==maxSize)?true:false;
		}
		int getSize()const{ return count; }
		friend istream &operator>>(istream &is,PQueue &Q);
		friend ostream &operator<<(ostream &os,PQueue &Q); 
	protected:
		Priority *pqelements;
		int count;
		int maxSize;
		void adjust();
};
PQueue::PQueue(int sz):maxSize(sz),count(0){
	pqelements=new Priority[maxSize];
	assert(pqelements!=NULL);
}
bool PQueue::Insert(Priority &x){
	if(count==maxSize) return false;
	pqelements[count++]=x;
	adjust(); 
	return true;
}
void PQueue::adjust(){
	Priority temp=pqelements[count-1]; int j;
	for(j=count-2;j>=0;j--){
		if(pqelements[j].prio<=temp.prio) break;
		else pqelements[j+1]=pqelements[j];
	}
	pqelements[j+1]=temp;
}
bool PQueue::RemoveMin(Priority &x){
	if(IsEmpty()) return false;
	x=pqelements[0];
	for(int j=1;j<count;j++){
		pqelements[j-1]=pqelements[j];
	}
	count--;
	return true;
}
bool PQueue::getFront(Priority &x)const{
	if(IsEmpty()) return false;
	x=pqelements[0];
	return true;
}
istream &operator>>(istream &is,PQueue &Q){
	int n;
	cout<<"输入元素的个数："<<endl;
	is>>n;
	Priority p;
	cout<<"输入 "<<n<<" 个元素！"<<endl; 
	for(int i=0;i<n;i++){
		is>>p.num;
		is>>p.prio;
		Q.Insert(p);
	}
	return is;
}
ostream &operator<<(ostream &os,PQueue &Q){
	int i=0;
	os<<"输入优先队列中元素："<<endl;
	os<<"执行顺序  任务编号   优先权"<<endl; 
	for(int j=0;j<Q.count;j++){
		os<<++i<<" "<<Q.pqelements[j].num<<" "<<Q.pqelements[j].prio<<endl;
	} 
	return os;
}