// Tarea1_Hugo_Florián_1236521.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;
// Ejercicio 1:
// Recursivo
float prod(float x, float y)
{
	if (y == 0)
		return 0;
	else 
	{
		return x + prod(x, y - 1);
	}
}
//Iterativo
float prodit(float x, float y)
{
	float sum = 0;

	for (int i = 0; i < y; i++)
	{
		sum += x;
	}

	return sum;
}

//Ejercicio 2:
// Dentro de la carpeta de la solución se encuentra el archivo csv el
// puede modificarse para la opción 2;
//Recursiva
bool pal_recur(string palabra)
{
	if (palabra.length() < 2)
	{
		return true;
	}
	if (palabra[0] == palabra[palabra.length() - 1])
	{
		return pal_recur(palabra.substr(1, palabra.length() - 2));
	}

	return false;
}

bool pal_it(string palabra)
{
	size_t longitud = palabra.length() - 1;
	size_t i = 0;
	bool esPalindromo = true;

	for (i = 0; i < palabra.length() / 2 && esPalindromo; i++) {

		if (palabra[i] != palabra[longitud - i]) {
			esPalindromo = false;
		}
	}

	return esPalindromo;
}


//Lectura de CSV
int csv() 
{
	
	ifstream infile("EJE2.csv");
	string line = "";
	vector<string> datos_csv;

	while (getline(infile, line)) {
		stringstream strstr(line);
		string word = "";
		while (getline(strstr, word, ','))
		{
			datos_csv.push_back(word);
		}
	}

	int cont = 0;

	for (int i = 0; i < datos_csv.size(); i++)
	{
		if ((pal_recur(datos_csv.at(i))) == true)
		{
			cont++;
		}
	}

	return cont;
	
}

//Lectura de CSV
//Iterativa
int csv_It()
{

	ifstream infile("EJE2.csv");
	string line = "";
	vector<string> datos_csv;

	while (getline(infile, line)) {
		stringstream strstr(line);
		string word = "";
		while (getline(strstr, word, ','))
		{
			datos_csv.push_back(word);
		}
	}

	int cont = 0;

	for (int i = 0; i < datos_csv.size(); i++)
	{
		if ((pal_it(datos_csv.at(i)) == true))
		{
			cont++;
		}
	}

	return cont;

}



int main()
{
	int op;

	float n1, n2;

	do
	{
		system("cls");
		cout << "Ingrese la opcion\n";
		cout << "1. Producto de dos numeros\n";
		cout << "2. Comprobacion de palabras palindromas\n";
		cout << "3. Conversion de base \"m\" a base \"n\" \n";
		cout << "4. Salir \n";

		cin >> op;

		if (cin.fail())
		{
			cout << "Error de entrada\n";
			cin.clear();
			cin.ignore(numeric_limits<::streamsize>::max(), \
				'\n');
			system("PAUSE");
		}
		else
		{
			int contador_pal = 0;
			int contador_pal_it = 0;

			if ((op == 1) || (op == 2) || (op == 3) || (op == 4))
			{
				switch (op)
				{
				case 1:
					system("cls");
					cout << "Ingrese n1: "; cin >> n1; cout << "\n";
					cout << "Ingrese n2: "; cin >> n2; cout << "\n";

					if (n1 == false || n2 == false)
					{
						cout << "Error de entrada";
					}
					else
					{
						cout << "Recursiva:\n";
						cout << prod(n1, n2);
						cout << "\nIterativa:\n";
						cout << prodit(n1, n2)<<"\n";

						system("PAUSE");
					}
					break;
				case 2:
					contador_pal = csv();
					contador_pal_it = csv_It();
					cout << "Recursiva:\n";
					cout << contador_pal<<"\n";
					cout << "Iterativa:\n";
					cout << contador_pal_it << "\n";
					system("PAUSE");
				default:
					break;
				}
			}
			else
			{
				cout << "Opcion invalida";
			}
		}
		

	} while (op != 4);
    
}

