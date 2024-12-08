#include "BTL.h"
using namespace std;

//Từ đoạn này là hàm thuộc Class Giảng Viên
vector<GiangVien> danhSachGiangVien;                     //Vector Giang Vien
void xoaGiangVien(vector<GiangVien> &danhSach) {
    bool found = false;
    cin.ignore();
    string key; getline(cin,key);
    // Duyệt danh sách để tìm giảng viên cần xóa
    for (int i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getMSGV() == key || danhSach[i].getName() == key) {
            cout << "Đã xóa giảng viên: ";
            danhSach[i].Output();
            danhSach.erase(danhSach.begin() + i); // Xóa sinh viên tại chỉ số i
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy giảng viên có MSGV hoặc tên: " << key << endl;
    }
}
void UpdateGiangVienInVector(vector<GiangVien> &danhSachGiangVien) {
    if (danhSachGiangVien.empty()) {
        cout << "Danh sách giảng viên trống!" << endl;
        return;
    }

    string mssv;
    cout << "Nhập MSSV giảng viên cần chỉnh sửa: ";
    cin >> mssv;

    bool found = false;
    for (auto &gv : danhSachGiangVien) {
        if (gv.getMSGV() == mssv) {
            cout << "Giảng viên tìm thấy:\n";
            gv.Output();
            
            // Cập nhật thông tin giảng viên
            cout << "\nChỉnh sửa thông tin giảng viên:\n";
            gv.UpdateField();
            
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy giảng viên có MSSV: " << mssv << endl;
    }
}



//Từ đoạn này là hàm thuộc Class Sinh Viên
vector<SinhVien> danhSachSinhVien;

void SinhVien::Input () {                           //Hàm nhập thông tin sinh viên vào chương trình
    cout << "Nhập mã số sinh viên: "; cin >> this->msv;
    cin.ignore();
    cout << "Nhập họ và tên sinh viên: "; getline(cin,this->HoVaTen);
    cout << "Nhập ngày tháng năm sinh: "; cin >> this->birth;
    cout << "Nhập gpa của sinh viên: "; cin >> this->gpa; 
}
void SinhVien::Write () {                //Hàm ghi thông tin sinh viên vào file text
    fstream fs;
    fs.open("data_log.txt", ios::app);
    if (fs.is_open()) {
    fs << this->msv;
    fs << ";";
    fs << this->HoVaTen << ";";
    fs << this->birth << ";";
    fs << this->gpa << ";"; 
    fs << endl;
    fs.close();
    }
}
void SinhVien::Output () {                        //Hàm xuất thông tin sinh viên ra màn hình
    cout << "MSV: " <<  this->msv << endl << "Ho va ten: " << this->HoVaTen << endl << "Ngay thang nam sinh: " << this->birth << endl << "GPA: " << this->gpa << endl << endl;
}

double SinhVien::getGPA () {                        //Hàm lấy GPA khỏi vùng private của Class Sinh Viên
    return this->gpa;
}
string SinhVien::getMSSV() const {              //Lấy tên và mssv khỏi private
     return msv;
}
string SinhVien::getName() const {
    return HoVaTen;
}
bool GPAcompare (SinhVien a, SinhVien b) {
    return a.getGPA() > b.getGPA();
}
void Read (fstream fs) {                            //Hàm đọc thông tin sinh viên từ file text
    fs.open("data_log.txt", ios::in);
    if (fs.is_open()) {
        string line;
        while (getline(fs, line)) {
            cout << line << endl;
        }
        fs.close();
    }
}
void xoaSinhVien(vector<SinhVien> &danhSach) {
    bool found = false;
    string key; getline(cin,key);
    // Duyệt danh sách để tìm sinh viên cần xóa
    for (int i = 0; i < danhSach.size(); ++i) {
        if (danhSach[i].getMSSV() == key || danhSach[i].getName() == key) {
            cout << "Đã xóa sinh viên: ";
            danhSach[i].Output();
            danhSach.erase(danhSach.begin() + i); // Xóa sinh viên tại chỉ số i
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy sinh viên có MSSV hoặc tên: " << key << endl;
    }
}
// Ham xoa sinh vien dua tren MSV
void DeleteStudentByMSV(const string &filename, string &target_msv) {
    fstream read_file;
    read_file.open(filename, ios::in);
    if (!read_file.is_open()) {
        cout << "Khong the mo tep de doc!" << endl;
        return;
    }
    vector<string> lines;
    string line;
    while (getline(read_file, line)) {
        size_t semicolon_pos = line.find(';');
        if (semicolon_pos != string::npos) {
            string msv = line.substr(0, semicolon_pos);
            if (msv != target_msv) {
                lines.push_back(line);
            }
        }
    }
    read_file.close();

    // Ghi lai cac dong con lai vao tep
    ofstream write_file(filename, ios::out | ios::trunc);
    if (!write_file.is_open()) {
        cout << "Khong the mo tep de ghi!" << endl;
        return;
    }

    for (const string &remaining_line : lines) {
        write_file << remaining_line << endl;
    }
    write_file.close();

    cout << "Da xoa sinh vien co MSV: " << target_msv << endl;
}
void SinhVien::UpdateField() {
        int choice;
        /*cout << "Chọn thông tin cần thay đổi:" << endl;
        cout << "1. Họ và tên" << endl;
        cout << "2. MSSV" << endl;
        cout << "3. GPA" << endl;
        cout << "4. Ngày sinh" << endl;
        cout << "Lựa chọn: ";*/
        cin >> choice;

        cin.ignore(); // Loại bỏ ký tự thừa sau khi nhập số

        switch (choice) {
            case 1: {
                cout << "Nhập họ và tên mới: ";
                getline(cin, HoVaTen);
                break;
            }
            case 2: {
                cout << "Nhập MSSV mới: ";
                cin >> msv;
                break;
            }
            case 3: {
                cout << "Nhập GPA mới: ";
                cin >> gpa;
                break;
            }
            case 4: {
                cout << "Nhập ngày sinh mới (dd/mm/yyyy): ";
                cin.ignore();
                getline(cin, birth);
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ!" << endl;
                break;
        }
}
void chinhSuaSinhVien(vector<SinhVien> &danhSach) {
    if (danhSach.empty()) {
        cout << "Danh sách sinh viên trống!" << endl;
        return;
    }

    // Hiển thị danh sách sinh viên
    cout << "Danh sách sinh viên hiện có:\n";
    for (size_t i = 0; i < danhSach.size(); ++i) {
        cout << i + 1 << ". ";
        danhSach[i].Output();
    }

    // Chọn sinh viên để chỉnh sửa
    string key;
    cout << "\nNhập MSSV hoặc tên sinh viên cần chỉnh sửa: ";
    cin.ignore();
    getline(cin, key);

    bool found = false;
    for (auto &sv : danhSach) {
        if (sv.getMSSV() == key || sv.getName() == key) {
            cout << "\nSinh viên được chọn:\n";
            sv.Output();

            // Gọi hàm cập nhật thông tin của sinh viên
            cout << "\nCập nhật thông tin sinh viên:\n";
            sv.UpdateField();

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Không tìm thấy sinh viên có MSSV hoặc tên: " << key << endl;
    }
}



//Main
int main () {
    cout << "Nhap N: ";
    int n; cin >> n;
    fstream fs;
    for (int i = 0; i < n; i++) {
        SinhVien A;
        A.Input();
        A.Write();
        danhSachSinhVien.push_back(A);
    }
    string s;
    cout << "Nhap mssv cua sinh vien can xoa: ";
    cin.ignore();
    getline(cin, s);
    DeleteStudentByMSV("data_log.txt", s);

    // for (int i = 0; i < n; i++) {
    //     GiangVien A;
    //     A.Input();
    //     danhSachGiangVien.push_back(A);
    // }
    //     xoaGiangVien(danhSachGiangVien);
    // for (int i = 0; i < danhSachGiangVien.size(); i++) {
    //     danhSachGiangVien[i].Output();
    // }
    
}