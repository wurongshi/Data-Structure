class UFSets{
	public:
		UFSets(int sz=DefaultSize);
		~UFSets(){ delete []parent;  }
		UFSets operator =(UFSets &R);
		void Union(int Root1,int Root2);
		int Find(int x);
		void WeightedUnion(int Root1,int Root2);
		int CollapsingFind(int i);
		friend istream &operator >>(istream &in,UFSets &R);
		friend ostream &operator <<(ostream &out,UFSets &R);
	private:
	    int *parent;
		int size; 
};
UFSets::UFSets(int sz){
	size=sz;
	parent=new int[size];
	for(int i=0;i<size;i++) parent[i]=-1;
}
int UFSets::Find(int x){
	while(parent[x]>=0) x=parent[x];
	return x;
}
void UFSets::Union(int Root1,int Root2){
	parent[Root1]+=parent[Root2];
	parent[Root2]=Root1;
}
UFSets UFSets:: operator =(UFSets &R){
	size=R.size;
	parent=new int[size];
	for(int i=0;i<size;i++) parent[i]=R.parent[i];
	return *this;
}
void UFSets::WeightedUnion(int Root1,int Root2){
	int r1=Find(Root1),r2=Find(Root2),temp;
	if(r1!=r2){
		temp=parent[r1]+parent[r2];
		if(parent[r2]<parent[r1]){
			parent[r1]=r2; parent[r2]=temp;
		}
		else{
			parent[r2]=r1; parent[r1]=temp;
		}
	}
}   
int UFSets::CollapsingFind(int i){
	int j;
	for(j=i;parent[j]>=0;j=parent[j]);
	
	while(i!=j){
		int temp=parent[i];
		parent[i]=j; i=temp;
	}	
	return j;
}                                                                             
istream &operator >>(istream &in,UFSets &R){
	int data;
	cout<<"输入并查集中元素："<<endl;
	for(int i=0;i<R.size;i++){
		cin>>data;
		R.parent[i]=data;
	}
	return in;
}
ostream &operator <<(ostream &out,UFSets &R){
	cout<<"输出并查集中元素："<<endl;
	for(int i=0;i<R.size;i++){
		out<<"[ "<<i<<" ] "<<R.parent[i]<<endl;;
	}
	out<<endl;
	return out;
}