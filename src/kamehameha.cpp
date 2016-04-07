#include <stdio.h>      /* printf */
#include <math.h>       /* log */
#include <utility>      // std::pair, std::get
#include <iostream>     // std::cout
#include <list>
#include <vector>
#include <cstdio>
#include <sys/time.h>

using namespace std;

timeval timeStart, timeEnd;

void init_time()
{
    gettimeofday(&timeStart,NULL);
}

double get_time()
{
    gettimeofday(&timeEnd,NULL);
    return (1000000*(timeEnd.tv_sec-timeStart.tv_sec)+(timeEnd.tv_usec-timeStart.tv_usec))/1000000.0;
}

vector<pair<pair<int,int>,pair<int,int> > > generarConjPares(std::vector<std::pair<int,int> > puntos);
vector<pair<int,int> > generarConjSinLD(pair<pair<int,int>,pair<int,int> > par,std::vector<std::pair<int,int> > puntos);
vector<pair<pair<int,int>,pair<int,int> > > mejoresPares(vector<pair<int,int> > puntos);
int conjMasChico (vector<vector<pair<pair<int,int>,pair<int,int> > > > posiblesConvinaciones);
int ConjLD(pair<pair<int,int>,pair<int,int> >  par,vector<pair<int,int> >& puntosCopia,vector<int>& matadosConEstePar,vector<bool>& puntosCopiaMascara);
void mostrarLinea(int cantLD,vector<int>& matadosConEstePar);

int kamehameha(std::vector<std::pair<int,int> > puntos,vector<pair<pair<int,int>,pair<int,int> > >& paresOptimos){
   paresOptimos = mejoresPares(puntos);

    return paresOptimos.size();
}

vector<pair<pair<int,int>,pair<int,int> > > mejoresPares(vector<pair<int,int> > puntos){
  if(puntos.size()==0){
    vector<pair<pair<int,int>,pair<int,int> > > res;
    return res;
  }
  if(puntos.size()==1){
    pair<pair<int,int>,pair<int,int> > par(puntos[0],puntos[0]);
    vector<pair<pair<int,int>,pair<int,int> > > res(1,par);
    return res;
  }else{
    if(puntos.size()==2){
      pair<pair<int,int>,pair<int,int> > par(puntos[0],puntos[1]);
      vector<pair<pair<int,int>,pair<int,int> > > res(1,par);
      return res;
    }else{
      vector<pair<pair<int,int>,pair<int,int> > > pares = generarConjPares(puntos);//genera conj Pares que pasen por el ultimo osea por puntos.back()

      vector<vector<pair<pair<int,int>,pair<int,int> > > >  posiblesConvinaciones(pares.size(),pares);//creo un conj de conj de pares con tamaño pares.size y lo lleno con que no importa tipo pares

      puntos.pop_back();  //saco el ultimo para recursivisar sin este
      for (int i = 0; i < pares.size(); i++) {

        posiblesConvinaciones[i]=mejoresPares(generarConjSinLD(pares[i],puntos));
        posiblesConvinaciones[i].push_back(pares[i]);
      }

      int mejorPar= conjMasChico(posiblesConvinaciones);
      return posiblesConvinaciones[mejorPar];
    }
  }
}

vector<pair<pair<int,int>,pair<int,int> > > generarConjPares(std::vector<std::pair<int,int> > puntos){
  vector<pair<pair<int,int>,pair<int,int> > > pares;
  pair<pair<int,int>,pair<int,int> > par(puntos.back(),puntos.back());

  for (int i = 0; i < puntos.size()-1; i++) {
    par.second.first=puntos[i].first;
    par.second.second=puntos[i].second;
    pares.push_back(par);
  }
  return pares;
}

int conjMasChico (vector<vector<pair<pair<int,int>,pair<int,int> > > > posiblesConvinaciones){
  int    min=0;

  for (int i = 0; i < posiblesConvinaciones.size(); i++) {
    if (posiblesConvinaciones[i].size()<posiblesConvinaciones[min].size())
      min=i;

  }

  return min;
}

