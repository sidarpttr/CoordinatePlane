#include "header.h"

int main()
{

    Coordinate k(21);
    Point a(k,"a", 0, 0);
    Point b(k,"b",7,4);
    Point c(k,"c",3,0);
    k.draw();
    Line d("A",a,b);
    Line l("B",a,c);
    Line m("C",b,c);
    d.info({l,d,m});

    return 0;
}