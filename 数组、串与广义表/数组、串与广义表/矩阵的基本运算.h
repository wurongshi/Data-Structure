template<class T>
struct Trituple{
	int row,col;
	T value;
	Trituple<T> &operator =(Trituple<T> &x){
		row=x.row; col=x.col;  value=x.value;
		return *this;
	}
}; 
template<class T>
class SparseMatrix{
	
	public:
		void output();
		friend ostream& operator<< <>(ostream &out, SparseMatrix<T> &M);
	    friend istream& operator>> <>(istream &in,SparseMatrix<T> &M);
		SparseMatrix(int maxSz=DefaultSize);
		SparseMatrix(SparseMatrix<T> &x);
		~SparseMatrix(){  delete []smArray;  }
		SparseMatrix<T> &operator =(SparseMatrix<T> &x);
		SparseMatrix<T> Transpose();   //矩阵的转置 
		SparseMatrix<T> Add(SparseMatrix<T> &b);   //矩阵的相加
		SparseMatrix<T> Multiply(SparseMatrix<T> &b);   //矩阵相乘 
	
		int Rows,Cols,Terms;
		Trituple<T> *smArray;
		int maxTerms;
};
template<class T>
SparseMatrix<T>::SparseMatrix(int maxSz):maxTerms(maxSz){
	if(maxSz<1){
		cout<<"矩阵初始化值错误！"<<endl;
		return ;
	}
	smArray=new Trituple<T>[maxSz];
	if(smArray==NULL){
		cout<<"存储分配错误！ "<<endl;
		return ; 
	}
	Rows=Cols=Terms=0;
}
template<class T>
SparseMatrix<T>::SparseMatrix(SparseMatrix<T> &x){
	Rows=x.Rows;  Cols=x.Cols; Terms=x.Terms;
	maxTerms=x.maxTerms;
	smArray=new Trituple<T>[maxTerms];
	if(smArray==NULL){
		cout<<"存储分配错误！"<<endl;
		return ;
	}
	for(int i=0;i<Terms;i++) smArray[i]=x.smArray[i];
}
template<class T>
ostream &operator <<(ostream &out,SparseMatrix<T> &M){
	out<<"rows="<<M.Rows<<endl;
	out<<"cols="<<M.Cols<<endl;
	out<<"Nonzero terms="<<M.Terms<<endl;
	for(int i=0;i<M.Terms;i++){
		out<<"M["<<M.smArray[i].row<<"]["<<M.smArray[i].col<<"]="<<M.smArray[i].value<<endl;
	}
	return out;
}
template<class T> 
istream &operator >>(istream &in,SparseMatrix<T> &M){
	cout<<"Enter number of rows,cols and terms:"<<endl;
	in>>M.Rows>>M.Cols>>M.Terms;
	if(M.Terms>M.maxTerms){
		cout<<" Number of terms overflow!"<<endl; 
	    exit(1);
	}
	for(int i=0;i<M.Terms;i++){
		cout<<"Enter row,col and value of term:"<<endl;
		in>>M.smArray[i].row>>M.smArray[i].col>>M.smArray[i].value;
	}
	return in;
}
template<class T>
SparseMatrix<T> &SparseMatrix<T>:: operator =(SparseMatrix<T> &x){
	Rows=x.Rows;  Cols=x.Cols; Terms=x.Terms;
	maxTerms=x.maxTerms;
	smArray=new Trituple<T>[maxTerms];
	if(smArray==NULL){
		cout<<"存储分配错误！"<<endl;
		exit(1);
	}
	for(int i=0;i<Terms;i++) smArray[i]=x.smArray[i];
	return *this;
}
template<class T>
SparseMatrix<T> SparseMatrix<T>::Transpose(){
	SparseMatrix<T> b(maxTerms);
	b.Rows=Cols;   b.Cols=Rows; 
	b.Terms=Terms;
	if(Terms>0){
		int i,k,CurrentB=0;
		for(k=0;k<Cols;k++){
			for(i=0;i<Terms;i++){
				if(smArray[i].col==k){
					b.smArray[CurrentB].row=k;
					b.smArray[CurrentB].col=smArray[i].row;
					b.smArray[CurrentB].value=smArray[i].value;
					CurrentB++;
				}
			}
		}
	}
	return b;
} 
template<class T>
SparseMatrix<T> SparseMatrix<T>::Add(SparseMatrix<T> &b){
	SparseMatrix<T> Result; 
	Result.Rows=Rows;  Result.Cols=Cols;
	if(Rows!=b.Rows||Cols!=b.Cols){
		cout<<"Incompatible matrices!"<<endl;
		return Result;
	}
	int i=0,j=0,index_a,index_b;  Result.Terms=0;
	while(i<Terms&&j<b.Terms){
		index_a=Cols*smArray[i].row+smArray[i].col;
		index_b=Cols*b.smArray[j].row+b.smArray[j].col;
		if(index_a<index_b){
			Result.smArray[Result.Terms]=smArray[i];
			i++;
		}
		else if(index_a>index_b){
			Result.smArray[Result.Terms]=b.smArray[j];
			j++;
		}
		else{
			Result.smArray[Result.Terms]=smArray[i];
			Result.smArray[Result.Terms].value=smArray[i].value+b.smArray[i].value;
			i++;  j++;
		}
		Result.Terms++;
	}
	for(;i<Terms;i++){
		Result.smArray[Result.Terms]=smArray[i];
		Result.Terms++;
	}
	for(;j<b.Terms;j++){
		Result.smArray[Result.Terms]=b.smArray[j];
		Result.Terms++;
	}
	return Result;
}
template<class T>
SparseMatrix<T> SparseMatrix<T>::Multiply(SparseMatrix<T> &b){
	SparseMarix<T> Result; 
	Result.Rows=Rows;  Result.Cols=b.Cols;
	if(Cols!=b.Rows){
		cout<<"Incompatible matrices!"<<endl;
		return Result;
	}
	if(Terms==maxTerms||b.Terms=b.maxTerms){
		cout<<"One additional space in a or b needed!"<<endl;
		return Result;
	}
	int *rowSize=new int[b.Rows];
	int *rowStart=new int[b.Rows+1];
	T *temp=new T[b.Cols];   //暂存每一行计算结果
	int i,Current,lastInResult,RowA,RowB,ColB;
	for(i=0;i<b.Rows;i++) rowSize[i]=0;
	for(i=0;i<b.Terms;i++) rowSize[b.smArray[i].row]++; //计算各行非0元素的个数
	rowStart[0]=0; 
	for(i=1;i<=b.Rows;i++)
		rowStart[i]=rowStart[i-1]+rowSize[i-1];
	Current=0;  lastInResult=-1;
	while(Current<Terms){
		RowA=smArray[Current].row;
		for(i=0;i<b.Cols;i++) temp[i]=0;
		while(Current<Terms){
			ColA=smArray[Current].col;
			for(i=rowStart[ColA];i<rowStart[ColA+1];i++){
				ColB=b.smArray[i].col;
				temp[ColB]+=smArray[Current].value*b.smArray[i].value;
			}
			Current++;
		}
		for(i=0;i<b.Cols;i++)
			if(temp[i]!=0){
				lastInResult++;
				Result.smArray[lastInResult].row=RowA;
				Result.smArray[lastInResult].col=i;
				Result.smArray[lastInResult].value=temp[i];
			}
	}
	Result.Rows=Rows; Result.Cols=b.Cols;
	Result.Terms=lastInResult+1;
	delete []rowSize;  delete []rowStart;  delete []temp;
	return Result;
}
/*template<class T>
void SparseMatrix<T>::output(){
	cout<<"rows="<<Rows<<endl;
	cout<<"cols="<<Cols<<endl;
	cout<<"Nonzero terms="<<Terms<<endl;
	for(int i=0;i<Terms;i++){
		cout<<"M["<<smArray[i].row<<"]["<<smArray[i].col<<"]="<<smArray[i].value<<endl;
	}
} */
