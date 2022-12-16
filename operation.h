#ifndef OPERATION_H_H
#define OPERATION_H_H

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include"place.h"
using namespace std;
#define num_inf 10000

bool all[100]={1};

bool damage(int damageAura,int damageHealth,PLACE *damageAuraGo,PLACE *damageHealthGo);
bool attack(int cardID,bool rangeAttack[],int damageAura,int damageHealth,int magami,bool normalReact,bool superReact,bool react,bool isAvoid,bool overDamage);
int reaction(bool normalReact,bool superReact);
bool game_init();
bool card_move(PLACE *placeFrom,PLACE *placeto,int cardNum,int cardTonum);
bool card_check(PLACE placeFind,bool option1,bool option2,bool option3,bool option4,bool option5);
int sakura_move(PLACE *placeFrom,PLACE *placeto,int amountMove);
bool arrow_move(PLACE *placeFrom,PLACE *placeto,int amountMove);
bool basic_move(int movement);
int range_count();
bool action_card_use(int indexCard);
bool attack_card_use(int indexCard);
bool enhancement_card_use(int indexCard);
bool card_use(int indexCard,PLACE *placefrom);
int card_choose(PLACE *placefrom,int typeCard,int typeUse,int subtypeUse,bool useRange[],int isSelfMegami,int typeSuper,int megami,int isBuild,int isPerjury,int isSet);
bool cost_check(int id);
int getId(int indexCard,PLACE *placefrom);
bool card_back(int placeTo);
bool sakura_relate(PLACE *placeRelate,int amountRelate,int indexCard);
bool enhancment_relate(int sakuraNeed);
bool drawcard(int amountCard);
bool addConcentration();
bool isReshuffle();
bool enhancement_check();
bool sectionStart();
bool sectionMain();
bool sectionEnd();

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

bool attack(int cardID,bool rangeAttack[],int damageAura,int damageHealth,int magami,bool normalReact=1,bool superReact=1,bool react=1,bool isAvoid=1,bool overDamage=0)
{
    bool isDamage=1,isEffect=1;
    if(!rangeAttack[range_count()])
        return 0;
    if(react)
        int reactid=reaction(normalReact,superReact);
    if(!rangeAttack[range_count()])
        return 0;
    if(isDamage)
        damage(damageAura,damageHealth);
    return 1;
}

