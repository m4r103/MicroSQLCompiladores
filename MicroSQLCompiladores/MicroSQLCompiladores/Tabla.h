#ifndef TABLA_H
#define TABLA_H

#include"pugixml.hpp"
#include<vector>
#include<map>
#include<iostream>
#include<string>

struct _registro
{
	std::map<std::string, std::string> atributo_valor; //La llave es el atributo
	int id;
};

typedef _registro str_registro;

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
	~Tabla();
	void addColumna(std::string nombre, int size);
	bool removeColumna(std::string nombre);
	void desplegarListaColumnas();
	int getNumeroColumnas();
	bool modificiarRegistro(str_registro busqueda);
	bool removeRegistro(str_registro busqueda);
	std::vector<str_registro> consultarRegistro(str_registro busqueda);
	std::vector<str_registro> leerRegistros();
	bool insertarRegistro(str_registro insertar);
	std::vector<std::string> getColumnas();
	bool save();
};
#endif //TABLA_H
