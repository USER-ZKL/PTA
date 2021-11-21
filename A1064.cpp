#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
array<int,1010> datas;
array<int,1010> tree;
int n,pos = 1;
void dfs(int index){
	if(index > n) return;
	dfs(index*2);
	tree.at(index) = datas.at(pos++);
	dfs(index*2+1);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		int d = 0;
		cin>>d;
		datas.at(i) = d;
	} 
	sort(datas.begin()+1,datas.begin()+n+1);
	dfs(1);
	int flag = true;
	for(int j=1;j<=n;++j){
		if(flag){
			flag = false;
		}else {
			cout<<" ";
		}
		cout<<tree.at(j);
	}
} 
