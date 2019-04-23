// Mat2 definition
# include <array>

struct Mat2 {

// matrix layout :
// e_00 e_01
// e_10 e_11

float e_00 = 1.0f;
float e_01 = 0.0f;
float e_10 = 0.0f;
float e_11 = 1.0f;

// TODO ( in mat2 . cpp ) Definition v . operator *=
Mat2 & operator *=( Mat2 const & m );

};

// TODO ( in mat2 . cpp ) Definition v . operator *
Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 );