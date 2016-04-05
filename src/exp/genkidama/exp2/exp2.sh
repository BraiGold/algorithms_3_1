#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
n="10" 
t="50 70 80" 
cota="500"

while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 2 - Tiempo de ejecución variando el t"
       echo ""
       echo "    Opciones disponibles:"
       echo "        -h        Imprime este texto de ayuda."
       echo "        -a <núm>  Cantidad de iteraciones - por defecto 1"
       echo ""
       exit 0 ;;
  esac
done


#genero archivos de entrada
for i in $t; do
  printf "%d %d %d \n" $n $i $cota | $(dirname $0)/generador #parametros del programa generador de archivos de entrada (n, t, cota) 
done 

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp2.txt

for k in $t; do
  printf "%d " $k >> $(dirname $0)/tiempos-exp2.txt
  for h in $(seq 1 $iteraciones); do
     $(dirname $0)/../../../genkidama < $(dirname $0)/puntosRandom-$k.txt -t >> $(dirname $0)/tiempos-exp2.txt
  done
  printf "\n">> $(dirname $0)/tiempos-exp2.txt
done

octave -q $(dirname $0)/exp2.m
