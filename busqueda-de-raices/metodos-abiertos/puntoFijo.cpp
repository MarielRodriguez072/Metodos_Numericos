#include <iostream>
#include <cmath>

using namespace std;

double f(double x);
double g(double x);
double derivada(double x);

int main(int argc, char const *argv[]){
  double a = 0; 
  double x1 = 0;
  double x = 0;
  double error = 0;
  double errorMinimo = 0;
  int iteracion = 0;

  cout << "Ingrese el valor inicial: "<< endl;
  cin >> a;
  cout << "Ingrese el valor del error esperado (e): "<< endl;
  cin >> errorMinimo;
  error = errorMinimo+1;
  x=a; //para modificar la variable que contenga el valor de a. entonces por cada iteracion tendre un nuevo valor de x
  while(error>errorMinimo){
    iteracion++;
    if(fabs(derivada(x))>1){
      cout<<"El metodo no converge porque la derivada de g(x) en a es mayor o igual a 1"<<endl;
      return 0;	
    }
    x1=g(x);
    error = fabs(x-x1);
    x=x1;
    cout<<"Iteracion: "<<iteracion<<endl;
    cout<<"Error: "<<error<<endl;
   
  }
  cout << "La Raiz es: " << x << endl;
  return 0;
}


// funcion original
double f(double x){
  return 3*x+sin(x)-exp(x); //3x+sen(x)-e^x-----> 3x= -sen(x) + e^x-----> x= (-sen(x) + e^x)/3-------> [-1(sen(x)-e^x)]/3
  //return pow(x,2)+ x - 4;
}
// despeje
double g(double x){
  return -1*(sin(x)-exp(x))/3;
  //return 4 - pow(x,2);
}
// derivada
double derivada(double x){
  double h = 0.00001;
  return (g(x+h)-g(x))/h;
}
