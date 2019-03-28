template<class T>
struct ThreadNode{
	int ltag,rtag;
	ThreadNode<T> *leftChild,*rightChild;
	T data;
	ThreadNode(const T item):data(item),leftChild(NULL),rightChild(NULL),ltag(0),rtag(0){}
}; 
template<class T>
class ThreadTree;
template<class T>
istream &operator >>(istream &in,ThreadTree<T> &tree);
template<class T>
class ThreadTree{
	protected:
		ThreadNode<T> *root;
		void createInThread(ThreadNode<T> *current,ThreadNode<T> *&pre);
		ThreadNode<T> *Parent(ThreadNode<T> *t);
		friend istream &operator >> <>(istream &in,ThreadTree &tree);		
	public:
		ThreadTree():root(NULL){}
		void createInThread();
		void createTree(istream &in,ThreadNode<T> *&subTree);
		ThreadNode<T> *First(ThreadNode<T> *current);
		ThreadNode<T> *Last(ThreadNode<T> *current);
		ThreadNode<T> *Next(ThreadNode<T> *current);
		ThreadNode<T> *Prior(ThreadNode<T> *current);
		void InOrder(void (*visit)(ThreadNode<T> *p));
		void PreOrder(void (*visit)(ThreadNode<T> *p));
		void PostOrder(void (*visit)(ThreadNode<T> *p));  
};
template<class T>
void visit(ThreadNode<T> *p){
	cout<<p->data<<" ";
}
template<class T>
istream &operator >>(istream &in,ThreadTree<T> &tree){
	tree.createTree(in,tree.root);
	return in;
}
template<class T>
void ThreadTree<T>::createTree(istream &in,ThreadNode<T> *&subTree){
	T item;
	if(!in.eof()){
		in>>item;
		if(item!='#'){
			subTree=new ThreadNode<T>(item);
			if(subTree==NULL){
				cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl;
				exit(1);
			}
			createTree(in,subTree->leftChild);
			createTree(in,subTree->rightChild);
		}
		else subTree=NULL;
	}
}
template<class T>
ThreadNode<T> *ThreadTree<T>::First(ThreadNode<T> *current){
	ThreadNode<T> *p=current;
	while(p->ltag==0) p=p->leftChild;
	return p;
}
template<class T>
ThreadNode<T> *ThreadTree<T>::Last(ThreadNode<T> *current){
	ThreadNode<T> *p=current;
	while(p->rtag==0) p=p->rightChild;
	return p;
}
template<class T>
ThreadNode<T> *ThreadTree<T>::Next(ThreadNode<T> *current){
	ThreadNode<T> *p=current->rightChild;
	if(current->rtag==0) return First(p);
	else return p;
}
template<class T>
ThreadNode<T> *ThreadTree<T>::Prior(ThreadNode<T> *current){
	ThreadNode<T> *p=current->leftChild;
	if(current->ltag==0) return Last(p);
	else return p;
}
template<class T>
void ThreadTree<T>::InOrder(void (*visit)(ThreadNode<T> *p)){
	ThreadNode<T> *p;
	for(p=First(root);p!=NULL;p=Next(p)) visit(p);
}
template<class T>
void ThreadTree<T>::createInThread(){
	ThreadNode<T> *pre=NULL;
	if(root!=NULL){
		createInThread(root,pre);
		pre->rightChild=NULL;
		pre->rtag=1;
	}
}
template<class T>
void ThreadTree<T>::createInThread(ThreadNode<T> *current,ThreadNode<T> *&pre){
	if(current==NULL) return ;
	createInThread(current->leftChild,pre);
	if(current->leftChild==NULL){
		current->leftChild=pre; 
		current->ltag=1;
	} 
	if(pre!=NULL&&pre->rightChild==NULL){
		pre->rightChild=current;
		pre->rtag=1;
	}
	pre=current;
	createInThread(current->rightChild,pre);
}
template<class T>
void ThreadTree<T>::PreOrder(void (*visit)(ThreadNode<T> *p)){
	ThreadNode<T> *p=root;
	while(p!=NULL){
		visit(p);
		if(p->ltag==0) p=p->leftChild;
		else if(p->rtag==0) p=p->rightChild;
		else{
			while(p!=NULL&&p->rtag==1)
			    p=p->rightChild;
			if(p!=NULL) p=p->rightChild;
		}
	}
}
template<class T>
void ThreadTree<T>::PostOrder(void (*visit)(ThreadNode<T> *p)){
	ThreadNode<T> *t=root;
	while(t->ltag==0||t->rtag==0)
	    if(t->ltag==0) t=t->leftChild;
	    else if(t->rtag==0) t=t->rightChild;
	visit(t);
	ThreadNode<T> *p;
	while((p=Parent(t))!=NULL){
		if(p->rightChild==t||p->rtag==1)
		t=p;
		else{
			t=p->rightChild;
	        while(t->ltag==0||t->rtag==0)
	            if(t->ltag==0) t=t->leftChild;
	            else if(t->rtag==0) t=t->rightChild;
		}
		visit(t);
	}
}
template<class T>
ThreadNode<T> *ThreadTree<T>::Parent(ThreadNode<T> *t){
	ThreadNode<T> *p;
	if(t==root) return NULL;
	for(p=t;p->ltag==0;p=p->leftChild);
	if(p->leftChild!=NULL)
	    for(p=p->leftChild;p!=NULL&&p->leftChild!=t&&p->rightChild!=t;p=p->rightChild);
	if(p==NULL||p->leftChild==NULL){
	    for(p=t;p->rtag==0;p=p->rightChild);
	    for(p=p->rightChild;p!=NULL&&p->leftChild!=t&&p->rightChild!=t;p=p->leftChild);
	}
	return p;
		
}