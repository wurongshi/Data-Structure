 template<class T>
 class Stack{
 	public:
 		Stack(){}
 		virtual void Push(T &x)=0;
 		virtual bool Pop(T &x)=0;
 		virtual bool getTop(T &x)=0;
 		virtual bool IsEmpty()=0;
 		virtual bool IsFull()=0;
 		virtual int getSize()=0;
 };
 	
 template<class T> 
 class SeqStack:public Stack<T>{
 	public:
 		SeqStack(int sz=50);
 		~SeqStack(){}
 		void Push(T &x);
 		bool Pop(T &x);
 		bool getTop(T &x);
 		bool IsEmpty(){ return (top==-1)?true:false; }
		bool IsFull(){ return (top==maxSize-1)?true:false; }
		int getSize(){ return top+1; }
		void makeEmpty(){ top=-1; } 
		void input(int n);
		friend ostream &operator<< <>(ostream &out, SeqStack<T> &sq);
	private:
		int top;
		T *elements;
		int maxSize;
		void overflowProcess();
 };
 template<class T>
 SeqStack<T>::SeqStack(int sz):top(-1),maxSize(sz){
 	elements=new T[maxSize];
 	assert(elements!=NULL);
 }
 template<class T>
 void SeqStack<T>::overflowProcess(){
 	T *newArray=new T[maxSize+stackIncreament];
 	if(newArray==NULL){
 		cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl;
	 }
	for(int i=0;i<=top;i++) newArray[i]=elements[i];
	maxSize+=stackIncreament;
	delete []elements;  elements=newArray;
 }
 template<class T>
 void SeqStack<T>::Push(T &x){
 	if(IsFull()==true) overflowProcess();
 	top++;
 	elements[top]=x;
 }
 template<class T>
 bool SeqStack<T>::Pop(T &x){
 	if(IsEmpty()) return false;
 	x=elements[top--];
 	return true;
 }
 template<class T>
 bool SeqStack<T>::getTop(T &x){
 	if(IsEmpty()) return false;
 	x=elements[top];
 	return true;
 }
 template<class T>
ostream &operator<< (ostream &out, SeqStack<T> &sq){
 	out<<"top="<<sq.top<<endl;
 	for(int i=sq.top;i>=0;i--){
 		out<<i<<": "<<sq.elements[i]<<endl; ;
	 }
	return out;
 }
 template<class T>
 void SeqStack<T>::input(int n){
 	int x;
 	makeEmpty();
 	for(int i=0;i<n;i++){
 		cin>>x;
 		Push(x);
	 }
 }