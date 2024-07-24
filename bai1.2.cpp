#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tạo mảng ngẫu nhiên chứa toàn số chẵn
void createEvenRandomArray(int arr[], int n, int lower, int upper) {
    for (int i = 0; i < n; i++) {
        int num;
        do {
            num = lower + rand() % (upper - lower + 1);
        } while (num % 2 != 0); // Lặp lại cho đến khi tìm được số chẵn
        arr[i] = num;
    }
}

int main() {
    srand(time(0)); // Khởi tạo hạt giống cho hàm rand()

    int n = 15; // Số phần tử của mảng (>= 15)
    int lower = 0; // Giá trị nhỏ nhất có thể có trong mảng
    int upper = 100; // Giá trị lớn nhất có thể có trong mảng

    // Cấp phát động bộ nhớ cho mảng
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        return 1;
    }

    createEvenRandomArray(arr, n, lower, upper);

    printf("Mảng ngẫu nhiên chứa toàn số chẵn:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Giải phóng bộ nhớ đã cấp phát
    free(arr);

    return 0;
}
