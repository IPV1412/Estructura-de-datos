# Proyecto Parcial1 - DLList

#### Jonathan Nava Noguez   IPV1412

#### Estructura de datos    ID: 6576

**Instrucciones:** Entregar la documentación del siguiente código explicando lo que hace cada bloque de código, las funciones y palabras reservadas del sistema utilizadas.

---

## SLList.h - Interfaz
### Inicio
```cpp
#include <utility>
#include <iostream>
```
Se incluyen las bibliotecas `utility` e `iostream` para utilizar las utilidades y las funciones de entrada/salida estándar, respectivamente.

```cpp
template <typename Object>
class DLList {
private:
```
Inicializa la clase DLList  que implementa la lista doblemente enlazada, que almacena la informacion en una plantilla privada.
<br>

### Clases Anidadas
#### Node
```cpp 
struct Node {
    Object data;
    Node *prev;
    Node *next;

    Node(const Object &d = Object{}, Node *p = nullptr, Node *n = nullptr);
    Node(Object &&d, Node *p = nullptr, Node *n = nullptr);
};
```
La clase anidada `Node` define la estructura de un nodo de la lista doblemente enlazada. Cada nodo contiene un dato (`data`), un puntero al nodo anterior (`prev`) y un puntero al siguiente nodo (`next`).
Se proporcionan dos constructores: uno para inicializar un nodo con un dato constante por referencia (`const Object &d`) y otro para un dato en movimiento (`Object &&d`).

#### Const_iterator
```cpp
public:
class const_iterator{
public:
    const_iterator();
    const Object &operator*() const;
    const_iterator &operator++();
    const_iterator operator++ (int);
    bool operator== (const const_iterator& rhs) const;
    bool operator!= (const const_iterator& rhs) const;

protected:
    Node* current;
    Object& retrieve() const;
    const_iterator(Node *p);

    friend class DLList<Object>;
};
```
La clase de iterador constante `const_iterator` permite acceder a los elementos de la lista, pero no modificarlos. 
Proporciona operadores de desreferenciación (`*`) para acceder al elemento actual, y operadores de incremento (`++`) para avanzar al siguiente elemento. 
También se sobrecargan los operadores de igualdad (`==`) y desigualdad (`!=`) para comparar iteradores. 
Los miembros incluyen un puntero al nodo actual (`current`) y un método privado para recuperar el dato actual.

#### Iterator
```cpp
class iterator : public const_iterator {
public:
    iterator();
    Object& operator*();
    const Object& operator*() const;
    iterator & operator++ ();
    iterator &operator--();
    iterator operator++ (int);
    iterator operator-- (int);
    iterator operator+ (int steps) const;

protected:
    iterator(Node *p);

    friend class DLList<Object>;
};
```
La clase de iterador `iterator` hereda de `const_iterator` y permite tanto el acceso como la modificación de los elementos de la lista.
Proporciona los mismos operadores que `const_iterator`, pero con la capacidad adicional de modificar los datos. También se proporciona un operador de suma (`+`) para avanzar varios pasos en la lista. 
El constructor toma un puntero al nodo actual (`Node *p`).
<br>

### Métodos
#### Constructores y Destructor
```cpp
public:
DLList();
DLList(std::initializer_list<Object> initList);
~DLList();
DLList(const DLList &rhs);
DLList &operator=(const DLList &rhs);
DLList(DLList &&rhs);
DLList &operator=(DLList &&rhs);
```
Estos métodos son los constructores, el destructor y los operadores de asignación de la clase `DLList`. 
Permiten crear una lista vacía, una lista inicializada con una lista de inicialización, copiar una lista, asignar una lista a otra y mover una lista.

#### Métodos de Acceso y Modificación
```cpp
iterator begin();
const_iterator begin() const;
iterator end();
const_iterator end() const;
```
Estos métodos devuelven iteradores al primer y último elemento de la lista.
Los métodos `begin()` devuelven un iterador no constante, mientras que los métodos `begin() const` devuelven un iterador constante.

```cpp
int size() const;
bool empty() const;
```
`size()` devuelve el tamaño de la lista y `empty()` verifica si la lista está vacía.

