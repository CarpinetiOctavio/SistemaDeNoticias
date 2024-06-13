#include "Desarrollo.h"
#include <fstream>

// Desarrollo funcion para abrir o crear archivos .txt donde se registraran los datos

void Desarrollo::registrarDatos(const std::string& nombreArchivo, const std::string& datos) {
    std::ofstream archivoSalida(nombreArchivo, std::ios::app);
    if (!archivoSalida) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }
    archivoSalida << datos << std::endl;
    archivoSalida.close();
}

// Funcion que lee el indice de los archivos para anotarlos con el correspondiente al archivado
int leerUltimoIndice(const std::string& nombreArchivo, const std::string& tipoRegistro) { // tipoRegistro espera comparar por ejemplo: Autor con Autor, en donde encontrará los indices
    std::ifstream archivoEntrada(nombreArchivo);
    if (!archivoEntrada) {
        // Si el archivo no existe, devolver 0
        return 0;
    }

    std::string linea;
    int ultimoIndice = 0;
    while (std::getline(archivoEntrada, linea)) { //mientras haya texto en cada línea, esta se almacena en la variable 'linea'
        // Suponiendo que el índice está en una línea que empieza con el tipo de registro
        if (linea.find(tipoRegistro) == 0) {
            size_t pos = linea.find(' '); //buscamos el primer espacio, .find() devuelve la posicion
            if (pos != std::string::npos) { //Verifica que se encontró la linea, npos y pos no coinciden
                int indice = std::stoi(linea.substr(pos + 1)); // Hace una subcadena desde el espacio consecutivo al tipoRegistro y lo pasa a entero
                if (indice > ultimoIndice) {
                    ultimoIndice = indice;
                }
            }
        }
    }

    archivoEntrada.close();
    return ultimoIndice;
}

/*
 * 1. DESARROLLO DE MENUES
 */

