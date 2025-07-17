#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Функция для вычисления средней длины слов
double averageWordLength(const string& text) {
    istringstream iss(text);
    string word;
    int totalLength = 0;
    int wordCount = 0;
    
    while (iss >> word) {
        totalLength += word.length();
        wordCount++;
    }
    
    return wordCount > 0 ? static_cast<double>(totalLength) / wordCount : 0.0;
}

// Функция для нахождения самого длинного слова
string findLongestWord(const string& text) {
    istringstream iss(text);
    string word, longest;
    
    while (iss >> word) {
        if (word.length() > longest.length()) {
            longest = word;
        }
    }
    
    return longest;
}

// Функция для создания форматированного текста
string createFormattedText(const string& text, size_t maxLength) {
    istringstream iss(text);
    string word, result;
    
    while (iss >> word) {
        result += word;
        if (word.length() < maxLength) {
            result += string(maxLength - word.length(), ' ');
        }
        result += " ";
    }
    
    return result;
}

void processTextFile(const string& inputFile, const string& outputFile) {
    // Чтение файла
    ifstream fin(inputFile);
    if (!fin) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return;
    }
    
    string line, text;
    while (getline(fin, line)) {
        text += line + " ";
    }
    fin.close();
    
    // Задача 1: Средняя длина слов
    double avgLength = averageWordLength(text);
    cout << "1. Средняя длина слов: " << avgLength << endl;
    
    // Задача 2: Форматирование текста
    string longestWord = findLongestWord(text);
    size_t maxLength = longestWord.length();
    cout << "2. Самое длинное слово: \"" << longestWord 
         << "\" (" << maxLength << " символов)" << endl;
    
    string formattedText = createFormattedText(text, maxLength);
    
    // Запись в файл
    ofstream fout(outputFile);
    if (!fout) {
        cerr << "Ошибка создания выходного файла!" << endl;
        return;
    }
    
    fout << formattedText;
    fout.close();
    
    cout << "Форматированный текст записан в файл: " << outputFile << endl;
}

int main() {
    const string inputFile = "F1.txt";
    const string outputFile = "F2.txt";
    
    // Создаем тестовый файл, если его нет
    ofstream createTestFile(inputFile);
    if (createTestFile) {
        createTestFile << "This is a sample text\n"
                       << "for testing file operations\n"
                       << "in C++ programming";
        createTestFile.close();
        cout << "Создан тестовый файл " << inputFile << endl;
    }
    
    // Обработка файла
    processTextFile(inputFile, outputFile);
    
    return 0;
}