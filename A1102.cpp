#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
struct Node{
	int data;
	int left;
	int right;
};
Node nodes[15];
int n;
int check[15] = {0};
int findroot(){
	int root;
	for(int i=0;i<n;++i){
		if(nodes[i].left != -1) check[nodes[i].left] = 1;
		if(nodes[i].right != -1) check[nodes[i].right] = 1;
	}
	for(int i=0;i<n;++i){
		if(check[i] == 0) root = i;
	}
	return root;
}
void BFS(int root){
	
	queue<Node> q;
	q.push(nodes[root]);
	int num = 0;
	while(!q.empty()){
		Node nw = q.front();
		q.pop();
		printf("%d",nw.data);
		num++;
		if(num < n) printf(" ");
		if(nw.right != -1) q.push(nodes[nw.right]);
		if(nw.left != -1) q.push(nodes[nw.left]);	
	}	
}
void inorder(int root){
	int num = 0;
	stack<Node> st;
	while(root != -1 || !st.empty()){
		while(root!=-1){
			st.push(nodes[root]);
			root = nodes[root].right;
		}
		if(!st.empty()){
			Node nw = st.top();
			st.pop();
			printf("%d",nw.data);
			num++;
			if(num<n) printf(" ");
			root = nw.left;
		}
	}
	
	
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		char l,r;
		getchar();
		scanf("%c %c",&l,&r);
		nodes[i].data = i;
		if(l!='-'){
			nodes[i].left = l-'0';
		}else nodes[i].left = -1;
		if(r!='-'){
			nodes[i].right = r-'0';
		}else nodes[i].right = -1;
	}
	int root = findroot();
	BFS(root);
	printf("\n");
	inorder(root);
} 
