#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include <cmath>
#include "circle.cpp"
#include "rectangle.cpp"

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

//Aufgabe 2.2
TEST_CASE ( " vec2.hpp " , " [vec2] " )
{
Vec2 a ; // requires that 0.0 f == a . x and 0.0 f == a . y
Vec2 b {5.1f , -9.3f }; /* requires that 5.1 f == Approx ( b . x ) and -9.3 f == Approx ( b . y ) */

REQUIRE(0.0f == a.x);
REQUIRE(0.0f == a.y);

REQUIRE(5.1f == Approx(b.x) );
REQUIRE(-9.3f == Approx(b.y) ); 

}

//Aufgabe 2.3 += operator
TEST_CASE ( "operator +=" , "[vec2]" ) {
  Vec2 f {4.5f, -1.9f};
  Vec2 g {3.2f, 10.5f};
  f+=g;
  REQUIRE(7.7f == Approx(f.x));
  REQUIRE(8.6f == Approx(f.y));
}

//Aufgabe 2.3 -= operator
TEST_CASE ( "operator -=" , "[vec2]" ) {
  Vec2 f {4.5f, -1.9f};
  Vec2 g {3.2f, 10.5f};
  f-=g;
  REQUIRE(1.3f == Approx(f.x));
  REQUIRE(-12.4f == Approx(f.y));
}

//Aufgabe 2.3 *= operator
TEST_CASE ( "operator *=" , "[vec2]" ) {
  Vec2 f {4.5f, -1.9f};
  float s = 2;
  f*=s;
  REQUIRE(9.0f == Approx(f.x));
  REQUIRE(-3.8f == Approx(f.y));
}

//Aufgabe 2.3 /= operator
TEST_CASE ( "operator /=" , "[vec2]" ) {
  Vec2 f {4.5f, -1.9f};
  float s = 2;
  f/=s;
  REQUIRE(2.25f == Approx(f.x));
  REQUIRE(-0.95f == Approx(f.y));
}

//Aufgabe 2.4 + operator
TEST_CASE ( "operator +" , "[vec2]" ) {
  Vec2 a {4.5f, -1.9f};
  Vec2 b {3.2f, 10.5f};
  Vec2 c = a + b;
  
  REQUIRE((7.7f == Approx(c.x)));
  REQUIRE((8.6f == Approx(c.y)));

  Vec2 d {1.2f, 13.4f};
  Vec2 e {6.1f, 7.6f};
  Vec2 f = d + e;
  
  REQUIRE((7.3f == Approx(f.x)));
  REQUIRE((21.0f == Approx(f.y)));

  Vec2 g {-8.8f, 2.0f};
  Vec2 h {3.0f, 10.0f};
  Vec2 i = g + h;
  
  REQUIRE((-5.8f == Approx(i.x)));
  REQUIRE((12.0f == Approx(i.y)));
}

//Aufgabe 2.4 - operator
TEST_CASE ( "operator -" , "[vec2]" ) {
  Vec2 a {4.5f, -1.9f};
  Vec2 b {3.2f, 10.5f};
  Vec2 c = a - b;
  
  REQUIRE((1.3f == Approx(c.x)));
  REQUIRE((-12.4f == Approx(c.y)));

  Vec2 d {1.2f, 13.4f};
  Vec2 e {6.1f, 7.6f};
  Vec2 f = d - e;
  
  REQUIRE((-4.9f == Approx(f.x)));
  REQUIRE((5.8f == Approx(f.y)));

  Vec2 g {-8.8f, 2.0f};
  Vec2 h {3.0f, 10.0f};
  Vec2 i = g - h;
  
  REQUIRE((-11.8f == Approx(i.x)));
  REQUIRE((-8.0f == Approx(i.y)));
}

//Aufgabe 2.4 * operator
TEST_CASE ( "operator *" , "[vec2]" ) {
  Vec2 c {4.5f, -1.9f};
  c *= 2;
  
  REQUIRE((9.0f == Approx(c.x)));
  REQUIRE((-3.8f == Approx(c.y)));

  Vec2 d {1.2f, 13.4f};
  d *= -5;
  
  REQUIRE((-6.0f == Approx(d.x)));
  REQUIRE((-67.0f == Approx(d.y)));

  Vec2 g {-8.8f, 2.0f};
  g *= 1.5;
  
  REQUIRE((-13.2f == Approx(g.x)));
  REQUIRE((3.0f == Approx(g.y)));
}

