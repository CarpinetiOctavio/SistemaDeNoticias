//
// Created by Octavio Carpineti on 06/06/2024.
//

#include "Desarrollo.h"
#include "iostream"

void Desarrollo::menuInicial()
{
    int opcion0 = 0;

    do {
        std::cout << "\n\n\t\tSistema de noticias\n\n";
        std::cout
                << "Ingrese el numero correspondiente, para indicar el rol de la persona a ser empleada en el sistema : \n";
        std::cout << "1. Lector\n";
        std::cout << "2. Autor\n";
        std::cout << "3. Salir del sistema\n";
        std::cin >> opcion0;

        int opcion1 = 0;

            switch (opcion1) {
                case 1:
                    menuLectorInicial(); // menu para carga de lector
                    break;
                case 2:
                    menuAutorInicial(); // Implementar la función para gestión de transacciones
                    break;
                case 3:
                    std::cout << "Saliendo del programa..."; // Implementar la función para realizar consultas
                    break;
                default:
                    std::cout << "\nOpción no válida. Intente nuevamente.\n";
            }
        } while (opcion0 != 3);
}

void Desarrollo::menuLectorInicial()
{
    int opcion1 = 0;
    int cantLectores = 0;

    do {
        std::cout << "\n\n\t\tMenu de lector\n\n";
        std::cout << "Indique que opcion desea realizar con el lector: \n";
        std::cout << "1. Carga de lector\n";
        std::cout << "3. Comentar articulo \n";

        std::cout << "Indique cuantos lectores se ingresaran en el sistema: \n";
        std::cin >> cantLectores;

        std::cout << "2. Gestión de movimientos\n";
        std::cout << "3. Consultas\n";
        std::cout << "4. Informes\n";
        std::cout << "5. Salir del sistema\n";
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion1;

        switch (opcion1) {
            case 1:
                ; // Implementacion para gestiónar clientes y personal
                break;
            case 2:
                ; // Implementar la función para gestión de transacciones
                break;
            case 3:
                ; // Implementar la función para realizar consultas
                break;
            case 4:
                ; // Implementar la función para generar informes
                break;
            case 5:
                std::cout << "\nSaliendo del sistema...\n";
                break;
            default:
                std::cout << "\nOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion1 != 5);
}
