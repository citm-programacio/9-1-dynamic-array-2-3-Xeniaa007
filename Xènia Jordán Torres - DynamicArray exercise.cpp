// Xènia Jordán Torres - DynamicArray exercise.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

//Estructura de la solució:
//1. Crear una classe que contingui una array, la mida de la array i la capacitat del array
//2. Crear un constructor per inicialitzar totes les variables
//3. Crear una funció void amb un bucle for que inverteixi l'ordre, haurem de crear una nova array amb new li haurem de dir al bucle que comenci per size-1 (pel final) i llavors aquest nou número ha d'anar a parar a aquesta nova array.
//4. Caldrà fer un print de la array
//5. L'haurem de borrar amb delete la vella
//6. En el main haurem de crear un objecte de la classe
//7. Cridarem la funció amb l'objecte creat.

#include <iostream>
using namespace std;

class array_class {
private:
	int mida = 0;
	int capacitat = 10;
	int* array;


public:
	array_class() : mida(0), capacitat(0), array(nullptr) { //constructor per defecte
		array = new int[capacitat];
	}

	array_class(int m) : mida(m), capacitat(10) {
		array = new int [capacitat];
		for (int i = 0; i < mida; i++) {
			array[i] = i + 1; //afegim valors a l'array, el primer serà 1, perquè la i = 0, i 0+1 = 1, el dos serà 1+1=2, el 3, 2+1 = 3, etc . . .
		}
	}

	~array_class() {
		delete[] array;
	}

	void reverse_array()
	{
		int* array_nova = new int[mida];
		for (int i = 0; i < mida; i++)
		{
			array_nova[i] = array[mida - i - 1]; //comencem per la mida i li anem restant -1 a cada posició, d'aquesta manera la llegim del revés
		}

		for (int i = 0; i < mida; i++) 
		{
			array[i] = array_nova[i]; //tots els valors girats els passem a la array de la classe
		}

		delete[] array_nova; //com que ja hem fet totes les operacions i no la necessitem més la borrem de la memòria dinàmica
	}

	void imprimir_array()
	{
		for (int i = 0; i < mida; i++)
		{
			cout << "[" << array[i] << "]" << endl;
		}
	}

};


int main()
{

	array_class array_inventada(10); //creem un objecte de la classe AMB UNA MIDA EN CONCRET

	cout << "Array original: " << endl;
	array_inventada.imprimir_array();

	cout << "Invertint l'array . . . . " << endl;
	array_inventada.reverse_array();

	cout << "Resultat final: " << endl;
	array_inventada.imprimir_array();
}