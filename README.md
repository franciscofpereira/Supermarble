
Descrition: This project was the first one developed for the class of Analysis and Synthesis of Algorithms, 
            which was taken on the first semester of the second year of my bachelor's degree @IST. 
            
Objective: Maximize the profit that can be extracted from a rectangular marble sheet when cutting it into smaller rectangular pieces.
           The approach to solve this problem is similar to the one used on the knapsack problem. A dynamic programming approach is used
           to avoid recomputing the optimal solutions to the subproblems.
            

-Refer to the file p1.pdf for the project's instructions and details.
-Refer to the file relatiorio_supermarble.pdf for the full report on the solution's time complexity and description.

-The source code to the problem's solution is in proj1.cpp.

To compile proj1.cpp use:
> **_NOTE:_** g++ -std=c++11 -O3 -Wall proj1.cpp -lm

-To generate unit test files for the problem, you can compile and run gen_supermarble.cpp.

To compile gen_supermarble.cpp use:
g++ -std=c++11 -O3 -Wall -o gen_supermarble gen_supermarble.cpp -lm

To run gen_supermarble.cpp and create a unit testfile use:
./gen_supermarble <N> <M> <P> > testfile (where N and M are the dimensions of the marble sheet and P the number of pieces)  
