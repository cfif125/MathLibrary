#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include "MathLibrary.h"

Matrix::Matrix()
{

}


Matrix::Matrix(int countLines, int countCol) : countOfLines(countLines), countOfColumns(countCol)
{
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of strong and columns...\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    //temporary value to store the value
    double item_data;
    //temporary vector
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            printf("element[%d][%d] = ", line, column);
            cin >> item_data;
            temp_vector.push_back(item_data);
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}



UnitMatrix::UnitMatrix(int countLin, int countCol) :Matrix()
{
    try
    {
        if ((countLin <= 0) || (countCol <= 0))
            throw "Wrong number of rows and columns...\n";
        if (((countLin <= 0) || (countCol <= 0)) || (countLin != countCol))
            throw "\nWrong number of rows and/or columns. The matrix must be square. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    countOfLines = countLin;
    countOfColumns = countCol;
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            
            if (line == column)
            {
                temp_vector.push_back(1);
            }
            else
            {

                temp_vector.push_back(0);
            }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

UnitMatrix::UnitMatrix(const Matrix& pMatrix)
{

    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of rows and columns... \n";
        if (countOfLines != countOfColumns)
            throw "\nWrong number of rows and/or columns. The matrix must be square. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(1);
            }
            else
            {
                temp_vector.push_back(0);
            }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

DiagMatrix::DiagMatrix()
{

}

DiagMatrix::DiagMatrix(int countLin, int countCol)
{
    countOfLines = countLin;
    countOfColumns = countCol;

    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of rows and columns... \n";
        if (countOfLines != countOfColumns)
            throw "\nWrong number of rows and/or columns. The matrix must be square.\n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    double item_data;
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("element[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
            {
                temp_vector.push_back(0);
            }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

DiagMatrix::DiagMatrix(const Matrix& pMatrix)
{
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;
    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of rows and columns... \n";
        if (countOfLines != countOfColumns)
            throw "\nWrong number of rows and/or columns. The matrix must be square. \n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(pMatrix.data[line][column]);
            }
            else
            {
                temp_vector.push_back(0);
            }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

UpperTriangularMatrix::UpperTriangularMatrix() {}

UpperTriangularMatrix::UpperTriangularMatrix(const Matrix& pMatrix)
{
    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;


    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of rows and columns. \n";
        if (countOfLines != countOfColumns)
            throw "\nWrong number of rows and/or columns. The matrix must be square.\n\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
 
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(pMatrix.data[line][column]);
            }
            else
                if (column > line)
                {
                    temp_vector.push_back(pMatrix.data[line][column]);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}


UpperTriangularMatrix::UpperTriangularMatrix(int countLin = 0, int countCol = 0)
{

    countOfLines = countLin;
    countOfColumns = countCol;

    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of rows and columns.  \n";
        if (countOfLines != countOfColumns)
            throw "\nWrong number of rows and/or columns. The matrix must be square. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }

    double item_data;
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("element[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
                if (column > line)
                {
                    printf("element[%d][%d] = ", line, column);
                    cin >> item_data;
                    temp_vector.push_back(item_data);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}


LowerTriangularMatrix::LowerTriangularMatrix()
{

}

LowerTriangularMatrix::LowerTriangularMatrix(const Matrix& pMatrix)
{

    countOfLines = pMatrix.countOfLines;
    countOfColumns = pMatrix.countOfColumns;

    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of rows and/or columns. \n";
        if (countOfLines != countOfColumns)
            throw "\nWrong number of rows and/or columns. The matrix must be square. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                temp_vector.push_back(pMatrix.data[line][column]);
            }
            else
                if (column < line)
                {
                    temp_vector.push_back(pMatrix.data[line][column]);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}

LowerTriangularMatrix::LowerTriangularMatrix(int countLin = 0, int countCol = 0)
{
    countOfLines = countLin;
    countOfColumns = countCol;

    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Wrong number of rows and/or columns. \n";
        if (countOfLines != countOfColumns)
            throw "\nWrong number of rows and/or columns. The matrix must be square. \n\n";

    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }

    double item_data;
    vector<double> temp_vector;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("element[%d][%d] = ", line, column);
                scanf_s("%lf", &item_data);
                temp_vector.push_back(item_data);
            }
            else
                if (column < line)
                {
                    printf("element[%d][%d] = ", line, column);
                    cin >> item_data;
                    temp_vector.push_back(item_data);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
}


SymMatrix::SymMatrix(int countLin = 0, int countCol = 0)
{
    countOfLines = countLin;
    countOfColumns = countCol;

    try
    {
        if ((countOfLines <= 0) || (countOfColumns <= 0))
            throw "Invalid number of rows and/or columns. \n";
        if (countOfLines != countOfColumns)
            throw "\nInvalid number of rows and/or columns. The matrix must be square. \n\n";
    }
    catch (const char* msg)
    {
        cout << msg << endl;
        throw - 1;
    }

    double item_data;

    vector<double> temp_vector;
    cout << "Enter the matrix element by element: " << endl;
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (line == column)
            {
                printf("element[%d][%d] = ", line, column);
                cin >> item_data;
                temp_vector.push_back(item_data);
            }
            else
                if (column > line)
                {
                    printf("element[%d][%d] и element[%d][%d] = ", line, column, column, line);
                    cin >> item_data;

                    temp_vector.push_back(item_data);
                }
                else
                {
                    temp_vector.push_back(0);
                }
        }
        data.push_back(temp_vector);
        temp_vector.clear();
    }
    
    for (int line = 0; line < countOfLines; line++)
    {
        for (int column = 0; column < countOfColumns; column++)
        {
            if (column < line)
            {
                data[line][column] = data[column][line];
            }
        }
    }

}


std::ostream& operator<< (std::ostream& out, const Matrix& matrix)
{
    vector<double> temp;
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        temp = matrix.data[line];
        for (int column = 0; column < matrix.countOfColumns; column++)
        {
            cout << temp[column] << "\t";
        }
        cout << "\n";
    }
    return out;
}


Matrix operator+(const Matrix& A, const Matrix& B)
{

    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "Summation is not possible, matrices have different dimensions\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    Matrix temp_matrix;

    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;
    vector<double> temp_vector;
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            temp_vector.push_back(A.data[line][column] + B.data[line][column]);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

Matrix operator-(const Matrix& A, const Matrix& B)
{
    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "Вычитание невозможно, имеет место разная размерность\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    Matrix temp_matrix;

    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;
    vector<double> temp_vector;
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            temp_vector.push_back(A.data[line][column] - B.data[line][column]);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

Matrix operator*(const Matrix& A, const Matrix& B)
{
    try
    {
        if (A.countOfColumns != B.countOfLines)
            throw "Product is impossible, matrices have inappropriate dimensions\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    Matrix temp_matrix;
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = B.countOfColumns;
    double temp_data = 0;
    vector<double> temp_vector;
    for (int i = 0; i < A.countOfLines; i++)
    {
        for (int j = 0; j < temp_matrix.countOfColumns; j++)
        {
            for (int k = 0; k < A.countOfColumns; k++)
            {
                temp_data += A.data[i][k] * B.data[k][j];
            }
            temp_vector.push_back(temp_data);
            temp_data = 0;
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

Matrix operator*(const double& d, const Matrix& B)
{
    Matrix temp_matrix;
    temp_matrix.countOfLines = B.countOfLines;
    temp_matrix.countOfColumns = B.countOfColumns;
    double temp_data = 0;
    vector<double> temp_vector;
    for (int i = 0; i < temp_matrix.countOfLines; i++)
    {
        for (int j = 0; j < temp_matrix.countOfColumns; j++)
        {
            temp_data = d * B.data[i][j];
            temp_vector.push_back(temp_data);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

Matrix MultOfAdamard(const Matrix& A, const Matrix& B)
{

    try
    {
        if ((A.countOfLines != B.countOfLines) || (A.countOfColumns != B.countOfColumns))
            throw "Hadamard product is impossible, matrices have different dimensions\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    Matrix temp_matrix;
    vector<double> temp_vector;
    temp_matrix.countOfLines = A.countOfLines;
    temp_matrix.countOfColumns = A.countOfColumns;

    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            temp_vector.push_back(A.data[line][column] * B.data[line][column]);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}

//LW_2

double MethodGauss(const Matrix& matrix)
{

    try
    {
        if (((matrix.countOfLines <= 0) || (matrix.countOfColumns <= 0)) || (matrix.countOfLines != matrix.countOfColumns))
            throw "Wrong number of rows and columns\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    Matrix temp_matrix = matrix;
    double det = 1;
    int max_item_index;
    double max_item;
    double mult_coeff;
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        max_item = fabs(matrix.data[line][line]);
        max_item_index = line;
        for (int i = line + 1; i < matrix.countOfLines; i++)
        {
            double element = fabs(matrix.data[i][line]);
            if (element > max_item)
            {
                max_item = element;
                max_item_index = i;
            }
        }

    }

    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int line2 = line + 1; line2 < temp_matrix.countOfLines; line2++)
        {
            if (temp_matrix.data[line][line] != 0)
                mult_coeff = -1.0 * temp_matrix.data[line2][line] / temp_matrix.data[line][line];
            else break;
            mult_coeff = -1.0 * temp_matrix.data[line2][line] / temp_matrix.data[line][line];
            //cout << "mult_coeff = " << mult_coeff << endl;
            for (int column = line; column < matrix.countOfColumns; column++)
            {
                temp_matrix.data[line2][column] = temp_matrix.data[line2][column] + temp_matrix.data[line][column] * mult_coeff;
            }
        }
    }

    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            if (line == column)
            {
                det *= temp_matrix.data[line][column];
            }
        }
    }
    return det;
}

double Trace(const Matrix& matrix)
{
    try
    {
        if (((matrix.countOfLines <= 0) || (matrix.countOfColumns <= 0)) || (matrix.countOfLines != matrix.countOfColumns))
            throw "Wrong number of rows and columns\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    Matrix temp_matrix = matrix;
    double tr = 0;
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            if (line == column)
                tr += temp_matrix.data[line][column];
        }
    }
    return tr;
}


double ScalarMult(const Matrix& v1, const Matrix& v2)
{
    try
    {
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "One of (all) variables(s) is not a vector...\n";
        if (!((v2.countOfLines == 1) && (v2.countOfColumns >= 1)) && !((v2.countOfLines >= 1) && (v2.countOfColumns == 1)))
            throw "One of (all) variables(s) is not a vector...\n";

    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    vector<double> temp_v1;
    vector<double> temp_v2;
    double abs_val[2];
    double scalar_mult = 0;
    double temp[2];
    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    if (v2.countOfLines > 1)
    {
        for (int line = 0; line < v2.countOfLines; line++)
        {
            temp_v2.push_back(v2.data[line][0]);
        }
    }
    else
    {
        temp_v2 = v2.data[0];
    }

    for (int column = 0; column < temp_v2.size(); column++)
    {
        scalar_mult += temp_v1[column] * temp_v2[column];
    }


    return scalar_mult;
}

double Norma(const Matrix& v1)
{

    try
    {
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "Object is not a vector\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    vector<double> temp_v1;
    double summa = 0;
    double abs_val;

    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    for (int column = 0; column < temp_v1.size(); column++)
    {
        summa += temp_v1[column] * temp_v1[column];
    }
    abs_val = sqrt(summa);
    return abs_val;
}

double MaxNorma(const Matrix& v1)
{
    try
    {
        if (v1.countOfLines <= 0 || v1.countOfColumns <= 0)
            throw "Inappropriate vector size \n";
        if (!((v1.countOfLines == 1) && (v1.countOfColumns >= 1)) && !((v1.countOfLines >= 1) && (v1.countOfColumns == 1)))
            throw "Object is not a vector\n";
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    vector<double> temp_v1;
    double max = DBL_MIN;

    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    for (int column = 0; column < temp_v1.size(); column++)
    {
        if (temp_v1[column] > max)
            max = temp_v1[column];
    }
    return max;
}


double NormFrobenius(const Matrix& matrix)
{

    Matrix temp_matrix = matrix;
    double acc = 0;
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            acc += temp_matrix.data[line][column] * temp_matrix.data[line][column];
        }
    }
    return sqrt(acc);
}

double AngleBetVectors(const Matrix& v1, const Matrix& v2)
{

    vector<double> temp_v1;
    vector<double> temp_v2;
    double abs_val[2];
    double scalar_mult = 0;
    double temp[2];
    if (v1.countOfLines > 1)
    {
        for (int line = 0; line < v1.countOfLines; line++)
        {
            temp_v1.push_back(v1.data[line][0]);
        }
    }
    else
    {
        temp_v1 = v1.data[0];
    }

    if (v2.countOfLines > 1)
    {
        for (int line = 0; line < v2.countOfLines; line++)
        {
            temp_v2.push_back(v2.data[line][0]);
        }
    }
    else
    {
        temp_v2 = v2.data[0];
    }
    double scalar = ScalarMult(v1, v2);


    temp[0] = 0;
    temp[1] = 0;
    for (int column = 0; column < temp_v2.size(); column++)
    {
        temp[0] += temp_v1[column] * temp_v1[column];
        temp[1] += temp_v2[column] * temp_v2[column];
    }

    abs_val[0] = sqrt(temp[0]);
    abs_val[1] = sqrt(temp[1]);


    return (scalar / (abs_val[0] * abs_val[1]));
}


int GaussMatrixRank(const Matrix& matrix)
{

    Matrix temp_matrix = matrix;
    double temp_buffer;
    double mult_coeff;
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        for (int line2 = line + 1; line2 < temp_matrix.countOfLines; line2++)
        {
            if (temp_matrix.data[line][line] != 0)
                mult_coeff = -1.0 * temp_matrix.data[line2][line] / temp_matrix.data[line][line];
            else break;

            for (int column = line; column < matrix.countOfColumns; column++)
            {
                temp_matrix.data[line2][column] = temp_matrix.data[line2][column] + temp_matrix.data[line][column] * mult_coeff;
            }
        }
    }
    cout << temp_matrix << endl;
    int count_rank = 0;
    int have_line = 0;
    for (int line = 0; line < temp_matrix.countOfLines; line++)
    {
        for (int column = 0; column < temp_matrix.countOfColumns; column++)
        {
            if (temp_matrix.data[line][column] != 0.0)
            {
                have_line = 1;
                break;
            }
        }
        if (have_line)
            count_rank++;
        have_line = 0;
    }
    return count_rank;
}

Matrix GetMinorElementsMatrix(const Matrix& matrix, int line, int column)
{
    Matrix temp_matrix;
    vector<double> temp_vector;
    for (int i = 0; i < matrix.countOfLines; i++)
    {
        for (int j = 0; j < matrix.countOfColumns; j++)
        {
            if (!((i == line) && (j == column)) && !((i == line) && (j != column)) && !((i != line) && (j == column)))
            {
                temp_vector.push_back(matrix.data[i][j]);

            }

        }
        if (temp_vector.size() != 0)
        {
            temp_matrix.data.push_back(temp_vector);
            temp_vector.clear();
        }

    }
    temp_matrix.countOfLines = temp_matrix.data.size();
    temp_matrix.countOfColumns = temp_matrix.data.size(); 
    return temp_matrix;

}

Matrix TransposeMatrix(const Matrix& matrix)
{
    Matrix temp_matrix;
    vector<double> temp_vector;
    temp_matrix.countOfLines = matrix.countOfColumns;
    temp_matrix.countOfColumns = matrix.countOfLines;

    for (int column = 0; column < matrix.countOfColumns; column++)
    {
        for (int line = 0; line < matrix.countOfLines; line++)
        {
            temp_vector.push_back(matrix.data[line][column]);
        }
        temp_matrix.data.push_back(temp_vector);
        temp_vector.clear();
    }
    return temp_matrix;
}


Matrix InverseMatrix(const Matrix& matrix)
{

    try {
        if (MethodGauss(matrix) == 0)
            throw ("Inverse matrix does not exist\n");
    }
    catch (const char* msg)
    {
        printf(msg);
        throw - 1;
    }
    Matrix algMatrix;
    Matrix transAlgMatrix;
    Matrix reverseMatrix;
    vector<double> temp_vector;
    double detMatrix = MethodGauss(matrix);
    for (int line = 0; line < matrix.countOfLines; line++)
    {
        for (int column = 0; column < matrix.countOfColumns; column++)
        {
            double temp = pow(-1, line + column) * MethodGauss(GetMinorElementsMatrix(matrix, line, column));
            if (temp == 0)
                temp = fabs(temp);
            temp_vector.push_back(temp);
        }
        algMatrix.data.push_back(temp_vector);
        temp_vector.clear();
    }

    algMatrix.countOfLines = matrix.countOfLines;
    algMatrix.countOfColumns = matrix.countOfColumns;
    transAlgMatrix = TransposeMatrix(algMatrix);
    reverseMatrix = 1 / detMatrix * transAlgMatrix;
    return reverseMatrix;
}