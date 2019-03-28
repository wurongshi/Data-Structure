template <class T>
struct BinTreeNode{
	T data;
	BinTreeNode<T> *leftChild,*rightChild;
	BinTreeNode(T x,BinTreeNode<T> *l=NULL,BinTreeNode<T> *r=NULL):data(x),leftChild(l),rightChild(r){}
}; 
template<class T>
struct stkNode{
	BinTreeNode<T> *ptr;
	enum tag{L=0,R=1}tag;
	stkNode(BinTreeNode<T> *N=NULL):ptr(N),tag(L){	}
};
template<class T>
class BinaryTree;
template<class T>
istream &operator >>(istream &in,BinaryTree<T> &Tree);
template<class T>
ostream &operator <<(ostream &out,BinaryTree<T> &Tree);
template<class T>
class BinaryTree{
	public:
		BinaryTree():root(NULL){ }              //构造函数 
		BinaryTree(T value):RefValue(value),root(NULL){ }   //构造函数 
		BinaryTree(BinaryTree<T> &s);                   //复制构造函数 
		~BinaryTree(){ destroy(root); }
		bool isEmpty(){ return (root==NULL)?true:false; }
		void CreateBinTree(ifstream &in,BinTreeNode<T> *&subTree);
		BinTreeNode<T> *Parent(BinTreeNode<T> *current){
			return (root==NULL||root==current)? NULL:Parent(root,current);
		}
		BinTreeNode<T> *LeftChild(BinTreeNode<T> *current){
			return (current!=NULL)? current->leftChild:NULL;
		}
	    BinTreeNode<T> *RightChild(BinTreeNode<T> *current){
			return (current!=NULL)? current->rightChild:NULL;
		}
		int Height(){ return Height(root); } 
		int Size(){ return Size(root); }
        BinTreeNode<T> *getRoot()const{ return root; }
        void PreOrder(void (*visit)(BinTreeNode<T> *p)){           // 前序遍历 
        	PreOrder(root,visit);
		}
		void InOrder(void (*visit)(BinTreeNode<T> *p)){            //中序遍历 
        	InOrder(root,visit);
		}
		void PostOrder(void (*visit)(BinTreeNode<T> *p)){          // 后序遍历 
        	PostOrder(root,visit);
		}
		void preOrder1(void (*visit)(BinTreeNode<T> *p));    //前序非递归 
		void preOrder2(void (*visit)(BinTreeNode<T> *p));    //前序非递归 
		void inOrder(void (*visit)(BinTreeNode<T> *p));      //中序非递归 
		void postOrder(void (*visit)(BinTreeNode<T> *p));    //后序非递归 
		void LevelOrder(void (*visit)(BinTreeNode<T> *p));         // 层次遍历 
		//int Insert(const T &item);
		BinTreeNode<T> *Find(T &item)const;
	protected:
		BinTreeNode<T> *root;
		T RefValue;
		void CreateBinTree(istream &in,BinTreeNode<T> *&subTree);
		//bool Insert(BinTreeNode<T> *&subTree,const T &x);
		void destroy(BinTreeNode<T> *subTree);
		bool Find(BinTreeNode<T> *subTree,const T &x)const;
		BinTreeNode<T> *Copy(BinTreeNode<T> *orignode);
		int Height(BinTreeNode<T> *subTree)const;
		int Size(BinTreeNode<T> *subTree)const; 
		BinTreeNode<T> *Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current);           
		//BinTreeNode<T> *Find(BinTreeNode<T> *subTree,const T &x)const;              
		void Traverse(BinTreeNode<T> *subTree,ostream &out);                            // 前序遍历输出 
		void PreOrder(BinTreeNode<T> *subTree,void(*visit)(BinTreeNode<T> *p));          //  前序遍历 
		void InOrder(BinTreeNode<T> *subTree,void(*visit)(BinTreeNode<T> *p));           //  中序遍历 
		void PostOrder(BinTreeNode<T> *subTree,void(*visit)(BinTreeNode<T> *p));         //  后序遍历 
		friend istream &operator >> <>(istream &in,BinaryTree<T> &Tree);
		friend ostream &operator << <>(ostream &out,BinaryTree<T> &Tree);
};
template<class T>
void visit(BinTreeNode<T> *p){
	cout<<p->data<<' ';
}
template<class T>
void BinaryTree<T>::destroy(BinTreeNode<T> *subTree){
	if(subTree!=NULL){
		destroy(subTree->leftChild);
		destroy(subTree->rightChild);
		delete subTree;
	}
}
template<class T>
BinTreeNode<T> *BinaryTree<T>::Parent(BinTreeNode<T> *subTree,BinTreeNode<T> *current){
	if(subTree==NULL) return NULL;
	if(subTree->leftChild==current||subTree->rightChild) return subTree;
	BinTreeNode<T> *p;
	if(p=Parent(subTree->leftChild,current)!=NULL) return p;
	else return Parent(subTree->rightChild,current);
}
template<class T>
void BinaryTree<T>::Traverse(BinTreeNode<T> *subTree,ostream &out){
	if(subTree!=NULL){
		out<<subTree->data<<' ';
		Traverse(subTree->leftChild,out);
		Traverse(subTree->rightChild,out);
	}
}
template<class T>
istream &operator>>(istream &in,BinaryTree<T> &Tree){
	Tree.CreateBinTree(in,Tree.root);
	return in;
}
template<class T>
ostream &operator<<(ostream &out,BinaryTree<T> &Tree){
	out<<"二叉树的前序遍历!"<<endl;
	Tree.Traverse(Tree.root,out);
	out<<endl;
	return out; 
}

