#include <iostream>
using namespace std;

class Students
{
private:
    char firstname[100][50];
    char lastname[100][50];
    int count;
public:
    void set(int n){
        count = n;
        for (int i = 0; i < n; i++){
            cout << "Введите фамилию и имя " << i + 1 << " студента: ";
            cin >> firstname[i] >> lastname[i];
        }
    }
    void get(){
        cout << "Студенты: " << endl;
        for (int i = 0; i < count; i++){
            cout << firstname[i] << " " << lastname[i] << endl;
        }
    }
};

int main(){
    Students student1;
    int n;
    cout << "Введите количество студентов: ";
    cin >> n;
    student1.set(n);
    student1.get();
    return 0;
}