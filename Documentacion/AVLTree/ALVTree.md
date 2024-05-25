# Struct Wars: El Retorno del Árbol  - AVLTree

#### Jonathan Nava Noguez   IPV1412

#### Estructura de datos    ID: 6576

**Instrucciones:** A partir del siguiente repositorio de GitHub: https://github.com/BiomedicLJZ/Arboles.git. Clonar el repositorio y documentar el código del archivo AVLTree.h.

---
## AVLTree.h - Interfaz
### Inicio
```cpp
#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
```
Se incluye la biblioteca `iostream` para utilizar las utilidades y las funciones de entrada/salida estándar.
Este archivo contiene la declaración de la clase AVLTree, que implementa un árbol AVL _(Adelson-Velsky y Landis)_. 
Un árbol AVL es un tipo de árbol binario de búsqueda balanceado en el que la diferencia de alturas entre los subárboles izquierdo y derecho de cualquier nodo es como máximo uno.
<br>

### Nodo
```cpp
struct Node {
int value;
Node* left;
Node* right;
int height;
};
```
La estructura **Node** representa un nodo en el árbol AVL.
Almacena un valor entero, punteros a los hijos izquierdo y derecho, y la altura del nodo en el árbol.
<br>

### Clase ALVTree
```cpp
class AVLTree {
public:
void printTree() {
printTree(root, 0, 10);
}
```
**_printTree():_** Este método imprime el árbol AVL en la consola. 
Toma tres parámetros: el nodo raíz del árbol, el espacio y el recuento. 
Si no se proporcionan valores para el espacio y el recuento, se utilizan valores predeterminados de 0 y 10 respectivamente.
Este método llama a una función privada _printTree()_ que realiza el recorrido recursivo del árbol e imprime los nodos en un formato visualmente comprensible.
<br>

### Metodos privados
```cpp
private:
Node* root;// Puntero a la raíz del árbol

 // Métodos privados para la manipulación del árbol
    int getNodeHeight(Node* N) { //Este método devuelve la altura del nodo N en el árbol.
        if (N == nullptr) // Puntero al nodo cuya altura se desea conocer.
            return 0;
        return N->height; //Retorna la altura del nodo N.
    }

    int maxHeight(int a, int b) { // Este método devuelve la altura máxima entre dos valores enteros a y b.
        return (a > b)? a : b;
    }

    Node* newNode(int value) { //Crea un nuevo nodo con el valor dado.
        Node* node = new Node();
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;
        node->height = 1;
        return(node);
    }

    Node* rightRotate(Node* y) { //Este método realiza una rotación hacia la derecha en el subárbol con raíz en el nodo y.
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;
        x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) { //Rotación hacia la izquierda en el subárbol con raíz en el nodo x.
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = maxHeight(getNodeHeight(x->left), getNodeHeight(x->right)) + 1;
        y->height = maxHeight(getNodeHeight(y->left), getNodeHeight(y->right)) + 1;

        return y;
    }

    int getBalance(Node* N) { //Calcula el factor de equilibrio (balance) del nodo N.
        if (N == nullptr)
            return 0;
        return getNodeHeight(N->left) - getNodeHeight(N->right);
    }

    Node* insertNode(Node* node, int value) { //Este método inserta un nuevo nodo con el valor dado en el árbol con raíz en el nodo node.
        if (node == nullptr)
            return(newNode(value));

        if (value < node->value)
            node->left = insertNode(node->left, value);
        else if (value > node->value)
            node->right = insertNode(node->right, value);
        else
            return node;

        node->height = 1 + maxHeight(getNodeHeight(node->left), getNodeHeight(node->right));

        int balance = getBalance(node);

        if (balance > 1 && value < node->left->value)
            return rightRotate(node);

        if (balance < -1 && value > node->right->value)
            return leftRotate(node);

        if (balance > 1 && value > node->left->value) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && value < node->right->value) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) { //Encuentra el nodo con el valor mínimo en el árbol con raíz en el nodo node.
        Node* current = node;

        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    Node* deleteNode(Node* root, int value) { //Método que elimina el nodo con el valor dado del árbol con raíz en el nodo root.
        if (root == nullptr)
            return root;

        if ( value < root->value )
            root->left = deleteNode(root->left, value);
        else if( value > root->value )
            root->right = deleteNode(root->right, value);
        else {
            if( (root->left == nullptr) || (root->right == nullptr) ) {
                Node *temp = root->left ? root->left : root->right;

                if(temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;

                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);

                root->value = temp->value;

                root->right = deleteNode(root->right, temp->value);
            }
        }

        if (root == nullptr)
            return root;

        root->height = 1 + maxHeight(getNodeHeight(root->left), getNodeHeight(root->right));

        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);

        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void deleteTree(Node* node) { //Este método elimina todos los nodos del árbol con raíz en el nodo node.
        if (node == nullptr)
            return;

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }
```
Representa el árbol AVL y contiene métodos para rotar, eliminar y recorrer los nodos del árbol.
Los métodos privados de la clase son utilizados internamente para realizar operaciones específicas en el árbol, como rotaciones y ajustes de balance.
<br>

