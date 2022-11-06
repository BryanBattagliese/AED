#include <iostream>
#include <array>
#include <fstream>

/* Consigna: Calcular el promedio de ventas por mes. */

int promedio (Cubo&,int,int);

using std::array;
using Cubo = array<array<array<unsigned,12>,3>,4>;

int promedio (Cubo&total,int mes,int region)
{
    int sum{};
    for(auto meses : total.at(region))
        sum += meses.at(mes);

    return sum/total.at(region).size();    
}

int main ()
{   
    Cubo total{0};

    std::fstream file;
    file.open("dim3.txt");

    for(unsigned venta, mes, vendedor, region; file >> region >> vendedor >> mes >> venta ;)
        total[region][vendedor][mes] += venta;
        
    std::cout << "Promedio de ventas por mes:" << '\n';

    for(int k{0}; k<4; ++k)
    {   std::cout << '\n' << "Region " << k << '\n';    
            
        for(int j{0};j<12;++j)
            std::cout <<  "Mes " << j << " = " << promedio(total,j,k) << '\n';      
    }; 
      
}

