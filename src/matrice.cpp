#include "matrice.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
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
   // std::mt19937 generator(rd());
   // auto generator = std::default_random_engine {};
   // std::shuffle(matrix.begin(), matrix.end(), generator);
   // srand(unsigned(time(std::chrono::system_clock::now())));
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

   for(size_t index = 1; index < vec.size(); ++index) {
      os << ", " << vec[index] ;
   }

   os << ']';
   return os;
}

ostream& writeMatrix(ostream& os, Matrix matrix) {
   os << '[';

   if(matrix.size() > 0)
      writeVector(os, matrix[0]);

   for(size_t index = 1; index < matrix.size(); ++index){
      os << ", ";
      writeVector(os, matrix[index]);
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

/**
 * Take two vectors, left and right and return left < right
 * @param left left operand
 * @param right right operand
 * @return left < right
 */
bool hasSmallerSize(const Vector& left, const Vector& right) {
   return left.size() < right.size();
}


/**
 * return the maximum value of a vector
 * @param vec
 * @return max value of a vector (using operator<)
 */
coef maxOfVector(const Vector& vec) {
   return *max_element(vec.begin(), vec.end());
}

/**
 * Say if left biggest element is smaller than right
 * @param left
 * @param right
 * @return  true if the biggest element of left is smaller than the one of right
 */
bool maxValueIsSmaller(const Vector& left, const Vector& right) {
   return maxOfVector(left) < maxOfVector(right);
}

/**
 * Sum of the values in the vector
 * @param vec
 * @return summed values
 */
coef sumLineValues(const Vector& vec) {
   return accumulate(vec.begin(), vec.end(), 0);
}

/**
 * Compare the sum of the values of two vectors
 * @param left
 * @param right
 * @return sumLineValues(left) < sumLineValues(right)
 */
bool valuesSumIsSmaller(const Vector& left, const Vector& right) {
   return sumLineValues(left) < sumLineValues(right);
}
