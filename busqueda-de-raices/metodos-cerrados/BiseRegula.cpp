

#include <iostream>
#include <cmath>

using namespace std;

/*
* el metodo de Regular Falsi("puntoMedioR) es mas rapido
* */
double puntoMedioR(double a, double b);
double puntoMedioB(double a, double b);

//  funcion  donde busco las raices
double f(double x);

int main(int argc, char const *argv[]){
  double a,b,c,error,errorMin,anterior;
  cout<<"Ingrese el valor a del intervalo"<<endl;
  cin >> a;
  cout<<"Ingrese el valor de b del intervalo"<<endl;
  cin >> b;
  cout<<"Ingrese el error"<<endl;
  cin >> errorMin;
 
  //Con esta condicion nos aseguramos de que el rango A y B no esten del mismo lado
  if(f(a)*f(b)>0){
    cout << "no hay raices en el intervalo o tiene raices pares" << endl;
    return 0;
  }
  
  anterior = 0;
  while(error > errorMin){
  
    
    c = puntoMedioR(a,b);
    if(f(a)*f(c)>0)
      a=c;
    else if(f(b)*f(c)>0)
      b=c;
    else
      break;

    // error aproximado: valor absoluto del punto "c" con el anterior
    error = fabs(c-anterior);
    anterior = c; 
  }

  printf("el valor de la raiz es:%f",c);
  return 0;
}

double f(double x){
  return (2.12295*(x*x)-0.206982*x-0.952854);
}

// punto medio del met. Regula falsi
double puntoMedioR(double a, double b){ return b-((f(b)*(a-b))/(f(a)-f(b))); }

//  punto medio del met. biseccion.
double puntoMedioB(double a, double b){ return (b+a)/2; }