bool game_init()
{
    srand(time(NULL));
    concentraOppo=rand()%2;
    concentraSelf=1-concentraOppo;

    RANGE.isPlacehad=1;
    RANGE.isSakuraallow=1;
    RANGE.isCardallow=0;
    RANGE.upperSakura=10;
    RANGE.amountSakura=10;
    
    AURASELF.isPlacehad=1;
    AURASELF.isCardallow=0;
    AURASELF.isSakuraallow=1;
    AURASELF.upperSakura=5;
    AURASELF.amountSakura=3;
    
    AURAOPPO.isPlacehad=1;
    AURAOPPO.isCardallow=0;
    AURAOPPO.isSakuraallow=1;
    AURAOPPO.upperSakura=5;
    AURAOPPO.amountSakura=3;

    HEALTHSELF.isPlacehad=1;
    HEALTHSELF.isCardallow=0;
    HEALTHSELF.isSakuraallow=1;
    HEALTHSELF.upperSakura=num_inf;
    HEALTHSELF.amountSakura=10;
    
    HEALTHOPPO.isPlacehad=1;
    HEALTHOPPO.isCardallow=0;
    HEALTHOPPO.isSakuraallow=1;
    HEALTHOPPO.upperSakura=num_inf;
    HEALTHOPPO.amountSakura=10;

    POWERSELF.isPlacehad=1;
    POWERSELF.isCardallow=0;
    POWERSELF.isSakuraallow=1;
    POWERSELF.upperSakura=num_inf;
    POWERSELF.amountSakura=0;
    
    POWEROPPO.isPlacehad=1;
    POWEROPPO.isCardallow=0;
    POWEROPPO.isSakuraallow=1;
    POWEROPPO.upperSakura=num_inf;
    POWEROPPO.amountSakura=0;

    VOID.isPlacehad=1;
    VOID.isSakuraallow=1;
    VOID.isCardallow=0;
    VOID.upperSakura=num_inf;
    VOID.amountSakura=0;

    DECKSELF.isCardallow=1;
    DECKSELF.isSakuraallow=0;
    DECKSELF.amountCard=0;
    DECKSELF.upperCard=num_inf;
    DECKSELF.isCardcross=0;
    DECKSELF.isCardfront=0;
    DECKSELF.isCardselfKnow=0;
    DECKSELF.isCardOtherKnow=0;

    DECKOPPO.isCardallow=1;
    DECKOPPO.isSakuraallow=0;
    DECKOPPO.amountCard=0;
    DECKOPPO.upperCard=num_inf;
    DECKOPPO.isCardcross=0;
    DECKOPPO.isCardfront=0;
    DECKOPPO.isCardselfKnow=0;
    DECKOPPO.isCardOtherKnow=0;

    HANDSELF.isCardallow=1;
    HANDSELF.isSakuraallow=0;
    HANDSELF.amountCard=0;
    HANDSELF.upperCard=2;
    HANDSELF.isCardcross=0;
    HANDSELF.isCardfront=0;
    HANDSELF.isCardselfKnow=1;
    HANDSELF.isCardOtherKnow=0;

    HANDOPPO.isCardallow=1;
    HANDOPPO.isSakuraallow=0;
    HANDOPPO.amountCard=0;
    HANDOPPO.upperCard=2;
    HANDOPPO.isCardcross=0;
    HANDOPPO.isCardfront=0;
    HANDOPPO.isCardselfKnow=0;
    HANDOPPO.isCardOtherKnow=1;

    FRONTSELF.isCardallow=1;
    FRONTSELF.isSakuraallow=0;
    FRONTSELF.amountCard=0;
    FRONTSELF.upperCard=num_inf;
    FRONTSELF.isCardcross=0;
    FRONTSELF.isCardfront=1;
    FRONTSELF.isCardselfKnow=1;
    FRONTSELF.isCardOtherKnow=1;

    FRONTOPPO.isCardallow=1;
    FRONTOPPO.isSakuraallow=0;
    FRONTOPPO.amountCard=0;
    FRONTOPPO.upperCard=num_inf;
    FRONTOPPO.isCardcross=0;
    FRONTOPPO.isCardfront=1;
    FRONTOPPO.isCardselfKnow=1;
    FRONTOPPO.isCardOtherKnow=1;

    BEHINDSELF.isCardallow=1;
    BEHINDSELF.isSakuraallow=0;
    BEHINDSELF.amountCard=0;
    BEHINDSELF.upperCard=num_inf;
    BEHINDSELF.isCardcross=1;
    BEHINDSELF.isCardfront=0;
    BEHINDSELF.isCardselfKnow=1;
    BEHINDSELF.isCardOtherKnow=0;

    BEHINDOPPO.isCardallow=1;
    BEHINDOPPO.isSakuraallow=0;
    BEHINDOPPO.amountCard=0;
    BEHINDOPPO.upperCard=num_inf;
    BEHINDOPPO.isCardcross=1;
    BEHINDOPPO.isCardfront=0;
    BEHINDOPPO.isCardselfKnow=0;
    BEHINDOPPO.isCardOtherKnow=1;

        SEAL.isCardallow=1;
        SEAL.isSakuraallow=0;
        SEAL.amountCard=0;
        SEAL.upperCard=num_inf;
        SEAL.isCardcross=0;
        SEAL.isCardfront=1;
        SEAL.isCardselfKnow=1;
        SEAL.isCardOtherKnow=1;

        SUPERSELF.isCardallow=1;
        SUPERSELF.isSakuraallow=1;
        SUPERSELF.amountSakura=0;
        SUPERSELF.upperSakura=num_inf;
        SUPERSELF.amountCard=0;
        SUPERSELF.upperCard=1;
        SUPERSELF.isCardcross=0;
        SUPERSELF.isCardfront=0;
        SUPERSELF.isCardselfKnow=1;
        SUPERSELF.isCardOtherKnow=0;

        SUPEROPPO.isCardallow=1;
        SUPEROPPO.isSakuraallow=1;
        SUPEROPPO.amountSakura=0;
        SUPEROPPO.upperSakura=num_inf;
        SUPEROPPO.amountCard=0;
        SUPEROPPO.upperCard=1;
        SUPEROPPO.isCardcross=0;
        SUPEROPPO.isCardfront=0;
        SUPEROPPO.isCardselfKnow=0;
        SUPEROPPO.isCardOtherKnow=1;

        ENHANCEMENTSELF.isCardallow=1;
        ENHANCEMENTSELF.isSakuraallow=1;
        ENHANCEMENTSELF.amountSakura=0;
        ENHANCEMENTSELF.upperSakura=num_inf;
        ENHANCEMENTSELF.amountCard=1;
        ENHANCEMENTSELF.upperCard=1;
        ENHANCEMENTSELF.isCardcross=0;
        ENHANCEMENTSELF.isCardfront=0;
        ENHANCEMENTSELF.isCardselfKnow=1;
        ENHANCEMENTSELF.isCardOtherKnow=0;

        ENHANCEMENTOPPO.isCardallow=1;
        ENHANCEMENTOPPO.isSakuraallow=1;
        ENHANCEMENTOPPO.amountSakura=0;
        ENHANCEMENTOPPO.upperSakura=1;
        ENHANCEMENTOPPO.amountCard=1;
        ENHANCEMENTOPPO.upperCard=1;
        ENHANCEMENTOPPO.isCardcross=0;
        ENHANCEMENTOPPO.isCardfront=0;
        ENHANCEMENTOPPO.isCardselfKnow=0;
        ENHANCEMENTOPPO.isCardOtherKnow=1;

        EXSELF.isCardallow=1;
        EXSELF.isSakuraallow=0;
        EXSELF.amountCard=1;
        EXSELF.upperCard=1;
        EXSELF.isCardcross=0;
        EXSELF.isCardfront=1;
        EXSELF.isCardselfKnow=1;
        EXSELF.isCardOtherKnow=1;

        EXOPPO.isCardallow=1;
        EXOPPO.isSakuraallow=0;
        EXOPPO.amountCard=1;
        EXOPPO.upperCard=1;
        EXOPPO.isCardcross=0;
        EXOPPO.isCardfront=1;
        EXOPPO.isCardselfKnow=1;
        EXOPPO.isCardOtherKnow=1;

        USINGSELF.isCardallow=1;
        USINGSELF.isSakuraallow=0;
        USINGSELF.amountCard=1;
        USINGSELF.upperCard=1;
        USINGSELF.isCardcross=0;
        USINGSELF.isCardfront=1;
        USINGSELF.isCardselfKnow=1;
        USINGSELF.isCardOtherKnow=1;

        USINGOPPO.isCardallow=1;
        USINGOPPO.isSakuraallow=0;
        USINGOPPO.amountCard=1;
        USINGOPPO.upperCard=1;
        USINGOPPO.isCardcross=0;
        USINGOPPO.isCardfront=1;
        USINGOPPO.isCardselfKnow=1;
        USINGOPPO.isCardOtherKnow=1;
    

    OUTGAMESELF.isCardallow=1;
    OUTGAMESELF.isSakuraallow=1;
    OUTGAMESELF.amountSakura=1000;
    OUTGAMESELF.upperSakura=num_inf;
    OUTGAMESELF.amountCard=0;
    OUTGAMESELF.upperCard=num_inf;
    OUTGAMESELF.isCardcross=0;
    OUTGAMESELF.isCardfront=0;
    OUTGAMESELF.isCardselfKnow=1;
    OUTGAMESELF.isCardOtherKnow=0;

    OUTGAMEOPPO.isCardallow=1;
    OUTGAMEOPPO.isSakuraallow=1;
    OUTGAMEOPPO.amountSakura=1000;
    OUTGAMEOPPO.upperSakura=num_inf;
    OUTGAMEOPPO.amountCard=0;
    OUTGAMEOPPO.upperCard=num_inf;
    OUTGAMEOPPO.isCardcross=0;
    OUTGAMEOPPO.isCardfront=0;
    OUTGAMEOPPO.isCardselfKnow=0;
    OUTGAMEOPPO.isCardOtherKnow=1;

    GAMEOUTSELF.isCardallow=1;
    GAMEOUTSELF.isSakuraallow=1;
    GAMEOUTSELF.amountSakura=0;
    GAMEOUTSELF.upperSakura=num_inf;
    GAMEOUTSELF.amountCard=0;
    GAMEOUTSELF.upperCard=num_inf;
    GAMEOUTSELF.isCardcross=0;
    GAMEOUTSELF.isCardfront=1;
    GAMEOUTSELF.isCardselfKnow=1;
    GAMEOUTSELF.isCardOtherKnow=1;

    GAMEOUTOPPO.isCardallow=1;
    GAMEOUTOPPO.isSakuraallow=1;
    GAMEOUTOPPO.amountSakura=0;
    GAMEOUTOPPO.upperSakura=num_inf;
    GAMEOUTOPPO.amountCard=0;
    GAMEOUTOPPO.upperCard=num_inf;
    GAMEOUTOPPO.isCardcross=0;
    GAMEOUTOPPO.isCardfront=1;
    GAMEOUTOPPO.isCardselfKnow=1;
    GAMEOUTOPPO.isCardOtherKnow=1;
    return true;
}

