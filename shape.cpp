#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int trapeziod();
void isoscelesTrapezoid(double lowerBase, double upperBase, double height);   //равнобокая трапеция
void rectangularTrapezoid(double lowerBase, double upperBase, double straighSide);  //прямоугольная трапеция
void anarbitraryTrapezoid(double lowerBase, double upperBase, double rightSide, double leftSide, double height);  //произвольная трапеция

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
            system("cls");
            trapeziod();
             break;
        case ('3'): //для окружности
            break;
        default: 
            cout << " The shape is not selected " << "\n";
            break;
    }
    return 0;
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
            rectangularTrapezoid(lowerBase, upperBase, straighSide);
            break;
        }
        case ('3'): {
            cout << " lower base = ";
            int lowerBase;
            cin >> lowerBase;
            cout << " upper base = ";
            int upperBase;
            cin >> upperBase;
            cout << " right side = ";
            int rightSide;
            cin >> rightSide;
            cout << " left side = ";
            int leftSide;
            cin >> leftSide;
            cout << " height = ";
            double height;
            cin >> height;
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
    if((lowerbase + upperbase != rightSide + leftSide) & (lowerbase + upperbase > height))
    {
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
    return (upperBase - lowerBase) * (upperBase - lowerBase) + height * height; 
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

    return;
}