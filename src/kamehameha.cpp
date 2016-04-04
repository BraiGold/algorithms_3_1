#include "./kamehameha.h"
using namespace std;

vector<pair<pair<int,int>,pair<int,int> > > generarConjPares(std::vector<std::pair<int,int> > puntos);
vector<pair<int,int> > generarConjSinLD(pair<pair<int,int>,pair<int,int> > par,std::vector<std::pair<int,int> > puntos);
vector<pair<pair<int,int>,pair<int,int> > > mejoresPares(vector<pair<int,int> > puntos);
int conjMasChico (vector<vector<pair<pair<int,int>,pair<int,int> > > > posiblesConvinaciones);

int kamehameha(int N,std::vector<std::pair<int,int> > puntos){
  vector<pair<pair<int,int>,pair<int,int> > > paresOptimos  =mejoresPares(puntos);

    return puntos.size();
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

      vector<vector<pair<pair<int,int>,pair<int,int> > > > posiblesConvinaciones(pares.size(),pares[0]);//creo un conj de conj de pares con tamaño pares.size y lo lleno con que no importa tipo pares[0]

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
  vector<pair<int,int> > conjSinLD;
  for (int i = 0; i < puntos.size(); i++) {
    if ((puntos[i].first-par.first.first)*(par.first.second-par.second.second)!=(par.first.second-par.second.first)*(puntos[i].second-par.first.second))
      conjSinLD.push_back(puntos[i]);
  }
  return conjSinLD;
}
