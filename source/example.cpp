#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
# include "circle.hpp"
# include "rectangle.hpp"
# include "color.hpp"
# include "vec2.hpp"
# include "mat2.hpp"
# include <vector>
# include <array>


int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }

    bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

    auto t = win.get_time();

    float x1 = 400.f + 380.f * std::sin(t);
    float y1 = 400.f + 380.f * std::cos(t);

    float x2 = 400.f + 380.f * std::sin(2.0f*t);
    float y2 = 400.f + 380.f * std::cos(2.0f*t);

    float x3 = 400.f + 380.f * std::sin(t-10.f);
    float y3 = 400.f + 380.f * std::cos(t-10.f);

    win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
    win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
    win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);

    auto mouse_position = win.mouse_position();
    if (left_pressed) {
      win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                    mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                    1.0,0.0,0.0, // color with r,g,b in [0.0, 1.0]
                    1.0);        // line thickness = 1.0 * default thickness
    }

    win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
    win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second, mouse_position.second, 0.0, 0.0, 0.0);

    win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
    win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first, win.window_size().second, 0.0, 0.0, 0.0);

    std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " + std::to_string(mouse_position.second) + ")";
    
    int text_offset_x = 10;
    int text_offset_y = 5;
    unsigned int font_size = 35;
    
    win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

    // Aufgabe 2.11
    Circle k = Circle(Vec2 {200.0f, 200.0f}, 150.0f, Color {0.0f, 1.0f, 0.0f}, Color {0.0f, 1.0f, 1.0f});
    
    Circle c = Circle(Vec2 {500.0f, 560.0f}, 120.0f, Color {1.0f, 0.0f, 0.0f}, Color {1.0f, 1.0f, 0.0f});

    Rectangle n = Rectangle(Vec2 {400.0f, 300.0f}, Vec2 {600.0f, 100.0f}, Color {1.0f, 0.5f, 1.0f}, Color {1.0f, 1.0f, 1.0f});
   
    Rectangle a = Rectangle(Vec2 {100.0f, 700.0f}, Vec2 {250.0f, 500.0f}, Color {0.0f, 0.0f, 1.0f}, Color {0.0f, 0.0f, 0.0f});

    // Aufgabe 2.13
    std::vector <Circle> Circles;
    Circles.push_back(k);
    Circles.push_back(c);

    // std::vector <Rectangle> Rectangles;
    // Rectangles.push_back(n);
    // Rectangles.push_back(a);

    std::array <Rectangle,2> Rectangles = {n, a};

    for (int q = 0; q < Circles.size(); ++q) {
        if (Circles[q].is_inside_c(Vec2{float(mouse_position.first), float(mouse_position.second)})) {
            Circles[q].draw(win, 10.0f, true);
        } 
        else {
            Circles[q].draw(win, 2.0f, false);
        }
    }

    for (int w = 0; w < Rectangles.size(); ++w) {
        if (Rectangles[w].is_inside(Vec2{float(mouse_position.first), float(mouse_position.second)})) {
            Rectangles[w].draw(win, 10.0f, true);
        } 
        else {
            Rectangles[w].draw(win, 2.0f, false);
        }
    }

    win.update(); 
  }

  return 0;
}
