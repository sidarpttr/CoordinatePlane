#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <initializer_list>
#include <math.h>
using namespace std;

class Coordinate
{
private:
public:
    string **plane;
    int size;
    Coordinate(int);
    Coordinate(Coordinate &);
    ~Coordinate();
    void create();
    void add(int, int);
    void draw();
};

class Point
{
public:
    int _x, _y;
    string name;
    Point(Coordinate &, string, int, int);
    double slope(Point &) const;
};

class Line
{
public:
    double distance;
    double slope;
    double angle;
    string name;
    Line(string, Point &, Point &);
    void info(std::initializer_list<Line>)const;
};

#include "header.cpp"
#endif