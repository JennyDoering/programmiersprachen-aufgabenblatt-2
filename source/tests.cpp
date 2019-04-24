#include "vec2.hpp"
#include "mat2.hpp"

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
  Mat2 mat_a {2.0f, 1.5f, 3.3f, -4.2f};
  
  Mat2 mat_b {1.0f, 2.0f, 3.0f, 4.0f};
  mat_a *= mat_b;

  // e_00 = 2.0f;
  // e_01 = 1.5f;
  // e_10 = 3.3f;
  // e_11 = -4.2f;

  REQUIRE(2.0f == Approx(mat_a.e_00));
  REQUIRE(4.0f == Approx(mat_a.e_01));
  REQUIRE(9.9f == Approx(mat_a.e_10));
  REQUIRE(-16.8f == Approx(mat_a.e_11));

  // float s = 2;
  // m *= s;

  // REQUIRE(4.0f == Approx(m.e_00));
  // REQUIRE(3.0f == Approx(m.e_01));
  // REQUIRE(6.6f == Approx(m.e_10));
  // REQUIRE(-8.4f == Approx(m.e_11));

 
}

TEST_CASE ("Grauton RGB", "[color.hpp]"){
  Color a;
  
  REQUIRE(0.5f == a.r);
  REQUIRE(0.5f == a.g);
  REQUIRE(0.5f == a.b);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

