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
   Circle(Vec2 const& point_, float const& radius_, Color const& col_, Color const& highlight_col_ = Color {});
   float circumference() const;
   void draw(Window const& win, float line_thickness = 1.0f, bool highlight = false) const;
   bool is_inside_c(const Vec2& point_) const;

private:

    float radius_;
    Vec2 point_;
    Color col_;
    Color highlight_col_;
};


# endif