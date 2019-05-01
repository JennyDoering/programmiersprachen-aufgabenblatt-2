# ifndef CLOCK_HPP
# define CLOCK_HPP
# include "vec2.hpp"
# include "mat2.hpp"
# include "window.hpp"
# include "circle.hpp"
# include "rectangle.hpp"
# include <cmath>

# include <GLFW/glfw3.h>
# include <utility>
# include "color.hpp"
# include <vector>


struct NVGcontext;
struct GLFWwindow;

class Clock {

public: 
    
    Clock();
    Clock(Circle const& kreis_uhr);
    
};

# endif