// Xènia Jordán Torres - DynamicArray exercise.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

#include <iostream>
using namespace std;

class array_classe {
private:
    int mida = 0;
    int* array;
public:
    array_classe() : mida(0), array(nullptr) {}

    void ordenar_array(int num)
    {
        int* array_nova; //creem una array
        array_nova = new int[mida + 1]; //li assignem una mida dinàmica que serà sempre de mida + 1 (anirà creixent)

        int i = 0;
        int j = 0; //necessitem 2 iteradors perquè hem de controlar 2 arrays diferents ja que recordem, que la nova array conté un nou número

        while (i < mida && array[i] < num) { //el bucle ha de recorrer tot l'array i només copiarà els elements que siguin més petits que el número inserit per l'usuari
            array_nova[j] = array[i]; //passem els elements a la nova array
            i++;
            j++;
        }

        array_nova[j] = num; //ara inserim el número
        j++;

        while (i < mida) { //alerta! ENCARA ENS QUEDEN NÚMEROS PER POSAR (els que són més grans) 
            array_nova[j] = array[i]; //els col·locarem aquí 
            i++;
            j++;
        }

        delete[] array;
        array = array_nova;
        mida++; //HEM D'ACTUALITZAR LA MIDA PERQUÈ L'HEM FET CRÈIXER A +1
    }

    void imprimir_array()
    {
        for (int i = 0; i < mida; i++)
        {
            cout << "[" << array[i] << "]";
        }
        cout << endl;
    }

    ~array_classe() //destruim la classe un cop hem acabat d'usar-la
    {
        delete[] array;
    }
};


int main()
{
    array_classe array_main; //objecte de la classe
    int num;
    
    while (true)
    {
        
        cout << "Escriu un num\n";
        cin >> num;
        cout << endl;
        array_main.ordenar_array(num);
        array_main.imprimir_array();
        

    }
}
