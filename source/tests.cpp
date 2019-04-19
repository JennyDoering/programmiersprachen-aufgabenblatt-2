#include "vec2.hpp"

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

//Aufgabe 2.2
TEST_CASE ( " vec2.hpp " , " [vec2] " )
{
Vec2 a ; // requires that 0.0 f == a . x and 0.0 f == a . y
Vec2 b {5.1f , -9.3f }; /* requires that 5.1 f == Approx ( a . y ) and -9.3 f == Approx ( b . y ) */

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
  a + b;
  
  //REQUIRE(operator+((7.7f == Approx(ergebnis.x))));
  //REQUIRE(operator+((8.6f == Approx(ergebnis.y))));
  
  //REQUIRE(operator+((4.5f, -1.9f),(3.2f, 10.5f) == Approx(7.7f, 8.6f))));
  //REQUIRE(operator+({1.2f, 13.4f},{6.1f, 7.6f}) == Approx(7.3f, 21.0f));
  //REQUIRE(operator+({-8.8f, 2.0f},{3.0f, 10.0f}) == Approx(-5.8f, 12.0f));

  REQUIRE(operator+(7.7f == Approx((ergebnisx))));
  REQUIRE(operator+(8.6f == Approx((ergebnisy))));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

