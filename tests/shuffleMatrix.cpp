/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_09
Fichier     : shuffleMatrix.cpp
Auteur(s)   : Florian Riesen et David Gallay
Date        : 17.12.2019

But         : test function shuffleMatrix
Remarque(s) :

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "../src/matrice.h"
using namespace std;

int exit_value = EXIT_SUCCESS;

bool compareMatrix(const Matrix& m1, const Matrix& m2) {
   if(m1.size() != m2.size()) return false;
   for(size_t line = 0; line < m1.size(); ++line) {
      if(m1[line].size() != m2[line].size()) return false;
      for(size_t col = 0; col < m1[line].size(); ++col) {
         if(m1[line][col] != m2[line][col]) return false;
      }
   }
   return true;
}

int main() {

    Matrix matrix = {
        {13, 14, 15, 16, 6},
        {1, 2, 3, 4, 2},
        {8, 5, 6, 7},
        {1, 2, 3, 5},
        {1, 7, 3, 79},
        {11, 12, 15, 8, 6},
    };

   Matrix shuffled1 = matrix;
   shuffleMatrix(shuffled1);

   Matrix shuffled2 = matrix;
   shuffleMatrix(shuffled2);

   displayMatrix(matrix);
   cout << endl;

   displayMatrix(shuffled1);
   cout << endl;

   displayMatrix(shuffled2);
   cout << endl;

   if(compareMatrix(matrix, shuffled1)) return EXIT_FAILURE;
   if(compareMatrix(matrix, shuffled2)) return EXIT_FAILURE;
   if(compareMatrix(shuffled1, shuffled2)) return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
