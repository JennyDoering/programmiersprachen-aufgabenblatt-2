 # include "clock.hpp"
 # include "window.hpp"

int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};

  while (!win.should_close()) {

auto zeit = win.get_time();

int stunde = zeit / 3600;
int minute = zeit / 60;
int sekunde = (int)zeit % 60;

std::string display_text = "Vergangene Zeit seit Start: " + std::to_string(stunde) + " h " + std::to_string(minute) + " min " + std::to_string(sekunde) + " s ";
    
int text_offset_x = 10;
int text_offset_y = 5;
unsigned int font_size = 35;
    
win.draw_text(text_offset_x, text_offset_y, font_size, display_text);

Circle grund = Circle({400.0f, 400.0f}, 200.0f, Color {1.0f, 1.0f, 1.0f});
grund.draw(win, 2.0f, false);

Vec2 stunde_punkt = {400.0f, 400.0f};
Vec2 minute_punkt = {400.0f, 400.0f};
Vec2 sekunde_punkt = {400.0f, 400.0f};

float winkel_stunde = (2 * M_PI) / 60;
float winkel_minute = (2 * M_PI) / 60;
float winkel_sekunde = (int)(2 * M_PI) % 12;

win.draw_line(minute_punkt.x, minute_punkt.y, 180.0f * cos(winkel_stunde * (sekunde - 15)) + 400.0f, 180.0f * sin(winkel_stunde * (sekunde - 15)) + 400.0f, 1.0f, 1.0f, 0.0f);
win.draw_line(minute_punkt.x, minute_punkt.y, 150.0f * cos(winkel_stunde * (minute - 15)) + 400.0f, 150.0f * sin(winkel_stunde * (minute - 15)) + 400.0f, 1.0f, 0.0f, 1.0f);
win.draw_line(minute_punkt.x, minute_punkt.y, 90.0f * cos(winkel_stunde * 5 * (stunde - 15)) + 400.0f, 90.0f * sin(winkel_stunde * 5 * (stunde - 15)) + 400.0f, 0.0f, 1.0f, 0.0f);

auto mouse_position = win.mouse_position();

win.update();

  }
}