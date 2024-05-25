# Tarea Documentación del Código - SLList

#### Jonathan Nava Noguez   IPV1412

#### Estructura de datos    ID: 6576

**Instrucciones:** Explicar el funcionamiento del siguiente código.

---

## SLList.h - Interfaz

### Inicio
    #ifndef SLLLIST_H
    #define SLLLIST_H
Aquí, se están asegurando de que el contenido del archivo SLList.h solo se incluya una vez en un programa.

    #include <iostream>
    #include <utility>
Se incluyen las librerías estándar iostream y utility necesarias para utilizar las funcionalidades de entrada y salida de C++.
<br>

### Estructura del Nodo
    // Definición de la clase SLList
    template<typename Object>
    class SLList {
    public:
Se define una plantilla de clase SLList que contiene una estructura interna _Node._

    // Estructura interna de un nodo de la lista
    struct Node {
    Object data;  // Datos almacenados en el nodo
    Node *next;   // Puntero al siguiente nodo
        // Constructores del Node
        Node(const Object &d = Object{}, Node *n = nullptr);  // Constructor con parámetros por defecto
        Node(Object &&d, Node *n = nullptr);                  // Constructor de movimiento
    };
Cada nodo contiene un dato de tipo _Object_ y un puntero al siguiente nodo en la lista.
<br>

### Clase Iterador
    // Iterador para recorrer la lista
    class iterator {
    public:
    iterator();          // Constructor por defecto
    Object &operator*(); // Sobrecarga del operador de desreferenciación
    iterator &operator++();     // Sobrecarga del operador de preincremento
    const iterator operator++(int);  // Sobrecarga del operador de postincremento
    bool operator==(const iterator &rhs) const; // Sobrecarga del operador de igualdad
    bool operator!=(const iterator &rhs) const; // Sobrecarga del operador de desigualdad

    private:
        Node *current;  // Puntero al nodo actual

        // Constructor privado utilizado por la clase SLList
        iterator(Node *p);

        friend class SLList<Object>;  // Declaración de amistad con la clase SLList
    };
Se define una clase interna iterator para permitir la iteración sobre la lista enlazada. 
Esta clase tiene los operadores de incremento, comparación y acceso a datos necesarios para recorrer la lista.
<br>

### Métodos y Variables Públicas
     public:
    // Constructor por defecto de SLList
    SLList();
    // Constructor que recibe una lista inicializadora
    SLList(std::initializer_list<Object> init_list);
    // Destructor de SLList
    ~SLList();
    // Método que devuelve un iterador al primer elemento de la lista
    iterator begin();
    // Método que devuelve un iterador al último elemento de la lista
    iterator end();
    // Método que devuelve el tamaño de la lista
    int size() const;
    // Método que verifica si la lista está vacía
    bool empty() const;
    // Método que elimina todos los elementos de la lista
    void clear();
    // Método que devuelve una referencia al primer elemento de la lista
    Object &front();
    // Método que agrega un nuevo elemento al principio de la lista (por copia)
    void push_front(const Object &x);
    // Método que agrega un nuevo elemento al principio de la lista (por movimiento)
    void push_front(Object &&x);
    // Método que elimina el primer elemento de la lista
    void pop_front();
    // Método que inserta un nuevo elemento antes de la posición especificada por el iterador
    iterator insert(iterator itr, const Object &x);
    // Método que inserta un nuevo elemento antes de la posición especificada por el iterador (por movimiento)
    iterator insert(iterator itr, Object &&x);
    // Método que elimina el elemento apuntado por el iterador
    iterator erase(iterator itr);
    // Método que imprime todos los elementos de la lista
    void print();
Se declaran los métodos públicos de la clase SLList, incluyendo constructores, destructores, operaciones de acceso y modificación, así como métodos para el manejo de la lista como _size, empty, clear, push_front, pop_front, insert, erase y print._
<br>

### Variables Privadas
    private:
    Node *head;  // Puntero al nodo cabeza de la lista
    Node *tail;  // Puntero al nodo cola de la lista
    int theSize; // Tamaño de la lista
    // Método privado utilizado para inicializar la lista
    void init();
};

