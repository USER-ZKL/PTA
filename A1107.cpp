#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int hobbies[1010] = {0};
int father[1010] = {0};
int boolf[1010] = {0};
void init(){
	for(int i=1;i<=n;i++){
		father[i] = i;
	}
}
int findf(int x){
	int a = x;
	while(x!=father[x]){
		x = father[x];
	}
	while(a!=father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}
void uion(int a,int b){
	int fa = findf(a);
	int fb = findf(b);
	if(fa!=fb) father[fa] = fb;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;++i){
		int hs = 0;
		scanf("%d:",&hs);
		for(int j=0;j<hs;j++){
			int hn = 0;
			scanf("%d",&hn);
			if(hobbies[hn]== 0){
				hobbies[hn] = i;
			}
			uion(i,findf(hobbies[hn]));
		}
	}
	for(int k=1;k<=n;k++){
		boolf[findf(k)]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(boolf[i]!=0) ans++;
	}
	sort(boolf+1,boolf+n+1,cmp);
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++){
		printf("%d",boolf[i]);
		if(i<ans) printf(" ");
	}
} 
