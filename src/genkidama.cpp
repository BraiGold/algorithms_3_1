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
  //  std::cerr << "llego hasta el "<< i << std::endl;
    int aEsteLeDisparo=masLejanoQueMataAl(i,N,T,enemigos);//busco el mas grande(lejano) que mate al primero de los que quedan vivos
  //  std::cerr << "masLejanoQueMataAl Da: "<< aEsteLeDisparo << std::endl;
    i = masLejanoQueMata(aEsteLeDisparo,N,T,enemigos) + 1;//empiezo a preguntar desde el sigiente al ultimo en morir
  //  std::cerr << "se Rompe en masLejanoQueMata pues da:" << i<< std::endl;
    DisparosEfectuados->push_back(aEsteLeDisparo);
    //std::cerr << "se rompe haciendo el push_back" << std::endl;
    cantGenkidamas++;
  }
  return cantGenkidamas;
}

int masLejanoQueMataAl(int i,int N, int T,vector<pair<int,int> >& enemigos){
    int j=i+1;//pregunto desde el siguiente porque es obvio que i mata a i
//    std::cerr << "el j="<<j<<"  mata al i="<<i <<" esta afirmacion da:"<<mataAl(j,i,N,T,enemigos) << std::endl;
    while(j<enemigos.size() && mataAl(j,i,N,T,enemigos)){//mata j al i?
      j++;
    }
    return j-1;//el primero que falla menos 1 es el ultimo que efectivamente mata al i
}

int masLejanoQueMata(int aEsteLeDisparo, int N,int T, vector<pair<int,int> >& enemigos){
  int j=aEsteLeDisparo+1;//pregunto desde el siguinte porque es obv
  while(j<enemigos.size() && mataAl(aEsteLeDisparo,j,N,T,enemigos)){//mata i al j?
    j++;
  }
  return j-1;

}

bool mataAl(int i,int j,int N,int T,vector<pair<int,int> >& enemigos){//mata i al j?
//  std::cerr << "enemigos[i]=("<<enemigos[i].first<<";"<<enemigos[i].second<<") y enemigos[j]=("<<enemigos[j].first <<";" <<enemigos << std::endl;
  if(enemigos[i].first + T >= enemigos[j].first && enemigos[i].second + T >= enemigos[j].second )
    return true;
  else
    return false;
}



int main() {
  int n,t,a,b;
  cin >> n >> t;
std::vector<std::pair<int,int> > enemigos;
//std::cerr << n << " " <<t << std::endl;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
  //  std::cerr << i<<"----"<< a<<" "<<b << std::endl;
    std::pair<int, int>e1(a,b);
    enemigos.push_back(e1);
  }
  list<int>DisparosEfectuados;
  //std::cerr << "llego: " << std::endl;
  int G=genkidama(n,t,enemigos,&DisparosEfectuados);
  //std::cerr << "Respuesta: " << std::endl;
  cout << G << endl;
  //std::cerr << "Respuesta: " << std::endl;
  //std::cerr << G << std::endl;

  int cantDisparos=DisparosEfectuados.size();
  //muestro los disparos efectuados
  for(int i=0; i < cantDisparos-1; i++) {
    cout << DisparosEfectuados.front() + 1 << ' ';
    //  cerr << DisparosEfectuados.front() + 1 << ' ';
    DisparosEfectuados.pop_front();
  }
    std::cout << DisparosEfectuados.front() + 1 << std::endl;
  //  std::cerr << DisparosEfectuados.back() << std::endl;
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
