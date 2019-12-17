#ifndef MATRICE_H
#define MATRICE_H
#include <vector>
#include <iostream>

//Definition du type coef 
typedef int coef;
//Definition du type Vector 
typedef std::vector<coef> Vector;
//Definition du type Matrix
typedef std::vector<Vector> Matrix;

/**
 * Affichage d'un vecteur sous la forme [v1,v2,v3]
 * @param vec  vecteur qui sera affiche
 */
void displayVec(const Vector& vec);

/**
 * Affichage d'une matrice sous la forme [[v1,v2,v3],[v4,v5,v6]]
 * @param matrix  vecteur qui sera affiche
 */
void displayMatrix(const Matrix& matrix);

/**
 * Verification du fait que la matrice soit carree
 * @param matrix Matrice a verifier
 * @return retourne true si la matrice est carree, false en cas contraire
 */
bool isSquared(const Matrix& matrix);

/**
 * Retourne la longueur max des vecteurs de la matrice
 * @param matrix Matrice de vecteur
 * @return taille du vecteur le plus long
 */
coef maxCol(const Matrix& matrix);

/**
 * Retourne un vecteur contenant la somme des valeurs de chacune des lignes
 * @param matrix Matrice a evaluer
 * @return Somme des vecteurs regroupe en 1 vecteur
 */
Vector sumLine(const Matrix& matrix);

/**
 * Retour le vecteur de la matrice dont la somme la plus petite.
 * @param matrix Matrice a evaluer
 * @return Le vecteur avec la plus petite somme
 */
Vector vectMinSum(const Matrix& matrix);

/**
 * Melange aleatoirement les vecteurs de la matrice
 * @param matrix Matrice a evaluer
 */
void shuffleMatrix(Matrix& matrix);

/**
 * Trie les vecteurs de la matrice en fonction du plus grand element de 
 * chaque vecteur
 * @param matrix Matrice a evaluer
 */
void sortMatrix(Matrix& matrix);

/**
 * Calcul la somme de la diagonale de droite a gauche
 * @param matrix Matrice a evaluer
 * @param sum parametre de sortie, permet de recuperer la valeur de la somme
 * @return true si la matrice est carree, false en cas contraire
 */
bool sumDiagRL(const Matrix& matrix, coef& sum);

/**
 * Calcul la somme de la diagonale de gauche a droite
 * @param matrix Matrice a evaluer
 * @param sum parametre de sortie, permet de recuperer la valeur de la somme
 * @return true si la matrice est carree, false en cas contraire
 */
bool sumDiagLR(const Matrix& matrix, coef& sum);

/**
 * 
 * @param os flux de sortie
 * @param vec Vecteur a ecrire
 * @return retour de la reference du flux de sortie
 */
std::ostream& writeVector(std::ostream& os, Vector vec);

/**
 * 
 * @param os flux de sortie
 * @param matrix Matrice a ecrire
 * @return retour de la reference du flux de sortie
 */
std::ostream& writeMatrix(std::ostream& os, Matrix matrix);

/**
 * Surchage de l'operateur << pour les type Vector
 * @param os 
 * @param vec Vecteurs a afficher
 * @return  retour de la reference du flux de sortie
 */
std::ostream& operator<<(std::ostream& os, const Vector& vec);

/**
 * Surchage de l'operateur << pour les type Matrix
 * @param os  flux de sortie
 * @param matrix Matrice a afficher
 * @return  retour de la reference du flux de sortie
 */
std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

#endif // MATRICE_H