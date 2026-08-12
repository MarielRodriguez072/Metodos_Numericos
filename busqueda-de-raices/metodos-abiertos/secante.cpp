
#include <iostream>
#include <cmath>

using namespace std;

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
double Secante(double x0, double x1, double exactitud, int &iteraciones, double &error)
{
  double xi = 0;

  do
  {
    //Calcula el nuevo punto y el error. Formula de la secante.
    xi = x1 - ((funcion(x1) * (x0 - x1)) / (funcion(x0) - funcion(x1)));
    error = errorAbsoluto(x1, xi);

    x0 = x1;  //xvv=xv 
    x1 = xi; //xn=xv

    //Se suma una iteracion.
    iteraciones++;

    
  } while (error > exactitud);

  //Regresa el ultimo valor calculado.
  return x1;
}

int main(){
  
  double x0 = 0, x1 = 0, error = 0;
  int iteraciones = 0;

  //Llama al metodo de la secante con valores iniciales de 0 y 1, y un error de 0.00001.
  double res = Secante(0, 1, 0.00001, iteraciones, error);//modificar estos valores en caso de ser necesario.
  cout << "La raiz es: " << res << "\n";
  cout << "Iteraciones: " << iteraciones << "\n";
  cout << "Error: " << error << endl;

  return 0;
}
