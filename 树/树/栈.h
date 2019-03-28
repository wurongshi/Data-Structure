template<class T> 
 class SeqStack{
 	public:
 		SeqStack(int sz=50);
 		~SeqStack(){}
 		void Push(const T x);
 		bool Pop(T &x);
 		bool getTop(T &x);
 		bool IsEmpty(){ return (top==-1)?true:false; }
		bool IsFull(){ return (top==maxSize-1)?true:false; }
		int getSize(){ return top+1; }
		void makeEmpty(){ top=-1; } 
		void input(int n);
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
 		cout<<"�洢�������"<<endl;
	 }
	for(int i=0;i<=top;i++) newArray[i]=elements[i];
	maxSize+=stackIncreament;
	delete []elements;  elements=newArray;
 }
 template<class T>
 void SeqStack<T>::Push(const T x){
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