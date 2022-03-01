#include <string>
#include <sstream>
#include <iomanip>

#include "Matrix.h"


// ----------------------------------------------------------------------------

Matrix33::Matrix33()
{
}


Matrix33 Matrix33::zeros()
{
    return Matrix33(0,0,0  ,0,0,0  ,0,0,0);
}


// ----------------------------------------------------------------------------

Matrix33 Matrix33::ones()
{
    return Matrix33(1,1,1  ,1,1,1  ,1,1,1);
}


// ----------------------------------------------------------------------------

Matrix33::Matrix33( double m11, double m12, double m13, double m21, double m22, double m23, double m31, double m32, double m33 )
{
    m_matrix[0][0] = m11;
    m_matrix[0][1] = m12;
    m_matrix[0][2] = m13;
    m_matrix[1][0] = m21; m_matrix[1][1] = m22; m_matrix[1][2] = m23;
    m_matrix[2][0] = m31; m_matrix[2][1] = m32; m_matrix[2][2] = m33;
}


// ----------------------------------------------------------------------------

std::string Matrix33::toString() const
{
    std::stringstream s;
    s << "----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[0][0];
    s << " | " <<std::setw(6) << m_matrix[0][1];
    s << " | " <<std::setw(6) << m_matrix[0][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[1][0];
    s << " | " <<std::setw(6) << m_matrix[1][1];
    s << " | " <<std::setw(6) << m_matrix[1][2] << " |";
    s << "\n----------------------------\n";
    s << "| "  <<std::setw(6) << m_matrix[2][0];
    s << " | " <<std::setw(6) << m_matrix[2][1];
    s << " | " <<std::setw(6) << m_matrix[2][2] << " |";
    s << "\n----------------------------\n";

    return s.str();
}


// ----------------------------------------------------------------------------


Matrix33 Matrix33::operator*(Matrix33& rhs)
{
    Matrix33 result;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.get(i, j) = 0;
            for (int k = 0; k < 3; k++)
            {
                result.get(i, j) += get(i, k) * rhs.get(k, j);
            }
        }
    }
    return result;
}


Matrix33 Matrix33::operator+(Matrix33& rhs)
{
    Matrix33 result;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.get(i, j) = get(i, j) + rhs.get(i, j);
        }
    }
    return result;
}


Matrix33 Matrix33::operator*(double rhs)
{
    Matrix33 result;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result.get(i, j) = get(i, j) * rhs;
        }
    }
    return result;
}


Matrix33 Matrix33::operator+=(Matrix33& rhs)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            get(i, j) += rhs.get(i, j);
        }
    }
    return *this;
}


//Matrix33 Matrix33::operator*(double val, Matrix33& rhs)
//{
//    Matrix33 result;
//    for (int i = 0; i < 3; i++)
//    {
//        for (int j = 0; j < 3; j++)
//        {
//            result.get(i, j) = val * rhs.get(i, j);
//        }
//    }
//    return result;
//}


Matrix33::operator double()
{
    double det = get(0, 0) * (get(1, 1) * get(2, 2) - get(1, 2) * get(2, 1)) -
        get(0, 1) * (get(1, 0) * get(2, 2) - get(1, 2) * get(2, 0)) +
        get(0, 2) * (get(1, 0) * get(2, 1) - get(1, 1) * get(2, 0));
    return det;
}