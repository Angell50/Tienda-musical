#ifndef INVENTARIO_H
#define INVENTARIO_H

#define MAX_PRODUCTOS 100

extern char nombres[MAX_PRODUCTOS][50];
extern int cantidades[MAX_PRODUCTOS];
extern float precios[MAX_PRODUCTOS];
extern int numProductos;

int leerEnteroPositivo(char* mensaje);
float leerFlotantePositivo(char* mensaje);
int leerEnteroEntre(char* mensaje, int minimo, int maximo);
void guardarInventario();
void cargarInventario();
void agregarProducto();
void editarProducto();
void eliminarProducto();
void listarProductos();

#endif