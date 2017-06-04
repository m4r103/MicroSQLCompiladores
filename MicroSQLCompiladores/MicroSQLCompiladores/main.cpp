
#include<iostream>
#include<cstring>
#include"Tabla.h"


int main()
{
	Tabla miTabla("datos");
	miTabla.addColumna("Nombre", 50);
	miTabla.addColumna("Apellido", 50);
	miTabla.addColumna("Telefono", 10);

	str_registro miRegistro;

	miRegistro.atributo_valor.insert(std::pair <std::string, std::string> ("Nombre", "Orange"));
	miRegistro.atributo_valor.insert(std::pair <std::string, std::string> ("Apellido", "Pekoe"));
	miRegistro.atributo_valor.insert(std::pair <std::string, std::string> ("Telefono", "55555"));

	miTabla.insertarRegistro(miRegistro);

	str_registro miRegistro2;

	miRegistro2.atributo_valor.insert(std::pair <std::string, std::string> ("Nombre", "Maria"));
	miRegistro2.atributo_valor.insert(std::pair <std::string, std::string> ("Apellido", "Kajiura"));
	miRegistro2.atributo_valor.insert(std::pair <std::string, std::string> ("Telefono", "7777777"));

	miTabla.insertarRegistro(miRegistro2);

	std::vector<str_registro> registros = miTabla.consultarRegistro(miRegistro);

	std::vector<std::string> atributos = miTabla.getColumnas();
	for (auto& x : atributos)
	{
		std::cout << x << std::endl;
	}

	for (auto& x : registros)
	{
		for(auto y : x.atributo_valor)
			std::cout << y.first << " : " << y.second << std::endl;
	}

	system("pause");
	return 0;
}
