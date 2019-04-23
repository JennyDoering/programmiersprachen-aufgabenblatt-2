#include "mat2.hpp"

// Memberfunktion
Mat2 & Mat2::operator *=( Mat2 const & m ) {
   
    // std::array (<std::array < float, 2 > , 2 > const & m);
    // m = { 
    //     {a, b}, 
    //     {c, d};
    // }
   
    // float e_00 = (a* e + b* g);
    // float e_01 = (a* f + b* h);
    // float e_10 = (c* e + d* g);
    // float e_11 = (c* f + d* h);

    // e_00 = (a.m * s + b.m * s);
    // e_01 = (a.m * s + b.m * s);
    // e_01 = (c.m * s + d.m * s);
    // e_11 = (c.m * s + d.m * s);

    // float s;
    // m := {e_00, e_01, e_10, e_11};
    // e_00 = (e_00.m * s + e_01.m * s);
    // e_01 = (e_00.m * s + e_01.m * s);
    // e_01 = (e_10.m * s + e_11.m * s);
    // e_11 = (e_10.m * s + e_11.m * s);

    // e_00 = (e_00 * s + e_01 * s);
    // e_01 = (e_00 * s + e_01 * s);
    // e_01 = (e_10 * s + e_11 * s);
    // e_11 = (e_10 * s + e_11 * s);

    // e_00 = e_00 * s;
    // e_01 = e_01 * s;
    // e_10 = e_10 * s;
    // e_11 = e_11 * s;

//     for(int x=0;x<zeilen;x++){
// 	for(int j=0;j<zeilen;j++){	
// 		int result = 0;
// 		for(int y=0;y<spalten;y++){			
// 				result += matrixA[x][y] * matrixB[y][j];
// 		}
// 		matrixC[x][j] = result;
// 	}		
// }

    

    return *this;
}


