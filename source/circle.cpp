# include "circle.hpp"


Circle::Circle() {}
Circle::Circle(Vec2 const& point_, float const& radius_, Color const& col_) : radius_ (radius_), point_ (point_), col_ (col_) {}

float Circle::circumference() const {
    const float pi = 3.1415926f;
    float u = 2 * pi * radius_;
    return u;
}