//Aufgabe 2.4 / operator
TEST_CASE ( "operator /" , "[vec2]" ) {
  Vec2 c {4.5f, -1.9f};
  c /= 2;
  
  REQUIRE((2.25f == Approx(c.x)));
  REQUIRE((-0.95f == Approx(c.y)));

  Vec2 d {1.2f, 13.4f};
  d /= -5;
  
  REQUIRE((-0.24f == Approx(d.x)));
  REQUIRE((-2.68f == Approx(d.y)));

  Vec2 g {-9.0f, 3.0f};
  g /= 1.5;
  
  REQUIRE((-6.0f == Approx(g.x)));
  REQUIRE((2.0f == Approx(g.y)));
}

//Aufgabe 2.4 * (2) operator
TEST_CASE ( "operator * (2)" , "[vec2]" ) {
  Vec2 c {4.5f, -1.9f};
  c *= 2;

  REQUIRE((9.0f == Approx(c.x)));
  REQUIRE((-3.8f == Approx(c.y)));

  Vec2 d {1.2f, 13.4f};
  d *= -5;
  
  REQUIRE((-6.0f == Approx(d.x)));
  REQUIRE((-67.0f == Approx(d.y)));

  Vec2 g {-8.8f, 2.0f};
  g *= 1.5;
  
  REQUIRE((-13.2f == Approx(g.x)));
  REQUIRE((3.0f == Approx(g.y)));
}

// Aufgabe 2.5 *= operator
TEST_CASE ("operator *= Matrizen", "[mat2]"){
  Mat2 mat_a {2.0f, 1.0f, 3.0f, -4.0f};
  Mat2 mat_b {1.0f, 2.0f, 6.0f, 0.0f};
  
  mat_a *= mat_b;

  REQUIRE(8.0f == Approx(mat_a.e_00));
  REQUIRE(4.0f == Approx(mat_a.e_01));
  REQUIRE(-21.0f == Approx(mat_a.e_10));
  REQUIRE(6.0f == Approx(mat_a.e_11));

  Mat2 mat_c {-3.0f, 1.5f, 8.0f, 0.0f};
  Mat2 mat_d {1.0f, 3.0f, -7.0f, 9.0f};
  
  mat_c *= mat_d;

  REQUIRE(-13.5f == Approx(mat_c.e_00));
  REQUIRE(4.5f == Approx(mat_c.e_01));
  REQUIRE(8.0f == Approx(mat_c.e_10));
  REQUIRE(24.0f == Approx(mat_c.e_11));
 
}

// Aufgabe 2.5 * operator
TEST_CASE ("operator * Matrizen", "[mat2]"){
  Mat2 mat_a {2.0f, 1.0f, 3.0f, -4.0f};
  Mat2 mat_b {1.0f, 2.0f, 6.0f, 0.0f};
  
  Mat2 mat_c = mat_a *= mat_b;

  REQUIRE(8.0f == Approx(mat_c.e_00));
  REQUIRE(4.0f == Approx(mat_c.e_01));
  REQUIRE(-21.0f == Approx(mat_c.e_10));
  REQUIRE(6.0f == Approx(mat_c.e_11));

  Mat2 mat_d {-3.0f, 1.5f, 8.0f, 0.0f};
  Mat2 mat_e {1.0f, 3.0f, -7.0f, 9.0f};
  
  Mat2 mat_f = mat_d *= mat_e;

  REQUIRE(-13.5f == Approx(mat_f.e_00));
  REQUIRE(4.5f == Approx(mat_f.e_01));
  REQUIRE(8.0f == Approx(mat_f.e_10));
  REQUIRE(24.0f == Approx(mat_f.e_11));
 
}

// Aufgabe 2.6 det ()
TEST_CASE ("Determinante", "[mat2]") {
  Mat2 mat_a {2.0f, 1.0f, 3.0f, -4.0f};
  float b = mat_a.det();
  REQUIRE(b == Approx (-11.0f));

  Mat2 mat_c {1.5f, -5.5f, 2.0f, 9.0f};
  float d = mat_c.det();
  REQUIRE(d == Approx (24.5f));
}

// Aufgabe 2.6 * operator Matrix * Vektor
TEST_CASE ("Matrix * Vektor", "[mat2]") {
  Mat2 mat1 {1.0f, 3.0f, 0.0f, 4.0f};
  Vec2 vec1 {2.0f, 5.0f};
  
  Vec2 erg1 = mat1 * vec1;

  REQUIRE(17.0f == Approx(erg1.x));
  REQUIRE(20.0f == Approx(erg1.y));

  Mat2 mat2 {5.0f, -2.0f, 1.0f, 8.0f};
  Vec2 vec2 {1.0f, 3.0f};
  
  Vec2 erg2 = mat2 * vec2;

  REQUIRE(-1.0f == Approx(erg2.x));
  REQUIRE(25.0f == Approx(erg2.y));
}

