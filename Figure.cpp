#include "Figure.h"
#include "Vector.h"
#include <cmath>
#include <iostream>

Figure::Figure() {
	std::cout << "Введите значение координат X: ";
	std::cin >> this->x1;
	std::cin >> this->x2;
	std::cin >> this->x3;
	std::cin >> this->x4;
	std::cout << "Введите значение координат Y: ";
	std::cin >> this->y1;
	std::cin >> this->y2;
	std::cin >> this->y3;
	std::cin >> this->y4;

	this->a.set(x1, x2, y1, y2);
	this->b.set(x2, x3, y2, y3);
	this->c.set(x3, x4, y3, y4);
	this->d.set(x4, x1, y4, x1);

	this->P = a.len() + b.len() + c.len() + d.len();
	this->S = sqrt(P / 2 * (pow(P / 2 - a.len(), 2) + pow(P / 2 - b.len(), 2) + pow(P / 2 - c.len(), 2) + pow(P / 2 - d.len(), 2)));
}

void Figure::show() {
	std::cout << "сторона À = " << a.len() << " сторона B = " << b.len() << " сторона C = " << c.len() << " сторона D = " << d.len() << "\n";
	std::cout << "Периметр = " << this->P << " ПлощадьЫ = " << this->S;
}

bool Figure::is_prug() {
	bool angles_90 = a.angle(b) == 90 && c.angle(d) == 90;
	bool opposide_sides_equal = a.len() == c.len() && b.len() == d.len();

	return angles_90 && opposide_sides_equal;
}

bool Figure::is_square() {
	bool angles_90 = a.angle(b) == 90 && c.angle(d) == 90;
	bool all_sides_equal = a.len() == b.len() && b.len() == c.len() && c.len() == d.len();

	return angles_90 && all_sides_equal;
}

bool Figure::is_romb() {
	bool all_sides_equal = a.len() == b.len() && b.len() == c.len() && c.len() == d.len();
	bool opposite_angles_equal = a.angle(b) == c.angle(d) && d.angle(a) == b.angle(c);




	return all_sides_equal && opposite_angles_equal;
}

bool Figure::is_in_circle() {
	return a.angle(b) == c.angle(d) && d.angle(a) == b.angle(c);
}

bool Figure::is_out_circle() {
	return a.len() + c.len() == b.len() + d.len();
}