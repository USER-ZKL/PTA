#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
struct node{
	int levl;
	vector<int> children;
};
node tree[110];
int maxnum = 0;
int dep[110];
int gen = 0;
int n,m;
void bfs(){
	queue<node> q;
	tree[1].levl = 1;
	q.push(tree[1]);
	while(!q.empty()){
		node nw = q.front();
		dep[nw.levl]++;
		q.pop();
		for(int i=0;i<nw.children.size();++i){
			tree[nw.children[i]].levl = nw.levl+1;
			q.push(tree[nw.children[i]]);
		}
	}	
}
void findmaxnum(){
	for(int i=1;i<=n;i++){
		if(dep[i]>maxnum){
			maxnum = dep[i];
			gen = i;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;++i){
		int family = 0,cds = 0;
		scanf("%d %d",&family,&cds);
		for(int j = 0;j<cds;++j){
			int child =0;
			scanf("%d",&child);
			tree[family].children.push_back(child);
		}
	}
	bfs();	
	findmaxnum();
	printf("%d %d",maxnum,gen);
}
