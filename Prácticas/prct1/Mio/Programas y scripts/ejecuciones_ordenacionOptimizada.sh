#!/bin/bash
inicio=100
fin=30000
incremento=500
ejecutable="ordenacionOptimizada"
salida="tiempos_ordenacionOptimizada.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
  echo "Ejecución tam =" $i
  echo `./$ejecutable $i 10000` >> $salida
  i=$[$i+$incremento]
done
