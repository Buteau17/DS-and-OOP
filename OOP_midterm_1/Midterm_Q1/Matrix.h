#pragma once
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

class Matrix_Shape {
public:
	int m, n;
	Matrix_Shape(int m, int n) :m(m), n(n) {}
	bool operator== (const Matrix_Shape& other)const { return m == other.m && n == other.n; }
	bool operator!= (const Matrix_Shape& other)const { return m != other.m || n != other.n; }
	bool CanMultiply(const Matrix_Shape& other)const { return n == other.m; }
	string ToString()const { return "(" + to_string(m) + "," + to_string(n) + ")"; }
};

class Matrix {
private:
	Matrix_Shape mShape;
	vector<vector<int> > M;
public:

	bool isValid = true;

	// Output matrix value with format { mShape.m, mShape.n, M[0][0], M[0][1], ... }

	vector<int> Flattern() const
	{
		vector<int> rawData;
		rawData.push_back(mShape.m);
		rawData.push_back(mShape.n);
		for (size_t i = 0; i < mShape.m; i++)
		{
			for (size_t j = 0; j < mShape.n; j++)
			{
				rawData.push_back(M[i][j]);
			}
		}
		return rawData;
	}
	
	// An empty matrix is an invalid matrix.
	Matrix() :isValid(false), mShape(0, 0) {}

	Matrix(const int m, const int n, const vector<int>& rawData) :mShape(m, n)
	{
		// TODO: Construct the matrix
		int id = 0;
		for (int i = 0; i < m; i++) {
			vector<int> tmp;
			for (int j = 0; j < n; j ++) {
				tmp.push_back(rawData[id++]);
			}
			M.push_back(tmp);
		}
	}


	static Matrix Add(const Matrix& a, const Matrix& b)
	{
		if ((a.mShape != b.mShape) || !a.isValid || !b.isValid)
		{
			cout << "operands could not be broadcast together with shapes " << a.mShape.ToString() << " " << b.mShape.ToString() << endl;
			return Matrix();
		}

		vector<int> rawData;

		// TODO: Add matrix A with matrix B

		for (int i = 0; i < a.mShape.m; i++) {
			for (int j = 0; j < a.mShape.n; j++) {
				rawData.push_back(a.M[i][j] + b.M[i][j]);
			}
		}

		return Matrix(a.mShape.m, a.mShape.n, rawData);
	}

	static Matrix Minus(const Matrix& a, const Matrix& b)
	{
		if (a.mShape != b.mShape || !a.isValid || !b.isValid)
		{
			cout << "operands could not be broadcast together with shapes " << a.mShape.ToString() << " " << b.mShape.ToString() << endl;
			return Matrix();
		}

		vector<int> rawData;

		// TODO: Minus matrix A with matrix B
		

		for (int i = 0; i < a.mShape.m; i++) {
			for (int j = 0; j < a.mShape.n; j++) {
				rawData.push_back(a.M[i][j] - b.M[i][j]);
			}
		}

		return Matrix(a.mShape.m, a.mShape.n, rawData);
	}

	static Matrix Transpose(const Matrix& a)
	{
		if (!a.isValid)
		{
			cout << "matrix is not valid " << endl;
			return Matrix();
		}
		vector<int> rawData;

		// TODO: Transpose matrix A
		

		for (int i = 0; i < a.mShape.n; i++) {
			for (int j = 0; j < a.mShape.m; j++) {
				//cout << '(' << i << ' ' << j << ')' << ' ';
				rawData.push_back(a.M[j][i]);
			}
		}

		return Matrix(a.mShape.n, a.mShape.m, rawData);
	}

	static Matrix Multiply(const Matrix& a, const Matrix& b)
	{
		if (!a.mShape.CanMultiply(b.mShape) || !a.isValid || !b.isValid)
		{
			cout << "operands could not be broadcast together with shapes " << a.mShape.ToString() << " " << b.mShape.ToString() << endl;
			return Matrix();
		}
		vector<int> rawData;

		// TODO: Multiply matrix A with matrix B

		for (int i = 0; i < a.mShape.m; i++) {
			for (int j = 0; j < b.mShape.n; j++) {
				int tmp =0 ;
				for (int k = 0; k < a.mShape.m; k++) {
					tmp += a.M[i][k] * b.M[k][j];
				}
				rawData.push_back(tmp);
			}
		}

		return Matrix(a.mShape.m, b.mShape.n, rawData);
	}

	Matrix operator+(const Matrix& b) const;
	Matrix operator-(const Matrix& b) const;
	Matrix Deepcopy() const;
	void Print();

};