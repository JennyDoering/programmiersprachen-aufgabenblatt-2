#include "mat2.hpp"

// Memberfunktion
Mat2 & operator *=( Mat2 const & m ) {
    // float e_00 = (a* e + b* g);
    // float e_01 = (a* f + b* h);
    // float e_10 = (c* e + d* g);
    // float e_11 = (c* f + d* h);

    // e_00 = (a.m * s + b.m * s);
    // e_01 = (a.m * s + b.m * s);
    // e_01 = (c.m * s + d.m * s);
    // e_11 = (c.m * s + d.m * s);

    float s;
    m := {e_00, e_01, e_10, e_11};
    e_00 = (e_00.m * s + e_01.m * s);
    e_01 = (e_00.m * s + e_01.m * s);
    e_01 = (e_10.m * s + e_11.m * s);
    e_11 = (e_10.m * s + e_11.m * s);
    return *this;
}


