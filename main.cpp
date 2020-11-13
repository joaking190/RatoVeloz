#include <iostream>
#include "Labirinto.h"
using namespace std;

int main(){
    char labirinto[5][5] = {

        ENTRADA, PAREDE, QUEIJO, VAZIO, VAZIO,
        VAZIO, PAREDE, VAZIO, VAZIO, VAZIO,
        VAZIO, PAREDE, VAZIO, VAZIO, VAZIO,
        VAZIO, PAREDE, VAZIO, VAZIO, VAZIO,
        VAZIO, VAZIO, VAZIO, VAZIO, VAZIO};

    Rato rato;

    procurarQueijo(labirinto, rato.posX, rato.posY,rato.deOndeVeio, rato.temQueijo);

}