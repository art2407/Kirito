#include "Triangle.h"
#include <iostream>
#include <cmath>

void Triangle::set(float a1, float b1, float c1) {
	this->a = a1;
	this->b = b1;
	this->c = c1;
}

bool Triangle::exst_tr() {
	return a + b > c && b + c > a && a + c > b;
}

void Triangle::show() {
	std::cout << "Ïëîùàäü = " << this->square() << " Ïåðèìåòð = " << this->perimetr() << "\n";

}

float Triangle::perimetr() {
	return a + b + c;
}

float Triangle::square() {
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}