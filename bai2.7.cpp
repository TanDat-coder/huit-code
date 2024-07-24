#include <stdio.h>

// Cấu trúc cho hỗn số
typedef struct {
	int phan_nguyen;
	int tu_so;
	int mau_so;
} HonSo;

// Hàm in hỗn số
void printHonSo(HonSo hs) {
	printf("%d %d/%d\n", hs.phan_nguyen, hs.tu_so, hs.mau_so);
}

// Hàm in mảng hỗn số
void printArray(HonSo b[], int n) {
	for (int i = 0; i < n; i++) {
		printHonSo(b[i]);
	}
}

// Hàm tính giá trị của hỗn số dưới dạng số thực
float giaTriHonSo(HonSo hs) {
	return hs.phan_nguyen + (float)hs.tu_so / hs.mau_so;
}

// Hàm sắp xếp Bubble Sort
void bubbleSort(HonSo b[], int n, int tang_dan) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			float value1 = giaTriHonSo(b[j]);
			float value2 = giaTriHonSo(b[j + 1]);
			if (tang_dan ? value1 > value2 : value1 < value2) {
				HonSo temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
}

// Hàm sắp xếp Selection Sort
void selectionSort(HonSo b[], int n, int tang_dan) {
	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			float value1 = giaTriHonSo(b[min_idx]);
			float value2 = giaTriHonSo(b[j]);
			if (tang_dan ? value1 > value2 : value1 < value2) {
				min_idx = j;
			}
		}
		HonSo temp = b[min_idx];
		b[min_idx] = b[i];
		b[i] = temp;
	}
}

// Hàm sắp xếp Insertion Sort
void insertionSort(HonSo b[], int n, int tang_dan) {
	for (int i = 1; i < n; i++) {
		HonSo key = b[i];
		int j = i - 1;
		float value_key = giaTriHonSo(key);
		while (j >= 0 && (tang_dan ? giaTriHonSo(b[j]) > value_key : giaTriHonSo(b[j]) < value_key)) {
			b[j + 1] = b[j];
			j = j - 1;
		}
		b[j + 1] = key;
	}
}

int main() {
	// Khởi tạo mảng hỗn số
	HonSo b[] = { { 1, 1, 2 }, { 2, 1, 4 }, { 1, 3, 4 }, { 3, 1, 5 } };
	int n = sizeof(b) / sizeof(b[0]);

	printf("Mảng ban đầu:\n");
	printArray(b, n);

	// Sắp xếp tăng dần bằng Bubble Sort
	bubbleSort(b, n, 1);
	printf("\nMảng sau khi sắp xếp tăng dần bằng Bubble Sort:\n");
	printArray(b, n);

	// Sắp xếp giảm dần bằng Selection Sort
	selectionSort(b, n, 0);
	printf("\nMảng sau khi sắp xếp giảm dần bằng Selection Sort:\n");
	printArray(b, n);

	// Sắp xếp tăng dần bằng Insertion Sort
	insertionSort(b, n, 1);
	printf("\nMảng sau khi sắp xếp tăng dần bằng Insertion Sort:\n");
	printArray(b, n);

	return 0;
}
