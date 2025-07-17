#include <iostream>
using namespace std;

int main() {
    int N;            
    int swim_hour;    

    cout << "Сколько человек в очереди? ";
    cin >> N;
    
    cout << "На какой час записан сеанс в бассейне? (например, 13 для 13:00) ";
    cin >> swim_hour;
    
    int total_wait_minutes = N * 15;  
    
    int end_hour = 12 + (total_wait_minutes / 60);  
    int end_minute = total_wait_minutes % 60;      
    
    end_minute += 30;
    
    if (end_minute >= 60) {
        end_hour += 1;
        end_minute -= 60;
    }
    
    if (end_hour < swim_hour || (end_hour == swim_hour && end_minute == 0)) {
        cout << "Успеваете! Придёте как раз к " << swim_hour << ":00" << endl;
    } else {
        cout << "Не успеваете. Ближайший сеанс в " << swim_hour + 1 << ":00" << endl;
    }
    
    return 0;
}