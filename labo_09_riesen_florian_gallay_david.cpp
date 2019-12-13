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
#include "src/matrice.h"

using namespace std;

#define WAIT_ENTER while(cin.get()!='\n')

int main() {
   
   Matrix matix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{1,2,3,4}};
   
   displayMatrice(matix);
   
   cout << isSquared(matix);
   
   WAIT_ENTER;
   return EXIT_SUCCESS;
}
