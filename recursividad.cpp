/*
Función Signo
sg(0) = 0
sg(x + 1) = 1

Función Signo Inverso
isg(0) = 1
isg(x + 1) = 0

Función And
And(x, y) = sg(x * y)

Función Or
Or(x, y) = sg(p + q)

Ejercicios
¿Qué resulta de aplicar?
I-	sg(isg(sg(0)))
II-	or(0,0)
III-	and(1,1)
IV-	and(or(0,1),isg(0))

NOTA:Las funciones aparecian desordenadas en el archivo txt que usted me dio.

1. Crea una función recursiva que regrese 1 si un número es impar y 2 en
caso contrario

2. Crea una función recursiva de tal forma que regrese 0 si x1 = x2 = x3 = x4,
es decir f es de la forma f(x1, x2, x3, x4), si necesitas funciones extras
debes definirlas también.

*/

#include <iostream>
#include <string.h>

using namespace std;

int funcion=0, resultado=0, r;
char* idFuncion="";

void mostrarFunciones();
int calcular(int);
int factorial(int);
int sg(int);
int isg(int);
int andf(int, int);
int orf(int, int);

int par(int n);
int impar(int n);

int f(int, int, int, int);

int main(int argc, char** argv)
{
	cout<<"Ejemplo de recursividad en C++"<<endl;
	cout<<"------------------------------"<<endl;
	mostrarFunciones();
	cout<<"Que funcion deseas calcular ";
	cin>>funcion;
	resultado=calcular(funcion);
	cout<<"El resultado del "<<idFuncion<<" es "<<resultado<<endl;
	return 0;
}

void mostrarFunciones()
{
	cout<<"1- Factorial"<<endl;
	cout<<"2- Signo sg(x)"<<endl;
	cout<<"3- Signo Inverso isg(x)"<<endl;
	cout<<"-----Ejercicios Resueltos-----"<<endl;
	cout<<"4- sg(isg(sg(0)))"<<endl;
	cout<<"5- or(0,0)"<<endl;
	cout<<"6- and(1,1)"<<endl;
	cout<<"7- and(or(0,1),isg(0))"<<endl;
	cout<<"8- conocer si es par o impar"<<endl;
}

int calcular(int f)
{
	int numero=0, resultado=0;

	switch(f)
	{
		case 1:
			idFuncion="Factorial";
			cout<<"Ingresa un numero ";
			cin>>numero;

			resultado=factorial(numero);
			break;
		case 2:
			idFuncion="Signo";
			cout<<"Ingresa un numero ";
        	cin>>numero;

			resultado=sg(numero);
			break;
		case 3:
			idFuncion="Signo Invertido";
			cout<<"Ingresa un numero ";
			cin>>numero;

			resultado=isg(numero);
			break;
		case 4:
			idFuncion="Ejercicio I";
			resultado=sg(isg(sg(0)));
			break;
		case 5:
			idFuncion="Ejercicio II";
			resultado=orf(0,0);
			break;
		case 6:
			idFuncion="Ejercicio III";
			resultado=andf(1,1);
			break;
		case 7:
			idFuncion="Ejercicio IV";
			resultado=andf(orf(0,1),isg(0));
			break;
		case 8:
			idFuncion="par o impar";
			cout<<"Ingresa un numero ";
        	cin>>numero;

			resultado=par(numero);
			break;
		default:cout<<"La función que elegiste no esta entre las opciones";
	}

	return resultado;
}

int factorial (int n)
{

	if(n<=2)
		r=1;
	else
		r=n*factorial(n-1);

	return r;
}

//recursividad directa
int sg(int n)
{
	if(n==0)
	{
		r=0;
	}
	else if(n<2)
		r=1;
	else
		r=sg(n-1);

	return r;
}

int isg(int n)
{
	return !sg(n);
}

int andf(int x, int y)
{
	return sg(x*y);
}

int orf(int x, int y)
{
	int p=x, q=y;
	return sg(p+q);
}

//recursividad indirecta

int par(int n)
{
  if (n == 0)
	return 2;
  
  return impar(n-1);
}

int impar(int n)
{
  if (n == 0)
	return 1;
  
  return par(n-1);
}
