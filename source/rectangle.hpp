# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP
# include "vec2.hpp" 
# include "color.hpp"
# include "window.hpp"
# include <cmath>


class Rectangle {

public: 
    Rectangle();
    Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& col_);
    float circumference() const;
    void draw(Window const& win) const;

private:
    Vec2 min_;
    Vec2 max_;
    Color col_;
};


# endif