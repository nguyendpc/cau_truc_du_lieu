#include <bits/stdc++.h>
using namespace std;

struct nut {
	int giatri;
	struct nut *tiep;
};
typedef struct nut *Node;

// khoi tao 1 nut
Node taoMotNut(int value){
	Node nutmoi;
	nutmoi = (Node)malloc(sizeof(struct nut));
	nutmoi->giatri = value;
	nutmoi->tiep = NULL;	
	return nutmoi;
}

// them 1 nut vao cuoi danh sach
Node themVaoCuoi(Node danhsach, int value){
	Node nutmoi, nuttam;
	nutmoi = taoMotNut(value);
	if(danhsach == NULL){
		return nutmoi;
	}
	nuttam = danhsach;
	while(nuttam->tiep != NULL){
		nuttam = nuttam->tiep;
	}
	nuttam->tiep = nutmoi;
	return danhsach;
}

// them 1 nut vao dau danh sach
Node themVaoDau(Node danhsach, int value){
	Node nutmoi, nuttam;
	nutmoi = taoMotNut(value);
	if(danhsach == NULL){
		return nutmoi;
	}
	nutmoi->tiep = danhsach;
	return nutmoi;
}

// them 1 nut vao vi tri bat ky
Node themVaoViTriBatKy(Node danhsach, int value, int vitri){
	Node nutmoi, nuttam, danhsachtam;
	nutmoi = taoMotNut(value);
	if(danhsach == NULL || vitri == 0){
		return nutmoi;
	}
	danhsachtam = danhsach;
	int i = 1;
	while(danhsachtam != NULL &&  i <= vitri){
		if(i == vitri){
			nutmoi->tiep = danhsachtam->tiep;
			danhsachtam->tiep = nutmoi;
		}
		danhsachtam = danhsachtam->tiep;
		++i;
	}
	return danhsach;
}

// xoa o dau
Node xoaDau(Node danhsach){
	if(danhsach == NULL) return danhsach;
	else return danhsach->tiep;
}

// xoa o vi tri bat ky
Node xoaViTriBatKy(Node danhsach,int vitri){
	if(danhsach == NULL) return danhsach;
	if(vitri == 0) return xoaDau(danhsach);
	Node danhsachtam;
	danhsachtam = danhsach;
	int i = 1;
	while(danhsachtam != NULL && i<=vitri){
		if(i==vitri){
			danhsachtam->tiep = danhsachtam->tiep->tiep;
		}
		danhsachtam = danhsachtam->tiep;
		++i;
	}
	return danhsach;
}

// duyet danh sach
void duyetDanhSach(Node danhsach){
	if(danhsach == NULL){
		cout << "danh sach trong" << endl;
	}else{
		while(danhsach != NULL){
			cout << danhsach->giatri << " ";
			danhsach = danhsach->tiep;
		}
		cout << endl;
	}
}

// khoi tao danh sach tu ban phim, nhap phim 0 de ket thuc nhap danh sach
Node nhapdanhsach(Node danhsach){
	int x;
	do{
		cout<<"Nhap mot so nguyen, nhap 0 de dung: ";
		cin>>x;

		if(x!=0)
		{
			danhsach = themVaoCuoi(danhsach,x);
		}
	}while(x!=0);
	return danhsach;
}

int main(){
	Node danhsach, themNutDau;
	danhsach = NULL;
	danhsach = nhapdanhsach(danhsach);
	duyetDanhSach(danhsach);
	themNutDau = xoaViTriBatKy(danhsach,2);
	duyetDanhSach(themNutDau);
}

