#include <iostream>
#include <cmath>
#include <iomanip>

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
  const int MAX_ITER = 1000;

  cout << "Ingrese el valor inicial: " << endl;
  cin >> a;
  cout << "Ingrese el valor del error esperado (e), debe ser mayor a cero: " << endl;
  cin >> errorMinimo;

  if(errorMinimo <= 0){
    cout << "El error esperado debe ser mayor que 0." << endl;
    return 1;
  }

  // Decimales exactos que garantiza la tolerancia: d ~ -log10(e) (e = 0.5*10^-d)
  int decimales = (int)ceil(-log10(errorMinimo));
  if(decimales < 1) decimales = 1;

  error = errorMinimo + 1;
  x = a;

  // Verificar convergencia antes de iterar: se requiere |g'(x)| < 1
  if(fabs(derivada(x)) >= 1){
    cout << "El metodo no converge: |g'(x)| = " << fabs(derivada(x))
         << " >= 1 en x = " << x << endl;
    return 1;
  }

  cout << fixed << setprecision(decimales + 1);
  cout << "Iteracion |         x        |        f(x)       | Error absoluto | Error relativo | Error porcentual (%)" << endl;
  cout << "----------+-------------------+------------------+----------------+----------------+---------------------" << endl;

  while(error > errorMinimo){
    iteracion++;
    if(iteracion > MAX_ITER){
      cout << "Se alcanzaron las " << MAX_ITER << " iteraciones maximas sin cumplir la tolerancia." << endl;
      return 1;
    }
    if(fabs(derivada(x)) >= 1){
      cout << "El metodo no converge: |g'(x)| = " << fabs(derivada(x))
           << " >= 1 en x = " << x << endl;
      return 1;
    }
    x1 = g(x);
    error = fabs(x - x1);
    x = x1;
    double errorRelativo = (x != 0) ? error / fabs(x) : 0;
    double errorPorcentual = errorRelativo * 100;
    cout << setw(9) << iteracion << " | " << setw(17) << x << " | "
         << setw(16) << f(x) << " | " << setw(14) << error << " | "
         << setw(14) << errorRelativo << " | " << setw(19) << errorPorcentual << endl;
  }

  cout << "--------------------------------------------------------------" << endl;
  cout << "Cantidad total de iteraciones: " << iteracion << endl;
  cout << "La Raiz es: " << x << endl;
  cout << "Error absoluto estimado final: " << error << endl;
  cout << "Error porcentual estimado final: " << (x != 0 ? error / fabs(x) * 100 : 0) << " %" << endl;
  cout << "Decimales exactos garantizados: " << decimales << endl;
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
// derivada de g(x) por diferencia central (mas precisa que la hacia adelante)
double derivada(double x){
  double h = 0.00001;
  return (g(x + h) - g(x - h)) / (2*h);
}
