#include<iostream>
#include<vector>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
vector<int> datas;
vector<int> preorder;

int n;
node* creatree(int d,node **root){
	if(!(*root)){
		node *wn = new node;
		wn->data = d;
		wn->left = NULL;
		wn->right = NULL;
		*root = wn;
		return wn;
	}
	else{
		if(d < (*root)->data) (*root)->left = creatree(d,&(*root)->left);
		else (*root)->right = creatree(d,&(*root)->right);
	}
	return *root;
}
node* creamirrortree(int d,node **root){
	if(!(*root)){
		node *wn = new node;
		wn->data = d;
		wn->left = NULL;
		wn->right = NULL;
		*root = wn;
		return wn;
	}
	else{
		if(d >= (*root)->data) (*root)->left = creamirrortree(d,&(*root)->left);
		else (*root)->right = creamirrortree(d,&(*root)->right);
	}
	return *root;
}
void reverse(node *root){
	if(!root) return;
	reverse(root->left);
	reverse(root->right);
	node *tmp = NULL;
	tmp = root->left;
	root->left = root->right;
	root->right = tmp; 
}
void dfs(node *root){
	if(!root) return;
	preorder.push_back(root->data);
	dfs(root->left);
	dfs(root->right);
}
int sum = 0;
void postorder(node *root){
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
	sum+=1;
	if(sum<n) cout<<" ";
}
int main(){
	node *root = NULL;
	node *mirror = NULL;
	cin>>n;
	for(int i=0;i<n;++i){
		int d = 0;
		cin>>d;
		datas.push_back(d);
		creatree(d,&root);
		//creamirrortree(d,&mirror);
	}
	dfs(root);
	if(datas == preorder) {
		cout<<"YES"<<endl;
		postorder(root);
	}else {
		preorder.clear();
		//dfs(mirror);
		reverse(root);
		dfs(root);
		if(datas == preorder){
			cout<<"YES"<<endl;
			postorder(root);
		}else{
			cout<<"NO";
		}
	}
} 
