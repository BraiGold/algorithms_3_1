#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string

using namespace std;

int main() {
	FILE * doc;
	
	int n, t, cota;
	cin >> n >> t >> cota;  // n < cota
	
	int x, x_anterior, y, y_anterior;


	char filename[64];
	sprintf(filename, "puntosRandom-%d.txt", t);
	

	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc, "%d %d\n",n ,t);

			//int randNum = rand()%(max-min + 1) + min;
		x_anterior = rand() % (cota - n +1) + n; // entre n y cota
		y_anterior = rand() % (cota - n +1) + 0; //entre 0 y cota-n

		fprintf(doc, "%d %d\n", x_anterior, y_anterior);

  		int cuantosPtosFaltan = n - 1 ; 

		for(int i=0; i<n-1; i++){
			x = rand() % (x_anterior) + 0; //entre 0 y x_anterior - 1
			while(x < cuantosPtosFaltan){
			x = rand() % (x_anterior) + 0; //entre 0 y x_anterior - 1
			}
			y = rand() % ((cota - cuantosPtosFaltan) - (y_anterior + 1) +1) + (y_anterior + 1); // entre (y_anterior + 1) y (cota - cuantosPtosFaltan)
			while(y < cota - cuantosPtosFaltan){
			y = rand() % ((cota - cuantosPtosFaltan) - (y_anterior + 1) +1) + (y_anterior + 1); // entre (y_anterior + 1) y (cota - cuantosPtosFaltan)
			}
	
			fprintf(doc, "%d %d\n", x, y);

			x_anterior = x;
			y_anterior = y;
			cuantosPtosFaltan--;

		}

    	fclose(doc);
	}

	return 0;
}