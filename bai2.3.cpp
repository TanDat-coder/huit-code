#include <stdio.h>

// Định nghĩa cấu trúc hỗn số
typedef struct {
	int phanNguyen;
	float phanSo;
} HonSo;

// Hàm so sánh hai hỗn số
int soSanhHonSo(HonSo a, HonSo b) {
	float giaTriA = a.phanNguyen + a.phanSo;
	float giaTriB = b.phanNguyen + b.phanSo;

	if (giaTriA < giaTriB)
		return -1;
	else if (giaTriA > giaTriB)
		return 1;
	else
		return 0;
}

// Hàm tìm kiếm tuần tự một hỗn số trong mảng
int timKiemHonSo(HonSo arr[], int n, HonSo key) {
	for (int i = 0; i < n; i++) {
		if (soSanhHonSo(arr[i], key) == 0) {
			return i; // Trả về chỉ số nếu tìm thấy
		}
	}
	return -1; // Không tìm thấy
}

// Hàm sắp xếp nổi bọt (Bubble Sort) cho mảng hỗn số
void sapXepHonSo(HonSo arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (soSanhHonSo(arr[j], arr[j + 1]) > 0) {
				// Hoán đổi arr[j] và arr[j+1]
				HonSo temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// Hàm in mảng hỗn số
void inMangHonSo(HonSo arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d + %f\n", arr[i].phanNguyen, arr[i].phanSo);
	}
}

int main() {
	// Tạo mảng các hỗn số
	HonSo arr[] = {
		{ 1, 0.5 },
		{ 2, 0.25 },
		{ 1, 0.75 },
		{ 3, 0.1 }
	};
	int n = sizeof(arr) / sizeof(arr[0]);

	// In mảng trước khi sắp xếp
	printf("Mang truoc khi sap xep:\n");
	inMangHonSo(arr, n);

	// Sắp xếp mảng
	sapXepHonSo(arr, n);

	// In mảng sau khi sắp xếp
	printf("Mang sau khi sap xep:\n");
	inMangHonSo(arr, n);

	// Tìm kiếm một hỗn số trong mảng
	HonSo key = { 2, 0.25 };
	int index = timKiemHonSo(arr, n, key);
	if (index != -1) {
		printf("Tim thay hon so %d + %f tai vi tri %d\n", key.phanNguyen, key.phanSo, index);
	}
	else {
		printf("Khong tim thay hon so\n");
	}

	return 0;
}
