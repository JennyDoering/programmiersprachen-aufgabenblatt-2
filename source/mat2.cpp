#include "mat2.hpp"
#include "vec2.hpp"

// Memberfunktion (Aufgabe 2.5)
Mat2 & Mat2::operator *=( Mat2 const & m ) {

    float a = e_00;
    float b = e_01;
    float c = e_10;
    float d = e_11;

    e_00 = a * m.e_00 + b * m.e_10;
    e_01 = a * m.e_01 + b * m.e_11;
    e_10 = c * m.e_00 + d * m.e_10;
    e_11 = c * m.e_01 + d * m.e_11;

    return *this;
}

// freie Funktion (Aufgabe 2.5)
Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 ) {
    Mat2 g = m1;
    return g *= m2;
}

// Memberfunktion - Berechnung der Determinanten (Aufgabe 2.6)
float Mat2::det () const {

  float a = e_00;
  float b = e_01;
  float c = e_10;
  float d = e_11;

  return (a * c) - (b * d);
}

Vec2 operator*(Mat2 const & m, Vec2 const & v) {
 
  float a = m.e_00 * v.x + m.e_01 * v.y;
  float b = m.e_10 * v.x + m.e_11 * v.y;

  Vec2 erg = {a, b};
  return erg;
}

Vec2 operator*(Vec2 const & v, Mat2 const & m);
Mat2 inverse(Mat2 const & m);
Mat2 transpose(Mat2 const & m);
Mat2 make_rotation_mat2(float phi);