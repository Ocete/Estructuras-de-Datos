#!/bin/bash
inicio=1000
fin=300000
incremento=1000
ejecutable="mergesort"
salida="tiempos_mergesortUmbralAlto.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
  echo "Ejecución tam =" $i
  echo `./$ejecutable $i` >> $salida
  i=$[$i+$incremento]
done
