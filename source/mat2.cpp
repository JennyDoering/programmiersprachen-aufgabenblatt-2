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

  return (a * d) - (b * c);
}

Vec2 operator*(Mat2 const & m, Vec2 const & v) {
 
  float a = m.e_00 * v.x + m.e_01 * v.y;
  float b = m.e_10 * v.x + m.e_11 * v.y;

  Vec2 erg = {a, b};
  return erg;
}

Vec2 operator*(Vec2 const & v, Mat2 const & m) {
  
  float a = v.x * m.e_00 + v.y * m.e_10;
  float b = v.x * m.e_01 + v.y * m.e_11;

  Vec2 erg = {a, b};
  return erg;
}

Mat2 inverse(Mat2 const & m) {
// Adjunkte Berechnung

  Mat2 mat_invers;
  float det = (m.e_00 * m.e_11) - (m.e_01 * m.e_10);
  float q = 1/ det;

  mat_invers.e_00 = q * m.e_11;
  mat_invers.e_01 = q * (-m.e_01);
  mat_invers.e_10 = q * (-m.e_10);
  mat_invers.e_11 = q * m.e_00;

  return mat_invers;

}

Mat2 transpose(Mat2 const & m) {

  Mat2 n = m;

  n.e_00 = m.e_00;
  n.e_01 = m.e_10;
  n.e_10 = m.e_01;
  n.e_11 = m.e_11;

  return n;
}

// Mat2 make_rotation_mat2(float phi) {

// }