bool card_check(PLACE placeFind,bool option1,bool option2,bool option3,bool option4,bool option5)
{
    return 1;
}

bool card_move(PLACE *placeFrom,PLACE *placeto,int cardNum,int cardTonum)
{
    
    for(int i=placeto->amountCard;i>cardTonum;i--)
        placeto->aboutCard[i+1]=placeto->aboutCard[i];
    placeFrom->amountCard=placeFrom->amountCard-1;
    placeto->amountCard=placeto->amountCard+1;
    placeto->aboutCard[cardTonum]=placeFrom->aboutCard[cardNum];
    for(int i=cardNum;i<placeFrom->amountCard;i++)
        placeFrom->aboutCard[i]=placeFrom->aboutCard[i+1];
    if(placeto->aboutCard[cardTonum].sakura>0)
        sakura_move(placeFrom,placeto,placeto->aboutCard[cardTonum].sakura);
    return 1;
}

int sakura_move(PLACE *placeFrom,PLACE *placeto,int amountMove)
{
    int maxx1=placeFrom->amountSakura;
    int maxx2=placeto->upperSakura-placeto->amountSakura;
    int maxx=maxx1<maxx2?maxx1:maxx2;
    maxx=maxx<amountMove?maxx:amountMove;
    if(maxx)
    {
        placeFrom->amountSakura=placeFrom->amountSakura-maxx;
        placeto->amountSakura=placeto->amountSakura+maxx;
    }
    return maxx;
}

