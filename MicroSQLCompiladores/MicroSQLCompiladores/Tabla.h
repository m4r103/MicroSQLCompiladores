#ifndef TABLA_H
#define TABLA_H

#include"pugixml.hpp"
#include<vector>
#include<iostream>
class Tabla
{
private:
	pugi::xml_document documento;
	pugi::xml_node tabla;
	std::vector<std::string> definicion;
	void limpiaBuffer();
public:
	Tabla();
	~Tabla();
	void addColumna();
	bool removeColumna(char * nombre);
	void desplegarListaColumnas();
	int getNumeroColumnas();
	bool modificiarRegistro(int id, char * columna);
	bool removeRegistro(int id);
	void consultarRegistro(int id);
	void desplegarRegistros();
	void insertarRegistro();
	bool save();
};
#endif //TABLA_H
