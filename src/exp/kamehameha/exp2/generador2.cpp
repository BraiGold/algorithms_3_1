#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string
#include <utility>      // std::pair, std::get
#include <vector>


using namespace std;

bool AlineadoConOtroEnelVector(vector<pair<int,int> > vec, pair<int, int> par){
	bool res = false;
	for(int i = 0; i < vec.size() - 1; i++){
		for(int j = i + 1; j < vec.size(); j++){
			if((vec[i].first-par.first)*(vec[j].second-par.second) == (vec[j].first-par.first)*(vec[i].second-par.second)){
				res = true;
			}
		}
	}
	return res;
}

int main() {
	FILE * doc;
	
	int n, cota;
	cin >> n >> cota;
	
	char filename[64];
	sprintf(filename, "puntosNOalineados-%d.txt", n);
	
	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc,"%d\n",n);
			//int randNum = rand()%(max-min + 1) + min;

		int LOW = 0;
		int HIGH = cota;
		int x1;
		int y1;
		int x2;
		int y2;
		int m;
		int b;

		vector<pair<int, int> > randoms;
		
		time_t seconds;
		time(&seconds);
		srand((unsigned int) seconds);
		m = rand() % (2 - LOW + 1) + LOW;
		b = rand() % (HIGH - LOW + 1) + LOW;
		x1 = rand() % (HIGH - LOW + 1) + LOW;
		y1 = x1 * m + b;

		pair<int,int> p1(x1,y1);
		x2 = x1 * 2;
		y2 = y1 * 2;
		pair<int,int> p2(x2,y2);

		randoms.push_back(p1);
		randoms.push_back(p2);
		fprintf(doc, "%d %d\n", p1.first, p1.second);
		fprintf(doc, "%d %d\n", p2.first, p2.second);

		for(int i = 0; i < n - 2; i++){
			m = rand() % (2 - LOW + 1) + LOW;
			b = rand() % (HIGH - LOW + 1) + LOW;
			x1 = rand() % (HIGH - LOW + 1) + LOW;
			y1 = x1 * m + b;
	
			pair<int,int> p1(x1,y1);
			
				while(AlineadoConOtroEnelVector(randoms, p1)){
					m = rand() % (2 - LOW + 1) + LOW;
					b = rand() % (HIGH - LOW + 1) + LOW;
					cerr << b << endl;
					x1 = rand() % (HIGH - LOW + 1) + LOW;
					y1 = x1 * m + b;
					p1.first = x1;
					p1.second = y1;

				}

			randoms.push_back(p1);
			fprintf(doc, "%d %d\n", p1.first, p1.second);

		}

	}

    	fclose(doc);

	return 0;
}

