#include "cronologia.h"
#include "fecha_historica.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=3){
      cout<<"Dime los nombres de los ficheros con las cronologias " << endl;
      return 0;
   }

   ifstream f1 (argv[1]), f2 (argv[2]);
   if (!f1 || !f2){
    cout << "No puedo abrir alguno de los ficheros." << endl;
    return 0;
   }

   Cronologia cron1, cron2, cronMerged, cronIntersec;
   f1 >> cron1;
   f2 >> cron2;

   //cron1.print();
   //cron2.print();

   cronMerged = cron1.mergeCron(cron2);
   cronIntersec = cron1.intersecCron(cron2);

   cout << "\t\tUnión de ambas cronologías : " << endl;
   cronMerged.print();
   cout << "\n\n\n\n\n\t\tIntersección de ambas cronologías: " << endl;
   cronIntersec.print();
   cout << "\n\n\n\n\n\t\tSubcronología de la intersección entre 1980 y 2000: " << endl;
   cronIntersec.subcronologia(1990, 2000).print();
   cout << "\n\n\n\n\n\t\tSubcronología de la unión con la palabra \"developed\": " << endl;
   cronMerged.subcronologia("developed").print();
   cout << "\n\n\n\n\n\t\tEventos en el año 1999 de ambas cronologías: " << endl;
   cronMerged.getFechaHistorica(1999)->print();

   /* Exhibir aquí la funcionalidad programada para el TDA Cronologia / TDA FechaHistorica */

   // Algunas sugerencias:
   // - Obtener los eventos acaecidos en un año dado -> cronologia.getFechaHistorica(int fecha);
   // DONE - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // DONE - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // DONE - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)


}
