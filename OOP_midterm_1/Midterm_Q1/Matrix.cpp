#include "Matrix.h"

void Matrix::Print()
{
	// TODO: Print the Matrix

	for (size_t i = 0; i < mShape.m; i++)
	{
		for (size_t j = 0; j < mShape.n; j++)
		{
			cout << this->M[i][j] << ' ';
		}
		cout << '\n';
	}
}
//a+b
Matrix Matrix::operator+(const Matrix& b) const
{
	// TODO: Overloading the operator 
	Matrix result = Add(*this, b);
	//*this = result;
	return result;
	//return *this;
}
Matrix Matrix::operator-(const Matrix& b) const
{
	// TODO: Overloading the operator 
	Matrix result = Minus(*this, b);
	return result;

	//return *this;
}

Matrix Matrix::Deepcopy() const
{
	// TODO: return Deepcopy version of that matrix
	Matrix result = *this;
	return result ;
}
