#include <stdio.h>

// Định nghĩa cấu trúc cho hỗn số
typedef struct {
	int phanNguyen; // Phần nguyên
	int tu;         // Tử
	int mau;        // Mẫu
} HonSo;

// Hàm chuyển hỗn số sang phân số
void chuyenHonSoSangPhanSo(HonSo hs, int *tu, int *mau) {
	*tu = hs.phanNguyen * hs.mau + hs.tu; // Tính tử
	*mau = hs.mau; // Mẫu không thay đổi
}

// Hàm chính
int main() {
	// Khai báo mảng hỗn số
	HonSo b[5] = {
		{ 2, 3, 4 },   // 2 3/4
		{ 1, 1, 2 },   // 1 1/2
		{ 0, 5, 6 },   // 0 5/6
		{ 3, 2, 5 },   // 3 2/5
		{ 4, 1, 3 }    // 4 1/3
	};

	// Chuyển đổi và in ra phân số
	printf("Chuyen doi tu hon so sang phan so:\n");
	for (int i = 0; i < 5; i++) {
		int tu, mau;
		chuyenHonSoSangPhanSo(b[i], &tu, &mau);
		printf("Hỗn số %d: %d/%d\n", i + 1, tu, mau);
	}

	return 0;
}
