#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
struct node{
	int weight;
	vector<int> children;
};
node tree[110];
vector<vector<int> > paths;
vector<int> path;
int n,m,s,cnt = 0;
void dfs(int index,int sum){
	path.push_back(tree[index].weight);
	sum+=tree[index].weight;
	if(tree[index].children.empty()){
		
		if(sum == s) {
			cnt++;
			paths.push_back(path);
			/*
			for(int p=0;p<path.size();++p){
				printf("%d",path[p]);
				if(p<path.size()-1) printf(" ");
			}
			printf("\n");*/
		}
		return;
	}
	for(int i=0;i<tree[index].children.size();++i){
		dfs(tree[index].children[i],sum);
		path.pop_back();
	}
	
	
}
int main(){
	scanf("%d %d %d",&n,&m,&s);
	for(int i=0;i<n;i++){
		int w = 0;
		scanf("%d",&w);
		tree[i].weight = w;	
	}
	for(int j=0;j<m;++j){
		int f = 0;
		int t = 0;
		scanf("%d %d",&f,&t);
		for(int q = 0;q<t;++q){
			int cn = 0;
			scanf("%d",&cn);
			tree[f].children.push_back(cn);
		}
		sort(tree[f].children.begin(),tree[f].children.end(),
			[](int w,int y){return tree[w].weight > tree[y].weight;}
		);
	}
	dfs(0,0);
	for(int k=0;k<paths.size();++k){
		for(int l=0;l<paths[k].size();++l){
			cout<<paths[k][l];
			if(l<paths[k].size()-1) cout<<" ";
		}
		if(k<paths.size()-1) cout<<endl;
	}

} 
