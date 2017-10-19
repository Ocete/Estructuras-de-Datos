#!/bin/bash
inicio=100
fin=2000
incremento=100
ejecutable="MM"
salida="tiempos_MM.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
  echo "Ejecución tam =" $i
  echo `./$ejecutable $i` >> $salida
  i=$[$i+$incremento]
done
