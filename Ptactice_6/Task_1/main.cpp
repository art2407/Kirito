#include <iostream>
#include "cone.h"
int main(){
    setlocale(LC_ALL, "Russian");
    cone c1(4, 8);
    cone c2(1, 2, 3, 6, 12);
    cout << "����� 1: " << c1;
    cout << "������� �����������: " << c1.area() << "\n";
    cout << "�����: " << c1.volume() << "\n";
    cout << "����� 2: " << c2;
    cout << "������� �����������: " << c2.area() << "\n";
    cout << "�����: " << c2.volume() << "\n";
    return 0;
}