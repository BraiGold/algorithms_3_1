#!/bin/bash 

LC_NUMERIC="en_US.UTF-8"

iteraciones=1
#n="50 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000" 
#cota="2000"
n=18
cota=500
m=1
b=0
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

#genero archivos de entrada
printf "%d %d \n" $n $cota $m $b | $(dirname $0)/generador #parametros del programa generador de archivos de entrada (n, cota) 
printf "%d %d \n" $n $cota | $(dirname $0)/generador2 #parametros del programa generador de archivos de entrada (n, t, cota) 


printf "%d \n" $iteraciones >> $(dirname $0)/tiempos-exp4.txt

  printf "%d " 1 >> $(dirname $0)/tiempos-exp4.txt
  for h in $(seq 1 $iteraciones); do
     $(dirname $0)/../../../kamehameha < $(dirname $0)/puntosAlineados-$n.txt -t >> $(dirname $0)/tiempos-exp4.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp4.txt

 printf "%d " 2 >> $(dirname $0)/tiempos-exp4.txt
  for h in $(seq 1 $iteraciones); do
    echo "estoy corriendo la iteracion numero"
    printf "%d\n" $h
     $(dirname $0)/../../../kamehameha < $(dirname $0)/puntosNOalineados-$n.txt -t >> $(dirname $0)/tiempos-exp4.txt
  done
  printf "\n" >> $(dirname $0)/tiempos-exp4.txt



  printf "%d \n" $iteraciones >> $(dirname $0)/tiemposSinPoda-exp4.txt

  printf "%d " 1 >> $(dirname $0)/tiemposSinPoda-exp4.txt
  for h in $(seq 1 $iteraciones); do
     $(dirname $0)/../../../kamehamehaSinPoda < $(dirname $0)/puntosAlineados-$n.txt -t >> $(dirname $0)/tiemposSinPoda-exp4.txt
  done
  printf "\n" >> $(dirname $0)/tiemposSinPoda-exp4.txt

 printf "%d " 2 >> $(dirname $0)/tiemposSinPoda-exp4.txt
  for h in $(seq 1 $iteraciones); do
    echo "estoy corriendo la iteracion numero"
    printf "%d\n" $h
     $(dirname $0)/../../../kamehamehaSinPoda < $(dirname $0)/puntosNOalineados-$n.txt -t >> $(dirname $0)/tiemposSinPoda-exp4.txt
  done
  printf "\n" >> $(dirname $0)/tiemposSinPoda-exp4.txt

#octave -q $(dirname $0)/exp1.m