bool arrow_move(PLACE *placeFrom,PLACE *placeto,int amountMove)
{
    //if(bachongying==1 && user==myself)
    //AURASELF.upperSakura=8;
    int maxx1=placeFrom->amountSakura;
    int maxx2=placeto->upperSakura-placeto->amountSakura;
    int maxx=maxx1<maxx2?maxx1:maxx2;
    maxx=maxx<amountMove?maxx:amountMove;
    if(maxx)
    {
        placeFrom->amountSakura=placeFrom->amountSakura-maxx;
        placeto->amountSakura=placeto->amountSakura+maxx;
    }
    //arrow_move_count+1
    //AURASELF.upperSakura=5;
    return 1;
}

bool basic_move(int movement=0)
{
    if(movement==0)
    {
        cin>>movement;//1-5：前进、后退、装付、集气、离脱,后面修改成选择
    }
    if(movement==1 && range_count()>range_close)
        sakura_move(&RANGE,&AURASELF,1);
    if(movement==2)
        sakura_move(&AURASELF,&RANGE,1);
    if(movement==3)
        sakura_move(&VOID,&AURASELF,1);
    if(movement==4)
        sakura_move(&AURASELF,&POWERSELF,1);
    if(movement==5 && range_count()<=range_close)
        sakura_move(&VOID,&RANGE,1);
    return 1;
}

