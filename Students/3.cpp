#include <iostream>
using namespace std;

class Students{
private:
    char firstname[50][100];
    char lastname[50][100];
    int count, countofgrades;
    int **arr;
public: 
    Students() : count(0), countofgrades(0), arr(nullptr) {} //Конструктор по умолчанию
    Students(int n, int countofgrades){ //Конструктор с параметрами
        count = n;
        this->countofgrades = countofgrades;

        arr = new int* [count];
        for (int i = 0; i < count; i++){
            arr[i] = new int[this->countofgrades];
        }
        
        for (int i = 0; i < count; i++){
            cout << "Введите фамилию и имя " << i + 1 << " студента: ";
            cin >> firstname[i] >> lastname[i];
        }
        for (int i = 0; i < count; i++){
            cout << "Введите оценки для студента - " << firstname[i] << " " << lastname[i] << ": ";
            for (int j = 0; j < countofgrades; j++){
                cin >> arr[i][j];
            }
        }
    }
    void get(){ //Геттер
        cout << "Студенты: " << endl;
        for (int i = 0; i < count; i++){
            cout << firstname[i] << " " << lastname[i] << endl;
        }
        cout << "Оценки студентов: " << endl;
        for (int i = 0; i < count; i++){
            cout << firstname[i] << " " << lastname[i] << ": ";
            for (int j = 0; j < countofgrades; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void average(){ //Средний балл
        for (int i = 0; i < count; i++){
            double sum = 0;
            for (int j = 0; j < countofgrades; j++){
                sum += arr[i][j];
            }
            double mid = sum / countofgrades;
            cout << "Средний балл студента - " << firstname[i] << " " << lastname[i] << " : " << mid << endl;
        }
    }
    ~Students(){ //Деструктор
        for (int i = 0; i < count; i++){
            delete[] arr[i]; 
        }
        delete[] arr;
    }
};

int main(){
    int n, countofgrades;
    cout << "Введите количество студентов: " << endl;
    cin >> n;
    cout << "Введите количество оценок: ";
    cin >> countofgrades;
    Students s1(n, countofgrades);
    s1.get();
    s1.average();
    return 0;
}