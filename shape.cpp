#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int trapeziod();
void isoscelesTrapezoid(double lowerBase, double upperBase, double height);   //равнобокая трапеция
void rectangularTrapezoid(double lowerBase, double upperBase, double straighSide);  //прямоугольная трапеция
void anarbitraryTrapezoid(double lowerBase, double upperBase, double rightSide, double leftSide, double height);  //произвольная трапеция

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
            system("cls");
            trapeziod();
            break;
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
    cout << "Ошибка! Такой треугольник не может существовать!" << endl;
 return 0;
  }
  
  int P = Perimetr(a, b, c);
  cout << "Периметр равен: " << P << endl;
  double S = Geron(a, b, c, P);
  cout << "Площадь равна: " << S <<endl;
  bool is_rb = rav_bedr(a, b, c);
  if(is_rb == true){
    cout << "Треугольник равнобедренный";
  } else {
  cout << "Треугольник неравнобедренный";
}
return 0;
}

int Perimetr(int a, int b, int c){ // Ищем периметр треугольника
  int sum = a+b+c;
  return sum;
}

double Geron(int a, int b, int c, int P){ // Площадь по формуле Герона
  double S = sqrt(P/2*(P-a)*(P-b)*(P-c));
  return S;
}

bool rav_bedr(int a, int b, int c){ // проверка на равнобедренность
  if (a == b or a==c or b==c){
    return true;
  } else {
  return false;
}
}

int trapeziod() {
    cout << "Type of trapezoid:" << endl;
    cout << " 1 - isosceles" << endl;
    cout << " 2 - rectangular" << endl;
    cout << " 3 - an arbitrary" << endl;
    char type;
    cin >> type;
    system("cls");
    switch (type){
        case ('1'): {
            cout << " lower base = ";
            double lowerBase;
            cin >> lowerBase;
            cout << " upper base = ";
            double upperBase;
            cin >> upperBase;
            cout << " height = ";
            double height;
            cin >> height;
            if ( !cin ) {
                cout << "Wrong input data";
                break;
            }
            isoscelesTrapezoid(lowerBase, upperBase, height);
            break;
        }
        case ('2'): {
            cout << " lower base = ";
            double lowerBase;
            cin >> lowerBase;
            cout << " upper base = ";
            double upperBase;
            cin >> upperBase;
            cout << " straigh side = ";
            double straighSide;
            cin >> straighSide;
            if ( !cin ) {
                cout << "Wrong input data";
                break;
            }
            rectangularTrapezoid(lowerBase, upperBase, straighSide);
            break;
        }
        case ('3'): {
            cout << " lower base = ";
            double lowerBase;
            cin >> lowerBase;
            cout << " upper base = ";
            double upperBase;
            cin >> upperBase;
            cout << " right side = ";
            double rightSide;
            cin >> rightSide;
            cout << " left side = ";
            double leftSide;
            cin >> leftSide;
            cout << " height = ";
            double height;
            cin >> height;
            if ( !cin ) {
                cout << "Wrong input data";
                break;
            }
            anarbitraryTrapezoid(lowerBase, upperBase, rightSide, leftSide, height);
            break;
        }
        default:
            cout << " The type is not selected " << "\n";
            break;
    }
    return 0;
}

int checkAvailability(double lowerbase, double upperbase, double rightSide, double leftSide, double height) {
    if((abs(lowerbase - upperbase) < rightSide + leftSide) && (lowerbase + upperbase > height)) {
        return 1;
    }
    return 0;
}

double middleLine(int lowerbase, int upperbase){
    double middleline = (lowerbase + upperbase)*(0.5);
    return middleline;
}

double square(double lowerbase, double upperbase, double height){
    double square = height * ((lowerbase + upperbase)*(0.5));
    return square;
}

double isosceleSide(double lowerBase, double upperBase, double height) {
    double side_sqr = (height * height + 0.25 * (lowerBase - upperBase) * (lowerBase - upperBase));
    return sqrt(side_sqr);
}

double rectangularSide(double lowerBase, double upperBase, double height){
    return sqrt((upperBase - lowerBase) * (upperBase - lowerBase) + (height * height)); 
}

void isoscelesTrapezoid(double lowerBase, double upperBase, double height){
    double tr_middleLine = middleLine(lowerBase, upperBase);
    double tr_square = square(lowerBase, upperBase, height);
    double tr_perimetr = isosceleSide(lowerBase, upperBase, height) * 2  + lowerBase + upperBase;

    cout << "Square = " << tr_square << endl;
    cout << "Middle line = " << tr_middleLine << endl;
    cout << "Perimetr = " << tr_perimetr << endl;
}

void rectangularTrapezoid(double lowerBase, double upperBase, double straighSide) {
    double tr_middleLine = middleLine(lowerBase, upperBase);
    double tr_square = square(lowerBase, upperBase, straighSide);
    double tr_perimetr = rectangularSide(lowerBase, upperBase, straighSide) + straighSide + upperBase + lowerBase;

    cout << "Square = " << tr_square << endl;
    cout << "Middle line = " << tr_middleLine << endl;
    cout << "Perimetr = " << tr_perimetr << endl;
}

void anarbitraryTrapezoid(double lowerBase, double upperBase, double rightSide, double leftSide, double height) {
    if(!checkAvailability(lowerBase, upperBase, rightSide, leftSide, height))
    {
        cout << "wrong input data" << endl;
        return;
    }
         
    double tr_middleLine = middleLine(lowerBase, upperBase);
    double tr_square = square(lowerBase, upperBase, height);
    double tr_perimetr = rightSide + leftSide + upperBase + lowerBase;

    cout << "Square = " << tr_square << endl;
    cout << "Middle line = " << tr_middleLine << endl;
    cout << "Perimetr = " << tr_perimetr << endl;
}