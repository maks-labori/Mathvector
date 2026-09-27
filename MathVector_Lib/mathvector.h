#pragma once
#include "vector.h"

template <typename vector_type>
class MathVector : public Vector<vector_type> {
private:
	size_t _start_index;
public:
	MathVector(size_t s = 0,vector_type* data = nullptr);

	MathVector(std::initializer_list<vector_type> );
	MathVector(const MathVector<vector_type>&);
	~MathVector() = default;
	inline size_t size()const noexcept {
		return this->size();
	}

	MathVector<vector_type> operator* (double value)const noexcept;
	MathVector<vector_type>& operator*=(double value)noexcept;

	MathVector<vector_type> operator+ (const MathVector<vector_type>& other);
	MathVector<vector_type> operator- (const MathVector<vector_type>& other);
	double operator* (const MathVector<vector_type>& other);

	MathVector<vector_type>& operator+=(const MathVector<vector_type>& other);
	MathVector<vector_type>& operator-=(const MathVector<vector_type>& other);
	MathVector<vector_type>& operator=(const MathVector<vector_type>& other);

	const vector_type& operator[](size_t index)const;
	vector_type& operator[](size_t index);

	bool operator==(MathVector<vector_type>& other);
	bool operator!=(MathVector<vector_type>& other);

	friend std::istream& operator>> (std::istream& in, MathVector<vector_type>& vec);
	friend std::ostream& operator<< (std::ostream& out, const MathVector<vector_type>& vec);
};

template <typename vector_type>
MathVector<vector_type>::MathVector(size_t s, vector_type* data) {
	Vector<vector_type>(data, s);
	_start_index(0);
	Vector<vector_type>::shrink_to_fit();
}

template <typename vector_type>
MathVector<vector_type>::MathVector(std::initializer_list<vector_type> data) {
	Vector<vector_type>(data);
	_start_index(0)
	Vector<vector_type>::shrink_to_fit();
}

template <typename vector_type>
MathVector<vector_type>::MathVector(const MathVector<vector_type>& other)  {
	Vector<vector_type>(other);
	_start_index(0);
	Vector<vector_type>::shrink_to_fit();
}

template <typename vector_type>
MathVector<vector_type> MathVector<vector_type>::operator*(double value)const noexcept{
	MathVector<vector_type> res(*this);
	for (int i = 0;i < this->size();++i) {
		res[i] *= value;
	}
	return res;
}

template <typename vector_type>
MathVector<vector_type>& MathVector<vector_type>::operator*=(double value)noexcept{
	return (*this) * value;
}

template <typename vector_type>
MathVector<vector_type> MathVector<vector_type>::operator+(const MathVector<vector_type>& other){
	MathVector<vector_type> res(*this);
	for (int i = 0;i < this->size();++i) {
		res[i] = this[i] + other[i];
	}
	return res;
}

template <typename vector_type>
MathVector<vector_type> MathVector<vector_type>::operator-(const MathVector<vector_type>& other){
	MathVector<vector_type> res(*this);
	for (int i = 0;i < this->size();++i) {
		res[i] = this[i] - other[i];
	}
	return res;
}

template <typename vector_type>
double MathVector<vector_type>::operator* (const MathVector<vector_type>& other) {
	double res = 0.0;
	for (int i = 0;i < this->size();++i) {
		res += (*this)[i] * other[i];
	}
	return res;
}

template <typename vector_type>
MathVector<vector_type>& MathVector<vector_type>::operator+=(const MathVector<vector_type>& other) {
	(*this) = (*this) + other;
	return *this;
}

template <typename vector_type>
MathVector<vector_type>& MathVector<vector_type>::operator-=(const MathVector<vector_type>& other){
	(*this) = (*this) - other;
	return *this;
}

template <typename vector_type>
MathVector<vector_type>& MathVector<vector_type>::operator=(const MathVector<vector_type>& other){
	if (&other != this) {
		(*this).Vector<vector_type>::operator=(other);
		_start_index = other._start_index;
		return (*this);
	}
}

template <typename vector_type>
const vector_type& MathVector<vector_type>::operator[](size_t index)const {
	return (*this).Vector<vector_type>::operator[](index);
}

template <typename vector_type>
vector_type& MathVector<vector_type>::operator[](size_t index) {
	return (*this).Vector<vector_type>::operator[](index);
}

template <typename vector_type>
bool MathVector<vector_type>::operator==(MathVector<vector_type>& other) {
	return ((*this).Vector<vector_type>::operator==(other) && _start_index == other._start_index);
}

template <typename vector_type>
bool MathVector<vector_type>::operator!=(MathVector<vector_type>& other) {
	return !((*this) == other);
}

template <typename vector_type>
std::istream& operator>> (std::istream& in, MathVector<vector_type>& vec) {
	vector_type element;
	while (in >> element) {
		(*this).push_back(element);
	}
	return in;
}

template <typename vector_type>
std::ostream& operator<< (std::ostream& out, const MathVector<vector_type>& vec) {
	out << "{";
	if (this->isempty()) {
		out << "}\n";
		return out;
	}
	out << vec[0];
	for (int i = 1;i < this->size();++i) {
		out << "," << vec[i];
	}
	out << "}\n";
	return out;
}