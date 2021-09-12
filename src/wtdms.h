/*

	Library for working with vectors and matrices in C++

*/

#ifndef WTDMS_H_
#define WTDMS_H_

#include <stdio.h>
#include <cmath>
#include <array>
#include <initializer_list>

#include <algorithm>
#include <map>
#include <string>

#include "wtdms_except.h"

namespace wtdms
{

typedef double VECTOR_TYPE;

// ===== VECTORS =====
template <size_t N>
class Vec
{
	public:
		std::array<VECTOR_TYPE, N> array;
		
		Vec();
		Vec(std::initializer_list<VECTOR_TYPE> lst);

		size_t dimension() { return N; }
		void print();

		VECTOR_TYPE length();

		VECTOR_TYPE& operator[](size_t idx);

		Vec<N> operator-() const;
		Vec<N> operator~() const;
		Vec<N> operator+(const Vec<N>& other) const;
		Vec<N> operator-(const Vec<N>& other) const;
		//Vec<N> operator*(const Vec<N>& other) const;
};

template <size_t N>
Vec<N>::Vec(std::initializer_list<VECTOR_TYPE> lst) {
	array.fill(0);
	
	size_t i = 0;
	for (const VECTOR_TYPE& xi : lst) {
		array[i++] = xi;
	}
}

template <size_t N>
Vec<N>::Vec() {
	array.fill(0);
}

template <size_t N>
void Vec<N>::print()
{
	char c;
	for (size_t i = 0; i < N; i++) {
		if (i == 0) c = ' ';
		else
			c = '+';
			if (array[i] < 0)
				c = '-';
		printf(" %c %f x%d", c, array[i], i + 1);
	}
	printf("\n");
}

template <size_t N>
VECTOR_TYPE Vec<N>::length()
{
	VECTOR_TYPE sm = 0;
	for (auto i : array)
		sm += i*i;
	return std::sqrt(sm);
}

template <size_t N>
VECTOR_TYPE& Vec<N>::operator[](size_t idx)
{
	if (idx >= 0 && idx <= N) {
		return array[idx];
	} else {
		throw dimension_range();
	}
}

template <size_t N>
Vec<N> Vec<N>::operator-() const
{
	Vec<N> ret;
	for (size_t i = 0; i < N; i++) {
		ret[i] = -array[i];
	}
	return ret;
}

template <size_t N>
Vec<N> Vec<N>::operator~() const
{
	return operator-();
}

template <size_t N>
Vec<N> Vec<N>::operator+(const Vec<N>& other) const
{
	Vec<N> ret;
	for (size_t i = 0; i < N; i++) {
		ret.array[i] = array[i] + other.array[i];
	}
	return ret;
}

template <size_t N>
Vec<N> Vec<N>::operator-(const Vec<N>& other) const
{
	return operator+(-other);
}

/*template <size_t N>
Vec<N> Vec<N>::operator*(const Vec<N>& other) const
{
	
}*/


}

#endif //WTDMS_H_