//void CreateBinTree(istream &in,BinTreeNode<char> *&BT){
//	Stack<BinTreeNode<char> *>s;
//	BT=NULL;
//	BinTreeNode<char> *p, *t; int k;
//	char ch;
//	in>>ch;
//	while(ch!=RefValue){
//		switch(ch){
//			case'(':s.Push(p); k=1; break;
//			case')':s.Pop(p); break;
//			case',':k=2; break;
//			default: p=new BinTreeNode(ch);
//			      if(BT==NULL) BT=p;
//			      else if(k==1){
//			      	s.getTop(t); t->leftChild=p;
//				  }
//				  else{
//				  	s.getTop(t); t->rightChild=p;
//				  }
//		}
//		in>>ch;
//	}
//}
template<class T>  //递归中序 
void BinaryTree<T>::InOrder(BinTreeNode<T> *subTree,void(*visit)(BinTreeNode<T> *p)){
	if(subTree!=NULL){
		InOrder(subTree->leftChild,visit);
		visit(subTree);
		InOrder(subTree->rightChild,visit);
	}
}
template<class T> //递归前序 
void BinaryTree<T>::PreOrder(BinTreeNode<T> *subTree,void(*visit)(BinTreeNode<T> *p)){
	if(subTree!=NULL){
		visit(subTree);
		PreOrder(subTree->leftChild,visit);
		PreOrder(subTree->rightChild,visit);
	} 
}
template<class T> //递归后序 
void BinaryTree<T>::PostOrder(BinTreeNode<T> *subTree,void(*visit)(BinTreeNode<T> *p)){
	if(subTree!=NULL){
		PostOrder(subTree->leftChild,visit);
		PostOrder(subTree->rightChild,visit);
		visit(subTree);
	}
}
template<class T> //结点个数 
int BinaryTree<T>::Size(BinTreeNode<T> *subTree)const{
	if(subTree==NULL) return 0;
	else return 1+Size(subTree->leftChild)+Size(subTree->rightChild);
} 
template<class T>
int BinaryTree<T>::Height(BinTreeNode<T> *subTree)const{
	if(subTree==NULL) return 0;
	else{
		int i=Height(subTree->leftChild);
		int j=Height(subTree->rightChild);
		return (i<j)? j+1:i+1;
	}
}
template<class T>  //复制构造函数 
BinaryTree<T>::BinaryTree(BinaryTree<T> &s){
	root=Copy(s.root);
} 
template<class T>  //复制 
BinTreeNode<T> *BinaryTree<T>::Copy(BinTreeNode<T> *orignode){
	if(orignode==NULL) return NULL;
	BinTreeNode<T> *temp=new BinTreeNode<T>;
	temp->data=orignode->data;
	temp->leftChild=Copy(orignode->leftChild);
	temp->rightChild=Copy(orignode->rightChild); 
}
template<class T>
int operator ==(BinaryTree<T> &s,BinaryTree<T> &t){
	return (equals(s.root,t.root))? true:false;
} 
template<class T>
bool equals(BinTreeNode<T> *a,BinTreeNode<T> *b){
	if(a==NULL&&b==NULL) return true;
	if(a!=NULL&&b!=NULL&&a->data==b.data&&equals(a->leftChild,b->leftChild)&&equals(a->rightChild,b->rightChild))
	    return true;
	else return false;
}
template<class T>
void BinaryTree<T>::CreateBinTree(istream &in,BinTreeNode<T> *&subTree){
	T item;
	if(!in.eof()){
		in>>item;
		if(item!=RefValue){
			subTree=new BinTreeNode<T>(item);
			if(subTree==NULL){
				cout<<"存储分配错误！"<<endl; exit(1);
			}
			CreateBinTree(in,subTree->leftChild);
			CreateBinTree(in,subTree->rightChild);
		}
		else subTree=NULL;
	}
}
template<class T>
void PrintBTree(BinTreeNode<T> *BT){
	if(BT!=NULL){
		cout<<BT->data;
		if(BT->leftChild!=NULL||BT->rightChild!=NULL){
			cout<<"(";
			PrintBTree(BT->leftChild);
			cout<<" , ";
			if(BT->rightChild!=NULL)
			    PrintBTree(BT->rightChild);
			cout<<")";
		}
	}
}
template<class T>
void BinaryTree<T>::preOrder1(void (*visit)(BinTreeNode<T> *p)){    //前序非递归 
	SeqStack<BinTreeNode<T> *> S;
	BinTreeNode<T> *p=root;
	S.Push(NULL);
	while(p!=NULL){
		visit(p);
		if(p->rightChild!=NULL) S.Push(p->rightChild);
		if(p->leftChild!=NULL) p=p->leftChild;
		else S.Pop(p);
	}
}
template<class T>
void BinaryTree<T>::preOrder2(void (*visit)(BinTreeNode<T> *p)){    //前序非递归 
	SeqStack<BinTreeNode<T> *> S;
	BinTreeNode<T> *p;
	S.Push(root);
	while(!S.IsEmpty()){
		S.Pop(p); visit(p);
		if(p->rightChild!=NULL) S.Push(p->rightChild);
		if(p->leftChild!=NULL) S.Push(p->leftChild);
	}
} 
template<class T>
void BinaryTree<T>::inOrder(void (*visit)(BinTreeNode<T> *p)){     //中序非递归 
	SeqStack<BinTreeNode<T> *> S;
	BinTreeNode<T> *p=root;
	do{
		while(p!=NULL){
			S.Push(p);
			p=p->leftChild;
		}
		if(!S.IsEmpty()){
			S.Pop(p);
			visit(p);
			p=p->rightChild;
		}
	}while(p!=NULL||!S.IsEmpty());
}
template<class T>
void BinaryTree<T>::LevelOrder(void (*visit)(BinTreeNode<T> *p)){  //层次遍历  
	SeqQueue<BinTreeNode<T> *> Q;
	BinTreeNode<T> *p=root;
	Q.EnQueue(p);
	while(!Q.IsEmpty()){
		Q.DeQueue(p); visit(p);
		if(p->leftChild!=NULL) Q.EnQueue(p->leftChild);
		if(p->rightChild!=NULL) Q.EnQueue(p->rightChild);
	} 
}
template<class T>
void BinaryTree<T>::postOrder(void (*visit)(BinTreeNode<T> *p)){
	SeqStack<stkNode<T> > S; stkNode<T> w;
	BinTreeNode<T> *p=root;
	do{
		while(p!=NULL){
			w.ptr=p;
			w.tag=w.L;
			S.Push(w);
			p=p->leftChild;
		}
		int continue1=1;
		while(continue1&&!S.IsEmpty()){
			S.Pop(w);  p=w.ptr;
			switch(w.tag){
				case 0:w.tag=w.R; S.Push(w);
				       continue1=0;
				       p=p->rightChild;
				       break;
				case 1:visit(p); break;
			}
		}
	}while(!S.IsEmpty());
	cout<<endl;
}