```cpp
void clear();
```
Elimina todos los elementos de la lista.

```cpp
Object &front();
const Object &front() const;
Object &back();
const Object &back() const;
```
Te permiten acceder al primer y último elemento de la lista. Los métodos `front()` devuelven una referencia al primer elemento, mientras que los métodos `back()` devuelven una referencia al último elemento. 
Los métodos constantes no permiten modificar los elementos.

```cpp
void push_front(const Object &x);
void push_front(Object &&x);
void push_back(const Object &x);
void push_back(Object &&x);
```
Insertan elementos al frente y al final de la lista.
Los métodos `push_front()` toman un dato por referencia constante o en movimiento, mientras que los métodos `push_back()` realizan lo mismo pero insertan al final de la lista.

```cpp
void pop_front();
void pop_back();
```
Eliminan el primer y el último elemento de la lista, respectivamente.

```cpp
iterator insert(iterator itr, const Object &x);
iterator insert(iterator itr, Object &&x);
```
Insertan un elemento antes de la posición especificada por el iterador `itr`.

```cpp
void insert(int pos, const Object &x);
void insert(int pos, Object &x);
```
Insertan un elemento en una posición dada por el índice `pos`, con un dato constante o en movimiento.

```cpp
iterator erase(iterator itr);
void erase(int pos);
iterator erase(iterator from, iterator to);
```
Eliminan un elemento en una posición especificada por un iterador, por un índice o por un rango de iteradores.

```cpp
void print() const;
```
Imprime todos los elementos de la lista.

#### Métodos Privados

```cpp
private:
    int theSize;
    Node *head;
    Node *tail;

    void init();
    iterator get_iterator(int pos);
};
```
`init()` inicializa la lista estableciendo el tamaño en 0 y configurando los punteros de cabeza y cola.
El iterator `get_iterator(int pos):` Es una función miembro privada que devuelve un iterador apuntando al nodo en la posición pos de la lista.
Este método se utiliza internamente para obtener un iterador a una posición específica en la lista.

### FIN
```cpp
#include "DLList.cpp"
```
Incluye la implementación `DLList.cpp`, que contiene las definiciones de los métodos de la clase `DLList`.
<br>
---
--- 
## SLList.cpp - Implementacion
### Inicio
```cpp
#include "DLList.h"
```
El archivo anterior "DLList.h" incluye la declaración de la clase DLList y los otros componentes necesarios para su funcionamiento. 
<br>

### Constructores iniciales
```cpp
template<typename Object>
DLList<Object>::Node::Node(const Object &d, Node *p, Node *n)
        : data{d}, prev{p}, next{n} {}

template<typename Object>
DLList<Object>::Node::Node(Object &&d, Node *p, Node *n)
        : data{std::move(d)}, prev{p}, next{n} {}
```
Estos son los constructores de la clase anidada Node de la lista doblemente enlazada `(DLList).`
La clase Node representa un nodo que contiene un dato `(data)`, un puntero al nodo anterior `(prev)` y un puntero al siguiente nodo `(next).` 
Los constructores inicializan estos miembros con los valores proporcionados.

```cpp
template<typename Object>
DLList<Object>::const_iterator::const_iterator() : current{nullptr} {}
```
Este es el constructor de la clase const_iterator, que representa un iterador constante para la lista. 
Inicializa el puntero al nodo actual _(current)_ como nulo.
<br>

### Metodos Sobrecargados y de crecimiento
```cpp
template<typename Object>
const Object &DLList<Object>::const_iterator::operator*() const {
    return retrieve();
}
```
Este método sobrecarga el operador de desreferenciación _(*)_ para devolver el dato almacenado en el nodo actual al que apunta el iterador.

```cpp
template<typename Object>
typename DLList<Object>::const_iterator &DLList<Object>::const_iterator::operator++() {
    current = current->next;
    return *this;
}
```
Sobrecarga el operador de incremento _(++)_ para avanzar al siguiente nodo en la lista y devuelve una referencia al iterador actualizado.

