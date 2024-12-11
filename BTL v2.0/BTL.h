
#ifndef BTL_h
#define BTL_h

#include <bits/stdc++.h>
#include <string>
using namespace std;
struct Truong {                                     //Struct của 1 trường
    string truong;
    string khoa;
};
struct NodeHS {                   //Khởi tạo link list hs
    string HovaTen;
    string msv;
    string birth;
    Truong school;
    double gpa;
    NodeHS *next;
};
// typedef NodeHS* nodehs;
struct NodeGV {                   //Khởi tạo link list gv
    string HovaTen;
    string msv;
    string birth;
    Truong school;
    NodeHS *next;
};

class SinhVien {                                    //Định nghĩa Class Sinh Viên
    friend class vector;
    friend class string;
    private:
        std::string HoVaTen;                             
        std::string msv;
        double gpa;
        std::string birth;
        Truong School;
        static int total_sv;                        //Hàm đếm tổng số sinh viên
    public:
        void Input();                               //Các Function của Class Sinh Viên
        void Output();
        double getGPA();
        void Write();
        string getMSSV() const;
        string getName() const;
        string getBirth() const;
        //void UpdateField();
};
class GiangVien {                                    //Định nghĩa của Class Giảng Viên
    friend class vector;
    private: 
        std::string HoVaTen;
        std::string msv;
        std::string birth;
        static int total_gv;
        Truong School;
    public: 
        void Input ();                              //Các Function thuộc Class Giảng Viên
        void Output ();
        // void Write(fstream &fs);
        std::string getMSGV() const;
        std::string getName() const;
        //void xoaGiangVien (vector<GiangVien> &danhSach);
        void UpdateField();
        void Write(const string& filename);
        vector<GiangVien> ReadGiangVienFromFile(const string&filename, vector<GiangVien> danhSachGiangVien);
};



//Các hàm thuộc Class Giảng Viên:
void GiangVien::Input () {                          //Hàm nhập thông tin của giảng viên vào chương trình
    std::cout << "Nhập mã của giảng viên: "; std::cin >> this->msv;   
    std::cin.ignore();
    cout << "Nhập họ và tên giảng viên: "; std::getline(std::cin,this->HoVaTen);
    cout << "Nhập ngày tháng năm sinh: "; cin >> this->birth;
    cout << "Nhập khoa giảng viên trực thuộc: "; cin >> this->School.khoa;
    cout << "Nhập trường giảng viên trực thuộc: "; cin >>this->School.truong;
}
void GiangVien::Output() {                         //Hàm xuất thông tin của giảng viên ra màn hình
    cout << "MSV: " <<  this->msv << endl << "Họ và tên: " << this->HoVaTen << endl << "Ngày tháng năm sinh: " << this->birth << endl << "Khoa: " << this->School.khoa << endl << "Trường: " <<this->School.truong << endl << endl;
}
string GiangVien::getMSGV() const {              //Lấy tên và mssv khỏi private
     return msv;
}
string GiangVien::getName() const {
    return HoVaTen;
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
void GiangVien::UpdateField() {                     //Update thong tin giang vien
        int choice;
        /*cout << "Chọn thông tin cần thay đổi:" << endl;
        cout << "1. Họ và tên" << endl;
        cout << "2. MSV (Mã số giảng viên)" << endl;
        cout << "3. Ngày sinh" << endl;
        cout << "4. Tên trường" << endl;
        cout << "5. Khoa" << endl;
        cout << "Lựa chọn: ";*/
        cin >> choice;

        cin.ignore(); // Loại bỏ ký tự thừa sau khi nhập số

        switch (choice) {
            case 1: {
                cout << "Nhập họ và tên mới: ";
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
                getline(cin, School.truong);
                break;
            }
            case 5: {
                std::cout << "Nhập khoa mới: ";
                std::getline(std::cin, School.khoa);
                break;
            }
            default:
                std::cout << "Lựa chọn không hợp lệ!" << endl;
                break;
        }
}
void xoaGiangVien(vector<GiangVien> &danhSach) {
    bool found = false;
    std::cin.ignore();
    std::string key; std::getline(std::cin,key);
    // Duyệt danh sách để tìm sinh viên cần xóa
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
vector<GiangVien> danhSachGiangVien;                     //Vector Giang Vien
vector<GiangVien> GiangVien:: ReadGiangVienFromFile(const string& filename, vector<GiangVien> danhSachGiangVien) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Không thể mở file!" << endl;
        return danhSachGiangVien;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        GiangVien gv;
        string truong, khoa;

        // Tách các phần thông tin dựa trên dấu phân cách `;`
        getline(ss, gv.msv, ';');
        getline(ss, gv.HoVaTen, ';');
        getline(ss, gv.birth, ';');
        getline(ss, khoa, ';');
        getline(ss, truong, ';');

        gv.School.khoa = khoa;
        gv.School.truong = truong;

        danhSachGiangVien.push_back(gv);
    }

    file.close();
    return danhSachGiangVien;
}
void GiangVien::Write (const string& filename) {                //Hàm ghi thông tin sinh viên vào file text
    fstream fs(filename);
    fs.open("data_log.txt", ios::app);
    if (fs.is_open()) {
    fs << this->msv;
    fs << ";";
    fs << this->HoVaTen << ";";
    fs << this->birth << ";";
    fs << endl;
    fs.close();
    }
}



