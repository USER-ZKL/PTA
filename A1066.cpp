#include<iostream>
using namespace std;
struct node{
	node(int d,int h,node *l,node *r):data(d),height(h),left(l),right(r){
	} 
	int data;
	int height;
	node *left;
	node *right;
};
int getheight(node* &root){
	if(!root) return 0;
	else return root->height;
}

void updataheight(node* &root){
	if(!root) return;
	root->height = max(getheight(root->left),getheight(root->right))+1;
}

int getBalance(node* &root){
	if(!root) return 0;
	return getheight(root->left) - getheight(root->right);
}
void R(node* &root){
	node* tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	updataheight(tmp);
	updataheight(root);
	root = tmp;
	
}
void L(node* &root){
	node* tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	updataheight(tmp);
	updataheight(root);
	root = tmp;
	
}



void insert(node* &root,int d){
	if(root == NULL){
		root = new node(d,1,NULL,NULL);
		return;
	}else{ 
		if(d < root->data){
			insert(root->left,d);
			updataheight(root);
			if(int h = getBalance(root)==2){
				if(getBalance(root->left)==1){
					R(root);
				}else if(getheight(root->left)==-1){
					L(root->left);
					R(root);
				}
			}
		} 
		else{
			insert(root->right,d);
			updataheight(root);
			if(getBalance(root)==-2){
				if(getBalance(root->right)==-1){
					L(root);
				}else if(getBalance(root->right)==1){
					R(root->right);
					L(root);
				}
			}	
		}			
	}
}
int main(){
	int n = 0;
	cin>>n;
	node *root = NULL;
	for(int i=0;i<n;i++){
		int d = 0;
		cin>>d;
		insert(root,d);
	}
	cout<<root->data;
} 
