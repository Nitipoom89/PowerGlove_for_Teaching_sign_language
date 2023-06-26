//
// Created by Simone on 18/05/2022.
//

#pragma once
#include "../../macros.h"


namespace Eloquent {
    namespace Graphics {
        namespace Colormaps {
            class Pastel2_r {
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
                uint8_t red[64] = {204, 204, 204, 204, 204, 204, 204, 204, 241, 241, 241, 241, 241, 241, 241, 241, 255, 255, 255, 255, 255, 255, 255, 255, 230, 230, 230, 230, 230, 230, 230, 230, 244, 244, 244, 244, 244, 244, 244, 244, 203, 203, 203, 203, 203, 203, 203, 203, 253, 253, 253, 253, 253, 253, 253, 253, 179, 179, 179, 179, 179, 179, 179, 179};
                uint8_t green[64] = {204, 204, 204, 204, 204, 204, 204, 204, 226, 226, 226, 226, 226, 226, 226, 226, 242, 242, 242, 242, 242, 242, 242, 242, 245, 245, 245, 245, 245, 245, 245, 245, 202, 202, 202, 202, 202, 202, 202, 202, 213, 213, 213, 213, 213, 213, 213, 213, 205, 205, 205, 205, 205, 205, 205, 205, 226, 226, 226, 226, 226, 226, 226, 226};
                uint8_t blue[64] = {204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 204, 174, 174, 174, 174, 174, 174, 174, 174, 201, 201, 201, 201, 201, 201, 201, 201, 228, 228, 228, 228, 228, 228, 228, 228, 232, 232, 232, 232, 232, 232, 232, 232, 172, 172, 172, 172, 172, 172, 172, 172, 205, 205, 205, 205, 205, 205, 205, 205};
            };
        }
    }
}

ELOQUENT_SINGLETON(Eloquent::Graphics::Colormaps::Pastel2_r pastel2_r);