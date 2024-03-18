#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int triangle();
int Perimetr(int a, int b, int c); // Ищем периметр треугольника
double Geron(int a, int b, int c, int P); // Площадь по формуле Герона
bool rav_bedr(int a, int b, int c); // проверка на равнобедренность

int main(){
    cout << " Выберите фигуру: " << endl;
    cout << " 1 - треугольник," << endl;
    cout << " 2 - трапеция," << endl;
    char shape;
    cin >> shape;
    switch (shape){
        case ('1'):
            system("cls");
            triangle();
            break;
        case ('2'): 
            //system("cls");
            //trapeziod(); 
            //break;
        default: 
            cout << " The shape is not selected " << "\n";
            break;
    }
    return 0;
}

int triangle(){
  cout<< "Введите стороны треугольника:"<<endl;
  int a,b,c;
  cin >> a >> b >> c;
  if (a +b <= c or a+c <= b or b+c <= a){ // проверка на существование треугольника (если сумма двух сторон <= третьей, то трег не сущ)
    cout << " Ошибка! Такой треугольник не может существовать!" << endl;
 return 0;
  }
  
  int P = Perimetr(a, b, c);
  cout << " Периметр равен: " << P << endl;
  double S = Geron(a, b, c, P);
  cout << " Площадь равна: " << S <<endl;
  bool is_rb = rav_bedr(a, b, c);
  if(is_rb == true){
    cout << " Треугольник равнобедренный";
  } else {
  cout << " Треугольник неравнобедренный";
}
return 0;
}

int Perimetr(int a, int b, int c){ // Ищем периметр треугольника
  int sum = a+b+c;
  return sum;
}

double Geron(int a, int b, int c, int P){ // Площадь по формуле Герона
  double PP = P/2;
  double S = sqrt(PP*(PP-a)*(PP-b)*(PP-c));
  return S;
}

bool rav_bedr(int a, int b, int c){ // проверка на равнобедренность
  if (a == b or a==c or b==c){
    return true;
  } else {
  return false;
}
}