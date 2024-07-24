#include <iostream>
#include <cstdlib>

using namespace std;

void quickSort(int a[], int left, int right) {
	int i = left, j = right;
	int pivot = a[(left + right) / 2];

	while (i <= j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(a, left, j);
	if (i < right)
		quickSort(a, i, right);
}

int main() {
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;

	int a[n];
	cout << "Nhap cac phan tu cua mang:\n";
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 101; // Tao so nguyen ngau nhien tu 0 den 100
		cout << a[i] << " ";
	}
	cout << "\n";

	quickSort(a, 0, n - 1);

	cout << "Mang sau khi sap xep:\n";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "\n";

	return 0;
}