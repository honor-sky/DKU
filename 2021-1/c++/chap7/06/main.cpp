#include <iostream>
using namespace std;

class Matrix {
	int array[4];
public:
	Matrix(int a=0, int b=0, int c=0, int d=0) {
		this->array[0] = a;
		this->array[1] = b;
		this->array[2] = c;
		this->array[3] = d;
	}
	void show() {
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++) {
			cout << array[i] << " ";
		}
		cout << "}"<<endl;
	}

	Matrix operator+(Matrix m) {
		Matrix tmp;
		for (int i = 0; i < 4; i++) {
			tmp.array[i] = this->array[i] + m.array[i];
		}
		return tmp;
	}

	Matrix& operator+=(Matrix m) {
		for (int i = 0; i < 4; i++) {
			this->array[i] = this->array[i] + m.array[i];
		}
		return *this;
	}

	bool operator==(Matrix m) {
		for (int i = 0; i < 4; i++) {
			if (this->array[i] == m.array[i]) {
				continue;
			}
			else {
				return false;
			}
			return true;	
		}
	}
};


int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c) {
		cout << "a and c are same" << endl;
	}
}