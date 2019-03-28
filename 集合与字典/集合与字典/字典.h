template<class T,class E>
struct ChainNode{
	T data;
	ChainNode<T,E> *link;
	ChainNode():link(NULL){ }
	ChainNode(T &elem,ChainNode<T,E> *next=NULL):data(elem),link(next){ }
};
template<class T,class E>
class SortedChain;
template<class T,class E>
istream &operator >>(istream &in,SortedChain<T,E> &S);
template<class T,class E>
ostream &operator <<(ostream &out,SortedChain<T,E> &S);
template<class T,class E>
class SortedChain{
	public:
		SortedChain(){
			first=new ChainNode<T,E>;
			assert(first!=NULL);
		}
		~SortedChain(){ }
		ChainNode<T,E> *Search(const E e1)const;
		void Insert(const E e1,T t1);
		bool Remove(const E e1,T &t1);
		ChainNode<T,E> *Begin(){ return first->link;  }
		ChainNode<T,E> *Next(ChainNode<T,E> *current)const{
			if(current!=NULL) return current->link;
			else return NULL;
		}
		friend istream &operator >> <>(istream &in,SortedChain<T,E> &S);
		friend ostream &operator << <>(ostream &out,SortedChain<T,E> &S);
	private:
		ChainNode<T,E> *first;
};
template<class T,class E>
ChainNode<T,E> *SortedChain<T,E>::Search(const E e1)const{
	ChainNode<T,E> *p=first->link;
	while(p!=NULL&&p->data<e1) p=p->link;
	if(p!=NULL&&p->data==e1) return p;
	else return NULL;
}
template<class T,class E>
void SortedChain<T,E>::Insert(const E e1,T t1){
	ChainNode<T,E> *p=first->link,*pre=first,*newNode;
	while(p!=NULL&&p->data<e1){
		pre=p; p=p->link;
	}
	if(p!=NULL&&p->data==e1){  p->data=t1; return; }
	newNode=new ChainNode<T,E>(t1);
	if(newNode==NULL){
		cout<<"存储分配失败！"<<endl; exit(1);
	}
	newNode->link=p; pre->link=newNode;
}
template<class T,class E>
bool SortedChain<T,E>::Remove(const E e1,T &t1){
	ChainNode<T,E> *p=first->link,*pre=first;
	while(p!=NULL&&p->data<e1){
		pre=p;   p=p->link;  
	}
	if(p!=NULL&&p->data==e1){
		pre->link=p->link;
		t1=p->data; delete p;
		return true;
	}
	else return false;
}
template<class T,class E>
istream &operator >>(istream &in,SortedChain<T,E> &S){
	int n; T elem;
	cout<<"输入字典中元素的个数：";
	in>>n;
	cout<<"输入 "<<n<<" 个元素："<<endl;
	for(int i=0;i<n;i++){
		in>>elem;
		ChainNode<T,E> *p=S.first->link,*pre=S.first,*newNode;
		while(p!=NULL&&p->data<elem){
			p=p->link; pre=p;
		}
		newNode=new ChainNode<T,E>(elem);
		if(newNode==NULL){
		cout<<"存储分配失败！"<<endl; exit(1);
	    }
	    newNode->link=p; pre->link=newNode;	
	} 
	return in;
}
template<class T,class E>
ostream &operator <<(ostream &out,SortedChain<T,E> &S){
	out<<"输出字典中的元素："<<endl; int count=0;
	ChainNode<T,E> *p=S.first->link;
	while(p!=NULL){
		count++;
		out<<p->data<<' ';
		p=p->link;
	}
	out<<endl<<"字典中共有 "<<count<<" 个元素！"<<endl;;
	return out;
}