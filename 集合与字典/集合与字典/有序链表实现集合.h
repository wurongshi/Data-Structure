template<class T>
struct SetNode{
	T data;
	SetNode<T> *link;
	SetNode():link(NULL){}
	SetNode(const T &x,SetNode<T> *next=NULL):data(x),link(next){}
};
template<class T>
class LinkedSet{
	private:
		SetNode<T> *first,*last;
	public:
		LinkedSet(){ first=last=new SetNode<T>; }
		LinkedSet(LinkedSet<T> &R);
		~LinkedSet(){  makeEmpty(); delete first;  }
		void makeEmpty();
		bool addMember(const T &x);
		bool delMember(const T &x);
		LinkedSet operator =(LinkedSet<T> &R);
		LinkedSet operator +(LinkedSet<T> &R);
		LinkedSet operator *(LinkedSet<T> &R);
		LinkedSet operator -(LinkedSet<T> &R);
		bool Contains(const T &x);
		bool operator ==(LinkedSet<T> &R);
		bool Min(T &x);
		bool Max(T &x);
		bool subSet(LinkedSet<T> &R);
		friend istream &operator >> <>(istream &in,LinkedSet<T> &R);
		friend ostream &operator << <>(ostream &out,LinkedSet<T> &R);
};
template<class T>
LinkedSet<T>::LinkedSet(LinkedSet<T> &R){
	SetNode<T> *srcptr=R.first->link;
	first=last=new SetNode<T>;
	while(srcptr!=NULL){
		last->link=new SetNode<T>(srcptr->data);
		last=last->link;
		srcptr=srcptr->link;
	}
	last->link=NULL;
} 
template<class T>
void LinkedSet<T>::makeEmpty(){
	SetNode<T> *p=first->link,*q;
	while(p!=NULL&&p!=last){
		first->link=p->link;
		q=p;
		p=p->link;
		delete q;
	}
	first->link=NULL;
}
template<class T>
bool LinkedSet<T>::addMember(const T &x){
	SetNode<T> *p=first->link,*pre=first;
	while(p!=NULL&&p->data<x){
		pre=p;p=p->link;
	}
	if(p!=NULL&&p->data==x) return false;
	SetNode<T> *s=new SetNode<T>(x);
	s->link=p;  pre->link=s;
	if(p==NULL) last=s;
	return true;
}
template<class T>
bool LinkedSet<T>::delMember(const T &x){
	SetNode<T> *p=first->link, *pre=first;
	while(p!=NULL&&p->data<x){
		pre=p;p=p->link;
	}
	if(p!=NULL&&p->data==x){
		pre->link=p->link;
		if(p==last) last=pre;
		delete p;  return true;
	}
	else return false;
}
template<class T>
bool LinkedSet<T>::Contains(const T &x){
	SetNode<T> *temp=first->link;
	while(temp!=NULL&&temp->data<x){
		temp=temp->link;
	}
	if(temp!=NULL&&temp->data==x) return true;
	else return false;
}
template<class T>
LinkedSet<T> LinkedSet<T>:: operator =(LinkedSet<T> &R){
	SetNode<T> *pb=R.first->link;
	SetNode<T> *pa=first=new SetNode<T>;
	while(pb!=NULL){
		pa->link=new SetNode<T>(pb->data);
		pa=pa->link;  pb=pb->link;
	}
	pa->link=NULL;  last=pa;
	return *this;
	
}
template<class T>
LinkedSet<T> LinkedSet<T>:: operator +(LinkedSet<T> &R){   //���� 
	SetNode<T> *pb=R.first->link;
	SetNode<T> *pa=first->link;
	LinkedSet<T> temp;
	SetNode<T> *p,*pc=temp.first;
	while(pa!=NULL&&pb!=NULL){
		if(pa->data==pb->data){
			pc->link=new SetNode<T>(pa->data);
			pa=pa->link;   pb=pb->link;
		}
		else if(pa->data<pb->data){
			pc->link=new SetNode<T>(pa->data);
			pa=pa->link;
		}
		else{
			pc->link=new SetNode<T>(pb->data);
			pb=pb->link;
		}
		pc=pc->link;
	} 
	if(pa!=NULL) p=pa;
	else p=pb;
	while(p!=NULL){
		pc->link=new SetNode<T>(p->data);
		pc=pc->link;  p=p->link;
	}
	pc->link=NULL;  temp.last=pc;
	return temp;
}
template<class T>
LinkedSet<T> LinkedSet<T>:: operator *(LinkedSet<T> &R){   //���� 
	SetNode<T> *pb=R.first->link;
	SetNode<T> *pa=first->link;
	LinkedSet<T> temp;
	SetNode<T> *pc=temp.first;
	while(pa!=NULL&&pb!=NULL){
		if(pa->data==pb->data){
			pc->link=new SetNode<T>(pa->data);
			pc=pc->link;
			pa=pa->link;   pb=pb->link;
		}
		else if(pa->data<pb->data) pa=pa->link;
		else pb=pb->link;
	} 
	pc->link=NULL; temp.last=pc;
	return temp;
}
template<class T>
LinkedSet<T> LinkedSet<T>:: operator -(LinkedSet<T> &R){
	SetNode<T> *pb=R.first->link;
	SetNode<T> *pa=first->link;
	LinkedSet<T> temp;
	SetNode<T> *pc=temp.first;
	while(pa!=NULL&&pb!=NULL){
		if(pa->data==pb->data){
			pa=pa->link;  pb=pb->link;
		}
		else if(pa->data<pb->data){
			pc->link=new SetNode<T>(pa->data);
			pc=pc->link;  pa=pa->link;
		}
		else pb=pb->link;
	}
	while(pa!=NULL){
		pc->link=new SetNode<T>(pa->data);
		pc=pc->link;   pa=pa->link;
	}
	pc->link=NULL; temp.last=pc;
	return temp;
}
template<class T>
bool LinkedSet<T>::operator ==(LinkedSet<T> &R){
	SetNode<T> *pb=R.first->link;
	SetNode<T> *pa=first->link;
	while(pa!=NULL&&pb!=NULL){
		if(pa->data==pb->data){
			pa=pa->link;   pb=pb->link;
		}
		else return false;
	}
	if(pa!=NULL||pb!=NULL) return false;
	return true;
}
template<class T>
bool LinkedSet<T>::Min(T &x){
	if(first->link!=NULL){
		x=first->link->data;
		return true;
	}
	return false;
} 
template<class T>
bool LinkedSet<T>::Max(T &x){
	if(last!=NULL&&last!=first){
		x=last->data;
		return true;
	}
	return false;
}
template<class T>
istream &operator >>(istream &in,LinkedSet<T> &R){
	T elem;  int n;
	cout<<"������������һ�����ϣ����뼯��Ԫ�صĸ�����";
	in>>n;
	for(int i=0;i<n;i++){
		in>>elem;
		R.addMember(elem);
	} 
	return in;
}
template<class T>
ostream &operator <<(ostream &out,LinkedSet<T> &R){
	SetNode<T> *p=R.first->link; T x; 
	out<<"��������е�Ԫ�أ�"<<endl;
	while(p!=NULL){
		out<<p->data<<' ';
		p=p->link;
	}
	R.Max(x);
	out<<endl<<"�����е����Ԫ��Ϊ��"<<x<<endl;
	R.Min(x);
	out<<"�����е���СԪ��Ϊ��"<<x<<endl;
	return out;
}