#include<cstdio>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
};
int n;
int pre[40],inorder[40]; 

Node* creatree(int preL,int preR,int inL,int inR){
	if(preL > preR) return NULL;
	int r = pre[preL];
	Node *root = new Node;
	root->data = r;
	int k;
	for(int i=0;i<n;i++){
		if(inorder[i]==r){
			k = i;
			break;
		}
	}
	int leftnum = k - inL;
	root->left = creatree(preL+1,preL+leftnum,inL,k-1);
	root->right = creatree(preL+leftnum+1,preR,k+1,inR);
	return root;
}
int num = 0;
void postinversal(Node *root){
	if(!root) return;
	
	postinversal(root->left);
	postinversal(root->right);
	printf("%d",root->data);
	num++;
	if(num<n) printf(" ");
}
int main(){
	
	scanf("%d",&n);
	int preindex = 0,index = 0;
	stack<int> st;
	for(int i=0;i<2*n;i++){
		string s;
		cin>>s;
		if(s=="Push"){
			int x = 0;
			cin>>x;
			pre[preindex++] = x;
			st.push(x);
		}
		if(s=="Pop"){
			inorder[index++] = st.top();
			st.pop();
		}
	}
	Node *root = creatree(0,n-1,0,n-1);
	postinversal(root);
	return 0;
} 
