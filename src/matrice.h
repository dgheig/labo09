#ifndef MATRICE_H
#define MATRICE_H
#include <vector>
#include <iostream>

typedef int coef;
typedef std::vector<coef> Vector;
typedef std::vector<Vector> Matrix;


void displayVec(const Vector& vec);
void displayMatrix(const Matrix& matrix);

bool isSquared(const Matrix& matrix);

coef maxCol(const Matrix& matrix);
Vector sumLine(const Matrix& matrix);
Vector vectMinSum(const Matrix& matrix);

void shuffleMatrix(Matrix& matrix);
void sortMatrix(Matrix& matrix);

bool sumDiagRL(const Matrix& matrix, coef& sum);
bool sumDiagLR(const Matrix& matrix, coef& sum);

std::ostream& writeVector(std::ostream& os, Vector vec);
std::ostream& writeMatrix(std::ostream& os, Matrix matrix);
std::ostream& operator<<(std::ostream& os, const Vector& vec);
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

#endif // MATRICE_H