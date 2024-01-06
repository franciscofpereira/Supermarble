# SuperMarble 

## Description

This project was the first one developed for the class of Analysis and Synthesis of Algorithms, taken during the first semester of the second year of my bachelor's degree @IST.

## Objective

**Maximize the profit** that can be extracted from a rectangular marble sheet when cutting it into smaller rectangular pieces. The approach to solving this problem is similar to the one used in the knapsack problem. A dynamic programming approach is employed to avoid recomputing optimal solutions to subproblems.

- Refer to the file `p1.pdf` for the project's instructions and details.
- Refer to the file `relatorio_supermarble.pdf` for the full report on the solution's time complexity and description.

**Source Code:** The source code for the problem's solution is in `proj1.cpp`.

To compile `proj1.cpp`, use:
> **g++ -std=c++11 -O3 -Wall proj1.cpp -lm**

**Unit Tests:** To generate unit test files for the problem, compile and run `gen_supermarble.cpp`.

To compile `gen_supermarble.cpp`, use:
> **g++ -std=c++11 -O3 -Wall -o gen_supermarble gen_supermarble.cpp -lm**

To run `gen_supermarble.cpp` and create a unit test file, use:
> **./gen_supermarble N M P > testfile**
> (where N and M are the dimensions of the marble sheet, P the number of pieces and testfile the name of the unit test)
