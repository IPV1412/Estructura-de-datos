# Documentación de Codigo 1 - IntCell

#### Jonathan Nava Noguez   IPV1412

#### Estructura de datos    ID: 6576

**Instrucciones:** Documentar el siguiente código en su parte de Interfaz e implementación para poder describir el comportamiento del código y cómo afecta la memoria RAM

---

## IntCell.h - Interfaz
![Interfaz.PNG](..%2FInterfaz.PNG)

### Inicio

    #ifndef INTCELL_H
    #define INTCELL_H

    class IntCell {
    public:
En las primeras lineas se empieza con las directivas del preprocesador #ifndef, #define, y #endif, que se utilizan para evitar la inclusión múltiple de archivos de encabezado. 
En este caso, se están asegurando de que el contenido del archivo IntCell.h solo se incluya una vez en un programa.
<br><br>

### Constructores

    IntCell() = default; //Constructor por default
Despues de la creacion de una clase IntCell publica se define el constructor por defecto de la clase IntCell. 
La instrucción = default indica que este constructor se define como predeterminado.
Este constructor crea un objeto IntCell sin parámetros y lo inicializa según la inicialización predeterminada.

    IntCell(int newValue = 0); //Constructor de tipo entero
Constructor de la clase IntCell que acepta un parámetro _newValue_ de tipo entero. 
El parámetro tiene un valor predeterminado de 0, lo que significa que si no se proporciona ningún valor al crear un objeto IntCell, se utilizará 0 como valor inicial.

    IntCell(const IntCell &rhs); // Respaldo o copia del costructor
Toma una referencia constante _rhs_ a otro objeto IntCell y crea una copia de ese objeto. 
Este constructor tiene como objetivo hacer una copia de un objeto IntCell.

    IntCell(IntCell &&rhs) noexcept; //Constructor referenciador
En este constructor se esta haciendo referencia al valor de la clase IntCell.
Toma una referencia de valor _r-valor rhs_ a otro objeto IntCell y mueve los recursos del objeto rhs al nuevo objeto IntCell. 
La palabra _(noexcept)_ indica que este constructor no lanzará excepciones.
<br><br>

### Destructor

    ~IntCell() = default; //Destructor del IntCell
Todo inicio tiene un fin, pues esta linea es un destructor de la clase IntCell. 
Se define como predeterminado con = default, lo que significa que se utiliza la implementación predeterminada del destructor. 
El destructor se encarga de liberar los recursos asignados dinámicamente por un objeto IntCell cuando ese objeto se destruye.
<br><br>

### Operadores

    IntCell &operator=(const IntCell &rhs); // Operador de asignación de copia
Este operador se utiliza para asignar el valor de un objeto IntCell a otro objeto IntCell existente utilizando el operador de asignación _(=)_. 
Toma una referencia constante _rhs_ a otro objeto IntCell como parámetro y devuelve una referencia a _*this_, lo que permite la encadenación de operadores de asignación. 
Este operador realiza una copia profunda del objeto _rhs_ en el objeto actual.

    IntCell &operator=(IntCell &&rhs) noexcept; // Operador de asignación de movimiento
Este operador se utiliza para asignar el valor de un objeto IntCell a otro objeto IntCell existente utilizando el operador de asignación _(=)_ cuando el objeto fuente _(rhs)_ es un _r-valor_ (valor de referencia temporal).
Toma una referencia de valor _r-valor rhs_ a otro objeto IntCell como parámetro y devuelve una referencia a _*this,_ lo que permite la encadenación de operadores de asignación. 
Este operador mueve los recursos del objeto rhs al objeto actual, evitando copias innecesarias y mejorando la eficiencia en términos de memoria y rendimiento.

        IntCell &operator=(int rhs); // Operador de asignación con primitivo int
Este operador acepta un valor entero primitivo como parámetro y se utiliza para asignar un valor entero primitivo a un objeto IntCell. 
Devuelve una referencia a _*this,_ lo que permite la encadenación de operadores de asignación. 
Este operador convierte implícitamente el valor entero primitivo en un objeto IntCell y asigna ese valor al objeto actual.

        IntCell &operator+(const IntCell &rhs); // Operador de suma con IntCell
Es un operador de suma para la clase IntCell, que acepta otro objeto IntCell como parámetro, se utiliza para sumar dos objetos IntCell. 
Devuelve una referencia a un nuevo objeto IntCell que contiene el resultado de la suma de los valores de los dos objetos IntCell.

        IntCell &operator+(int rhs); // Operador de suma con primitivo int
Esta línea declara un operador de suma sobrecargado para la clase IntCell, que acepta un valor entero primitivo como parámetro, se utiliza para sumar un valor entero primitivo a un objeto IntCell.
Devuelve una referencia a un nuevo objeto IntCell que contiene el resultado de la suma del valor del objeto IntCell y el valor entero primitivo.

        IntCell &operator-(const IntCell &rhs); // Operador de resta con IntCell
Este operador es igual al de la suma su diferencia radica en que se se utiliza para restar el valor de un objeto IntCell del valor de otro objeto IntCell.
Y al igual devuelve una referencia a un nuevo objeto IntCell que contiene el resultado de la resta de los valores de los dos objetos IntCell.

        IntCell &operator-(int rhs); // Operador de resta con primitivo int
Identico al operador primitivo de suma aqui acepta un valor entero primitivo como parámetro yse utiliza para restar un valor entero primitivo del valor de un objeto IntCell. 
Devuelve una referencia a un nuevo objeto IntCell que contiene el resultado de la resta del valor del objeto IntCell y el valor entero primitivo.
<br><br>

### Metodos

        int getValue() const; // Método para obtener el valor almacenado
Este método devuelve el valor almacenado en el objeto IntCell. 
Se declara como _const_ para indicar que no modificará el estado del objeto.

        void setValue(int newValue); // Método para establecer el valor almacenado
Por otro lado este establece el valor almacenado en el objeto IntCell al valor especificado por el parámetro _newValue._
<br><br>

### Variable
    private:
    int storedValue; // Valor almacenado en el objeto IntCell
    };
