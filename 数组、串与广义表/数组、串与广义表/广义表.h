template<class T>
struct GenListNode{
public:
	GenListNode():utype(0),tlink(NULL),info.ref(0){}
	GenListNode(GenListNode<T> &RL){
		utype=RL.utype;  tlink=RL.tlink;  info=RL.info;
	}
private:
	int utype;
	GenListNode<T> *tlink;
	union{
		int ref;
		T value;
		GenListNode<T> *hlink;
	}info;
};
template<class T>
struct Items{
	int utype;
	union{
		int ref;
		T value;
		GenListNode<T> *link;
	}info;
	Items():utype(0),info.ref(0){}
	Items(Items<T> &RL){ utype=RL.utype; info=RL.info;  }
};
template<class T>
class GenList{
public:
	GenList();
	~GenList();
	bool Head(Items<T> &x);
	bool Tail(GenList<T> &lt);
	GenListNode<T> *First();
	GenListNode<T> *Next(GenListNode<T> *elem);
	void Copy(const GenList<T> &R);
	void delvalue(GenListNode<T> *ls,T x);
	int Length();
	int depth();
	friend istream &operator >> <>(istream &in,GenList<T> &L);
private:
	GenListNode<T> *first;
	GenListNode<T> *Copy(GenListNode<T> *ls);
	int Length(GenListNode<T> *ls);
	int depth(GenListNode<T> *ls);
	bool equal(GenListNode<T> *s,GenListNode<T> *t);
	void Remove(GenListNode<T> *ls);
	void Createlist(istream &in,GenListNode<T> *&ls,SeqList<T> &L1,SeqList<GenListNode<T> *> &L2);
};
template<class T>
GenList<T>::GenList(){
	first=new GenListNode<T>;
	assert(first!=NULL);
}
template<class T>
bool GenList<T>::Head(Items<T> &x){
	if(first->tlink==NULL) return false;
	else{
		x.utype=first->tlink->utypt;
		x.info=first->tlink->info;
		return true;
	}
}
template<class T>
bool GenList<T>::Tail(GenList<T> &lt){
	if(first->tlink==NULL) return false;
	else{
		lt.first->utype=0;
		lt.first->info.ref=0;
		lt.first->tlink=Copy(first->tlink->tlink);
		return true;
	}
}
template<class T>
GenListNode<T> *GenList<T>::First(){
	if(first->tlink==NULL)  return NULL;
	else return first->tlink;
}
template<class T>
GenListNode<T> *GenList<T>::Next(GenListNode<T> *elem){
	if(elem->tlink==NULL)  return false;
	else return elem->tlink;
}
template<class T>
void GenList<T>::Copy(const GenList<T> &R){
	first=Copy(R.first);
}
template<class T>
GenListNode<T> *GenList<T>::Copy(GenListNode<T> *ls){
	GenListNode<T> *q=NULL;
	if(sl!=NULL){
		q=new GenListNode<T>;
		q->utype=ls->utype;
		switch(ls->utype){
		case 0: q->info.ref=ls->info.ref; break;
		case 1: q->info.value=ls->info.value; break; 
		case 2: q->info.hlink=Copy(ls->info.hlink); break;
		}
		q->tlink=Copy(ls->tlink);
	}
	return q;
}
template<class T>
int GenList<T>::Length(){
	return Length(first);
}
template<class T>
int GenList<T>::Length(GenListNode<T> *ls){    //Éî¶È
	if(ls!=NULL)  return 1+Length(ls->tlink);
	else return 0;
}
template<class T>
int GenList<T>::depth(){
	return depth(first);
}
template<class T>
int GenList<T>::depth(GenListNode<T> *ls){
	if(ls->tlink==NULL) return 1;
	GenListNode<T> *temp=ls->tlink;  int m=0,n;
	while(temp!=NULL){
		if(temp->utype==2){
			n=depth(temp->info.hlink);
			if(m<n) m=n;
		}
		temp=temp->tlink;
	}
	return m+1;
}
template<class T>
bool equal(GenListNode<T> *s,GenListNode<T> *t){
	int x;
	if(s->tlink==NULL&&t->tlink==NULL)  return true;
	if(s->tlink!=NULL&&t->tlink!=NULL&&s->tlink->utype==t->tlink->utype){
		if(s->tlink->utype==1)  x=(s->tlink->info.value==t->tlink->info.value)? 1:0;
		else if(s->tlink->utype==2)  x=equal(s->tlink->info.hlink,t->tlink->info.hlink)? 1:0;
		if(x==1) return equal(s->tlink,t->tlink);
	}
	return false;
}
template<class T> 
void GenList<T>::delvalue(GenListNode<T> *ls,T x){
	if(ls->tlink!=NULL){
		GenListNode<T> *p=ls->tlink;
		while(p!=NULL&&(p->utype==1&&p->info.value==x)){
			ls->tlink=p->tlink;  delete p;  p=ls->tlink;
		}
		if(p!=NULL){
			if(p->utype==2)
				delvalue(p->info.hlink,x);
			delvalue(p,x);
		}
	}
}
template<class T>
GenList<T>::~GenList(){
	Remove(first);
}
template<class T>
void GenList<T>::Remove(GenListNode<T> *ls){
	ls->info.ref--;
	if(ls->info.ref<=0){
		GenListNode<T> *q;
		while(ls->tlink!=NULL){
			q=ls->tlink;
			if(q->utype==2){
				Remove(q->info.hlink);
				if(q->info.hlink->info.ref<=0)
					delete q->info.hlink;
			}
			ls->tlink=q->tlink; delete q;
		}
	}
}
template<class T>
void GenList<T>::Createlist(istream &in,GenListNode<T> *&ls,SeqList<T> &L1,SeqList<GenListNode<T> *> &L2){
	T chr;
	in>>chr;
	if(isalpha(chr)&&isupper(chr)||chr=='('){
		ls=new GenListNode<T>;   ls->utype=2;
		if(isalpha(chr)&&isupper(chr)){
			int n=L1.Length();
			int m=L1.Search(chr);
			if(m!=0){
				GenListNode<T> *p=L2.Locate(m);
				p->info.ref++;
			}
			else{
				L1.Insert(n,chr);  L2.Insert(n,ls);
			}
			in>>chr;
			if(chr!='(') exit(1);
		}
		ls->info.hlink=new GenListNode<T>;
		ls->info.hlink->utype=0;  ls->info.hlink->ref=1;  
	}
}