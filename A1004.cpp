#include<cstdio>
#include<vector>
using namespace std;
vector<int> tree[110];
int deps[110] = {0};
int n,m;
int maxdep = 0;
void dfs(int index,int dep){
	if(tree[index].empty()){
		maxdep = (dep > maxdep)? dep : maxdep;
		deps[dep]++;
		return;
	}
	for(int i=0;i<tree[index].size();++i){
		dfs(tree[index][i],dep+1);
	}
	
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i){
		int fami = 0,t = 0;
		scanf("%d %d",&fami,&t);
		for(int j=0;j<t;++j){
			int c = 0;
			scanf("%d",&c);
			tree[fami].push_back(c);
		}
	}
	dfs(1,1);
	int num = 0;
	for(int q=1;q<=maxdep;++q){
		printf("%d",deps[q]);
		num++;
		if(num<maxdep) printf(" ");
		
	}
}