### Metodos publicos
```cpp
public:
AVLTree() : root(nullptr) {} //Constructor de la clase AVLTree que inicializa un nuevo árbol AVL con la raíz establecida como nullptr.

    ~AVLTree() { // Destructor de la clase AVLTree que libera la memoria ocupada por todos los nodos del árbol llamando a la función deleteTree().
        deleteTree(root);
    }

    void insert(int value) { // Inserta un nuevo nodo con el valor especificado en el árbol AVL llamando a la función insertNode().
        root = insertNode(root, value);
    }

    void remove(int value) { //Elimina un nodo con el valor especificado del árbol AVL llamando a la función deleteNode()
        root = deleteNode(root, value);
    }

    void inorderTraversal(Node* node) { //Realiza un recorrido en orden del árbol AVL empezando desde el nodo especificado, imprimiendo los valores de los nodos en orden ascendente.
        if (node == nullptr)
            return;

        inorderTraversal(node->left);
        std::cout << node->value << " ";
        inorderTraversal(node->right);
    }

    void preorderTraversal(Node* node) { // Realiza un recorrido en preorden del árbol AVL empezando desde el nodo especificado, imprimiendo los valores de los nodos en el orden raíz-izquierda-derecha.
        if (node == nullptr)
            return;

        std::cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }

    void postorderTraversal(Node* node) { //Realiza un recorrido en postorden del árbol AVL empezando desde el nodo especificado, imprimiendo los valores de los nodos en el orden izquierda-derecha-raíz.
        if (node == nullptr)
            return;

        postorderTraversal(node->left);
        postorderTraversal(node->right);
        std::cout << node->value << " ";
    }
    void printTree(Node* root, int space = 0, int COUNT = 10) { // Imprime el árbol AVL en la consola en un formato visualmente legible, con la opción de ajustar el espacio y el recuento.
        if (root == nullptr) {
            return;
        }

        space += COUNT;
        printTree(root->right, space);

        std::cout << std::endl;

        for (int i = COUNT; i < space; i++) {
            std::cout << " ";
        }

        std::cout << root->value << "\n";

        printTree(root->left, space);
    }
};
```
Los métodos públicos de la clase AVLTree se encargan del ordenamiento de los nodos y la inserción de estos, así como imprimir el árbol en la consola de manera visual.
Estos métodos proporcionan funcionalidades esenciales para interactuar con el árbol AVL y realizar operaciones de inserción, eliminación y visualización.
<br>

### Fin
```cpp
#endif // AVLTREE_H
```
Esto finaliza la declaración de la interfaz de la clase AVLTree.
<br>

---
IEEE
> “Arboles/AVLTree.h en master · BiomedicLJZ/Arboles.” https://github.com/BiomedicLJZ/Arboles/blob/master/AVLTree.h
> GeeksforGeeks, “AVL Tree Data Structure,” GeeksforGeeks, Nov. 02, 2023. https://www.geeksforgeeks.org/introduction-to-avl-tree/
> “Star Wars: La guerra de los clones | Disney+,” Disney+, Aug. 15, 2008. https://www.disneyplus.com/es-mx/movies/star-wars-la-guerra-de-los-clones/AVmv1ulT1nQW
