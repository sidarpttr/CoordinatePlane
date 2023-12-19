#include "header.h"

int main()
{

    Coordinate k(21);
    Point a(k,"a", 0, 0);
    Point b(k,"b",7,4);
    Point c(k,"c",3,0);
    k.draw();
    Line d(a,b);
    Line l(a,c);
    Line m(b,c);
    d.info({l,d,m});
    cout<<"angle between |AC| and |BC|  =>   "<<l.angle_between_2lines(m)<<endl;

    return 0;
}