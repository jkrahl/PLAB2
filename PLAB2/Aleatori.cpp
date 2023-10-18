#include <stdlib.h>
#include <time.h>

int Aleatori(int NumMin, int NumMax)
{
    int NumAleatori;
    srand((unsigned)time(NULL));
    NumAleatori = NumMin + (rand() % (NumMax - NumMin + 1));

    return NumAleatori;
}