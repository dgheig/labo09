#include "matrice.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <ctime>
using namespace std;

bool hasSmallerSize(const Vector& left, const Vector& right);
coef maxOfVector(const Vector& vec);
bool maxValueIsSmaller(const Vector& left, const Vector& right);
coef sumLineValues(const Vector& vec);
bool valuesSumIsSmaller(const Vector& left, const Vector& right);

void displayVec(const Vector& vec) {
   writeVector(cout, vec);
   cout << endl;
}

void displayMatrix(const Matrix& matrix) {
   writeMatrix(cout, matrix);
   cout << endl;
}

bool isSquared(const Matrix& matrix) {
   size_t nbLines = matrix.size();
   for(Vector vec : matrix){
      if(vec.size() != nbLines)
         return false;
   }
   return true;
}

coef maxCol(const Matrix& matrix) {
   return max_element(matrix.begin(), matrix.end(), hasSmallerSize)->size();
}

Vector sumLine(const Matrix& matrix) {
   Vector result_vec(matrix.size());
   transform(matrix.begin(), matrix.end(), result_vec.begin(), sumLineValues);
   return result_vec;
}

Vector vectMinSum(const Matrix& matrix) {
   return *min_element(matrix.begin(), matrix.end(), valuesSumIsSmaller);
}

void shuffleMatrix(Matrix& matrix) {
   // std::random_device rd;
   // std::mt19937 g(rd());
   // std::shuffle(v.begin(), v.end(), g);

   srand(unsigned(time(NULL)));
   random_shuffle(matrix.begin(), matrix.end());
}



void sortMatrix(Matrix& matrix){
   sort(matrix.begin(), matrix.end(), maxValueIsSmaller);
}


bool sumDiagRL(const Matrix& matrix, coef& sum){
   if(!isSquared(matrix))
      return false;

   sum = 0;
   for(size_t line = 0, column = matrix.size() - 1; line < matrix.size(); ++line, --column) {
      sum += matrix[line][column];
   }

   return true;
}

bool sumDiagLR(const Matrix& matrix, coef& sum){

   if(!isSquared(matrix))
      return false;

   sum = 0;
   for(size_t line = 0; line < matrix.size(); ++line) {
      sum += matrix[line][line];
   }

   return true;
}

ostream& writeVector(ostream& os, Vector vec) {
   os << '[';
   if(vec.size() > 0)
      os << vec[0];

   for(auto iterator = vec.begin() + 1; iterator != vec.end(); ++iterator){
      os << ", " << *iterator ;
   }

   os << ']';
   return os;
}

ostream& writeMatrix(ostream& os, Matrix matrix) {
   os << '[';

   if(matrix.size() > 0)
      writeVector(os, matrix[0]);

   for(auto iterator = matrix.begin() + 1; iterator != matrix.end(); ++iterator){
      os << ", ";
      writeVector(os, *iterator);
   }

   os << ']';
   return os;
}

ostream& operator<<(ostream& os, const Vector& vec)
{
   return writeVector(os, vec);
}

ostream& operator<<(ostream& os, const Matrix& matrix)
{
   return writeMatrix(os, matrix);
}

// Utilities function only defined in .cpp

bool hasSmallerSize(const Vector& left, const Vector& right) {
   return left.size() < right.size();
}

coef maxOfVector(const Vector& vec) {
   return *max_element(vec.begin(), vec.end());
}

bool maxValueIsSmaller(const Vector& left, const Vector& right) {
   return maxOfVector(left) < maxOfVector(right);
}

coef sumLineValues(const Vector& vec) {
   return accumulate(vec.begin(), vec.end(), 0);
}

bool valuesSumIsSmaller(const Vector& left, const Vector& right) {
   return sumLineValues(left) < sumLineValues(right);
}
