#include <string>

class IndexException
{
public:

    IndexException(const int& col, const int& row)
        : m_col(col), m_row(row)
    {  }

    std::string getError() const {
        return "Auf den Index \"" + std::to_string(m_col) + " , " + std::to_string(m_row) + "\" konnte nicht zugegriffen werden!\n";
    }

private:
    int m_col;
    int m_row;
};


