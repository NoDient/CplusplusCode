#include <iostream>
#include <string>
#include <vector>
using namespace std;

class NhanVien {
protected:
	string HoTen;
	string NgaySinh;
	float LuongCoBan; // lương cơ bản
public:
	string getHoTen() { return HoTen; } // hàm thêm vào để có thể tìm kiếm theo họ tên 
	virtual float TinhLuong() = 0;
	virtual void Nhap();
	virtual void Xuat();
};

class NVQuanLy : public NhanVien {
	float HeSo, Thuong; // hệ số, thưởng
public:
	float TinhLuong();
	void Nhap();
	void Xuat();
};

class NVVanPhong : public NhanVien {
	float SoNgayLamViec, TroCap; // số ngày làm việc và trợ cấp
public:
	float TinhLuong();
	void Nhap();
	void Xuat();
};

class NVSanXuat : public NhanVien {
	float SoSanPham;
public:
	float TinhLuong();
	void Nhap();
	void Xuat();
};

class CongTy {
	vector<NhanVien*> DSNhanVien;
public:
	void Nhap();
	void Xuat();
	float TinhTongLuong();
	NhanVien* TimKiemNV(string);
};

int main() {
	CongTy cty;
	cty.Nhap();
	cty.Xuat();
	cout << cty.TinhTongLuong() << endl;
	cout << "\nNhap ten can tim: ";
	/*string find = "";
	getline(cin, find); // Bỏ comment 2 dòng này để nhập tên theo ý muốn, và truyền find vào phương thức bên dưới*/
	NhanVien* nv = cty.TimKiemNV("Nguyen Van A"); // nhập tên 1 trong các nhân viên là "Nguyen Van A" để tìm được
	if (nv != NULL) nv->Xuat();
	else cout << "Khong the tim thay nhan vien\n";
	return 0;
}

void NhanVien::Nhap() {
	cout << "Nhap thong tin nhan vien: ";
	cout << "\nHo ten: ";
	getline(cin, HoTen);
	cout << "Ngay sinh: ";
	getline(cin, NgaySinh);
	cout << "Luong co ban: ";
	cin >> LuongCoBan;
	// cin.ignore();
}

void NhanVien::Xuat() {
	cout <<"Ho ten: " + HoTen << endl;
	cout <<"Ngay sinh " + NgaySinh << endl;
	cout << "Luong co ban: " << LuongCoBan << endl;
}

float NVQuanLy::TinhLuong() { return LuongCoBan * HeSo + Thuong; }

void NVQuanLy::Nhap() {
	NhanVien::Nhap();
	cout << "He so luong: ";
	cin >> HeSo;
	cout << "Thuong: ";
	cin >> Thuong;
}

void NVQuanLy::Xuat() {
	NhanVien::Xuat();
	cout << "He so luong :" << HeSo << endl;
	cout << "Thuong: " << Thuong << endl;
	cout << "Luong: " << TinhLuong() << endl;
}

float NVVanPhong::TinhLuong() {
	return LuongCoBan + SoNgayLamViec * 100000 + TroCap;
}

void NVVanPhong::Nhap() {
	NhanVien::Nhap();
	cout << "So ngay lam viec: ";
	cin >> SoNgayLamViec;
	cout << "Tro cap: ";
	cin >> TroCap;
}

void NVVanPhong::Xuat() {
	NhanVien::Xuat();
	cout << "So ngay lam viec: " << SoNgayLamViec << endl;
	cout << "Tro cap: " << TroCap << endl;
	cout << "Luong: " << TinhLuong() << endl;
}

float NVSanXuat::TinhLuong() {
	return LuongCoBan + SoSanPham * 2000;
}

void NVSanXuat::Nhap() {
	NhanVien::Nhap();
	cout << "So san pham: ";
	cin >> SoSanPham;
}

void NVSanXuat::Xuat() {
	NhanVien::Xuat();
	cout << "So san pham: " << SoSanPham << endl;
}

void CongTy::Nhap() {
	NhanVien* nv = NULL;
	int kieuNV = 0, stop = 0;
	// cout << "\nNHAP DANH SACH NHAN VIEN\n";
	do {
		cout << "Chon kieu nhan vien (0 = Van Phong, 1 = San Xuat, 2 = Quan Ly): ";
		cin >> kieuNV;
		cin.ignore();
		switch (kieuNV) {
		case 0:
			nv = new NVVanPhong();
			nv->Nhap();
			DSNhanVien.push_back(nv);
			break;
		case 1:
			nv = new NVSanXuat();
			nv->Nhap();
			DSNhanVien.push_back(nv);
			break;
		case 2:
			nv = new NVQuanLy();
			nv->Nhap();
			DSNhanVien.push_back(nv);
			break;
		default:
			cout << "Kieu nhan vien khong hop le! Vui long nhap lai!\n";
			continue;
		}
		cout << "Ban muon nhap tiep khong ? An \"-999\" de dung nhap!\n";
		cin >> stop;
	} while (stop != -999);

}

void CongTy::Xuat() {
	cout << endl;
	for (NhanVien* nv : DSNhanVien) {
		nv->Xuat();
		cout << endl;
	}
}

float CongTy::TinhTongLuong() {
	float tongLuong = 0;
	for (NhanVien* nv : DSNhanVien) {
		tongLuong += nv->TinhLuong();
	}
	return tongLuong;
}

NhanVien* CongTy::TimKiemNV(string HotenNV) {
	for (NhanVien* nv : DSNhanVien) {
		if (nv->getHoTen() == HotenNV) return nv;
	}
	return NULL;
}