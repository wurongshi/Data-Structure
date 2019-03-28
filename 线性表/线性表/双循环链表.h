template <class T>
struct DbCireNode{
	T data;
	DbCireNode<T> *llink,*rlink;
	DbCireNode<T>(DbCireNode<T> *left=NULL,DbCireNode<T> *right=NULL){ llink=left; rlink=right; }
	DbCireNode<T>(T value,DbCireNode<T> *left=NULL,DbCireNode<T> *right=NULL):data(value),llink(left),rlink(right){ }
};
template<class T>
class DbCireList{
	public:
	    DbCireList(T uniqueVal);
	    ~DbCireList(){}
	    int Length();
	    bool IsEmpty(){ return first->rlink==first; }
	    DbCireNode<T> *getHead(){ return first; }
	    void setHead(DbCireNode<T> *ptr){ first=ptr; }
	    DbCireNode<T> *Search(T &x);
	    DbCireNode<T> *Locate(int i,int d);
	    bool Insert(int i,T &x,int d);
	    bool Remove(int i,T &x,int d);
	    void input();
	    void output();
	private:
		DbCireNode<T> *first;		
};
template<class T>
DbCireList<T>::DbCireList(T uniqueVal){
	first=new DbCireNode<T>(uniqueVal);
	first->rlink=first; first->llink=first;
}
template<class T> 
int DbCireList<T>::Length(){
	int count=0;
	DbCireNode<T> *p=first;
	while(p->rlink!=first){
		count++;
		p=p->rlink;
	}
	return count;
}
template<class T>
DbCireNode<T> *DbCireList<T>::Search(T &x){
	DbCireNode<T> *current=first;
	if(current==NULL) return NULL;
	while(current->rlink!=first){
		if(current->rlink->data==x) break;
		current=current->rlink;
	}
	return current->rlink;
}
template<class T>
DbCireNode<T> *DbCireList<T>::Locate(int i,int d){
	if(i<0||i>Length()) return NULL;
	DbCireNode<T> *current=first;
	if(d==0){
		current=first->llink;
		for(int j=0;j<i;j++){ current=current->llink; }
		return current;
	}
	else{
		current=first->rlink;
		for(int j=0;j<i;j++) current=current->rlink;
		return current;		
	}
}
template<class T>
bool DbCireList<T>::Insert(int i,T &x,int d){
	if(i<0||i>Length()) return false;
	DbCireNode<T> *newNode=new DbCireNode<T>(x);
	if(newNode==NULL){ cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl; return false; } 
	if(d==0){
		if(i==0){
			DbCireNode<T> *p=first;
			 newNode->llink=p->llink;
			 p->llink->rlink=newNode;
			 newNode->rlink=p;
			 p->llink=newNode;
			return true;
		}
		else{
			DbCireNode<T> *q=Locate(i-1,0);
			newNode->llink=q->llink;  q->llink->rlink=newNode;
			newNode->rlink=q;  q->llink=newNode;
			return true;
		}
	}
	else{
		if(i==0){
			newNode->rlink=first->rlink;  first->rlink->llink=newNode;
			first->rlink=newNode; newNode->llink=first;
			return true;
		}
		else{
			DbCireNode<T>*q=Locate(i-1,1);
			newNode->rlink=q->rlink; q->rlink->llink=newNode;
			q->rlink=newNode; newNode->llink=q;
			return true;
		}
	}
} 
template<class T>
bool DbCireList<T>::Remove(int i,T &x,int d){
	if(IsEmpty()) return false;
	if(i<0||i>=Length()) return false;
	DbCireNode<T> *current=Locate(i,d);
	DbCireNode<T> *p=current->llink;
	p->rlink=current->rlink;
	current->rlink->llink=p;
	x=current->data;
	delete current;
	return true;
}
template<class T>
void DbCireList<T>::input(){
	int i,value;
	DbCireNode<T> *p=first;
	for(i=0;i<first->data;i++){
		cin>>value;
		DbCireNode<T> *newNode=new DbCireNode<T>(value);
		newNode->llink=p;
		p->rlink=newNode;
		newNode->rlink=NULL;
		p=p->rlink;		
	}
	p->rlink=first; first->llink=p;	
}
template<class T>
void DbCireList<T>::output(){
	int i=0;
	if(IsEmpty()) return ;
	DbCireNode<T> *p=first;
	while(p->rlink!=first){
		cout<<"#"<<i++<<": "<<p->rlink->data<<endl;
		p=p->rlink;
	}
}