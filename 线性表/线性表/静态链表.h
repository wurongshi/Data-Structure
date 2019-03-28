const int maxSize=100;
template<class T>
struct SLinkNode{
	T data;
	int link;
}; 
template<class T>
class StaticList{
	SLinkNode<T> elem[maxSize];
	int avi;
	public:
		void InitList();
		int Length();
		int Search(T x);
		int Locate(int i);
		bool Append(T x);
		bool Insert(int i,T x);
		bool Remove(int i);
		bool IsEmpty();
		void input();
		void output();
}; 
template<class T>
void StaticList<T>::InitList(){
	elem[0].link=-1; avi=1;
	for(int i=1;i<maxSize-1;i++){
		elem[i].link=i+1;
	}
	elem[maxSize-1].link=-1;
}
template<class T>
int StaticList<T>::Length(){
	int p=elem[0].link; int i=0;
	while(p!=-1){
		p=elem[p].link;
		i++;
	}
	return i;
}
template<class T>
bool StaticList<T>::IsEmpty(){
	if(elem[0].link==-1) return true;
	return false;
} 
template<class T>
int StaticList<T>::Search(T x){
	int p=elem[0].link;
	while(p!=-1){
		if(elem[p].data==x) break;
		p=elem[p].link;
	}
	return p;
}
template<class T>
int StaticList<T>::Locate(int i){
	if(i<0) return -1;
	if(i==0) return 0;
	int j=1,p=elem[0].link;
	while(p!=-1&&j<i){
		p=elem[p].link; j++;
	}
	return p;
}
template<class T>
bool StaticList<T>::Append(T x){
	if(avi==-1) return false;
	int q=avi;
	avi=elem[avi].link;
	elem[q].data=x; elem[q].link=-1;
	int p=0;
	while(elem[p].link!=-1) p=elem[p].link;
	elem[p].link=q;
	return true;
}
template<class T>
bool StaticList<T>::Insert(int i,T x){
	int p=Locate(i);
	if(p==-1) return false;
	int q=avi;
	avi=elem[avi].link;
	elem[q].data=x;
	elem[q].link=elem[p].link;
	elem[p].link=q;
	return true;	
}
template<class T>
bool StaticList<T>::Remove(int i){
	int p=Locate(i-1);
	if(p==-1) return false;
	int q=elem[p].link;
	elem[p].link=elem[q].link;
	elem[q].link=avi;
	avi=q;
	return true;
}
template<class T>
void StaticList<T>::input(){
	int n,q,value;
	InitList();
	elem[0].link=avi;
	cout<<"创建一个单链表，输入元素个数：";
	cin>>n;
	while(1){
		if(n<maxSize) break;
		else cout<<"输入超出范围，请重新输入：";
		cin>>n;
	}
	cout<<"输入 "<<n<<" 个元素: "<<endl; 
	for(int i=0;i<n;i++){
		q=avi;
		avi=elem[avi].link;
		cin>>value;
		elem[q].data=value;
	}
	elem[q].link=-1;
}
template<class T>
void StaticList<T>::output(){
	int i=1;
	cout<<"输出静态链表中的元素："<<endl;
	int p=elem[0].link;
	while(p!=-1){
		cout<<"第"<<i++<<"个元素： "<<elem[p].data<<endl; 
		p=elem[p].link;
	}
} 