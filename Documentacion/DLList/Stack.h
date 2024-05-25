//
// Created by OVERLORD on 10/04/2024.
//
#ifndef STACK_H
#define STACK_H

#include "DLList.h"

template<typename T>
class Stack {
public:
    Stack() {}

    ~Stack() {}

    void push(const T& data) {
        list.push_back(data); // Agrega el elemento al final de la lista
    }

    void pop() {
        list.pop_back(); // Elimina el último elemento añadido
    }

    const T& top() const {
        return list.back(); // Devuelve una referencia al último elemento añadido
    }

    bool empty() const {
        return list.empty(); // Verifica si la pila está vacía
    }

    int size() const {
        return list.size(); // Devuelve el tamaño de la pila
    }

    void clear() {
        list.clear(); // Elimina todos los elementos de la pila
    }

    void print() const {
        list.print(); // Imprime los elementos de la pila
    }

private:
    DLList<T> list;
};

#endif
