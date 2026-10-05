
#include <iostream>
#include <windows.h>
#include <random>
#include <cmath>
#include <cstdlib> 
#include <cfloat>  // Для дробных чисел DBL_MAX

// Вввод
void write(double* arr, int size) {
	std::cout << "Ведите элементы через пробел" << std::endl;
	for (int i = 0; i < size; ++i) {
		double n;
		std::cin >> n;
		if (!(std::cin)) {
			std::cout << "Ошибка ввода" << std::endl;
			std::exit(1);

		}
		arr[i] = n;
	}
}


// вывод
void print(double* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
}


// рандом
void random(double* arr, int size, std::mt19937* gen) {
	double max, min;
	std::cout << "Ведите границы [a,b]" << std::endl;
	std::cin >> min >> max;
	if (!(std::cin )) {
		std::cout << "Ошибка ввода! Введите два числа:" << std::endl;
		std::exit(1);
	}
	if (min > max) {
		std::swap(min, max);
	}

	
	std::uniform_real_distribution<double>dist(min, max);
	for (int i = 0; i < size; ++i) {
		arr[i] = dist(*gen);
	}

}


// преоброзование
void trans(double* arr, int size) {

	int number = 0; //это какая по счетту пременая
	double toi2 = DBL_MAX;
	double toi1; //счетчик нк типо с ним сравниваем

	int count = 0;


	for (int i = 0; i < size; ++i) {
		double sum1 = 0;
		double sum2 = 0; // вот это мы сравниваем
		int up = i + 1; // вторая половина
		int r = 0;
		while (r < i) {
			sum1 = sum1 + arr[r];
			r += 1;
		}
		while (up < size) {
			sum2 = sum2 + arr[up];
			up += 1;
		}
		double toi1 = std::abs(sum1 - sum2);
		count += 1;


		if (toi1 < toi2) {
			toi2 = toi1;
			number = count;
		}

	}

	std::cout << "перемена по счету " << number << " приблизительно делит  массив на равные по сумме части" << std::endl;
}

int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);

	int size; // размер маассива
	std::cout << "ведите количество переменных(больше двух)" << std::endl;
	std::cin >> size;
	if (!(std::cin) || size <= 2) {
		std::cout << "Ошибка ввода" << std::endl;
		return 1;
	}
	std::random_device rd;
	std::mt19937 gen(rd());
	double* arr = new double[size];
	std::cout << "как вы хотите заполнить массив:" << std::endl;
	std::cout << "1-вручную" << std::endl;
	std::cout << "2-рандом" << std::endl;
	int choose;
	std::cin >> choose;

	if (choose == 1) {
		write(arr, size);

	}


	else if (choose == 2) {
		random(arr, size, &gen);

	}

	else {
		std::cout << "Ошибка ввода" << std::endl;
		delete[] arr;
		return 1;
	}
	std::cout << "Элементы массива: ";
	print(arr, size);
	std::cout << " " << std::endl;
	trans(arr, size);
	delete[] arr;
	return 0;
}
