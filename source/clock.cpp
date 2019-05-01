 # include "clock.hpp"
 # include "window.hpp"
 //# include <vector>
//  #include "window.hpp"
// #include <GLFW/glfw3.h>
// #include <utility>
// #include <cmath>
// #include "rectangle.hpp"
// #include "circle.hpp"

//  auto t = win.get_time();
//         int temp;
//         int th = t / 3600;
//         int tm = t / 60;
//         int ts = int(t) % 60;
//         std::string display_text = "Time: "
//                                    + std::to_string(th) + "h "
//                                    + std::to_string(tm) + "m "
//                                    + std::to_string(ts) + "s";
//         int text_offset_x = 5;
//         int text_offset_y = 480;
//         unsigned int font_size = 25;
//         win.draw_text(text_offset_x,
//                       text_offset_y,
//                       font_size,
//                       display_text);
 
// Circle base{Vec2{250, 250}, 250, Color{0, 0, 0}};
// base.draw(win, 2);
// Circle middle{Vec2{250, 250}, 2};
// middle.draw(win, Color{0, 0, 0}, 2);
// Vec2 mid{250, 250};
// Vec2 sec{250, 0};

// float angle = 2 * M_PI / 60;
// float angle_h = 1.5708; // bottom of the clock in radiants
// float angle_min = angle_h;
// for (int i = 1; i <= 60; i++) {
//     win.draw_point(250 * cos(angle_h) + 250, 250 * sin(angle_h) + 250, 1, 1, 1);
//     win.draw_point(250 * cos(angle_min) + 250, 250 * sin(angle_min) + 250, 0.5, 0.5, 0.5);
//     angle_h += 0.523599;     // + 30° -> every hour
//     angle_min += 0.10472;    // + 6°  -> every min
//     }

// win.draw_line(mid.x, mid.y, 250 * cos(angle * (ts - 15)) + 250, 250 * sin(angle * (ts - 15)) + 250, 1, 0, 0);
// win.draw_line(mid.x, mid.y, 200 * cos(angle * (tm - 15)) + 250, 200 * sin(angle * (tm - 15)) + 250, 1, 1, 1, 2);
// win.draw_line(mid.x, mid.y, 150 * cos(angle * 5 * (th - 15)) + 250, 150 * sin(angle * 5 * (th - 15)) + 250, 0, 0, 0, 5);

// auto mouse_position = win.mouse_position();

// win.update();



auto zeit = win.get_time();

int stunde = zeit / 3600;
int minute = zeit / 60;
int sekunde = zeit % 60;

std::string display_text = "Vergangene Zeit seit Start: " + std::to_string(stunde) + " h " + std::to_string(minute) + " min " + std::to_string(sekunde) + " s ";
    
int text_offset_x = 10;
int text_offset_y = 5;
unsigned int font_size = 35;
    
win.draw_text(text_offset_x, text_offset_y, font_size, display_text);


Circle grund = Circle({400.0f, 400.0f}, 200.0f, Color {1.0f, 1.0f, 1.0f});
grund.draw(win, 2.0f, false);

// std::vector <Circle> Circles;
// Circles.push_back(grund);

Vec2 stunde_punkt = {400.0f, 200.0f};
Vec2 minute_punkt = {400.0f, 350.0f};
Vec2 sekunde_punkt = {400.0f, 300.0f};

float winkel_stunde = (2 * M_PI) / 60;
float winkel_minute = (2 * M_PI) / 60;
float winkel_sekunde = (2 * M_PI) % 12;

for (int i = 1; i <= 60; ++i) {
    win.draw_point(200.0f * std::cos(winkel_stunde) + 200.0f, 200.0f * std::sin(winkel_stunde) + 200.0f, 0.0f, 0.0f, 1.0f);
    win.draw_point(200.0f * std::cos(winkel_minute) + 200.0f, 200.0f * std::sin(winkel_minute) + 200.0f, 1.0f, 0.0f, 0.0f);
    winkel_stunde += (((2 * M_PI) / 360) * 30); // 360 Grad / 12h = 30
    winkel_minute += (((2 * M_PI) / 360) * 6); // 360 Grad / 60min = 6
} 

win.draw_line(minute_punkt.x, minute_punkt.y, 250.0f * cos(winkel_stunde * (sekunde - 15)) + 250, 250 * sin(winkel_stunde * (sekunde - 15)) + 250, 1, 0, 0);
win.draw_line(minute_punkt.x, minute_punkt.y, 200.0f * cos(winkel_stunde * (minute - 15)) + 250, 200 * sin(winkel_stunde * (minute - 15)) + 250, 1, 1, 1, 2);
win.draw_line(minute_punkt.x, minute_punkt.y, 150.0f * cos(winkel_stunde * 5 * (stunde - 15)) + 250, 150 * sin(winkel_stunde * 5 * (stunde - 15)) + 250, 0, 0, 0, 5);

auto mouse_position = win.mouse_position();

win.update();
