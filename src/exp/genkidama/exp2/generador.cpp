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

int random() {
	return rand() % 1000 + (rand() % 1000) * 1000 + (rand() % 1000) * 1000000
}


int main() {
	FILE * doc;
	
	int n, t, cota;
	cin >> n >> t >> cota;  // n < cota
	
	int x, x_anterior, y, y_anterior;
	vector<int > randoms_x;
	vector<int > randoms_y;


	char filename[64];
	sprintf(filename, "puntosRandom-%d.txt", n);
	

	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc, "%d %d\n",n ,t);
		time_t seconds;
		time(&seconds);
		srand((unsigned int) seconds);
	
		int LOW = 0;
		int HIGH = cota;
		int x;
		int y;

		
		for(int i = 0; i < n; i++){


				//creo un nuevo x
				x = random() % (HIGH - LOW + 1) + LOW;
			
				while(EstaEnelVector(randoms_x, x)){
					x = random() % (HIGH - LOW + 1) + LOW;
				}
				randoms_x.push_back(x);

				//creo un nuevo y
				y = random() % (HIGH - LOW + 1) + LOW;
			
				while(EstaEnelVector(randoms_y, y)){
					y = random() % (HIGH - LOW + 1) + LOW;
				}
				randoms_y.push_back(y);

		}

		
		sort(randoms_x.begin(), randoms_x.end()); //ordeno los x
		reverse(randoms_x.begin(), randoms_x.end()); //doy vuelta los x
		sort(randoms_y.begin(), randoms_y.end()); //ordeno los y

	}

	for (int i = 0; i < n; i++) {
		fprintf(doc, "%d %d\n", randoms_x[i], randoms_y[i]);
	}
    	

    fclose(doc);

	return 0;
}