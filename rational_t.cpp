// AUTOR: Rubén Díaz Marrero
// FECHA: 03/03/2023
// EMAIL: alu0101552613@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 2
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html

// pauta de estilo [92]: comentarios multilínea usando solo "//"

#include "rational_t.hpp"

/**
 * Constructor de la clase rational_t
*/
rational_t::rational_t(const int n, const int d) {
  assert(d != 0);
  num_ = n, den_ = d;
}

/**
 * Getter del numerador
*/
inline
int rational_t::get_num() const {
  return num_;
}

/**
 * Getter del denominador
*/
inline
int rational_t::get_den() const {
  return den_;
}

/**
 * Setter del numerador
*/
void rational_t::set_num(const int n) {
  num_ = n;
}


/**
 * Setter del denominador
*/
void rational_t::set_den(const int d) {
  assert(d != 0);
  den_ = d;
}

/**
 * Método que devuelve el valor en doble presición
 * del racional
*/
inline
double rational_t::value() const { 
  return double(get_num()) / get_den();
}

/**
 * Método que devuelve el racional * -1
*/
rational_t  rational_t::opposite() const { 
  return rational_t((-1)*get_num(), get_den());
}

/**
 * Método que devuelve el recíproco de un racional
*/
rational_t rational_t::reciprocal() const { 
  return rational_t(get_den(), get_num());
}


// comparaciones
/**
 * Comparación de igualdad entre dos racionales
*/
bool rational_t::is_equal(const rational_t& r, const double precision) const { 
  return fabs(value() - r.value()) < precision;
}

/**
 * Comparación > entre dos racionales
*/
bool rational_t::is_greater(const rational_t& r, const double precision) const {
  return (value() - r.value()) > precision;
}


/**
 * Comparación < entre dos racionales
*/
bool rational_t::is_less(const rational_t& r, const double precision) const {
  return r.is_greater(*this, precision);
}


// operaciones
/**
 * Suma de racionales
*/
rational_t rational_t::add(const rational_t& r) const {
  return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                    get_den() * r.get_den());
}


/**
 * Resta de racionales
*/
rational_t rational_t::substract(const rational_t& r) const {
  return add(r.opposite());
}

/**
 * Multiplicación de racionales
*/
rational_t rational_t::multiply(const rational_t& r) const {
  return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

/**
 * División de racionales
*/
rational_t rational_t::divide(const rational_t& r) const {
  return multiply(r.reciprocal());
}


// FASE I: operadores
/**
 * Sobrecarga del operador suma
*/
rational_t operator+(const rational_t& a, const rational_t& b) {
  return a.add(b);
  // rellenar código
}


/**
 * Sobrecarga del operador resta
*/
rational_t operator-(const rational_t& a, const rational_t& b) {
  return a.substract(b);
  // rellenar código
}

/**
 * Sobrecarga del operador *
*/
rational_t operator*(const rational_t& a, const rational_t& b) {
  return a.multiply(b);
  // rellenar código
}

/**
 * Sobrecarga del operador /
*/
rational_t operator/(const rational_t& a, const rational_t& b) {
  return a.divide(b);
  // rellenar código
}



// E/S
/**
 * Método de escritura de un racional
*/
void rational_t::write(ostream& os) const {
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}

/**
 * Método de lectura de un racional
*/
void rational_t::read(istream& is) {
  is >> num_ >> den_;
  assert(den_ != 0);
}

/**
 * Sobrecarga del operador <<
*/
ostream& operator<<(ostream& os, const rational_t& r) {
  r.write(os);
  return os;
}

/**
 * Sobrecarga del operador >>
*/
istream& operator>>(istream& is, rational_t& r) {
  r.read(is);
  return is;
}