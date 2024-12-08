#include "BTL.h"
#include <iomanip>
#include <fstream>


//Từ đoạn này là hàm thuộc Class Giảng Viên

void GiangVien::Input () {                          //Hàm nhập thông tin của giảng viên vào chương trình
    std::cout << "Nhập mã của giảng viên: "; std::cin >> this->msv;   
    std::cin.ignore();
    std::cout << "Nhập họ và tên giảng viên: "; std::getline(std::cin,this->HoVaTen);
    std::cout << "Nhập ngày tháng năm sinh: "; std::cin >> this->birth;
    // cout << "Nhập khoa, trường giảng viên trực thuộc: "; cin >> this->School.khoa >> this->School.truong;
}
void GiangVien::Output() {                         //Hàm xuất thông tin của giảng viên ra màn hình
    std::cout << "MSV: " <<  this->msv << std::endl << "Họ và tên: " << this->HoVaTen << std::endl << "Ngày tháng năm sinh: " << this->birth << std::endl << "Khoa: " << this->School.khoa << std::endl << "Trường: " <<this->School.truong << std::endl << std::endl;
}       

// void GiangVien::Write() {                          //Hàm ghi thông tin của giảng viên vào file text

// }
std::string GiangVien::getMSGV() const {              //Lấy tên và mssv khỏi private
     return msv;
}
std::string GiangVien::getName() const {
    return HoVaTen;
}
void GiangVien::UpdateField() {                     //Update thong tin giang vien
        int choice;
        /*cout << "Chọn thông tin cần thay đổi:" << endl;
        cout << "1. Họ và tên" << endl;
        cout << "2. MSV (Mã số giảng viên)" << endl;
        cout << "3. Ngày sinh" << endl;
        cout << "4. Tên trường" << endl;
        cout << "5. Khoa" << endl;
        cout << "Lựa chọn: ";*/
        std::cin >> choice;

        std::cin.ignore(); // Loại bỏ ký tự thừa sau khi nhập số

        switch (choice) {
            case 1: {
                std::cout << "Nhập họ và tên mới: ";
                std::getline(std::cin, HoVaTen);
                break;
            }
            case 2: {
                std::cout << "Nhập MSV mới: ";
                std::cin >> msv;
                break;
            }
            case 3: {
                std::cout << "Nhập ngày sinh mới (dd/mm/yyyy): ";
                std::cin.ignore();
                std::getline(std::cin, birth);
                break;
            }
            case 4: {
                std::cout << "Nhập tên trường mới: ";
                std::getline(std::cin, School.truong);
                break;
            }
            case 5: {
                std::cout << "Nhập khoa mới: ";
                std::getline(std::cin, School.khoa);
                // break;
            }
            default:
                std::cout << "Lựa chọn không hợp lệ!" << std::endl;
                break;
        }
}void GiangVien::UpdateField() {                     //Update thong tin giang vien
        int choice;
        /*cout << "Chọn thông tin cần thay đổi:" << endl;
        cout << "1. Họ và tên" << endl;
        cout << "2. MSV (Mã số giảng viên)" << endl;
        cout << "3. Ngày sinh" << endl;
        cout << "4. Tên trường" << endl;
        cout << "5. Khoa" << endl;
        cout << "Lựa chọn: ";*/
        std::cin >> choice;

        std::cin.ignore(); // Loại bỏ ký tự thừa sau khi nhập số

        switch (choice) {
            case 1: {
                std::cout << "Nhập họ và tên mới: ";
                std::getline(std::cin, HoVaTen);
                break;
            }
            case 2: {
                std::cout << "Nhập MSV mới: ";
                std::cin >> msv;
                break;
            }
            case 3: {
                std::cout << "Nhập ngày sinh mới (dd/mm/yyyy): ";
                std::cin.ignore();
                std::getline(std::cin, birth);
                break;
            }
            case 4: {
                std::cout << "Nhập tên trường mới: ";
                std::getline(std::cin, School.truong);
                break;
            }
            case 5: {
                std::cout << "Nhập khoa mới: ";
                std::getline(std::cin, School.khoa);
                break;
            }
            default:
                std::cout << "Lựa chọn không hợp lệ!" << std::endl;
                break;
        }
}
void UpdateGiangVienInVector(std::vector<GiangVien> &danhSachGiangVien) {
    if (danhSachGiangVien.empty()) {
        std::cout << "Danh sách giảng viên trống!" << std::endl;
        return;
    }

    std::string mssv;
    std::cout << "Nhập MSSV giảng viên cần chỉnh sửa: ";
    std::cin >> mssv;

    bool found = false;
    for (auto &gv : danhSachGiangVien) {
        if (gv.getMSGV() == mssv) {
            std::cout << "Giảng viên tìm thấy:\n";
            gv.Output();
            
            // Cập nhật thông tin giảng viên
            std::cout << "\nChỉnh sửa thông tin giảng viên:\n";
            gv.UpdateField();
            
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Không tìm thấy giảng viên có MSSV: " << mssv << std::endl;
    }
}
