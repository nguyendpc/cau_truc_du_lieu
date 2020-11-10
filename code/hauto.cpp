#include <bits/stdc++.h>
using namespace std;

struct stackToanTu{
	char toanTu;
	stackToanTu *tiep;
};
typedef stackToanTu Ngan;
Ngan *ngan;

struct danhSachHauTo{
	char giatri;
	danhSachHauTo *tiep;
};
typedef danhSachHauTo Node;
Node *dau;

void khoiTao(Node *&dau, Ngan *&ngan){
	dau = NULL;
	ngan = NULL;
}

void mocCuoi(Node *&dau, char value){
	
	// tao nut moi
	Node *nutmoi;
	nutmoi = new Node;
	nutmoi->giatri = value;
	nutmoi->tiep = NULL;
	// tao xong
	if(dau == NULL){
		dau = nutmoi;
	}
	else{
		Node *nuttam;
		nuttam = dau;
		while(nuttam->tiep != NULL){
			nuttam = nuttam->tiep;
		}
		nuttam->tiep = nutmoi;
	}
}

void pushStack(Ngan *&ngan, char toanTu){
	// tao nut moi
	Ngan *nutmoi;
	nutmoi = new Ngan;
	nutmoi->toanTu = toanTu;
	nutmoi->tiep = NULL;
	// tao xong
	if(ngan == NULL){
		ngan = nutmoi;
	}else{
		nutmoi->tiep = ngan;
		ngan = nutmoi;
	}
}

void popStack(Ngan *&ngan, Node *&dau ,int &thongbao){
	while( ngan!=NULL && ngan->toanTu != '('){
		mocCuoi(dau,ngan->toanTu);
		ngan = ngan->tiep;
	}	

	if(ngan == NULL){
		// thong bao bieuthuc sai, thuat toan dung
		thongbao = 1;
	}else{
		// xoa ngan chua '('
		ngan = ngan->tiep;
	}
	
}

int kiemTraToanTu(char kytu){
	if(kytu == '(') return 1;
	if(kytu == ')') return 2;
	if(kytu == '+') return 3;
	if(kytu == '-') return 3;
	if(kytu == '*') return 4;
	if(kytu == '/' || kytu == '%') return 4;

	return 0;
}

void duyetDS(Node *dau){
	while(dau != NULL){
		cout<< dau->giatri;
		dau = dau->tiep;
	}
	cout << endl;
}

void viewStack(Ngan *ngan){
	while(ngan != NULL){
		cout<< ngan->toanTu;
		ngan = ngan->tiep;
	}
	cout << endl;
}

void chuyenDoi(char bieuthuc[], Node *&dau, Ngan *&ngan){
	int i = 0;
	while(bieuthuc[i] != '\0' ){
		cout<< bieuthuc[i]<< endl;
		int giatri = kiemTraToanTu(bieuthuc[i]);
		
		// neu la toan hang thi luu vao danhSachHauTo
		if( giatri == 0 ){
			mocCuoi(dau,bieuthuc[i]);
		}
		
		// neu la ky tu '(' thi them vao top stackToanTu
		if(giatri == 1){
			pushStack(ngan, bieuthuc[i]);
		}
		
		// neu khac  ')' thi:
		// so sanh: toan hang moi & toan hang top 
		// neu toan hang moi <= toan hang top thi lay toan hang top bo vao danhSachHauTo, 
		// gan toan hang moi vao vi tri top
		// neu toan hang moi > toan hang top thi them vao stackToanTu
		if( giatri == 3 || giatri == 4){
			if(ngan == NULL){
				pushStack(ngan, bieuthuc[i]);
			}else{
				if(giatri <= kiemTraToanTu(ngan->toanTu)){
					mocCuoi(dau,ngan->toanTu);
					ngan->toanTu = bieuthuc[i];
				}else{
					pushStack(ngan, bieuthuc[i]);
				}
			}
			
		}
		
		// neu la  ')' thi:
		if(giatri == 2){
			int thongbao = 0;
			popStack(ngan,dau,thongbao);
			if(thongbao == 1)
			{
				ngan->toanTu = -1;
				break;
			}
		}
		++i;
		
	}
	
	// do cac toan tu con lai vao danhSachHauTo
	while(ngan!=NULL){
		if( ngan->toanTu == '(' ){
			break;
		}
		mocCuoi(dau, ngan->	toanTu );
		ngan = ngan->tiep; 
	}
}

int main(){
	khoiTao(dau,ngan);
	char bieuthuc[] = "A + ( B * C - D / E * F)";	

	chuyenDoi(bieuthuc,dau,ngan);
	if(ngan!=NULL){
		cout<< "bieu thuc sai" << endl;
		viewStack( ngan );
	}else{
		duyetDS(dau);
	}
	
}
