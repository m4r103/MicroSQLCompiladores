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
/*Crea una nueva tabla con un nombre especificado*/
Tabla::Tabla(std::string nombre)
{
	nombre += ".xml";
	pugi::xml_parse_result result = documento.load_file(nombre.c_str());
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
/*Agrega una nueva columna*/
void Tabla::addColumna(std::string nombre, int size)
{

	for (unsigned i = 0; i < definicion.size(); i++)
		if (nombre == definicion[i]) {
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
/*Obtiene el numero de columnas*/
int Tabla::getNumeroColumnas()
{
	return definicion.size();
}
/*Elimina la columna especificada*/
bool Tabla::removeColumna(std::string nombre)
{
	pugi::xml_node defi = tabla.first_child();
	pugi::xml_attribute name;
	int i = 0;
	for (auto x : definicion)
	{
		if (x == nombre)
		{
			definicion.erase(definicion.begin() + i);
			for (pugi::xml_node columna = defi.first_child(); columna; columna = columna.next_sibling())
			{
				name = columna.attribute("nombre");
				if (nombre == name.value())
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
/*Obtiene los nombres de las columnas como un std::vector<std::string>*/
std::vector<std::string> Tabla::getColumnas()
{
	return definicion;
}

/*Inserta un registro con los valores de str_registro.atributo_valor donde las columnas
son las llaves del std::map y los valores el valor*/
bool Tabla::insertarRegistro(str_registro insertar)
{
	if (!existColumns(getAttributeNames(insertar)))
	{
		std::cout << "Error de columnas";
		return false;
	}
	if (definicion.size() == 0)
	{
		std::cout << "No existen columnas";
		return false;
	}
	int i = 0;
	/*Buscamos el ultimo registro y su id*/
	for (pugi::xml_node registro : tabla.children("registros"))
	{
		int lastReg = std::atoi(registro.child_value());
		if (i < lastReg)
			i = lastReg;
	}
	pugi::xml_node registros = tabla.child("registros");
	/*Creamos el nodo */
	pugi::xml_node registro = registros.append_child("registro");
	for (auto x : definicion)
	{
		/*Cargamos las columnas al nodod como atributos*/
		pugi::xml_attribute atributo = registro.append_attribute(x.c_str());
	}
	/*Cargamos los valores en las columnas deseadas*/
	for(auto x: insertar.atributo_valor)
		registro.attribute(x.first.c_str()).set_value(x.second.c_str());
	/*Escribismos el ID*/
	char dest[10];
	i++;
	std::sprintf(dest, "%d", i);
	registro.append_child(pugi::node_pcdata).set_value(dest);
	/*Guardamos el xml*/
	save();
	return true;
}
/*Modifica el xml con los valores de str_registro.atributo_valor donde el id sea igual a str_registro.id*/
bool Tabla::modificiarRegistro(str_registro busqueda)
{
	if (!existColumns(getAttributeNames(busqueda)))
		return false;
	for (pugi::xml_node registro : tabla.child("registros"))
	{
		if (std::atoi(registro.child_value()) == busqueda.id)
			for (auto x : busqueda.atributo_valor)
			{
				registro.attribute(x.first.c_str()).set_value(x.second.c_str());
			}
	}
	return true;
}

/*Elimina del xml todos los registros que cumplan con las caracteristicas del str_registro especificado*/
bool Tabla::removeRegistro(str_registro busqueda)
{
	if (!existColumns(getAttributeNames(busqueda)))
		return false;
	std::vector<str_registro> aux = consultarRegistro(busqueda);
	if (aux.size() <= 0)
		return false;
	pugi::xml_node registros = tabla.child("registros");
	for (auto x : aux)
	{
		for (pugi::xml_node registro = registros.first_child(); registro; registro = registro.next_sibling())
		{
			if (std::atoi(registro.child_value()) == x.id)
			{
				registros.remove_child(registro);
				save();
				break;
			}
		}
	}
	return true;
}

/*Devuelve los registros que cumplen con las caracteristicas
del str_registro usado*/
std::vector<str_registro> Tabla::consultarRegistro(str_registro busqueda)
{
	std::vector<str_registro> aux = leerRegistros();
	std::vector<str_registro> ret;

	for (str_registro registro : aux)
	{
		auto y = registro.atributo_valor;
		for (auto x : busqueda.atributo_valor)
		{
			if (y.at(x.first) != x.second)
				continue;
		}
		ret.push_back(registro);
	siguiente_registro:
	}
	return ret;
}

/*Trae todos los registros del xml*/
std::vector<str_registro> Tabla::leerRegistros()
{
	std::vector<str_registro> ret;

	str_registro aux;
	for (pugi::xml_node registro : tabla.children("registros"))
	{
		aux.atributo_valor.clear();
		for (pugi::xml_attribute attr : registro.attributes())
		{
			aux.atributo_valor.insert(std::pair<std::string, std::string>(attr.name(), attr.value()));
		}
		aux.id = std::atoi(registro.child_value());
		ret.push_back(aux);
	}
	return ret;
}
/*Extrae los nombres de los atribuso de un registro y los devuelve como un vector de cadenas*/
std::vector<std::string> Tabla::getAttributeNames(str_registro busqueda)
{
	std::vector<std::string> ret;
	for (auto x : busqueda.atributo_valor)
		ret.push_back(x.first);
	return ret;
}
/*Verifica la existencia de los atributos*/
bool Tabla::existColumns(std::vector<std::string> nombre_atributos)
{
	if (nombre_atributos.size() <= 0)
		return false;
	int i = 0;
	for (auto x : nombre_atributos)
		for (auto y : definicion)
			if (x == y)
				i++;
	if (i == nombre_atributos.size())
		return true;
	return false;
}
/*Muestra en pantalla las columnas*/
void Tabla::desplegarListaColumnas()
{
	if (definicion.size() == 0)
		std::cout << "No hay columnas" << std::endl;
	for (auto x : definicion)
	{
		std::cout << "Nombre columna: " << x << std::endl;
	}

}

bool Tabla::save()
{
	return documento.save_file("file.xml");
}