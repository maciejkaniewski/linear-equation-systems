# linear-equation-systems

linear-equation-systems is a project I realized in the second semester of my studies within the Object Oriented Programming course at the Wroclaw University of Technology in the field of Control Engineering and Robotics. The main goal of this task was to create a program for solving linear systems of equations, using the own implemented vector and matrix.

## Table of Contents

  - [Features](#features)
  - [Setup](#setup)
  - [Usage](#usage)
  - [Concepts I Learned](#concepts-i-learned)
  
## Features

- Solve systems of equations with a user-defined number of unknowns
- Load equation systems as text files

## Setup
Prerequisites:
* Installed CMake *(minimum VERSION 3.0)*,

Clone repository:

    git clone https://github.com/maciejkaniewski/linear-equation-systems.git

Create `build` directory and launch `CMake`:

    cd linear-equation-systems
    mkdir build
    cd build
    cmake ..

Run `make` command and execute the program. Redirect the data file to the program input:

    make
    ./Linear_Equation_Systems < ../data/1_SYSTEM3.DAT

If the data file has not been redirected to the program input, the data has to be entered manually, which is not a very convenient method.

## Usage

After successfully starting the program, the following result appears in the terminal:

    System of equations:

    | 1 2 3 |   |x_1|   | 11 |
    | 5 2 3 | * |x_2| = | 22 |
    | 1 2 5 |   |x_3|   | 3 |

    Solution x = (2.75, 10.125, -4)

### Changing size of equation system

The size of the equation can be changed in the `vector.hh` file:

```C++
#ifndef VECTOR_HH
#define VECTOR_HH

#define SIZE 3

.
.
.

#endif // VECTOR_HH
```

After changing the `SIZE` value, the program must be recompiled.

## Concepts I Learned

- Class implementation,
- Creating methods for classes.
