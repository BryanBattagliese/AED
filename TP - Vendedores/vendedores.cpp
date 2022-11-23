#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;
using Cubo = array<array<array<unsigned,12>,3>,4>;

template <unsigned N, typename T = int>
struct mejores
{
    array<T,N>  a  {};
    unsigned    id {};
};

/* ------------------------------------------------------------------------------------------------------------------------- */

void cargarDatos            (Cubo &);
void mostrarVentas          (Cubo &);
void mostrarDatos           (Cubo &);
void crearTXT               (Cubo &);

int mayorVenta                  (Cubo &,int,int);
int mayorVentaII                (Cubo &,int,int);
int promedioVenta               (Cubo &,int,int);
mejores<3> acumMejorVendedor    (const Cubo &,int,int);

void mostrarMejores             (const mejores<3>,int,int);
void mejoresVendedores          (const Cubo &,int,int);
void guardarVentas              (const Cubo &, int, int);

string nombres                  (int, int);
string N_regiones               (int);

/* ------------------------------------------------------------------------------------------------------------------------- */

int main ()
{
  Cubo total{};
  cargarDatos(total);
  mostrarVentas(total);
  mostrarDatos(total);
  crearTXT(total);
  guardarVentas(total, 0, 0);
}

/* ------------------------------------------------------------------------------------------------------------------------- */

void cargarDatos (Cubo &total)
{ 
    ifstream file2;
    fstream filedim;

	file2.open("file.bin", ios::in | ios::binary);
	file2.read(reinterpret_cast<char *>(&total), sizeof(total));
	filedim.open("vendedores.txt");

    int region{}, vendedor{}, mes{}, importe{};
	    
    for (; filedim >> region >> vendedor >> mes >> importe;)
	    {
		    total.at(region - 1).at(vendedor - 1).at(mes - 1) += importe;
	    }
	
    file2.close();
}

void mostrarVentas (Cubo &total)
{
    ofstream file;
	file.open("file.bin", ios::out | ios::binary);
	
    for (int i{}; i < 4; ++i)
	{   cout << '\n' << "Region: " << N_regiones(i) << '\n';
		
        for (int j{}; j < 3; ++j)
		{   cout << '\n' << "Vendedor: " << nombres(j,i) << '\n';
			
            for (int k{}; k < 12; ++k)
			{   cout << "En el mes: " << k + 1 << " vendio: "
                     << "$" << total[i][j][k] << '\n';
			}
		}
	}
	
    file.write(reinterpret_cast<char *>(&total), sizeof(total));
	file.close();
}

void mostrarDatos (Cubo &total)
{
    for(int m{}; m<12; ++m)
    {  
        for(int r{}; r<4; ++r)
        {
            cout << '\n' << "El importe maximo para el mes "    << m+1 << " de la region " << N_regiones(r) 
                 <<" fue de: $ " << mayorVenta (total,m,r);
            
            cout << '\n' << "El importe promedio para el mes "  << m+1 << " de la region " << N_regiones(r) 
                 <<" fue de: $ " << promedioVenta (total,m,r) << '\n';

            mejoresVendedores(total,m,r);
        }
    }

}

void crearTXT (Cubo &total)
{
    ofstream file3;
	file3.open("ventas.txt", ios::out);
	
    for (int i{}; i < 4; ++i)
	{
		file3 << '\n'
			  << " Region: " << N_regiones(i) << '\n';
		
        for (int j{}; j < 3; ++j)
		{
			file3 << '\n'
				  << '\n' << " Vendedor: " << nombres(j,i) << '\n';
			
            for (int k{}; k < 12; ++k)
			{
				file3 << " Durante el mes: " << k + 1 << " vendio: "
					  << "$" << total[i][j][k] << '\n';
			}
		}
	}
}

/* ------------------------------------------------------------------------------------------------------------------------- */

int mayorVenta (Cubo &total, int mes, int region)
{   
    int sum{};
    for (auto ext : total.at(region))
        if(ext.at(mes) > sum)
        {
            sum = ext.at(mes);
        }
    
    return sum;
}

int mayorVentaII (const Cubo &cubo, int mes, int region)      
{   
    int sum{};
    for (auto ext : cubo.at(region))
        if(ext.at(mes) > sum)
        {
            sum = ext.at(mes);
        }
    
    return sum;
}

int promedioVenta (Cubo &total, int mes, int region)
{
    int sum{};
    for (auto ext : total.at(region))
        sum += ext.at(mes);
    
    return sum / (total.at(region).size());
}

mejores<3> acumMejorVendedor (const Cubo &cubo, int mes, int region, int max)
{   
    mejores<3> vendedores {};
    
    for (int idVen{}; idVen < 3; ++idVen)
        if (cubo.at(region).at(idVen).at(mes) == max)
            vendedores.a.at(vendedores.id++)  = idVen;
    
    return vendedores;
}       

void mostrarMejores (const mejores<3> &vendedores,int region) 
{   
    if (vendedores.id > 1)
    {
        cout << "Los mejores vendedores son: ";
        for(int x{}; x < vendedores.id; ++x)
            cout << nombres(vendedores.a.at(x),region);
    }
    
    else
     cout << "El mejor vendedor es: " << nombres(vendedores.a.at(0),region) << '\n';
}

void mejoresVendedores (const Cubo &total, int mes, int region)
{
     mostrarMejores(acumMejorVendedor(total, mes, region, mayorVentaII(total, mes, region)), region);
}

void guardarVentas (const Cubo &total, int vendedor, int region) 
{ 
  array<int, 12> vector0;

  for(int i{}; i < 12; i++) 
    vector0.at(i) = total.at(region).at(vendedor).at(i);

  cout << '\n' << "Guardar ventas 0: " << '\n';
  
  for (int i{}; i < 12; i++)
    cout << vector0.at(i) << '\t';
}

string nombres(int vendedor, int region)
{
	static const array<array<string, 3>, 4> vendedores{{{{"Agustin", "Damian", "Bryan"}},
							    {{"Pedro", "Lucia", "Macarena"}},
							    {{"Sofia", "Jose Maria", "Bautista"}},
							    {{"Amelia", "Osvaldo", "Lidia"}}}};
	return vendedores.at(region).at(vendedor);
}

string N_regiones (int region)
{
	array<string, 4> regiones{"Este", "Oeste", "Norte", "Sur"};
	return regiones.at(region);
}
