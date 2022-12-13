#ifndef PLACE_H_H
#define PLACE_H_H

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<ctime>
#include<list>

using namespace std;
#define num_inf 10000

struct CARD
{
    int keeper;
    int id;
    int sakura=0;
    int megami;
    list<CARD*> about;
};

struct PLACE
{
    bool isPlacehad;
    bool isSakuraallow;
    int amountSakura;
    int upperSakura;
    bool isCardallow;
    bool isCardselfKnow;
    bool isCardOtherKnow;
    int amountCard;
    int upperCard;
    CARD aboutCard[100];
    bool isCardfront;
    bool isCardcross;
};
int concentraSelf=0,concentraOppo=0,range_front=0,range_back=0,range_close=2;
PLACE RANGE,AURASELF,AURAOPPO,HEALTHSELF,HEALTHOPPO,POWERSELF,POWEROPPO,VOID;
PLACE DECKSELF,DECKOPPO,HANDSELF,HANDOPPO,FRONTSELF,FRONTOPPO,BEHINDSELF,BEHINDOPPO;
PLACE SUPERSELF,SUPEROPPO,ENHANCEMENTSELF,ENHANCEMENTOPPO,EXSELF,EXOPPO,USINGSELF,USINGOPPO,SEAL;
PLACE OUTGAMESELF,OUTGAMEOPPO,GAMEOUTSELF,GAMEOUTOPPO;



#endif

