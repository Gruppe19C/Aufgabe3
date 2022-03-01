#ifndef Matrix3
#define Matrix3

#include <string>
#include <iostream>
#include "MyExceptions.h"

class Matrix33
{
public:

    // Static Class-Functions
    static Matrix33 zeros();
    static Matrix33 ones();

    // Construction
    Matrix33( double m11, double ml2, double m13, 
              double m21, double m22, double m23, 
              double m31, double m32, double m33 );

    Matrix33();

    double& get(int row, int col)
    {
        try {
            if (row > 2 || col > 2) throw IndexException(col, row);
            return m_matrix[row][col];
        }
        catch (IndexException& e)
        {
            std::cout << "Exception:\n" << e.getError() << std::endl;
    }}

    std::string toString() const;

    Matrix33 operator*(Matrix33& rhs);
    Matrix33 operator+(Matrix33& rhs);
    Matrix33 operator*(double rhs);
    Matrix33 operator+=(Matrix33& rhs);
    //static Matrix33 operator*(double val, Matrix33& rhs);
    operator double();

private:
    double m_matrix[3][3];
};

#endif