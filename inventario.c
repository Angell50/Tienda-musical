#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventario.h"

char nombres[MAX_PRODUCTOS][50];
int cantidades[MAX_PRODUCTOS];
float precios[MAX_PRODUCTOS];
int numProductos = 0;

int leerEnteroPositivo(char* mensaje) {
    int valor;
    do {
        printf("%s: ", mensaje);
        scanf("%d", &valor);
    } while (valor <= 0);
    return valor;
}

float leerFlotantePositivo(char* mensaje) {
    float valor;
    do {
        printf("%s: ", mensaje);
        scanf("%f", &valor);
    } while (valor <= 0);
    return valor;
}

int leerEnteroEntre(char* mensaje, int minimo, int maximo) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
    } while (valor < minimo || valor > maximo);
    return valor;
}

void guardarInventario() {
    FILE* archivo = fopen("inventario.txt", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < numProductos; i++) {
        fprintf(archivo, "%s %d %.2f\n", nombres[i], cantidades[i], precios[i]);
    }

    fclose(archivo);
    printf("Inventario guardado en el archivo 'inventario.txt' correctamente.\n");
}

void cargarInventario() {
    FILE* archivo = fopen("inventario.txt", "r");

    if (archivo == NULL) {
        printf("No se encontró el archivo de inventario. Se creará uno nuevo.\n");
        return;
    }

    numProductos = 0;

    while (!feof(archivo) && numProductos < MAX_PRODUCTOS) {
        fscanf(archivo, "%s %d %f\n", nombres[numProductos], &cantidades[numProductos], &precios[numProductos]);
        numProductos++;
    }

    fclose(archivo);
    printf("Inventario cargado desde el archivo 'inventario.txt' correctamente.\n");
}

void agregarProducto() {
    if (numProductos == MAX_PRODUCTOS) {
        printf("El inventario está lleno. No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[numProductos]);

    printf("Ingrese la cantidad de productos: ");
    scanf("%d", &cantidades[numProductos]);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &precios[numProductos]);

    numProductos++;
    printf("Producto agregado con éxito.\n");
}

void editarProducto() {
    char nombre[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombre);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        int j;
        for (j = 0; nombres[i][j] != '\0' && nombre[j] != '\0'; j++) {
            if (nombres[i][j] != nombre[j]) {
                break;
            }
        }

        if (nombres[i][j] == '\0' && nombre[j] == '\0') {
            printf("Ingrese la nueva cantidad de productos: ");
            scanf("%d", &cantidades[i]);

            printf("Ingrese el nuevo precio del producto: ");
            scanf("%f", &precios[i]);

            printf("Producto editado con éxito.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró el producto con el nombre ingresado.\n");
    }
}

void eliminarProducto() {
    char nombre[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        int j;
        for (j = 0; nombres[i][j] != '\0' && nombre[j] != '\0'; j++) {
            if (nombres[i][j] != nombre[j]) {
                break;
            }
        }

        if (nombres[i][j] == '\0' && nombre[j] == '\0') {
            for (int k = i; k < numProductos - 1; k++) {
                int l;
                for (l = 0; nombres[k][l] != '\0'; l++) {
                    nombres[k][l] = nombres[k + 1][l];
                }
                nombres[k][l] = '\0';
                cantidades[k] = cantidades[k + 1];
                precios[k] = precios[k + 1];
            }

            numProductos--;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("No se encontró el producto con el nombre ingresado.\n");
    } else {
        printf("Producto eliminado con éxito.\n");
    }
}

void listarProductos() {
    if (numProductos == 0) {
        printf("No hay productos en el inventario.\n");
    } else {
        printf("INVENTARIO:\n");
        for (int i = 0; i < numProductos; i++) {
            printf("Producto: %s\n", nombres[i]);
            printf("Cantidad: %d\n", cantidades[i]);
            printf("Precio: %.2f\n", precios[i]);
            printf("--------------------------\n");
        }
    }
}