# Fases de la Traducción y Errores
## 6.1. Objetivos
- Identificar las fases de traducción y errores.
## 6.2. Temas
- Fases de traducción.
- Preprocesamiento.
- Compilación.
- Ensamblado.
- Vinculación (Link).
- Errores en cada fase.
## 6.3. Tareas
1. Investigar las funcionalidades y opciones que su compilador presenta para
limitar el inicio y fin de las fases de traducción.  
2. Para la siguiente secuencia de pasos:  
a. Transicribir en `readme.md` cada comando ejecutado y  
b. Describir en `readme.md` el resultado u error obtenidos para cada paso.
## 6.3.1. Secuencia de Pasos
1. Escribir hello2.c, que es una variante de hello.c:
```
#include <stdio.h>

int/*medio*/main(void){
    int i=42;
    prontf("La respuesta es %d\n");
```
2. Preprocesar `hello2.c`, no compilar, y generar `hello2.i`. Analizar su
contenido.
3. Escribir hello3.c, una nueva variante:
```int printf(const char *s, ...);
int main(void){
int i=42;
prontf("La respuesta es %d\n");
```
4. Investigar la semántica de la primera línea.
5. Preprocesar `hello3.c`, no compilar, y generar `hello3.i`. Buscar diferencias
entre `hello3.c` y `hello3.i`.
6. Compilar el resultado y generar `hello3.s`, no ensamblar.
7. Corregir en el nuevo archivo `hello4.c` y empezar de nuevo, generar `hello4.s`, no ensamblar.
8. Investigar `hello4.s`.
9. Ensamblar `hello4.s` en `hello4.o`, no vincular.
10. Vincular `hello4.o` con la biblioteca estándar y generar el ejecutable.
11. Corregir en `hello5.c` y generar el ejecutable.
12. Ejecutar y analizar el resultado.
13. Corregir en `hello6.c` y empezar de nuevo.
14. Escribir `hello7.c`, una nueva variante:
```
int main(void){
int i=42;
printf("La respuesta es %d\n", i);
}
```
15. Explicar porqué funciona.
## 6.4. Restricciones
- El programa ejemplo debe enviar por stdout la frase La respuesta es 42, el valor 42 debe surgir de una variable.
## 6.5. Productos

```
DD-FasesErrores
|-- readme.md
|-- hello2.c
|-- hello3.c
|-- hello4.c
|-- hello5.c
|-- hello6.c
`-- hello7.c
```
---
---
# Resolución


##  Funcionalidades y opciones del compilador

Comando  |  Acción
------- | -------
-E | Preprocess only; do not compile, assemble or link.
-S | Compile only; do not assemble or link.
-c | Compile and assemble, but do not link.
-o \<file> |  Place the output into \<file>

## Paso 1
## hello2.c
```
#include <stdio.h>

