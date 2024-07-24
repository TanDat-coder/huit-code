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

// Hàm tính tổng hai hỗn số
HonSo tinhTong(HonSo hs1, HonSo hs2) {
	int tu1, mau1, tu2, mau2;
	chuyenHonSoSangPhanSo(hs1, &tu1, &mau1);
	chuyenHonSoSangPhanSo(hs2, &tu2, &mau2);

	// Tính tử và mẫu của tổng
	HonSo tong;
	tong.tu = tu1 * mau2 + tu2 * mau1;
	tong.mau = mau1 * mau2;
	tong.phanNguyen = tong.tu / tong.mau; // Phần nguyên
	tong.tu %= tong.mau; // Tử còn lại

	return tong;
}

// Hàm tính hiệu hai hỗn số
HonSo tinhHieu(HonSo hs1, HonSo hs2) {
	int tu1, mau1, tu2, mau2;
	chuyenHonSoSangPhanSo(hs1, &tu1, &mau1);
	chuyenHonSoSangPhanSo(hs2, &tu2, &mau2);

	// Tính tử và mẫu của hiệu
	HonSo hieu;
	hieu.tu = tu1 * mau2 - tu2 * mau1;
	hieu.mau = mau1 * mau2;
	hieu.phanNguyen = hieu.tu / hieu.mau; // Phần nguyên
	hieu.tu %= hieu.mau; // Tử còn lại

	return hieu;
}

// Hàm tính tích hai hỗn số
HonSo tinhTich(HonSo hs1, HonSo hs2) {
	int tu1, mau1, tu2, mau2;
	chuyenHonSoSangPhanSo(hs1, &tu1, &mau1);
	chuyenHonSoSangPhanSo(hs2, &tu2, &mau2);

	// Tính tử và mẫu của tích
	HonSo tich;
	tich.tu = tu1 * tu2;
	tich.mau = mau1 * mau2;
	tich.phanNguyen = tich.tu / tich.mau; // Phần nguyên
	tich.tu %= tich.mau; // Tử còn lại

	return tich;
}

// Hàm tính thương hai hỗn số
HonSo tinhThuong(HonSo hs1, HonSo hs2) {
	int tu1, mau1, tu2, mau2;
	chuyenHonSoSangPhanSo(hs1, &tu1, &mau1);
	chuyenHonSoSangPhanSo(hs2, &tu2, &mau2);

	// Tính tử và mẫu của thương
	HonSo thuong;
	thuong.tu = tu1 * mau2;
	thuong.mau = mau1 * tu2;
	thuong.phanNguyen = thuong.tu / thuong.mau; // Phần nguyên
	thuong.tu %= thuong.mau; // Tử còn lại

	return thuong;
}

// Hàm chính
int main() {
	// Khai báo mảng hỗn số
	HonSo b[2] = {
		{ 2, 3, 4 },   // 2 3/4
		{ 1, 1, 2 }    // 1 1/2
	};

	// Tính toán
	HonSo tong = tinhTong(b[0], b[1]);
	HonSo hieu = tinhHieu(b[0], b[1]);
	HonSo tich = tinhTich(b[0], b[1]);
	HonSo thuong = tinhThuong(b[0], b[1]);

	// In kết quả
	printf("Tổng: %d %d/%d\n", tong.phanNguyen, tong.tu, tong.mau);
	printf("Hiệu: %d %d/%d\n", hieu.phanNguyen, hieu.tu, hieu.mau);
	printf("Tích: %d %d/%d\n", tich.phanNguyen, tich.tu, tich.mau);
	printf("Thương: %d %d/%d\n", thuong.phanNguyen, thuong.tu, thuong.mau);

	return 0;
}
