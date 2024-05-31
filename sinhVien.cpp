#include <iostream>
#include <vector>

using namespace std;

class sinhVien {
protected:
    int maSoSinhVien;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    float diemTrungBinh;
    string xetTotNghiep;
public:
    sinhVien() {};

    sinhVien(int maSoSinhVien, string hoTen, string diaChi, int tongSoTinhChi, float diemTrungBinh)
            : maSoSinhVien(maSoSinhVien), hoTen(hoTen), diaChi(diaChi), tongSoTinChi(tongSoTinhChi),
              diemTrungBinh(diemTrungBinh), xetTotNghiep("Chua tot nghiep") {};

    virtual void print();

    virtual bool duocTotNghiep() {
        return false;
    }

    virtual void setTotNghiep(string isTotNghiep) {
        this->xetTotNghiep = isTotNghiep;
    }
    float getDiemTrungBinh() {
        return this->diemTrungBinh;
    }
};

class sinhVienHeDaiHoc : public sinhVien {
private:
    float diemThiTotNghiep;
public:
    sinhVienHeDaiHoc() {};

    sinhVienHeDaiHoc(int maSoSinhVien, string hoTen, string diaChi, int tongSoTinhChi, float diemTrungBinh,
                     float diemThiTotNghiep) : sinhVien(maSoSinhVien, hoTen, diaChi, tongSoTinhChi,
                                                        diemTrungBinh),
                                               diemThiTotNghiep(diemThiTotNghiep) {};

    void print();

    bool duocTotNghiep() {
        return (this->tongSoTinChi >= 120 and this->diemTrungBinh >= 5.0 and this->diemThiTotNghiep >= 5.0);
    }

    void setTotNghiep(string isTotNghiep) {
        this->xetTotNghiep = isTotNghiep;
    }
};

class sinhVienVB2 : public sinhVien {
private:
    string tenLuanVan;
    float diemLuanVan;
public:
    sinhVienVB2() {};

    sinhVienVB2(int maSoSinhVien, string hoTen, string diaChi, int tongSoTinhChi, float diemTrungBinh,
                string tenLuanVan, float diemLuanVan) : sinhVien(maSoSinhVien, hoTen, diaChi, tongSoTinhChi,
                                                                 diemTrungBinh), tenLuanVan(tenLuanVan),
                                                        diemLuanVan(diemLuanVan) {};

    void print();

    bool duocTotNghiep() {
        return (this->tongSoTinChi >= 120 and this->diemTrungBinh >= 5.0 and this->diemLuanVan >= 5.0);
    }

    void setTotNghiep(string isTotNghiep) {
        this->xetTotNghiep = isTotNghiep;
    }
};

class truongDaiHoc {
private:
    string tenTruong;
    vector<sinhVien *> danhSachSinhVien;
public:
    truongDaiHoc() {};

    truongDaiHoc(string tenTruong) : tenTruong(tenTruong) {};

    void khoiTaoDanhSachSinhVien();

    void xuatCacDanhSachSinhVien();

    void xetTotNghiep();

    void xuatCacDanhSachSinhVienDuDieuKienTotNghiep();
    sinhVien sinhVienDiemTrungBinhCaoNhat();
};

void sinhVien::print() {
    cout << "Ma so sinh vien: " << this->maSoSinhVien << endl;
    cout << "Ho va ten: " << this->hoTen << endl;
    cout << "Dia chi: " << this->diaChi << endl;
    cout << "Tong so tin chi: " << this->tongSoTinChi << endl;
    cout << "Diem trung binh: " << this->diemTrungBinh << endl;
    cout << "Xet tot nghiep: " << this->xetTotNghiep << endl;
}

void sinhVienHeDaiHoc::print() {
    sinhVien::print();
    cout << "Diem thi tot nghiep: " << this->diemThiTotNghiep << endl;
}

void sinhVienVB2::print() {
    sinhVien::print();
    cout << "Ten luan van: " << this->tenLuanVan << endl;
    cout << "Diem luan van: " << this->diemLuanVan << endl;
}

// Bai 1: Khoi tao danh sach sinh vien
void truongDaiHoc::khoiTaoDanhSachSinhVien() {
    danhSachSinhVien.push_back(
            new sinhVienVB2(43242, "Nguyen My Thuan", "Di An, Binh Duong", 119, 8.5, "Thiet ke lai Facebook", 9.2));
    danhSachSinhVien.push_back(new sinhVienHeDaiHoc(31245, "Nguyen My Thong", "Thu Duc, Ho Chi Minh", 125, 8.2, 8.5));
}

// Bai 2: Xuat cac danh sach sinh vien
void truongDaiHoc::xuatCacDanhSachSinhVien() {
    for (int i = 0; i < this->danhSachSinhVien.size(); i++) {
        this->danhSachSinhVien[i]->print();
    }
}

// Bai 3: Xet tot nghiep
void truongDaiHoc::xetTotNghiep() {
    for (int i = 0; i < this->danhSachSinhVien.size(); i++) {
        if (this->danhSachSinhVien[i]->duocTotNghiep()) this->danhSachSinhVien[i]->setTotNghiep("Da tot nghiep");
    }
}

// Bai 4: tim cac sinh vien du dieu kien tot nghiep
void truongDaiHoc::xuatCacDanhSachSinhVienDuDieuKienTotNghiep() {
    for (int i = 0; i < this->danhSachSinhVien.size(); i++) {
        if (this->danhSachSinhVien[i]->duocTotNghiep()) this->danhSachSinhVien[i]->print();
    }
}

// Bai 7: Tim sinh vien co diem trung binh cao nhat
sinhVien truongDaiHoc::sinhVienDiemTrungBinhCaoNhat() {
    sinhVien* sinhVienMAX = this->danhSachSinhVien[0];
    for (int i = 1; i < this->danhSachSinhVien.size(); i++) {
        if (this->danhSachSinhVien[i]->getDiemTrungBinh() > sinhVienMAX->getDiemTrungBinh()) sinhVienMAX = this->danhSachSinhVien[i];
    }
    return *sinhVienMAX;
}

int main() {
    truongDaiHoc UIT("UIT");
    UIT.khoiTaoDanhSachSinhVien();
    UIT.xetTotNghiep();
//    UIT.xuatCacDanhSachSinhVienDuDieuKienTotNghiep();
//    UIT.xuatCacDanhSachSinhVien();
    UIT.sinhVienDiemTrungBinhCaoNhat().print();
    return 0;
}
