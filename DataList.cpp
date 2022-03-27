#include <iostream>

using namespace std;

struct MenuDataList{
    string type;
    string name;
    int price;

    MenuDataList *next;
    MenuDataList *prev;
};

struct BuyList{
    string name;
    string notes[10];

    BuyList *next;
};

BuyList *buyList;
MenuDataList *menuDataList;