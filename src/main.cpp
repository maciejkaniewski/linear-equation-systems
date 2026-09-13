#include "equation_system.hh"

int main(int argc, char **argv)
{
    EquationSystem system;

    std::cin >> system;
    std::cout << "System of equations:" << std::endl << std::endl;
    std::cout << system << std::endl;

    system.SolveEquation();
}