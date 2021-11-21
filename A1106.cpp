#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
vector<int> tree[100010];
int n = 0;
double p,r;
int mindep = 100010;
int cnt = 0;
void dfs(int index,int dep){
	if(tree[index].empty()){
		if(dep < mindep){
			mindep = dep;
			cnt = 1;
		}else if(dep == mindep){
			cnt+=1;
		}
		return;
	}
	for(int i=0;i<tree[index].size();++i){
		dfs(tree[index][i],dep+1);
	}
}

int main(){
	scanf("%d %lf %lf",&n,&p,&r);
	for(int i=0;i<n;++i){
		int t = 0;
		scanf("%d",&t);
		for(int j=0;j<t;++j){
			int c =0;
			scanf("%d",&c);
			tree[i].push_back(c);
		}
	}
	dfs(0,1);
	r/=100;
	printf("%.4f %d",p*pow((1+r),mindep-1),cnt);
	
}
 
