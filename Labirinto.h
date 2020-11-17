#ifndef Labirinto_h
#define Labirinto_h

#include <cstdlib>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>
using namespace std;

const int LARGURA = 5;
const int ALTURA = 5;
const char DIREITA = 0;
const char ESQUERDA = 1;
const char CIMA = 2;
const char BAIXO = 3;
const char VISITANDO = 'V';
const char VOLTANDO = 'R';
const char VAZIO = '.';
const char QUEIJO = 'Q';
const char PAREDE = 'P';
const char ENTRADA = 'E';




struct Rato{
    int posX = 0;
    int posY = 0;
    bool temQueijo = false;
    int deOndeVeio = ESQUERDA;
};


void desenharMapa(char mapa[ALTURA][LARGURA]){
    for (int i = 0; i < ALTURA; i++){
        for (int j = 0; j < ALTURA; j++){
            cout << mapa[i][j] << "\t";
        } cout << endl;
    }
    cout << endl;
}

char construirMapa(char mapa[ALTURA][LARGURA]){
    srand(time(NULL));  
    int entradaPosX = rand() % 5;
    int entradaPosY = rand() % 5;     

    for (int i = 0; i < ALTURA; i++){
        for (int j = 0; j < ALTURA; j++){
            if (i < 4 and j == 1)
                mapa[i][j] = PAREDE;
            else if (i == 2 and j == 2)
                mapa[i][j] = QUEIJO;
            else if(i == entradaPosX and j == entradaPosY and mapa[i][j] != PAREDE and mapa[i][j] != QUEIJO)
                mapa[i][j] = ENTRADA;
            else
                mapa[i][j] = VAZIO;
        }
    }
    desenharMapa(mapa);
    Sleep(1000);

bool procurarQueijo(char labirinto[LARGURA][ALTURA],int posX,int posY, int deOndeVeio, bool &temQueijo){
    if(posX < 0 || posY < 0 || posX >= LARGURA || posY >= ALTURA){
        return false;
    }else if(labirinto[posX][posY]==QUEIJO){
        temQueijo = true;
        labirinto[posX][posY] = VOLTANDO;
        desenharMapa(labirinto);
        Sleep(1000);
        return true;
    }else if(labirinto[posX][posY]==PAREDE || labirinto[posX][posY] == VISITANDO){
        return false;
    }else{
        labirinto[posX][posY] = VISITANDO;
        desenharMapa(labirinto);
        Sleep(1000);

        if(deOndeVeio != DIREITA and procurarQueijo(labirinto,posX,posY+1, ESQUERDA, temQueijo)){
            labirinto[posX][posY] = VOLTANDO;
            desenharMapa(labirinto);
            Sleep(1000);
            return true;
        }else if(deOndeVeio != BAIXO and procurarQueijo(labirinto,posX+1,posY, CIMA, temQueijo)){
            labirinto[posX][posY] = VOLTANDO;
            desenharMapa(labirinto);
            Sleep(1000);
            return true;
        }else if(deOndeVeio != ESQUERDA and procurarQueijo(labirinto,posX,posY-1, DIREITA, temQueijo)){
            labirinto[posX][posY] = VOLTANDO;
            desenharMapa(labirinto);
            Sleep(1000);
            return true;
        }else if(deOndeVeio != CIMA and procurarQueijo(labirinto,posX-1,posY, BAIXO, temQueijo)){
            labirinto[posX][posY] = VOLTANDO;
            desenharMapa(labirinto);
            Sleep(1000);
            return true;
        }
        desenharMapa(labirinto);
    }
    return false;
}

#endif
