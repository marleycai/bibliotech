#include <iostream>
#include <cstring>

//FOR UUID:
#include <random>
#include <sstream>

//https://www.w3.org/Style/CSS/postprocessor/
#include "parseform.c"

using namespace std;

//Namespace and function for UUID creation 
//https://stackoverflow.com/questions/24365331/how-can-i-generate-uuid-in-c-without-using-boost-library
namespace uuid 
{
    static std::random_device              rd;
    static std::mt19937                    gen(rd());
    static std::uniform_int_distribution<> dis(0, 15);
    static std::uniform_int_distribution<> dis2(8, 11);

    std::string generate_uuid_v4() 
    {
        std::stringstream ss;
        int i;
        ss << std::hex;
        for (i = 0; i < 8; i++) 
        {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 4; i++) 
        {
            ss << dis(gen);
        }
        ss << "-4";
        for (i = 0; i < 3; i++) 
        {
            ss << dis(gen);
        }
        ss << "-";
        ss << dis2(gen);
        for (i = 0; i < 3; i++) 
        {
            ss << dis(gen);
        }
        ss << "-";
        for (i = 0; i < 12; i++) 
        {
            ss << dis(gen);
        };
        return ss.str();
    }
}

int main(void)
{
    /*Se imprime cómo exige el estándar HTTP dos retornos de carro después 
    de la cabecera con el tipo de contenido y juego de caracteres UTF8 para 
    la correcta visualización de una respuesta en texto
    */
    std::cout << "Content-Type:text/plain;charset=utf-8\n\n";
    
    /*Se aplica el parser de la W3C a la entrada estandar que es lo que enviamos por
        POST desde el Frontend con html y javascript.
        Se pasa cómo parámetro la ruta al directorio donde se subiran los archivos pdf
        y se usa un identificador único universal para nombrar cada pdf
    */
    string file_path = "./uploaded_files/" + uuid::generate_uuid_v4(); 
    char* c_file_path = (char*)file_path.c_str();

    if (upload(c_file_path))
    {
        cout << "Su archivo se subió correctamente, ¡muchas gracias!";
    }
    else
    {
        cout << "Su archivo no pudo subirse, disculpe las molestias";
    }
    
    return 0;
}
