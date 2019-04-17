# ifndef VEC2_HPP
# define VEC2_HPP

// Vec2 data type definition

struct Vec2
{
/* TODO add member variables with
default member initialisation */

    float x = 0.0f;
    float y = 0.0f;

    Vec2 & operator +=( Vec2 const & v );
    Vec2 & operator -=( Vec2 const & v );
    Vec2 & operator *=( float s );
    Vec2 & operator /=( float s );

};
# endif // VEC2_HPP