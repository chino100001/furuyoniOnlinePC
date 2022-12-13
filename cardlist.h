#ifndef CARDLIST_H_H
#define CARDLIST_H_H

#define num_inf 10000





struct CARD_INFO
{
    int cardtype;//不持有此信息0,通常牌1,王牌2,毒牌3,transform4,兵员5,
    int id;//id编写方式:O-N1,N1-EX1,N2,N3...N7,S1,S1-EX1,S2...S4,(P1...P4),(ts1...ts4),A1-N1(以此类推)
    int rule;//1属于NA
    int megami;
    int megamiType;//0为O，依次类推
    int usedtype;//0为不定，攻击、行动、付与依次
    int subusedtype;//0为不定，全力、对应依次
    bool isAttack;
    bool range[100]={0};//下标10等于0距
    int auraAttack;
    int healthAttack;
    bool isHalo;//忘了付与牌怎么翻译了
    int amountHalo;
    bool isAction;
    bool isSuper;
    int cost;
};


CARD_INFO card[10000];





#endif