//Từ đoạn này là hàm thuộc Class Sinh Viên
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
void Read () {                            //Hàm đọc thông tin sinh viên từ file text
    fstream fs;
    fs.open("data_log.txt", ios::in);
    if (fs.is_open()) {
        string line;
        while (getline(fs, line)) {
            cout << line << endl;
        }
        fs.close();
    }
}



bool GPAcompare (SinhVien a, SinhVien b) {
    return a.getGPA() > b.getGPA();
}
string SinhVien::getMSSV() const {
    return msv;
}
string SinhVien::getName() const {
    return HoVaTen;
}
string SinhVien::getBirth() const {
    return birth;
}


//NODE FUNCTION:
bool CompareByMSSV(NodeHS *a, NodeHS *b) {
    for (size_t i = 0;i < a->msv.size();i++) {
        if (a->msv[i] > b->msv[i]) {
            return true;
            break;
        }
        else {
            return false;
            break;
        }
    }
    return false;
}
bool CompareByNameAscending(NodeHS* a, NodeHS* b) {
    return a->HovaTen > b->HovaTen;
}
bool CompareByGPA (NodeHS *a, NodeHS*b) {
    return a->gpa > b->gpa;
}
void InsertNode (NodeHS *&head, string birth, string msv, string HovaTen, double gpa) {         //Thêm 1 phần tử vào đầu của link list
    NodeHS *NewNode = new NodeHS();
    NewNode->msv = msv;
    NewNode->birth = birth;
    NewNode->gpa = gpa;
    NewNode->HovaTen = HovaTen;
    NewNode->next = head;
    head = NewNode;
}
void PrintList (NodeHS *head) {
    NodeHS *curr = head;
    while (curr != nullptr) {
        cout << curr->msv  << "\t" << curr->HovaTen << "\t" << curr->birth << "\t" << curr->school.khoa << "\t" << curr->school.truong << "\t" << curr->gpa << endl;
        curr = curr->next;
    }
    cout <<"Empty" << endl;
}
NodeHS *findMiddle (NodeHS *head) {                //Tìm phần tử ở giữa Link List => MergeSort
    if (!head || !head -> next) return head;

    NodeHS *slow = head;
    NodeHS *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    } 
    return slow;
}
NodeHS* Merge (NodeHS *left, NodeHS *right, function<bool(NodeHS*, NodeHS*)> comperator) {          //Đơn giản là merge
    if (!left) return right;
    if (!right) return left;

    if (comperator(left, right)) {
        left->next = Merge(left->next, right, comperator);
        return left;
    }
    else {
        right->next = Merge(left, right->next, comperator);
        return right;
    }
}
NodeHS* MergeSort (NodeHS *head, function<bool(NodeHS*, NodeHS*)> comperator) {         //Merge Sort, n(logn)
    if (!head || !head -> next) return head;
    NodeHS *middle = findMiddle(head);
    NodeHS *rhead = middle ->next;
    middle->next = nullptr;
    NodeHS*left = MergeSort(head, comperator);
    NodeHS*right = MergeSort(head, comperator);
    return Merge(left, right, comperator); 
}
#endif