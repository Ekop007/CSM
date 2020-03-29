#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <vector>

// матрица[строка][столбец]
template <typename T>
class MatrixT
{
public:
    MatrixT() : row(0), col(0) {}
    MatrixT(size_t n) : row(n), col(n)
    {
        matrix.resize(row);
        for (auto it = matrix.begin(); it != matrix.end(); ++it)
        {
            it->resize(col);
        }
    }

    MatrixT(size_t rows, size_t cols): row(rows), col(cols)
    {
        matrix.resize(row);
        for (auto it = matrix.begin(); it != matrix.end(); ++it)
        {
            it->resize(col);
        }
    }

    MatrixT(const MatrixT& M) : row(M.row), col(M.col)
    {
        matrix = M.matrix;
    }

    MatrixT(MatrixT&& M) noexcept : row(std::move(M.row)), col(std::move(M.col))
    {
        matrix = std::move(M.matrix);
    }

    ~MatrixT() {}

    void resize(const size_t n)
    {
        row = n;
        col = n;
        matrix.resize(row);
        for (auto it = matrix.begin(); it != matrix.end(); ++it)
        {
            it->resize(col, 0);
        }
    }

    void resize(const size_t rows, const size_t cols)
    {
        col = cols;
        row = rows;
        matrix.resize(row);
        for (auto it = matrix.begin(); it != matrix.end(); ++it)
        {
            it->resize(col, 0);
        }
    }


    void setAllValue(T value)
    {
        for (auto row_it = matrix.begin(); row_it != matrix.end(); ++row_it)
        {
            for (auto col_it = row_it->begin(); col_it != row_it->end(); ++col_it)
            {
                (*col_it) = value;
            }
        }
    }

    T determ()
    {
        if (col == row)
        {
            std::vector<m_vec *> matr(col);
            for (size_t i = 0; i < col; ++i)
            {
                matr[i] = &matrix[i];
            }
            deterninant = determ(matr, col);
            for (size_t i = 0; i < col; ++i)
            {
                matr[i] = nullptr;
            }
        }
        else
        {
            return T();
        }
    }


private:
    T determ(std::vector<std::vector<T> *> &matr, size_t size)
    {
        T det(0);
        if (col != row)
        {
            return det;
        }
        if (size == 1)
        {
            det = matr[0][0];
        }
        else if (size == 2)
        {
            det = (*matr[0])[0] * (*matr[1])[1] - (*matr[0])[1] * (*matrix[1])[0];
        }
        else
        {
            std::vector<m_vec *> arr(size - 1);
            for (size_t i = 0; i < size; ++i)
            {
                for (size_t j = 0; i < size - 1; ++i)
                {
                    if (j < i)
                    {
                        arr[j] = matr[j];
                    }
                    else
                    {
                        arr[j] = matr[j+1];
                    }
                    det += pow(-1.0, i + j) * determ(arr, size - 1) * (*matr[i])[size - 1];
                }
            }

        }
    }

public:
    MatrixT &transposed()
    {
        m_matrix matr;
        matr.resize(col);
        for (size_t i = 0; i < col; ++i)
        {
            matr[i].resize(row);
            for (size_t j = 0; i < row; ++i)
            {
                matr[i][j] = matrix[j][i];
            }
        }
        matrix.clear();
        matrix = std::move(matr);
        std::swap(col, row);
        return *this;
    }

    MatrixT transposed(int)
    {
        MatrixT M(*this);
        return M.transposed();
    }

    MatrixT inverse()
    {
        MatrixT M(std::move(this->transposed(1)));
        M /= this->determ();
        return M;
    }

    MatrixT &operator=(const MatrixT &m)
    {
        if (this != &m)
        {
            col = m.col;
            row = m.row;
            matrix = m.matrix;
        }
        return *this;
    }

    MatrixT &operator=(MatrixT &&m)
    {
        if (this != &m)
        {
            col = std::move(m.col);
            row = std::move(m.row);
            matrix = std::move(m.matrix);
        }
        return *this;
    }

    std::vector<T> &operator[](size_t index) { return matrix[index]; }
    const std::vector<T> &operator[](size_t index) const { return matrix[index]; }

    MatrixT &operator+=(const MatrixT &m)
    {
        for (size_t i = 0; i < row; ++i)
        {
            for (size_t j = 0; j < col; ++j)
            {
                matrix[i][j] += m.matrix[i][j];
            }
        }
        return *this;
    }

    MatrixT &operator-=(const MatrixT &m)
    {
        for (size_t i = 0; i < row; ++i)
        {
            for (size_t j = 0; j < col; ++j)
            {
                matrix[i][j] -= m.matrix[i][j];
            }
        }
        return *this;
    }

    MatrixT &operator*=(const MatrixT &m)
    {
        if (col != m.row)
        {
            throw -1;
        }
        m_matrix matr(row);
        for (size_t i = 0; i < row; ++i)
        {
            matr[i].resize(m.col);
            for (size_t j = 0; j < m.col; ++j)
            {
                matr[i][j] = 0;
                for (size_t k = 0; k < col; ++k)
                {
                    matr[i][j] += matrix[i][k] * m.matrix[k][j];
                }
            }
        }
        col = m.col;
        matrix = matr;
        return *this;
    }

    MatrixT &operator*=(const T &value)
    {
        for (size_t i = 0; i < row; ++i)
        {
            for (size_t j = 0; j < col; ++j)
            {
                matrix[i][j] *= value;
            }
        }
        return *this;
    }

    MatrixT &operator/=(const T &value)
    {
        for (size_t i = 0; i < row; ++i)
        {
            for (size_t j = 0; j < col; ++j)
            {
                matrix[i][j] /= value;
            }
        }
        return *this;
    }

    template <typename T1>
    friend MatrixT<T1> operator+(const MatrixT<T1> &m1, const MatrixT<T1> &m2);
    template <typename T1>
    friend MatrixT<T1> operator-(const MatrixT<T1> &m1, const MatrixT<T1> &m2);
    template <typename T1>
    friend MatrixT<T1> operator*(const MatrixT<T1> &m, const T1 &value);
    template <typename T1>
    friend MatrixT<T1> operator/(const MatrixT<T1> &m, const T1 &value);
    template <typename T1>
    friend MatrixT<T1> operator*(const T1 &value, const MatrixT<T1> &m);
    template <typename T1>
    friend MatrixT<T1> operator*(const MatrixT<T1> &m1, const MatrixT<T1> &m2);

    size_t getR() const { return row; }
    size_t getC() const { return col; }


private:
    using m_vec = std::vector<T>;
    using m_matrix = std::vector<std::vector<T>>;

    size_t row;
    size_t col;
    std::vector<std::vector<T>> matrix;
    T deterninant;
};

#endif // MATRIX_H
