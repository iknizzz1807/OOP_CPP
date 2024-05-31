#include <iostream>
#include <vector>

using namespace std;

class nhanVien{
protected:
    int maNhanVien;
    string hoTen;
    float luongCoBan;
    float luongHangThang;
public:
    nhanVien(){};
    nhanVien(int maNhanVien, string hoTen, float luongCoBan):maNhanVien(maNhanVien), hoTen(hoTen), luongCoBan(luongCoBan), luongHangThang(0){}
    virtual void print();
    virtual void tinhLuong(){};
    int getMaNhanVien() {
        return this->maNhanVien;
    }
    void setLuongCoBan(float luongCoBan) {
        this->luongCoBan = luongCoBan;
    }
    float getLuongHangThang() {
        return this->luongHangThang;
    }
    virtual int getSoSanPham() {
        return -1;
    }
};

class nhanVienVP : public nhanVien{
    int soNgay;
public:
    nhanVienVP(){};
    nhanVienVP(int maNhanVien, string hoTen, float luongCoBan,int soNgay):nhanVien(maNhanVien, hoTen, luongCoBan), soNgay(soNgay){}
    void print();
    void tinhLuong();
};

class nhanVienSX : public nhanVien{
    int soSanPham;
public:
    nhanVienSX();
    nhanVienSX(int maNhanVien, string hoTen, float luongCoBan,int soSanPham):nhanVien(maNhanVien, hoTen, luongCoBan), soSanPham(soSanPham){}
    void print();
    void tinhLuong();
    int getSoSanPham() {
        return this->soSanPham;
    }
};

class congTy{
    int maCongTy;
    string tenCongTy;
    vector<nhanVien*> danhSachNV;
public:
    congTy(int maCongTy, string tenCongTy):maCongTy(maCongTy), tenCongTy(tenCongTy){}
    void nhapDanhSachNV();
    void print();
    void tinhLuong();
    void timNhanVien(int maNhanVien);
    void capNhatLuong(int maNhanVien, float luongMoi);
    void timNhanVienCoLuongCaoNhat();
    void timNhanVienCoSoSanPhamThapNhat();
    void tim10NhanVienCoLuongCaoNhat();
};

// Bai 1: Tao du lieu nhan vien
void congTy::nhapDanhSachNV(){
    this->danhSachNV.push_back(new nhanVienVP(63231523, "Nguyen My Thong", 3e6, 10));
    this->danhSachNV.push_back(new nhanVienSX(634133, "Nguyen My Thuan", 8e6, 23));
    this->danhSachNV.push_back(new nhanVienVP(63232414, "Nguyen My Thanh", 7e6, 12));
    this->danhSachNV.push_back(new nhanVienSX(6323445, "Nguyen My Thuy", 6e6, 9));
    this->danhSachNV.push_back(new nhanVienVP(6333226, "Nguyen My Thien", 5e6, 15));
    this->danhSachNV.push_back(new nhanVienVP(10221334, "Tran Van A", 10e6, 40));
    this->danhSachNV.push_back(new nhanVienSX(56342784, "Le Thi B", 7.5e6, 35));
    this->danhSachNV.push_back(new nhanVienVP(9821276, "Pham Van C", 8.5e6, 45));
    this->danhSachNV.push_back(new nhanVienVP(62423268, "Hoang Van E", 9.2e6, 50));
    this->danhSachNV.push_back(new nhanVienVP(745623438, "Pham Van N", 8.3e6, 47));
    this->danhSachNV.push_back(new nhanVienSX(1232468, "Hoang Van M", 7.3e6, 8));
    this->danhSachNV.push_back(new nhanVienVP(24341268, "Pham Van K", 6.3e6, 7));
    this->danhSachNV.push_back(new nhanVienSX(2463248, "Hoang Van L", 5.3e6, 6));
    this->danhSachNV.push_back(new nhanVienVP(432468, "Pham Van P", 4.3e6, 5));
    this->danhSachNV.push_back(new nhanVienSX(224468, "Hoang Van Q", 3.3e6, 4));
    this->danhSachNV.push_back(new nhanVienSX(27865468, "Pham Van R", 2.3e6, 3));
    this->danhSachNV.push_back(new nhanVienVP(9874326, "Hoang Van S", 1.3e6, 2));
}

// Bai 2: Xuat cac nhan vien trong cong ty
void congTy::print(){
    for(int i = 0; i < this->danhSachNV.size(); i++) {
        this->danhSachNV[i]->print();
    }
}

// Bai 3: Tinh luong nhan vien trong cong ty
void congTy::tinhLuong(){
    for(int i = 0; i < this->danhSachNV.size(); i++) {
        this->danhSachNV[i]->tinhLuong();
    }
}

