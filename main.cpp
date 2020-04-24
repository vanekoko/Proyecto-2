#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Pelicula.h"

using namespace std;

int main(){
    string nombre,genero,titulo,m;
    int id,numpeli,anio,duracion,canA,ids;
    Actor actor[20];
    Funcion funcion[20];
    Pelicula pelicula[20];
    ifstream actores, peliculas;
    actores.open("actores.txt");
    peliculas.open("peliculas.txt");
//archivo actores a arreglo de objetos
    int i=0, j=0;
    while(actores>>id){
            actor[i].setid(id);
            getline(actores,nombre);actor[i].setnombre(nombre);
            i++;
        }
//archivo peliculas a arreglo de objetos
    while(peliculas >> numpeli){
        pelicula[j].setnumPeli(numpeli);
        peliculas>>anio;pelicula[j].setanio(anio);
        peliculas>>duracion;pelicula[j].setduracion(duracion);
        peliculas>>genero;pelicula[j].setgenero(genero);
        peliculas>>canA;
        for(int k=0;k<canA;k++){
            peliculas>>ids;
            for(int e=0;e<20;e++){
                if(ids==actor[e].getid()){
                    pelicula[j].addactor(actor[e]);
                }
            }
        }
        getline(peliculas, titulo);pelicula[j].settitulo(titulo);
        j++;
    }
    actores.close();
    peliculas.close();
//Registro de funciones
    int ll;int p=0;
//while(r!='n'){
    cout<<"\nRegistro de funciones\n¿Cuantas funciones quiere ingresar: "<<endl;
    cin>>ll;
    string a; int b,c,d,e;
        for(int i=0;i<ll;i++){
            cout<<"Clave funcion"<<endl;
            cin>>a;
            funcion[i].setcveFuncion(a);
            cout<<"Numero Pelicula"<<endl;
            cin>>b;
            for(int x=0;x<j;j++){
                if(b==pelicula[x].getnumPeli()){
                    funcion[i].setnumPeli(b);
                    p=1;
                    break;
                }
            }
            if(p==1){
                cout<<"Sala"<<endl;
                cin>>c;
                funcion[i].setsala(c);
                cout<<"Hora"<<endl;
                cin>>d;
                if(0<=d && d<=24){
                    cout<<"Minutos"<<endl;
                    cin>>e;
                    if(0<=e && e<=59){
                        Hora inicio(d,e);
                        funcion[i].setHora(inicio);
                        ll++;
                    }
                    else if(e<=0 || e>=60){
                        cout<<"Ingrese minutos correctos"<<endl;
                        break;
                    }
                }
                else if(e<=0 || e>=25){
                    cout<<"Ingrese hora correcta"<<endl;
                    break;
                }
            }
            if (p==0){
            cout<<"Ingrese un numero de pelicula valido\nVuelva a ingresar presione g"<<endl;
            break;
            }
            p=0;
    }
//menu
    char op;
    while(op != 'g'){
        cout<<"\n\nBienvenido al menu de inicio.\nPor favor, seleccione una opcion"<<endl;
        cout<<"a = Mostrar lista de actores. \nb = Mostrar lista de peliculas disponibles."<<endl;
        cout<<"c = Mostrar funciones disponibles. \nd = Consulta de funcion por horarios."<<endl;
        cout<<"e = Consulta de funcion por clave. \nf = Consulta de actores por pelicula. \ng = Terminar"<<endl;
        cin>>op;
        int p=0;
        switch (op){
        case 'a':{
            for (int a=0;a<i;a++){
                cout<<"ID: "<<actor[a].getid()<<"\tNombre: "<<actor[a].getnombre()<<endl;
                }
            break;}
        case 'b':{
            for(int b=0;b<j;b++){
                cout<<"\n\nTitulo: "<<pelicula[b].getTitulo()<<"\nAnio: "<<pelicula[b].getanio()<<"\nGenero: "<<pelicula[b].getgenero()<<"\nActores: "<<endl;
                for(int a=0;a<pelicula[b].getcanActores();a++){
                    pelicula[b].getlistaActor(a);
                }
            }
            break;}
        case 'c':{
            for(int a=0;a<ll;a++){
                cout<<"\nClave: "<<funcion[a].getcveFuncion()<<endl;
                for(int b=0;b<j;b++){
                    if(funcion[a].getnumPeli()==pelicula[b].getnumPeli()){
                            cout<<"Titulo: "<<pelicula[b].getTitulo();}
                }
                cout<<"\nSala: "<<funcion[a].getsala()<<"\t\t";
                funcion[a].inicio.muestra();
            }
            break;}
        case 'd':{
            int ho, mi;
            cout<<"\nIngrese hora: ";
            cin>>ho;
            if(0<=ho && ho<=24){
                cout<<"Ingrese minutos: ";
                cin>>mi;
                if(0<=mi && mi<=59){
                Hora busqueda(ho,mi);
                for(int d=0;d<ll;d++){
                    if(funcion[d].inicio.gethh()==busqueda.gethh()){
                        for(int b=0;b<j;b++){
                            if(funcion[d].getnumPeli()==pelicula[b].getnumPeli()){
                                    cout<<"\nTitulo: "<<pelicula[b].getTitulo();}
                        }
                    cout<<"\t\tSala: "<<funcion[d].getsala()<<"\t\t";
                    funcion[d].inicio.muestra();
                    }
                }
                }
                else if(mi<=0 || mi>=60){
                    cout<<"**Ingrese minutos correctos"<<endl;
                    break;
                }
            }
            else if(ho<=0 || ho>=25){
                cout<<"**Ingrese hora correcta"<<endl;
                break;
            }
            break;
            }
        case 'e':{
            string cve;
            cout<<"\nIngrese clave de funcion: ";
            cin>>cve;
            for(int e=0;e<ll;e++){
                if(funcion[e].getcveFuncion()==cve){
                    cout<<"\nSala: "<<funcion[e].getsala()<<endl;
                    funcion[e].inicio.muestra();
                    for(int b=0;b<j;b++){
                        if(funcion[e].getnumPeli()==pelicula[b].getnumPeli()){
                                cout<<"Titulo: "<<pelicula[b].getTitulo();}
                        if(funcion[e].getnumPeli()==pelicula[b].getnumPeli()){
                                cout<<"\nGenero: "<<pelicula[b].getgenero();}
                        if(funcion[e].getnumPeli()==pelicula[b].getnumPeli()){
                                cout<<"\n";
                                pelicula[b].getlistaActores();
                    }
                }
                p=1;
                break;
            }
            }
            if(p==0){
                cout<<"La clave no ha sido encontrada"<<endl;
            }
            break;
        }
        case 'f':{
            int idnuevo;
            cout<<"Ingrese ID del Actor: ";
            cin>>idnuevo;
            for(int f=0;f<20;f++){
                if(actor[f].getid()==idnuevo){
                    cout<<"\n"<<actor[f].getnombre()<<endl;
                    for(int x=0;x<j;x++){
                        for(int y=0;y<pelicula[x].getcanActores();y++){
                            if(pelicula[x].listaActores[y].getid()==idnuevo){
                                cout<<"\n- Titulo: "<<pelicula[x].getTitulo()<<"\n  Anio: "<<pelicula[x].getanio()<<endl;
                            }
                        }
                    }
                    p=1;
                break;
                }
            }
            if(p==0){
                cout<<"El ID no ha sido encontrada"<<endl;
            }
            break;}
        }
    }
    return 0;
}
