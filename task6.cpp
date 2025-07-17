#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double polynomial(double x, int n) {
    double result = 0.0;
    for (int i = 0; i <= n; ++i) {
        result += pow(x, i);
    }
    return result;
}

int main() {
    int n = 10;
    double x_start = -0.9; 
    double x_end = 0.9;    
    double step = 0.1;     

    cout << "Вычисление многочлена P(x) = 1 + x + x^2 + ... + x^10 для x ∈ [-0.9; 0.9] с шагом 0.1:\n";
    cout << "   x   |   P(x)   \n";

    for (double x = x_start; x <= x_end + 1e-9; x += step) { 
        double px = polynomial(x, n);
        cout << fixed << setprecision(1) << setw(5) << x << " | " 
             << setprecision(6) << setw(8) << px << endl;
    }

    return 0;
}