```cpp
template<typename Object>
typename DLList<Object>::const_iterator DLList<Object>::const_iterator::operator++(int) {
    const_iterator old = *this;
    ++(*this);
    return old;
}
```
Sobrecarga el operador de incremento _(++)_ en su forma de postfijo para avanzar al siguiente nodo en la lista y devuelve una copia del iterador antes de la modificación.

```cpp
template<typename Object>
bool DLList<Object>::const_iterator::operator==(const const_iterator &rhs) const {
    return current == rhs.current;
}
```
Este método sobrecarga el operador de igualdad _(==)_ para comparar dos iteradores y determinar si apuntan al mismo nodo en la lista.

```cpp
template<typename Object>
bool DLList<Object>::const_iterator::operator!=(const const_iterator &rhs) const {
    return !(*this == rhs);
}
```
Este método sobrecarga el operador de desigualdad _(!=)_ para comparar dos iteradores y determinar si no apuntan al mismo nodo en la lista.

```cpp
template<typename Object>
Object &DLList<Object>::const_iterator::retrieve() const {
    return current->data;
}
```
Este método privado devuelve una referencia al dato almacenado en el nodo actual al que apunta el iterador.
<br>

### Constructores adicionales - 1
#### Clase iterador - adicional
```cpp
template<typename Object>
DLList<Object>::const_iterator::const_iterator(Node *p) : current{p} {}
```
Constructor adicional de la clase `const_iterator` que inicializa el puntero al nodo actual con el nodo proporcionado.

#### Clase iterador - Predeterminado
```cpp
template<typename Object>
DLList<Object>::iterator::iterator() {}
```
Este es el constructor predeterminado de la clase iterator, que representa un iterador para la lista.
No realiza ninguna acción específica en la inicialización.
<br>

### Metodos Sobrecargados y de desreferenciación
```cpp
template<typename Object>
Object &DLList<Object>::iterator::operator*() {
    return const_iterator::retrieve();
}
```
El método sobrecarga el operador de desreferenciación _(*)_ para devolver una referencia al dato almacenado en el nodo actual al que apunta el iterador.

```cpp
template<typename Object>
const Object &DLList<Object>::iterator::operator*() const {
    return const_iterator::operator*();
}
```
Este método sobrecarga el operador de desreferenciación _(*)_ constante para devolver una referencia constante al dato almacenado en el nodo actual al que apunta el iterador.

```cpp
template<typename Object>
typename DLList<Object>::iterator &DLList<Object>::iterator::operator++() {
    this->current = this->current->next;
    return *this;
}
```
Método sobrecarga el operador de incremento _(++)_ para avanzar al siguiente nodo en la lista y devuelve una referencia al iterador actualizado.

