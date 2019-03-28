template<class T>
class bitSet{
	public:
		bitSet(int sz=DefaultSize);
		bitSet(const bitSet<T> &R);
		~bitSet(){ delete []bitVector; }
        void makeEmpty(){
        	for(int i=0;i<vectorSize;i++) bitVector[i]=0;
		}
		unsigned short getMember(const T x);
		void putMember(const T x,unsigned short v);
		bool addMember(const T x);
		bool delMember(const T x);
	//	bitSet &operator =(const bitSet<T> &R);
		bitSet operator +(const bitSet<T> &R);
		bitSet operator *(const bitSet<T> &R);
		bitSet operator -(bitSet<T> &R);
		bool Contains(const T x);
		bool subSet(bitSet<T> &R);
		bool operator ==(bitSet<T> &R);
		friend istream &operator >> <>(istream &in,bitSet<T> &R);
		friend ostream &operator << <>(ostream &out,bitSet<T> &R);
	private:
		int setSize;
		int vectorSize;
		unsigned short *bitVector;
};
template<class T>
bitSet<T>::bitSet(int sz):setSize(sz){
	assert(setSize>0);
	vectorSize=(setSize+15)>>4;
	bitVector=new unsigned short[vectorSize];
	assert(bitVector!=NULL);
	for(int i=0;i<vectorSize;i++) bitVector[i]=0;
}
template<class T>
bitSet<T>::bitSet(const bitSet<T> &R){
	setSize=R.setSize;
	vectorSize=R.vectorSize;
	bitVector=new unsigned short[vectorSize];
	assert(bitVector!=NULL);
	for(int i=0;i<vectorSize;i++){
		bitVector[i]=R.bitVector[i];
	}
}
template<class T>
unsigned short bitSet<T>::getMember(const T x){
	int ad=x/16, id=x%16;
	unsigned short elem=bitVector[ad];
	return ((elem>>(15-id))%2);
}
template<class T>
void bitSet<T>::putMember(const T x,unsigned short v){
	int ad=x/16, id=x%16;
	unsigned short elem=bitVector[ad];
	unsigned short temp=elem>>(15-id);  elem=elem<<(id+1);
	if(temp%2==0&&v==1) temp=temp+1;
	else if(temp%2==1&&v==0) temp=temp-1;
	bitVector[ad]=(temp<<(15-id)|elem>>(id+1));
}
template<class T>
bool bitSet<T>::addMember(const T x){
	assert(x>=0&&x<setSize);
	if(getMember(x)==0){
		putMember(x,1);
		return true;
	}
	return false;
}
template<class T>
bool bitSet<T>::delMember(const T x){
	assert(x>=0&&x<setSize);
	if(getMember(x)==1){
		putMember(x,0);
		return true;
	}
	return false;
} 
template<class T>
bitSet<T> bitSet<T>::operator +(const bitSet<T> &R){
	assert(vectorSize==R.vectorSize);
	bitSet<T> temp(setSize);
	for(int i=0;i<vectorSize;i++)
	    temp.bitVector[i]=bitVector[i]|R.bitVector[i];
	return temp; 
}
template<class T>
bitSet<T> bitSet<T>::operator *(const bitSet<T> &R){
	assert(vectorSize==R.vectorSize);
	bitSet<T> temp(setSize);
	for(int i=0;i<vectorSize;i++)
	    temp.bitVector[i]=bitVector[i]&R.bitVector[i];
	return temp;
}
template<class T>
bitSet<T> bitSet<T>::operator -(bitSet<T> &R){
	assert(vectorSize==R.vectorSize);
	bitSet<T> t(setSize);
	for(int i=0;i<vectorSize;i++){
		 t.bitVector[i]=bitVector[i]&!R.bitVector[i];
	}   
	return t;
}
template<class T>
bool bitSet<T>::Contains(const T x){
	assert(x>=0&&x<setSize);
	return (getMember(x)==1)?true:false;
}
template<class T>
bool bitSet<T>::subSet(bitSet<T> &R){
	assert(setSize==R.setSize);
	for(int i=0;i<setSize;i++)
	    if(bitVector[i]&!R.bitVector[i]) return false;
	return true;
}
template<class T>
bool bitSet<T>::operator ==(bitSet<T> &R){
	if(setSize!=R.setSize) return false;
	for(int i=0;i<setSize;i++)
	    if(bitVector[i]&!R.bitVector[i]) return false;
	return true;
}
template<class T>
istream &operator >>(istream &in,bitSet<T> &R){
	T x;
	cout<<"输入集合中的元素："<<endl;
	for(unsigned short i=0;i<R.setSize;i++){
		in>>x;
		R.putMember(i,x);
	}
	cout<<"输入完毕！"<<endl;
	return in;
}
template<class T>
ostream &operator <<(ostream &out,bitSet<T> &R){
	out<<"输出集合中的元素："<<endl; int i;
	for(i=0;i<R.setSize;i++){
		out<<R.getMember(i)<<' ';
	}
	out<<endl;
	return out;
}