Se definen variables privadas para representar el inicio y fin de la lista _(head y tail)_, así como el tamaño de la lista _(theSize)_.
También se define un método privado init para inicializar la lista.
<br>

### Fin
    #include "SLList.cpp"  // Inclusión del archivo de implementación SLList.cpp
    #endif  // SLLLIST_H
Se cierra el archivo de encabezado y se incluye la implementación de la clase desde el archivo SLList.cpp.

---

## SLList.cpp - Implementación

### Inicio
    #include "SLList.h"
Incluye la libreria creada _SLList.h_ explicada anteriormente
<br>

### Constructores
    // Implementación del constructor Node con parámetros por defecto
    template<typename Object>
    SLList<Object>::Node::Node(const Object &d, Node *n)
    : data{d}, next{n} {}
Este código implementa el constructor de la clase `Node` dentro de `SLList`, tomando un dato y un puntero al siguiente nodo como parámetros.
Se utiliza para inicializar los miembros de datos `data` y `next` con los valores proporcionados.

    // Implementación del constructor Node de movimiento
    template<typename Object>
    SLList<Object>::Node::Node(Object &&d, Node *n)
    : data{std::move(d)}, next{n} {}
    // Implementación del constructor por defecto del iterador
    template<typename Object>
    SLList<Object>::iterator::iterator() : current{nullptr} {}
Este fragmento implementa el constructor de movimiento para la clase `Node` dentro de `SLList`, que toma un dato como r-valor y un puntero al siguiente nodo como parámetros.
También implementa el constructor por defecto para el iterador, que inicializa el puntero `current` como `nullptr`.
<br>

### Operadores 
    // Implementación del operador de la desreferenciación del iterador
    template<typename Object>
    Object &SLList<Object>::iterator::operator*() {
    if(current == nullptr)
    throw std::logic_error("Trying to dereference a null pointer.");
    return current->data;
    }
Aqui se implementa un operador que obtienen el valor directo del puntero es decir una (desreferenciacion);el (`*`) del iterador en la clase `SLList`.
Retorna una referencia al dato almacenado en el nodo apuntado por el iterador.
Si el puntero `current` es `nullptr`, se lanza una excepción de lógica indicando que se está intentando desreferenciar un puntero nulo.
   
    // Implementación del operador de preincremento del iterador
    template<typename Object>
    typename SLList<Object>::iterator &SLList<Object>::iterator::operator++() {
    if(current)
    current = current->next;
    else
    throw std::logic_error("Trying to increment past the end.");
    return *this;
    }
El operador utiliza el incremento _(++)_ para avanzar el iterador al siguiente nodo en la lista enlazada.
Comienza verificando si el nodo actual al que apunta el iterador no es nulo. 
Si es así, avanza al siguiente nodo modificando el puntero current para que apunte al siguiente nodo en la lista. 
Si el nodo actual es nulo, lo que significa que el iterador ya está al final de la lista, se lanza una excepción de lógica indicando que se está intentando avanzar más allá del final de la lista.
Finalmente, el operador devuelve una referencia al iterador actualizado, lo que permite la encadenación de operadores.

    // Implementación del operador de postincremento del iterador
    template<typename Object>
    typename SLList<Object>::iterator SLList<Object>::iterator::operator++(int) {
    iterator old = *this;
    ++(*this);
    return old;
    }
Similar al anterior este operador del iterador crea una copia del iterador actual, luego incrementa el iterador utilizando el operador de preincremento (++), y finalmente devuelve la copia del iterador antes del incremento.

    // Implementación del operador de igualdad del iterador
    template<typename Object>
    bool SLList<Object>::iterator::operator==(const iterator &rhs) const {
    return current == rhs.current;
    }
Aqui se compara si el nodo actual al que apunta el iterador es igual al nodo apuntado por otro iterador (rhs). 
Devuelve verdadero si ambos apuntan al mismo nodo y falso en caso contrario.

    // Implementación del operador de desigualdad del iterador
    template<typename Object>
    bool SLList<Object>::iterator::operator!=(const iterator &rhs) const {
    return !(*this == rhs);
    }
