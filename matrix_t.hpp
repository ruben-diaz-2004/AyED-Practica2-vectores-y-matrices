// AUTOR: Rubén Díaz Marrero
// FECHA: 03/03/2023
// EMAIL: alu0101552613@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

#pragma once

#include <iostream>
#include <cassert>

#include "vector_t.hpp"

using namespace std;

template<class T>
class matrix_t {
public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  
  void resize(const int, const int);
  
  // getters
  int get_m(void) const;
  int get_n(void) const;
  
  // getters-setters
  T& at(const int, const int);
  T& operator()(const int, const int);
  
  // getters constantes
  const T& at(const int, const int) const;
  const T& operator()(const int, const int) const;
  
  // operaciones y operadores
  void multiply(const matrix_t<T>&, const matrix_t<T>&);

  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  int m_, n_; // m_ filas y n_ columnas
  vector_t<T> v_;
  
  int pos(const int, const int) const;
};


/**
 * Constructor de matrices pasando filas y columnas
 * @param m, filas
 * @param n, columnas
*/
template<class T> matrix_t<T>::matrix_t(const int m, const int n) { 
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


/**
 * Destructor de la clase matrix_t
*/
template<class T>
matrix_t<T>::~matrix_t()
{}


/**
 * Redimensiona una matriz
 * @param m, filas
 * @param n, columnas
*/
template<class T>
void matrix_t<T>::resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  m_ = m;
  n_ = n;
  v_.resize(m_ * n_);
}


/**
 * Getter de las filas
*/
template<class T>
inline int matrix_t<T>::get_m() const {
  return m_;
}


/**
 * Getter de las columnas
*/
template<class T>
inline int matrix_t<T>::get_n() const {
  return n_;
}


/**
 * Lo utilizamos como getter-setter
 * Comprueba las dimensiones de la matriz y devuelve la posición
 * en el vector del punto que pasamos
*/
template<class T>
T& matrix_t<T>::at(const int i, const int j) {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


/**
 * Sobrecarga del operador ()
 * Llama al método at.
*/
template<class T>
T& matrix_t<T>::operator()(const int i, const int j) {
  return at(i, j);
}


/**
 * Lo utilizamos como getter-setter
 * Comprueba las dimensiones de la matriz y devuelve la posición
 * en el vector del punto que pasamos
*/
template<class T>
const T& matrix_t<T>::at(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return v_[pos(i, j)];
}


/**
 * Sobrecarga del operador ()
 * Llama al método at.
*/
template<class T>
const T& matrix_t<T>::operator()(const int i, const int j) const {
  return at(i, j);
}


/**
 * Método de escritura de la matriz
 * Muestra en pantalla la matriz deseada
*/
template<class T>
void matrix_t<T>::write(ostream& os) const { 
  os << get_m() << "x" << get_n() << endl;
  for (int i = 1; i <= get_m(); ++i) {
    for (int j = 1; j <= get_n(); ++j)
      os << at(i, j) << "\t";
    os << endl;
  }
  os << endl;
}


/**
 * Método de lectura de la matriz
 * Lee los elementos de una matriz
*/
template<class T>
void matrix_t<T>::read(istream& is) {
  is >> m_ >> n_;
  resize(m_, n_);
  for (int i = 1; i <= get_m(); ++i)
    for (int j = 1; j <= get_n(); ++j)
      is >> at(i, j);
}

/**
 * Indica la posición en el vector de un elemento
 * de la matriz
*/
template<class T>
inline
int matrix_t<T>::pos(const int i, const int j) const {
  assert(i > 0 && i <= get_m());
  assert(j > 0 && j <= get_n());
  return (i - 1) * get_n() + (j - 1);
}



// FASE III: producto matricial
/**
 * Calcula el producto matricial de las matrices A y B
 * @param A. Primera matriz
 * @param B. Segunda matriz
*/
template<class T>
void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
  assert(A.get_n() == B.get_m());
  resize(A.get_m(), B.get_n());
  // Calcular el producto de las matrices A y B
  for(int i{1}; i <= A.get_m(); i++) {
      for(int j{1}; j <= A.get_n(); j++) {
          // at(i,j) = 0;
          for(int k{1}; k <= A.get_n(); k++) {
              at(i,j) = at(i,j) + A.at(i,k) * B.at(k,j);
          }
      }
  }
}
