#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010; 
struct Node{
	int address;
	int data;
	int next;
	int order;
}node[maxn];
bool cmp(Node a,Node b){
	return a.order<b.order;
}
int main(){
	for(int i=0;i<maxn;i++){
		node[i].order = maxn;
	}
	
	int begin,n,k;
	scanf("%d%d%d",&begin,&n,&k);
	
	for(int j=0;j<n;j++){
		int address;
		scanf("%d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address = address;
	}
	
	int count = 0;
	int p = begin;
	while(p!=-1){
		node[p].order = count++;
		p = node[p].next;
	}
	
	sort(node,node+maxn,cmp);//静态单链表建成
	
	for(int i=1;i<=n/k;i++){
		for(int j=(i*k)-1;j>(i-1)*k;j--){
			printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address);
		}
		if(i<n/k){
			printf("%05d %d %05d\n",node[(i-1)*k].address,node[(i-1)*k].data,node[(i+1)*k-1].address);
		}else{
			printf("%05d %d %05d\n",node[(i-1)*k].address,node[(i-1)*k].data,node[i*k].address);
			for(int q=i*k;q<n;q++){
				if(q!=n-1) printf("%05d %d %05d\n",node[q].address,node[q].data,node[q].next);
				else{
					printf("%05d %d ",node[q].address,node[q].data);
					printf("-1\n");
				}  
				
			}
		}	
	} 
	 
	return 0;
} 
