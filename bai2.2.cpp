#include <stdio.h>

// Định nghĩa cấu trúc hỗn số
typedef struct {
	int phanNguyen;
	int tuSo;
	int mauSo;
} HonSo;

// Hàm xuất danh sách hỗn số
void xuatDanhSachHonSo(HonSo* mang, int kichThuoc) {
	for (int i = 0; i < kichThuoc; i++) {
		printf("%d %d/%d\n", mang[i].phanNguyen, mang[i].tuSo, mang[i].mauSo);
	}
}

// Hàm so sánh hai hỗn số
int soSanhHonSo(HonSo a, HonSo b) {
	// Chuyển hỗn số thành số thập phân để so sánh
	float giaTriA = a.phanNguyen + (float)a.tuSo / a.mauSo;
	float giaTriB = b.phanNguyen + (float)b.tuSo / b.mauSo;
	if (giaTriA > giaTriB) return 1;
	else if (giaTriA < giaTriB) return -1;
	else return 0;
}

// Hàm sắp xếp hỗn số bằng giải thuật Bubble Sort
void sapXepHonSo(HonSo* mang, int kichThuoc) {
	for (int i = 0; i < kichThuoc - 1; i++) {
		for (int j = 0; j < kichThuoc - i - 1; j++) {
			if (soSanhHonSo(mang[j], mang[j + 1]) > 0) {
				HonSo temp = mang[j];
				mang[j] = mang[j + 1];
				mang[j + 1] = temp;
			}
		}
	}
}

// Hàm tìm kiếm hỗn số bằng giải thuật Tìm kiếm tuần tự
int timKiemHonSo(HonSo* mang, int kichThuoc, HonSo x) {
	for (int i = 0; i < kichThuoc; i++) {
		if (soSanhHonSo(mang[i], x) == 0) {
			return i; // Trả về chỉ số của phần tử tìm thấy
		}
	}
	return -1; // Không tìm thấy
}

int main() {
	// Tạo mảng chứa các hỗn số
	HonSo mang[] = {
		{ 1, 1, 2 },
		{ 3, 3, 4 },
		{ 2, 2, 3 },
		{ 4, 1, 2 }
	};
	int kichThuoc = sizeof(mang) / sizeof(mang[0]);

	// Xuất danh sách hỗn số ban đầu
	printf("Danh sach hon so ban dau:\n");
	xuatDanhSachHonSo(mang, kichThuoc);

	// Sắp xếp danh sách hỗn số
	sapXepHonSo(mang, kichThuoc);
	printf("\nDanh sach hon so sau khi sap xep:\n");
	xuatDanhSachHonSo(mang, kichThuoc);

	// Tìm kiếm hỗn số trong danh sách
	HonSo x = { 2, 2, 3 };
	int viTri = timKiemHonSo(mang, kichThuoc, x);
	if (viTri != -1) {
		printf("\nTim thay hon so %d %d/%d tai vi tri %d\n", x.phanNguyen, x.tuSo, x.mauSo, viTri);
	}
	else {
		printf("\nKhong tim thay hon so %d %d/%d trong danh sach\n", x.phanNguyen, x.tuSo, x.mauSo);
	}

	return 0;
}
