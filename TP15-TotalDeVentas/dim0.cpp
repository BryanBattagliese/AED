#include <iostream>  
#include <fstream>

/* Consigna 1: DIM 0
   Dado los importes, mostrar ventas totales.
*/

/* ANALISIS:

   VENTA* --> P --> VENTA (entran multiplicidad de ventas, tambien puede entrar 0)
   VENTA = N              (ventas = natural)

*/

int main ()
{
   std::fstream file;
   unsigned total {0};

   file.open("dim0.txt");
   
   for(unsigned venta; file >> venta;)       
      total += venta;                           
      std::cout << "Total de ventas "<< " = " << total << '\n';                
}
