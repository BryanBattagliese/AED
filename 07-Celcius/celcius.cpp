#include <cassert>

// especificacion matematica: f: R->R / f(x) = 5/9 * (x - 32)
double celcius  (double);                        

// especificacion matematica: f: RxRxR -> B / f(X,y,z) {z>=0} = {{ V  si  b-|t| <= a <= b+|t|                                                             
bool   areNear  (double,double,double = 0.001);//               {{ F  e.o.c.}}
 
int main ()
{   
    assert (areNear(1,1,0.1));
    assert (areNear(44.0,43.0,1.0));
    assert (not areNear(12.0,11.0,0.001));
    assert (not areNear(11.0,12.0,0.001));
    assert (areNear(6.999, 7.0));
    
    assert (celcius(50) == 10);
    assert (celcius(32) == 0);
    assert (celcius(68) >= 18);
    assert (celcius(99) != 35);
}


double celcius(double t)
{
    return ((t-32.0) * (5.0/9.0));
}


bool areNear (double a, double b, double t)
{
    return (a-t)<= b and b<=(a+t);
}