En caso de que sea una desigualdad este parte se encarga pues utiliza la negación del operador de igualdad para determinar si dos iteradores no apuntan al mismo nodo. 
Devuelve verdadero si los iteradores no apuntan al mismo nodo y falso si apuntan al mismo nodo.
<br>

### Constructores dependientes
    // Implementación del constructor del iterador con un nodo dado
    template<typename Object>
    SLList<Object>::iterator::iterator(Node *p) : current{p} {}
El constructor toma un puntero a un nodo como parámetro y lo asigna al miembro de datos `current` del iterador.
Se utiliza para inicializar un iterador con un nodo específico dentro de la lista enlazada.

    // Implementación del constructor por defecto de SLList
    template<typename Object>
    SLList<Object>::SLList() : head(new Node()), tail(new Node()), theSize(0) {
    head->next = tail;
    }
Este constructor por defecto de la clase `SLList` inicializa una lista enlazada simple. 
Crea un nodo cabeza (`head`) y un nodo cola (`tail`), ambos inicializados como nuevos nodos vacíos. La variable `theSize` se establece en 0 para indicar que la lista está vacía. 
Además, se enlaza el nodo cabeza con el nodo cola para formar una lista vacía.

    // Implementación del constructor de SLList con lista inicializadora
    template<typename Object>
    SLList<Object>::SLList(std::initializer_list<Object> init_list) {
    head = new Node();
    tail = new Node();
    head->next = tail;
    theSize = 0;
    for(const auto& x : init_list) {
    push_front(x);
    }
    }
La clase `SLList` permite inicializar la lista enlazada con elementos proporcionados en una lista inicializadora. 
Comienza creando un nodo cabeza (`head`) y un nodo cola (`tail`), ambos inicializados como nuevos nodos vacíos. 
Se establece `head->next` como el nodo cola para indicar que la lista está vacía.
Luego, itera a través de la lista inicializadora `init_list` y utiliza la función `push_front()` para agregar cada elemento al frente de la lista enlazada, lo que construye la lista en el orden dado por la lista inicializadora.
<br>

### Destructor
    // Implementación del destructor de SLList
    template<typename Object>
    SLList<Object>::~SLList() {
    clear();
    delete head;
    delete tail;
    }
El destructor de MUNDOS XD; se encarga de liberar la memoria asignada dinámicamente por la lista enlazada.
Comienza invocando la función `clear()` (como en minecraft) para eliminar todos los elementos de la lista y liberar la memoria asociada a cada nodo. 
Luego, elimina los nodos cabeza (`head`) y cola (`tail`) utilizando el operador `delete`, lo que libera la memoria asignada a estos nodos.
<br>

### Metodos

    // Implementación del método begin() que devuelve un iterador al primer elemento de la lista
    template<typename Object>
    typename SLList<Object>::iterator SLList<Object>::begin() { return {head->next}; }
Este método devuelve un iterador que apunta al primer elemento de la lista. 
Primero, crea un iterador que apunta al siguiente nodo después de la cabeza de la lista y lo devuelve.

    // Implementación del método end() que devuelve un iterador al último elemento de la lista
    template<typename Object>
    typename SLList<Object>::iterator SLList<Object>::end() { return {tail}; }
Similar al método begin(), este método devuelve un iterador que apunta al último elemento de la lista, que es el nodo de la cola.

    // Implementación del método size() que devuelve el tamaño de la lista
    template<typename Object>
    int SLList<Object>::size() const { return theSize; }
Este método devuelve el tamaño actual de la lista, que está representado por la variable _theSize._

    // Implementación del método empty() que verifica si la lista está vacía
    template<typename Object>
    bool SLList<Object>::empty() const { return size() == 0; }
Verifica si la lista está vacía comparando el tamaño actual con 0. Si el tamaño es 0, devuelve verdadero; de lo contrario, devuelve falso.

    // Implementación del método clear() que elimina todos los elementos de la lista
    template<typename Object>
    void SLList<Object>::clear() { while (!empty()) pop_front(); }
