#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_NOT 8

typedef struct
{
    int id;
    char procesador[10];
    char marca[20];
    float precio;
}eNotebook;

/** Crear una función llamada aplicarDescuento que reciba como parámetro el precio de un producto y devuelva el valor del producto con un descuento del 5%.
Realizar la llamada desde el main.

 *Crear una función que se llame contarCaracteres que reciba una cadena de caracteres como primer parámetro
  y un carácter como segundo y devuelva la cantidad de veces que ese carácter aparece en la cadena

 * Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca.
 Ante igualdad de marca deberá ordenarse por precio. Hardcodear datos y mostrarlos desde el main..*/

 float aplicarDescuento(float precio);
 int contarCaracteres(char cadena[], char caracter);
 int ordenarPorMarcaYPrecio(eNotebook notebooks[], int tamNot);

int main()
{
    float precioACaculular;
    float precioConDescuento;
    char palabra[20];
    char caracter;
    int totalCaracter;
    eNotebook notebooks[TAM_NOT] = {
        {1, "i3", "Intel", 350},
        {2, "i5", "Celeron", 450},
        {3, "i7", "Intel", 550},
        {4, "i9", "Intel", 650},
        {5, "Ryzen 3", "AMD", 300},
        {6, "Ryzen 5", "AMD", 400},
        {7, "Ryzen 7", "Pentium", 500},
        {8, "Ryzen 9", "AMD", 600}
    };

    printf("Ingrese un precio a calcularle el 5%%\n");
    scanf("%f", &precioACaculular);

    precioConDescuento = aplicarDescuento(precioACaculular);

    printf("El precio con descuento es: %.2f\n", precioConDescuento);

    system("pause");

    printf("\nIngrese una palabra.\n");
    fflush(stdin);
    gets(palabra);
    strupr(palabra);

    printf("Ingrese el caracter que desea saber cuantas veces esta en: %s\n", palabra);
    fflush(stdin);
    scanf("%c", &caracter);
    caracter = toupper(caracter);

    totalCaracter = contarCaracteres(palabra, caracter);

    printf("En la palabra el caracter elegido se encuentra: %d (vez/veces)\n", totalCaracter);

    system("pause");

    printf("\n   *** Listado de Notebooks no ordenadas ***  \n");
    printf("\n|ID  |Procesador      |Marca      |Precio     \n");
    printf("------------------------------------------------\n");

    for(int i = 0; i < TAM_NOT; i++)
    {
        printf("%d       %-7s        %-10s        %.2f\n",
           notebooks[i].id,
           notebooks[i].procesador,
           notebooks[i].marca,
           notebooks[i].precio
           );
    }

    printf("\n\n");

    printf("\n   *** Listado de Notebooks ordenadas ***     \n");
    printf("------------------------------------------------\n");

    ordenarPorMarcaYPrecio(notebooks, TAM_NOT);

    for(int i = 0; i < TAM_NOT; i++)
    {
        printf("%d       %-7s        %-10s        %.2f\n",
           notebooks[i].id,
           notebooks[i].procesador,
           notebooks[i].marca,
           notebooks[i].precio
           );
    }

    return 0;
}

//Primera Funcion
float aplicarDescuento(float precio)
{
    float precioConDescuento;
    float precioFinalConDescuento;

    precioConDescuento = precio * 5 / 100;

    precioFinalConDescuento = precio - precioConDescuento;

    return precioFinalConDescuento;
}

//Segunda Funcion
int contarCaracteres(char cadena[], char caracter)
{
    int contadorCaracter = 0;
    if(cadena != NULL)
    {
        for(int i = 0; i < strlen(cadena); i++)
        {
            if(cadena[i] == caracter)
            {
                contadorCaracter++;
            }
        }
    }
    return contadorCaracter;
}

//Tercera Funcion

int ordenarPorMarcaYPrecio(eNotebook notebooks[], int tamNot)
{
    int todoOk = 0;
    eNotebook auxNotebook;

    for(int i = 0; i < tamNot - 1; i++)
    {
        for(int j = i + 1; j < tamNot; j++)
        {
            if((strcmp(notebooks[i].marca, notebooks[j].marca) > 0) || (strcmp(notebooks[i].marca, notebooks[j].marca) == 0 && notebooks[i].precio > notebooks[j].precio))
            {
                auxNotebook = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = auxNotebook;
            }
        }
    }
    todoOk = 1;
    return todoOk;
}