void nhanVien::print() {
    cout << "Ma nhan vien: " << this->maNhanVien << endl;
    cout << "Ho va ten: " << this->hoTen << endl;
    cout << "Luong co ban: " << this->luongCoBan << endl;
}

void nhanVienVP::print() {
    cout << "Ma nhan vien: " << this->maNhanVien << endl;
    cout << "Ho va ten: " << this->hoTen << endl;
    cout << "Luong co ban: " << this->luongCoBan << endl;
    cout << "Luong hang thang: " << this->luongHangThang << endl;
}

void nhanVienVP::tinhLuong() {
    if(this->soNgay >= 15) {
        this->luongHangThang = this->luongCoBan + this->soNgay*250000;
    }
    else this->luongHangThang = 1.2 * (this->luongCoBan + this->soNgay*250000);
}

void nhanVienSX::print() {
    cout << "Ma nhan vien: " << this->maNhanVien << endl;
    cout << "Ho va ten: " << this->hoTen << endl;
    cout << "Luong co ban: " << this->luongCoBan << endl;
    cout << "Luong hang thang: " << this->luongHangThang << endl;
}

void nhanVienSX::tinhLuong() {
    this->luongHangThang = this->luongCoBan + this->soSanPham*175000;
    if(this->luongHangThang >= 10e0) {
        this->luongHangThang = this->luongHangThang + this->luongHangThang * 0.1;
    }
    if(this->soSanPham < 10) {
        this->luongHangThang = this->luongHangThang + this->luongHangThang * 0.3;
    }
}

// Bai 4: Tim nhan vien theo ma nhan vien
void congTy::timNhanVien(int maNhanVien) {
    for(int i = 0; i < this->danhSachNV.size(); i++) {
        if(this->danhSachNV[i]->getMaNhanVien() == maNhanVien) {
            this->danhSachNV[i]->print();
            return;
        }
    }
    cout << "Khong tim thay nhan vien" << endl;
}

// Bai 5: Cap nhat luong co ban cua nhan vien theo ma nhan vien
void congTy::capNhatLuong(int maNhanVien, float luongMoi) {
    for(int i = 0; i < this->danhSachNV.size(); i++) {
        if(this->danhSachNV[i]->getMaNhanVien() == maNhanVien) {
            this->danhSachNV[i]->setLuongCoBan(luongMoi);
            return;
        }
    }
}

// Bai 6: Tim nhan vien co luong cao nhat
void congTy::timNhanVienCoLuongCaoNhat() {
    float max = this->danhSachNV[0]->getLuongHangThang();
    int index = 0;
    for(int i = 1; i < this->danhSachNV.size(); i++) {
        if(this->danhSachNV[i]->getLuongHangThang() > max) {
            max = this->danhSachNV[i]->getLuongHangThang();
            index = i;
        }
    }
    this->danhSachNV[index]->print();
}

// Bai 7: Tim nhan vien co san pham ban duoc thap nhat
void congTy::timNhanVienCoSoSanPhamThapNhat() {
    int min = INT_MAX;
    nhanVien* nhanVienMin = nullptr;
    for(int i = 0; i < this->danhSachNV.size(); i++) {
        int soSanPham = this->danhSachNV[i]->getSoSanPham();
        if(soSanPham != -1 && soSanPham < min) {
            min = soSanPham;
            nhanVienMin = this->danhSachNV[i];
        }
    }
    if(nhanVienMin) {
        nhanVienMin->print();
    } else {
        cout << "Khong tim thay nhan vien san xuat" << endl;
    }
}

// Bai 8: Tim 10 nhan vien co luong cao nhat
void congTy::tim10NhanVienCoLuongCaoNhat(){
    vector<nhanVien*> temp = this->danhSachNV;
    for(int i = 0; i < 10; i++) {
        float max = temp[0]->getLuongHangThang();
        int index = 0;
        for(int j = 1; j < temp.size(); j++) {
            if(temp[j]->getLuongHangThang() > max) {
                max = temp[j]->getLuongHangThang();
                index = j;
            }
        }
        temp[index]->print();
        temp.erase(temp.begin() + index);
    }
}

int main()
{
    congTy congTy(31234, "Google");
    congTy.nhapDanhSachNV();
    congTy.tinhLuong();
//    congTy.timNhanVien(6323);
//    congTy.capNhatLuong(6323, 10e6);
//    congTy.print();
//    congTy.timNhanVienCoLuongCaoNhat();
//    congTy.timNhanVienCoSoSanPhamThapNhat();
    congTy.tim10NhanVienCoLuongCaoNhat();
    return 0;
}
