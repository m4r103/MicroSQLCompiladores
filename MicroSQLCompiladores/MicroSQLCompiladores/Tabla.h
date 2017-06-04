#ifndef TABLA_H
#define TABLA_H

#include"pugixml.hpp"
#include<vector>
#include<map>
#include<iostream>
#include<string>

struct _registro
{
	/*La llave es el atributo y el valor el valor*/
	std::map<std::string, std::string> atributo_valor; 
	/*Id dentro del xml*/
	int id;
};

typedef _registro str_registro;

typedef std::vector<str_registro> register_collection;

class Tabla
{
private:
	pugi::xml_document documento;
	pugi::xml_node tabla;
	std::vector<std::string> definicion;
	void limpiaBuffer();
	bool existColumns(std::vector<std::string> nombre_atributos);
	std::vector<std::string> getAttributeNames(str_registro busqueda);
public:
	Tabla();
	/*Crea una nueva tabla con un nombre especificado*/
	Tabla(std::string nombre);
	~Tabla();
	/*Agrega una nueva columna*/
	void addColumna(std::string nombre, int size);
	/*Elimina la columna especificada*/
	bool removeColumna(std::string nombre);
	/*/Muestra en pantalla las columnas*/
	void desplegarListaColumnas();
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
	bool save();
};
#endif //TABLA_H
