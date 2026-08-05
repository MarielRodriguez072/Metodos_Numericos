//Método de la secante
//Autor: Dominic Márquez

#include <iostream>
#include <cmath>

using namespace std;

double x0, x1, xi, error;

//Variable que guarda las iteraciones.
int iteraciones = 0;

//Metodo que representa la evaluacion de la funcion.
double funcion(double x)
{
  return cos(3+x+4*x); 
}

//Funcion que calcula el error
double errorAbsoluto(double viejo, double nuevo)
{
  return abs((nuevo - viejo) / nuevo) * 100;
}

//Metodo de la secante: acepta dos valores iniciales y un error.
double Secante(double x0, double x1, double exactitud)
{

  do
  {
    //Calcula el nuevo punto y el error.
    xi = x1 - ((funcion(x1) * (x0 - x1)) / (funcion(x0) - funcion(x1)));
    error = errorAbsoluto(x1, xi);

    x0 = x1;  //xvv=xv 
    x1 = xi; //xn=xv

    //Se suma una iteracion.
    iteraciones++;

    //Todo lo hace mientras el error deseado no haya sido
    //alcanzado todavia.
  } while (error > exactitud);

  //Regresa el altimo valor calculado.
  return x1;
}

int main(){
  //Llama al metodo de la secante con valores iniciales de
  //0 y 1, y un error de 0.00001.
  double res = Secante(0, 1, 0.00001);
  cout << "La raiz es: " << res << "\n";
  cout << "Iteraciones: " << iteraciones;

  return 0;
}
