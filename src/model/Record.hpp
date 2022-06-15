#include <iostream>

using namespace std;

struct Configs{
    string title = "";
    string theme = "Dark";
    bool isFirstTime = true;
};

struct UserData {
    int permLevel;
    string password;

    UserData *left, *middle, *right;
};

struct FBList{
    string type;
    string name;
    int stock;
    int price;

    FBList *next;
    FBList *prev;
};

struct BuyList{
    string name;
    string type;
    int amount;
    int totalPrice;
    BuyList *next;
    BuyList *prev;
};

struct ExpendEstimated{
    string type, name;
    int amount, income, time;

    ExpendEstimated *prev, *next;
};

Configs configs;
UserData *allUserData;
FBList * fbList;
BuyList *buyList;
ExpendEstimated *expendEstimated, *expendTail;