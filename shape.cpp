#include <iostream>
using namespace std;

int main(){
    cout << " Choose a shape: " << endl;
    cout << " 1 - triangle," << endl;
    cout << " 2 - trapezoid," << endl;
    cout << " 3 - circle" << endl;
    char shape;
    cin >> shape;
    switch (shape){
        case ('1'):
            //для треугольника
            break;
        case ('2'):
            //для трапеции
            break;
        case ('3'):
            //для окружности
            break;
        default:
            cout << " The shape is not selected, repeat:" << "\n";
            cin >> shape;
            break;
    }
}