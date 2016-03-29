#include <stdio.h>      /* printf */
#include <math.h>       /* log */
#include <utility>      // std::pair, std::get
#include <iostream>     // std::cout
#include <list>
#include <vector>


//int genkidama (int N,int T,std::vector<std::pair<int,int> > enemigos,std::list<int>* DisparosEfectuados);
int masLejanoQueMataAl(int i,int N,int T,std::vector<std::pair<int,int> >& enemigos);
int masLejanoQueMata(int aEsteLeDisparo,int N,int T, std::vector<std::pair<int,int> >& enemigos);
bool mataAl(int i,int j,int N,int T,std::vector<std::pair<int,int> >& enemigos);

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

std::vector<std::pair<int,int> > enemigos;

int main() {
  int n,t,a,b;
  cin >> n >> t;

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    std::pair<int, int>e1(a,b); 
    enemigos.push_back(e1);
  }
  list<int>DisparosEfectuados;
  int G=genkidama(n,t,enemigos,&DisparosEfectuados);
  cout << G << endl;
  
  int cantDisparos=DisparosEfectuados.size();
  //muestro los disparos efectuados
  for(int i=0; i < cantDisparos; i++) {
    cout << DisparosEfectuados.back() + 1 << ' ';
    DisparosEfectuados.pop_back();
  }
    std::cout << std::endl;
  /*std::pair<int,int>e1(100,0);
  std::pair<int,int>e2(75,25);
  std::pair<int,int>e3(50,50);
  std::pair<int,int>e4(25,75);
  std::pair<int,int>e5(0,100);
  std::vector<std::pair<int,int> > enemigos;
  enemigos.push_back(e1);
  enemigos.push_back(e2);
  enemigos.push_back(e3);
  enemigos.push_back(e4);
  enemigos.push_back(e5);

  list<int>DisparosEfectuados;
  int G=genkidama(5,26,enemigos,&DisparosEfectuados);
  cout << G << std::endl;
  int cantDisparos=DisparosEfectuados.size();

  //muestro los disparos efectuados
  for(int i=0; i< cantDisparos; ++i){
    std::cout << DisparosEfectuados.back() << ' ';
    DisparosEfectuados.pop_back();

  }
  std::cout << std::endl; */
}