int range_count()
{
    return RANGE.amountSakura;
}

bool action_card_use(int indexCard)
{
    int cardID=getId(indexCard,&USINGSELF);
    return 1;
}

bool attack_card_use(int indexCard)
{
    int cardID=getId(indexCard,&USINGSELF);
    attack(cardID,card[cardID].range,card[cardID].auraAttack,card[cardID].healthAttack,card[cardID].megami);
    return 1;
}

bool enhancement_card_use(int indexCard)
{
    int cardID=getId(indexCard,&USINGSELF);
    return 1;
}

bool cost_check(int id)
{
    //燃烧、理、尸、远心、距离
    int costPower=card[id].cost;
    if(costPower>POWERSELF.amountSakura)
        return 0;
    return 1;
}

bool card_use(int indexCard,PLACE *placefrom)
{
    //amountUsingoppo
    if(!cost_check(placefrom->aboutCard[indexCard].id))
        return 0;
    int idCard=getId(indexCard,placefrom);
    int megamiCard=placefrom->aboutCard[indexCard].megami;
    card_move(placefrom,&USINGSELF,indexCard,USINGSELF.amountCard+1);
    //获取id
    if(card[idCard].usedtype==1)
    {
        attack_card_use(USINGSELF.amountCard);
    }
    else if(card[idCard].usedtype==2)
    {
        action_card_use(USINGSELF.amountCard);
    }
    else if(card[idCard].usedtype==3)
    {
        enhancement_card_use(USINGSELF.amountCard);
    }
    return 1;
}

int card_choose(PLACE *placefrom,int typeCard,int typeUse,int subtypeUse,bool useRange[],int isSelfMegami=0,int typeSuper=2,int megami=0,int isBuild=1,int isPerjury=0,int isSet=0)
{
    int indexCard;
    bool index[100]={0};
    for(int i=1;i<=placefrom->amountCard;i++)
    {
        if(card[placefrom->aboutCard[i].id].cardtype==typeCard || typeCard==0)
            if(card[placefrom->aboutCard[i].id].usedtype==typeUse || typeUse==0)
                if(card[placefrom->aboutCard[i].id].subusedtype==typeUse || subtypeUse==0)
                    if(card[placefrom->aboutCard[i].id].megami!=isSelfMegami || isSelfMegami==0)
                        if(!useRange[range_count()])
                            if(placefrom->aboutCard[i].typeSuper==typeSuper || typeSuper==2)
                                if(placefrom->aboutCard[i].megami==megami || megami==0)
                                    if(cost_check(placefrom->aboutCard[i].id))
                                        index[i]=1;
    }

    cout<<endl;
    for(int i=1;i<=placefrom->amountCard;i++)
        cout<<placefrom->aboutCard[i].id<<" ";
    cout<<endl;
    cin>>indexCard;

    return indexCard;
}
//build构筑,perjury伪证,set设置

int getId(int indexCard,PLACE *placefrom)
{
    int idCard=placefrom->aboutCard[indexCard].id;
    return idCard;
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
        indexReact=card_choose(&HANDSELF,1,0,2,all);
        card_use(indexReact,&HANDSELF);
        getId(indexReact,&HANDSELF);
    }
    else if(chooseReact==2 && superReact)
    {
        indexReact=card_choose(&SUPERSELF,2,0,2,all);
        card_use(indexReact,&SUPERSELF);
        getId(indexReact,&SUPERSELF);
    }
    
    return idReact;
}

