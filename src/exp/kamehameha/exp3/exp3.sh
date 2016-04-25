#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
#n="50 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000" 
#cota="2000"
n="5 7 9 10 11 12 13 14 15 16 17 18"
cota="500"
while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 3 - Comparando el algoritmo con poda y sin poda"
       echo ""
       echo "    Opciones disponibles:"
       echo "        -h        Imprime este texto de ayuda."
       echo "        -a <núm>  Cantidad de iteraciones - por defecto 1"
       echo ""
       exit 0 ;;
  esac
done

#genero archivos de entrada
for i in $n; do
  printf "%d %d \n" $i $cota | $(dirname $0)/generador #parametros del programa generador de archivos de entrada (n, t, cota) 
done 

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp3-conPoda.txt
printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp3-sinPoda.txt


for k in $n; do
  printf "%d " $k >> $(dirname $0)/tiempos-exp3-conPoda.txt
  for h in $(seq 1 $iteraciones); do
     $(dirname $0)/../../../kamehameha < $(dirname $0)/puntosRandom-$k.txt -t >> $(dirname $0)/tiempos-exp3-conPoda.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp3-conPoda.txt
done

for k in $n; do
  printf "%d " $k >> $(dirname $0)/tiempos-exp3-sinPoda.txt
  for h in $(seq 1 $iteraciones); do
     $(dirname $0)/../../../kamehameha < $(dirname $0)/puntosRandom-$k.txt -t >> $(dirname $0)/tiempos-exp3-sinPoda.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp3-sinPoda.txt
done


#octave -q $(dirname $0)/exp3.m