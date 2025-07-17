#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция генерации фиксированной тестовой матрицы
vector<vector<int>> getExampleMatrix() {
    return {
        {1, 0, 3},
        {4, 5, 0},
        {0, 8, 9}
    };
}

// Функция генерации случайной матрицы
vector<vector<int>> generateRandomMatrix(int n, int m, int minVal, int maxVal) {
    vector<vector<int>> mat(n, vector<int>(m));
    for (auto& row : mat) {
        for (int& val : row) {
            val = minVal + rand() % (maxVal - minVal + 1);
        }
    }
    return mat;
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) cout << val << "\t";
        cout << endl;
    }
}

int matrixSum(const vector<vector<int>>& mat) {
    int sum = 0;
    for (const auto& row : mat)
        for (int val : row)
            sum += val;
    return sum;
}

int createBinaryMatrix(vector<vector<int>>& mat) {
    int count = 0;
    for (auto& row : mat)
        for (int& val : row)
            if (val != 0) {
                count++;
                val = 1;
            }
    return count;
}

int main() {
    cout << "Фиксированный пример из задания:\n";
    vector<vector<int>> example = getExampleMatrix();
    
    cout << "Исходная матрица:\n";
    printMatrix(example);
    
    cout << "\nСумма элементов: " << matrixSum(example) << endl;
    
    int nonZero = createBinaryMatrix(example);
    cout << "\nБинарная матрица:\n";
    printMatrix(example);
    cout << "\nНенулевых элементов: " << nonZero << endl;

    // Дополнительно: генерация случайной матрицы
    srand(time(0));
    cout << "\n\nСлучайная матрица:\n";
    auto randomMatrix = generateRandomMatrix(3, 4, -2, 5);
    printMatrix(randomMatrix);
    cout << "Сумма: " << matrixSum(randomMatrix) << endl;
    
    return 0;
}