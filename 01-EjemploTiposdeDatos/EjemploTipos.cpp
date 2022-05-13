#include <cassert>  
#include <string>
#include <iomanip>

using namespace std::literals;

int main ()
{
    // PRUEBA DE DATO TIPO: BOOL (values true or false)
	
    assert (true);
    assert (false == false);
    assert (true != false);
    assert (not false);
    assert (not false == true);
    assert (false or true);
    assert (true and true);
    assert (false or true and false == false);
    assert (true or true and false);
    

    // PRUEBA DE DATO TIPO: CHAR (utiliza la tabla ASCII. (ej: 'A' == 65)). Se utilizan las comiilas simples 'x'.
    
    assert ('a' != 'A');
    assert ('a' > 'A');
    assert ('A' == 65);
    assert ('a' - 32 == 'A');
    assert ('5' != '4' + '1');
    assert (1 == 'B' - 'A');
        

    // PRUEBA DE DATO TIPO: UNSIGNED (conjunto de numeros naturales N). Se utiliza la 'u', ya que sin esta, serian "int's".

    assert (2u + 4u < 10u);
    assert (3u - 2u != 6u);
    assert (2u * 2u == 2u + 2u);
    assert (25u / 5u > 4u);
    assert (1u ==  11u % 2u);
    

    // PRUEBA DE DATO TIPO: INT (contjunto de numeros enteros Z).

    assert (6+6 <= 12);
    assert (-19 == -10-9);
    assert (4 > -22);
    assert (22 != 10*2);
    assert (20 == 100/5);
    assert (3 == 28%5);


    // PRUEBA DE DATO TIPO: DOUBLE (conjunto de numeros reales R). 
    // assert (0.0 == 0. and .0 == 0.0 and 0.0 == 0.0f and 0.0 == 0e1); ((f se refiere a "float")).

    assert (2.0 != 1.0);
    assert (0.0 - 1.0 == -1.0 );
    assert (7.4 != 2.3 + 2.6);
    assert (4.5 < 4.0 + 1.1);
    assert (3.0 * 12.1 != 15.2);
    assert (19.6 / 0.3 < 101.7);
    assert (1.0 != 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
    

    // PRUEBA DE DATO TIPO: STRING (tipo de dato compuesto, cadena de caracteres (char's)). Se utilizan las comillas "x".

    assert ("bryanAED"s == "bryan"s + "AED"s);
    assert ("bryanAED"s.length() == 8);
    assert ("AA" < "BB");
    assert ("AA" != "aa");

}
