#pragma once
class Vector {
private:
	float x1, y1, x2, y2;  // Ïàðàìåòðû âåêòîðà ÷åðåç 2 òî÷êè
public:
	void set(float x1, float x2, float y1, float y2);
	float len();
	float angle(Vector a);
	float scalar(Vector a);
};