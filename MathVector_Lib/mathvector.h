#pragma once
#include "vector.h"

template <typename vector_type>
class MathVector : public Vector<vector_type> {
private:
	size_t _start_index;
public:
	MathVector(size_t s = 0,const vector_type* data = nullptr);
	MathVector(std::initializer_list<vector_type>);
	MathVector(const MathVector<vector_type>&);
	~MathVector() = default;
	/*inline size_t size()const noexcept;

	MathVector operator* (double value)const noexcept;
	MathVector operator+ (double value);
	MathVector operator- (double value);

	MathVector operator+ (const MathVector<vector_type>& other);
	MathVector operator- (const MathVector<vector_type>& other);
	double operator* (const MathVector<vector_type>& other);

	MathVector& operator+=(double value);
	MathVector& operator-=(double value);
	MathVector& operator*=(double value);

	MathVector& operator+=(const MathVector<vector_type>& other);
	MathVector& operator-=(const MathVector<vector_type>& other);

	MathVector& operator=(const MathVector<vector_type>& other);

	const vector_type& operator[](size_t index)const;
	vector_type& operator[](size_t index);

	bool operator==(MathVector<vector_type>& other);
	bool operator!=(MathVector<vector_type>& other);

	friend std::istream& operator>> (std::istream& in, MathVector<vector_type>& vec);
	friend std::ostream& operator<< (std::ostream& out, const MathVector<vector_type>& vec);*/
};