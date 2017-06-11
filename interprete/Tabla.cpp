//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif

#include "Tabla.h"
void Tabla::limpiaBuffer()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

Tabla::Tabla()
{
	this->nombreArchivo ="";
	this->nombreTabla = "";
}
/*Crea una nueva tabla con un nombre especificado*/
Tabla::Tabla(std::string nombre)
{
	this->nombreTabla = nombre;
	nombre += ".xml";
	this->nombreArchivo = nombre;
	pugi::xml_parse_result result = this->documento.load_file(nombre.c_str());
	if (!result)
	{
		// std::cout << "Creando archivo" << std::endl;
		pugi::xml_node decl = this->documento.prepend_child(pugi::node_declaration);
		decl.append_attribute("version") = "1.0";
		decl.append_attribute("encoding") = "UTF-8";
		decl.append_attribute("standalone") = "no";

		this->tabla = this->documento.append_child("tabla");

		pugi::xml_node defi = this->tabla.append_child("definicion");
		pugi::xml_node registros = this->tabla.append_child("registros");
		this->documento.save_file(nombre.c_str());
	}
	if (result)
	{
		// std::cout << "Archivo cargado" << std::endl;
		this->tabla = this->documento.first_child();
		pugi::xml_node defi = this->tabla.child("definicion");
		pugi::xml_attribute name;
		for (pugi::xml_node columna = defi.first_child(); columna; columna = columna.next_sibling())
		{
			name = columna.attribute("nombre");
			this->definicion.push_back((char*)name.value());
		}
	}
}

int Tabla::leerTabla(std::string nombre)
{
	this->nombreTabla = nombre;
	nombre += ".xml";
	this->nombreArchivo = nombre;
	/*Modo lectura*/
	int status = 1;
	pugi::xml_parse_result result = this->documento.load_file(nombre.c_str());
	if (result)
	{
		// std::cout << "Archivo cargado" << std::endl;
		this->tabla = this->documento.first_child();
		pugi::xml_node defi = this->tabla.child("definicion");
		pugi::xml_attribute name;
		for (pugi::xml_node columna = defi.first_child(); columna; columna = columna.next_sibling())
		{
			name = columna.attribute("nombre");
			this->definicion.push_back((char*)name.value());
		}
	}
	else
		status = 0;
	return status;
}


Tabla::~Tabla()
{
	//this->documento.save_file(this->nombreArchivo.c_str());
}
/*Agrega una nueva columna*/
void Tabla::addColumna(std::string nombre, int size)
{

	for (unsigned i = 0; i < this->definicion.size(); i++)
		if (nombre == this->definicion[i]) {
			std::cout << "Columna existente " << this->definicion[i] << std::endl;
			return;
		}
	this->definicion.push_back(nombre);

	pugi::xml_node defi = this->tabla.first_child();

	pugi::xml_node columna = defi.append_child("columna");

	pugi::xml_attribute cname = columna.append_attribute("nombre");
	pugi::xml_attribute csize = columna.append_attribute("size");

	pugi::xml_node registros = this->tabla.child("registros");
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
	return this->definicion.size();
}
/*Elimina la columna especificada*/
bool Tabla::removeColumna(std::string nombre)
{
	pugi::xml_node defi = this->tabla.first_child();
	pugi::xml_attribute name;
	int i = 0;
	for (auto x : this->definicion)
	{
		if (x == nombre)
		{
			this->definicion.erase(this->definicion.begin() + i);
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
	return this->definicion;
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
	if (this->definicion.size() == 0)
	{
		std::cout << "No existen columnas";
		return false;
	}
	int i = 0;
	/*Buscamos el ultimo registro y su id*/
	pugi::xml_node registros = this->tabla.child("registros");
	for (pugi::xml_node registro : registros.children())
	{
		int lastReg = std::atoi(registro.child_value());
		if (i < lastReg)
			i = lastReg;
	}
	/*Creamos el nodo */
	pugi::xml_node registro = registros.append_child("registro");
	for (auto x : this->definicion)
	{
		/*Cargamos las columnas al nodod como atributos*/
		registro.append_attribute(x.c_str());
	}
	/*Cargamos los valores en las columnas deseadas*/
	for (auto x : insertar.atributo_valor)
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
	pugi::xml_node registros = this->tabla.child("registros");
	for (pugi::xml_node registro : registros.children())
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
	pugi::xml_node registros = this->tabla.child("registros");
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

	if (aux.size() <= 0)
		return ret;

	bool flag = true;

	for (str_registro registro : aux)
	{
		std::map<std::string, std::string> y = registro.atributo_valor;
		for (auto x : busqueda.atributo_valor)
		{
			if (y.at(x.first) != x.second)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ret.push_back(registro);
		flag = true;
	}
	return ret;
}

/*Trae todos los registros del xml*/
std::vector<str_registro> Tabla::leerRegistros()
{
	std::vector<str_registro> ret;

	str_registro aux;
	pugi::xml_node regisros = tabla.child("registros");
	for (pugi::xml_node registro = regisros.first_child(); registro; registro = registro.next_sibling())
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
	{
		ret.push_back(x.first);
	}
	return ret;
}
/*Verifica la existencia de los atributos*/
bool Tabla::existColumns(std::vector<std::string> nombre_atributos)
{
	if (nombre_atributos.size() <= 0)
		return false;
	int i = 0;
	for (auto x : nombre_atributos)
	{
		for (auto y : this->definicion)
		{

			if (x == y)
			{
				i++;
				break;
			}
		}
	}
	if (i == nombre_atributos.size())
		return true;
	return false;
}
/*Muestra en pantalla las columnas*/
void Tabla::desplegarListaColumnas()
{
	if (this->definicion.size() == 0)
		std::cout << "No hay columnas" << std::endl;
	for (auto x : this->definicion)
	{
		std::cout << "Nombre columna: " << x << std::endl;
	}

}

/*Obtiene el nombre de la tabla como un std::string*/
std::string Tabla::getTableName()
{
	return this->nombreTabla;
}

bool Tabla::save()
{
	return this->documento.save_file(this->nombreArchivo.c_str());
}