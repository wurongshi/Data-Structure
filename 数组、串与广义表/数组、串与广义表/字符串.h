class AString{
	public:
		AString(int sz=defaultSize);
		AString(const char *init);
		AString(const AString &ob);
		~AString(){ delete []ch; }
		int Length()const{ return curLength; }
		AString operator()(int pos, int len);
		int operator==(AString& ob)const{ return strcmp(ch,ob.ch)==0; }
		int operator!=(AString &ob)const{ return strcmp(ch,ob.ch)!=0; }
		int operator!()const{ return curLength==0; }
		AString &operator=(const AString &ob);
		AString &operator+=(const AString &ob);
		char &operator[](int i);
		int fastFind(AString &pat,int k)const;
		void getNext();
		friend istream &operator >>(istream &in,AString &s);
		friend ostream &operator <<(ostream &out,AString &s);
	private:
	    char *ch;
		int *next;
		int curLength;
		int maxSize; 
}; 
AString::AString(int sz){
	maxSize=sz;
	next=new int[maxSize+1];
	ch=new char[maxSize];
	if(ch==NULL){
		cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl; 
		exit(1); 
	}
	curLength=0; ch[0]='\0';
}
AString::AString(const char *init){
	int len=strlen(init);
	maxSize=(len>defaultSize)?len:defaultSize;
	next=new int[maxSize+1];
	ch=new char[maxSize+1];
	if(ch==NULL){
		cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl;
		exit(1);
	}
	curLength=len;
	strcpy_s(ch,curLength,init);
}
AString::AString(const AString &ob){
	maxSize=ob.maxSize;
	ch=new char[maxSize+1];
	if(ch==NULL){
		cout<<"´æ´¢·ÖÅä´íÎó!"<<endl;
		exit(1);
	}
	curLength=ob.curLength;	
}
AString AString::operator()(int pos, int len){
	AString temp;
	if(pos<0||pos+len-1>maxSize||len<0){
		temp.curLength=len;  temp.ch[0]='\0';
	}
	else{
		if(pos+len-1>=curLength) len=curLength-pos;
		temp.curLength=len;
		for(int i=0,j=pos;i<len;i++,j++){
			temp.ch[i]=ch[i];
		}
		temp.ch[len]='\0';
		}
	return temp;
}
AString &AString::operator=(const AString &ob){
	if(&ob!=this){
	    delete []ch;
		ch=new char[ob.maxSize];
		if(ch==NULL){
			cout<<"´æ´¢·ÖÅä´íÎó£¡"<<endl;
			exit(1);
		}
		curLength=ob.curLength;
		strcpy_s(ch,curLength+1,ob.ch);
	}
	else cout<<"×Ö·û´®×ÔÉú¸³Öµ³ö´í£¡"<<endl;
	return *this;
}
AString &AString::operator+=(const AString &ob){
	char *temp=ch;
	int n=curLength+ob.curLength;
	int m=(maxSize>=n)?maxSize:n;
	ch=new char[m];
	if(ch==NULL){
		cout<<"´æ´¢·ÖÅä´íÎó£¡";
		exit(1); 
	}
	maxSize=m; curLength=n;
	strcpy_s(ch,n+1,temp);
	strcat_s(ch,n+1,ob.ch);
	delete []temp; return *this;
}
char &AString::operator[](int i){
	if(i<0||i>=curLength){
		cout<<"×Ö·û´®ÏÂ±ê³¬½ç£¡"<<endl;
		exit(1);
	}
	return ch[i];
}
istream &operator >>(istream &in,AString &s){
	int i,n=0; char c;
	cout<<"ÇëÊäÈë×Ö·û´®³¤¶È:  ";
	in>>n;
	if(n>=s.maxSize){
	    cout<<"×Ö·û´®³¤¶È³¬ÏÞ£¡"<<endl; exit(1);
	}
	for(i=0;i<n;i++){
		in>>c;
		s.ch[i]=c;
	}
	s.ch[i]='\0';
	s.curLength=n;
	return in;
}
ostream &operator <<(ostream &out,AString &s){
	for(int i=0;i<s.curLength;i++){
		out<<s.ch[i];
	}
	out<<endl;
	return out;
}
void AString::getNext(){
	int j=0,k=-1,lengthP=curLength;
	next[0]=-1;
	while(j<lengthP){
		if(k==-1||ch[j]==ch[k]){
			j++; k++;
			next[j]=k;
		}
		else k=next[k];
	}
}
int AString::fastFind(AString &pat,int k)const{
	int posP=0,posT=k;
	int lengthP=pat.curLength;
	int lengthT=curLength;
	while(posP<lengthP&&posT<lengthT)
		if(posP==-1||pat.ch[posP]==ch[posT]){
			posP++;  posT++;
		}
		else posP=pat.next[posP];
	if(posP<lengthP){  cout<<"Æ¥ÅäÊ§°Ü£¡"<<endl;  return -1;  }
	else{ cout<<"Æ¥Åä³É¹¦£¬¿ªÊ¼Î»ÖÃÎª£º "<<posT-lengthP<<endl;  return posT-lengthP;  }
}