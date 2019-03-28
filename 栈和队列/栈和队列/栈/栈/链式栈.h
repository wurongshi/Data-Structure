 template<class T>
 struct LinkNode{
 	T data;
 	LinkNode<T> *link;
 	LinkNode(LinkNode<T> *ptr=NULL):link(ptr){}
	LinkNode(T d,LinkNode<T> *ptr=NULL):data(d),link(ptr){}
 };
 template<class T>
 class LinkedStack{
 	public:
 		LinkedStack():top(NULL){}
 		~LinkedStack(){}
		void Push(const T &x);
		bool Pop(T &x);
		bool getTop(T &x)const;
		bool IsEmpty()const{ return (top==NULL)?true:false; }
		int getSize()const;
		void makeEmpty();
		friend ostream &operator<< <>(ostream &out,LinkedStack<T> &s);
		void input();
	private:
		LinkNode<T> *top;
 };
  template<class T>
  void LinkedStack<T>::Push(const T &x){
  	top=new LinkNode<T>(x,top);
  	assert(top!=NULL);
  }
  template<class T>
  bool LinkedStack<T>::Pop(T &x){
  	if(IsEmpty()) return false;
  	LinkNode<T> *p=top;
  	top=top->link; x=p->data;
  	delete p;  return true;
  }
  template<class T>
  bool LinkedStack<T>::getTop(T &x)const{
  	if(IsEmpty()==true) return false;
  	x=top->data;
  	return true;
  }
  template<class T>
  int LinkedStack<T>::getSize()const{
  	LinkNode<T> *p=top; int k=0;
  	while(p!=NULL){
  		p=p->link;
  		k++;
	  }
	  return k;
  }
  template<class T>
  void LinkedStack<T>::makeEmpty(){
  	while(top!=NULL){
  		LinkNode<T> *p=top;
  		top=top->link;
  		delete p;
	  }
  }
  template<class T>
  ostream &operator <<(ostream &out,LinkedStack<T> &s){
  	out<<"栈中元素个数："<<s.getSize()<<endl;
  	LinkNode<T> *p=s.top; int i=s.getSize();
  	while(p!=NULL){
  		out<<--i<<": "<<p->data<<endl;
  		p=p->link;
	  }
	  return out;
  }
  template<class T>
  void LinkedStack<T>::input(){
  	int n,d;
  	cout<<"创建一个链式栈，请输入栈中元素个数：";
  	cin>>n;
  	cout<<"输入栈中元素："<<endl; 
  	for(int i=0;i<n;i++){
  		cin>>d;
  		Push(d);
	  }
  }