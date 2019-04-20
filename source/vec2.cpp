#include "vec2.hpp"

//Memberfunktionen (Aufgabe 2.3)
Vec2 & Vec2::operator +=( Vec2 const & v ) {
    x = x + v.x;
    y = y + v.y;
    return *this;
}

Vec2 & Vec2::operator -=( Vec2 const & v ){
    x = x - v.x;
    y = y - v.y;
    return *this;
}

Vec2 & Vec2::operator *=( float s ) {
    x = x * s;
    y = y * s;
    return *this;
}

Vec2 & Vec2::operator /=( float s ) {
    x = x / s;
    y = y / s;
    return *this;
}

// freie Funktionen (Aufgabe 2.4)
Vec2 operator+( Vec2 const& u , Vec2 const& v ) {

    Vec2 a = u;
    return a += v;
}

Vec2 operator-( Vec2 const& u , Vec2 const& v ) {
    
    Vec2 a = u;
    return a -= v;
}

Vec2 operator*( Vec2 const& v , float s ) {
   
    float b = s;
    Vec2 a = v * b;
    return a;
}

Vec2 operator/( Vec2 const& v , float s ) {
    float b = s;
    Vec2 a = v / b;
    return a;
}

Vec2 operator*( float s , Vec2 const& v ){
    
    return v * s;

}

