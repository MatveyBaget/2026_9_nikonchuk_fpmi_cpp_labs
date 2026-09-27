
// solve task with usage of
// dymanic arrays
#include <iostream>
#include <windows.h>
#include <random>
//ввод массива в ручную
void write(int* arr, int size) {
	std::cout << "ведите " << size << " цифр через пробел" << std::endl;
	for (int i = 0; i < size; ++i) {
		int n;
		std::cin >> n;
		if (!(std::cin)||n<0) {
			std::cout << "ошибка ввода!!!" << std::endl;
			std::exit;
		}
		arr[i] = n;
	}
}
// рандомный вводд
void random(int* arr, int size) {
	int maxel, minel;
	
	std::cout << "Ведите границы начала и конца[a,b]" << std::endl;
	std::cin >> minel >> maxel;
	if (minel > maxel) {
		std::swap(minel, maxel);
	}
	if (minel < 0) {
		std::cout << "должно быть натуральным" << std::endl;
		std::exit;
	}
	std::mt19937 gen(10000);
	std::uniform_int_distribution<int> dist(minel, maxel);
	for (int i = 0; i < size; ++i) {
		arr[i] = dist(gen);
	}

}
// вывод маасив
void print(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
}
//расчет 
void toi(int* arr, int size) {
	int max, min;
	
	min = arr[9];
	max = arr[0];
	for (int i = 0; i < size; ++i) {
		if (min > arr[i]) {
			
			min = arr[i];
		}
		if (max < arr[i]) {

			max = arr[i];

		}
	}
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	// аврифметич
	double roi = (static_cast<double>(sum) - min - max) / (size - 2);
	std::cout << "Итоговая оцунка:" << roi << std::endl;
	}
int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	std::cout << "Ведите количество судей" << std::endl;
	int size; // количество судей
	std::cin >> size;
		if (!(std::cin) || size <= 0) {
			std::cout << "ошибка ввода!!" << std::endl;
			return 1;
	}
		int* arr = new int[size];
		std::cout << "Как вы хотите вести цифры 1-вручную; 2-рандом. " << std::endl;
		int choos;
		std::cin >> choos;
		if (choos == 1) {
			write(arr, size);
		}
		else if (choos == 2) {
			random(arr, size);
		}
		else {
			std::cout << "Ошибка ввода" << std::endl;
			delete[] arr;
			return 1;
		}
		std::cout << "Оценки судей" ;
		print(arr, size);
		std::cout << "" << std::endl;
		toi(arr, size);
		delete[] arr;
		return 0;
}
