template<class E,class K>
struct AVLNode{
	int bf;
	E data;
	AVLNode<E,K> *left,*right;
	AVLNode():left(NULL),right(NULL),bf(0){	}
	AVLNode(E d,AVLNode<E,K> *l=NULL,AVLNode<E,K> *r=NULL):data(d),left(l),right(r),bf(0){ }
};
template<class E,class K>
class AVLTree:public BST<E,K>{
	public:
		AVLTree():BST<E,K>::root(NULL){}
	    AVLTree(K Ref):BST<E,K>::RefValue(Ref),root(NULL){ }
	    bool Insert(E &e1){  return Insert(root,e1); }
		bool Remove(K x,E &e1){  return Remove(root,x,e1);  }
		friend istream &operator>>(istream &in,AVLTree<E,K> &Tree);
		friend ostream &operator<<(istream &out,AVLTree<E,K> &Tree);
		int Height()const;
	protected:
		AVLNode<E,K> *Search(K x,AVLNode<E,K> *&par)const;
		bool Insert(AVLNode<E,K> *&ptr,E &e1);
		bool Remove(AVLNode<E,K> *&ptr,K x,E &e1);
		void RotateL(AVLNode<E,K> *&ptr);
		void RotateR(AVLNode<E,K> *&ptr);
		void RotateLR(AVLNode<E,K> *&ptr);
		void RotateRL(AVLNode<E,K> *&ptr);
		int Height(AVLNode<E,K> *ptr)const;
};
int main(int argc, char** argv) {
	return 0;
}