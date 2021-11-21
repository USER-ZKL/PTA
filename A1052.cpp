#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node{
	int address;
	int key;
	int next;
	int flag;
}node[maxn];

bool cmp(Node a,Node b){
	if(a.flag==0 || b.flag==0){
		return a.flag > b.flag;
	}
	return a.key < b.key;
}
int main(){
	int n,begin;
	scanf("%d%d",&n,&begin);
	
	for(int q=0;q<maxn;q++){
		node[q].flag = 0;
	}
	
	for(int i=0;i<n;i++){
		int address;
		scanf("%d",&address);
		scanf("%d%d",&node[address].key,&node[address].next);
		node[address].address = address;
	}
	
	int p = begin;
	int count = 0;
	while(p!=-1){
		node[p].flag = 1;
		p = node[p].next;
		count+=1;
	}
	
	sort(node,node+maxn,cmp);
	/*
	for(int m=0;m<n-1;m++){
		printf("%05d %d %05d\n",node[m].address,node[m].key,node[m].next);
	}*/
	
	for(int j=0;j<n-1;j++){
		node[j].next = node[j+1].address;
	}
	
	
	node[n-1].next = -1;
	printf("%d %05d\n",count,node[0].address);
	for(int p=0;p<n-1;p++){
		printf("%05d %d %05d\n",node[p].address,node[p].key,node[p].next);
	}
	printf("%05d %d ",node[n-1].address,node[n-1].key);
	printf("-1\n");
	return 0;
} 
