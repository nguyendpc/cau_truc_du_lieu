#include <bits/stdc++.h>
using namespace std;

struct sinhvien{
	string hoten;
	string gioitinh;
	sinhvien *next;
};
typedef sinhvien Node;
Node *dau;

void inDanhSach(Node *dau){
	if(dau == NULL){
		cout << "danh sach rong!!!";
	}else{
		while(dau != NULL){
			cout << dau->hoten << "\t" << dau->gioitinh << endl;
			dau = dau->next; 
		}
	}
	cout << endl;
}

void taoDanhSach( Node *&dau ){
	string gioitinh;
	int soSv;
	string hoten;
	Node *nuttam;
	
	cout << "nhap so sinh vien cua lop: ";
	cin >> soSv;
	fflush(stdin);
	for(int i = 0;i<soSv;i++ ){
		cout << "nhap ho ten sinh vien: ";
		getline(cin,hoten);

		cout <<hoten<< "nhap gioi tinh sinh vien: ";
		getline(cin,gioitinh);

		// tao ra 1 nut moi
		Node *nutmoi;
		nutmoi = new Node;
		nutmoi->hoten = hoten;
		nutmoi->gioitinh = gioitinh;
		nutmoi->next = NULL;
		// tao xong
			
		if(dau == NULL ){
			dau = nutmoi;
		}else{
			nuttam->next = nutmoi;
		}
		nuttam = nutmoi;
		
	}
	

}

int main(){
	dau = NULL;
	taoDanhSach(dau);
	inDanhSach(dau);
}
