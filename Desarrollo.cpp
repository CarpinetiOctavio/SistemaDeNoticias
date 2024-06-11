#include "Desarrollo.h"

// Implementación del menú inicial
void Desarrollo::menuInicial()
{
    int opcion0 = 0;

    do
    {
        std::cout << "\n\n\t\tSistema de noticias\n\n";
        std::cout << "Ingrese el número correspondiente para indicar el rol de la persona a ser empleada en el sistema: \n";
        std::cout << "1. Lector\n";
        std::cout << "2. Autor\n";
        std::cout << "3. Salir del sistema\n";
        std::cin >> opcion0;

        switch (opcion0)
        {
            case 1:
                menuLectorInicial();
                break;
            case 2:
                menuAutorInicial();
                break;
            case 3:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "\nOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion0 != 3);
}

// Implementación del menú del lector
void Desarrollo::menuLectorInicial()
{
    int opcion1 = 0;

    do {
        std::cout << "\n\n\t\tMenú de lector\n\n";
        std::cout << "Indique qué opción desea realizar con el lector: \n";
        std::cout << "1. Carga de lector\n";
        std::cout << "2. Leer artículo\n";
        std::cout << "3. Comentar artículo\n";
        std::cout << "4. Salir\n";
        std::cin >> opcion1;

        switch (opcion1)
        {
            case 1:
                registrarUsuario();
                break;
            case 2:
                // Implementar la función para leer artículo
                break;
            case 3:
                // Implementar la función para comentar artículo
                break;
            case 4:
                std::cout << "\nSaliendo del menú de lector...\n";
                break;
            default:
                std::cout << "\nOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion1 != 4);
}

// Implementación del menú del autor
void Desarrollo::menuAutorInicial()
{
    int opcion1 = 0;

    do {
        std::cout << "\n\n\t\tMenú de autor\n\n";
        std::cout << "Indique qué opción desea realizar con el autor: \n";
        std::cout << "1. Carga de autor\n";
        std::cout << "2. Registrar artículo\n";
        std::cout << "3. Salir\n";
        std::cin >> opcion1;

        switch (opcion1)
        {
            case 1:
                registrarAutor();
                break;
            case 2:
                registrarArticulo();
                break;
            case 3:
                std::cout << "\nSaliendo del menú de autor...\n";
                break;
            default:
                std::cout << "\nOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion1 != 3);
}

// Implementación de la función registrarUsuario
void Desarrollo::registrarUsuario()
{
    int cantUsuarios = 0;
    std::cout << "Seleccione la cantidad de usuarios a ingresar al sistema: \n";
    std::cin >> cantUsuarios;

    for (int i = 0; i < cantUsuarios; i++)
    {
        int dni, edad;
        std::string nombre;

        std::cout << "Ingrese los datos del usuario " << i + 1 << ": \n";

        std::cout << "DNI: ";
        std::cin >> dni;

        /*
         * En aquellas entradas de texto, las cuales puedan contener espacios, se emplea getline, en vez de cin, para evitar posibles errores
         * Ademas, se usa cin.ignore, para vaciar el buffer de entrada, a la hora de cargar el texto
         */
        std::cout << "Nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Edad: ";
        std::cin >> edad;

        Usuario usuario(dni, nombre, edad);
        usuarios.push_back(usuario);
    }
}

// Implementación de la función registrarAutor
void Desarrollo::registrarAutor()
{
    int cantAutores = 0;
    std::cout << "Seleccione la cantidad de autores a ingresar al sistema: \n";
    std::cin >> cantAutores;

    for (int i = 0; i < cantAutores; i++)
    {
        int dni;
        std::string nombre, medio;

        std::cout << "Ingrese los datos del autor " << i + 1 << ": \n";

        std::cout << "DNI: ";
        std::cin >> dni;

        /*
         * En aquellas entradas de texto, las cuales puedan contener espacios, se emplea getline, en vez de cin, para evitar posibles errores
         * Ademas, se usa cin.ignore, para vaciar el buffer de entrada, a la hora de cargar el texto
         */
        std::cout << "Nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Medio: ";
        std::getline(std::cin, medio);

        /*
         * Autor autor(dni, nombre, medio): funciona como un constructor
         * Se crea un objeto autor, del tipo de clase Autor, en la cual se le asignan los valores:
         * dni, nombre y medio, a sus valores correspondientes
         */
        Autor autor(dni, nombre, medio);

        autores.push_back(autor); // Agrega el objeto autor, al final de la linea del vector autores
    }
}

void Desarrollo::registrarArticulo()
{
   // Condicional en caso de querer ingresar un articulo, y no tener ningun autor ingresado
    if (autores.empty())
    {
        std::cout << "No es posible cargar un articulo, debido a que no existen autores ingresados.\n";
        std::cout << "Carge un autor, para poder asignarle el articulo a crear.\n";
        return;
    }

    int cantArticulos = 0;
    std::cout << "Seleccione la cantidad de artículos a ingresar al sistema: \n";
    std::cin >> cantArticulos;

    for (int i = 0; i < cantArticulos; i++) {

        std::string titulo, detalle;
        int     dia = 0,
                mes = 0,
                anio = 0;

        int IndiceDeSeleccionDeAutor = 0;

        std::cout << "Ingrese los datos del artículo " << i + 1 << ": \n";

        std::cout << "Título: ";
        std::cin.ignore(); // Clear newline from the buffer
        std::getline(std::cin, titulo);

        std::cout << "Detalle: ";
        std::getline(std::cin, detalle);

        std::cout << "Día: ";
        std::cin >> dia;

        std::cout << "Mes: ";
        std::cin >> mes;

        std::cout << "Año: ";
        std::cin >> anio;

        /*
         * Se solicita a que autor asignar el articulo creado, y se recorre el indice de autores cargados, en un bucle
         * Se declara e inicializa j como contador del bucle
         * j recorre el mismo, mientras sea menor que el contador del vector autores
         * autores[j].getNombre(): Se obtiene el nombre del autor en la posición j del vector. Lo mismo con el DNI
         */
        std::cout << "Seleccione el autor para el artículo: \n";
        for (size_t j = 0; j < autores.size(); j++) {
            std::cout << j + 1 << ". " << autores[j].getNombre() << " (DNI: " << autores[j].getDni() << ")\n";
        }

        // Se lee el indice del autor seleccionado con IndiceDeSeleccionDeAutor
        std::cin >> IndiceDeSeleccionDeAutor;

        /*
         * Condicional para verificar que la seleccion del autor sea correcta
         * Que IndiceDeSeleccionDeAutor este dentro de los parametros validos ( mayor a 1, y menor a la cantidad de autores ingresados)
         * Caso contrario, decrementa i, para que se repita el bucle principal, e indique una opcion correcta
         */
        if (IndiceDeSeleccionDeAutor < 1 || IndiceDeSeleccionDeAutor > autores.size()) {
            std::cout << "Índice de autor no válido. Intente nuevamente.\n";
            i--; // Repetir este ciclo para intentar nuevamente. Retorna i al valor inicial, para comenzar de nuevo
            continue;
        }

        // Se crea el objeto autorSeleccionado, del tipo Autor
        // Se establece la seleccion del autor, en IndiceDeSeleccionDeAutor - 1 (ya que recorre a partir de 0)
        Autor autorSeleccionado = autores[IndiceDeSeleccionDeAutor - 1];

        /*
         * Se crea un objeto Articulo utilizando los datos del artículo y el objeto Autor seleccionado
         * Los atributos de titulo, detalle, dia, mes, anio; son los datos del artículo que se obtuvieron anteriormente
         * autorSeleccionado, es el objeto Autor seleccionado en el paso anterior
         */
        Articulo articulo(titulo, detalle, dia, mes, anio, autorSeleccionado);
        articulos.push_back(articulo); // Carga el objeto articulo, al vector articulos
    }
}


