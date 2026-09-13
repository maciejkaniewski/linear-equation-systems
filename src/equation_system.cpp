#include "equation_system.hh"

Vector EquationSystem::SolveEquation()
{
    double tmp_det = 0, main_det = 0;
    Vector result, tmp_vector;
    Matrix tmp_matrix;

    A.Transpose();
    tmp_matrix = A;
    main_det = tmp_matrix.CalculateDeterminant(tmp_matrix, SIZE);

    for (int i = 0; i < SIZE; ++i)
    {
        tmp_vector = A[i];
        A[i] = B;
        tmp_matrix = A;
        tmp_det = tmp_matrix.CalculateDeterminant(tmp_matrix, SIZE);
        result[i] = tmp_det / main_det;
        A[i] = tmp_vector;
    }

    std::cout << "Solution x = (";

    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            std::cout << result[i] << ")";
        }
        else
        {
            std::cout << result[i] << ", ";
        }
    }

    return result;
}

std::ostream &operator<<(std::ostream &output, const EquationSystem &equation_system)
{
    for (int i = 0; i < SIZE; ++i)
    {
        if (i == (SIZE / 2))
        {
            output << "| " << equation_system[i] << "| * |x_" << i + 1 << "| = | " << equation_system.GetElementB(i) << " |" << std::endl;
        }
        else
        {
            output << "| " << equation_system[i] << "|   |x_" << i + 1 << "|   | " << equation_system.GetElementB(i) << " |" << std::endl;
        }
    }

    return output;
}

std::istream &operator>>(std::istream &input, EquationSystem &equation_system)
{
    Vector tmp;
    double element = 0;

    for (int i = 0; i < SIZE; ++i)
    {
        input >> tmp;
        equation_system[i] = tmp;
    }

    for (int i = 0; i < SIZE; ++i)
    {
        input >> element;
        equation_system.ChangeElementB(element, i);
    }

    return input;
}