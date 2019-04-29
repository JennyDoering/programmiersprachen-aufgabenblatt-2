# ifndef CIRCLE_HPP
# define CIRCLE_HPP
# include "vec2.hpp"
# include "color.hpp"
# include "window.hpp"
# include <cmath>
# include "mat2.hpp"


class Circle {
public:
   Circle();
   Circle(Vec2 const& point_, float const& radius_, Color const& col_);
   float circumference() const;
   void draw(Window const& win) const;

private:

    float radius_;
    Vec2 point_;
    Color col_;
};


# endif