//Aufgabe 2.6 * operator Vektor * Matrix
TEST_CASE ("Vektor * Matrix", "[mat2]") {
  Vec2 vec3 {2.0f, 5.0f};
  Mat2 mat3 {1.0f, 3.0f, 0.0f, 4.0f};
 
  Vec2 erg3 = vec3 * mat3;

  REQUIRE(2.0f == Approx(erg3.x));
  REQUIRE(26.0f == Approx(erg3.y));

  Mat2 mat4 {5.0f, -2.0f, 1.0f, 8.0f};
  Vec2 vec4 {1.0f, 3.0f};
  
  Vec2 erg4 = vec4 * mat4;

  REQUIRE(8.0f == Approx(erg4.x));
  REQUIRE(22.0f == Approx(erg4.y));
}

// Aufgabe 2.6 transpose ()
TEST_CASE ("transpose", "[mat2]") {
  Mat2 mat_g = {1.0f, 2.0f, 3.0f, 4.0f};

  REQUIRE(transpose(mat_g).e_00 == 1.0f);
  REQUIRE(transpose(mat_g).e_01 == 3.0f);
  REQUIRE(transpose(mat_g).e_10 == 2.0f);
  REQUIRE(transpose(mat_g).e_11 == 4.0f);

  Mat2 mat_s = {-9.0f, -2.3f, 8.1f, 5.0f};

  REQUIRE(transpose(mat_s).e_00 == -9.0f);
  REQUIRE(transpose(mat_s).e_01 == 8.1f);
  REQUIRE(transpose(mat_s).e_10 == -2.3f);
  REQUIRE(transpose(mat_s).e_11 == 5.0f);
}

// Aufgabe 2.6 inverse ()
TEST_CASE ("inverse", "[mat2]") {
  Mat2 mat_k = {1.0f, 2.0f, 3.0f, 4.0f};

  REQUIRE(inverse(mat_k).e_00 == Approx(-2.0f));
  REQUIRE(inverse(mat_k).e_01 == Approx(1.0f));
  REQUIRE(inverse(mat_k).e_10 == Approx(1.5f));
  REQUIRE(inverse(mat_k).e_11 == Approx(-0.5f));

  Mat2 mat_w = {2.5f, -7.0f, 10.0f, -21.0f};

  REQUIRE(inverse(mat_w).e_00 == Approx(-1.2f));
  REQUIRE(inverse(mat_w).e_01 == Approx(0.4f));
  REQUIRE(inverse(mat_w).e_10 == Approx(-0.5714).epsilon(0.001));
  REQUIRE(inverse(mat_w).e_11 == Approx(0.143f).epsilon(0.001));
}

// Aufgabe 2.6 make_rotation_mat2 ()
TEST_CASE ("make_rotation_mat2", "[mat2]") {
  const float pi = 3.1415926f;

  Vec2 o = {1.0f, 2.0f};
  Mat2 mat_p = make_rotation_mat2(pi);
  Vec2 o_rot = mat_p * o;
  
  REQUIRE(o_rot.x == Approx(-1.0f).epsilon(0.001));
  REQUIRE(o_rot.y == Approx(-2.0f).epsilon(0.001));

  Vec2 t = {8.0f, 4.0f};
  Mat2 mat_q = make_rotation_mat2(pi/6);
  Vec2 t_rot = mat_q * t;
  
  REQUIRE(t_rot.x == Approx(4.928f).epsilon(0.001));
  REQUIRE(t_rot.y == Approx(7.464f).epsilon(0.001));
}

// Aufgabe 2.7
TEST_CASE ("Grauton RGB", "[color.hpp]"){
  Color a;
  
  REQUIRE(0.5f == a.r);
  REQUIRE(0.5f == a.g);
  REQUIRE(0.5f == a.b);
}

//Aufgabe 2.9
TEST_CASE ("circumference", "[circle, rectangle]"){

  Circle c1 = Circle(Vec2 {}, 1.0f, Color {});
  REQUIRE(Approx(c1.circumference()) == 2 * M_PI);

  Circle c2 = Circle (Vec2 {2.0f, 3.0f}, 2.5f, Color {});
  REQUIRE(Approx(c2.circumference()) == 15.70795);

  Rectangle r1 = Rectangle(Vec2 {}, Vec2 {}, Color {});
  REQUIRE(Approx(r1.circumference()) == 0.0f);

  Rectangle r2 = Rectangle(Vec2 {2.0f, 2.0f}, Vec2 {4.0f, 4.0f}, Color {});
  REQUIRE(Approx(r2.circumference()) == 8.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

