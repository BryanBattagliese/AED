#include <iostream>
#include <array>

/* Consigna 3: DIM 2
   Dado los importes, meses, y números de los tres vendedores
   (0, 1, 2), mostrar total de ventas por mes y vendedor.
*/

int main ()
{
    using std::array;
    array<array<unsigned,12>,3> total{0};

    std::cout << "Ingrese importe de la venta, mes y vendedor correspondiente" << '\n';

    for(unsigned venta, mes, vendedor; std::cin >> venta >> mes >> vendedor;)
        total[vendedor][mes] += venta;
        
    std::cout << "TOTAL DE VENTAS" << '\n';

    for(int i{0}; i<3; ++i)
    {   std::cout << '\n' << "VENDEDOR " << i << '\n';    
            for(int j{0};j<12;++j)
                std::cout <<  "MES " << j << " = " << total[i][j]<< '\n';      
    };
}