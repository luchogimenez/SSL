# hello.c
```
#include <stdio.h>

int main ( ) {

    printf("Hello World! \n");
}
```
# hello.cpp

```#include <iostream>

int main ( ) {

    std :: cout<<"Hello World! \n";
}
```

|                         |*Similitudes*                               |*Diferencias*                 |
|-------------------------|-------------------------------------------|-----------------------------|
|*Léxico (token)*         |#,include, int, main(), entre otras                     |uso de ": :" y "<<" en cpp   |
|*Sintaxis (estructura)*    |tienen estructura muy similares            |en cpp el operador binario es **infijo** en la sentecia de expresion std::cout<< mientras que en c la sentencia de expresion printf("") es **sufija**.         |
|*Semánitca (significado)*  |son muy similares            |en c printf invoca una funcion y le pasa la cadena como argumento mientras que en cpp std: : cout << solicita que se inserte la cadena en el flujo de salida |
|*Pragmática (efecto)*      |en ambos el efecto deseado es mostrar en consola la cadena            | |