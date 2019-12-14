#include "matrice.h"
#include <algorithm>
#include <iostream>
#include <ctime>
using namespace std;

bool hasSmallerSize(Vector left, Vector right);
bool MaxOfVector(Vector left, Vector right);
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
   srand(unsigned(time(NULL)));
   random_shuffle(matrix.begin(), matrix.end());
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


void sortMatrix(Matrix& matrix){
   sort(matrix.begin(), matrix.end(), MaxOfVector);
}

bool hasSmallerSize(Vector left, Vector right) {
   return left.size() < right.size();
}


bool MaxOfVector(Vector left, Vector right){
   return *max_element(left.begin(), left.end()) < *max_element(right.begin(), right.end());
}


coef sumLineValues(Vector vec) {
   coef sum = 0;
   for(auto val : vec) {
      sum += val;
   }
   return sum;
}

bool sumDiagRL(Matrix& matrix, coef& sum){
   if(!isSquared(matrix))
      return false;
      
   for(int coefC = 0; coefC < matrix.size(); coefC++)
   {
      for(int coefL = 0; coefL < matrix[coefC].size(); coefL++)
      {
         //if(i+j==(m-1))
         if(coefC+coefL == (matrix.size()-1))
            sum += matrix[coefC][coefL];
      }
   }
}
   
 bool sumDiagLR(Matrix& matrix, coef& sum){
  
   if(!isSquared(matrix))
      return false;
      
   for(int coefC = 0; coefC < matrix.size(); coefC++)
   {
      for(int coefL = 0; coefL < matrix[coefC].size(); coefL++)
      {
         
         if(coefC == coefL)
            sum += matrix[coefC][coefL];
      }
   }
   
  
   
}