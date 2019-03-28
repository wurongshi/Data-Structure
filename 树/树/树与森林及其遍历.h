template<class T>
struct TreeNode{
	T data;
	TreeNode<T> *firstChild,*nextSibling;
	TreeNode(T value=0,TreeNode<T> *fc=NULL,TreeNode<T> *ns=NULL):data(value),firstChild(fc),nextSibling(ns){}
}; 
template<class>
class Tree;
template<class T>
istream &operator >>(istream &in,Tree<T> &tree);
template<class T>
ostream &operator <<(ostream &in,Tree<T> &tree);
template<class T>
class Tree{
	private:
		TreeNode<T> *root,*current;
		bool Find(TreeNode<T> *p,T value);
		void RemovesubTree(TreeNode<T> *p);
		bool FindParent(TreeNode<T> *p,TreeNode<T> *t);
		void createTree(istream &in,TreeNode<T> *&subTree);
		void PreOrder(ostream &out,TreeNode<T> *p);
		void preOrder(TreeNode<T> *t,void (*visit)(TreeNode<T> *p)); //借助二叉树实现先根遍历 
		void PostOrder(ostream &out,TreeNode<T> *p);
		void postOrder(TreeNode<T> *t,void (*visit)(TreeNode<T> *p)); //借助二叉树实现后根遍历 
		void LevelOrder(ostream &out,TreeNode<T> *p);
		TreeNode<T> *create_tree(T *&GL);
	public:
		Tree(){ root=current=NULL; }
		bool Root();
		TreeNode<T> *getRoot(){ return root; }
		bool IsEmpty(){  return (root==NULL)? true:false; }
		bool FirstChild();
		bool NextSibling();
		bool Parent();
		bool Find(T target); 
		int count_node(TreeNode<T> *t)const;
		int find_depth(TreeNode<T> *t)const;
		void create_tree();
		void show_tree(TreeNode<T> *t);
		friend istream &operator >> <>(istream &in,Tree<T> &tree);
		friend ostream &operator << <>(ostream &in,Tree<T> &tree);
};
template<class T> 
void visit(TreeNode<T> *p){
	cout<<p->data<<' ';
}
template<class T>
bool Tree<T>::Root(){
	if(root==NULL){  current=NULL; return false;  }
	else{ current=root; return true; }
} 
template<class T>
bool Tree<T>::FirstChild(){
	if(current!=NULL&&current->firstChild!=NULL){
		current=current->firstChild;
		return true;
	}
	else{
    	current=NULL;  return false;
    }  
}
template<class T>
bool Tree<T>::NextSibling(){
	if(current!=NULL&&current->nextSibling!=NULL){
		current=current->nextSibling;
		return true;
	}
	current=NULL; return false;
}
template<class T>
bool Tree<T>::Parent(){
	TreeNode<T> *p=current;
	if(current==NULL||current=root){
		current=NULL; return false;
	}
	return FindParent(root,p);
}
template<class T>
bool Tree<T>::FindParent(TreeNode<T> *t,TreeNode<T> *p){
	TreeNode<T> *q=t->firstChild;  bool succ;
	while(q!=NULL&&p!=q){
		if((succ=FindParent(q,p))==true) return succ;
		q=q->nextSibling;   
	}
	if(q!=NULL&&q==p){ current=t;  return true; }
	else{  current=NULL;  return false;  }
}
template<class T>
bool Tree<T>::Find(T value){
	if(IsEmpty()) return false;
	return Find(root,value);
}
template<class T>
bool Tree<T>::Find(TreeNode<T> *p,T value){
	bool result=false;
	if(p->data==value){ current=p; result=true;  }
	else{
		TreeNode<T> *q=p->firstChild;
		while(q!=NULL&&!(result=Find(q,value))){
			q=q->nextSibling;
		}
	}
	return result;
}
template<class T>
istream &operator >>(istream &in,Tree<T> &tree){
	tree.createTree(in,tree.root);
	return in;
}
template<class T>
ostream &operator <<(ostream &out,Tree<T> &tree){
	out<<"树中共有 "<<tree.count_node(tree.root)<<" 个结点！"<<endl; 
	out<<"树的深度为： "<<tree.find_depth(tree.root)<<endl;;
	out<<"先根次序遍历！"<<endl; 
	tree.PreOrder(out,tree.root);
	out<<endl<<"后根次序遍历！"<<endl;
	tree.PostOrder(out,tree.root);
	out<<endl<<"借助二叉树实现先根遍历！"<<endl;
	tree.preOrder(tree.root,visit); 
	out<<endl<<"借助二叉树实现后根遍历！"<<endl;
	tree.postOrder(tree.root,visit); 
	out<<endl<<"层次遍历！"<<endl;
	tree.LevelOrder(out,tree.root);
	return out;
	
}
template<class T>
void Tree<T>::show_tree(TreeNode<T> *t){
	if(t==NULL) return;
	cout<<" ( ";
	cout<<t->data;
	for(TreeNode<T> *p=t->firstChild;p!=NULL;p=p->nextSibling){
		show_tree(p);
	}
	cout<<" ) ";
}
template<class T>
void Tree<T>::createTree(istream &in,TreeNode<T> *&subTree){
	T item;
	if(!in.eof()){
		in>>item;
		if(item!='#'){
			subTree=new TreeNode<T>(item);
			if(subTree==NULL){
				cout<<"存储分配错误！"<<endl;
				exit(1);
			}
			createTree(in,subTree->firstChild);
			createTree(in,subTree->nextSibling);
		}
		else subTree=NULL;
	}
}
template<class T>
void Tree<T>::create_tree(){
	T *s=new T[maxSize];
	int i=0;  T ch;
	cin>>ch;
	while(ch!='#'){
		s[i]=ch;
		cin>>ch;
		i++;
	}
	root=create_tree(s);
}
template<class T>
TreeNode<T> *Tree<T>::create_tree(T *&GL){
	if(*GL=='\0') return NULL;
	if(*(GL)==')'){  GL++; return NULL;	}
	if(*(GL)=='('){  GL++;	}
	TreeNode<T> *t=new TreeNode<T>(*(GL++)); 
	t->firstChild=create_tree(GL);
	t->nextSibling=create_tree(GL);
	return t;
}
template<class T>
int Tree<T>::count_node(TreeNode<T> *t)const{
	if(t==NULL) return 0;
	int count=1;
	count+=count_node(t->firstChild);
	count+=count_node(t->nextSibling);
	return count;
}
template<class T>
int Tree<T>::find_depth(TreeNode<T> *t)const{
	if(t==NULL) return 0;
	int fc_depth=find_depth(t->firstChild)+1;
	int ns_depth=find_depth(t->nextSibling);
	return (fc_depth>ns_depth)? fc_depth:ns_depth;
}
template<class T>
void Tree<T>::PreOrder(ostream &out,TreeNode<T> *p){
	if(p!=NULL){
		out<<p->data<<' ';
		for(p=p->firstChild;p!=NULL;p=p->nextSibling)
		    PreOrder(out,p);
	}
}
template<class T>
void Tree<T>::preOrder(TreeNode<T> *t,void (*visit)(TreeNode<T> *p)){
	if(t!=NULL){
		visit(t);
		preOrder(t->firstChild,visit);
		preOrder(t->nextSibling,visit);
	}
} 
template<class T>
void Tree<T>::PostOrder(ostream &out,TreeNode<T> *p){
	if(p!=NULL){
		TreeNode<T> *q;
		for(q=p->firstChild;q!=NULL;q=q->nextSibling)
		    PostOrder(out,q);
		out<<p->data<<' ';
	}
}
template<class T>
void Tree<T>::postOrder(TreeNode<T> *t,void (*visit)(TreeNode<T> *p)){
	if(t!=NULL){
		postOrder(t->firstChild,visit);
		visit(t);
		postOrder(t->nextSibling,visit);
	}
}
template<class T>
void Tree<T>::LevelOrder(ostream &out,TreeNode<T> *p){
	SeqQueue<TreeNode<T> *> Q;
	if(p!=NULL){
		Q.EnQueue(p);
		while(!Q.IsEmpty()){
			Q.DeQueue(p);
			out<<p->data<<' ';
			for(p=p->firstChild;p!=NULL;p=p->nextSibling)
			    Q.EnQueue(p);
		}
	}
}