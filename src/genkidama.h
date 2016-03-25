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
