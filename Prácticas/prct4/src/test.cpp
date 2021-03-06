// José Antonio Álvarez Ocete
// Yábir García Benchakhtir

#include "Chronology.h"
#include "historic_date.h"
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


   Chronology cron1, cron2, cronMerged, cronIntersec;
   f1 >> cron1;
   f2 >> cron2;

   //cron1.print();
   //cout << cron1;
   //cron2.print();

   cron1.mergeCron(cron2, cronMerged);
   cron1.intersecCron(cron2, cronIntersec);

   //cout << "\t\tUnión de ambas cronologías : " << endl;
   //cronMerged.print();

   cout << "===================================" << endl;
   cout << "Intersección de ambas cronologías: " << endl;
   cout << "===================================" << endl;
   cout << cronIntersec;

   cout << "===================================" << endl;
   cout << "Subcronología de la intersección entre 1990 y 2000: " << endl;
   cout << "===================================" << endl;
   //cout << "\n\n\n\n\n\t\tSubcronología de la intersección entre 1990 y 2000: " << endl;
   cronIntersec.subChronology(1990, 2000).print();

   cout << "===================================" << endl;
   cout << "Subcronología de la intersección con la palabra \"developed\": " << endl;
   cout << "===================================" << endl;
   //cout << "\n\n\n\n\n\t\tSubcronología de la intersección con la palabra \"developed\": " << endl;
   cronIntersec.subChronology("developed").print();

   cout << "===================================" << endl;
   cout << "Eventos en el año 2002 de ambas cronologías: " << endl;
   cout << "===================================" << endl;
   //cout << "\n\n\n\n\n\t\tEventos en el año 2002 de ambas cronologías: " << endl;
   cronMerged.getHistoricDate(2002).print();

   cout << "===================================" << endl;
   cout << "Media de eventos por año: ";
   cout << cron1.mean() << endl;
   cout << "Año con más eventos en la cronología 1: " << endl;
   cron1.trend().print();
   cout << "Total de eventos: " << cron1.numEvents() << endl;
   cout << "Total de años: " << cron1.numYears() << endl;

   /* Exhibir aquí la funcionalidad programada para el TDA Chronology / TDA HistoricDate */

   // Algunas sugerencias:
   // - Obtener los eventos acaecidos en un año dado -> Chronology.getHistoricDate(int fecha);
   // DONE - Obtener la (sub)cronología de eventos históricos acaecidos en [anioDesde, anioHasta], donde anioDesde y anioHasta son proporcionados por el usuario
   // DONE - Obtener la (sub)cronología de eventos históricos asociados a una palabra clave. Ejemplo: la cronología de eventos asociados a "Einstein"
   // DONE - Operadores sobre cronologías, ejemplo: Unión de dos cronologías (la cronología resultante debería estar ordenada)


}
