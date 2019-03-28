template <class T>
struct DbNode{
	T data;
	DbNode<T> *llink,*rlink;
	DbNode<T>(DbNode<T> *left=NULL,DbNode<T> *right=NULL){ llink=left; rlink=right; }
	DbNode<T>(T value,DbNode<T> *left=NULL,DbNode<T> *right=NULL):data(value),llink(left),rlink(right){ }
};
template<class T>
class DbList{
	public:
	    DbList(T uniqueVal);
	    ~DbList(){}
	    int Length();
	    bool IsEmpty(){ return first->rlink==NULL; }
	    DbNode<T> *getHead(){ return first; }
	    void setHead(DbNode<T> *ptr){ first=ptr; }
	    DbNode<T> *Search(T &x);
	    DbNode<T> *Locate(int i,int d);
	    bool Insert(int i,T &x,int d);
	    bool Remove(int i,T &x,int d);
	    void input();
	    void output();
	private:
		DbNode<T> *first;		
};
template<class T>
DbList<T>::DbList(T uniqueVal){
	first=new DbNode<T>(uniqueVal);
}
template<class T> 
int DbList<T>::Length(){
	int count=0;
	DbNode<T> *p=first;
	while(p->rlink!=NULL){
		count++;
		p=p->rlink;
	}
	return count;
}
template<class T>
DbNode<T> *DbList<T>::Search(T &x){
	DbNode<T> *current=first;
	if(current==NULL) return NULL;
	while(current!=NULL){
		if(current->data==x) break;
		current=current->rlink;
	}
	return current;
}
template<class T>
DbNode<T> *DbList<T>::Locate(int i,int d){
	if(i<0||i>Length()) return NULL;
	DbNode<T> *current=first,*p=first;
	while(p->rlink!=NULL) p=p->rlink;
	if(d==0){
		current=p;
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
bool DbList<T>::Insert(int i,T &x,int d){
	if(i<0||i>Length()) return false;
	DbNode<T> *newNode=new DbNode<T>(x);
	if(newNode==NULL){ cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl; return false; } 
	if(d==0){
		if(i==0){
			DbNode<T> *p=Locate(0,0);
			p->rlink=newNode; newNode->llink=p;
			return true;
		}
		else{
			DbNode<T> *q=Locate(i-1,0);
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
			DbNode<T>*q=Locate(i-1,1);
			newNode->rlink=q->rlink; q->rlink->llink=newNode;
			q->rlink=newNode; newNode->llink=q;
			return true;
		}
	}
} 
template<class T>
bool DbList<T>::Remove(int i,T &x,int d){
	if(IsEmpty()) return false;
	if(i<0||i>=Length()) return false;
	if(d==0){
		if(i==0){
		    DbNode <T>*p=Locate(0,0);
		    x=p->data;
		    delete p;
			return true;	
		}
		DbNode <T>*q=Locate(i-1,0),*s;
		s=q->llink; x=s->data; q->llink=s->llink;
		s->llink->rlink=q; return true;
	}
	else{
		if(i==0){
			DbNode<T> *p=first->rlink;
			x=p->data;
			first->rlink=p->rlink;
			p->rlink->llink=first;          
			delete p; return true;
		}
		if(i==Length()-1){
			DbNode<T> *p=Locate(0,0);
			x=p->data;
			p->llink->rlink=NULL;
			delete p; return true;
		}
		DbNode<T> *q=Locate(i-1,1),*s;
		s=q->rlink;  x=s->data;   q->rlink=s->rlink;
		s->rlink->llink=q;  delete s; 
		return true;		
	}
	
}
template<class T>
void DbList<T>::input(){
	int i,value;
	DbNode<T> *p=first,*current=NULL;
	for(i=0;i<first->data;i++){
		cin>>value;
		DbNode<T> *newNode=new DbNode<T>(value);
		newNode->llink=p;
		p->rlink=newNode;
		newNode->rlink=NULL;
		p=p->rlink;		
	}
	p->rlink=NULL;	
}
template<class T>
void DbList<T>::output(){
	int i=0;
	if(IsEmpty()) return ;
	DbNode<T> *p=first;
	while(p->rlink!=NULL){
		cout<<"#"<<i++<<": "<<p->rlink->data<<endl;
		p=p->rlink;
	}
}