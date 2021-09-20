#define Student_H
#ifdef Student_H
#include<stdio.h>
#include<conio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#define MAX 1000
using namespace std;
// Tạo cấu trúc Student
struct Ngaysinh {
	int ngay;
	int thang;
	int nam;
};
struct SinhVien {
	int id;
	char ten[30];
	char gtinh[5];
	int tuoi;
	float dToan;
	float dLy;
	float dHoa;
	float dTB = 0;
	char xLoai[10] = "-";
	Ngaysinh ngaysinh;
};
struct ArrList
{
	SinhVien stud[MAX];
	int len = 0;
	int maxLen = MAX;
};
int keyPress(int Clear);
void printLine(int n);
bool isEmpty(ArrList& dsSV);
bool isFull(ArrList& dsSV);
void tinhDTB(SinhVien& ItemSV);
void xeploai(SinhVien& ItemSV);
void capNhatThongTinSV(SinhVien& ItemSV);
void nhapThongTinSV(ArrList& dsSV, int id);
void nhapSV(ArrList& dsSV);
void capNhatSV(ArrList& dsSV, int id);
int xoaTheoID(ArrList& dsSV, int id);
void timKiemTheoTen(ArrList& dsSV, char ten[]);
void sapxepTheoDTB(ArrList& dsSV);
void sapXepTheoTen(ArrList& dsSV);
void showStudent(ArrList& dsSV);
void showOne(SinhVien sv);
void docFile(ArrList& dsSV, char fileName[]);
void ghiFile(ArrList& dsSV, char fileName[]);
#endif