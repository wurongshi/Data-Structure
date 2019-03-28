 class Calculator{              //表达式计算 
 	public: 
 		Calculator(int sz):s(sz){}
		void Run();
		void Clear();
		void output();
	private:
		SeqStack<double> s;
		void AddOperand(double value){ s.Push(value); }
		bool Get2Operands(double &left,double &right);
		void DoOperator(char op);
		
 };
 void Calculator::DoOperator(char op){
 	double left,right,value;  bool result;
 	result=Get2Operands(left,right);
 	if(result==true)
 	    switch(op){
 	    	case'+':value=left+right;s.Push(value); break;
 	    	case'-':value=left-right;s.Push(value); break;
 	    	case'*':value=left*right;s.Push(value); break;
 	    	case'/':if(right==0.0){
 	    		cout<<"Divide by 0!"<<endl;
 	    		Clear();
			 }
			else {
				value=left/right; s.Push(value);
			}
			break;
		 }
	else Clear();
 }
 bool Calculator::Get2Operands(double& left,double& right){
 	if(s.IsEmpty()==true){
 		cout<<"缺少右操作数！"<<endl; 
 		return false;
	 }
	 s.Pop(right);
	 if(s.IsEmpty()==true){
	 	cout<<"缺少左操作数！"<<endl;
	 }
	 s.Pop(left);
	 return true;
 }
 void Calculator::Run(){
 	char ch; double newOperand;
 	while(cin>>ch,ch!='#'){
 		switch(ch){
 			case'+': case'-': case'*': case'/':
 				DoOperator(ch); break; 
 			default:cin.putback(ch);
 			  cin>>newOperand;
 			  AddOperand(newOperand);
		 }
	 }
 }
 void Calculator::output(){
 	double x;
 	s.Pop(x);
 	cout<<x; 
 }
 void Calculator::Clear(){ 
 	s.makeEmpty();
 }
 
 //----------------------------------------------------
 //----------------------------------------------------
 //----------------------------------------------------
 //-----将中缀表示转换为后缀表示-----------------------
 int icp(char ch){
 	if(ch=='#') return 0;
 	if(ch=='(') return 6;
	if(ch=='*'||ch=='/'||ch=='%') return 4;
	if(ch=='+'||ch=='-') return 2;
	if(ch==')') return 1; 
	else return -1;
 } 
 int isp(char ch){
 	if(ch=='#') return 0;
 	if(ch=='(') return 1;
	if(ch=='*'||ch=='/'||ch=='%') return 5;
	if(ch=='+'||ch=='-') return 3;
	if(ch==')') return 6; 
	else return -1;
 }
 bool isdigit(char ch){
 	if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) return true;
 	return false;
 }
 void postfix(){
 	SeqStack<char>s;
 	char ch='#',ch1,op;
 	s.Push(ch);
 	cin.get(ch);
 	while(s.IsEmpty()==false){
 		if(isdigit(ch)){ cout<<ch; cin.get(ch); }
		else{
			s.getTop(ch1);
			if(isp(ch1)<icp(ch)){
				s.Push(ch);
				cin.get(ch);
			}
			else if(isp(ch1)>icp(ch)){
				s.Pop(op);
				cout<<op;
			}
			else{
				s.Pop(op);
				if(op=='(') cin.get(ch);
			}
		}
	 }
 }