#ifndef TABLA_H
#define TABLA_H

#include"pugixml.hpp"
#include<vector>
#include<map>
#include<iostream>
#include<string>

struct _registro
{
	/*Registro Vacio*/
	_registro() {}
	/*Recibe dos str::vector<std::string> uno para el nombre de atributos y el segundo
	para los valores de los atributos*/
	_registro(std::vector<std::string> attrib, std::vector<std::string> valor) { generateRegistro(attrib, valor); }
	/*La llave es el atributo y el valor el valor*/
	std::map<std::string, std::string> atributo_valor;
	/*Id dentro del xml*/
	int id;
	void generateRegistro(std::vector<std::string> attrib, std::vector<std::string> valor)
	{
		if (attrib.size() != valor.size())
		{
			std::cout << "Faltan parametros" << std::endl;
			return;
		}
		for (unsigned i = 0; i < attrib.size(); i++)
		{
			atributo_valor.insert(std::pair<std::string, std::string>(attrib[i], valor[i]));
		}
	}
};

typedef _registro str_registro;


class Tabla
{
private:
	pugi::xml_document documento;
	pugi::xml_node tabla;
	std::string nombreTabla;
	std::string nombreArchivo;
	std::vector<std::string> definicion;
	void limpiaBuffer();
	bool existColumns(std::vector<std::string> nombre_atributos);
	std::vector<std::string> getAttributeNames(str_registro busqueda);
public:
	/*Crea una nueva tabla con un nombre especificado*/
	Tabla();
	Tabla(std::string nombre);
	~Tabla();
	/*Leer tabla*/
	int leerTabla(std::string nombre);
	/*Agrega una nueva columna*/
	void addColumna(std::string nombre, int size);
	/*Elimina la columna especificada*/
	bool removeColumna(std::string nombre);
	/*/Muestra en pantalla las columnas*/
	void desplegarListaColumnas();
	/*Devuelve el numero de columnas*/	
	int getNumeroColumnas();
	/*Modifica el xml con los valores de str_registro.atributo_valor donde el id sea igual a str_registro.id
	en caso de error retorna false*/
	bool modificiarRegistro(str_registro busqueda);
	/*Elimina del xml todos los registros que cumplan con las caracteristicas del str_registro especificado
	en caso de error retorna false*/
	bool removeRegistro(str_registro busqueda);
	/*Devuelve los registros que cumplen con las caracteristicas
	del str_registro usado en caso de no existir el registro retorna un std::vector vacio*/
	std::vector<str_registro> consultarRegistro(str_registro busqueda);
	/*Trae todos los registros del xml*/
	std::vector<str_registro> leerRegistros();
	/*Inserta un registro con los valores de str_registro.atributo_valor donde las columnas
	son las llaves del std::map y los valores el valor retorna false ne caso de error*/
	bool insertarRegistro(str_registro insertar);
	/*Obtiene los nombres de las columnas como un std::vector<std::string>*/
	std::vector<std::string> getColumnas();
	/*Guarda la tabla*/
	bool save();
	/*Obtiene el nombre de la tabla como un std::string*/
	std::string getTableName();
};
#endif //TABLA_H
