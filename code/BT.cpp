#include <bits/stdc++.h>
using namespace std;

struct nut{
	int info;
	nut *left,*right;
};
typedef nut Node;
Node *root;

void khoiTao(Node *&root){
	root = NULL;
}


void timX(Node *&root, int x ){
	if(root != NULL){
		if(root->info != x){
			timX(root->left,x);
			timX(root->right,x);
		}
	}
}

void mocNut(Node *&root, int y, char z){
	if(root == NULL){
		root = new Node;
		root->info = y;
		root->left = NULL;
		root->right = NULL;
	}else{
		if( z == 'L'){
			mocNut(root->left,y,z);
		}else if( z == 'R'){
			mocNut(root->right,y,z);
		}
	}
}

void taoCay(Node *&root){
	int N,r,x,y;
	char z;
	cin >> N;
	cin >> r;
	root = new Node;
	root->info = r;
	root->left = NULL;
	root->right = NULL;
	for(int i=0; i<N - 1;i++){
		cin >> x;
		cin >> y;
		cin >> z;
		timX(root,x);
		mocNut(root,y,z);
	}
}

void duyetLNR(Node *root){
	if(root != NULL){
		duyetLNR(root->left);
		cout << root->info << " ";
		duyetLNR(root->right );
	}
}


int main(){
	khoiTao(root);
	taoCay(root);
	duyetLNR(root);
	
}
