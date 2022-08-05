#include <stdio.h>
#include <stdlib.h>
#include "Menus.h"

int menu()
{
    int opcion;

    system("cls");
    printf("-----------------------------------\n"
           "------- *** MENU POST *** ---------\n"
           "-----------------------------------\n\n"
           "1. CARGAR ARCHIVO\n"
           "2. MOSTRAR LISTA DE POST\n"
           "3. ASIGNAR ESTADISTICAS\n"
           "4. FILTRAR POR MEJORES POSTEOS\n"
           "5. FILTRAR POR HATERS\n"
           "6. ORDENAR POR NIVEL DE CANTIDAD DE FOLLOWERS\n"
           "7. MOSTRAR MAS POPULAR\n"
           "8. SALIR\n\n"
           "Ingrese la opcion deseada: ");

    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
