template<class T>
void BubbleSort(dataList<T> &L,int n){    //基本起泡排序
	Element<T> temp;
	cout<<"基本冒泡排序！"<<endl;
	for(int i=1;i<n;i++)
		for(int j=n-1;j>=i;j--)
			if(L[j-1]>L[j]){
				temp=L[j-1];  L[j-1]=L[j];  L[j]=temp;
			}
}
template<class T>
void BubbleSort_promote(dataList<T> &L,int n){
	cout<<"改进的气泡排序算法！"<<endl;
	Element<T> temp;
	bool exchange;  int i,j;
	for(i=1;i<n;i++){
		exchange=false;
		for(j=n-1;j>=i;j--)
			if(L[j-1]>L[j]){
				temp=L[j-1];  L[j-1]=L[j]; L[j]=temp;
				exchange=true;
			}
		if(exchange==false) return ;
	}
}
template<class T>
void InsertSort(dataList<T> &L,const int left,const int right){    //直接插入排序
	Element<T> temp;  int i,j;
	for(i=left+1;i<=right;i++)
		if(L[i]<L[i-1]){
			temp=L[i]; j=i-1;
			do{
				L[j+1]=L[j]; j--;
			}while(j>=left&&temp<L[j]);
			L[j+1]=temp;
		}
}
template<class T>
void BinaryInsertSort(dataList<T> &L,const int left,const int right){  //折半插入排序
	cout<<"折半插入排序！"<<endl;
	Element<T> temp;   int i,low,high,middle,k;
	for(i=left+1;i<=right;i++){
		temp=L[i];  low=left;  high=i-1;
		while(low<=high){
			middle=(low+high)/2;
			if(temp<L[middle])  high=middle-1;
			else low=middle+1;
		}
		for(k=i-1;k>=low;k--) L[k+1]=L[k];
		L[low]=temp;
	}
}
template<class T>
void ShellSort(dataList<T> &L,const int left,const int right){      //希尔排序
	cout<<"希尔排序！"<<endl;
	int i,j,gap=right-left+1;
	Element<T> temp;
	do{
		gap=gap/3+1;
		for(i=left+gap;i<=right;i++)
			if(L[i]<L[i-gap]){
				temp=L[i]; j=i-gap;
				do{
					L[j+gap]=L[j];
					j=j-gap;
				}while(j>=left&&temp<L[j]);
				L[j+gap]=temp;
			}
	}while(gap>1);
}
template<class T>
void QuickSort(dataList<T> &L,const int left,const int right){   //快速排序
	if(left<right){
		int pivotpos=L.Partition(left,right);
		QuickSort(L,left,pivotpos-1);
		QuickSort(L,pivotpos+1,right);
	}
}
template<class T>
void QuickSort_Insert(dataList<T> &L,const int left,const int right){   //快速排序改进
	if(right-left<=M){
		InsertSort(L,left,right);
	}
	else{
		int pivotpos=L.Partition(left,right);
		QuickSort_Insert(L,left,pivotpos-1);
		QuickSort_Insert(L,pivotpos+1,right);
	}
}
template<class T>
void QuickSort_Insert2(dataList<T> &L,const int left,const int right){ //快速排序改进2
	if(right-left<=M) return;
	int pivotpos=L.Partition(left,right);
	QuickSort_Insert2(L,left,pivotpos-1);
	QuickSort_Insert2(L,pivotpos+1,right);
}
template<class T>
void HybridSort(dataList<T> &L,const int left,const int right){
	QuickSort_Insert2(L,left,right);
	InsertSort(L,left,right);
}
template<class T>
int Partition(dataList<T> &L,const int left,const int right){  //快速排序改进3
	int i=left,j=right-1;
	if(left<right){
		Element<T> pivot=L.median3(left,right);
		for(;;){
			while(i<j&&L[i]<pivot) i++;
			while(i<j&&pivot<L[j]) j--;
			if(i<j){
				L.Swap(L[i],L[j]); 
				i++;  j--;
			}
			else break;
		}
		if(L[i]>pivot){  L[right]=L[i];  L[i]=pivot;  }
	}
	return i;
}
template<class T>
void QuickSort_Insert3(dataList<T> &L,const int left,const int right){
	if(right-left<=5) return ;
	int pivotpos=Partition(L,left,right);
	QuickSort_Insert3(L,left,pivotpos-1);
	QuickSort_Insert3(L,pivotpos,right); 
}
template<class T>
void HybridSort2(dataList<T> &L,const int left,const int right){
	QuickSort_Insert3(L,left,right);
	InsertSort(L,left,right);
}
template<class T>
void QuickSort3(dataList<T> &L,const int left,const int right){  //三路划分快速排序
	 int i,j,k,p,q;
	 if(right<=left)  return; 
	 Element<T> pivot=L[right]; 
	 i=left-1;  j=right;  p=left-1;  q=right;
	 while(1){
		 while(L[++i]<pivot)  if(i==j) break;
		 while(pivot<L[--j])  if(j==i) break;
		 if(i>=j) break;
		 L.Swap(L[i],L[j]);
		 if(L[i]==pivot){ 
			 p++;  L.Swap(L[p],L[i]);
		 }
		 if(pivot==L[j]){
			 q--;  L.Swap(L[q],L[j]);
		 }
	 }
	 if(L[i]>L[right]){
		 L.Swap(L[i],L[right]);   k=right-1;
	 }
	 else k=right;
	 i++;
	 while(k>=q){  
		 if(i<=right){
		     L.Swap(L[k],L[i]);
		 }
		 i++;  k--;
	 }
	 for(k=left;k<=p;k++,j--){
		 if(j>=left){
		     L.Swap(L[k],L[j]);
		 }
	 }
	 QuickSort3(L,left,j);
	 QuickSort3(L,i,right);
}
template<class T>
void SelectSort(dataList<T> &L,const int left,const int right){   //选择排序
	cout<<"选择排序！"<<endl;
	for(int i=left;i<right;i++){
		int k=i;
		for(int j=i+1;j<=right;j++){
			if(L[j]<L[k]) k=j;
		}
		if(k!=i) L.Swap(L[i],L[k]);
	}
}
template<class T>
void HeapSort(MaxHeap<T> &H){    //堆排序
	cout<<"堆排序！"<<endl;
	for(int i=(H.Length()-2)/2;i>=0;i--){
		H.siftDown(i,H.Length()-1);
	}
	for(int i=H.Length()-1;i>=0;i--){
		H.Swap(0,i); H.siftDown(0,i-1);
	}
	cout<<H<<endl;
}
template<class T>
void TournamentSort(T a[],const int left,const int right){
	cout<<"锦标赛排序！"<<endl;
	int size=right-left+1;
	WinnerTree<T> WT(size);
	T *data;
	data=new T[size+1];
	int i;
	for(i=1;i<=size;i++) data[i]=a[i+left-1];
	WT.Initial(data,size);
	for(i=1;i<=size;i++){
		a[i+left-1]=WT.Winner(); 
		WT.Update();
		WT.rePlay(WT[1]);
		if(WT.Winner()==maxValue) break;
	}
	for(i=1;i<=size;i++) cout<<a[i]<<" ";
	cout<<endl;
	delete []data;          
}
template<class T>
void merge(dataList<T> &L1,dataList<T> &L2,const int left,const int mid,const int right){  //两路归并
	for(int k=left;k<=right;k++) L2[k]=L1[k];
	int s1=left,s2=mid+1,t=left;
	while(s1<=mid&&s2<=right)
		if(L2[s1]<=L2[s2]) L1[t++]=L2[s1++];
		else L1[t++]=L2[s2++];
	while(s1<=mid) L1[t++]=L2[s1++];
	while(s2<=right) L2[t++]=L2[s2++];
}
template<class T>
void mergeSort(dataList<T> &L,dataList<T> &L2,const int left,const int right){   //两路归并排序
	if(left>=right) return ;
	int mid=(left+right)/2;
	mergeSort(L,L2,left,mid);
	mergeSort(L,L2,mid+1,right);
	merge(L,L2,left,mid,right);
}
template<class T>
void improvedMerge(dataList<T> &L1,dataList<T> &L2,const int left,const int mid,const int right){
	int s1=left,s2=right,t=left,k;
	for(k=left;k<=mid;k++) L2[k]=L1[k];
	for(k=mid+1;k<=right;k++) L2[right-k+mid+1]=L1[k];
	while(t<=right)
		if(L2[s1]<=L2[s2]) L1[t++]=L2[s1++];
		else L1[t++]=L2[s2--];
}
template<class T>
void doSort(dataList<T> &L,dataList<T> &L2,const int left,const int right){
	if(left>=right) return ;
	if(right-left+1<M) return ;
	int mid=(left+right)/2;
	doSort(L,L2,left,mid);
	doSort(L,L2,mid+1,right);
	improvedMerge(L,L2,left,mid,right);
}
template<class T>
void mergeSort2(dataList<T> &L,dataList<T> &L2,const int left,const int right){
	doSort(L,L2,left,right);
	InsertSort(L,left,right);
}
template<class T>
void ListInsertSort(staticLinkedList<T> &L){
	cout<<"链表插入排序算法！"<<endl;
	L[0].key=maxValue;  L[0].link=1;  L[1].link=0;
	for(int i=2;i<=L.Length();i++){
		int p=L[0].link;
		int pre=0;
		while(L[p].key<=L[i].key){
			pre=p; p=L[p].link;
		}
		L[i].link=p; L[pre].link=i;
	}
}
template<class T>
int ListMerge(staticLinkedList<T> &L,int s1,int s2){
	int k=0,i=s1,j=s2;
	while(i!=0&&j!=0)
		if(L[i].key<=L[j].key){
			L[k].link=i;  k=i;  i=L[i].link;
		}
		else { L[k].link=j; k=j; j=L[j].link; }
	if(i==0) L[k].link=j;
	else L[k].link=i;
	return L[0].link;
}
template<class T>
int rMergeSort(staticLinkedList<T> &L,int left,int right){
	if(left>=right) return left; 
	int mid=(left+right)/2;
	return ListMerge(L,rMergeSort(L,left,mid),rMergeSort(L,mid+1,right));
}
template<class T>
void ReArrange(staticLinkedList<T> &L){
	cout<<"静态链表排序结果的重排！"<<endl;
	int i=1,head=L[0].link;  Elements<T> temp;
	while(head!=0){
		temp=L[head]; L[head]=L[i]; L[i]=temp;
		L[i].link=head;
		head=temp.link;
		i++;
		while(head<i&&head>0) head=L[head].link;
	}
	for(i=0;i<L.Length();i++) L[i].link=i+1;
	L[L.Length()].link=0;
}