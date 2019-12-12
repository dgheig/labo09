#include "matrice.h"
#include <algorithm>
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