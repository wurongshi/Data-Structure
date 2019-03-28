template<class T>
class WinnerTree{
public:
	WinnerTree(int TreeSize=20):maxSize(TreeSize),n(0){ t=new int[TreeSize];  }
	~WinnerTree(){ delete []t;  }
	bool Initial(T a[],int size);  //初始化
	bool rePlay(int i);
	void Update(){  e[t[1]]=maxValue;  }
	int Winner()const{  return (n!=0)? e[t[1]]:0;  }   //取最终胜利者
	int Winner(int i)const{ return (i<n)? t[i]:0;  }  //取第i个胜利者
	int Winner(int a,int b){  return (e[a]<=e[b])? a:b;  }  //取a、b中的胜利者
	int &operator [](int i){ return t[i]; }
	T getE(int i){ return e[i]; }
private:
	int maxSize;  //允许的最大选手数
	int n;        //当前的选手数
	int lowExt;   //最远层外部结点的个数
	int offset;   //2^(s+1) -1^
	int *t;         //内部结点编号
	T *e;         //外部结点
	void Play(int k,int le,int re);
};
template<class T>
bool WinnerTree<T>::Initial(T a[],int size){
	if(size>maxSize||size<2) return false;
	n=size; e=a;
	int i,s;
	for(s=1;2*s<=n-1;s+=s);
	lowExt=2*(n-s); offset=2*s-1;
	for(i=2;i<=lowExt;i+=2)
		Play((offset+i)/2,i-1,i);
	
	if(n%2==0) i=lowExt+2;
	else{
		Play(n/2,t[n-1],lowExt+1);
		i=lowExt+3;
	}
	for(;i<=n;i+=2)
		Play((i-lowExt+n-1)/2,i-1,i);
	return true;
}
template<class T>
void WinnerTree<T>::Play(int k,int lc,int rc){
	t[k]=Winner(lc,rc);
	while(k>1&&k%2!=0){
		t[k/2]=Winner(t[k-1],t[k]);
		k/=2;
	}
}
template<class T>
bool WinnerTree<T>::rePlay(int i){
	if(i<=0||i>n)  return false;
	int k,lc,rc;
	if(i<=lowExt){
		k=(offset+i)/2;
		lc=2*k-offset; rc=lc+1;
	}
	else{
		k=(i-lowExt+n-1)/2;
		if(2*k==n-1){ lc=t[2*k];  rc=i; }
		else{ lc=2*k+lowExt-n+1;  rc=lc+1; }
	}
	t[k]=Winner(lc,rc);
	k/=2;
	for(;k>=1;k/=2){
		if(2*k==n-1) 
			t[k]=Winner(t[2*k],lowExt+2*k+2-n);
		else t[k]=Winner(t[2*k],t[2*k+1]);
	}
	return true;
}