El método clear() elimina todos los elementos de la lista invocando repetidamente el método pop_front() hasta que la lista esté vacía.

    // Implementación del método front() que devuelve una referencia al primer elemento de la lista
    template<typename Object>
     Object &SLList<Object>::front() {
    if(empty())
    throw std::logic_error("List is empty.");
    return *begin();
    }
Devuelve una referencia al primer elemento de la lista.
Si la lista está vacía, se lanza una excepción lógica

    // Implementación del método push_front() que agrega un nuevo elemento al principio de la lista (por copia)
    template<typename Object>
    void SLList<Object>::push_front(const Object &x) { insert(begin(), x); }
Implementa un nuevo elemento al principio de la lista mediante la inserción de x utilizando el método insert().

    // Implementación del método push_front() que agrega un nuevo elemento al principio de la lista (por movimiento)
    template<typename Object>
    void SLList<Object>::push_front(Object &&x) { insert(begin(), std::move(x)); }
Similar al método anterior, pero acepta un objeto por movimiento, lo que puede ser más eficiente en términos de rendimiento.

    // Implementación del método pop_front() que elimina el primer elemento de la lista
    template<typename Object>
    void SLList<Object>::pop_front() {
    if(empty())
    throw std::logic_error("List is empty.");
    erase(begin());
    }
Elimina el primer elemento de la lista invocando el _método erase()_ en el primer iterador.

    // Implementación del método insert() que inserta un nuevo elemento antes de la posición especificada por el iterador
    template<typename Object>
    typename SLList<Object>::iterator SLList<Object>::insert(iterator itr, const Object &x) {
    Node *p = itr.current;
    Node *newNode = new Node{x, p->next};
    p->next = newNode;
    theSize++;
    return iterator(newNode);
    }
Inserta un nuevo elemento antes de la posición especificada por el iterador itr. Primero, crea un nuevo nodo con el valor x y lo inserta en la lista antes del nodo actual.

    // Implementación del método insert() que inserta un nuevo elemento antes de la posición especificada por el iterador (por movimiento)
    template<typename Object>
    typename SLList<Object>::iterator SLList<Object>::insert(iterator itr, Object &&x) {
    Node *p = itr.current;
    Node *newNode = new Node{std::move(x), p->next};
    p->next = newNode;
    theSize++;
    return iterator(newNode);
    }
Similar al método anterior, pero acepta un objeto por movimiento para una inserción eficiente.

    // Implementación del método erase() que elimina el elemento apuntado por el iterador
    template<typename Object>
    typename SLList<Object>::iterator SLList<Object>::erase(iterator itr) {
    if (itr == end())
    throw std::logic_error("Cannot erase at end iterator");
    Node *p = head;
    while (p->next != itr.current) p = p->next;
    Node *toDelete = itr.current;
    p->next = itr.current->next;
    delete toDelete;
    theSize--;
    return iterator(p->next);
    }
Elimina el elemento apuntado por el iterador itr, ajustando los enlaces de los nodos adyacentes y liberando la memoria ocupada por el nodo eliminado.

    // Implementación del método print() que imprime todos los elementos de la lista
    template<typename Object>
    void SLList<Object>::print() {
    iterator itr = begin();
    while (itr != end()) {
    std::cout << *itr << " ";
    ++itr;
    }
    std::cout << std::endl;
    }
Imprime todos los elementos de la lista utilizando un bucle while que itera sobre los elementos y los imprime uno por uno.

    // Implementación del método init() que inicializa la lista
    template<typename Object>
    void SLList<Object>::init() {
    theSize = 0;
    head->next = tail;
    }
Inicializa la lista estableciendo theSize en 0 y configurando los enlaces de la cabeza y la cola de la lista.
<br>

---

IEEE
> “SLList.cpp,” Google Docs (Leonardo Juárez Zucco). https://drive.google.com/file/d/1ezPcLIkOBoua1Igle5IhJQFq6xLCwB3i/view
> “SLList.H,” Google Docs (Leonardo Juárez Zucco). https://drive.google.com/file/d/1FaiUZKgObkduoLavrzgeXi2fIvyBeJSw/view