#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

typedef struct pixel_
{
    // Position
    int x;
    int y;

    // Components
    short red;
    short green;
    short blue;
} pixel;

void printPixel(pixel monPixel)
{
    printf("%3d,%3d,%3d\n", monPixel.red, monPixel.green, monPixel.blue);
}

void printImage(pixel *image)
{
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        printPixel(*(image + i));
    }
}

void niveauGris(pixel *monPixel)
{
    short gris = (monPixel->red + monPixel->green + monPixel->blue) / 3;

    monPixel->red = gris;
    monPixel->green = gris;
    monPixel->blue = gris;
}

void imageGris(pixel *image)
{
    for (int i = 0; i < SIZE * SIZE; i++)
    {
        niveauGris((image + i));
    }
}

int main()
{
    srand(time(NULL));

    pixel image[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j].red = rand() % 256;
            image[i][j].green = rand() % 256;
            image[i][j].blue = rand() % 256;
        }
    }

    imageGris(image);

    printImage(image);

    return 0;
}