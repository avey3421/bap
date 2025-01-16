/*
Mandelbrot Set in Terminal
made by DIMITRIS TSIOLAKIS
*/

#include <stdio.h>

#define WIDTH 100
#define HEIGHT 60
#define LIMIT 30

char IsInMandelbrot(float x, float y)
{
    float x0 = x;
    float y0 = y;
    for (int i = 0; i < LIMIT; i++)
    {
        if (x*x + y*y > 4)
        {
            return 0;
        }
        float xtemp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtemp;
    }
    return 1;
}

float MapRange(int i, int imax, float s, float e)
{
    float r = (float)i / imax;
    float l = (e - s) * r;
    return s + l;
}


int main()
{
    char* screen = malloc(WIDTH * HEIGHT);

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            float x0 = MapRange(j, WIDTH, -2, -1);
            float y0 = MapRange(i, HEIGHT, 2, -2);
            if (IsInMandelbrot(x0, y0))
            {
                screen[i * WIDTH + j] = '*';
            }
            else
            {
                screen[i * WIDTH + j] = ' ';
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            printf("%c", screen[i * WIDTH + j]);
        }
        printf("\n");
    }

    free(screen);
    return 0;
}

