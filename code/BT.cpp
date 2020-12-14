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

void duyetLNR(Node *root){
	if(root != NULL){
		duyetLNR(root->left);
		cout << root->info << " ";
		duyetLNR(root->right );
	}
}

void duyetLRN(Node *root){
	if(root != NULL){
		duyetLRN(root->left);
		duyetLRN(root->right );
		cout << root->info << " ";
	}
}


int timX(Node *&root, int x, int y, int z ){
	if(root != NULL){
		if(root->info == x){
			Node *p;
			p = new Node;
			p->info = y;
			p->left = NULL;
			p->right = NULL;
			if( z == 'L'){
				root->left = p;
			}else if( z == 'R'){
				root->right = p;
			}
			return 0;
		}
		timX(root->left,x,y,z);
		timX(root->right ,x,y,z);
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
		
		timX(root,x,y,z);
		
	}
}



int main(){
	khoiTao(root);
	taoCay(root);
	duyetLNR(root);
	cout << endl;
	duyetLRN(root);
}
