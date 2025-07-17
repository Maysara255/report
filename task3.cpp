#include <iostream>
#include <unordered_set>

using namespace std;

bool hasUniqueDigits(int number) {
    if (number < 10) return true; 
    
    unordered_set<int> digits;
    while (number > 0) {
        int digit = number % 10;
        if (digits.count(digit) > 0) {
            return false;
        }
        digits.insert(digit);
        number /= 10;
    }
    return true;
}

void printNumbersWithUniqueDigits(int N) {
    for (int i = 1; i <= N; ++i) {
        if (hasUniqueDigits(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    char choice;
    
    do {
        int N;
        cout << "Введите число N: ";
        cin >> N;
        
        if (N < 1) {
            cout << "Число N должно быть не меньше 1." << endl;
        } else {
            cout << "Числа от 1 до " << N << " без повторяющихся цифр:" << endl;
            printNumbersWithUniqueDigits(N);
        }
        
        cout << "Хотите продолжить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}