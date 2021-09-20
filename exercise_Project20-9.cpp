#include"Student.h"
using namespace std;
bool isEmpty(ArrList& dsSV) {
	return (dsSV.len == 0) ? true : false;
}
bool isFull(ArrList& dsSV){
	return (dsSV.len == dsSV.maxLen) ? true : false;
}
void tinhDTB(SinhVien& ItemSV) {
	ItemSV.dTB = (ItemSV.dHoa + ItemSV.dLy + ItemSV.dToan) / 3;
}
void xeploai(SinhVien& ItemSV) {
	if (ItemSV.dTB >= 8) {
		strcpy(ItemSV.xLoai,(char*)"Gioi");
	}
	else if(ItemSV.dTB >= 6.5){
		strcpy(ItemSV.xLoai, (char*)"Kha");
	}
	else {
		strcpy(ItemSV.xLoai, (char*)"TB");
	}
}
void nhapThongTinSV(ArrList& dsSV, int id) {
	cout << "Ten: "; cin.getline(dsSV.stud[dsSV.len].ten,30);
	cout << "Gioi Tinh:"; cin.getline(dsSV.stud[dsSV.len].gtinh,5);
	cout << "Tuoi: "; cin >> dsSV.stud[dsSV.len].tuoi;
	cout << "Ngay Thang Nam Sinh: "; cin >> dsSV.stud[dsSV.len].ngaysinh.ngay >> dsSV.stud[dsSV.len].ngaysinh.thang >> dsSV.stud[dsSV.len].ngaysinh.ngay;
	cout << "Diem Toan: "; cin >> dsSV.stud[dsSV.len].dToan;
	cout << "Diem Ly: "; cin >> dsSV.stud[dsSV.len].dLy;
	cout << "Diem Hoa: "; cin >> dsSV.stud[dsSV.len].dHoa;
	tinhDTB(dsSV.stud[dsSV.len]);
	dsSV.len++;
}
int xoaTheoID(ArrList& dsSV, int id) {
	if (dsSV.len <= 0) {
		return;
	}
	
	bool check = false;
	for (int i = 0; i < dsSV.len; i++) {
		if (dsSV.stud[i].id==id) {
			for (int j = i; j < dsSV.len - 1; j++) {
				dsSV.stud[j] = dsSV.stud[j + 1];
				check = true;
		   }
		    
		}
		if (check == true) {
			break;
		}
	}
	dsSV.len--;
}
void showOne(SinhVien sv) {
	cout << "ID: " << sv.id << endl;
	cout << "Ten: " << sv.ten << endl;
	cout << "Gioi Tinh:" << sv.gtinh << endl;
	cout << "Tuoi: " << sv.tuoi << endl;
	cout << "Ngay Thang Nam Sinh: " << sv.ngaysinh.ngay << "/" << sv.ngaysinh.thang << "/" << sv.ngaysinh.nam << endl;
	cout << "Diem Toan: " << sv.dToan << endl;
	cout << "Diem Ly: " << sv.dLy << endl;
	cout << "Diem Hoa: " << sv.dHoa << endl;
	cout << "DTB: " << sv.dTB << endl;
	cout << "Xep loai: " << sv.xLoai << endl;
}
void showStudent(ArrList& dsSV) {
	for (int i = 0; i < dsSV.len; i++) {

	}
}
void timKiemTheoTen(ArrList& dsSV, char ten[]) {
	SinhVien t[MAX];
	for (int i = 0; i < dsSV.len; i++) {
		if (strcmp(ten, dsSV.stud[i].ten)==0){

		}
	 }
}
void swap(SinhVien& sv1, SinhVien& sv2) {
	SinhVien sv = sv1;
	sv1 = sv2;
	sv2 = sv;
}
void sapxepTheoDTB(ArrList& dsSV) {
	int minIndex;
	for (int i = 0; i < dsSV.len; i++) {
		minIndex = i;
		for (int j = 0; j < dsSV.len; i++) {
			if (dsSV.stud[minIndex].dTB < dsSV.stud[j].dTB) {
				minIndex = j;
			}
			swap(dsSV.stud[minIndex],dsSV.stud[i]);
	   }
	}
}
void sapXepTheoTen(ArrList& dsSV) {
	char sv1[30];
	char sv2[30];
	bool check = false;
	for (int i = 0; i < dsSV.len; i++) {
		strcpy(sv1, dsSV.stud[i].ten);
		for(int j = 0;j<dsSV.len;j++){
			strcpy(sv2, dsSV.stud[j].ten);
			if (strcmp(sv1, sv2) > 0) {
				swap(dsSV.stud[j], dsSV.stud[i]);
			}
		}
	}
}
void capNhatSV(ArrList& dsSV, int id) {
	for (int i = 0; i < dsSV.len; i++) {
		if (dsSV.stud[i].id == id) {
			cout << "Ten: "; cin.getline(dsSV.stud[i].ten, 30);
			cout << "Gioi Tinh:"; cin.getline(dsSV.stud[i].gtinh, 5);
			cout << "Tuoi: "; cin >> dsSV.stud[i].tuoi;
			cout << "Ngay Thang Nam Sinh: "; cin >> dsSV.stud[i].ngaysinh.ngay >> dsSV.stud[i].ngaysinh.thang >> dsSV.stud[i].ngaysinh.ngay;
			cout << "Diem Toan: "; cin >> dsSV.stud[i].dToan;
			cout << "Diem Ly: "; cin >> dsSV.stud[i].dLy;
			cout << "Diem Hoa: "; cin >> dsSV.stud[i].dHoa;
	  }
	}
}
void docFile(ArrList& dsSV, char fileName[]) {
	int size = 0;
	ifstream fileInput(fileName);

	if (fileInput.fail())
	{
		cout << "Failed to open this file!" << endl;
		return ;
	}
	while (!fileInput.eof())
	{
		 fileInput >> dsSV.stud[size].id >> dsSV.stud[size].ten >> dsSV.stud[size].gtinh >> dsSV.stud[size].tuoi
			>> dsSV.stud[size].ngaysinh.ngay >> dsSV.stud[size].ngaysinh.thang >> dsSV.stud[size].ngaysinh.nam
			>> dsSV.stud[size].dToan >> dsSV.stud[size].dLy >> dsSV.stud[size].dHoa;
		  dsSV.stud[size].dTB = (dsSV.stud[size].dToan + dsSV.stud[size].dLy + dsSV.stud[size].dHoa) / 3;
	}
	cout << endl;
	fileInput.close();
}
void ghiFile(ArrList& dsSV, char fileName[]) {
	int size = 0;
	ofstream myfile;
	myfile.open(fileName);

	if (myfile.fail())
	{
		cout << "Failed to open this file!" << endl;
		return;
	}
	while (size<dsSV.len )
	{
		myfile << dsSV.stud[size].id << dsSV.stud[size].ten << dsSV.stud[size].gtinh << dsSV.stud[size].tuoi
			<< dsSV.stud[size].ngaysinh.ngay << dsSV.stud[size].ngaysinh.thang << dsSV.stud[size].ngaysinh.nam
			<< dsSV.stud[size].dToan << dsSV.stud[size].dLy << dsSV.stud[size].dHoa<<dsSV.stud[size].dTB;
		size++;
	}
}
int main() {

}