#include <iostream>
using namespace std;

int main() {
    char choice;
    do {
        int K, K1, K2, K3;
        cout << "Введите бюджет подарка (K руб.): ";
        cin >> K;
        cout << "Введите цену яблока (K1 руб.): ";
        cin >> K1;
        cout << "Введите цену апельсина (K2 руб.): ";
        cin >> K2;
        cout << "Введите цену печенья (K3 руб.): ";
        cin >> K3;

        int min_cost = K1 + K2 + K3;
        if (min_cost > K) {
            cout << "Не хватает денег даже на минимальный подарок!" << endl;
        } else {
            int remaining = K - min_cost;

            int max_apples = remaining / K1;
            int max_oranges = remaining / K2;
            int max_cookies = remaining / K3;

            if (max_apples >= max_oranges && max_apples >= max_cookies) {
                cout << "Подарок: 1+" << max_apples << " яблок, 1 апельсин, 1 печенье" << endl;
                remaining -= max_apples * K1;
            } else if (max_oranges >= max_apples && max_oranges >= max_cookies) {
                cout << "Подарок: 1 яблоко, 1+" << max_oranges << " апельсинов, 1 печенье" << endl;
                remaining -= max_oranges * K2;
            } else {
                cout << "Подарок: 1 яблоко, 1 апельсин, 1+" << max_cookies << " печенья" << endl;
                remaining -= max_cookies * K3;
            }

            cout << "Остаток: " << remaining << " руб." << endl;
        }

        cout << "Хотите повторить? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}