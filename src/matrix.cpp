#include "matrix.hh"

Matrix::Matrix()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

Vector Matrix::operator*(const Vector &vector) const
{
    double tmp = 0;
    Vector result;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            tmp = matrix[i][j] * vector[j];
            result[i] += tmp;
        }
    }

    return result;
}

void Matrix::Transpose()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

double Matrix::CalculateDeterminant(const Matrix &matrix, int n) const
{
    double determinant = 0;

    if (n == 1)
    {
        return matrix[0][0];
    }

    if (n == 2)
    {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }

    Matrix tmp;
    int sign = 1;

    for (int i = 0; i < n; i++)
    {
        int j = 0, k = 0;

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (row != 0 && col != i)
                {
                    tmp[j][k++] = matrix[row][col];
                    if (k == n - 1)
                    {
                        k = 0;
                        j++;
                    }
                }
            }
        }

        determinant += sign * matrix[0][i] * CalculateDeterminant(tmp, n - 1);
        sign = -sign;
    }

    return determinant;
}

std::ostream &operator<<(std::ostream &output, const Matrix &matrix)
{
    for (int i = 0; i < SIZE; i++)
    {
        output << matrix[i] << " "
               << "\n";
    }

    return output;
}

std::istream &operator>>(std::istream &input, Matrix &matrix)
{
    Vector tmp;

    for (int i = 0; i < SIZE; i++)
    {
        input >> tmp;
        matrix[i] = tmp;
    }

    return input;
}