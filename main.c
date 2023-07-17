#include <stdio.h>
#include <stdlib.h>
#include "inventario.h"

int main() {
    cargarInventario();

    int opcion;

    do {
        printf("BIENVENIDO A LA CASA MUSICAL AMADOR JIMENEZ\n");
        printf("=== SISTEMA DE INVENTARIO ===\n");
        printf("1. AGREGAR PRODUCTO\n");
        printf("2. EDITAR PRODUCTO\n");
        printf("3. ELIMINAR PRODUCTO\n");
        printf("4. LISTAR PRODUCTO\n");
        printf("5. GUARDAR INVENTARIO\n");
        printf("6. SALIR\n");
        opcion = leerEnteroEntre("Ingrese una opcion: ",1,6);

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                editarProducto();
                break;
            case 3:
                eliminarProducto();
                break;
            case 4:
                listarProductos();
                break;
            case 5:
                guardarInventario();
                break;
            case 6:
                printf("Saliendo del sistema...\n");
                break;
        }

        printf("\n");
    } while (opcion != 6);

    return 0;
}