// Implementación del menú inicial al iniciar el programa
void Desarrollo::menuInicial()
{
    int opcion0 = 0;

    do
    {
        std::cout << "\n\n\t\tSistema de noticias\n\n";
        std::cout << "Ingrese el número correspondiente para indicar que menu desplegar: \n";
        std::cout << "1. Lector\n";
        std::cout << "2. Autor\n";
        std::cout << "3. Registros y consultas \n";
        std::cout << "4. Salir del sistema\n";
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
void Desarrollo::menuLectorInicial()
{
    int opcion1 = 0;

    do
    {
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
void Desarrollo::menuAutorInicial()
{
    int opcion1 = 0;

    do
    {
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

// Implementación del menú de registros y consultas
void Desarrollo::menuRegistrosConsultas()
{
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

    switch (opcionx)
    {
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

/*
 * 2. DESARROLLO DE FUNCIONES DEL MENU USUARIO
 */

// Implementación de la función registrarUsuario
void Desarrollo::registrarUsuario()
{
    int cantUsuarios = 0;
    std::cout << "Seleccione la cantidad de usuarios a ingresar al sistema: \n";
    std::cin >> cantUsuarios;

    // Leer el último índice del archivo o usar el tamaño actual del vector
    int usuarioInicial = leerUltimoIndice("registro_usuarios.txt", "Usuario");
    if (usuarioInicial == 0) {
        usuarioInicial = usuarios.size();
    }
    for (int i = 0; i < cantUsuarios; i++)
    {
        int dni, edad;
        std::string nombre;

        std::cout << "Ingrese los datos del usuario " << i + 1 << ": \n";

        std::cout << "DNI: ";
        std::cin >> dni;

        /*
         * En aquellas entradas de texto, las cuales puedan contener espacios, se emplea 'getline'
         * De usar 'cin', genera errores si en la entrada de texto tiene espacios
         * Para corroborar que no hayan fallas en la entrada de texto, se usa 'cin.ignore'
         *, para vaciar el buffer de entrada, a la hora de cargar el texto
         */
        std::cout << "Nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Edad: ";
        std::cin >> edad;

        /*
         * Se crea un objeto de la clase Usuario usando los datos ingresados (dni, nombre, y edad).
         * Trabajo como constructor
         */
        Usuario usuario(dni, nombre, edad);

        // El objeto usuario recién creado se agrega al vector usuarios.
        usuarios.push_back(usuario);

        // Registro del usuario en un archivo de texto
        // Formatear los datos del usuario a string
        std::string datosUsuario = "Usuario " + std::to_string(usuarioInicial + i + 1) + ":\n" +
                                   "DNI: " + std::to_string(dni) + "\n" +
                                   "Nombre: " + nombre + "\n" +
                                   "Edad: " + std::to_string(edad) + "\n";
        registrarDatos("registro_usuarios.txt", datosUsuario);
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

    int numeroDeComentario;
    std::string textoComentario;

    std::cout << "Seleccione el usuario que realiza el comentario:\n";
    mostrarUsuarios();

    // La seleccion de usuario que comenta se almacena en 'seleccionDeUsuario'
    int seleccionDeUsuario;
    std::cin >> seleccionDeUsuario;

    if (seleccionDeUsuario < 1 || seleccionDeUsuario > usuarios.size()) {
        std::cout << "Índice de usuario no válido. Intente nuevamente.\n";
        return;
    }

    /*
     * Selecciona un usuario de la lista de usuarios registrados basándose en el
     * Indice proporcionado por el usuario y crea una copia de dicho usuario.
     * El vector usuarios se posiciona en [seleccionDeUsuario - 1] (ya que los indices comienzan en 0)
     * usuarioSeleccionado crea una copia del usuario seleccionado
     */
    Usuario usuarioSeleccionado = usuarios[seleccionDeUsuario - 1];

    std::cout << "Seleccione el artículo que desea comentar:\n";
    mostrarArticulos();

    int indiceDeArticulo;
    std::cin >> indiceDeArticulo;

    const std::vector<Articulo> &articulos = publicacion.getArticulos();

    if (indiceDeArticulo < 1 || indiceDeArticulo > articulos.size()) {
        std::cout << "Seleccion de articulo invalida. Ingrese una opcion valida.\n";
        return;
    }

    const Articulo &articuloSeleccionado = articulos[indiceDeArticulo - 1];

    std::cout << "Especifique el numero del comentario a realizar: ";
    std::cin >> numeroDeComentario;
    std::cout << "Comente a continuacion: ";
    std::cin.ignore();
    std::getline(std::cin, textoComentario);

    Comentario comentario(numeroDeComentario, textoComentario, usuarioSeleccionado);

    if (!publicacion.comentarArticulo(articuloSeleccionado.getTitulo(), comentario, usuarioSeleccionado)) {
        std::cout << "Error al agregar el comentario.\n";
    }

    // Registro de comentario en archivo de texto
    // Formateo los datos del comentario como una cadena
    std::string datosComentario = "Usuario: " + usuarioSeleccionado.getNombre() +
                                  "\nArtículo: " + articuloSeleccionado.getTitulo() +
                                  "\nNúmero de comentario: " + std::to_string(numeroDeComentario) +
                                  "\nTexto del comentario: " + textoComentario + "\n";

    // Registro los datos en un archivo
    registrarDatos("registro_comentarios.txt", datosComentario);
}

// Implementación de la función para leer artículos
void Desarrollo::leerArticulos() const
{
    publicacion.mostrarArticulos();
}

/*
 * 3. DESARROLLO DEL FUNCIONES DEL MENU DE AUTOR
 */

// Función para registrar autores
void Desarrollo::registrarAutor()
{
    int cantAutores = 0;
    std::cout << "Seleccione la cantidad de autores a ingresar al sistema: \n";
    std::cin >> cantAutores;
    
    // Leer el último índice del archivo o usar el tamaño actual del vector
    int autorInicial = leerUltimoIndice("registro_autores.txt", "Autor");
    if (autorInicial == 0) {
        autorInicial = autores.size();
    }

    for (int i = 0; i < cantAutores; i++)
    {
        int dni;
        std::string nombre, medio;

        std::cout << "Ingrese los datos del " << i + 1 << " autor: \n";

        std::cout << "DNI: ";
        std::cin >> dni;

        std::cout << "Nombre: ";
        std::cin.ignore();
        std::getline(std::cin, nombre);

        std::cout << "Medio: ";
        std::getline(std::cin, medio);

        Autor autor(dni, nombre, medio);
        autores.push_back(autor);

        //Registro datos del autor en un archivo
        // Formatear los datos del autor como una cadena
        
        std::string datosAutor = "Autor " + std::to_string(autorInicial + i + 1) + ":\n" +
                                 "DNI: " + std::to_string(dni) + "\n" +
                                 "Nombre: " + nombre + "\n" +
                                 "Medio: " + medio + "\n";
        registrarDatos("registro_autores.txt", datosAutor);

    }
}

// Funcion para registrar articulos
void Desarrollo::registrarArticulo()
{
    if (autores.empty())
    {
        std::cout << "No es posible cargar un articulo, debido a que no existen autores ingresados.\n";
        std::cout << "Carge un autor previamente, para poder asignarle el articulo a crear.\n";
        return;
    }

    int cantArticulos = 0;
    std::cout << "Seleccione la cantidad de artículos a ingresar al sistema: \n";
    std::cin >> cantArticulos;


    // Leer el último índice del archivo o usar el tamaño actual del vector
    int articuloInicial = leerUltimoIndice("registro_articulos.txt", "Artículo");
    if (articuloInicial == 0) {
        articuloInicial = publicacion.getArticulos().size();
    }

    for (int i = 0; i < cantArticulos; i++)
    {

        std::string titulo, detalle;
        int     dia = 0,
                mes = 0,
                anio = 0;

        int IndiceDeSeleccionDeAutor = 0;

        std::cout << "Ingrese los datos del " << i + 1 << " artículo : \n";

        std::cout << "Título: ";
        std::cin.ignore(); // Limpiar buffer
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
         * Se solicita a que autor asignar el articulo creado, y 'j' recorre el indice de autores cargados, en un bucle
         * 'j' recorre el mismo, mientras sea menor que el contador del vector autores
         * autores[j].getNombre(): Se obtiene el nombre del autor en la posición j del vector. Lo mismo con el DNI
         */
        std::cout << "Especifique el autor para el artículo: \n";
        for (size_t j = 0; j < autores.size(); j++)
        {
            std::cout << j + 1 << ". " << autores[j].getNombre() << " (DNI: " << autores[j].getDni() << ")\n";
        }

        // Variable donde se guarda la posicion de la seleccion del autor
        std::cin >> IndiceDeSeleccionDeAutor;


        /*
         * Condicional para verificar que la seleccion del autor sea correcta
         * Que IndiceDeSeleccionDeAutor este dentro de los parametros validos (mayor a 1, y menor a la cantidad de autores ingresados)
         * Caso contrario, decrementa i, para que se repita el bucle principal, e indique una opcion correcta
         */
        if (IndiceDeSeleccionDeAutor < 1 || IndiceDeSeleccionDeAutor > autores.size())
        {
            std::cout << "Índice de autor no válido. Intente nuevamente.\n";
            i--; // Al decrementar i, se reanuda el bucle prinicpal en su estado inicial
            continue;
        }

        Autor autorSeleccionado = autores[IndiceDeSeleccionDeAutor - 1];

        /*
         * Se crea un objeto Articulo, el cual utiliza los datos del artículo y el objeto Autor seleccionado
         * Los atributos de titulo, detalle, dia, mes, anio; son los datos del artículo que se obtuvieron anteriormente
         * autorSeleccionado, es el objeto Autor seleccionado en el paso anterior
         */
        Articulo articulo(titulo, detalle, dia, mes, anio, autorSeleccionado);
        publicacion.agregarArticulo(articulo);


        // Registro datos del articulo en un .txt
        // Formatear los datos del artículo como una cadena
        
        std::string datosArticulo = "Artículo " + std::to_string(articuloInicial + i + 1) + ":\n" +
                                    "Título: " + titulo + "\n" +
                                    "Detalle: " + detalle + "\n" +
                                    "Fecha: " + std::to_string(dia) + "/" + std::to_string(mes) + "/" + std::to_string(anio) + "\n" +
                                    "Autor: " + autorSeleccionado.getNombre() + " (DNI: " + std::to_string(autorSeleccionado.getDni()) + ")\n";

        // Registrar los datos en un archivo
        registrarDatos("registro_articulos.txt", datosArticulo);

    }
}

/*
 * 4. DESARROLLO DE FUNCIONES DEL MENU DE REGISTROS Y CONSULTAS
 */

// Autores registrados
void Desarrollo::registroDeAutores()
{
    std::cout << "Autores registrados:\n";
    for (size_t i = 0; i < autores.size(); ++i)
    {
        const Autor &autor = autores[i];
        std::cout << "Nombre: " << autor.getNombre() << ", DNI: " << autor.getDni() << ", Medio: " << autor.getMedio() << "\n";
    }
}

// Usuarios registrados
void Desarrollo::registroDeUsuarios()
{
    std::cout << "Usuarios registrados:\n";
    for (size_t i = 0; i < usuarios.size(); ++i)
    {
        const Usuario& usuario = usuarios[i];
        std::cout << "Nombre: " << usuario.getNombre() << ", DNI: " << usuario.getDni() << ", Edad: " << usuario.getEdad() << "\n";
    }
}

// Funcion para mostrar listas de usuarios disponibles
void Desarrollo::mostrarUsuarios() const
{
    std::cout << "Usuarios disponibles:\n";
    for (size_t i = 0; i < usuarios.size(); ++i)
    {
        std::cout << i + 1 << ". " << usuarios[i].getNombre() << " (DNI: " << usuarios[i].getDni() << ")\n";
    }
}

// Función para mostrar la lista de artículos realizados
void Desarrollo::mostrarArticulos() const
{
    std::cout << "Los artículos disponibles son:\n";
    // Despliegue de listas de articulos generados
    const std::vector<Articulo> &articulos = publicacion.getArticulos();
    for (size_t i = 0; i < articulos.size(); ++i)
    {
        std::cout << i + 1 << ". " << articulos[i].getTitulo() << " (Autor: " << articulos[i].getAutor().getNombre() << ")\n";
    }
}

// Función para pedir la fecha, para establecer las noticias del año, y del ultimo mes
void Desarrollo::pedirFecha(int &mes, int &anio)
{
    std::cout << "Ingrese el mes actual (especificar entre 1 - 12): ";
    std::cin >> mes;
    while (mes < 1 || mes > 12)
    {
        std::cout << "Seleccion de mes invalida. Debe ser entre 1 y 12: ";
        std::cin >> mes;
    }

    std::cout << "Ingrese el año actual: ";
    std::cin >> anio;
    while (anio < 1)
    {
        std::cout << "Seleccion de año invalida. Debe ser mayor a 0: ";
        std::cin >> anio;
    }
}

// Función para listar noticias publicadas en el último mes
void Desarrollo::listarNoticiasUltimoMes(int mes)
{
    int mesActual, anioActual;
    pedirFecha(mesActual, anioActual);

    std::cout << "Noticias publicadas en el último mes:\n";
    const std::vector<Articulo> &articulos = publicacion.getArticulos();
    for (size_t i = 0; i < articulos.size(); ++i)
    {
        const Articulo& articulo = articulos[i];
        if (articulo.getMes() == mesActual && articulo.getAnio() == anioActual)
        {
            std::cout << "- " << articulo.getTitulo() << "\n";
        }
    }
}

// Función para listar noticias publicadas en el año especificado
void Desarrollo::listarNoticiasAnio(int anio)
{
    std::cout << "Ingrese el año para filtrar las noticias realizadas: ";
    std::cin >> anio;

    std::cout << "Noticias publicadas en el año " << anio << ":\n";
    const std::vector<Articulo> &articulos = publicacion.getArticulos();
    for (size_t i = 0; i < articulos.size(); ++i)
    {
        const Articulo &articulo = articulos[i];
        if (articulo.getAnio() == anio)
        {
            std::cout << "- " << articulo.getTitulo() << "\n";
        }
    }
}

void Desarrollo::consultarArticulosPorAutor()
{
    if (autores.empty())
    {
        std::cout << "No hay autores registrados. No existen articulos realizados.\n";
        return;
    }

    std::cout << "Seleccione el autor para listar sus artículos:\n";
    for (size_t i = 0; i < autores.size(); ++i)
    {
        std::cout << i + 1 << ". " << autores[i].getNombre() << " (DNI: " << autores[i].getDni() << ")\n";
    }

    int indiceAutor;
    std::cin >> indiceAutor;

    if (indiceAutor < 1 || indiceAutor > autores.size())
    {
        std::cout << "Seleccion de autor invalida. Intente de nuevo con una seleccion valida.\n";
        return;
    }

    const Autor& autorSeleccionado = autores[indiceAutor - 1];

    std::cout << "Artículos realidados, propios del autor " << autorSeleccionado.getNombre() << ":\n";
    const std::vector<Articulo> &articulos = publicacion.getArticulos();
    for (size_t i = 0; i < articulos.size(); ++i)
    {
        const Articulo &articulo = articulos[i];
        if (articulo.getAutor().getDni() == autorSeleccionado.getDni())
        {
            std::cout << "- " << articulo.getTitulo() << "\n";
        }
    }
}

void Desarrollo::consultarComentariosPorUsuario()
{
    if (usuarios.empty())
    {
        std::cout << "No hay usuarios registrados. No existen comentarios realizados.\n";
        return;
    }

    std::cout << "Seleccione el usuario para listar sus comentarios:\n";
    mostrarUsuarios();

    int indiceUsuario;
    std::cin >> indiceUsuario;

    if (indiceUsuario < 1 || indiceUsuario > usuarios.size())
    {
        std::cout << "Índice de usuario no válido. Intente nuevamente.\n";
        return;
    }

    const Usuario &usuarioSeleccionado = usuarios[indiceUsuario - 1];

    std::cout << "Comentarios del usuario " << usuarioSeleccionado.getNombre() << ":\n";
    const std::vector<Articulo> &articulos = publicacion.getArticulos();
    for (size_t i = 0; i < articulos.size(); ++i)
    {
        const Articulo &articulo = articulos[i];
        const std::vector<Comentario> &comentarios = articulo.getComentarios();
        for (size_t j = 0; j < comentarios.size(); ++j)
        {
            const Comentario &comentario = comentarios[j];
            if (comentario.getUsuario().getDni() == usuarioSeleccionado.getDni())
            {
                std::cout << "- " << comentario.getTexto() << " (Artículo: " << articulo.getTitulo() << ")\n";
            }
        }
    }
}