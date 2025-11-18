#include <cstddef>
#include <iostream>


template<typename T> class Vector {

private:
	T* data;
	size_t sz;
	size_t capacity;

	void resize(size_t new_cap) {
		T* new_data = new T[new_cap];
		for (size_t i = 0; i < sz; ++i) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = new_cap;
	}

public:
	Vector(): data(nullptr), sz(0), capacity(0) {}

	~Vector() {
		delete[] data;
	}

	Vector(const Vector& other): sz(other.sz), capacity(other.capacity) {
		data = new T[capacity];
		for (size_t i = 0; i < sz; ++i) {
			data[i] = other.data[i];
		}
	}

	Vector& operator=(const Vector& other) {
		if (this == &other) return *this;
		delete[] data;

		sz = other.sz;
		capacity = other.capacity;
		for (size_t i = 0; i < sz; ++i) {
			data[i] = other.data[i];
		}

		return *this;
	}

	
	void push_back(const T& value) {
		if (sz == capacity) {
			resize(capacity == 0 ? 1: capacity * 2);
		}

		data[sz++] = value;
	}

	T& operator[](size_t index) {
		if (index >= sz) throw std::out_of_range("Index out of range");
		return data[index];
	}

	const T& operator[](size_t index) const {
		if (index >= sz) throw std::out_of_range("Index out of range");
		return data[index];
	}


};






int main() {

	Vector<double> doubles;
	Vector<int> ints;
	
	doubles.push_back(1.5);
	doubles.push_back(2.5);

	ints.push_back(1);
	ints.push_back(2);

	std::cout << "double vector: " << doubles[0] << ", " << doubles[1] << '\n';
	std::cout << "int vector: " << ints[0] << ", " << ints[1] << '\n';
	return 0;

}
