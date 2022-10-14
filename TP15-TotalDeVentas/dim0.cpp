#include <iostream>  

/* Consigna 1: DIM 0
   Dado los importes, mostrar ventas totales.
*/

/* ANALISIS:

   VENTA* --> P --> VENTA (entran multiplicidad de ventas, tambien puede entrar 0)
   VENTA = N              (ventas = natural)

*/

int main ()
{
   unsigned total {0};                           
   
   for(unsigned venta; std::cin >> venta;)       
      total += venta;                           
      std::cout << "Total de ventas "<< " = " << total << '\n';                
}