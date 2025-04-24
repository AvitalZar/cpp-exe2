#pragma once

#include <iostream>
#include <cmath>

namespace theMatrix { //(כן זה בכוונה.)
	class SquareMat
	{
	private:
		double **mat;
		int size;
	public:
		SquareMat(int len);
		SquareMat(const SquareMat& other);


		//operators:

		double sum() const;

		//two [] operators, one so we can change the matrix and one for constant matrices.
		const double* operator[](int i) const;
		double* operator[](int i);

		SquareMat operator=(const SquareMat &other);

		SquareMat operator+(const SquareMat& other) const;
		SquareMat operator-(const SquareMat& other) const;
		SquareMat operator-();
		SquareMat operator*(const SquareMat& other) const;
		SquareMat operator*(double p) const; 
		friend SquareMat operator*(double p, SquareMat& m);

		SquareMat operator%(const SquareMat& other) const;
		SquareMat operator%(int i) const;

		SquareMat operator/(double num) const;
		SquareMat operator^(int n) const;

		SquareMat operator++();
		SquareMat operator--();
		SquareMat operator++(int);
		SquareMat operator--(int);

		SquareMat operator~();

		friend bool operator==(const SquareMat& cur, const SquareMat& other);
		friend bool operator!=(const SquareMat& cur, const SquareMat& other);

		friend bool operator<(const SquareMat& cur, const SquareMat& other);
		friend bool operator>(const SquareMat& cur, const SquareMat& other);
		friend bool operator<=(const SquareMat& cur, const SquareMat& other);
		friend bool operator>=(const SquareMat& cur, const SquareMat& other);

		
		double operator!() const;

		SquareMat operator*=(const SquareMat &other);
		SquareMat operator+=(const SquareMat &other);
		SquareMat operator-=(const SquareMat &other);
		SquareMat operator/=(double x);
		SquareMat operator%=(const SquareMat &other);

		SquareMat operator*=(double x);
		SquareMat operator%=(double x);

		friend std::ostream& operator<< (std::ostream& output, const SquareMat t);

		

		~SquareMat();
	};
};