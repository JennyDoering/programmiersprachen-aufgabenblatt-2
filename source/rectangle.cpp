# include "rectangle.hpp"

Rectangle::Rectangle() {}
Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, Color const& col_, Color const& highlight_col_) : min_ (min_), max_(max_), col_(col_), highlight_col_ (highlight_col_) {}

float Rectangle::circumference() const{

    float a = (max_.x - min_.x);
    float b = (max_.y - min_.y);
    return (2 * a) + (2 * b);
}

void Rectangle::draw(Window const& win, float line_thickness, bool highlight) const {

    if (highlight) {
        win.draw_line(min_.x, min_.y, max_.x, min_.y, highlight_col_.r, highlight_col_.g, highlight_col_.b, line_thickness);
        win.draw_line(max_.x, min_.y, max_.x, max_.y, highlight_col_.r, highlight_col_.g, highlight_col_.b, line_thickness);
        win.draw_line(max_.x, max_.y, min_.x, max_.y, highlight_col_.r, highlight_col_.g, highlight_col_.b, line_thickness);
        win.draw_line(min_.x, max_.y, min_.x, min_.y, highlight_col_.r, highlight_col_.g, highlight_col_.b, line_thickness);
    }
    else{

    win.draw_line(min_.x, min_.y, max_.x, min_.y, col_.r, col_.g, col_.b, line_thickness);
    win.draw_line(max_.x, min_.y, max_.x, max_.y, col_.r, col_.g, col_.b, line_thickness);
    win.draw_line(max_.x, max_.y, min_.x, max_.y, col_.r, col_.g, col_.b, line_thickness);
    win.draw_line(min_.x, max_.y, min_.x, min_.y, col_.r, col_.g, col_.b, line_thickness);
    }
}

bool Rectangle::is_inside(const Vec2& point_) const {
    Vec2 m = 0.5 * (min_ + max_);

    Vec2 h = max_ + m;
    float abstand_max_und_m = sqrt(((h.x) * (h.x)) + ((h.y) * (h.y)));

    Vec2 g = point_ + m;
    float abstand_point_und_m = sqrt(((g.x) * (g.x)) + ((g.y) * (g.y)));
    if (abstand_point_und_m > abstand_max_und_m) {
        return false;
    }
    else {
        return true;
    }
}