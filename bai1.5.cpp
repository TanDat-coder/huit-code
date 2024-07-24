#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *a, int n, int x) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (a[mid] == x) {
			return mid; // trả về vị trí của x
		}
		else if (a[mid] < x) {
			left = mid + 1; // tìm ở nửa phải
		}
		else {
			right = mid - 1; // tìm ở nửa trái
		}
	}

	return -1; // không tìm thấy x
}

int main() {
	int n, x;
	printf("Nhap so phan tu n: ");
	scanf("%d", &n);

	int *a = (int*)malloc(n * sizeof(int));
	printf("Nhap cac phan tu cho mang a:\n");
	for (int i = 0; i < n; i++) {
		a[i] = i * 2; // khởi tạo mảng a tăng dần
		printf("%d ", a[i]);
	}
	printf("\nNhap gia tri x can tim: ");
	scanf("%d", &x);

	int result = binarySearch(a, n, x);
	if (result == -1) {
		printf("Khong tim thay %d trong mang a.\n", x);
	}
	else {
		printf("Gia tri %d nam o vi tri %d trong mang a.\n", x, result);
	}

	free(a); // giải phóng bộ nhớ đã cấp phát
	return 0;
}