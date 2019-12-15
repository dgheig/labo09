/*
-----------------------------------------------------------------------------------
Laboratoire : Labo_09
Fichier     : labo_09_riesen_florian_gallay_david.cpp
Auteur(s)   : Florian Riesen et David Gallay
Date        : 25.11.2019

But         : Running shell simulation of the game of life program
Remarque(s) :

              There is a github repository:
               https://github.com/dgheig/labo09
              A worklfow is used to automaticly compile and test on push

              In extra directory, there's codes using SFML librairie.

Compilateur : MinGW-g++ 6.3.0 and g++ 7.4.0
-----------------------------------------------------------------------------------*/
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "src/matrice.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

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
   
   displayMatrice(matrix);
   cout << matrix << endl;;
   
   int sumRL = 0;
   int sumLR = 0;
   sumDiagRL(matrix, sumRL);
   sumDiagLR(matrix, sumLR);
   

   cout << "RL: " << sumRL << endl;
   cout << "LR: " << sumLR << endl;

   cout << "Maximum column size: " << maxCol(matrix2) << endl;
    
   
   WAIT_ENTER;
   return EXIT_SUCCESS;
}
