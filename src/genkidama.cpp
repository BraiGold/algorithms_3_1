#include "./genkidama.h"
using namespace std;

int genkidama (int N,int T,std::vector<std::pair<int,int> >& enemigos,std::list<int>* DisparosEfectuados){
  int cantGenkidamas=0;
  int i=0;

  while (i<N) {

    int aEsteLeDisparo=masLejanoQueMataAl(i,N,T,enemigos);//busco el mas grande(lejano) que mate al primero de los que quedan vivos
    i = masLejanoQueMata(aEsteLeDisparo,N,T,enemigos) + 1;//empiezo a preguntar desde el sigiente al ultimo en morir

    DisparosEfectuados->push_back(aEsteLeDisparo);
    cantGenkidamas++;
  }
return cantGenkidamas;
}

int masLejanoQueMataAl(int i,int N, int T,vector<pair<int,int> >& enemigos){
    int j=i+1;//pregunto desde el siguiente porque es obvio que i mata a i
    while(mataAl(j,i,N,T,enemigos)){//mata j al i?
      j++;
    }
    return j-1;//el primero que falla menos 1 es el ultimo que efectivamente mata al i
}

int masLejanoQueMata(int aEsteLeDisparo, int N,int T, vector<pair<int,int> >& enemigos){
  int j=aEsteLeDisparo+1;//pregunto desde el siguinte porque es obv
  while(mataAl(aEsteLeDisparo,j,N,T,enemigos)){//mata i al j?
    j++;
  }
  return j-1;

}

bool mataAl(int i,int j,int N,int T,vector<pair<int,int> >& enemigos){//mata i al j?
  if(enemigos[i].first + T >= enemigos[j].first && enemigos[i].second + T >= enemigos[j].second )
  return true;
  else
  return false;
}
