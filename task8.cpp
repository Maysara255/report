#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Student {
    string surname;
    int height;
};

vector<Student> generateClassData(int studentCount) {
    vector<string> surnames = {
        "Иванов", "Петров", "Сидоров", "Кузнецов", "Попов", 
        "Васильев", "Смирнов", "Федоров", "Михайлов", "Новиков"
    };
    
    if (studentCount < surnames.size()) {
        surnames.resize(studentCount);
    }
    
    sort(surnames.begin(), surnames.end());
    
    vector<Student> classData;
    srand(time(0));
    
    for (const auto& surname : surnames) {
        int height = 150 + rand() % 41;
        classData.push_back({surname, height});
    }
    
    return classData;
}

void analyzeClass(const vector<Student>& classData) {
    if (classData.empty()) {
        cout << "В классе нет учеников!" << endl;
        return;
    }
    
    auto [minIt, maxIt] = minmax_element(classData.begin(), classData.end(),
        [](const Student& a, const Student& b) {
            return a.height < b.height;
        });
    
    cout << "Результаты анализа класса (" << classData.size() << " учеников):\n";
    cout << "Самый высокий: " << maxIt->surname << " (" << maxIt->height << " см)\n";
    cout << "Самый маленький: " << minIt->surname << " (" << minIt->height << " см)\n";
    
    double average = 0;
    for (const auto& student : classData) {
        average += student.height;
    }
    average /= classData.size();
    cout << "Средний рост в классе: " << average << " см" << endl;
}

int main() {
    auto classData = generateClassData(8);

    cout << "Список класса (по алфавиту):\n";
    for (const auto& student : classData) {
        cout << student.surname << ": " << student.height << " см\n";
    }
    cout << endl;
    
    analyzeClass(classData);
    
    return 0;
}