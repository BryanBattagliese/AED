#include <iostream>
#include <array>

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
   std::array<unsigned,12> total{0};
   
   std::cout << "Ingrese importe de la venta y mes correspondiente" << '\n';

   for(unsigned venta, mes; std::cin >> venta >> mes;)
      total.at(mes) += venta;

   std::cout << "TOTAL DE VENTAS" << '\n';

   for(int i{0}; i<12 ;++i)
      std::cout << '\n' << " Mes " << i << " = " << total.at(i) << '\n';
}