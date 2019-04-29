# ifndef CIRCLE_HPP
# define CIRCLE_HPP
# include "vec2.hpp"
# include "color.hpp"
# include "window.hpp"
# include <cmath>


class Circle {
public:
   Circle();
   Circle(Vec2 const& point_, float const& radius_, Color const& col_);

private:

    float radius_;
    Vec2 point_;
    Color col_;
};


# endif