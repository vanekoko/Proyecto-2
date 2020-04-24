#include <iostream>
using namespace std;

class Actor{
private:
    int id;
    string nombre;
public:
    Actor(){id=0;nombre="";};
    Actor(int i, string n){id=i;nombre=n;};
    void setid(int i){id=i;};
    int getid(){return id;};
    void setnombre(string n){nombre=n;};
    string getnombre(){return nombre;};
    void muestra(){cout<<"ID: "<<id<<"\t Nombre: "<<nombre<<endl;};
    friend istream &operator>>(istream  &input, Actor &A ) {input >> A.id >> A.nombre;return input;}
};

class Hora{
private:
    int hh,mm;
public:
    Hora(){hh=0;mm=0;};
    Hora(int h,int m){hh=h;mm=m;};
    void sethh(int ho){hh=(ho>0 && ho<24 ? ho : 0);};
    int gethh(){return hh;};
    void setmm(int mi){mm=(mi>0 && mi<60 ? mi : 0);};
    int getmm(){return mm;};
    void muestra(){cout<<"Hora: "<<hh<<"\t Minutos: "<<mm<<endl;};
};