vector<pair<int,int> > generarConjSinLD(pair<pair<int,int>,pair<int,int> > par,std::vector<std::pair<int,int> > puntos){
  //std::cerr << "genero conjSinLD de: ("<<par.first.first<<";"<<par.first.second<<") ("<<par.second.first<<";"<<par.second.second<<")" << std::endl;
  vector<pair<int,int> > conjSinLD;
  if(par.first==par.second){return puntos; }

  for (int i = 0; i < puntos.size(); i++) {
          //        (x1 -x3)             *              (y1-y2)               !=             (x1-x2)              *              (y1-y3)
    if ((par.first.first-puntos[i].first)*(par.first.second-par.second.second)!=(par.first.first-par.second.first)*(par.first.second-puntos[i].second)){
      conjSinLD.push_back(puntos[i]);
  //    std::cerr << "---("<<puntos[i].first<<";"<<puntos[i].second<<")" << std::endl;
    }
  }
  return conjSinLD;
}

int main(int argc, char* argv[]){
  int n,a,b;
  cin >> n;
  vector<std::pair<int,int> > puntos;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    //std::cerr << i<<"---("<< a << ";" << b<<")"<< std::endl;
    std::pair<int, int>p1(a,b);
    puntos.push_back(p1);
  }


    vector<pair<pair<int,int>,pair<int,int> > > paresOptimos;

    vector<pair<int,int> > puntosCopia(puntos);
    vector<bool > puntosCopiaMascara(puntosCopia.size(),true);
    bool pidieronTiempo = false; 
    if (argc > 1) {
      if (argv[1] == string("-t")) {
        pidieronTiempo = true;
      }
    }
    double tiempo;
    init_time();

    int cantDisparos=kamehameha(puntos,paresOptimos);
    tiempo = get_time();
    if (!pidieronTiempo) {
     
    std::cout << cantDisparos << std::endl;
    vector<int> matadosConEstePar;
    int cantLD;

      for (int i = 0; i < paresOptimos.size(); i++) {
    //  std::cerr << "antes de conjLD it:"<< i << std::endl;
        cantLD=ConjLD(paresOptimos[i],puntosCopia,matadosConEstePar,puntosCopiaMascara);//cuenta los LD Y ademas arma una lista en matadosConEstePar
        mostrarLinea(cantLD,matadosConEstePar);
        matadosConEstePar.clear();
      }

    } else {
      printf("%.10f ", tiempo);
    }
    //std::cerr << "cantidad de disparos: " << cantDisparos << std::endl;
    //::cerr << "fueron: " <<paresOptimos.size() << std::endl;
    /*
    for (int i = 0; i < paresOptimos.size() ; i++) {
    //  std::cerr <<"[(" << paresOptimos[i].first.first<<";"<<paresOptimos[i].first.second<<")"<<"(" << paresOptimos[i].second.first<<";"<<paresOptimos[i].second.second<<")" <<"] " << std::endl;
    }
    */
}


int ConjLD(pair<pair<int,int>,pair<int,int> >  par,vector<pair<int,int> >& puntosCopia,vector<int>& matadosConEstePar,vector<bool>& puntosCopiaMascara){
  int cantLD=0;
  if(par.first==par.second){
    int i=0;
    while(i<puntosCopia.size() && puntosCopia[i]!=par.first){
      i++;
    }
    matadosConEstePar.push_back(i);
    return 1;
  }

  for (int i = 0; i < puntosCopia.size(); i++) {

          //        (x1 -x3)             *              (y1-y2)               ==             (x1-x2)              *              (y1-y3)
    if ((puntosCopiaMascara[i])&&((par.first.first-puntosCopia[i].first)*(par.first.second-par.second.second)==(par.first.first-par.second.first)*(par.first.second-puntosCopia[i].second))){
      matadosConEstePar.push_back(i);
      puntosCopiaMascara[i]=false;
      cantLD++;
    }

  }
  return cantLD;
}

void mostrarLinea(int cantLD,vector<int>& matadosConEstePar){
  std::cout << cantLD<<" ";
  //std::cerr << "tamanio de matadosConEstePar: "<<matadosConEstePar.size() << std::endl;
  for (int i = 0; i < matadosConEstePar.size()-1; i++) {
    std::cout << matadosConEstePar[i]+1<<" ";
    //std::cerr << matadosConEstePar[i]+1<<" ";
  }

  std::cout << matadosConEstePar[matadosConEstePar.size()-1]+1 << std::endl;
  //std::cerr << matadosConEstePar[matadosConEstePar.size()-1]+1 << std::endl;
}
