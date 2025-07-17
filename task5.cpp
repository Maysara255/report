#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double V1, V2, T;
    cout << "Введите скорость первого пловца (км/ч): ";
    cin >> V1;
    cout << "Введите скорость второго пловца (км/ч): ";
    cin >> V2;
    cout << "Введите время тренировки (часы): ";
    cin >> T;

    V1 = V1 * 1000 / 3600;
    V2 = V2 * 1000 / 3600;

    const double pool_length = 50.0;

    bool meet_at_start = false;
    double meet_time = 0.0;

    for (double t = 0; t <= T * 3600; t += 1) {
        double current_V1 = V1 * pow(0.95, t / 3600);
        double current_V2 = V2 * pow(0.97, t / 3600);

        // Вычисляем пройденные расстояния
        double distance1 = fmod(current_V1 * t, 2 * pool_length);
        double distance2 = fmod(current_V2 * t, 2 * pool_length);

        if (distance1 > pool_length) distance1 = 2 * pool_length - distance1;
        if (distance2 > pool_length) distance2 = 2 * pool_length - distance1;

        if (fabs(distance1) < 0.1 && fabs(distance2) < 0.1) {
            meet_at_start = true;
            meet_time = t / 3600; // Переводим секунды в часы
            break;
        }
    }

    if (meet_at_start) {
        cout << "Пловцы встретятся в точке начала движения через " << meet_time << " часов." << endl;
    } else {
        cout << "За время тренировки пловцы не встретились в начале. Вычисляем время первой встречи..." << endl;
        
        double t = T * 3600;
        while (true) {
            t += 1;
            double current_V1 = V1 * pow(0.95, t / 3600);
            double current_V2 = V2 * pow(0.97, t / 3600);

            double distance1 = fmod(current_V1 * t, 2 * pool_length);
            double distance2 = fmod(current_V2 * t, 2 * pool_length);

            if (distance1 > pool_length) distance1 = 2 * pool_length - distance1;
            if (distance2 > pool_length) distance2 = 2 * pool_length - distance1;

            if (fabs(distance1) < 0.1 && fabs(distance2) < 0.1) {
                meet_time = t / 3600;
                cout << "Пловцы встретятся в точке начала движения через " << meet_time << " часов." << endl;
                break;
            }
        }
    }

    return 0;
}