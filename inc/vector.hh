#ifndef VECTOR_HH
#define VECTOR_HH

#define SIZE 3

#include <iostream>
#include <cmath>

/**
 * @brief Model the concept of vector
 * 
 */
class Vector
{
private:
    double array[SIZE];

public:
    /**
     * @brief Construct vector filled with 0
     *
     */
    Vector();

    /**
     * @brief Access selected element from vector
     *
     * @param index
     * @return double
     */
    double operator[](unsigned int index) const { return array[index]; }

    /**
     * @brief Modify selected element from vector
     *
     * @param index
     * @return double&
     */
    double &operator[](unsigned int index) { return array[index]; }

    /**
     * @brief Add two vectors
     *
     * @param other
     * @return Vector
     */
    Vector operator+(const Vector &other) const;

    /**
     * @brief Subtract two vectors
     *
     * @param other
     * @return Vector
     */
    Vector operator-(const Vector &other) const;

    /**
     * @brief Divide vector by number
     *
     * @param number
     * @return Vector
     */
    Vector operator/(const double &number) const;

    /**
     * @brief Multiply vector by number
     *
     * @param other
     * @return Vector
     */
    Vector operator*(const double &other) const;

    /**
     * @brief Scalar multiplication of two vectors 
     * 
     * @param number
     * @return double 
     */
    double operator*(const Vector &number) const;

    /**
     * @brief Calculate length of vector
     * 
     * @param vector 
     * @return double 
     */
    double CalcuateVectorLength() const;
};

/**
 * @brief Display vector
 *
 * @param output stream
 * @param vector
 * @return std::ostream&
 */
std::ostream &operator<<(std::ostream &output, const Vector &vector);

/**
 * @brief Input vector
 *
 * @param input stream
 * @param vector
 * @return std::istream&
 */
std::istream &operator>>(std::istream &input, Vector &vector);

#endif // VECTOR_HH