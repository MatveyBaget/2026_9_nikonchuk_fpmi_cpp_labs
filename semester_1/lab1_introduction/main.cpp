#include <iostream>
#include <windows.h>
#include <algorithm>
int main() {
	SetConsoleCP(65001);
	SetConsoleOutputCP(65001);
	int n, m;
	std::cout << "ВЕДИТЕ( ЛЮБОЕ НАТУРАЛЬНОЕ ЧИСЛО n:";
	std::cin >> n;
	std::cout << "ведите любое натуральное число m:";
	std::cin >> m;
	if (m <= 0 || n <= 0) {
		std::cout << "это не натурально число ведите другие";
		return 0;
	}
	std::cout << "Общие делители чисел " << n << " и " << m << ": ";
	int Max_number = (std::min)(n, m);
	for (int i = 1; i <= Max_number; ++i) { 
		if (n % i == 0 && m % i == 0) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
	return 0;

}
