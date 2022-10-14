#include <cassert>
#include <iostream>

// Distancia: R x R -> R/Distancia (a,b) = Abs(a-b)     (Especificacion Matematica).

int    Abs       (int );
bool   areNear   (double,double,double = 0.001);
int    Distancia (int,int);

int main ()
{
    assert (Distancia(5,2) == 3);
    assert (Distancia(9,9) == 0);
    assert (Distancia(6,7) == 1);

    assert (areNear(Distancia(2,3) , 1));
    assert (areNear(Distancia(2,3), Distancia(5,1), 3 ) == true);
    assert (areNear(Distancia(1,3), Distancia(2,2), 1 ) == false);

    std:: cout << "SI \n";

}

bool areNear (double x, double y, double t)
{
    return (x-t)<= y and y<=(x+t);
}
int Abs (int a)
{
    return a<0 ? -a :a ;
}
int Distancia (int x, int y)
{
    return Abs(x-y);
}

/* (Ejecución)

areNear             --> tercera f que llama
Abs                 --> segunda f que llama
Distancia           --> primera f que llama
int main ()
distancia.exe
SO
HW

---piso---
*/

