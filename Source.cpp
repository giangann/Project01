#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
#define MAX 100
//#define A[100]
struct KhachHang {
	int maKH;
	char tenKH[256];
	char diachiKH[256];
	int socongtoKH;
};
void NhapThongtinKhachHang(KhachHang& kh) {
	cout << "Nhap ma so khach hang: ";
	cin >> kh.maKH;
	cin.ignore();
	cout << "Nhap ten khach hang: ";
	cin.getline(kh.tenKH, 256);
	cout << "Nhap dia chi khach hang: ";
	cin.getline(kh.diachiKH, 256);
	cout << "Nhap so cong to cua khach hang: ";
	cin >> kh.socongtoKH;
}
void NhapDachSachKhachHang(KhachHang dsKH[], int n) {
	for (int i = 1; i < n+1; i++) {
		cout << "Nhap thong tin khach hang thu " << i << ":\n";
		NhapThongtinKhachHang(dsKH[i]);
	}
}
void XuatThongtinKhachHang(KhachHang kh) {
	cout <<"   "<< kh.maKH << "                      " << kh.tenKH << "                          " << kh.diachiKH<<"                         "<<kh.socongtoKH << endl;
}
void XuatDanhSachKhachHang(KhachHang dsKH[], int n) {
	cout << " " << endl;
	cout << "Ma khach hang " << "          " << "Ten khach hang " << "          " << "Dia chi khach hang " << "          " << "So cong to khach hang " << endl;
	for (int i = 1; i < n+1; i++) {
		XuatThongtinKhachHang(dsKH[i]);
	}
	cout << " " << endl;
}
void LuuFileKH(KhachHang dsKH[], int n) {
	ofstream outfile("vtl1.bin", ofstream::binary);
	for (int i = 1; i < n+1; i++) {
		KhachHang kh = dsKH[i];
		outfile.write((char*)&kh, sizeof(KhachHang));
	}
	outfile.close();
}
void DocFileKH(KhachHang dsKH[]) {
	ifstream infile("vtl1.bin", ifstream::binary);
	int i = 0;
	while (!infile.eof()) {
		KhachHang kh;
		infile.read((char*)&kh, sizeof(KhachHang));
		dsKH[i++] = kh;
	}
	infile.close();
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

struct time {
	int tm_mday;
	int tm_mon;
	int tm_year;
};
struct ChiSoDien {
	int csDien;
	int ngay;
	int thang;
	int nam;
};
void NhapThongTinChiSoDien(ChiSoDien& cs) {
	cout << "Nhap chi so dien: ";
	cin >> cs.csDien;
	cout << "Nhap ngay chot tien: ";
	cin >> cs.ngay;
	cout << "Nhap thang chot dien: ";
	cin >> cs.thang;
	cout << "Nhap nam chot dien: ";
	cin >> cs.nam;
}
void NhapChiSoDien(ChiSoDien dsCS[], int n) {
	for (int i = 1; i < n+1; i++) {
		cout << "Nhap thong tin chi so dien cua khach hang thu " << i << " : "<<endl;
		NhapThongTinChiSoDien(dsCS[i]);
	}
}
void XuatThongTinChiSoDien(ChiSoDien cs, KhachHang kh) { 
	cout <<"   "<< kh.maKH <<"                                      "<< cs.csDien << "                                 " << cs.ngay << "/" << cs.thang << "/" << cs.nam<<endl;
}
void XuatChiSoDien(ChiSoDien dsCS[], KhachHang dsKH[], int n) {
	cout << " ";
	cout << "Ma khach hang " << "                         " << "Chi so dien khach hang " << "             " << "Ngay chot chi so dien " << endl;
	for (int i = 1; i < n+1; i++) {
		XuatThongTinChiSoDien(dsCS[i],dsKH[i]);
	}
	cout << " ";
}
void LuuFileCSDIEN(ChiSoDien dsCS[], int n) {
	ofstream outfile("vtl2.bin", ofstream::binary);
	for (int i = 1; i < n+1; i++) {
		ChiSoDien cs = dsCS[i];
		outfile.write((char*)&cs, sizeof(ChiSoDien));
	}
	outfile.close();
}
void DocFileCS(ChiSoDien dsCS[]) {
	ifstream infile("vtl2.bin", ifstream::binary);
	int i = 0;
	while (!infile.eof()) {
		ChiSoDien cs;
		infile.read((char*)&cs, sizeof(ChiSoDien));
		dsCS[i++] = cs;
	}
	infile.close();
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

/*struct GiaDien {
	int dienTieuThu;
	int donGia;
};
void XuatGiaTienDien (int dsGD[100]) {
	dsGD[1] = 50;
	dsGD[2] = 100;
	dsGD[3] = 150;
	dsGD[4] = 600;
	dsGD[5] = 865;
	dsGD[6] = 1000;
	cout << "      Dien nang tieu thu" << "      " << "Don gia(nghin dong/1 so dien)"<<endl;
	cout << "              " << dsGD[1] << "      " << "             " << dsGD[4] << endl;
	cout << "              " << dsGD[2] << "      " << "            " << dsGD[5] << endl;
	cout << "              " << dsGD[3] << "      " << "            " << dsGD[6] << endl;
	cout << "              " << "....." << "      " << "          " << "....." << endl;
}*/

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void ThemDuLieuVaoFile(KhachHang dsKH[],ChiSoDien dsCS[], int n) {
	int p;
	cout << "So khach hang ban can them thong tin la: ";
	cin >> p;
	for (int i = n+1; i < n + p+1; i++) {
		cout << "Nhap thong tin khach hang thu " << i << " : " << endl;
		NhapThongtinKhachHang(dsKH[i]);
		NhapThongTinChiSoDien(dsCS[i]);
		XuatDanhSachKhachHang(dsKH, n + p);
		XuatChiSoDien(dsCS, dsKH, n + p);
	}
}
void XoaDuLieuTrongFile(KhachHang dsKH[], ChiSoDien dsCS[], int n) {
	int t;
	cout << "Ban muon xoa du lieu cua khach hang thu may ? Nhap : ";
	cin >> t;
	if (0  <= t && t <= n-1) {
		for (int i = t; i < n - 1;i++) {
			dsKH[i] = dsKH[i + 1];
			dsCS[i] = dsCS[i + 1];
		}
		cout << "Danh sach thong tin khach hang sau khi xoa la: "<<endl;
		XuatDanhSachKhachHang(dsKH, n-1);
		XuatChiSoDien(dsCS, dsKH, n -1);
	}
	else cout << "Khong xoa du lieu duoc!!!"<<endl;
}
void SuaDuLieuKH(KhachHang dsKH[], int n) {
	int y;
    cout << "Ban muon sua du lieu cua khach hang thu may ? Nhap : ";
	cin >> y;
	if (0 <= y && y <= n - 1) {
		NhapThongtinKhachHang(dsKH[y]);
		XuatDanhSachKhachHang(dsKH, n);
	}
	else cout << "Khong sua du lieu duoc!!!" << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void SuaDuLieuCSD(ChiSoDien dsCS[], KhachHang dsKH[], int n) {
	int o;
	cout << "Ban muon sua du lieu cua khach hang thu may ? Nhap : ";
	cin >> o;
	if (0 <= o && o <= n - 1) {
		NhapThongTinChiSoDien(dsCS[o]);
		XuatChiSoDien(dsCS, dsKH, n);
	}
	else cout << "Khong sua du lieu duoc!!!"<<endl;
}


int main() {
	int n;
	cout << "Nhap so khach hang ban can lam viec voi: ";
	cin >> n;
    KhachHang dsKH[MAX];
	ChiSoDien dsCS[MAX];
	NhapDachSachKhachHang(dsKH, n);
	NhapChiSoDien(dsCS, n);
	cout << "---------------------------" << "MENU" << "---------------------------" << endl;
	cout << "1: Bo sung du lieu vao file!!!" << endl;
	cout << "2: Sua chua du lieu trong file!!!" << endl;
	cout << "3: Xoa du lieu trong file!!!" << endl;
	cout << "4: Thoat!" << endl;
	cout << "------------------------------------------------------------------------------------" << endl;
	int ktlt,vtl;
	do {
		cout << "Nhap chuc nang can thao tac: ";
		cin >> ktlt;
		switch (ktlt) {
		case 1:
			ThemDuLieuVaoFile(dsKH,dsCS, n);
			break;

		case 2:
				cout << "Ban muon sua du lieu trong file nao? " << endl;
				cout << "1: FILE KH" << endl;
				cout << "2: File CSD" << endl;
				cout << "Nhap: " << endl;
				cin >> vtl;
				if (0 < vtl && vtl < 3) {
					switch (vtl) {
					case 1:
						SuaDuLieuKH(dsKH, n);
						break;
					case 2:
						SuaDuLieuCSD(dsCS, dsKH, n);
						break;
					}
				}
				else {
					cout << "Khong sua duoc!!!" << endl;
					break;
				}
			break;

		case 3:
			XoaDuLieuTrongFile(dsKH,dsCS, n);
			break;
		}
	} while (0 < ktlt && ktlt < 4);
	return 0;
}