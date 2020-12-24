#include <bits/stdc++.h>
using namespace std;

struct nut{
	int value;
	nut *next;
};
typedef nut *Node;


void inDanhSach(Node dau){
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


Node chendau(Node dau, int value){
	// tao nut moi
	Node nutmoi;
	nutmoi = new nut;
	nutmoi->value  = value;
	nutmoi->next = dau;
	return nutmoi;
}

Node nhapDanhSach(){
	Node dau;
	dau = NULL;
	int value;
	Node nutmoi,nuttam;
	do{
		cout << "Nhap gia tri cua nut, nhap 0 de ket thuc";
		cin >> value;
		
		if(value !=0){
			// tao ra 1 nut moi
			nutmoi = new nut;
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
	
	
	return dau;
}

int main(){
	Node danhsach;
	danhsach = nhapDanhSach();
	inDanhSach(danhsach);
	danhsach = chendau(danhsach,10);
	inDanhSach(danhsach);
}