```cpp
template<typename Object>
typename DLList<Object>::iterator &DLList<Object>::iterator::operator--() {
    this->current = this->current->prev;
    return *this;
}
```
Este método sobrecarga el operador de decremento _(--)_ para retroceder al nodo anterior en la lista y devuelve una referencia al iterador actualizado.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::iterator::operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
}
```
Sobrecarga el operador de incremento _(++)_ en su forma de postfijo para avanzar al siguiente nodo en la lista y devuelve una copia del iterador antes de la modificación.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::iterator::operator--(int) {
    iterator old = *this;
    --(*this);
    return old;
}
```
Este método sobrecarga el operador de decremento _(--)_ en su forma de postfijo para retroceder al nodo anterior en la lista y devuelve una copia del iterador antes de la modificación.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::iterator::operator+(int steps) const {
    iterator new_itr = *this;
    for(int i = 0; i < steps; ++i) {
        ++new_itr;
    }
    return new_itr;
}
```
Este método sobrecarga el operador de suma _(+)_ para avanzar varios pasos en la lista y devuelve un nuevo iterador que apunta al nodo avanzado.
<br>

### Constructores adicionales - 2

```cpp
template<typename Object>
DLList<Object>::iterator::iterator(Node *p) : const_iterator{p} {}
```
Este es un constructor adicional de la clase iterator que inicializa el iterador con el nodo proporcionado.

```cpp
template<typename Object>
DLList<Object>::DLList() : theSize{0}, head{new Node}, tail{new Node} {
    head->next = tail;
    tail->prev = head;
}
```
Este es el constructor predeterminado de la `clase DLList`, que inicializa una lista doblemente enlazada vacía. 
Establece el tamaño en 0 y crea nodos dummy para la cabeza y la cola de la lista, configurando sus punteros adecuadamente.

```cpp
template<typename Object>
DLList<Object>::DLList(std::initializer_list<Object> initList) : DLList() {
    for(const auto &item : initList) {
        push_back(item);
    }
}
```
Este es un constructor adicional de la clase DLList que inicializa la lista con los elementos proporcionados en una lista de inicialización. 
Utiliza el constructor predeterminado para crear una lista vacía y luego inserta cada elemento de la lista de inicialización al final de la lista.
<br>
#### Destructor
```cpp
template<typename Object>
DLList<Object>::~DLList() {
    clear();
    delete head;
    delete tail;
}
```
Este es el destructor de la `clase DLList`, que libera la memoria asignada para todos los nodos de la lista, así como para los nodos dummy de la cabeza y la cola.
<br>
#### Constructor copia
```cpp
template<typename Object>
DLList<Object>::DLList(const DLList &rhs) : DLList() {
    for(auto &item : rhs) {
        push_back(item);
    }
}
```
Este es el constructor de copia de la `clase DLList`, que crea una nueva lista duplicando todos los elementos de otra lista proporcionada.
<br>
### Operadores
```cpp
template<typename Object>
DLList<Object> &DLList<Object>::operator=(const DLList &rhs) {
    DLList copy = rhs;
    std::swap(*this, copy);
    return *this;
}
```
Operador de asignación de copia de la `clase DLList`, que realiza una asignación segura de copia intercambiando los contenidos de la lista actual con una copia de la lista proporcionada.

```cpp
template<typename Object>
DLList<Object>::DLList(DLList &&rhs) : theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail} {
    rhs.theSize = 0;
    rhs.head = nullptr;
    rhs.tail = nullptr;
}
```
Constructor de movimiento de la `clase DLList`, que mueve los recursos de otra lista proporcionada a la lista actual, dejando la lista original en un estado válido pero no especificado.

```cpp
template<typename Object>
DLList<Object> &DLList<Object>::operator=(DLList &&rhs) {
    std::swap(theSize, rhs.theSize);
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    return *this;
}
```
Este es el operador de asignación de movimiento de la `clase DLList`, que realiza una asignación segura de movimiento intercambiando los contenidos de la lista actual con otra lista proporcionada.


### Metodos Finales 
```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::begin() {
    return {head->next};
}
```
Devuelve un iterador que apunta al primer elemento de la lista.

```cpp
template<typename Object>
typename DLList<Object>::const_iterator DLList<Object>::begin() const {
    return {head->next};
}
```
Te da un iterador constante que apunta al primer elemento de la lista.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::end() {
    return {tail};
}
```
Devuelve un iterador que apunta al final de la lista.

```cpp
template<typename Object>
typename DLList<Object>::const_iterator DLList<Object>::end() const {
    return {tail};
}
```
Devuelve un iterador constante que apunta al final de la lista.

```cpp
template<typename Object>
int DLList<Object>::size() const {
    return theSize;
}
```
Devuelve el tamaño actual de la lista.

```cpp
template<typename Object>
bool DLList<Object>::empty() const {
    return size() == 0;
}
```
Verifica si la lista está vacía o no.

```cpp
template<typename Object>
void DLList<Object>::clear() {
    while(!empty()) {
        pop_front();
    }
}
```
Elimina todos los elementos de la lista hasta que esté vacía.

```cpp
template<typename Object>
Object &DLList<Object>::front() {
    return *begin();
}
```
Te da una referencia al primer elemento de la lista.

```cpp
template<typename Object>
const Object &DLList<Object>::front() const {
    return *begin();
}
```
Devuelve una referencia constante al primer elemento de la lista.

```cpp
template<typename Object>
Object &DLList<Object>::back() {
    return *(--end());
}
```
Devuelve una referencia al último elemento de la lista.

