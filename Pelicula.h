#include <iostream>
#include "Actor Hora.h"
using namespace std;

class Pelicula{
private:
    int numPeli,anio,duracion,canActores;
    string titulo,genero;
public:
    Actor listaActores[10];
    Pelicula(){canActores=0;numPeli=0;anio=1900;duracion=0;titulo="";genero="";Actor listaActores[10];};
    void setnumPeli(int np){numPeli=np;};
    void setanio(int a){anio=a;};
    void setduracion(int d){duracion=d;};
    void settitulo(string t){titulo=t;};
    void setgenero(string g){genero=g;};
    int getnumPeli(){return numPeli;};
    int getanio(){return anio;};
    int getduracion(){return duracion;};
    string getTitulo(){return titulo;};
    string getgenero(){return genero;};
    void getlistaActor(int i){listaActores[i].muestra();};
    void getlistaActores(){for(int i=0;i<getcanActores();i++){listaActores[i].muestra();}};
    int getcanActores();
    bool addactor(Actor nuevo){
        if(getcanActores()< 10){
            int x=0;
            for(int i=0;i<getcanActores();i++){ // [0] 5, [1] 7, [2] 7, [3] 7
                if(listaActores[i].getid()==nuevo.getid()){
                    x=1;
                    break;
                }
            }
            if(x==1){
                cout<<"Nota: El actor "<<nuevo.getnombre()<<" ya esta en la lista";
                return false;
            }
            else if(x==0){
            listaActores[canActores]=nuevo;
            canActores++;
            return true;
            }
            }
        else{
            cout<<"Nota: Lista de actores llena, no se puede agregar nuevo";
            return false;
        }
    }
    };

int Pelicula::getcanActores(){
    canActores=0;
    for(int i=0;i<10;i++){
        if(listaActores[i].getid()!=0 && listaActores[i].getnombre()!="")
            {canActores++;}
        else{break;}}
    return canActores;
}

class Funcion{
private:
    string cveFuncion;
    int numPeli, sala;
public:
    Hora inicio;
    Funcion(){cveFuncion="";numPeli=0;sala=0;Hora i;inicio=i;};
    Funcion(string c,int n,int s,Hora i){cveFuncion=c;numPeli=n;sala=s;inicio=i;};
    void setcveFuncion(string c){cveFuncion=c;};
    void setnumPeli(int np){numPeli=np;};
    void setsala(int s){sala=s;};
    void setHora(Hora i) { inicio = i;};
    string getcveFuncion(){return cveFuncion;};
    int getnumPeli(){return numPeli;};
    int getsala(){return sala;};
    void muestra(){cout<<"Clave funcion: "<<cveFuncion<<"\tPelicula: "<<numPeli<<"\tSala: "<<sala<<endl;inicio.muestra();};
};
