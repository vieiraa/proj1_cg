#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

int differentColors(color_t c1, color_t c2) {
    if ((c1.red != c2.red) || (c1.green != c2.green) || (c1.blue != c2.blue))
        return 1;

    return 0;
}

void interpolate(color_t *c1, const color_t c2) {
    if (differentColors(*c1, c2)) {
        if (c1->red > c2.red)
            c1->red--;
        else if (c1->red < c2.red)
            c1->red++;

        if (c1->green > c2.green)
            c1->green--;
        else if (c1->green < c2.green)
            c1->green++;

        if (c1->blue > c2.blue)
            c1->blue--;
        else if (c1->blue < c2.blue)
            c1->blue++;
    }
}

void putPixel(pixel_t pixel) {
    if (pixel.x > IMAGE_WIDTH || pixel.y > IMAGE_HEIGHT)
        return;

    int coord = IMAGE_WIDTH * pixel.y * 4 + pixel.x * 4;

    FBptr[coord] = pixel.color.red;
    FBptr[coord + 1] = pixel.color.green;
    FBptr[coord + 2] = pixel.color.blue;
    FBptr[coord + 3] = pixel.color.alpha;
}

void drawLine(pixel_t start, pixel_t end) {
    int dx = abs(end.x - start.x);
    int dy = abs(end.y - start.y);
    bool swap = false;

    if (dx == 0 && dy == 0) {
        putPixel(start);
        return;
    }

    if (dy > dx) {
        std::swap(start.x, start.y);
        std::swap(end.x, end.y);
        std::swap(dx, dy);

        swap = true;
    }

    int incx = 0;
    int incy = 0;

    if (start.x < end.x)
        incx = 1;
    else if (start.x > end.x)
        incx = -1;

    if (start.y < end.y)
        incy = 1;
    else if (start.y > end.y)
        incy = -1;

    int d = 2 * dy - dx;
    int incr_e = 2 * dy;
    int incr_ne = 2 * (dy - dx);

    pixel_t aux = start;

    while (1) {
        if (swap)
            putPixel({aux.y, aux.x, aux.color});
        else
            putPixel(aux);

        if (d <= 0)
            d += incr_e;

        else {
            aux.y += incy;
            d += incr_ne;
        }

        // interpolacao de cores
        interpolate(&(aux.color), end.color);

        if ((dy == 0 && dx != 0) || (dy != 0 && dx != 0)) {
            if (aux.x == end.x)
                break;
        }

        else if (dx == 0 && dy != 0) {
            if (aux.y == end.y)
                break;
        }

        aux.x += incx;
    }
}

void drawTriangle(pixel_t p1, pixel_t p2, pixel_t p3) {
    drawLine(p1, p2);
    drawLine(p1, p3);
    drawLine(p2, p3);
}

#endif // _MYGL_H_

