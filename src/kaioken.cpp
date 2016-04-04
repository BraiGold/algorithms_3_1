#include <stdio.h>      /* printf */
#include <math.h>       /* log */

#include <iostream>
#include <cstdio>
#include <sys/time.h>

using namespace std;

timeval timeStart, timeEnd;

void init_time()
{
    gettimeofday(&timeStart,NULL);
}

double get_time()
{
    gettimeofday(&timeEnd,NULL);
    return (1000000*(timeEnd.tv_sec-timeStart.tv_sec)+(timeEnd.tv_usec-timeStart.tv_usec))/1000000.0;
}

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

void kaiokenTiempo (int cantGuerreros) {
	int cantMinPeleas = ceil(log2(cantGuerreros));
	int equipo;
	for (int i = 1; i <= cantMinPeleas; i++) { 
		equipo = 1; 
		for (int h = 1; h <= cantGuerreros; h = h + pow(2, i-1)) {
			for (int k = 0; k <  pow(2,i-1) && (h + k <= cantGuerreros); k++ ) {
			}
			if (equipo == 1) {
				equipo = 2;
			} else {
				equipo = 1;
			}
		}
	}
}

int main(int argc, char* argv[]) {

	bool pidieronTiempo = false; 
  	double tiempo;
  	if (argc > 1) {
    	if (argv[1] == string("-t")) {
      	pidieronTiempo = true;
    	}
  	}

	int guerreros;
	cin >> guerreros;
	
	if (pidieronTiempo) {
		init_time();
		kaiokenTiempo(guerreros);
		tiempo = get_time();
		printf("%.10f ", tiempo);
	} else { 
		kaioken(guerreros);
	}

	return 0;
}
