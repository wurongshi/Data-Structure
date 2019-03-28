template<class E,class K>
struct BSTNode{
	E data;
	BSTNode<E,K> *left,*right;
	BSTNode():left(NULL),right(NULL){ }
	BSTNode(const E d,BSTNode<E,K> *L=NULL,BSTNode<E,K> *R=NULL):data(d),left(L),right(R){ }
	~BSTNode(){ }
	void setData(E d){ data=d;  }
	E getData(){  return data;  }
};
template<class E,class K>
class BST{
	public:
		BST():root(NULL){}
		BST(K value);
		~BST(){}
	    bool Search(const K x)const{
	    	return (Search(x,root)!=NULL)? true:false;
		}
		BST<E,K> operator =(const BST<E,K> &R);
		void makeEmpty(){ makeEmpty(root); root=NULL;  }
		void PrintTree(){ PrintTree(root); }
		E Min(){ return Min(root)->data;  }
		E Max(){ return Max(root)->data;  }
		bool Insert(const E &e1){  return Insert(e1,root);  }
		bool Remove(const K x){  return Remove(x,root);  }
	private:
		BSTNode<E,K> *root;
		K RefValue;
		BSTNode<E,K> *Search(const K x,BSTNode<E,K> *ptr);
		void makeEmpty(BSTNode<E,K> *&ptr);
		void PrintTree(BSTNode<E,K> *ptr);
		BSTNode<E,K> *Copy(const BSTNode<E,K> *ptr);
		BSTNode<E,K> *Min(BSTNode<E,K> *ptr)const;
		BSTNode<E,K> *Max(BSTNode<E,K> *ptr)const; 
		bool Insert(const E &e1,BSTNode<E,K> *&ptr);
		bool Remove(const K x,BSTNode<E,K> *&ptr);
}; 
template<class E,class K>
BSTNode<E,K> *BST<E,K>::Search(const K x,BSTNode<E,K> *ptr){
	if(ptr==NULL) return NULL;
	else if(x<ptr->data) return Search(x,ptr->left);
	else if(x>ptr->data) return Search(x,ptr->right);
	else return ptr;
} 
template<class E,class K>
bool BST<E,K>::Insert(const E &e1,BSTNode<E,K> *&ptr){
	if(ptr==NULL){
		ptr=new BSTNode<E,K>(e1);
		if(ptr==NULL){  cout<<"Out of space"<<endl;  return false; }
		return true;
	}
	else if(e1<ptr->data)  Insert(e1,ptr->left);
	else if(e1>ptr->data)  Insert(e1,ptr->right);
	return false;
}
template<class E,class K>
bool BST<E,K>::Remove(const K x,BSTNode<E,K> *&ptr){
	BSTNode<E,K> *temp;
	if(ptr!=NULL){
		if(x<ptr->data) Remove(x,ptr->left);
		else if(x>ptr->data) Remove(x,ptr->right);
		else if(ptr->left!=NULL&&ptr->right!=NULL){
			temp=ptr->right;
			while(temp->left!=NULL) temp=temp->left;
			ptr->data=temp->data;
			Remove(ptr->data,ptr->right);
		}
		else{
			temp=ptr;
			if(ptr->left==NULL) ptr=ptr->right;
			else ptr=ptr->left;
			delete temp;  return true;
		}
	}
	return false;
} 
template<class E,class K>
BST<E,K>::BST(K value){
	E x;  root=NULL;  RefValue=value;
	cin>>x;
	while(x!=RefValue){
		Insert(x,root); cin>>x;
	}
}
template<class E,class K>
void BST<E,K>::PrintTree(BSTNode<E,K> *ptr){
	if(ptr!=NULL){
		cout<<ptr->data<<' ';
		PrintTree(ptr->left);
		PrintTree(ptr->right);
	}
}
template<class E,class K>
BST<E,K> BST<E,K>::operator =(const BST<E,K> &R){
	RefValue=R.RefValue;
	root=Copy(R.root);
	return *this;
}
template<class E,class K>
BSTNode<E,K> *BST<E,K>::Copy(const BSTNode<E,K> *ptr){
	if(ptr==NULL) return NULL;
	BSTNode<E,K> *temp=new BSTNode<E,K>;
	temp->data=ptr->data;
	temp->left=Copy(ptr->left);
	temp->right=Copy(ptr->right);
	return temp;
}
template<class E,class K>
void BST<E,K>::makeEmpty(BSTNode<E,K> *&ptr){
	if(ptr!=NULL){
		makeEmpty(ptr->left);
		makeEmpty(ptr->right);
		delete ptr;
	}
}