#include "./kaioken.h"


void kaioken (int cantGuerreros) {
	double cantMinPeleas = log2(cantGuerreros); 
	cantMinPeleas = ceil(cantMinPeleas);
	int equipo;
	cout << cantMinPeleas << endl;
	//printf("%d",cantMinPeleas);
	printf("\n");
	for (int i = 1; i <= cantMinPeleas; i++) { 
		equipo = 1; 
		for (int h = 1; h <= cantGuerreros; h = h + ceil(cantGuerreros/pow(2, i))) {
			for (int k = 0; k < ceil(cantGuerreros/ pow(2,i)) & (h + k <= cantGuerreros); k++ ) {
				printf("%d", equipo);
			}
			if (equipo == 1) {
				equipo = 2;
			} else {
				equipo = 1;
			}
		}
		printf("\n");
	}
}