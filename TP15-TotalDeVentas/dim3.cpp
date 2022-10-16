#include <iostream>
#include <array>
#include <string>

/* Consigna 4: DIM 3
   Dado los importes, meses, números de los tres vendedores, y
   números de las cuatro regiones (0, 1, 2, 3), mostrar total de ventas por mes,
   vendedor, y región.
*/


int main ()
{
    using std::array;
    array<array<array<unsigned,12>,3>,4> total{0};

    std::cout << "Ingrese importe de la venta, mes, vendedor y region correspondiente" << '\n';

    for(unsigned venta, mes, vendedor, region; std::cin >> venta >> mes >> vendedor >> region;)
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
