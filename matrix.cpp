#include "matrix.h"

template<typename T>
MatrixT<T> operator+(const MatrixT<T> &m1, const MatrixT<T> &m2)
{
    MatrixT<T> matr(m1.row, m1.col);
    for (size_t i = 0; i < matr.row; ++i)
    {
        for (size_t j = 0; j < matr.col; ++j)
        {
            matr[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }
    return matr;
}

template<typename T>
MatrixT<T> operator-(const MatrixT<T> &m1, const MatrixT<T> &m2)
{
    MatrixT<T> matr(m1.row, m1.col);
    for (size_t i = 0; i < matr.row; ++i)
    {
        for (size_t j = 0; j < matr.col; ++j)
        {
            matr[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
        }
    }
    return matr;
}

template<typename T>
MatrixT<T> operator*(const MatrixT<T> &m, const T &value)
{
    MatrixT<T> matr(m.row, m.col);
    for (size_t i = 0; i < matr.row; ++i)
    {
        for (size_t j = 0; j < matr.col; ++j)
        {
            matr[i][j] = m.matrix[i][j] * value;
        }
    }
    return matr;
}

template<typename T>
MatrixT<T> operator/(const MatrixT<T> &m, const T &value)
{
    MatrixT<T> matr(m.row, m.col);
    for (size_t i = 0; i < matr.row; ++i)
    {
        for (size_t j = 0; j < matr.col; ++j)
        {
            matr[i][j] = m.matrix[i][j] / value;
        }
    }
    return matr;
}

template<typename T>
MatrixT<T> operator*(const T &value, const MatrixT<T> &m)
{
    MatrixT<T> matr(m.row, m.col);
    for (size_t i = 0; i < matr.row; ++i)
    {
        for (size_t j = 0; j < matr.col; ++j)
        {
            matr[i][j] = m.matrix[i][j] / value;
        }
    }
    return matr;
}

template<typename T>
MatrixT<T> operator*(const MatrixT<T> &m1, const MatrixT<T> &m2)
{
    if (m1.col != m2.row)
    {
        throw -1;
    }
    MatrixT<T> matr(m1.row, m2.col);
    for (size_t i = 0; i < m1.row; ++i)
    {
        matr[i].resize(m2.col);
        for (size_t j = 0; j < m2.col; ++j)
        {
            matr[i][j] = 0;
            for (size_t k = 0; k < m1.col; ++k)
            {
                matr[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
            }
        }
    }
    return matr;
}
