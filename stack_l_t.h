// AUTOR: Samuel Martín Morales
// FECHA: 19/04/2019
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll_t.h"

// Clase para pilas mediante estructura dinámica
template<class T> class stack_l_t {
 public:	
  // constructor
  stack_l_t(void) : l_() {}

  // destructor
  ~stack_l_t(void) {}

  // operaciones
  // Método que se encarga de introducir un elemento en la pila
  void push(const T&);
  // Método que se encarga de eliminar el elemento que se encuentra en la cima de la pila
  void pop(void);
  // Método que se encarga de devolver el elemento que se encuentra en la cima de la pila
  const T& top(void) const;
  // Método que se encarga de comprobar si la pila está vacía
  bool empty(void) const;

  // E/S	
  std::ostream& write(std::ostream& os = std::cout) const;

private:
  dll_t<T> l_;
  // Modificación
  T sum_add_(void);
};


// operaciones
template<class T> void stack_l_t<T>::push(const T& dato) {
  dll_node_t<T>* nodo = new dll_node_t<T>(dato);
  assert(nodo != NULL);
  std::cout << std::endl;
  // Modificación
  // Mostramos la pila para poder ver el contenido de esta
  l_.push_front(nodo);
  write();
  std::cout << " La suma de las celdas con elementos impares tras realizar un push es: " << sum_add_() << std::endl;
}

template<class T> void stack_l_t<T>::pop(void) {
  assert(!empty());
  delete l_.pop_front();
}

template<class T> const T& stack_l_t<T>::top(void) const {
  assert(!empty());
  return l_.get_head()->get_data();
}

template<class T> bool stack_l_t<T>::empty(void) const {
  return l_.empty();
}

// E/S
template<class T> std::ostream& stack_l_t<T>::write(std::ostream& os) const {
  dll_node_t<T>* aux = l_.get_head();
  while (aux != NULL) { 
    os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
    aux = aux->get_next();
  }
  os << " └─────┘" << std::endl;
  return os;
}

// Modificación
// Suma del contenido de la pila que sean impares
template<class T> T stack_l_t<T>::sum_add_(void) {
  dll_node_t<T>* aux = l_.get_head();
  T sum = 0;
  while (aux != NULL) {
    if (aux->get_data() % 2 != 0) {
      sum += aux->get_data();
    }
    aux = aux->get_next();
  }
  return sum;
}


#endif  // STACKL_H_
