//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std; 

class Circle {

	int radius;

public:

	Circle(int r) : radius(r) { }

	int getRadius() { return radius; }

	void setRadius(int r) { radius = r; }

};

int main() {
	Circle c1(10);
	Circle c2(c1);
	cout << c2.getRadius();
}

/*class SortedArray {
	int size;
	int* p;
	void sort() { //정수 배열을 오름차순으로 정렬
		for (int i = 1; i < size; i++) {
			if (p[i-1] > p[i]) {
				int tmp = p[i];
				p[i] = p[i - 1];
				p[i - 1]=p[i];

			}
		}
	}
public:
	SortedArray();
	SortedArray(const SortedArray& src);
	SortedArray(int p[], int size);
	~SortedArray();
	SortedArray operator+(SortedArray& op2);
	SortedArray& operator=(const SortedArray& op2);
	void show() { //정렬되어서 보여줌
		sort();
		for (int i = 0; i < ) {
			cout <<
		}
		

	}
};

int main() {
	int n[] = { 2,20,6 };
	int m[] = { 10,7,8,30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;
	a.show();
	b.show();
	c.show();
}*/



