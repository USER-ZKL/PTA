#include<iostream>
#include<vector>
#include<array>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int data;
	int left;
	int right;
}; 
int n;
array<node,110>tree;
array<int,110> datas;
int pos = 0;
void creat(int index){
	if(index == -1) return;
	creat(tree[index].left);
	tree[index].data = datas.at(pos++);
	creat(tree[index].right);
}
int sum = 0;
void bfs(){
	queue<node> q;
	q.push(tree[0]);
	while(!q.empty()){
		node now = q.front();
		q.pop();
		cout<<now.data;
		sum++;
		if(sum<n) cout<<" ";
		if(now.left != -1) q.push(tree[now.left]);
		if(now.right !=-1) q.push(tree[now.right]);
		
	} 
}

int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		int l =0,r = 0;
		cin>>l>>r;
		tree[i].left = l;
		tree[i].right = r;
	}
	for(int j=0;j<n;++j){
		cin>>datas.at(j);
	}
	sort(datas.begin(),datas.begin()+n);
	creat(0);
	bfs();
}
