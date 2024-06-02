#include <iostream>
#include <vector>

using namespace std;

class nhanVien {
protected:
    int maNhanVien;
    string hoTen;
    float luongCoBan;
    float luongHangThang;
public:
    nhanVien() {};

    nhanVien(int maNhanVien, string hoTen, float luongCoBan) : maNhanVien(maNhanVien), hoTen(hoTen),
                                                               luongCoBan(luongCoBan), luongHangThang(0) {};

    virtual void print();

    virtual float getLuong() {
        return this->luongHangThang;
    }

    int getMaNhanVien() {
        return this->maNhanVien;
    }

    void setLuongCoBan(float luongMoi) {
        this->luongCoBan = luongMoi;
    }
};

class lapTrinhVien : public nhanVien {
private:
    int soGioTangCa;
public:
    lapTrinhVien() {};

    lapTrinhVien(int maNhanVien, string hoTen, float luongCoBan, int soGioTangCa) : nhanVien(maNhanVien, hoTen,
                                                                                             luongCoBan),
                                                                                    soGioTangCa(soGioTangCa) {};

    void print();

    float getLuong() {
        this->luongHangThang = this->luongCoBan + this->soGioTangCa * 250000;
        return this->luongHangThang;
    }
};

class phanTichVien : public nhanVien {
private:
    int soGioTangCa;
    float phuCap;
public:
    phanTichVien() {};

    phanTichVien(int maNhanVien, string hoTen, float luongCoBan, int soGioTangCa, float phuCap) : nhanVien(maNhanVien,
                                                                                                           hoTen,
                                                                                                           luongCoBan),
                                                                                                  soGioTangCa(
                                                                                                          soGioTangCa),
                                                                                                  phuCap(phuCap) {};

    void print();

    float getLuong() {
        this->luongHangThang = lapTrinhVien().getLuong() * 1.8;
        return this->luongHangThang;
    }
};

class nhanVienKiemThu : public nhanVien {
private:
    int soLoiPhatHien;
public:
    nhanVienKiemThu() {};

    nhanVienKiemThu(int maNhanVien, string hoTen, float luongCoBan, int soLoiPhatHien) : nhanVien(maNhanVien,
                                                                                                  hoTen,
                                                                                                  luongCoBan),
                                                                                         soLoiPhatHien(
                                                                                                 soLoiPhatHien) {};

    void print();

    float getLuong() {
        this->luongHangThang = this->luongCoBan + this->soLoiPhatHien * 85000;
        return this->luongHangThang;
    }
};

class congTy {
private:
    string maCongTy;
    vector<nhanVien *> danhSachNhanVien;
public:
    congTy() {};

    congTy(string maCongTy) {};

    void khoiTaoDanhSachNhanVien();

    void print();

    void printCacNhanVienCoLuongThapHonTrungBinh();

    void printThongTinNhanVienCoLuongCaoNhat();

    void printThongTinLapTrinhVienCoLuongCaoNhat();

    void printThongTinNhanVienKiemThuCoLuongThaphat();

    void capNhatLuongCoBan(int maNhanVien, float luongCoBan);
};

////////////////////////////////////////////////Khai bao cac phuong thuc///////////////////////////////////////////////////////

void nhanVien::print() {
    cout << "Ma nhan vien: " << this->maNhanVien << endl;
    cout << "Ho va ten: " << this->hoTen << endl;
    cout << "Luong co ban: " << this->luongCoBan << endl;
}

void lapTrinhVien::print() {
    nhanVien::print();
    cout << "So gio tang ca: " << this->soGioTangCa << endl;
}

void phanTichVien::print() {
    nhanVien::print();
    cout << "So gio tang ca: " << this->soGioTangCa << endl;
    cout << "Phu cap: " << this->phuCap << endl;
}

void nhanVienKiemThu::print() {
    nhanVien::print();
    cout << "So loi phat hien: " << this->soLoiPhatHien << endl;
}

