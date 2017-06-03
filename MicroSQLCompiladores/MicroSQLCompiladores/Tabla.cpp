#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Tabla.h"
void Tabla::limpiaBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}
Tabla::Tabla()
{
	pugi::xml_parse_result result = documento.load_file("file.xml");
	if (!result)
	{
		std::cout << "Creando archivo" << std::endl;
		pugi::xml_node decl = documento.prepend_child(pugi::node_declaration);
		decl.append_attribute("version") = "1.0";
		decl.append_attribute("encoding") = "UTF-8";
		decl.append_attribute("standalone") = "no";

		tabla = documento.append_child("tabla");

		pugi::xml_node defi = tabla.append_child("definicion");
		pugi::xml_node registros = tabla.append_child("registros");
		documento.save_file("file.xml");
	}
	if (result)
	{
		std::cout << "Archivo cargado" << std::endl;
		tabla = documento.first_child();
		pugi::xml_node defi = tabla.child("definicion");
		pugi::xml_attribute name;
		for (pugi::xml_node columna = defi.first_child(); columna; columna = columna.next_sibling())
		{
			name = columna.attribute("nombre");
			definicion.push_back((char*)name.value());
		}
	}
}
Tabla::~Tabla()
{
	documento.save_file("file.xml");
}
void Tabla::addColumna()
{
	std::string nombre;
	int size;
	std::cout << "Introduce nombre:";
	std::cin >> nombre;
	std::cout << "Introduce tamanio:";
	std::cin >> size;
	for (unsigned i = 0; i < definicion.size(); i++)
		if (strcmp(definicion[i].c_str(), nombre.c_str()) == 0){
			std::cout << "Columna existente " << definicion[i] << std::endl;
			return;
		}
	definicion.push_back(nombre);

	pugi::xml_node defi = tabla.first_child();

	pugi::xml_node columna = defi.append_child("columna");

	pugi::xml_attribute cname = columna.append_attribute("nombre");
	pugi::xml_attribute csize = columna.append_attribute("size");

	pugi::xml_node registros = tabla.child("registros");
	for (pugi::xml_node registro = registros.first_child(); registro; registro = registro.next_sibling())
	{
		pugi::xml_attribute atributo = registro.append_attribute(nombre.c_str());
		atributo.set_value("");
	}
	cname.set_value(nombre.c_str());
	csize.set_value(size);
	save();
}
int Tabla::getNumeroColumnas()
{
	return definicion.size();
}
bool Tabla::removeColumna(char * nombre)
{
	pugi::xml_node defi = tabla.first_child();
	pugi::xml_attribute name;
	int i = 0;
	for (auto x : definicion)
	{
		if (strcmp(x.c_str(), nombre) == 0)
		{
			definicion.erase(definicion.begin() + i);
			for (pugi::xml_node columna = defi.first_child(); columna; columna = columna.next_sibling())
			{
				name = columna.attribute("nombre");
				if (strcmp(nombre, name.value()) == 0)
				{
					defi.remove_child(columna);
					save();
					return true;
				}
			}
		}
		i++;
	}
	return false;
}
void Tabla::insertarRegistro()
{
	if (definicion.size() != 0)
	{
		int i = 0;
		char dest[10];
		pugi::xml_node registros = tabla.child("registros");
		for (pugi::xml_node registro = registros.first_child(); registro; registro = registro.next_sibling())
			i++;
		pugi::xml_node registro = registros.append_child("registro");
		std::string valor;
		for (auto x : definicion)
		{
			//limpiaBuffer();
			std::cout << "Inserta " << x << ":" << std::endl;
			std::cin >> valor;
			limpiaBuffer();
			pugi::xml_attribute atributo = registro.append_attribute(x.c_str());
			atributo.set_value(valor.c_str());
		}
		i++;
		std::sprintf(dest, "%d", i);
		registro.append_child(pugi::node_pcdata).set_value(dest);
		save();
	}else
		std::cout << "No hay atributos para generar un registro";
}
bool Tabla::modificiarRegistro(int id, char * columna)
{
	bool existe = false;
	for (auto x : definicion)
	{
		if (strcmp(x.c_str(), columna) == 0)
			existe = true;
	}
	pugi::xml_node registros = tabla.child("registros");
	for (pugi::xml_node registro = registros.first_child(); registro; registro = registro.next_sibling())
	{
		if (atoi(registro.child_value()) == id)
		{
			std::string valor;
			limpiaBuffer();
			std::cout << "Introduce " << columna << ":" << std::endl;
			std::cin >> valor;
			limpiaBuffer();
			registro.attribute(columna).set_value(valor.c_str());
			save();
			return existe;
		}
	}
	return existe;
}
bool Tabla::removeRegistro(int id)
{
	pugi::xml_node registros = tabla.child("registros");
	for (pugi::xml_node registro = registros.first_child(); registro; registro = registro.next_sibling())
	{
		if (atoi(registro.child_value()) == id)
		{
			registros.remove_child(registro);
			save();
			return true;
		}
	}
	return false;
}
void Tabla::consultarRegistro(int id)
{
	pugi::xml_node registros = tabla.child("registros");
	for (pugi::xml_node registro = registros.first_child(); registro; registro = registro.next_sibling())
	{
		if (atoi(registro.child_value()) == id)
		{
			for (auto x : definicion)
				std::cout << x << ": " << registro.attribute(x.c_str()).value() << " ";
			return;
		}
	}
	std::cout << "No se encontro el registro" << std::endl;
}
void Tabla::desplegarListaColumnas()
{
	if (definicion.size() == 0)
		std::cout << "No hay columnas" << std::endl;
	for (auto x : definicion)
	{
		std::cout << "Nombre columna: " << x << std::endl;
	}

}
void Tabla::desplegarRegistros()
{
	int i = 0;
	pugi::xml_node registros = tabla.child("registros");
	for (pugi::xml_node registro = registros.first_child(); registro; registro = registro.next_sibling())
	{
		std::cout << "Numero de registro: " << registro.child_value() << "\n";
		for (auto x : definicion)
			std::cout << x << ": " << registro.attribute(x.c_str()).value() << "\n";
		std::cout << std::endl;
		i++;
	}
	std::cout << i << " Registros mostrados" << std::endl;
}
bool Tabla::save()
{
	return documento.save_file("file.xml");
}