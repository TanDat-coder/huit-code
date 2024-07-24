#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Hàm khởi tạo mảng a với n phần tử ngẫu nhiên từ 0 đến 99
void initArray(int a[], int n) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 100;
	}
}

// Hàm sắp xếp mảng a tăng dần theo thuật toán Selection Sort
void selectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[minIndex]) {
				minIndex = j;
			}
		}
		swap(a[i], a[minIndex]);
	}
}

int main() {
	int n;
	cout << "Nhap kich thuoc mang: ";
	cin >> n;
	int a[n];

	// Khởi tạo mảng a với n phần tử ngẫu nhiên từ 0 đến 99
	initArray(a, n);

	cout << "Mang truoc khi sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	// Sắp xếp mảng a tăng dần theo thuật toán Selection Sort
	selectionSort(a, n);

	cout << "Mang sau khi sap xep: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}