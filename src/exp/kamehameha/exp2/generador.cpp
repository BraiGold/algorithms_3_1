#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string
#include <utility>      // std::pair, std::get
#include <vector>


using namespace std;
bool EstaEnelVector(vector<pair<int,int> > vec, pair<int, int> par){
	int i = 0;
	bool loEncontre = false;
	while(i < vec.size() && !loEncontre){
		if(vec[i].first == par.first && vec[i].second == par.second){
			loEncontre = true;
		}
		i++;
	}
	return loEncontre;
}

int randombis() {
	return rand() % 1000 + (rand() % 1000) * 1000 + (rand() % 1000) * 1000000;
}


int main() {
	FILE * doc;
	
	int n, cota, m, b;
	cin >> n >> cota >> m >> b;
	
	char filename[64];
	sprintf(filename, "puntosAlineados-%d.txt", n);
	
	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc,"%d\n",n);
			//int randNum = rand()%(max-min + 1) + min;

		int LOW = 0;
		int HIGH = cota;
		int x;
		int y;

		vector<pair<int, int> > randoms;
		
		time_t seconds;
		time(&seconds);
		srand((unsigned int) seconds);
		for(int i = 0; i < n; i++){

			x = randombis() % (HIGH - LOW + 1) + LOW;
			y = x * m + b;
			pair<int,int> p(x,y);
			
				while(EstaEnelVector(randoms, p)){
					x = randombis() % (HIGH - LOW + 1) + LOW;
					y = x * m + b;
					p.first = x;
					p.second = y;

				}
			randoms.push_back(p);
			fprintf(doc, "%d %d\n", p.first, p.second);

		}

	}

    	fclose(doc);

	return 0;
}

