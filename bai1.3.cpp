#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *a, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

int main() {
	int n, x;
	printf("Nhap so phan tu n: ");
	scanf("%d", &n);

	int *a = (int*)malloc(n * sizeof(int));
	printf("Nhap cac phan tu cho mang a:\n");
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 101; // khởi tạo mảng a với các số ngẫu nhiên từ 0 đến 100
		printf("%d ", a[i]);
	}
	printf("\nNhap gia tri x can tim: ");
	scanf("%d", &x);

	int position = linearSearch(a, n, x);
	if (position == -1) {
		printf("Khong tim thay %d trong mang a\n", x);
	}
	else {
		printf("%d nam o vi tri %d trong mang a\n", x, position);
	}

	free(a); // giải phóng bộ nhớ đã cấp phát
	return 0;
}