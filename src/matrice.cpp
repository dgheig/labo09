#include "matrice.h"
#include <algorithm>
#include <numeric>
#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
using namespace std;


/**
 * Compare la taille de deux vecteur
 * @param left left operand
 * @param right right operand
 * @return left < right
 */
bool hasSmallerSize(const Vector& left, const Vector& right);

/**
 * Retourne la plus grande valeure contenue dans le vecteur vec
 * @param vec
 * @return Plus grande valeur du vecteur (avec operator<)
 */
coef maxOfVector(const Vector& vec);

/**
 * Compare les valeurs les plus grandes de deux vecteurs
 * @param left
 * @param right
 * @return  vrai si le vecteur left a une valeur max plus petite que celle du vecteur right
 */
bool maxValueIsSmaller(const Vector& left, const Vector& right);

/**
 * Somme les valeurs du vecteur
 * @param vec
 * @return valeurs additionnees
 */
coef sumLineValues(const Vector& vec);

/**
 * Compare la somme des valeurs de deux vecteurs
 * @param left
 * @param right
 * @return vrai si la somme du vecteur left est plus petite que celle du vecteur right
 */
bool valuesSumIsSmaller(const Vector& left, const Vector& right);


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
   if(matrix.size())
      return *min_element(matrix.begin(), matrix.end(), valuesSumIsSmaller);
   return Vector();
}

void shuffleMatrix(Matrix& matrix) {
   /*
      NB:
         1) srand(unsigned(time(nullptr))) is omitted
            The value is already initialized as needed
         2) random_suffle is deprecated since c++11, we should
            create a generator:
               auto generator = std::default_random_engine {};
            or
               std::random_device rd;
               std::mt19937 generator(rd());
            Then, use the generator with shuffle function:
               shuffle(matrix.begin(), matrix.end(), generator);

            We used random_suffle to match the lesson

   */;
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
