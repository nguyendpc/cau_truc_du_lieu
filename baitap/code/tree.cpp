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

void mocNut(Node *&root, int x){
	if(root == NULL){
		root = new Node;
		root->info = x;
		root->left = NULL;
		root->right = NULL;
	}else{
		if( root->info >= x ){
			mocNut(root->left,x);
		}else{
			mocNut(root->right,x);
		}
	}
}

void taoCay(Node *&root){
	int x;
	do{
		cout << "Nhap gia tri: ";
		cin >> x;
		if(x != 0){
			mocNut(root,x);
		}
	}while(x != 0);
}

void duyetLNR(Node *root){
	if(root != NULL){
		duyetLNR(root->left);
		cout << root->info << " ";
		duyetLNR(root->right );
	}
}

Node *timX(Node *root, int x){
	if( root == NULL){
		return NULL;
	}
	if( root->info == x ){
		return root;
	}
	if(root->info >= x){
		timX(root->left ,x);
	}else{
		timX(root->right ,x);
	}
}

int main(){
	khoiTao(root);
	taoCay(root);
	duyetLNR(root);
	Node *tam;
	int X;
	cout << endl;
	cin >> X;
	tam = timX(root, X);
	if(tam == NULL){
		cout << "NULL";
	}else{
		cout << endl << tam->info ;
	}
	
}
