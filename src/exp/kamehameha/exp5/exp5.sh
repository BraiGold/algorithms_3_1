LC_NUMERIC="en_US.UTF-8"

iteraciones=1

n="3 6 9 12 15 18"

cota=500


while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 4 - Compara tiempo de ejecución en casos borde con y sin poda"
       echo ""
       echo "    Opciones disponibles:"
       echo "        -h        Imprime este texto de ayuda."
       echo "        -a <núm>  Cantidad de iteraciones - por defecto 1"
       echo ""
       exit 0 ;;
  esac
done

for i in $n; do
printf "%d %d \n" $i $cota | $(dirname $0)/generadorAlineadosC3 #parametros del programa generador de archivos de entrada (n, cota) 
done


printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp5-sin.txt
printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp5-con.txt

  for k in $n; do
  	printf "%d " $k >> $(dirname $0)/tiempos-exp5-sin.txt
  	for h in $(seq 1 $iteraciones); do
     	$(dirname $0)/../../../kamehamehaSinPoda < $(dirname $0)/puntosAlineadosC3-$k.txt -t >> $(dirname $0)/tiempos-exp5-sin.txt
 	done
  printf "\n" >> $(dirname $0)/tiempos-exp5-sin.txt
  done



  for k in $n; do
  	printf "%d " $k >> $(dirname $0)/tiempos-exp5-con.txt
  	for h in $(seq 1 $iteraciones); do
     $(dirname $0)/../../../kamehameha < $(dirname $0)/puntosAlineadosC3-$k.txt -t >> $(dirname $0)/tiempos-exp5-con.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp5-con.txt
done