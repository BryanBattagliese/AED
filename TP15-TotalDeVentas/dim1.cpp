#include <iostream>
#include <array>

/* Consigna 2: DIM 1
   Dado los importes y meses (de 0 a 11), mostrar ventas totales
   por mes.
*/

/* ANALISIS:
   (VENTA x mes) * --> P --> VENTA´12 (venta'12 = array)
   (VENTA =  N)

   ej- (venta en $, mes)
       (5,0) : (7,2) : (3,11) --->  $5 en enero; $7 en marzo; $3 en diciembre ...
*/

int main ()
{
   std::array<unsigned,12> total{0};
   
   for(unsigned venta, mes; std::cin >> venta >>mes;)
      total.at(mes) += venta;

   for(int i{0}; i<12 ;++i)
      std::cout << total.at(i) << '\n'; 
}