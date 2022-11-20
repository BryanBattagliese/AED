#include <iostream>
#include <fstream>
#include <array>

using namespace std;
using Cubo = array<array<array<unsigned,12>,3>,4>;

template <unsigned N, typename T = int>
struct mejores
{
    array<T,N>  a {};
    unsigned    id {};
};

/* ------------------------------------------------------------------------------------------------------------------------- */

void cargarDatos                (Cubo &);
void mostrarVentas              (Cubo &);
void mostrarDatos               (Cubo &);
void crearTXT                   (Cubo &);

int mayorVenta                  (Cubo &,int,int);
int promedioVenta               (Cubo &,int,int);
mejores<3> acumMejorVendedor    (const Cubo &,int,int);
void mostrarMejores             (const mejores<3>,int);
void mejoresVendedores          (const Cubo &,int,int);

/* ------------------------------------------------------------------------------------------------------------------------- */

int main ()
{	 
   	 Cubo                        total{};
    	  cargarDatos                 (total);
	  mostrarVentas               (total);
	  mostrarDatos                (total);
	  crearTXT                    (total);  
}

/* ------------------------------------------------------------------------------------------------------------------------- */

void cargarDatos (Cubo &total)               // DONE!!
{ 
    ifstream file2;
    std::fstream filedim;

	file2.open("file.bin", ios::in | ios::binary);
	file2.read(reinterpret_cast<char *>(&total), sizeof(total));
	filedim.open("dim3.txt");

    int v{}, m{}, r{}, importe{};
	    
    for (; filedim >> r >> v >> m >> importe;)
	    {
		    total.at(r - 1).at(v - 1).at(m - 1) += importe;
	    }
	
    file2.close();
}

void mostrarVentas (Cubo &total)             // DONE!!
{
    ofstream file;
	file.open("file.bin", ios::out | ios::binary);
	
    for (int i{}; i < 4; ++i)
	{   cout << '\n' << "Region: " << (i+1) << '\n';
		
        for (int j{}; j < 3; ++j)
		{   cout << '\n' << "Vendedor: " << (j+1) << '\n';
			
            for (int k{}; k < 12; ++k)
			{   cout << "En el mes: " << k + 1 << " vendio: "
                     << "$" << total[i][j][k] << '\n';
			}
		}
	}
	
    file.write(reinterpret_cast<char *>(&total), sizeof(total));
	file.close();
}

void mostrarDatos (Cubo &total)              // DONE!!
{
    for(int m{}; m<12; ++m)
    {  
        for(int r{}; r<4; ++r)
        {
            cout << '\n' << "El importe maximo para el mes "    << m+1 << " de la region " << r+1 
                 <<" fue de: $ " << mayorVenta (total,m,r);
            
            cout << '\n' << "El importe promedio para el mes "  << m+1 << " de la region " << r+1 
                 <<" fue de: $ " << promedioVenta (total,m,r) << '\n';
        
        }
    }

}

void crearTXT (Cubo &total)                  // DONE!!
{
    ofstream file3;
	file3.open("Vendedores.txt", ios::out);
	
    for (int i{}; i < 4; ++i)
	{
		file3 << '\n'
			  << " Region: " << (i) << '\n';
		
        for (int j{}; j < 3; ++j)
		{
			file3 << '\n'
				  << '\n' << " Vendedor: " << (j) << '\n';
			
            for (int k{}; k < 12; ++k)
			{
				file3 << " Durante el mes: " << k + 1 << " vendio: "
					  << "$" << total[i][j][k] << '\n';
			}
		}
	}
}

/* ------------------------------------------------------------------------------------------------------------------------- */

int mayorVenta (Cubo &total, int mes, int region)       // DONE!!
{   
    int sum {};
    for (auto ext : total.at(region))
        if(ext.at(mes) > sum)
        {
            sum = ext.at(mes);
        }
    
    return sum;
}

int promedioVenta (Cubo &total, int mes, int region)    // DONE!!
{
    int sum;
    for (auto ext : total.at(region))
        sum += ext.at(mes);
    
    return sum / (total.at(region).size());
}

mejores<3> acumMejorVendedor (Cubo &total, int mes, int region, int max)
{   
    mejores<3> vendedores;

    for (int idVen {}; idVen < 3; ++ idVen)
        if (total.at(region).at(idVen).at(mes) == max)
            vendedores.a.at(vendedores.id++) == idVen;
    
    return vendedores;
}       

void mostrarMejores (const mejores<3> &vendedores,int region)
{
    if (vendedores.id >1)
    {   
        cout << "Los mejores vendedores fueron ";
        for (int i{}; i<vendedores.id; ++i)
             cout << vendedores.a.at(i) << '\n';
    }

    else
    {
        cout << "El mejor vendedor fue " << vendedores.a.at(0);
    }
}

void mejoresVendedores (const Cubo &total, int mes, int region, int max)
{
   // mostrarMejores (acumMejorVendedor(total,mes,region,max),region);
}
