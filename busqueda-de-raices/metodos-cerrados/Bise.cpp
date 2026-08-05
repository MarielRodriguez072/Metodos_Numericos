#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

double f(double num);

int main(){
    //declracion de variables limites del intervalo, error, raiz y contador de iteraciones
    double a=0;
    double b=0;
    double x=0;
    double e=0;

    ofstream fs("Resultado.txt");
    
    int contador =0;
    double resultado;
    double c;
    bool ver=true; 
    cout<<"-----Intervalo a analizar-----"<<endl;
    cout<<"Ingrese el primer valor del intervalo (valor a)"<<endl;
    cin>>a;
    cout<<"Ingrese el segundo valor del intervalo (valor b)"<<endl;
    cin>>b;
    cout<<"Ingrese E (error)"<<endl;
    cin>>e;
    
    if(fabs(f(a))<e){
        
        cout<<a<<" es raiz"<<endl;
        ver=false;
    }
    if(fabs(f(b))<e){
        
        cout<<b<<" es raiz"<<endl;
        ver=false;
        
    }
    
    
    if( (f(a)*f(b)) >0){
        
        cout<<"No se puede"<<endl;
        
    }
    
    
    if(ver==false){
        
        return 0;
        
    }else{
        
        if(f(a)*f(b)>0){
            cout<<"No hay raiz o obtuviste numero par de raices"<<endl;
            return 0;
        }
        
    }
    
    
    do{
        //Biseccion
        c=(a+b)/2;

        //Falsa posicion (regula-falsi)
        //c=a-f(a)*(b-a)/(f(b)-f(a));
        
        contador=contador+1;
        if( (f(a)*f(c))>0 ){
            a=c;
        }else{
            b=c;
        }
        
        cout<<contador<<") "<<fabs(f(c))<<endl;
        fs<<contador<<") "<<fabs(f(c))<<endl;

    }while (fabs(f(c))>e);

    cout<<endl;
    cout<<"Ultima iteracion: "<<contador<<endl;
    cout<<endl;
    cout<<" La raiz es: "<<c<<endl;
    
    //system("pause");
    return 0;
}

double f(double x){
    return -2 + (7*x) - (5 * pow(x,2)) + (6 * pow(x,3));
    
}
