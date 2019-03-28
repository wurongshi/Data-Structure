template<class E,class K>
struct SkipNode{
	E data;
	SkipNode<E,K> **link;
	SkipNode(int size=DefaultSize){
		link=new SkipNode<E,K> *[size];
		if(link==NULL){
			cout<<"存储分配失败！"<<endl;
			exit(1);
		}
	}
	~SkipNode(){  delete []link;   }
};
template<class E,class K>
class SkipList;
template<class E,class K>
istream &operator >>(istream &in,SkipList<E,K> &s);
template<class E,class K>
ostream &operator <<(ostream &out,SkipList<E,K> &s);
template<class E,class K>
class SkipList{
	public:
		SkipList(K large,int maxLev=DefaultSize);
		~SkipList();
		bool Search(const K k1,E &e1)const;
		E &getData(SkipNode<E,K> *current){
			if(current!=NULL) return &current->data;
			else return NULL;
		} 
		bool Insert(const K k1,E &e1);
		bool Remove(const K k1,E &e1);
		friend istream &operator >> <>(istream &in,SkipList<E,K> &s);
		friend ostream &operator << <>(ostream &out,SkipList<E,K> &s);
		
	private:
		int maxLevel;
		int Levels;
		K TailKey;
		SkipNode<E,K> *head;
		SkipNode<E,K> *tail;
		SkipNode<E,K> **last;
		int Level();
		SkipNode<E,K> *SaveSearch(const K k1);
};
template<class E,class K>
SkipList<E,K>::SkipList(K large,int maxLev){
	maxLevel=maxLev;
	TailKey=large;
	Levels=0;
	head=new SkipNode<E,K>(maxLevel+1);
	tail=new SkipNode<E,K>(0);
	last=new SkipNode<E,K> *[maxLevel+1];
	tail->data=large;
	for(int i=0;i<=maxLevel;i++) head->link[i]=tail;
}
template<class E,class K>
SkipList<E,K>::~SkipList(){
	SkipNode<E,K> *next;
	while(head!=tail){
		next=head->link[0];
		delete head;
		head=next;
	}
	delete tail;
	delete []last;
}
template<class E,class K>
bool SkipList<E,K>::Search(const K k1,E &e1)const{
	if(k1>TailKey) return false;
	SkipNode<E,K> *p=head;
	for(int i=Levels;i>=0;i--){
		while(p->link[i]->data<k1){
			p=p->link[i];
		}
	}
	e1=p->link[0]->data;
	return (e1==k1)? true:false;
}
template<class E,class K>
SkipNode<E,K> *SkipList<E,K>::SaveSearch(const K k1){
	if(k1>TailKey) return NULL;
	SkipNode<E,K>*p=head;
	for(int i=Levels;i>=0;i--){
		while(p->link[i]->data<k1){
			p=p->link[i];
		}
		last[i]=p;
	}
	return p->link[0];
}
template<class E,class K>
int SkipList<E,K>::Level(){
	int lev=0;
	while(rand()<=RAND_MAX/2) lev++;
	return (lev<maxLevel)? lev:maxLevel;
} 
template<class E,class K>
bool SkipList<E,K>::Insert(const K k1,E &e1){
	if(k1>=TailKey){
		cout<<"关键码太大！"<<endl; 
		return false;
	} 
	SkipNode<E,K> *p=SaveSearch(k1);
	if(p->data==e1){
		cout<<"关键码重复！"<<endl;
		return false;
	}
	int lev=Level();
	if(lev>Levels){
		lev=++Levels;
		last[lev]=head;
	}
	SkipNode<E,K> *newNode=new SkipNode<E,K>(lev+1);
	newNode->data=e1;
	for(int i=0;i<=lev;i++){
		newNode->link[i]=last[i]->link[i];
		last[i]->link[i]=newNode;
	}
	return true;
}
template<class E,class K>
bool SkipList<E,K>::Remove(const K k1,E &e1){
	if(k1>TailKey){
		cout<<"存储分配失败！"<<endl; return false;
	}
	SkipNode<E,K> *p=SaveSearch(k1);
	if(p->data!=k1){
		cout<<"被删除的元素不存在！"<<endl;  return false;
	}
	for(int i=0;i<=Levels&&last[i]->link==p;i++){
		last[i]->link[i]=p->link[i];
	}
	while(Levels>0&&head->link[Levels]==tail){   //修改级数 
		Levels--;
	}
	e1=p->data; delete p;
	return true;
}
template<class E,class K>
istream &operator >>(istream &in,SkipList<E,K> &s){
	K k1; E e1; int n;
	cout<<"输入元素的个数："; 
	cin>>n;
	cout<<"输入 "<<n<<" 个元素！"<<endl; 
	for(int i=0;i<n;i++){
		cin>>k1;
		s.Insert(k1,k1);
	} 
	return in;
}
template<class E,class K>
ostream &operator <<(ostream &out,SkipList<E,K> &s){
	SkipNode<E,K> *p=s.head->link[0];
	while(p!=s.tail){
		out<<p->data<<' ';
		p=p->link[0];
	}
	out<<endl;
	return out;
}