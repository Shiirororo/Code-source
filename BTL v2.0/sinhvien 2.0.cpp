
#include "BTL.h"
// struct Truong {                                     //Struct của 1 trường

//Từ đoạn này là hàm thuộc Class Giảng Viên
       

using namespace std;

vector<SinhVien> danhSachSinhVien;

int main () {
   for (int i = 0; i < 5; i++) {
    SinhVien A;
    A.Input();
    A.Write();
}
}