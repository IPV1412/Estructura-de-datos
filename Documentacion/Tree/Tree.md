# Documentación De un Arbol - Tree

#### Jonathan Nava Noguez   IPV1412

#### Estructura de datos    ID: 6576

**Instrucciones:** Entregar una documentación del siguiente código..

---

## Tree.h - Interfaz
Este archivo proporciona la interfaz para las clases `Node` y `Tree`.
### Inicio
```cpp
#ifndef TREE_H
#define TREE_H

#include <iostream>
```
Este archivo de encabezado comienza con las inclusiones necesarias para el funcionamiento del código, como <iostream>.
Se empieza con las directivas del preprocesador #ifndef, #define, y #endif, que se utilizan para evitar la inclusión múltiple de archivos de encabezado.
<br>
### Clase Node
```cpp
template <typename T>
class Node {
public:
T data; //Datos almacenados en el nodo
Node* firstChild; //Puntero al primer nodo
Node* nextSibling; //Puntero al siguiente nodo

    explicit Node(T data);
};
```
La clase `Node` representa un nodo en una estructura de árbol.
Cada nodo tiene un campo para almacenar datos de tipo genérico T, así como punteros al primer hijo `(firstChild)` y al siguiente hermano `(nextSibling)`.
<br>
### Clase Tree
```cpp
template <typename T>
class Tree {
public:
Node<T>* root; //Puntero a la raiz del arbol

    Tree();

    Node<T>* addNode(T data, Node<T>* parent = nullptr);

    void printTree(Node<T>* node, int level = 0);
};
```
La clase `Tree` representa un árbol, con un puntero a su raíz.
Donde cada nodo tiene un puntero a la raíz del árbol `(root)`. 
La clase Tree también incluye métodos para agregar nodos `(addNode)` y para imprimir el árbol`(printTree)`.
<br>
### Fin
```cpp
#include "Tree.cpp"

#endif //TREE_H
```
Esta sección finaliza el archivo de encabezado e incluye el archivo de implementación Tree.cpp y se cierra la directiva de preprocesador #ifndef.
<br>
## Tree.cpp - Implementacion
### Inicio
```cpp
#include "Tree.h"
```
Este archivo comienza incluyendo el archivo de encabezado correspondiente Tree.h, que define las clases y funciones necesarias.
<br>

### Constructores
#### Node
```cpp
template <typename T>
Node<T>::Node(T data) : data(data), firstChild(nullptr), nextSibling(nullptr) {}
```
Implementa un constructor para la clase Node. 
Inicializa los campos de datos, `firstChild` y `nextSibling` a `nullptr`.
<br>
#### Tree
```cpp
template <typename T>
Tree<T>::Tree() : root(nullptr) {}
```
Este es el constructor de la clase Tree. 
Inicializa el puntero `root` a `nullptr`, lo que indica que el árbol está vacío al principio.
<br>
### Metodos
#### AddNode
```cpp
template <typename T>
Node<T>* Tree<T>::addNode(T data, Node<T>* parent) {
Node<T>* newNode = new Node<T>(data);    // Crear un nuevo nodo con los datos proporcionados

    if(parent) { // Verificar si se proporcionó un nodo padre
        if(parent->firstChild) { // Si el nodo padre ya tiene hijos
            Node<T>* sibling = parent->firstChild; // Encontrar el último hijo del nodo padre
            while(sibling->nextSibling) {
                sibling = sibling->nextSibling; 
            }
            sibling->nextSibling = newNode; // Agregar el nuevo nodo como hermano del último hijo
        } else {
            parent->firstChild = newNode; // Si el nodo padre no tiene hijos, el nuevo nodo se convierte en el primer hijo
        }
    } else {
        root = newNode; // Si no se proporcionó un nodo padre, el nuevo nodo se convierte en la raíz del árbol
    }

    return newNode; // Devolver el puntero al nuevo nodo
}
```
Este método añade un nuevo nodo al árbol.
Si se proporciona un nodo padre, el nuevo nodo se convierte en un hijo de ese nodo. 
Si no se proporciona un nodo padre, el nuevo nodo se convierte en la raíz del árbol.
<br>
#### PrintTree
```cpp
template <typename T>
void Tree<T>::printTree(Node<T>* node, int level) {
if(!node) return; // Verificar si el nodo es nulo

    for(int i = 0; i < level; i++) std::cout << "--"; // Imprimir guiones para representar la profundidad del nodo en el árbol
    std::cout << node->data << '\n'; // Imprimir los datos almacenados en el nodo actual

    printTree(node->firstChild, level + 1);  // Llama de manera recursiva al método para imprimir los hijos del nodo actual
    printTree(node->nextSibling, level); // Llama de manera recursiva  al método para imprimir los hermanos del nodo actual
}
```
Imprime el árbol en la consola, comenzando desde el nodo dado. 
Utiliza un enfoque de recorrido de profundidad primero (DFS) para imprimir los nodos en el orden correcto.
<br>

---
IEEE
> “Tree.h,” Google Docs. https://drive.google.com/file/d/1ng3igJSb3NwpcVC3idhf3JmuAz6bTAtn/view

> “Tree.cpp,” Google Docs. https://drive.google.com/file/d/1vNWNAPyyFLrRKy40BLtHTjgghBr44fGz/view