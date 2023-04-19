// AUTOR: Samuel Martín Morales
// FECHA: 19/04/2019
// EMAIL: alu0101359526@ull.edu.es
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Clase RPN (Reverse Polish Notation)

#ifndef RPNT_H_
#define RPNT_H_

#include <iostream>
#include <cctype>
#include <cmath>
//#include <cstdlib>

#include "queue_l_t.h"

// Clase RPN (Reverse Polish Notation)
template <class T> class rpn_t {
 public:
  // constructor
 rpn_t(void) : stack_() {}

  // destructor
  ~rpn_t() {}

  // operaciones
  const int evaluate(queue_l_t<char>&);

 private: 
  T stack_;
  void operate_(const char operador);
};


// operaciones
template<class T> const int rpn_t<T>::evaluate(queue_l_t<char>& q) {
  while (!q.empty()) 	{
    char c = q.front();
    
    q.pop();
    std::cout << "Sacamos de la cola un carácter: " << c;

    if (isdigit(c)) {
      int i = c - '0';
      stack_.push(i);
      std::cout << " (es un dígito) " << std::endl
		<< "   Lo metemos en la pila..." << std::endl;
    } else {
      std::cout << " (es un operador)" << std::endl;
      operate_(c);
    }
  }

  int result = stack_.top();
  stack_.pop();
  return result;
}

template<class T> void rpn_t<T>::operate_(const char c) {
  assert(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == 'r' || c == 'l' || c == 'c');

  int firstOperand, secondOperand;
  if (c == 'r' || c == 'l' || c == 'c') {
    firstOperand = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << firstOperand << std::endl;
  } else {
    firstOperand = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila un operando: " << firstOperand << std::endl;

    secondOperand = stack_.top();
    stack_.pop();
    std::cout << "   Sacamos de la pila otro operando: " << secondOperand << std::endl;
  }

  int result;
  switch (c) {
    case '+':
      result = secondOperand + firstOperand;
      break;
    case '-':
      result = secondOperand - firstOperand;
      break;
    case '*':
      result = secondOperand * firstOperand;
      break;
    case '/':
      result = secondOperand / firstOperand;
      break;
    case '^':
      result = pow(secondOperand, firstOperand);
      break;
    case 'r':
      result = sqrt(firstOperand);
      break;
    case 'l':
      result = log(firstOperand);
      break;
    case 'c':
      result = pow(firstOperand, 2);
      break;

  }

  stack_.push(result);
  std::cout << "   Metemos en la pila el resultado: " << result << std::endl;
}

 
#endif  // RPNT_H_
