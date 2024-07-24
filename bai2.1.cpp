#include <iostream>
#include <cstdlib>

using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

struct MixedNumber {
	int integer;
	Fraction fraction;
};

void createRandomMixedNumberArray(MixedNumber* b, int n) {
	for (int i = 0; i < n; i++) {
		b[i].integer = rand() % 11; // Số nguyên ngẫu nhiên từ 0 đến 10
		do {
			b[i].fraction.numerator = rand() % 21 - 10; // Tử số ngẫu nhiên từ -10 đến 10
			b[i].fraction.denominator = rand() % 10 + 1; // Mẫu số ngẫu nhiên từ 1 đến 10
		} while (b[i].fraction.denominator == 0); // Đảm bảo mẫu số khác 0
	}
}

void printMixedNumberArray(MixedNumber* b, int n) {
	for (int i = 0; i < n; i++) {
		cout << b[i].integer << " + " << b[i].fraction.numerator << "/" << b[i].fraction.denominator << "\n";
	}
}

int main() {
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;

	MixedNumber* b = new MixedNumber[n];
	createRandomMixedNumberArray(b, n);

	cout << "Mang chua cac gia tri hon so:\n";
	printMixedNumberArray(b, n);

	delete[] b;
	return 0;
}
