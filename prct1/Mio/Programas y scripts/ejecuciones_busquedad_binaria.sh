#!/bin/bash
inicio=10000
fin=3000000
incremento=50000
ejecutable="ejercicio_desc"
salida="tiempos_busquedad_binaria.dat"

i=$inicio
echo > $salida
while [ $i -lt $fin ]
do
  echo "Ejecución tam =" $i
  echo `./$ejecutable $i` >> $salida
  i=$[$i+$incremento]
done
