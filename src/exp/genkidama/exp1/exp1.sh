#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
n="$(seq 100000 10000 200000)" 
t="1000" 
cota="1000000"

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
  esac
done

#genero archivos de entrada
#for i in $n; do
#  echo "Esta creando el archivo numero"
#  printf "%d\n " $i
#  printf "%d %d %d \n" $i $t $cota | $(dirname $0)/generador #parametros del programa generador de archivos de entrada (n, t, cota) 
#done 

printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp1.txt

for k in $n; do
  printf "%d " $k >> $(dirname $0)/tiempos-exp1.txt
  echo "Esta corriendo la instancia numero"
  printf "%d\n " $k
  for h in $(seq 1 $iteraciones); do
    echo "iteracion numero"
    printf "%d\n " $h
     $(dirname $0)/../../../genkidama < $(dirname $0)/puntosRandom-$k.txt -t >> $(dirname $0)/tiempos-exp1.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp1.txt
done

octave -q $(dirname $0)/exp1.m