Variable de tipo entero que declara a _storedValue_ la cual almacena el valor entero en el objeto IntCell.
<br><br>

### Fin
    #endif  // INTCELL_H
Es quien declara el FIN.
// INTCELL_H <-- (indica qué símbolo de preprocesador está cerrando.)

---

--- 

## IntCell.cpp - Implementacion
![Implementacion.PNG](..%2FImplementacion.PNG)

### Inicio

    #include "IntCell.h"
Incluye el archivo anterior como libreria _(IntCell)_
<br><br>

### Constructores

    IntCell::IntCell(int newValue) : storedValue(newValue) {} // Constructor por defecto
Comienza con un constructor de la clase IntCell que toma un valor entero _newValue_ como parámetro e inicializa el miembro de datos _storedValue_ con este valor.

    IntCell::IntCell(const IntCell &rhs) : storedValue(rhs.storedValue) {} // Constructor de copia
Por otra parte este costructor toma una referencia constante _rhs_ a otro objeto IntCell como parámetro y copia el valor del de datos _storedValue_ del objeto _rhs_ al _storedValue_ del objeto actual.

    IntCell::IntCell(IntCell &&rhs) noexcept : storedValue(rhs.storedValue) {} // Constructor de movimiento o referencia
Es unconstructor de movimiento de la clase IntCell que toma una referencia de valor _r-valor_ _rhs_ a otro objeto IntCell como parámetro y mueve el valor de los de datos _storedValue_ del objeto _rhs_ a los datos de _storedValue_ del objeto actual.
<br><br>

### Operadores

    // Operador de asignación de copia
    IntCell &IntCell::operator=(const IntCell &rhs) {
    if (this != &rhs) {
    storedValue = rhs.storedValue;
    }
    return *this;
    }
El operador toma una referencia constante _rhs_ a otro objeto IntCell como parámetro y asigna el valor del miembro de datos _storedValue_ del objeto _rhs_ al miembro de datos storedValue del objeto actual, evitando asignación a sí mismo.

    // Eliminar el operador de asignación de movimiento
    IntCell &IntCell::operator=(IntCell &&rhs) noexcept {
    if (this != &rhs) {
    storedValue = rhs.storedValue;
    rhs.storedValue = 0;
    }
    return *this;
    }
Normalmente un operador de movimiento se usa para transferir recursos de un objeto a otro, pero en este caso específico se ha decidido eliminarlo. 
El código dentro de esta función primero verifica si el objeto actual _(*this)_ es diferente al objeto de origen _(rhs)_ para evitar la autoasignación. 
Luego, asigna el valor de los datos _storedValue_ del objeto de origen al objeto actual y establece el _storedValue_ del objeto de origen en 0.
Sin embargo, el código dentro de la función no se ejecutará durante la compilación. Esto significa que la eliminación del operador evitará la transferencia de recursos entre objetos IntCell.

#### Operadores Sobrecargados (Overlodeados)

    IntCell &IntCell::operator=(int rhs) {
    storedValue = rhs;
    return *this;
    }
Este es el operador de asignación que esta sobrecargado y pertenece a la clase IntCell, que acepta un valor entero _(rhs)_ como parámetro y asigna ese valor al de datos _storedValue_ del objeto actual. 
Luego, devuelve una referencia al objeto actual _(*this)_, lo que permite la encadenación de operadores de asignación.

~~~
IntCell &IntCell::operator+(const IntCell &rhs) {
storedValue = storedValue + rhs.storedValue;
return *this;
}

IntCell &IntCell::operator+(int rhs) {
storedValue = storedValue + rhs;
return *this;
}

IntCell &IntCell::operator-(const IntCell &rhs) {
storedValue = storedValue - rhs.storedValue;
return *this;
}

IntCell &IntCell::operator-(int rhs) {
storedValue = storedValue - rhs;
return *this;
}
~~~
Son operadores sobrecargados de suma y resta de la clase IntCell, que hacer refencia a los operadores de **Intcell.h.** 
Permiten sumar o restar un objeto IntCell (o un entero primitivo) al objeto actual, modificando el valor del _storedValue_ en consecuencia.
<br><br>

### Metodos
~~~
int IntCell::getValue() const {
return storedValue;
}

void IntCell::setValue(int newValue) {
storedValue = newValue;
}
~~~
Estos métodos _getValue y setValue_ permiten obtener y establecer el valor almacenado en un objeto IntCell, respectivamente.
<br><br>

### Fin
El codigo te sa las herramientas y posibilidades de trabajar con objetos IntCell, permitiendo asignaciones de enteros, operaciones de suma y resta; dando acceso a su valor almacenado.
<br>

---
IEEE
> “IntCell,” Google Docs (Leonardo Juárez Zucco). https://docs.google.com/document/d/1eMbp49dCFQVkJH8AN9OrpH49j7meuH2Kj5irWodEju4/edit