// Bai 1: Khoi tao danh sach nhan vien
void congTy::khoiTaoDanhSachNhanVien() {
    this->danhSachNhanVien.push_back(new nhanVienKiemThu(2131, "Tran Thi Ha Nhi", 3000, 43));
    this->danhSachNhanVien.push_back(new lapTrinhVien(8567, "Nguyen My Thong", 5000, 30));
    this->danhSachNhanVien.push_back(new phanTichVien(4856, "Bui Nguyen Gia Huy", 6000, 40, 1000));
}

// Bai 2: Xuat danh sach nhan vien
void congTy::print() {
    for (int i = 0; i < this->danhSachNhanVien.size(); i++) {
        danhSachNhanVien[i]->print();
    }
}

// Bai 3: Xuat danh sach nhan vien co muc luong thap hon muc luong trung binh cua cong ty
void congTy::printCacNhanVienCoLuongThapHonTrungBinh() {
    float tongLuong;
    for (int i = 0; i < this->danhSachNhanVien.size(); i++) {
        tongLuong += this->danhSachNhanVien[i]->getLuong();
    }
    float luongTrungBinh = tongLuong / this->danhSachNhanVien.size();
    for (int i = 0; i < this->danhSachNhanVien.size(); i++) {
        if (this->danhSachNhanVien[i]->getLuong() < luongTrungBinh) this->danhSachNhanVien[i]->print();
    }
}

// Bai 4: Xuat thong tin nhan vien co luong cao nhat
void congTy::printThongTinNhanVienCoLuongCaoNhat() {
    nhanVien *nhanVienMAX = this->danhSachNhanVien[0];
    for (int i = 1; i < this->danhSachNhanVien.size(); i++) {
        if (this->danhSachNhanVien[i]->getLuong() > nhanVienMAX->getLuong()) nhanVienMAX = this->danhSachNhanVien[i];
    }
    nhanVienMAX->print();
}


// Bai 6: Xuat thong tin lap trinh vien co muc luong cao nhat
void congTy::printThongTinLapTrinhVienCoLuongCaoNhat() {
    nhanVien *lapTrinhVienMAX;
    for (auto nv: this->danhSachNhanVien) {
        if (dynamic_cast<lapTrinhVien *>(nv)) {
            lapTrinhVienMAX = nv;
            break;
        }
    }
    for (auto nv: this->danhSachNhanVien) {
        if (dynamic_cast<lapTrinhVien *>(nv) and (nv->getLuong() > lapTrinhVienMAX->getLuong())) lapTrinhVienMAX = nv;
    }
    lapTrinhVienMAX->print();
}

// Bai 7: Xuat thong tin nhan vien kiem thu co luong cao nhat
void congTy::printThongTinNhanVienKiemThuCoLuongThaphat() {
    nhanVien *nhanVienKiemThuMIN;
    for (auto nv: this->danhSachNhanVien) {
        if (dynamic_cast<nhanVienKiemThu *>(nv)) {
            nhanVienKiemThuMIN = nv;
            break;
        }
    }
    for (auto nv: this->danhSachNhanVien) {
        if (dynamic_cast<lapTrinhVien *>(nv) and (nv->getLuong() < nhanVienKiemThuMIN->getLuong()))
            nhanVienKiemThuMIN = nv;
    }
    nhanVienKiemThuMIN->print();
}

// Bai 8: Cap nhat luong co ban cua nhan vien theo ma nhan vien
void congTy::capNhatLuongCoBan(int maNhanVien, float luongCoBan) {
    for(int i = 0; i < this->danhSachNhanVien.size(); i++) {
        if(this->danhSachNhanVien[i]->getMaNhanVien() == maNhanVien) this->danhSachNhanVien[i]->setLuongCoBan(luongCoBan);
    }
}

int main() {
    congTy congTy("TNHH MTV S102");
    congTy.khoiTaoDanhSachNhanVien();
//    congTy.printCacNhanVienCoLuongThapHonTrungBinh();
//    congTy.printThongTinNhanVienCoLuongCaoNhat();
//    congTy.printThongTinLapTrinhVienCoLuongCaoNhat();
//    congTy.printThongTinNhanVienKiemThuCoLuongThaphat();
    congTy.print();
    congTy.capNhatLuongCoBan(8567, 50000);
    congTy.print();
    return 0;
}