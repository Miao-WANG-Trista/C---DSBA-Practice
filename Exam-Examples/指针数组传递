#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class IntVector {
private:
	int* m_vector; // pointer to an array for storing elements of the vector
	int m_size; // size of the vector

public:
	// constructors
	IntVector(int n);
	IntVector(int* arr, int n);
	IntVector(const IntVector& old_v); // copy constructor

	// methods
	int maxEven();
	friend ostream& operator << (ostream& out, const IntVector& v);
	double f(int i);

	// destructor
	~IntVector();
};

IntVector::IntVector(int n) {
	m_vector = new int[n];
	m_size = n;
	for (int i = 0; i < n; i++) {
		m_vector[i] = 0;
	}
}

IntVector::IntVector(int* arr, int n) {
	m_vector = new int[n];
	m_size = n;
	for (int i = 0; i < n; i++) {
		m_vector[i] = arr[i];
	}
}

IntVector::IntVector(const IntVector& old_v) {
	m_vector = new int[old_v.m_size];
	m_size = old_v.m_size;
	for (int i = 0; i < old_v.m_size; i++) {
		m_vector[i] = old_v.m_vector[i];
	}
}

int IntVector::maxEven() {

	//method2
	int max_even = 1;
	for (int i = 0; i < m_size; i++) {
		// initialize max_even with the first even number in the vector
		if (m_vector[i] % 2 == 0 && max_even == 1) {
			max_even = m_vector[i];
			//cout << max_even << endl;
		}
		// find the max in the rest of even numbers
		if (m_vector[i] % 2 == 0 && m_vector[i] > max_even) {
			max_even = m_vector[i];
			}
		}
	if (max_even == 1)
		cout << "no even number in the vector!" << endl;
	return max_even;
}

ostream& operator << (ostream& out, const IntVector& v) {
	for (int i = 0; i < v.m_size-1; i++) {
		if (i == 0) { out << "intvector=["; }
		out << v.m_vector[i]<<",";
	}
	out << v.m_vector[v.m_size - 1] << "]";
	return out;
}

double IntVector::f(int i) {
	if (i <= m_size || i>=0) {
		return sqrt(m_vector[i - 1]);
	}
	else {
		cout << "Error! Index out of range";
		return 0.0;
	}
}

IntVector::~IntVector() { delete[] m_vector; }

int main() {
	// TEST CONSTRUCTOR AND cout<<
	int v1[] = { 1,2,3,4 };
	IntVector iv1(v1, 4);
	cout << iv1 << endl;

	// TEST maxEven()
	int v2[] = { -2,-10,87,1,1,3,5 };
	IntVector iv2(v2, 7);
	cout << iv2.maxEven() << endl;

	//TEST f(int)
	int v3[] = { 4,22,88,1,2,3,9 };
	IntVector iv3(v3, 7);
	cout << iv3.f(1) << " " << iv3.f(10) << endl;
	return 0;
}
