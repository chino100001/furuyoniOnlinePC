#ifndef ATTACK_H_H
#define ATTACK_H_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"place.h"
#include"operation.h"
using namespace std;
#define num_inf 10000

bool damage(int damageAura,int damageHealth,PLACE *damageAuraGo,PLACE *damageHealthGo);
bool attack(int cardID,int rangeAttack[100],int damageAura,int damageHealth,int magami,bool normalReact,bool superReact,bool react,bool isAvoid,bool overDamage);
int reaction(bool normalReact,bool superReact);

bool damage(int damageAura,int damageHealth,PLACE *damageAuraGo=&VOID,PLACE *damageHealthGo=&POWEROPPO)
{
    if(damageAura>AURAOPPO.amountSakura)
        sakura_move(&AURAOPPO,damageAuraGo,damageAura);
    else
    {
        int xxx;
        cout<<"choose1/2";
        cin>>xxx;
        if(xxx==1)
            sakura_move(&AURAOPPO,damageAuraGo,damageAura);
        else
            sakura_move(&HEALTHOPPO,damageHealthGo,damageHealth);
    }
    return 1;
}

bool attack(int cardID,int rangeAttack[100],int damageAura,int damageHealth,int magami,bool normalReact=1,bool superReact=1,bool react=1,bool isAvoid=1,bool overDamage=0)
{
    bool isDamage=1,isEffect=1;
    if(react)
        int reactid=reaction(normalReact,superReact);
    if(isDamage)
        damage(damageAura,damageHealth);
    return 1;
}

int reaction(bool normalReact,bool superReact)
{
    //选择通常牌对应或者王牌对应或者不对应
    bool isReaction;
    cin>>isReaction;
    
    int indexReact=0;
    int idReact;
    int chooseReact;//1通常牌，2王牌，3兵舍
    if(isReaction)
        cin>>chooseReact;

    if(chooseReact==1 && normalReact)
    {
        indexReact=card_choose(&HANDSELF,1,0,2);
        card_use(indexReact,&HANDSELF);
        getId(indexReact,&HANDSELF);
    }
    else if(chooseReact==2 && superReact)
    {
        indexReact=card_choose(&SUPERSELF,2,0,2);
        card_use(indexReact,&SUPERSELF);
        getId(indexReact,&SUPERSELF);
    }
    
    return idReact;
}

#endif
