#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
n="10000" 
t="4 50" 

while getopts 'ha:' opt; do
  case $opt in
    a) iteraciones=$OPTARG ;;
    h) echo ""
       echo "    Experimento 3 - Tiempo de ejecución en casos borde"
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
  printf "%d %d \n" $n $i | $(dirname $0)/generadorJuntos #parametros del programa generador de archivos de entrada (n, t)
  printf "%d %d \n" $n $i | $(dirname $0)/generadorSeparados #parametros del programa generador de archivos de entrada (n, t) 

done 
printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp3.txt

printf "%d " 1 >> $(dirname $0)/tiempos-exp3.txt
  
for h in $(seq 1 $iteraciones); do
  $(dirname $0)/../../../genkidama < $(dirname $0)/puntosJuntos-4.txt -t >> $(dirname $0)/tiempos-exp3.txt
done
printf "\n">> $(dirname $0)/tiempos-exp3.txt


printf "%d " 2 >> $(dirname $0)/tiempos-exp3.txt

for h in $(seq 1 $iteraciones); do
  $(dirname $0)/../../../genkidama < $(dirname $0)/puntosJuntos-50.txt -t >> $(dirname $0)/tiempos-exp3.txt
done
printf "\n">> $(dirname $0)/tiempos-exp3.txt


printf "%d " 3 >> $(dirname $0)/tiempos-exp3.txt

for h in $(seq 1 $iteraciones); do
  $(dirname $0)/../../../genkidama < $(dirname $0)/puntosSeparados-4.txt -t >> $(dirname $0)/tiempos-exp3.txt
done
printf "\n">> $(dirname $0)/tiempos-exp3.txt


printf "%d " 4 >> $(dirname $0)/tiempos-exp3.txt

for h in $(seq 1 $iteraciones); do
  $(dirname $0)/../../../genkidama < $(dirname $0)/puntosSeparados-50.txt -t >> $(dirname $0)/tiempos-exp3.txt
done
printf "\n">> $(dirname $0)/tiempos-exp3.txt


#octave -q $(dirname $0)/exp3.m
