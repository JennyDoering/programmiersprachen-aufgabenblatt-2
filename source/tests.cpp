#include "vec2.hpp"

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>


TEST_CASE ( " vec2.hpp " , " [ vec2] " )
{
Vec2 a ; // requires that 0.0 f == a . x and 0.0 f == a . y
Vec2 b {5.1f , -9.3f }; /* requires that 5.1 f == Approx ( a . y ) and -9.3 f == Approx ( b . y ) */

REQUIRE(0.0f == a.x);
REQUIRE(0.0f == a.y);

REQUIRE(5.1f == Approx(b.x) );
REQUIRE(-9.3f == Approx(b.y) ); 

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

