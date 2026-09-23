#include "mathvector.h"

template <typename vector_type>
MathVector<vector_type>::MathVector(size_t s, const vector_type* data) :Vector<vector_type>(s, data), _start_index(0) {
	this->shrink_to_fit();
}

template <typename vector_type>
MathVector<vector_type>::MathVector(std::initializer_list<vector_type> data) : Vector(data), _start_index(0) {
	Vector<vector_type>::shrink_to_fit();
}

template <typename vector_type>
MathVector<vector_type>::MathVector(const MathVector<vector_type>& other) : Vector(other), _start_index(0) {
	Vector<vector_type>::shrink_to_fit();
}