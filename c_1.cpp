#include <bits/stdc++.h>
using namespace std;

struct nut{
	int value;
	nut *next;
};
typedef nut Node;
Node *danhsach;

void taoDanhSach( Node *&dau ){
	int value;
	Node *nuttam;
	do{
		cout << "Nhap gia tri cua nut, nhap 0 de ket thuc";
		cin >> value;
		
		if(value !=0){
			// tao ra 1 nut moi
			Node *nutmoi;
			nutmoi = new Node;
			nutmoi->value = value;
			nutmoi->next = NULL;
			// tao xong
			
			if(dau == NULL ){
				dau = nutmoi;
			}else{
				nuttam->next = nutmoi;
			}
			nuttam = nutmoi;
		}
		
	}while(value !=0);
}

void inDanhSach(Node *dau){
	if(dau == NULL){
		cout << "danh sach rong!!!";
	}else{
		while(dau != NULL){
			cout << dau->value  << "\t";
			dau = dau->next; 
		}
	}
	cout << endl;
}

void chenDau(Node *&dau,int value){
	Node *nutmoi;
	nutmoi = new Node;
	nutmoi->value = value;
	nutmoi->next = dau;
	
	dau = nutmoi;
	
}

void daoNguoc(Node *&dau) {
	Node *p, *q;
	q = NULL; p = NULL;
	while(dau != NULL) {
		p = dau;
		dau = dau->next;
		p	->next = q;
		q = p;
	}
	dau = p;
}


void daoNguocTaoDSMoi(Node *&dau) {
	Node *p, *danhsachmoi;
	danhsachmoi = NULL;
	p = dau;
	while(p != NULL) {
		chenDau(danhsachmoi, p->value);
		p = p->next;
	}
	dau = danhsachmoi;
}

int main(){
	// khoi tao 1 nut rong
	danhsach = NULL;
	// tao danh sach lien ket don
	taoDanhSach(danhsach);
	// in danh sach
	inDanhSach(danhsach);
	//dao nguoc danh sach
//	daoNguocTaoDSMoi(danhsach);
	daoNguoc(danhsach);
	// in danh sach
	inDanhSach(danhsach);
	
}
