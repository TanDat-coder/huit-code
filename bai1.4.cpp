#include <stdio.h>
#include <stdlib.h>

void interchangeSort(int *a, int n, int order) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (order == 0) { // sắp xếp tăng dần
				if (a[i] > a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
			else { // sắp xếp giảm dần
				if (a[i] < a[j]) {
					int temp = a[i];
					a[i] = a[j];
					a[j] = temp;
				}
			}
		}
	}
}

int main() {
	int n, order;
	printf("Nhap so phan tu n: ");
	scanf("%d", &n);

	int *a = (int*)malloc(n * sizeof(int));
	printf("Nhap cac phan tu cho mang a:\n");
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 101; // khởi tạo mảng a với các số ngẫu nhiên từ 0 đến 100
		printf("%d ", a[i]);
	}
	printf("\nNhap 0 de sap xep tang dan, hoac 1 de sap xep giam dan: ");
	scanf("%d", &order);

	interchangeSort(a, n, order);

	printf("Mang a sau khi sap xep: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	free(a); // giải phóng bộ nhớ đã cấp phát
	return 0;
}