```cpp
template<typename Object>
const Object &DLList<Object>::back() const {
    return *(--end());
}
```
Devuelve una referencia constante al último elemento de la lista.

```cpp
template<typename Object>
void DLList<Object>::push_front(const Object &x) {
    insert(begin(), x);
}
```
Inserta un nuevo elemento al principio de la lista con el dato proporcionado.

```cpp
template<typename Object>
void DLList<Object>::push_front(Object &&x) {
    insert(begin(), std::move(x));
}
```
Inserta un nuevo elemento al principio de la lista con el dato proporcionado en movimiento.

```cpp
template<typename Object>
void DLList<Object>::push_back(const Object &x) {
    insert(end(), x);
}
```
Inserta un nuevo elemento al final de la lista con el dato proporcionado.

```cpp
template<typename Object>
void DLList<Object>::push_back(Object &&x) {
    insert(end(), std::move(x));
}
```
Inserta un nuevo elemento al final de la lista con el dato proporcionado en movimiento.

```cpp
template<typename Object>
void DLList<Object>::pop_front() {
    erase(begin());
}
```
Elimina el primer elemento de la lista.

```cpp
template<typename Object>
void DLList<Object>::pop_back() {
    erase(--end());
}
```
Elimina el último elemento de la lista.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::insert(iterator itr, const Object &x) {
    Node *p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node{x, p->prev, p}};
}
```
Inserta un nuevo elemento antes de la posición indicada por el iterador proporcionado y devuelve un iterador al nuevo elemento insertado.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::insert(iterator itr, Object &&x) {
    Node *p = itr.current;
    theSize++;
    return {p->prev = p->prev->next = new Node{std::move(x), p->prev, p}};
}
```
Inserta un nuevo elemento antes de la posición indicada por el iterador proporcionado, tomando el dato en movimiento, y devuelve un iterador al nuevo elemento insertado.

```cpp
template<typename Object>
void DLList<Object>::insert(int pos, const Object &x) {
    insert(get_iterator(pos), x);
}
```
Inserta un nuevo elemento en la posición indicada por el índice proporcionado con el dato proporcionado.

```cpp
template<typename Object>
void DLList<Object>::insert(int pos, Object &&x) {
    insert(get_iterator(pos), std::move(x));
}
```
Inserta un nuevo elemento en la posición indicada por el índice proporcionado, tomando el dato en movimiento.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::erase(iterator itr) {
    Node *p = itr.current;
    iterator retVal(p->next);
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
    theSize--;
    return retVal;
}
```
Elimina el elemento apuntado por el iterador proporcionado y devuelve un iterador al siguiente elemento en la lista.

```cpp
template<typename Object>
void DLList<Object>::erase(int pos) {
    erase(get_iterator(pos));
}
```
Elimina el elemento en la posición indicada por el índice proporcionado.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::erase(iterator from, iterator to) {
    for(iterator itr = from; itr != to;) {
        itr = erase(itr);
    }
    return to;
}
```
Elimina todos los elementos en el rango de iteradores proporcionado y devuelve un iterador al final del rango.

```cpp
template<typename Object>
void DLList<Object>::print() const {
    for(const auto &item : *this) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
```
Imprime todos los elementos de la lista, separados por espacios, seguido de un salto de línea.

```cpp
template<typename Object>
void DLList<Object>::init() {
    theSize = 0;
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
}
```
Inicializa la lista, estableciendo el tamaño en 0 y configurando correctamente los nodos dummy de la cabeza y la cola.

```cpp
template<typename Object>
typename DLList<Object>::iterator DLList<Object>::get_iterator(int pos) {
    iterator itr = begin();
    for(int i = 0; i < pos; ++i) {
        ++itr;
    }
    return itr;
}
```
Este método devuelve un iterador que apunta al elemento en la posición indicada por el índice proporcionado.
<br>
---
IEEE
> “DLList.cpp,” Google Docs. https://drive.google.com/file/d/1RoAWS-uIrQ8Fmm84s-VNNXn-fR58k4E2/view <br>
> “DLList.h,” Google Docs. https://drive.google.com/file/d/1HP46r2e5bI3I6tLkdQ-JqX4w9r2X52mN/view