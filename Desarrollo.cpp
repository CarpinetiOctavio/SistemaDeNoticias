#include "Desarrollo.h"

// Implementación del menú inicial
void Desarrollo::menuInicial() {
    int opcion0 = 0;

    do {
        std::cout << "\n\n\t\tSistema de noticias\n\n";
        std::cout << "Ingrese el número correspondiente para indicar el rol de la persona a ser empleada en el sistema: \n";
        std::cout << "1. Lector\n";
        std::cout << "2. Autor\n";
        std::cout << "3. Registros y consultas \n";
        std::cout << "4. Salir del sistema\n";
        std::cin >> opcion0;

        switch (opcion0) {
            case 1:
                menuLectorInicial();
                break;
            case 2:
                menuAutorInicial();
                break;
            case 3:
                menuRegistrosConsultas();
                break;
            case 4:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "\nOpción no válida. Intente nuevamente.\n";
        }
    } while (opcion0 != 4);
}

// Implementación del menú del lector
void Desarrollo::menuLectorInicial() {
    int opcion1 = 0;

    do {
        std::cout << "\n\n\t\tMenú de lector\n\n";
        std::cout << "Indique qué opción desea realizar con el lector: \n";
        std::cout << "1. Carga de lector\n";
        std::cout << "2. Leer artículo\n";
        std::cout << "3. Comentar artículo\n";
        std::cout << "4. Salir\n";
        std::cin >> opcion1;

        switch (opcion1) {
            case 1:
                registrarUsuario();
                break;
            case 2:
                leerArticulos();
                break;
            case 3:
                comentarArticulo();
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
void Desarrollo::menuAutorInicial() {
    int opcion1 = 0;

    do {
        std::cout << "\n\n\t\tMenú de autor\n\n";
        std::cout << "Indique qué opción desea realizar con el autor: \n";
        std::cout << "1. Carga de autor\n";
        std::cout << "2. Registrar artículo\n";
        std::cout << "3. Salir\n";
        std::cin >> opcion1;

        switch (opcion1) {
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

// Implementación del menú de registros y consultas
void Desarrollo::menuRegistrosConsultas() {
    int opcionx = 0;
    int anio = 0;
    int mes = 0;

    std::cout << "\n\n\t\t Registros y consultas \n\n";
    std::cout << "Indique que tipo de registro, o consulta, desea verificar\n";
    std::cout << "Registro de:\n";
    std::cout << "1. Autores\n";
    std::cout << "2. Usuarios\n";
    std::cout << "Consulta de:\n";
    std::cout << "3. Articulos creados por autor\n";
    std::cout << "4. Comentarios realizados por usuarios\n";
    std::cout << "5. Listado de noticias publicadas en el anio\n";
    std::cout << "6. Listado de noticias publicadas en el ultimo mes\n";
    std::cout << "Presione '7' para retornar al menu anterior\n";

    std::cin >> opcionx;

    switch (opcionx) {
        case 1:
            registroDeAutores();
            break;
        case 2:
            registroDeUsuarios();
            break;
        case 3:
            consultarArticulosPorAutor();
            break;
        case 4:
            consultarComentariosPorUsuario();
            break;
        case 5:
            listarNoticiasAnio(anio);
            break;
        case 6:
            listarNoticiasUltimoMes(mes);
            break;
        case 7:
            std::cout << "\nSaliendo del menú de Registros y Consultas...\n";
            break;
        default:
            std::cout << "\nOpción no válida. Intente nuevamente.\n";
    }
}

// Implementación de la función registrarUsuario
void Desarrollo::registrarUsuario() {
    int cantUsuarios = 0;
    std::cout << "Seleccione la cantidad de usuarios a ingresar al sistema: \n";
    std::cin >> cantUsuarios;

    for (int i = 0; i < cantUsuarios; i++) {
        int dni, edad;
        std::string nombre;

        std::cout << "Ingrese los datos del usuario " << i + 1 << ": \n";

        std::cout << "DNI: ";
        std::cin >> dni;

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
void Desarrollo::registrarAutor() {
    int cantAutores = 0;
    std::cout << "Seleccione la cantidad de autores a ingresar al sistema: \n";
    std::cin >> cantAutores;

    for (int i = 0; i < cantAutores; i++) {
        int dni;
        std::string nombre, medio;

        std::cout << "Ingrese los datos del autor " << i + 1 << ": \n";

        std::cout << "DNI: ";
        std::cin >> dni;

        std::cout << "Nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Medio: ";
        std::getline(std::cin, medio);

        Autor autor(dni, nombre, medio);
        autores.push_back(autor);
    }
}

void Desarrollo::registroDeAutores() {
    std::cout << "Autores registrados:\n";
    for (const auto& autor : autores) {
        std::cout << "Nombre: " << autor.getNombre() << ", DNI: " << autor.getDni() << ", Medio: " << autor.getMedio() << "\n";
    }
}

void Desarrollo::registroDeUsuarios() {
    std::cout << "Usuarios registrados:\n";
    for (const auto& usuario : usuarios) {
        std::cout << "Nombre: " << usuario.getNombre() << ", DNI: " << usuario.getDni() << ", Edad: " << usuario.getEdad() << "\n";
    }
}

// Implementación de la función registrarArticulo
void Desarrollo::registrarArticulo() {
    if (autores.empty()) {
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

        std::cout << "Seleccione el autor para el artículo: \n";
        for (size_t j = 0; j < autores.size(); j++) {
            std::cout << j + 1 << ". " << autores[j].getNombre() << " (DNI: " << autores[j].getDni() << ")\n";
        }

        std::cin >> IndiceDeSeleccionDeAutor;

        if (IndiceDeSeleccionDeAutor < 1 || IndiceDeSeleccionDeAutor > autores.size()) {
            std::cout << "Índice de autor no válido. Intente nuevamente.\n";
            i--;
            continue;
        }

        Autor autorSeleccionado = autores[IndiceDeSeleccionDeAutor - 1];
        Articulo articulo(titulo, detalle, dia, mes, anio, autorSeleccionado);
        publicacion.agregarArticulo(articulo);
    }
}

// Implementación de la función comentarArticulo
void Desarrollo::comentarArticulo() {
    if (usuarios.empty()) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }

    if (publicacion.getArticulos().empty()) {
        std::cout << "No hay artículos disponibles.\n";
        return;
    }

    int numeroComentario;
    std::string textoComentario;

    std::cout << "Seleccione el usuario que realiza el comentario:\n";
    mostrarUsuarios();

    int indiceUsuario;
    std::cin >> indiceUsuario;

    if (indiceUsuario < 1 || indiceUsuario > usuarios.size()) {
        std::cout << "Índice de usuario no válido. Intente nuevamente.\n";
        return;
    }

    Usuario usuarioSeleccionado = usuarios[indiceUsuario - 1];

    std::cout << "Seleccione el artículo que desea comentar:\n";
    mostrarArticulos();

    int indiceArticulo;
    std::cin >> indiceArticulo;

    const auto& articulos = publicacion.getArticulos();

    if (indiceArticulo < 1 || indiceArticulo > articulos.size()) {
        std::cout << "Índice de artículo no válido. Intente nuevamente.\n";
        return;
    }

    const Articulo& articuloSeleccionado = articulos[indiceArticulo - 1];

    std::cout << "Ingrese el número del comentario: ";
    std::cin >> numeroComentario;
    std::cout << "Ingrese el texto del comentario: ";
    std::cin.ignore();
    std::getline(std::cin, textoComentario);

    Comentario comentario(numeroComentario, textoComentario, usuarioSeleccionado);

    if (!publicacion.comentarArticulo(articuloSeleccionado.getTitulo(), comentario, usuarioSeleccionado)) {
        std::cout << "Error al agregar el comentario.\n";
    }
}

// Implementación de la función para leer artículos
void Desarrollo::leerArticulos() const {
    publicacion.mostrarArticulos();
}

// Implementación de la función para mostrar la lista de usuarios disponibles
void Desarrollo::mostrarUsuarios() const {
    std::cout << "Usuarios disponibles:\n";
    for (size_t i = 0; i < usuarios.size(); ++i) {
        std::cout << i + 1 << ". " << usuarios[i].getNombre() << " (DNI: " << usuarios[i].getDni() << ")\n";
    }
}

// Implementación de la función para mostrar la lista de artículos disponibles
void Desarrollo::mostrarArticulos() const {
    std::cout << "Artículos disponibles:\n";
    const auto& articulos = publicacion.getArticulos();
    for (size_t i = 0; i < articulos.size(); ++i) {
        std::cout << i + 1 << ". " << articulos[i].getTitulo() << " (Autor: " << articulos[i].getAutor().getNombre() << ")\n";
    }
}

// Implementación de la función para pedir la fecha
void Desarrollo::pedirFecha(int &mes, int &anio) {
    std::cout << "Ingrese el mes actual (1-12): ";
    std::cin >> mes;
    while (mes < 1 || mes > 12) {
        std::cout << "Mes no válido. Ingrese un mes entre 1 y 12: ";
        std::cin >> mes;
    }

    std::cout << "Ingrese el año actual: ";
    std::cin >> anio;
    while (anio < 1) {
        std::cout << "Año no válido. Ingrese un año mayor a 0: ";
        std::cin >> anio;
    }
}

// Implementación de la función para listar noticias publicadas en el último mes
void Desarrollo::listarNoticiasUltimoMes(int mes) {
    int mesActual, anioActual;
    pedirFecha(mesActual, anioActual);

    std::cout << "Noticias publicadas en el último mes:\n";
    for (const auto& articulo : publicacion.getArticulos()) {
        if (articulo.getMes() == mesActual && articulo.getAnio() == anioActual) {
            std::cout << "- " << articulo.getTitulo() << "\n";
        }
    }
}

// Implementación de la función para listar noticias publicadas en el año especificado
void Desarrollo::listarNoticiasAnio(int anio) {
    std::cout << "Ingrese el año para listar las noticias: ";
    std::cin >> anio;

    std::cout << "Noticias publicadas en el año " << anio << ":\n";
    for (const auto& articulo : publicacion.getArticulos()) {
        if (articulo.getAnio() == anio) {
            std::cout << "- " << articulo.getTitulo() << "\n";
        }
    }
}

// Implementación de la función para consultar artículos por autor
void Desarrollo::consultarArticulosPorAutor() {
    if (autores.empty()) {
        std::cout << "No hay autores registrados.\n";
        return;
    }

    std::cout << "Seleccione el autor para listar sus artículos:\n";
    for (size_t i = 0; i < autores.size(); ++i) {
        std::cout << i + 1 << ". " << autores[i].getNombre() << " (DNI: " << autores[i].getDni() << ")\n";
    }

    int indiceAutor;
    std::cin >> indiceAutor;

    if (indiceAutor < 1 || indiceAutor > autores.size()) {
        std::cout << "Índice de autor no válido. Intente nuevamente.\n";
        return;
    }

    const Autor& autorSeleccionado = autores[indiceAutor - 1];

    std::cout << "Artículos del autor " << autorSeleccionado.getNombre() << ":\n";
    for (const auto& articulo : publicacion.getArticulos()) {
        if (articulo.getAutor().getDni() == autorSeleccionado.getDni()) {
            std::cout << "- " << articulo.getTitulo() << "\n";
        }
    }
}

// Implementación de la función para consultar comentarios por usuario
void Desarrollo::consultarComentariosPorUsuario() {
    if (usuarios.empty()) {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }

    std::cout << "Seleccione el usuario para listar sus comentarios:\n";
    mostrarUsuarios();

    int indiceUsuario;
    std::cin >> indiceUsuario;

    if (indiceUsuario < 1 || indiceUsuario > usuarios.size()) {
        std::cout << "Índice de usuario no válido. Intente nuevamente.\n";
        return;
    }

    const Usuario& usuarioSeleccionado = usuarios[indiceUsuario - 1];

    std::cout << "Comentarios del usuario " << usuarioSeleccionado.getNombre() << ":\n";
    for (const auto& articulo : publicacion.getArticulos()) {
        for (const auto& comentario : articulo.getComentarios()) {
            if (comentario.getUsuario().getDni() == usuarioSeleccionado.getDni()) {
                std::cout << "- " << comentario.getTexto() << " (Artículo: " << articulo.getTitulo() << ")\n";
            }
        }
    }
}