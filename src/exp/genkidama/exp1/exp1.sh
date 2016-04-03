#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=3
n="5 10 15" 
t="50" 
cota="500"

while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 1 - Tiempo de ejecución variando cantidad de enemigos"
       echo ""
       echo "    Opciones disponibles:"
       echo "        -h        Imprime este texto de ayuda."
       echo "        -a <núm>  Cantidad de iteraciones - por defecto 1"
       echo ""
       exit 0 ;;
    c) if [ -d $(dirname $0)/exp1 ]; then rm $(dirname $0)/exp1 -R; fi
       exit 0 ;;
  esac
done




#genero archivos de entrada
for i in $n; do
  printf "%d %d %d \n" $i $t $cota | $(dirname $0)/generador #parametros del programa generador de archivos de entrada (n, t, cota) 
done 

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos.txt

for k in $n; do
  printf "%d " $k >> $(dirname $0)/tiempos.txt
  for h in $(seq 1 $iteraciones); do
     $(dirname $0)/../../../genkidama < $(dirname $0)/puntosRandom-$i.txt -t >> $(dirname $0)/tiempos.txt
  done
  printf "\n">> $(dirname $0)/tiempos.txt
done

#octave -q $(dirname $0)/exp1.m
