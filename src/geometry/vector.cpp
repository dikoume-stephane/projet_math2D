#include <iostream>
#include <cmath>
#include "point.h"
#include "utils.h"
#include "vector.h"
/*nous retrouverons ici l'inplementation des fonction de manipulation
des point basées sur les formules et aquis mathematiques. et en toute 
fin l'implementation de la fonction de convertion des nouvaux types en 
types affichables */
Vector2f MakeV2f(float x, float y)
{
    Vector2f v={x,y};
    return v;
}
Vector2f MakeV2f(const Point2f& a, const Point2f& b)
{
     Vector2f v={b.x - a.x , b.y - a.y};
     return v;
}
Vector2f Add(const Vector2f& a, const Vector2f& b)
{
    Vector2f v={b.x + a.x , b.y + a.y};
    return v;
}
Vector2f Sub(const Vector2f& a, const Vector2f& b)
{
    Vector2f v={a.x - b.x , a.y - b.y};
    return v;
}
Vector2f Scale(const Vector2f& v, float scalar)
{
    Vector2f vs={v.x*scalar , v.y* scalar};
    return vs;
}
float Dot(const Vector2f& a, const Vector2f& b)
{
    float Dotp = a.x*b.x + a.y*b.y;
    return Dotp;
}
float Length(const Vector2f& v)
{
    float norme = sqrt( v.x*v.x + v.y*v.y);
    return norme;
}
Vector2f Normalize(const Vector2f& v)
{
    float norme = Length(v);
    if(norme==0)
    {
      Vector2f v0 ={0,0};
      return v0;  
    }
    Vector2f vn ={v.x/norme , v.y/norme};
    return vn; 
}
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t)
{
    if(t<0) t=0;
    if(t>1) t=1;
    Vector2f v = Add(a,b);
    Vector2f vlr= Add(a,Scale(v,t));
    return vlr; 
}
float Determinant(const Vector2f& a, const Vector2f& b)
{
    float det=a.x*b.y - a.y*b.x;
    return det; 
}
bool Egal(const Vector2f& a, const Vector2f& b, float tolerance)
{
float dx= a.x - b.x;
    float dy= a.y - b.y;
    float dis= dx*dx + dy*dx;
    if(dis< (tolerance*tolerance)) return true ;
    return false ;
}
bool Different(const Vector2f& a, const Vector2f& b, float tolerance)
{
    float dx= a.x - b.x;
    float dy= a.y - b.y;
    float dis= dx*dx + dy*dx;
    if(dis> (tolerance*tolerance)) return true ;
    return false ;
}
Vector2f MakeNullVector()
{
    Vector2f v={0,0};
    return v;
}
std::string ToString(const Vector2f& v)
{
    std::ostringstream aff;
    aff <<"("<< v.x <<","<< v.y<<")";
    return aff.str();
}
