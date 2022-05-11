#include <cassert>
#include <string>
#include <iomanip>

using namespace std::literals;

int main ()
{
	// PRUEBA DE DATO TIPO: BOOL
	
    assert (true);
    assert (false==false);
    assert (true!=false);
    assert (not false);
    assert (not false==true);
    assert (false or true);
    assert (true and true);
    assert (false or true and false==false);
    assert (true or true and false);
    

    // PRUEBA DE DATO TIPO: CHAR
    
    assert (82 == 'R');
    assert (114 == 'r');
    assert ('9' == 57);
    assert ('k' == 107);
    

    // PRUEBA DE DATO TIPO: UNSIGNED

    assert (2+4 < 10);
    assert (2+2 == 2*2);
    assert (1 == 3-2);
    assert (5*3 == 15);
    

    // PRUEBA DE DATO TIPO: INT

    assert (-19 == -10-9);
    assert (48 == 50-2);
    assert (22 == 10*2 + 2);
    assert (-2  == 4/-2 );


    // PRUEBA DE DATO TIPO: DOUBLE
    
    assert (2.0 == 1.0+1.0);
    assert (0.1 == 1.0/10.0);
    assert (4 == 4.0);
    assert (2.0 == 1+1.0);
    assert (3 == 2+1.0);
    

    // PRUEBA DE DATO TIPO: STRING

    assert ("bryanAED"s == "bryan"s + "AED"s);
    assert ("bryanAED"s.length() == 8);
    assert ("algoritmos"s == "algo"s + "ritmos"s);
    assert ("algoritmos"s.length() > 0);
    
    
}
