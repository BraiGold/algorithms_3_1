#include <iostream>     //cin cout
#include <stdio.h>      // printf fopen fclose fputs 
#include <stdlib.h>     //
#include <string>       //to_string

using namespace std;

int main() {
	FILE * doc;
	
	int n, t, cota;
	cin >> n >> t;  
	cota = 50 * n;
	
	char filename[64];
	sprintf(filename, "puntosSeparados-%d.txt", t);
	

	doc = fopen(filename,"w");

	if (doc!=NULL) {
  	
		fprintf(doc, "%d %d\n",n ,t);

  		int x = cota;
  		int y = 0;

		for(int i=0; i<n; i++){
				
			fprintf(doc, "%d %d\n", x, y);
			x = x - 50;
			y = y + 50;
		}

    	fclose(doc);
	}

	return 0;
}