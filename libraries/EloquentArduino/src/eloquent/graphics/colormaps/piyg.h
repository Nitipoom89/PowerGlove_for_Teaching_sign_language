//
// Created by Simone on 18/05/2022.
//

#pragma once
#include "../../macros.h"


namespace Eloquent {
    namespace Graphics {
        namespace Colormaps {
            class PiYG {
            public:

                /**
                 * Convert single byte to RGB color
                 * @param x
                 * @param r
                 * @param g
                 * @param b
                 */
                void convert(uint8_t x, uint8_t *r, uint8_t *g, uint8_t *b) {
                    *r = red[x << 2];
                    *g = green[x << 2];
                    *b = blue[x << 2];
                }

            protected:
                uint8_t red[64] = {142, 150, 159, 168, 176, 185, 194, 199, 203, 207, 211, 215, 219, 223, 226, 229, 232, 235, 238, 241, 243, 245, 246, 248, 250, 252, 252, 251, 250, 249, 248, 247, 245, 242, 240, 237, 234, 232, 228, 221, 213, 206, 199, 192, 184, 175, 166, 157, 148, 139, 130, 122, 114, 106, 98, 90, 82, 75, 69, 63, 57, 51, 45, 39};
                uint8_t green[64] = {1, 5, 9, 13, 17, 21, 25, 37, 51, 66, 81, 95, 110, 122, 132, 143, 153, 163, 172, 182, 189, 195, 202, 209, 215, 222, 226, 230, 234, 237, 241, 245, 246, 246, 246, 245, 245, 245, 244, 241, 238, 234, 231, 228, 225, 219, 213, 207, 202, 196, 190, 184, 177, 170, 164, 157, 150, 143, 136, 129, 121, 114, 107, 100};
                uint8_t blue[64] = {82, 88, 95, 102, 109, 116, 122, 130, 138, 146, 153, 161, 169, 176, 183, 190, 197, 204, 211, 218, 221, 225, 228, 231, 235, 238, 240, 241, 242, 243, 245, 246, 243, 237, 231, 225, 219, 212, 205, 193, 182, 170, 158, 146, 135, 124, 113, 102, 91, 80, 69, 61, 56, 51, 46, 41, 36, 32, 31, 30, 28, 27, 26, 25};
            };
        }
    }
}

ELOQUENT_SINGLETON(Eloquent::Graphics::Colormaps::PiYG piyg);