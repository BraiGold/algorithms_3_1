#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string
#include <utility>      // std::pair, std::get
#include <vector>


using namespace std;

int randombis() {
	return rand() % 1000 + (rand() % 1000) * 1000 + (rand() % 1000) * 1000000;
}

int main() {
	FILE * doc;
	
	int n, cota;
	cin >> n >> cota;
	
	char filename[64];
	sprintf(filename, "puntosAlineadosC3-%d.txt", n);
	
	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc,"%d\n",n);
			//int randNum = rand()%(max-min + 1) + min;

		int LOW = 0;
		int HIGH = cota;
		int x;
		int y;
		
		time_t seconds;
		time(&seconds);



		for(int i = 0; i < n; i = i + 3){
			x = i;
			y = randombis() % (HIGH - LOW + 1) + LOW;
			pair<int,int> p1(x,y);
			fprintf(doc, "%d %d\n", p1.first, p1.second);
			y = randombis() % (HIGH - LOW + 1) + LOW;
			pair<int,int> p2(x,y);
			fprintf(doc, "%d %d\n", p2.first, p2.second);
			y = randombis() % (HIGH - LOW + 1) + LOW;
			pair<int,int> p3(x,y);
			fprintf(doc, "%d %d\n", p3.first, p3.second);

	
						
			


		}

	}

    	fclose(doc);

	return 0;
}

