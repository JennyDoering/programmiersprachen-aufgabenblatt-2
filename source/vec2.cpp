#include "vec2.hpp"
   
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

