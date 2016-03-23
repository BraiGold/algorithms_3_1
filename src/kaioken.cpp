#include "./kaioken.h"


void kaioken (int cantGuerreros) {
	int cantMinPeleas = log2(cantGuerreros);
	cantMinPeleas = ceil(cantMinPeleas);
	for (int i = 1; i <= cantMinPeleas; i++) { 
		for (int h = 1; h <= 2^i; h++) {
			for (int k = 1; k <= cantGuerreros/ (2^i); k++ ) {
				if ( h % 2 == 0) { 
					printf("%d",1);
				} else {
					printf("%d",2);
				}
			}
		}
		printf("\n");	
	}
}