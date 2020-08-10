# 10 Máquinas de Estado — Palabras en Líneas

Este trabajo está basado en el ejercicio 1-12 de [KR1988]:

    1-12. Escriba un programa que imprima su entrada una palabra por línea.

Problema: Imprimir cada palabra de la entrada en su propia línea.  
La cantidadde líneas en la salida coincide con la cantidad de palabras en la entrada. Cadalínea tiene solo una palabra.

## 10.1. Objetivos

* Aplicar máquinas de estado para el procesamiento de texto.
* Implementar máquinas de estado con diferentes métodos.

## 10.2. Temas

* Árboles de expresión.
* Representación de máquinas de estado.
* Implementación de máquinas de estado.

## 10.3. Tareas

### 1. Árboles de Expresión

a. Estudiar el programa del ejemplo las sección 1.5.4 Conteo de Palabras de [KR1988].

b. Dibujar el árbol de expresión para la inicialización de los contadores: nl = nw = nc = 0.

![arbol_1](Imagenes/arbol_b.png)

c. Dibujar el árbol de expresión para la expresión de control del segundo if: c == ' ' || c == '\n' || c == '\t'.

![arbol_1](Imagenes/arbol_c.png)

### 2. Máquina de estado

a. Describir en lenguaje dot [DOT2015] y dentro del archivo wl.gv la máquina de estado que resuelve el problema planteado.

![arbol_1](Imagenes/wl.png)

b. Formalizar la máquina de estados como una n-upla, basarse en el
Capítulo #1 del Volumen #3 de [MUCH2012].

$
M=(Q,\sum,T,q_0,F)
$

$
M=(\{IN,OUT\},\{ASCII\},T,\{OUT\},\{IN,OUT\})
$

$
\\donde:
\\
Q=\text{Conjunto finito no vacio de estados.}
\\
\sum=\text{Alfabeto reconocido por el autómata}
\\
T=\text{Función de transiciones}
\\
q_0=\text{Estado inicial}
\\
F=\text{Conjunto de estados finales}
\\
$

La función de transiciones se representa mediante la tabla de transiciones siguiente.

|T|{' ','\n', '\t'}|ASCII-{' ','\n', '\t'}|
|--------|--------|-----|
|    OUT-    |    OUT    |IN|
|    IN    |    OUT    |IN|

### 3. Implementaciones de Máquinas de Estado

Las implementaciones varían en los conceptos que utilizan para representar los estados y las transiciones.

a. Implementación #1: Una variable para el estado actual.

i. Escribir el programa wl-1-enum-switch.c que siga la Implementación#1, variante enum y switch.

Esta implementación es la regularización de la implementación de la sección 1.5.4 de [KR1988]. Los estados son valores de una variable y las transiciones son la selección estructurada y la actualización de esa variable. Esta versión es menos eficiente que la versión de [KR1988], pero su regularidad permite la automatización de la construcción del programa que implementa la máquina de estados. Además de la regularidad, esta versión debe:  

* Utilizar typedef y enum en vez de define, de tal modo que la variable estado se pueda declarar de la siguiente manera: States = Out;  

* Utilizar switch en vez de if.
  
ii. Responder en readme.md: Indicar ventajas y desventajas de la versión de [KR1988] y de esta implementción.

`Las enumeraciones proporcionan una manera conveniente de asociar valores constantes con nombres, una alternativa a` `#define` `con la ventaja de que los valores pueden ser generados para uno. Aunque las variables de tipo enum pueden ser declaradas, los compiladores no necesitan revisar que lo que se va a almacenar en tal variable es un valor válido para la enumeración. No obstante, las variables de enumeración ofrecen la oportunidad de revisarlas y tal cosa es a menudo mejor que` `#define` `. Además, un depurador puede ser capaz de imprimir los valores de variables de enumeración en su forma simbólica. Al usar switch se puden concatenar varios` `case` `en una acción simple.`

b. Implementación #2: Sentencias goto (sí, el infame goto)

i. Leer la sección 3.8 Goto and labels de [KR1988]

ii. Leer Go To Statement Considered Harmful de [DIJ1968].

iii. Leer "GOTO Considered Harmful" Considered Harmful de [RUB1987].

iv. Responder en readme.md: ¿Tiene alguna aplicación go to hoy en día? ¿Algún lenguaje moderno lo utiliza?

`Los lenguajes modernos lo utilizan pero de forma "implícita" en expresiones como for, switch, entre otras.`

v. Escribir el programa wl-2-goto.c que siga la Implementación #2.
En esta implementación los estados son etiquetas y las transiciones son la selección estructurada y el salto incondicional con la sentencia goto.

c. Implementación #3: Funciones Recursivas
i. Leer la sección 4.10 Recursividad de [KR1988].

ii. Responder en readme.md: ¿Es necesario que las funciones accedan a contadores? Si es así, ¿cómo hacerlo?.
Leer la sección 1.10 Variables Externas y Alcance y 4.3 Variables Externas de [KR1988].

`No fué necesario que las funciones accedan a contadores.`

iii. Escribir el programa, wl-3-rec.c que siga la implementación #3.
En esta implementación los estados son funciones recursivas y las transiciones son la selección estructurada y la invocación recursiva.

d. Implementación #X:  
Es posible diseñar más implementaciones. Por ejemplo, una basada en una tabla que defina las transiciones de la máquina. En ese caso, el programa usaría la tabla para lograr el comportamiento deseado. El objetivo de este punto es diseñar una implementación diferente a las implementaciones #1, #2, y #3.

i. Diseñar una nueva implementación e indicar en Readme.md cómo esa implementación representa los estados y cómo las transiciones.

ii. Escribir el programa, wl-x.c que siga la nueva implementación.
