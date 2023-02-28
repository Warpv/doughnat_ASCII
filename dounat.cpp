#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<math.h>
#include<iostream>
#include<vector>


// int win_fnn(){
//   std::vector<int> fnn(8);
 
//   // calling fill to initialize values in the
//   // range to 4
//   std::fill(fnn.begin() + 2, fnn.end() - 1, 4);
 
//   for (int i=0; i<fnn.size(); i++)
//     std::cout << fnn[i] << " ";

//     return fnn;
// }



int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    //printf("\x1b[2J");  // upper space
    for(;;) {
            // TODO - make buffer bigger    
            //        try with vector, not memset
        memset(b, 126, 1760);   // 128 - ASCII num symbol, max text buff 1760
        memset(z, 0, 7040);     // z buffer
        for(j = 0; j < 6.28; j += 0.001) {
            for(i = 0; i < 6.28; i += 0.05) {    // rotate circle around a bigger circle "6.28 - is a full rotation 
                float   c = sin(i),  d = cos(j), e = sin(A), f = sin(j), g = cos(A),
                        l = cos(i), m = cos(B), n = sin(B),
                        h = d + 2,  //size of inner diametr doughnat 
                        D = 1 / (c * h * e + f * g + 5), // D - depth of "camera"
                        t = c * h * g - f * e;
                int x = 35 + 40 * D * (l * h * m - t * n),  // cam move Ox axis on screen
                    y = 12 + 15 * D * (l * h * n + t * m),   // cam move Oy axis on screen
                    o = x + 80 * y,
                    N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {    // condition of light reflection
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H"); // clear screen
        for(k = 0; k < 1761; k++) {     // render full screen, max value is z
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;   //rotation Ox based on A value
            B += 0.00002;   //rotation Oz based on B value
        }
        
    }
    return 0;
}