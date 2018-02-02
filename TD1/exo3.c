#include <stdlib.h>
#include <stdio.h>

typedef struct complexe_
{
    float Re;
    float Im;
} complexe;

void afficherComplexe(complexe z)
{
    printf("%f", z.Re);
    if (z.Im < 0)
    {
        printf("-%fi", -z.Im);
    }
    else
    {
        printf("+%fi", z.Im);
    }
}

complexe additionComplexe(complexe z1, complexe z2)
{
    complexe z;

    z.Re = z1.Re + z2.Re;
    z.Im = z1.Im + z2.Im;

    return z;
}

complexe soustractionComplexe(complexe z1, complexe z2)
{
    complexe z;

    z.Re = z1.Re - z2.Re;
    z.Im = z1.Im - z2.Im;

    return z;
}

complexe multiplicationComplexe(complexe z1, complexe z2)
{
    complexe z;

    z.Re = z1.Re * z2.Re - z1.Im * z2.Im;
    z.Im = z1.Re * z2.Im + z2.Re * z1.Im;

    return z;
}

complexe divisionComplexe(complexe z1, complexe z2)
{
    complexe z;

    z.Re = (z1.Re * z2.Re + z1.Im * z2.Im) / (z2.Re * z2.Re + z2.Im * z2.Im);
    z.Im = (z1.Im * z2.Re - z1.Re * z2.Im) / (z2.Re * z2.Re + z2.Im * z2.Im);

    return z;
}

int main()
{
    complexe z1;
    z1.Re = 1;
    z1.Im = -5;

    complexe z2;
    z2.Re = 2;
    z2.Im = 2;

    printf("z1=");
    afficherComplexe(z1);
    printf("\n");
    printf("z2=");
    afficherComplexe(z2);
    printf("\n");

    printf("z1+z2=");
    afficherComplexe(additionComplexe(z1, z2));
    printf("\n");
    printf("z1-z2=");
    afficherComplexe(soustractionComplexe(z1, z2));
    printf("\n");
    printf("z1*z2=");
    afficherComplexe(multiplicationComplexe(z1, z2));
    printf("\n");
    printf("z1/z2=");
    afficherComplexe(divisionComplexe(z1, z2));
    printf("\n");

    return 0;
}