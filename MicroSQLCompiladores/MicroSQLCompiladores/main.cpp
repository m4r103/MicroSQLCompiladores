
#include<iostream>
#include<vector>
#include<cstring>
#include"Tabla.h"

void limpiar()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}
void operacionesColumnas(Tabla &nueva){
	int op;
	do
	{
		std::cout << "\n1:agregar columna\n2:mostrar columnas\n3:eliminar columna\nCualquier otro valor para salir\n";
		std::cin >> op;
		limpiar();
		switch (op)
		{
		case 1:
			nueva.addColumna();
			break;
		case 2:
			nueva.desplegarListaColumnas();
			break;
		case 3:
			char nombre[20];
			std::cout << "\nIntroduce nombre de columna\n";
			gets_s(nombre);
			if(nueva.removeColumna(nombre))
				std::cout << "Columna eliminada\n";
			else
				std::cout << "No se encontro la columna\n";
		default:
			break;
		}
		std::cout << "\n";
	} while (op>0 && op<4);
}
int main()
{
	Tabla nueva;
	int i = 0;
	int reg;
	std::cout << "Proyecto de Bases de datos SGBD general" << std::endl;
	do
	{
		std::cout << "1: operacines para atributos\n2: insertar registro\n3:desplegar registros\n"
			<< "4:modificar registro\n5:consultar registro\n6:eliminar registro\n7:salir\n";
		std::cin >> i;
		limpiar();
		switch (i)
		{
		case 1:
			operacionesColumnas(nueva);
			std::cout << "\n";
			break;
		case 2:
			nueva.insertarRegistro();
			break;
		case 3:
			nueva.desplegarRegistros();
			break;
		case 4:
			char nombre[20];
			std::cout << "Atributo a cambiar: ";
			gets_s(nombre);
			std::cout << "Numero de registro: ";
			std::cin >> reg;
			if(nueva.modificiarRegistro(reg,nombre))
				std::cout << "Registro modificado";
			else
				std::cout << "No se encontro el registor a midificar o el atributo no existe";
			break;
		case 5:
			std::cout << "Numero de registro: ";
			std::cin >> reg;
			nueva.consultarRegistro(reg);
			break;
		case 6:
			std::cout << "Numero de registro: ";
			std::cin >> reg;
			if(nueva.removeRegistro(reg))
				std::cout << "Registro eliminado ";
			else
				std::cout << "No se encontro el registro ";
			break;
		case 7:
			break;
		default:
			std::cout << "Opcion no valida" << std::endl;
		}std::cout << "\n";
	} while (i != 7);
	system("pause");
	return 0;
}
