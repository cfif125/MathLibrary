#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif

#include <vector>
#include <iostream>
using namespace std;

extern "C" MATHLIBRARY_API class Matrix
{
public:
    Matrix(int countLines, int countCol);
    Matrix();
    friend std::ostream& operator<< (std::ostream& out, const Matrix& matrix);
    friend std::istream& operator >> (std::istream& in, const Matrix& matrix);
    int countOfLines;
    int countOfColumns;
    //variable storing matrix elements
    vector<vector<double>> data;

};

//Identity matrix
extern "C" MATHLIBRARY_API class UnitMatrix : public Matrix
{
public:
    //constructor to create an identity matrix based on another matrix
    UnitMatrix(const Matrix& pMatrix);
    //new identity matrix of given dimensions
    UnitMatrix(int countLin, int countCol);
};

extern "C" MATHLIBRARY_API class DiagMatrix : public Matrix
{
public:
    //matrix based diagonal matrix
    DiagMatrix(const Matrix& pMatrix);
    //new diagonal matrix
    DiagMatrix(int countLin, int countCol);
    DiagMatrix();
};

extern "C" MATHLIBRARY_API class UpperTriangularMatrix : public Matrix
{
public:
    //matrix based creation (lower triangle clipping)
    UpperTriangularMatrix(const Matrix& pMatrix);
    //new triangular matrix
    UpperTriangularMatrix(int countLin, int countCol);
    UpperTriangularMatrix();
};

extern "C" MATHLIBRARY_API class LowerTriangularMatrix : public Matrix
{
public:
    //matrix based creation (upper triangle clipping)
    LowerTriangularMatrix(const Matrix& pMatrix);
    LowerTriangularMatrix(int countLin, int countCol);
    LowerTriangularMatrix();
};

//symmetric matrix
extern "C" MATHLIBRARY_API class SymMatrix : public Matrix
{
public:
    SymMatrix(int countLin, int countCol);
};

//LW_1
//operator overloading
extern "C" MATHLIBRARY_API Matrix operator+(const Matrix& A, const Matrix& B);
extern "C" MATHLIBRARY_API Matrix operator-(const Matrix& A, const Matrix& B);
extern "C" MATHLIBRARY_API Matrix operator*(const Matrix& A, const Matrix& B);
extern MATHLIBRARY_API Matrix operator*(const double& d, const Matrix& B);
//the Hadamard product
extern "C" MATHLIBRARY_API Matrix MultOfAdamard(const Matrix& A, const Matrix& B);


//LW_2
extern "C" MATHLIBRARY_API double Trace(const Matrix& matrix);
//determinant calculation
extern "C" MATHLIBRARY_API double MethodGauss(const Matrix& matrix);
extern "C" MATHLIBRARY_API double ScalarMult(const Matrix& v1, const Matrix& v2);
//Euclidean norm
extern "C" MATHLIBRARY_API double Norma(const Matrix& v1);
extern "C" MATHLIBRARY_API double MaxNorma(const Matrix& v1);
extern "C" MATHLIBRARY_API double NormFrobenius(const Matrix& matrix);


//LW_3
extern "C" MATHLIBRARY_API double AngleBetVectors(const Matrix& v1, const Matrix& v2);
extern "C" MATHLIBRARY_API int GaussMatrixRank(const Matrix& matrix);
extern "C" MATHLIBRARY_API Matrix GetMinorElementsMatrix(const Matrix& matrix, int line, int column);
extern "C" MATHLIBRARY_API Matrix TransposeMatrix(const Matrix& matrix);
extern "C" MATHLIBRARY_API Matrix InverseMatrix(const Matrix& matrix);
