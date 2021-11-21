#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100010;
bool isExit[10010] = {false};
struct Node{
	int address;
	int k;
	int next;
	int flag;
}node[maxn];

bool cmp(Node a,Node b){
	return a.flag < b.flag;
}

int main(){
	memset(isExit,false,sizeof(isExit));
	int begin,n;
	scanf("%d %d",&begin,&n);
	for(int i=0;i<maxn;i++){
		node[i].flag = 2*maxn;
	}
	for(int i=0;i<n;i++){
		int address;
		scanf("%d",&address);
		scanf("%d %d",&node[address].k,&node[address].next);
		node[address].address = address;
	}
	
	
	int countA =0,countB = 0;
	int p = begin;
	while(p!=-1){
		if(isExit[abs(node[p].k)]== false){
			isExit[abs(node[p].k)] = true;
			node[p].flag = countA++;
			
		}else{
			node[p].flag = maxn + countB;
			countB++; 
			
		}	
		p = node[p].next;
	}
	
	sort(node,node+maxn,cmp);
	int count = countA + countB;
	for(int i=0;i<count;i++){
		if(i!= countA-1 && i!= count - 1){
			printf("%05d %d %05d\n",node[i].address,node[i].k,node[i+1].address);
		}else{
			printf("%05d %d -1\n",node[i].address,node[i].k);
		}
	}
	
	for(int i=0;i<countA-1;i++){
		printf("%05d %d %05d\n",node[i].address,node[i].k,node[i+1].address);
	}
	printf("%05d %d -1\n",node[countA-1].address,node[countA-1].k);
	
	for(int q = countA;q<countA+countB-1;q++){
		printf("%05d %d %05d\n",node[q].address,node[q].k,node[q+1].address);
	}
	printf("%05d %d -1\n",node[countA+countB-1].address,node[countA+countB-1].k);
	
} 
