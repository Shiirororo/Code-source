
#ifndef BTL_h
#define BTL_h

#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>
#include <algorithm>
struct Truong {                                     //Struct của 1 trường
    std::string truong;
    std::string khoa;
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
        std::string getMSSV() const;
        std::string getName() const;
        void UpdateField();
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

};


#endif