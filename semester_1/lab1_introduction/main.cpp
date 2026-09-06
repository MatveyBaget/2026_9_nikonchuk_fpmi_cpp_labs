#include <iostream>
#include <numeric> 
#include <windows.h> 

int main() {
   
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

   int n, m;

    std::cout << "Введите первое натуральное число (n): ";
    std::cin >> n;

    std::cout << "Введите второе натуральное число (m): ";
    std::cin >> m;

    if (n == 0 || m == 0) {
        std::cout << "Числа должны быть натуральными (больше 0)." << std::endl;
        return 1;
    }

  int gcd_value = std::gcd(n, m);

    std::cout << "Общие делители чисел " << n << " и " << m << ":" << std::endl;

    for ( int i = 1; i <= gcd_value; ++i) {
        if (gcd_value % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
