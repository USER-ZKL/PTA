#include<cstdio>

const int maxn = 100010;
struct Node{
	int address;
	int next;
	char c;
}node[maxn];

int main(){
	int abegin,bbegin,n;
	scanf("%d%d%d",&abegin,&bbegin,&n);
	for(int i=0;i<n;i++){
		int address;
		char cq;
		int nextq;
		scanf("%d %c %d",&address,&cq,&nextq);
		node[address].address = address;
		node[address].c = cq;
		node[address].next = nextq;
	}
	
	
	for(int p = abegin;p!=-1;p=node[p].next){
		for(int q = bbegin;q!=-1;q=node[q].next){
			if(node[q].next == p){
				printf("%05d",p);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
	
} 
