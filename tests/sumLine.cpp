/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_09
Fichier     : sumLine.cpp
Auteur(s)   : Florian Riesen et David Gallay
Date        : 17.12.2019

But         : test function sumLine
Remarque(s) :

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "../src/matrice.h"

using namespace std;


int exit_value = EXIT_SUCCESS;


bool testSumLine(const Matrix& matrix, const Vector& expected) {
    Vector summed = sumLine(matrix);
    displayVec(summed);
    displayVec(expected);
    if(summed.size() != expected.size()) {
        cerr << "sumLine(matrix) has different size than expected";
        exit_value = EXIT_FAILURE;
        return false;
    }
    for(size_t index = 0; index < expected.size(); ++index) {

        if(summed.size() != expected.size()) {
            cerr << "Values of sumLine(matrix) are different than expected";
            exit_value = EXIT_FAILURE;
            return false;
        }
    }
    return true;
}

int main() {

   Matrix matrix = {
      {13,14,15,16},
      {1,2,3,4},
      {8,5,6,7},
      {1,2,3,5}
   };

   Matrix matrix2 = {
      {1, 2, 3, 5, 6},
      {4, 7, 9},
      {4, 2, 9},
   };

   testSumLine(matrix, {58, 10, 26, 11});
   testSumLine(matrix2, {17, 20, 15});


   return exit_value;
}
