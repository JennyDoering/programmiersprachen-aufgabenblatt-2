# include "rectangle.hpp"

Rectangle::Rectangle() {}
Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& col_) : min_ (min_), max_(max_), col_(col_) {}

float Rectangle::circumference() const{

    float a = (max_.x - min_.x);
    float b = (max_.y - min_.y);
    return (2 * a) + (2 * b);
}