#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ROWS = 10;
const int SEATS = 15;
const int VIP_START = 3;
const int VIP_END = 7;

struct Prices {
    int regular;
    int premiere;
    int discount;
};

enum SessionType { REGULAR, PREMIERE, DISCOUNT };

vector<vector<bool>> createOccupationMatrix() {
    vector<vector<bool>> matrix(ROWS, vector<bool>(SEATS, false));
    srand(time(0));
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SEATS; j++) {
            if (rand() % 100 < 30) {
                matrix[i][j] = true;
            }
        }
    }
    return matrix;
}

void saveMatrixToFile(const vector<vector<bool>>& matrix, const string& filename) {
    ofstream out(filename);
    for (const auto& row : matrix) {
        for (bool seat : row) {
            out << seat << " ";
        }
        out << "\n";
    }
    out.close();
}

vector<vector<bool>> loadMatrixFromFile(const string& filename) {
    vector<vector<bool>> matrix(ROWS, vector<bool>(SEATS, false));
    ifstream in(filename);
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SEATS; j++) {
            int val;
            in >> val;
            matrix[i][j] = val;
        }
    }
    in.close();
    return matrix;
}

int getTicketPrice(int row, SessionType type, const Prices& prices) {
    int basePrice = 0;
    
    switch (type) {
        case REGULAR: basePrice = prices.regular; break;
        case PREMIERE: basePrice = prices.premiere; break;
        case DISCOUNT: basePrice = prices.discount; break;
    }
    
    if (row < 3) { 
        return basePrice * 0.67; 
    } else if (row >= VIP_START && row <= VIP_END) { 
        return basePrice * 2;
    } else { 
        return basePrice;
    }
}

int calculateTotalRevenue(const vector<vector<bool>>& matrix, SessionType type, const Prices& prices) {
    int total = 0;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < SEATS; j++) {
            if (matrix[i][j]) { // Если место продано
                total += getTicketPrice(i, type, prices);
            }
        }
    }
    
    return total;
}

int main() {
    Prices prices = { 300, 500, 200 }; 
    
    vector<vector<bool>> occupation;
    string filename = "cinema_seats.txt";
    
    ifstream test(filename);
    if (test.good()) {
        test.close();
        occupation = loadMatrixFromFile(filename);
        cout << "Матрица занятости загружена из файла.\n";
    } else {
        occupation = createOccupationMatrix();
        saveMatrixToFile(occupation, filename);
        cout << "Создана новая матрица занятости и сохранена в файл.\n";
    }
    
    cout << "\nМатрица занятости мест (1 - занято, 0 - свободно):\n";
    for (const auto& row : occupation) {
        for (bool seat : row) {
            cout << seat << " ";
        }
        cout << "\n";
    }
    
    SessionType session;
    cout << "\nВыберите тип сеанса:\n"
         << "1. Обычный (" << prices.regular << " руб.)\n"
         << "2. Премьерный (" << prices.premiere << " руб.)\n"
         << "3. Льготный (" << prices.discount << " руб.)\n"
         << "Ваш выбор: ";
    
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: session = REGULAR; break;
        case 2: session = PREMIERE; break;
        case 3: session = DISCOUNT; break;
        default: 
            cout << "Неверный выбор, установлен обычный сеанс.\n";
            session = REGULAR;
    }
    
    int revenue = calculateTotalRevenue(occupation, session, prices);
    cout << "\nОбщая выручка: " << revenue << " руб.\n";
    
    return 0;
}