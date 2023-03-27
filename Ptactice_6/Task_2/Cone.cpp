#include "cone.h"
#include <cmath>
ostream& operator<<(ostream& os, const Cone& c) {
    os << "������: " << c.radius << ", ������: " << c.height;
    return os;
}
istream& operator>>(istream& is, Cone& c) {
    cout << "������� ������: ";
    is >> c.radius;
    cout << "������� ������: ";
    is >> c.height;
    return is;
}
istream& operator>>(istream& is, TruncatedCone& tc) {
    cout << "������ ������: ";
    is >> tc.radius;
    cout << "������� ������: ";
    is >> tc.topRadius;
    cout << "������: ";
    is >> tc.height;
    return is;
}
ostream& operator<<(ostream& os, const TruncatedCone& tc) {
    os << "������ ������: " << tc.radius << ", ������� ������: " << tc.topRadius << ", ������: " << tc.height;
    return os;
}