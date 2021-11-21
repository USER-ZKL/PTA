#include<cstdio>
#include<stdlib.h>
#include<queue>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
int n;
int inorder[40],post[40];
Node* creatree(int postL,int postR,int inL,int inR){
	if(postL > postR) return NULL;
	Node *root = (Node*)malloc(sizeof(Node));
	root->data = post[postR];
	int i = 0;
	for(;i<n;++i){
		if(inorder[i] == post[postR]) break;
	}
	int leftreenum = i-inL;
	int rightreenum = n-i-1;
	root->left = creatree(postL,postL+leftreenum-1,inL,i-1);
	root->right = creatree(postL+leftreenum,postR-1,i+1,inR);
	return root;	
}
void BFS(Node *root){
	queue<Node*> q;
	q.push(root);
	int num = 1;
	while(!q.empty()){
		Node *now = q.front();
		printf("%d",now->data);
		if(num < n) printf(" ");
		num++;
		q.pop();
		if(now->left) q.push(now->left);
		if(now->right) q.push(now->right);
	} 
	
	
	
} 

int main(){
	
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;++i){
		scanf("%d",&inorder[i]);
	}
	Node *root = creatree(0,n-1,0,n-1);
	BFS(root);
	return 0;
} 
