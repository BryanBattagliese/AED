#include <iostream>
#include <array>
#include <string>
#include <fstream>

/* Consigna 4: DIM 3
   Dado los importes, meses, números de los tres vendedores, y
   números de las cuatro regiones (0, 1, 2, 4), mostrar total de ventas por mes,
   vendedor, y región.
*/


int main ()
{
    using std::array;
    std::fstream file;
    array<array<array<unsigned,12>,3>,4> total{0};
    
    file.open("dim3.txt");

    for(unsigned venta, mes, vendedor, region; file >> venta >> mes >> vendedor >> region;)
        total[region][vendedor][mes] += venta;
        
    std::cout << "TOTAL DE VENTAS" << '\n';

    for(int k{0}; k<4; ++k)
    {   std::cout << '\n' << "REGION " << k << '\n';
      
      for(int i{0}; i<3; ++i)
      {   std::cout << '\n' << "VENDEDOR " << i << '\n';    
            
            for(int j{0};j<12;++j)
                std::cout <<  "MES " << j << " = " << total[k][i][j]<< '\n';      
      }; 
    }  
}
