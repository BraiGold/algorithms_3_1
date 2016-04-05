#include <stdio.h>      /* printf */
#include <math.h>       /* log */
#include <utility>      // std::pair, std::get
#include <iostream>     // std::cout
#include <list>
#include <vector>
#include <cstdio>
#include <sys/time.h>

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



int main(int argc, char* argv[]) {
  bool pidieronTiempo = false; 
  double tiempo;
  if (argc > 1) {
    if (argv[1] == string("-t")) {
      pidieronTiempo = true;
    }
  }
  int n,t,a,b;
  cin >> n >> t;
  vector<std::pair<int,int> > enemigos;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    std::pair<int, int>e1(a,b);
    enemigos.push_back(e1);
  }
  list<int>DisparosEfectuados;

  init_time();
  int G=genkidama(n,t,enemigos,&DisparosEfectuados);
  tiempo = get_time();

  if (!pidieronTiempo) { 
    cout << G << endl;

    int cantDisparos=DisparosEfectuados.size();
    for(int i=0; i < cantDisparos-1; i++) {
      cout << DisparosEfectuados.front() + 1 << ' ';
    DisparosEfectuados.pop_front();
    }
      cout << DisparosEfectuados.front() + 1 << endl;
  }

  if (pidieronTiempo) {
     printf("%.10f ", tiempo);
  }

}