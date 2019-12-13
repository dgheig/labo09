#include "matrice.h"
#include <algorithm>
#include <iostream>
using namespace std;

bool hasSmallerSize(Vector left, Vector right);
coef sumLineValues(Vector vec);

coef maxCol(const Matrix& matrix) {
   return max_element(matrix.begin(), matrix.end(), hasSmallerSize)->size();
}

Vector sumLine(const Matrix& matrix) {
   Vector result_vec(matrix.size());
   transform(matrix.begin(), matrix.end(), result_vec.begin(), sumLineValues);
   return result_vec;
}

void shuffleMatrix(Matrix& matrix) {

}

bool isSquared(const Matrix& matrix){
   int nbLines = matrix.size();
   for(Vector vec : matrix){
      if(vec.size() != nbLines)
         return false;
   }
   return true;
}

void displayMatrice(const Matrix& matrix){
   cout<<"[";
   int ElementNum = 1;
   
   for(Vector vec : matrix){
      char separateur = ElementNum == matrix.size() ? '\0' : ',';
      displayVec(vec);
      cout << separateur;
      ElementNum++;
   }
   
   cout<<"]";
}

void displayVec(const Vector& vec){
   cout<<"[";
   int ElementNum = 1;
   for(coef coeficient : vec){
      char separateur = ElementNum == vec.size() ? '\0' : ',';
      cout << coeficient << separateur ;
      ElementNum++;

   }
      
   cout<<"]";
}

bool hasSmallerSize(Vector left, Vector right) {
   return left.size() < right.size();
}


coef sumLineValues(Vector vec) {
   coef sum = 0;
   for(auto val : vec) {
      sum += val;
   }
   return sum;
}