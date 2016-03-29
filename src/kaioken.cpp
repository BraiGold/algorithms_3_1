#include <stdio.h>      /* printf */
#include <math.h>       /* log */

#include <iostream>

using namespace std;

void kaioken (int cantGuerreros) {
	int cantMinPeleas = ceil(log2(cantGuerreros));
	int equipo;
	cout << cantMinPeleas << endl;
	for (int i = 1; i <= cantMinPeleas; i++) { 
		equipo = 1; 
		for (int h = 1; h <= cantGuerreros; h = h + pow(2, i-1)) {
			for (int k = 0; k <  pow(2,i-1) && (h + k <= cantGuerreros); k++ ) {
				cout << equipo << " ";
			}
			if (equipo == 1) {
				equipo = 2;
			} else {
				equipo = 1;
			}
		}
		cout << endl;
	}
}

int main() {
	int guerreros;
	cin >> guerreros;
	kaioken(guerreros);

	return 0;
}
