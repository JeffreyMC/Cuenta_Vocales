#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//PROTOTIPOS DE FUNCIONES
void leerCadenas(string []);
void contarVocales(char *);
void masVocales(string []);
void menosVocales(string []);
void listaPalabras(string []);
void menu(string []);

//VARIABLES GLOBALES PARA LLEVAR EL CONTEO DE VOCALES POR ÍNDICE
int cont = 0; //Variable global para contar las veces que se llama la funcion contarVocales
int frecuencia[10] = {0};

int main()
{
    string cadena[10];  //crea un arreglo de tipo string con 10 posiciones

    menu(cadena);

    system("pause");
    return 0;
}

//fUNCION QUE MUESTRA EL MENU
void menu(string cadena[])
{
    leerCadenas(cadena);

    int opcion;

    do
    {
    cout << "\n***Bienvenido al menu de cuenta vocales***"<< endl;
    cout << "Por favor ingrese la opcion que desea realizar" << endl << endl;
    cout << "1. Ver cadena con mas vocales\n"
         << "2. Ver cadena con menos vocales\n"
         << "3. Salir\n";
    cin >> opcion;

    //LLAMA A OTRAS FUNCIONES DEPENDE DE LA ELECCION DEL USUARIO
    switch(opcion)
    {
        case 1: masVocales(cadena);
                break;
        case 2: menosVocales(cadena);
                break;
        case 3: cout <<"\nFINALIZANDO PROGRAMA...\n";
                break;
        default: cout <<"\nNO ingreso una opcion valida, intentelo de nuevo" << endl;
                break;
    }
}
    while(opcion != 3);

}

//ESTA FUNCION LEE DIEZ CADENAS STRING
void leerCadenas(string cadena[])
{
    //se crea el archivo Palabras.txt
    ofstream salida("Palabras.txt");

    char palabra[80]; //variable char temporal para las cadenas string
    cout << "Por favor introduzca 10 cadenas de caracteres: " << endl;
    for(int i = 0; i<10; i++)
    {
        cout << i+1 << ": ";
        cin.getline(palabra, 80);
        cadena[i] = palabra; //Pasa la cadena ingresada al arreglo string
        contarVocales(palabra); //llama a la funcion contarVocales y le pasa la variable temporal
        salida << palabra << endl;   //Escribe la palabra en el archivo Palabras.txt
    }

    salida.close(); //cierra el archivo
}

//FUNCION PARA CONTAR LAS VOCALES
void contarVocales(char *cadena)
{
    //lee cada caracter hasta llegar a \0
    while(*cadena)
    {
        switch(*cadena)
        {
        case 'A':
        case 'a':
            frecuencia[cont]++;
            break;
        case 'E':
        case 'e':
            frecuencia[cont]++;
            break;
        case 'I':
        case 'i':
            frecuencia[cont]++;
            break;
        case 'O':
        case 'o':
            frecuencia[cont]++;
            break;
        case 'U':
        case 'u':
            frecuencia[cont]++;
            break;
        }
        cadena++; //continua con el caracter siguiente de la cadena
    }//fin del while externo

    cont++; // se incrementa la variable global
}

//DETERMINA CUAL CADENA TIENE MAS VOCALES Y LA ESCRIBE EN UN ARCHIVO
void masVocales(string cadena[])
{
    system("cls"); // Limpia la pantalla
    int mayor = frecuencia[0];
    int place = 0;

    //Busca el índice que tiene mas vocales
    for(int i = 0; i<9; i++)
    {
        if(frecuencia[i+1] > mayor)
        {
            mayor = frecuencia[i+1];
            place = i+1; // índice donde se encuentra la cadena con mas vocales
        }
    }

    //se crea el archivo Muchas.txt
    ofstream salida("Muchas.txt");
    salida << cadena[place];
    salida.close();

        //Muestra en pantalla
    cout << "\nCADENA CON MAS VOCALES"<<endl;
    cout << cadena[place] << endl;
    cout << "Tiene " << frecuencia[place] << " vocales" << endl;
}

//DETERMINA CUAL CADENA TIENE MENOS VOCALES Y LA ESCRIBE EN UN ARCHIVO
void menosVocales(string cadena[])
{
    system("cls"); //limpia la pantalla
    int menor = frecuencia[0];
    int place = 0;

    //Busca el índice que tiene mas vocales
    for(int i = 0; i<9; i++)
    {
        if(frecuencia[i+1] < menor)
        {
            menor = frecuencia[i+1];
            place = i+1; // índice donde se encuentra la cadena con mas vocales
        }
    }

    //se crea el archivo Muchas.txt
    ofstream salida("Pocas.txt");
    salida << cadena[place];
    salida.close();

    //Muestra en pantalla
    cout << "\nCADENA CON MENOS VOCALES"<<endl;
    cout << cadena[place] << endl;
    cout << "Tiene " << frecuencia[place] << " vocales" << endl;
}


