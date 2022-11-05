#include <iostream>
#include <array>
#include <fstream>

/* Consigna 2: DIM 1
   Dado los importes y meses (de 0 a 11), mostrar ventas totales
   por mes.
*/

/* ANALISIS:
   (VENTA x mes) * --> P --> VENTA´12 (venta'12 = array)
   (VENTA =  N)

*/

int main ()
{
   std::fstream file;
   std::array<unsigned,12> total{0};
   
   file.open("dim1.txt");

   for(unsigned venta, mes; file >> venta >> mes;)
      total.at(mes) += venta;

   std::cout << "TOTAL DE VENTAS" << '\n';

   for(int i{0}; i<12 ;++i)
      std::cout << '\n' << " Mes " << i << " = " << total.at(i) << '\n';
}
