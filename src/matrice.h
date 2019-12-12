#ifndef MATRICE_H
#define MATRICE_H
#include <vector>

typedef int coef;
typedef std::vector<coef> Vector;
typedef std::vector<Vector> Matrix;


void displayVec(const Vector& vec);
void displayMatrice(const Matrix& matrix);

bool isSquared(const Matrix& matrix);

coef maxCol(const Matrix& matrix);
Vector sumLine(const Matrix& matrix);
void shuffleMatrix(Matrix& matrix);
void sortMatrix(Matrix& matrix);
bool sumDiagRL(Matrix& matrix, coef& sum);
bool sumDiagLR(Matrix& matrix, coef& sum);




#endif // MATRICE_H