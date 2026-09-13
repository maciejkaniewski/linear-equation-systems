#ifndef EQUATION_SYSTEM_HH
#define EQUATION_SYSTEM_HH

#include "matrix.hh"

class EquationSystem
{
private:
    Vector B;
    Matrix A;

public:
    /**
     * @brief Get the element from B vector
     *
     * @param index
     * @return double
     */
    double GetElementB(unsigned int index) const { return B[index]; }

    /**
     * @brief Change element in B vector
     *
     * @param element
     * @param index
     */
    void ChangeElementB(double element, unsigned int index) { B[index] = element; }

    /**
     * @brief Access selected row from matrix A
     *
     * @param row
     * @return Vector
     */
    Vector operator[](unsigned int row) const { return A[row]; }

    /**
     * @brief Modify selected row from matrix A
     *
     * @param row
     * @return Vector&
     */
    Vector &operator[](unsigned int row) { return A[row]; }

    /**
     * @brief Solve equation
     * 
     * @return Vector results
     */
    Vector SolveEquation();
};

/**
 * @brief Display system
 *
 * @param output
 * @param equation_system
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &output, const EquationSystem &equation_system);

/**
 * @brief Input system
 *
 * @param input
 * @param equation_system
 * @return std::istream&
 */
std::istream &operator>>(std::istream &input, EquationSystem &equation_system);

#endif // EQUATION_SYSTEM_H