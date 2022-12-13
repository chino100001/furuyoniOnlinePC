#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include"place.h"
#include"cardlist.h"
#include"operation.h"
//#include"attack.h"
using namespace std;
#define num_inf 10000


void stop()
{
    int fghjk;
    cin>>fghjk;
}

void operate_list()
{
    printf("SELFAURA:%d,HEALTH,:%d,POWER:%d\n",AURASELF.amountSakura,HEALTHSELF.amountSakura,POWERSELF.amountSakura);
    printf("OPPOAURA:%d,HEALTH,:%d,POWER:%d\n",AURAOPPO.amountSakura,HEALTHOPPO.amountSakura,POWEROPPO.amountSakura);
    printf("RANGE:%d,VOID:%d\n",RANGE.amountSakura,VOID.amountSakura);
    stop();
    printf("\n\n");
}

int main()
{
    if(game_init())
        cout<<"init success\n";
    else cout<<"init fail\n";
    //test
    while(1)
        operate_list();
    stop();
    return 0;
}
