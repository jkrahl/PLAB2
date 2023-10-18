#include <iostream>
#include "Aleatori.h"
#define ESCUT 1
#define CARREGA 2
#define TRET 3
#define EMPAT 0
#define WINA 1
#define WINB 2

using namespace std;

void PresentacioJoc()
{
    cout << "Dam dam dish, es un joc infantil on es simula un duel de pistolers. L'objectiu del joc es matar al contrincant" << endl;
    cout << "El joc es per parelles hi ha tres moviments basics :" << endl;
    cout << "- Bracos en creu sobre el pit : escut" << endl;
    cout << "- Mans en forma de pistola apuntant al contrincant : tret" << endl;
    cout << "- Dits index i del mig tocant el lateral del front : carregar" << endl;
    cout << "El joc es al millor de N partides on N es un nombre senar" << endl;
}


bool Senar(int Num)
{
    return (Num % 2 != 0);
}

int LlegirSenar()
{
    int senar;
    cout << "Introduir un nombre senar" << endl;
    cin >> senar;
    while (!Senar(senar))
    {
        cout << "ERROR: El nombre introduit es parell" << endl;
        cout << "Introduir un nombre senar" << endl;
        cin >> senar;
    }
    return senar;
}

void MenuDamDamDish()
{
    cout << "Escull entre:" << endl;
    cout << "1. Escut: protegeix dels trets del rival" << endl;
    cout << "2. Carrega: afegeix una bala al carregador" << endl;
    cout << "3. Tret: dispara al teu rival" << endl;
}

int LlegirNombre(int min, int max)
{
    int input;
    cout << "Entra valor entre " << min << " i " << max << endl;
    cin >> input;
    while (input < min || input > max)
    {
        cout << "Error: valor fora de l'interval" << endl;
        cout << "Entra valor entre " << min << " i " << max << endl;
        cin >> input;
    }
    return input;
}

void MissatgeAI(int opcio)
{
    cout << "L'ordinador ha escollit aleatoriament ";
    switch (opcio)
    {
    case ESCUT:
        cout << "ESCUT" << endl;
        break;
    case CARREGA:
        cout << "CARREGA" << endl;
        break;
    case TRET:
        cout << "TRET" << endl;
        break;
    default:
        break;
    }
}

int JocDamDamDish(int Player1, int Player2)
{
    if (Player1 == TRET && Player2 == CARREGA)
    {
        return WINA;
    }
    else if (Player1 == CARREGA && Player2 == TRET)
    {
        return WINB;
    }
    else
    {
        return EMPAT;
    }
}

int main()
{
    int nPartides, eleccioMaquina, eleccioJugador, balesMaquina = 1, balesJugador = 1, guanyadesPerJugador = 0, guanyadesPerMaquina = 0;
    PresentacioJoc();
    nPartides = LlegirSenar();
    do
    {
        int guanyador;
        if (balesMaquina == 0)
            eleccioMaquina = Aleatori(1, 2);
        else
            eleccioMaquina = Aleatori(1, 3);
        MenuDamDamDish();
        eleccioJugador = LlegirNombre(1, 3);
        while (balesJugador == 0 && eleccioJugador == TRET)
        {
            cout << "No tens bales. Escull entre 1 (Escut) o 2 (Carrega)" << endl;
            eleccioJugador = LlegirNombre(1, 2);
        }
        if (eleccioJugador == CARREGA)
            balesJugador++;
        if (eleccioJugador == TRET)
            balesJugador--;
        if (eleccioMaquina == CARREGA)
            balesMaquina++;
        if (eleccioMaquina == TRET)
            balesMaquina--;
        guanyador = JocDamDamDish(eleccioJugador, eleccioMaquina);
        MissatgeAI(eleccioMaquina);
        switch (guanyador)
        {
        case EMPAT:
            cout << "Empat. Seguim la partida" << endl;
            break;
        case WINA:
            cout << "Guanyes Tu!!!" << endl;
            guanyadesPerJugador++;
            balesJugador = 1;
            balesMaquina = 1;
            break;
        case WINB:
            cout << "Et guanya un ordinador!!!" << endl;
            guanyadesPerMaquina++;
            balesJugador = 1;
            balesMaquina = 1;
            break;
        default:
            break;
        }
        cout << "MARCADOR - Ordinador " << guanyadesPerMaquina << " Tu " << guanyadesPerJugador << endl;

    } while (guanyadesPerJugador < ((nPartides / 2) + 1) && guanyadesPerMaquina < ((nPartides / 2) + 1));

    if (guanyadesPerMaquina > guanyadesPerJugador)
        cout << "El guanyador final es l'ordinador" << endl;
    else
        cout << "Tu ets el guanyador final" << endl;
}