bool card_back(int placeTo=0)
{
    if(placeTo==0)
    {
        int cardId=getId(USINGSELF.amountCard,&USINGSELF);
        if(card[cardId].usedtype==3)
        {
            enhancment_relate(card[cardId].amountEnhancement);
            card_move(&USINGSELF,&ENHANCEMENTSELF,USINGSELF.amountCard,ENHANCEMENTSELF.amountCard+1);
        }
        else if(card[cardId].cardtype==1)
        {
            card_move(&USINGSELF,&FRONTSELF,USINGSELF.amountCard,FRONTSELF.amountCard+1);
        }
        else if(card[cardId].cardtype==2)
        {
            card_move(&USINGSELF,&SUPERSELF,USINGSELF.amountCard,SUPERSELF.amountCard+1);
        }
    }
    return 1;
}

bool sakura_relate(PLACE *placeRelate,int amountRelate,int indexCard)
{
    placeRelate->aboutCard[indexCard].sakura+=amountRelate;
    return 1;
}

bool enhancment_relate(int sakuraNeed)
{
    int auraProvide,voidProvide;
    if(AURASELF.amountSakura+VOID.amountSakura>sakuraNeed)
    {
        cin>>auraProvide>>voidProvide;
        sakura_move(&AURASELF,&USINGSELF,auraProvide);
        sakura_move(&VOID,&USINGSELF,voidProvide);
        sakura_relate(&USINGSELF,auraProvide+voidProvide,USINGSELF.amountCard);
    }
    else
    {
        int numRelate=AURASELF.amountSakura+VOID.amountSakura;
        sakura_move(&AURASELF,&USINGSELF,AURASELF.amountSakura);
        sakura_move(&VOID,&USINGSELF,VOID.amountSakura);
        sakura_relate(&USINGSELF,numRelate,USINGSELF.amountCard);
    }
    return 1;
}

bool drawcard(int amountCard)
{
    for(int i=1;i<=amountCard;i++)
    {
        if(DECKSELF.amountCard!=0)
            card_move(&DECKSELF,&HANDSELF,DECKSELF.amountCard,HANDSELF.amountCard+1);
        else if(DECKSELF.amountCard==0)
            damage(1,1);
    }    
    return 1;
}

bool addConcentration()
{
    if(stunSelf)
        stunSelf=0;
    else if(concentraSelf<2)
        concentraSelf++;
    return 1;
}

bool enhancement_check()
{
    //执行破弃效果,取消展开中标签
    return 1;
}

bool isReshuffle()
{
    damage(num_inf,1);
    while(BEHINDSELF.amountCard>0)
        card_move(&BEHINDSELF,&RAND,BEHINDSELF.amountCard,RAND.amountCard+1);
    while(FRONTSELF.amountCard>0)
        card_move(&FRONTSELF,&RAND,FRONTSELF.amountCard,RAND.amountCard+1);
    while(DECKSELF.amountCard>0)
        card_move(&DECKSELF,&RAND,DECKSELF.amountCard,RAND.amountCard+1);
    while(RAND.amountCard>0)
    {
        srand(time(NULL));
        int numReshuffle=rand()%(RAND.amountCard+1);
        card_move(&RAND,&DECKSELF,numReshuffle,DECKSELF.amountCard+1);
    }
    return 1;
}

bool sectionStart()
{
    addConcentration();
    for(int i=1;i<=ENHANCEMENTSELF.amountCard;i++)
        sakura_relate(&ENHANCEMENTSELF,-1,i);
    for(int i=1;i<=ENHANCEMENTOPPO.amountCard;i++)
        sakura_relate(&ENHANCEMENTOPPO,-1,i);
    enhancement_check();
    isReshuffle();
    drawcard(2);

    return 1;
}

bool sectionMain()
{
    int action_choose;
    cin>>action_choose;
    if(action_choose==1)
    {
        //标准使用
        //选基本动作，通常牌，王牌，等等
    }
    if(action_choose==2)
    {
        //全力使用
    }
    return 1;
}

bool sectionEnd()
{
    while(HANDSELF.amountCard<=2)
    {
        int indexThrow=card_choose(&HANDSELF,0,0,0,all);
        card_move(&HANDSELF,&BEHINDSELF,indexThrow,BEHINDSELF.amountCard+1);
    }
    return 1;
}

#endif
