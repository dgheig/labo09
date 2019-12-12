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
   #ifdef DEBUG
      cout << "Debug is active !" << endl;
   #endif


   WAIT_ENTER;
   return EXIT_SUCCESS;
}
