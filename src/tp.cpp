#include "./kaioken.cpp"
#include "./genkidama.cpp"
#include "./kamehameha.cpp"

int main(int argc, char* argv[]) {
	cout << "resuelvo kaioken:\n";
	kaioken(8);

	cout << "\n Resuelvo genikidama:\n";


	std::pair<int,int>e1(100,0);
	std::pair<int,int>e2(75,25);
	std::pair<int,int>e3(50,50);
	std::pair<int,int>e4(25,75);
	std::pair<int,int>e5(0,100);
	std::vector<std::pair<int,int> > enemigos;
	enemigos.push_back(e1);
	enemigos.push_back(e2);
	enemigos.push_back(e3);
	enemigos.push_back(e4);
	enemigos.push_back(e5);

	list<int>DisparosEfectuados;
	int G=genkidama(5,26,enemigos,&DisparosEfectuados);
//	cout << G;
  int cantDisparos=DisparosEfectuados.size();

	//muestro los disparos efectuados
	for(int i=0; i< cantDisparos; ++i){
  	std::cout << DisparosEfectuados.back() << ' ';
		DisparosEfectuados.pop_back();

	}
	std::cout << std::endl;

    return 0;
}
