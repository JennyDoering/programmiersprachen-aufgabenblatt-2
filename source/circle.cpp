# include "circle.hpp"

Circle::Circle() {}
Circle::Circle(Vec2 const& point_, float const& radius_, Color const& col_, Color const& highlight_col_) : radius_ (radius_), point_ (point_), col_ (col_), highlight_col_ (highlight_col_) {}

float Circle::circumference() const {
    const float pi = 3.1415926f;
    float u = 2 * pi * radius_;
    return u;
}

void Circle::draw(Window const& win, float line_thickness, bool highlight) const {
    Vec2 p1 {0, radius_};
    float winkel_bog = (3.6 * M_PI) / 180;
    for (int i = 1; i <= 100; ++i) {
        Vec2 p2 = p1 * make_rotation_mat2(winkel_bog);
        if (highlight) {
            win.draw_line(p1.x + point_.x, p1.y + point_.y, p2.x + point_.x, p2.y + point_.y, highlight_col_.r, highlight_col_.g, highlight_col_.b, line_thickness);
        }
        else {
        win.draw_line(p1.x + point_.x, p1.y + point_.y, p2.x + point_.x, p2.y + point_.y, col_.r, col_.g, col_.b, line_thickness);
        }
        p1 = p2;
    }
    
}

bool Circle::is_inside_c(const Vec2& point_) const {
    Vec2 m = {0, radius_};
}

