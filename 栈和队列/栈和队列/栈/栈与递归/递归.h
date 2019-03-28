long Factorial(long n){   //�׳� 
	if(n==0) return 1;
	else return n*Factorial(n-1);
} 
void Hanoi(int n,char A,char B,char C){   //��ŵ������ 
	if(n==1) cout<<"��"<<A<<"�Ƶ�"<<C<<endl;
	else{
		Hanoi(n-1,A,C,B);
		cout<<"��"<<A<<"�Ƶ�"<<C<<endl;
		Hanoi(n-1,B,A,C);
	}
} 
long Fib(long n){  //쳲������ݹ��㷨 
	if(n<=1) return n;
	else return Fib(n-1)+Fib(n-2);
} 
long FibIter(long n){  //쳲����������㷨 
	if(n<=1) return n;
	long twoback=0,oneback=1,current;
	for(int i=2;i<=n;i++){
		current=twoback+oneback;
		twoback=oneback;
		oneback=current;
	}
	return current;
} 
struct Node{
	long n;
	int tag;
	Node():n(0),tag(0){ }
}; 
long Fibnacci(long n){   //쳲������ǵݹ��㷨 
	SeqStack<Node> S; Node *w=new Node(); long sum=0;
	do{
		while(n>1){ w->n=n; w->tag=1; S.Push(*w); n--; }
		sum=sum+n;
		while(S.IsEmpty()==false){
			S.Pop(*w);
			if(w->tag==1){
				w->tag=2;
				S.Push(*w); n=w->n-2;
				break;
			}
		}
	}while(S.IsEmpty()==false);
	return sum; 
}