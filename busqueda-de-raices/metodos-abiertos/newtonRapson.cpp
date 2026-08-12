#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

double funcion(double x)
{
  return -x + 2;
}

double derivada(double x) 
{
  double h = 0.000001;
  return ((funcion(x + h) - funcion(x)) / h); //o meter a mano  la derivada de la funcion.
}

int main()
{

  int iteracion = 0;

  double tolerancia = 0;
  double xp = 0;
  double x = 0;
  double error = 0;

  cout << "Ingrese el X inicial" << endl;

  cin >> x;

  cout << "Ingrese el valor de la tolerancia" << endl;

  cin >> tolerancia;

  do
  {

    xp = (x - (funcion(x) / derivada(x)));

    if (derivada(xp) < 1)
    { 

      iteracion++;

      error = (fabs(xp - x) / fabs(xp)); //Error absoluto relaivo a xp
      // error porcentual = error  * 100; //si  me piden el error exacto es solo el fabs(xp-x)/fabs(xp) y si me piden el error porcentual es el mismo error * 100
      //error = pow((xp-x),2) / pow(x,2);    //Error relativo solo

      if (iteracion == 1000)
      {
        cout << "No se ha encontrado raices, inicie con otro valor o un menor error" << endl;
        exit(EXIT_FAILURE);
      }

      x = xp;
    }
    else
    {

      cout << "Error de convergencia, inicie con una tolerancia mayor" << endl;
      exit(EXIT_FAILURE);
    }

  } while (error > tolerancia);

  cout << " La raiz es " << x << "\n numero de iteraciones realizadas: " << iteracion << "\n con un error : " << error << endl;

  return 0;
}
