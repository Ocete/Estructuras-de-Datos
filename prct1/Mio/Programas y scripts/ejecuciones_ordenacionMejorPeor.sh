#!/bin/bash
inicio=100
fin=30000
incremento=500
ejecutable="ordenacionMejorPeor"
salida1="tiempos_ordenacionMejor.dat"
salida2="tiempos_ordenacionPeor.dat"

i=$inicio
echo > $salida1
echo > $salida2
while [ $i -lt $fin ]
do
  echo "Ejecución tam =" $i
  echo `./$ejecutable $i 10000 1` >> $salida1
  echo `./$ejecutable $i 10000 0` >> $salida2
  i=$[$i+$incremento]
done
