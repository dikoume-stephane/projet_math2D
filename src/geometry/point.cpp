#include <iostream>
#include <cmath>
#include "point.h"
#include "utils.h"
#include "vector.h"
/*nous retrouverons ici l'inplementation des fonction de manipulation
des point basées sur les formules et aquis mathematiques. et en toute 
fin l'implementation de la fonction de convertion des nouvaux types en 
types affichables */
Point2f MakeP2f(float x, float y)
{
    Point2f p={x,y};
    return p;
}
Point2f Translate(const Point2f& p, float dx, float dy)
{
    Point2f pt={p.x+dx , p.y+dy};
    return pt;
}
Point2f Translate(const Point2f& p, const Vector2f& v)
{
    Point2f pt={p.x+v.x , p.y+v.y};
    return pt;
}
Point2f Scale(const Point2f& p, float sx, float sy)
{
    Point2f pt={p.x*sx , p.y*sy};
    return pt;
}
Point2f Scale(const Point2f& p, const Vector2f& s)
{
    Point2f pt={p.x*s.x , p.y*s.y};
    return pt;
}
Point2f Rotate(const Point2f& p, float angleDegree)
{
    Point2f pt;
    float angleradiant = (angleDegree*M_PI)/180;
    pt.x = p.x*cos(angleradiant) - p.y*sin(angleradiant);
    pt.y = p.x*sin(angleradiant) + p.y*cos(angleradiant);
    return pt;
}
bool Egal(const Point2f& a, const Point2f& b, float tolerance)
{
    float dx= a.x - b.x;
    float dy= a.y - b.y;
    float dis= dx*dx + dy*dx;
    if(dis< (tolerance*tolerance)) return true ;
    return false ;
}
bool Different(const Point2f& a, const Point2f& b, float tolerance)
{
    float dx= a.x - b.x;
    float dy= a.y - b.y;
    float dis= dx*dx + dy*dx;
    if(dis> (tolerance*tolerance)) return true ;
    return false ;
}
Point2f MakeNullPoint()
{
    Point2f p={0,0};
    return p;
}
std::string ToString(const Point2f& p)
{
    std::ostringstream aff;
    aff <<"("<< p.x <<","<< p.y<<")";
    return aff.str();
}