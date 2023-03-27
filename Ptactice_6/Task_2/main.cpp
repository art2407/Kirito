#include "cone.h"
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    TruncatedCone tc1(4, 5, 2);
    TruncatedCone tc2(6, 5, 2);
    cout << "��������� ����� 1: " << tc1 << endl;
    cout << "������� �����������: " << tc1.surfaceArea() << ",�����: " << tc1.volume() << endl;
    cout << "��������� ����� 2: " << tc2 << endl;
    cout << "������� �����������: " << tc2.surfaceArea() << ",�����: " << tc2.volume() << endl;
    return 0;
}