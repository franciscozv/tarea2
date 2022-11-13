#include <iostream>
#include <vector>
#include <fstream>
#include<thread>
#include<string>
#include<unistd.h>
using namespace std;
void arrancarPing ( string  cadena);//tiene que recibir una direccion ip
int main(int argc, char * argv[])
{
	/*voy a recorrer el archivo para almacenar las direcciones ip como cadenas en
	un vector
	*/
	fstream fst("archivo_listado_ips.txt", ios::in);
	string str;
	vector<string> palabras;
	if(fst.is_open()){

		while(getline(fst, str)) palabras.push_back(str);

	}else cout << "error";

	fst.close();
	int n = palabras.size(); // numero de hilos
	//inicializando y creando hilos
	cout<<"IP           Trans.      Rec.       Perd.       Estado"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	thread threads[n];
	int i = 0;
	for (i = 0; i < n; i++) {
		threads[i] = thread(arrancarPing, palabras[i]);
	}
	//para esperar por el termino de todos los hilos. con un bucle for
	for (i = 0; i < n; i++) {
		threads[i].join();
	}

    return 0;
}

//funcion debe hacer toda la logica a partir del numero de ip que recibamos
//y despues mostrar la salida

void arrancarPing (string cadena) {
	cout<<cadena;
	cout<<endl;
}


