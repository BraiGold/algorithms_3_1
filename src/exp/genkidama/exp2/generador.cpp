#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string
#include <vector>
#include <algorithm>    // std::sort

using namespace std;

bool EstaEnelVector(vector<int > vec, int n) {
	int i = 0;
	bool loEncontre = false;
	while(i < vec.size() && !loEncontre) {
		if(vec[i] == n){
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
	
	int min_t = 1000;
	int salto_de_a = 500;
	int max_t = 10000;

	int n, t, cota;
	cin >> n >> cota >> min_t >> salto_de_a >> max_t;  // n < cota
  	
	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);
	
	int x, y;
	vector<int > randoms_x;
	vector<int > randoms_y;

	int LOW = 0;
	int HIGH = cota;

		
	for(int i = 0; i < n; i++){

				//creo un nuevo x
				x = randombis() % (HIGH - LOW + 1) + LOW;
			
				while(EstaEnelVector(randoms_x, x)){
					x = randombis() % (HIGH - LOW + 1) + LOW;
				}
				randoms_x.push_back(x);

				//creo un nuevo y
				y = randombis() % (HIGH - LOW + 1) + LOW;
			
				while(EstaEnelVector(randoms_y, y)){
					y = randombis() % (HIGH - LOW + 1) + LOW;
				}
				randoms_y.push_back(y);

	}

		
		sort(randoms_x.begin(), randoms_x.end()); //ordeno los x
		reverse(randoms_x.begin(), randoms_x.end()); //doy vuelta los x
		sort(randoms_y.begin(), randoms_y.end()); //ordeno los y

	for (t = min_t; t <= max_t; t = t + salto_de_a) { //para cada t, genero un nuevo archivo. Los puntos son siempre los mismos
		char filename[64];
		sprintf(filename, "puntosRandom-%d.txt", t);
		doc = fopen(filename,"w");
		if (doc!=NULL) {
			fprintf(doc, "%d %d\n",n ,t);
			for (int i = 0; i < n; i++) {
				fprintf(doc, "%d %d\n", randoms_x[i], randoms_y[i]);
			}
    		fclose(doc);
		}
	}


	return 0;
}