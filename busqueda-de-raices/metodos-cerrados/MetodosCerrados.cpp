#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

const int MAX_ITER = 100;

double f(double x);

double puntoMedioB(double a, double b);
double puntoMedioR(double a, double b);

int main(){
    int metodo=0;
    double a=0;
    double b=0;
    double e=0;
    double c=0;
    double anterior=0;
    double error=e+1;
    int contador=0;

    cout<<"----- Metodos cerrados de busqueda de raices -----"<<endl;
    cout<<"Seleccione el metodo a usar:"<<endl;
    cout<<"1) Biseccion"<<endl;
    cout<<"2) Regula Falsi (falsa posicion)"<<endl;
    cout<<"Opcion: ";
    cin>>metodo;

    cout<<"-----Intervalo a analizar-----"<<endl;
    cout<<"Ingrese el primer valor del intervalo (valor a)"<<endl;
    cin>>a;
    cout<<"Ingrese el segundo valor del intervalo (valor b)"<<endl;
    cin>>b;
    cout<<"Ingrese E (error)"<<endl;
    cin>>e;

    if(fabs(f(a))<e){
        cout<<a<<" es raiz"<<endl;
        return 0;
    }
    if(fabs(f(b))<e){
        cout<<b<<" es raiz"<<endl;
        return 0;
    }

    if(f(a)*f(b)>0){
        cout<<"No hay raiz en el intervalo o tiene un numero par de raices"<<endl;
        return 0;
    }

    ofstream fs("Resultado.txt");

    do{
        //Calculo del punto medio segun el metodo elegido
        if(metodo == 1){
            c = puntoMedioB(a, b);
        }else{
            c = puntoMedioR(a, b);
        }

        contador++;

        //Actualizacion del intervalo
        if(f(a)*f(c)>0){
            a=c;
        }else if(f(b)*f(c)>0){
            b=c;
        }else{
            break;
        }

        //Error aproximado: distancia entre la raiz actual y la anterior
        error = fabs(c-anterior);
        anterior = c;

        cout<<contador<<") f(c)="<<fabs(f(c))<<"  error="<<error<<endl;
        fs<<contador<<") f(c)="<<fabs(f(c))<<"  error="<<error<<endl;

    }while(error > e && contador < MAX_ITER);

    cout<<endl;
    cout<<"Ultima iteracion: "<<contador<<endl;
    cout<<endl;
    cout<<"La raiz es: "<<c<<endl;

    fs.close();
    return 0;
}

double f(double x){
    return -2 + (7*x) - (5 * pow(x,2)) + (6 * pow(x,3));
}


double puntoMedioB(double a, double b){
    return (a+b)/2;
}

double puntoMedioR(double a, double b){
    return b - (f(b)*(a-b))/(f(a)-f(b));
}
