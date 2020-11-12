#ifndef MAPA_h
#define MAPA_h

#include <iostream>

using namespace std;


const char QUEIJO = 'Q';
const char PAREDE = 'P';
const char ENTRADA = 'E';


struct mapa{
char labirinto[5][5] ={

    ENTRADA,PAREDE,QUEIJO,'0','0',
    '0',PAREDE,'0','0','0',
    '0',PAREDE,'0','0','0',
    '0',PAREDE,'0','0','0',
    '0','0','0','0','0'}; 

};



void desenharMapa(mapa Omapa){

for(int indice=0; indice<5; indice++){

    for(int j=0; j<5; j++){


        cout << Omapa.labirinto[indice][j] << "\t";
    }
cout << endl;
}
}



#endif




