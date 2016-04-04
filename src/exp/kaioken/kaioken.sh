#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
n="5 10 15" 


while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 1 - Tiempo de ejecución variando cantidad de guerreros"
       echo ""
       echo "    Opciones disponibles:"
       echo "        -h        Imprime este texto de ayuda."
       echo "        -a <núm>  Cantidad de iteraciones - por defecto 1"
       echo ""
       exit 0 ;;
  esac
done



#genero archivos de entrada

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp1.txt

for k in $n; do
  printf "%d " $k >> $(dirname $0)/tiempos-exp1.txt
  for h in $(seq 1 $iteraciones); do
    printf "%d " $k |  $(dirname $0)/../../kaioken -t >> $(dirname $0)/tiempos-exp1.txt
  done
  printf "\n">> $(dirname $0)/tiempos-exp1.txt
done

#octave -q $(dirname $0)/exp1.m
