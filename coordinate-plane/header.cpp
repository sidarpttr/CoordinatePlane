#include "header.h"
#define PI 3.14159265

Coordinate::Coordinate(int b = 15)
{
    size = (b <= 0) ? 0 : (b % 2 == 0) ? b + 1
                                        : b;
    if (size == 0)
    {
        cerr << "negatif veya sifir olamaz!";
    }
    else
    {
        plane = new string *[size];
        for (int i = 0; i < size; i++)
            plane[i] = new string[size];
        create();
    }
}

Coordinate::Coordinate(Coordinate &k) : size(k.size)
{
    plane = new string *[size];
    for (int i = 0; i < size; i++)
        plane[i] = new string[size];
}

Coordinate::~Coordinate()
{
    for (int i = 0; i < size; i++)
        delete[] plane[i];
    delete[] plane;
}

void Coordinate::create()
{
    int axis = (size - 1) / 2;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            plane[i][j] = (j == axis && i != axis)   ? " | "
                           : (j != axis && i == axis) ? "---"
                           : (i == axis && j == axis) ? "-+-"
                                                          : "   ";
    }
}

void Coordinate::add(int x, int y)
{
    int axis = (size - 1) / 2;
    if (x > axis || y > axis || x < -axis || y < -axis)
        cerr << "(" << x << "," << y << ")"
             << " can't be positioned, it's out of range!" << endl;
    else if (x > 0 && x <= axis)
        plane[axis - y][axis + x] = " ● ";
    else
        plane[axis - y][axis + x] = " ● ";
}

void Coordinate::draw()
{
    cout<<endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << plane[i][j];
        cout << endl;
    }
}

Point::Point(Coordinate &k, string name, int x, int y) : _x(x), _y(y), name(name)
{
    k.add(_x, _y);
}

double Point::slope(Point& n)const{
    return (double)(n._y - _y) / (n._x - _x);
}

Line::Line(Point& n1, Point& n2, string name = ""){
    if(name == "")
        name = n1.name + n2.name;
    for(char& c : name)
        c = toupper(c);
    this->name = '|' + name + '|';
    
    slope = n1.slope(n2);
    distance = sqrt((n1._y - n2._y)*(n1._y - n2._y) + (n1._x - n2._x)*(n1._x - n2._x));
    angle = atan(slope) * 180 / PI;
}

void Line::info(std::initializer_list<Line> lines)const{
        std::cout << std::endl;
        for (int i = 0; i < 41; i++) std::cout << "_";
        std::cout << std::endl << "|line\t|distance\t" << "|slope\t" << "|angle\t|" << std::endl;
        std::cout << "|-------|---------------|-------|-------|";

        for (const auto& line : lines) {
            std::cout << std::endl << "|" << line.name;
            printf("\t|%.2f\t\t|%.2f\t|%.2f\t|", line.distance, line.slope, line.angle);
        }

        std::cout << std::endl;
        for (int i = 0; i < 41; i++) std::cout << "-";
        std::cout << std::endl;
}

double Line::angle_between_2lines(Line l2){
    double line1_slope = this->slope;
    double line2_slope = l2.slope;
    double angle = atan((line1_slope - line2_slope)/(1 + line1_slope * line2_slope));
    return angle * 180 / PI;
}