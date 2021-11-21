#include<vector>
#include<iostream>
#include<array>
using namespace std;
int n;
array<int,110> source;
array<int,110> part;
array<int,110> temp;
void insert_sort(){	
	bool flag = false;
	int i=2;
	for(;i<=n;i++){	
		int tmp = temp[i],j = i;
		while(j>1 && tmp<temp[j-1]){
			temp[j] = temp[j-1];
			j--;
		}
		temp[j] = tmp;
		if(temp == part){
			cout<<"Insertion Sort"<<endl; 
			flag = true;
			break;
		} 
	}	
	if(flag){
		i++;
		int tmp = temp[i],j = i;
		while(j>1 && tmp<temp[j-1]){
			temp[j] = temp[j-1];
			j--;
		}
		temp[j] = tmp;
		for(int q=1;q<=n;q++){
			cout<<temp[q];
			if(q<n) cout<<" ";
		}
	}
	
}
void upAdjust(int i){
	int tmp = source[i];
	for(;tmp>source[i/2]&&i>1;i/=2){
		source[i/2] = source[i];
	}
	source[i] = tmp;
}
void downAdjust(int parent,int size){
	int child = 0;
	int tmp = source[parent];
	for(;parent*2<=size;parent=child){
		child = parent*2;
		if(child!=size){
			if(source[child] < source[child+1])
				child++;
		}
		if(tmp > source[child]) break;
		else{
			source[parent] = source[child];
		}
	}
	source[parent] = tmp;
}
void creatheap(){
	for(int i=n/2;i>=1;i--){
		downAdjust(i,n);
	}	
}

void heap_sort(){
	bool flag = false;
	creatheap();
	int i=n;
	for(;i>1;i--){
		int tmp = source[1];
		source[1] = source[i];
		source[i] = tmp;
		downAdjust(1,i-1);
		if(source == part){
			cout<<"Heap Sort"<<endl;
			flag = true;
			break;
		}
	}
	if(flag){
		i--;
		int tmp = source[1];
		source[1] = source[i];
		source[i] = tmp;
		downAdjust(1,i-1);
		for(int q=1;q<=n;q++){
			cout<<source[q];
			if(q<n) cout<<" ";
		}
	}
	
}

int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int d = 0;
		cin>>d;
		source.at(i) = d;
	}
	temp = source;
	for(int i=1;i<=n;++i){
		int d = 0;
		cin>>d;
		part.at(i)=d;
	}
	heap_sort();
	insert_sort();	
} 
