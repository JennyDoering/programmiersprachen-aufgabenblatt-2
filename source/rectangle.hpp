# ifndef RECTANGLE_HPP
# define RECTANGLE_HPP
# include "vec2.hpp" 
# include "color.hpp"
# include "window.hpp"
# include <cmath>


class Rectangle {

public: 
    Rectangle();
    Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& col_, Color const& highlight_col_ = Color {});
    float circumference() const;
    void draw(Window const& win, float line_thickness = 1.0f, bool highlight = false) const;
    bool is_inside(const Vec2& point_) const;

private:
    Vec2 min_;
    Vec2 max_;
    Color col_;
    Color highlight_col_;
    Vec2 point_;
};


# endif