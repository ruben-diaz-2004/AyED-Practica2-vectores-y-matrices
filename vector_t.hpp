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

using namespace std;

template<class T>
class vector_t {
public:
  vector_t(const int = 0);
  ~vector_t();
  
  void resize(const int);
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  void write(ostream& = cout) const;
  void read(istream& = cin);

private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};


/**
 * Constructor de la clase vector_t
*/
template<class T>
vector_t<T>::vector_t(const int n) {
  sz_ = n;
  build();
}

/**
 * Destructor de la clase vector_t
*/
template<class T>
vector_t<T>::~vector_t() {
  destroy();
}

/**
 * Método para contruir los vectores
 * Lo utiliza el constructor
*/
template<class T>
void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

/**
 * Método que utiliza el destructor
 * Elimina el vector que ocupaba espacio en memoria
*/
template<class T>
void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

/**
 * Método para cambiar el tamaño de un vector
*/
template<class T>
void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

/**
 * Devuelve el valor de una posición del vector
*/
template<class T>
inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}


/**
 * Getter del tamaño del vector
*/
template<class T>
inline int vector_t<T>::get_size() const {
  return sz_;
}

/**
 * Setter del valor de una posición del vector
*/
template<class T>
void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

/**
 * Getter-setter de una posición de memoria
*/
template<class T>
T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * Sobrecarga del operador []
*/
template<class T>
T& vector_t<T>::operator[](const int i) {
  return at(i);
}

/**
 * Getter-setter de una posición del vector
*/
template<class T>
const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * Sobrecarga del operador []
*/
template<class T>
const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

/**
 * Método de escritura de un vector
*/
template<class T>
void vector_t<T>::write(ostream& os) const { 
  os << get_size() << ":\t";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << "\t";
  os << endl;
}

/**
 * Método de lectura de un vector
*/
template<class T>
void vector_t<T>::read(istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; ++i)
    is >> at(i);
}


// FASE II: producto escalar
/**
 * Calcula el producto escalar de dos vectores
 * @param v. Primer vector
 * @param w. Segundo vector
*/
template<class T> T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
  assert(v.get_size() == w.get_size());
  T product{0};
  for (int i{0}; i < v.get_size(); ++i) {
    product = product + v[i] * w[i];
  }
  return product;
}


/**
 * Calcula el producto escalar de dos vectores
 * @param v. Primer vector
 * @param w. Segundo vector
*/
double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
  assert(v.get_size() == w.get_size());
  rational_t product;
  for (int i{0}; i < v.get_size(); ++i) {
    product = product + v[i] * w[i];
  }
  double scal_product = product.value();
  return scal_product;
}
