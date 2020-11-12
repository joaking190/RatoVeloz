#include <iostream>
#include "MAPA.h"
#include "Rato.h"

using namespace std;


const char RATO = 'R';


void mostrarposicaorato(Rato umRato){
    cout << "R" << umRato.forma << endl;

}

int main(){
mapa olabirinto;
desenharMapa(olabirinto);

Rato orato;

orato.posX=0;
orato.posY=0;
orato.forma= RATO;
mostrarposicaorato(orato);
}