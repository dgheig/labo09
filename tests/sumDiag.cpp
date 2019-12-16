/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_09
Fichier     : sumDiag.cpp
Auteur(s)   : Florian Riesen et David Gallay
Date        :

But         :
Remarque(s) :

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include "../src/matrice.h"
using namespace std;

int exit_value = EXIT_SUCCESS;

bool testSumDiagRL(const Matrix& matrix, coef expected = 0) {
    int sum = 0;
    displayMatrix(matrix);
    sumDiagRL(matrix, sum);

    if (sum != expected) {
        cerr << "sumDiagRL(matrix) has different value than expected\n"
             << "Expected: " << expected << '\n'
             << "Result: "   << sum << endl;
        exit_value = EXIT_FAILURE;
        return false;
    }
    return true;
}

bool testSumDiagLR(const Matrix& matrix, coef expected = 0) {
    int sum = 0;
    displayMatrix(matrix);
    sumDiagLR(matrix, sum);

    if (sum != expected) {
        cerr << "sumDiagLR(matrix) has different value than expected\n"
             << "Expected: " << expected << '\n'
             << "Result: "   << sum << endl;
        exit_value = EXIT_FAILURE;
        return false;
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

    testSumDiagLR(matrix, 26);
    testSumDiagRL(matrix, 25);


    return exit_value;
}