int/*medio*/main(void){
    int i=42;
    prontf("La respuesta es %d\n");
```
## Paso 2
Para preprocesar `hello2.c` se utiliza el comando `>gcc -E hello2.c -o hello2.i`  
En el archivo `hello2.i` se aprecian todas los prototipos de las funciones que pertenecen a la biblioteca stdio y al final se vuelve a repetir el código fuente, pero reemplaza el comentario /\*medio*/ por un espacio, quedando de la siguiente manera:

```
int main(void){
int i=42;
prontf("La respuesta es %d\n");
```
## Paso 3
## hello3.c

```
int printf(const char *s, ...);

int main(void){
int i=42;
prontf("La respuesta es %d\n");
```
## Paso 4
**Semántica de la primera linea:** definir una funcion de nombre printf que retorne un entero y reciba como parámetro un puntero a char y otros parámetros, declarar el objeto que luego será invocado.
## Paso 5 
Deferencias entre `hello3.c` y `hello3.i`
Para preprocesar `hello2.c` se utiliza el comando `>gcc -E hello2.c -o hello2.i` y se obtiene lo siguiente:
## hello3.i
```
# 1 "hello3.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "hello3.c"
int printf(const char *s, ...);
int main(void){
int i=42;
prontf("La respuesta es %d\n");
``` 
La diferencia son las primeras cuatro lineas de cógido del archivo hello3.i que representan anotaciones del preprocesador pero que son obviadas por el compilador.
> \# 1 "hello3.c"  
> \# 1 "<built-in>"  
> \# 1 "<command-line>"  
> \# 1 "hello3.c"  
## Paso 6
  
Para compilar sin ensamblar `hello3.c` se utiliza el siguiente comando `>gcc -S hello3.i`  
devuelve 1 warning y 1 error:  
>hello3.c: In function 'main':  
>hello3.c:4:1: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]  
>    4 | prontf("La respuesta es %d\n");  
>      | ^~~~~~  
>      | printf  
>hello3.c:4:1: error: expected declaration or statement at end of input  

## Paso 7
Se corrije el error de sintaxis agregando la llave '}' al final.
Se preprocesa y compila sin ensamblar utilizando los siguientes comandos:  

`>gcc -E hello4.c -o hello4.i`  
`>gcc -S hello4.i`  

generando los archivos `hello4.i` y `hello4.s` respectivamente.  
## Paso 8

Al correjir el error de sintaxis se puede compilar y se genera el archivo en código assembler, se aprecian los llamados a la funciones main y prontf ( `call __main` y `call __prontf`) también la cadena de caracteres como argumento, sigue el warning del paso anterior.
## hello4.s
```
	.file	"hello4.c"
	.text
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "La respuesta es %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$42, 28(%esp)
	movl	$LC0, (%esp)
	call	_prontf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE0:
	.ident	"GCC: (MinGW.org GCC Build-20200227-1) 9.2.0"
	.def	_prontf;	.scl	2;	.type	32;	.endef
```
## Paso 9
Para ensamblar `hello4.s`  sin vincular, se utiliza el siguiente comando `>gcc -c hello4.s` y se genera el archivo `hello4.o`
## Paso 10
Para vincular `hello4.o` con la biblioteca estándar se utiliza el siguiente comando `>gcc hello4.o`

Pero se produce un error y no se genera el archivo ejecutable `hello4.exe`
>c:/mingw/bin/../lib/gcc/mingw32/9.2.0/../../../../mingw32/bin/ld.exe: hello4.o:hello4.c:(.text+0x1e): undefined reference to `prontf'
collect2.exe: error: ld returned 1 exit status  
## Paso 11

Se corrije el warning de los pasos anteriores cambiando 'prontf' por 'printf' como sujiere el compilador considerandolo como error léxico. También se podria agregar el objeto prontf a la biblioteca estándar o crear una biblioteca y desarrollar dicha función.

## hello5.c 
```
int printf(const char *s, ...);
int main(void){
int i=42;
printf("La respuesta es %d\n");
}
``` 
se aplican todos los pasos para generar el archivo ejecutable `hello5.exe` 
## Paso 12
Se ejecuta obteniendose el siguiente resultado:
>La respuesta es 4200688

La respuesta deseada debe ser: 

>La respuesta es 42

Por lo que tiene un error pragmático
## Paso 13
Se corrije el error pragmático pasandole el parámetro "i" que falta en la funcion printf

## hello6.c
```
int printf(const char *s, ...);

int main(void){
int i=42;
printf("La respuesta es %d\n",i);
}
```
Se aplican todos los pasos anteriores y se genera el archivo ejecutable `hello6.exe`. Se ejecuta y se obtiene lo siguiente:

>La respuesta es 42

que es el resultado esperado.

## Paso 14
## hello7.c
```
int main(void){
int i=42;
printf("La respuesta es %d\n", i);
}
```
## Paso 15

Funciona ya que el linker encuentra la funcion printf en la biblioteca estándar, en c los prototipos de las funciones no son necesarios y por default se buscan automáticamente en la biblioteca estándar del compilador.
