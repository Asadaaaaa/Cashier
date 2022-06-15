#include <iostream>

using namespace std;

int fbGetTotalData();
FBList * fbGetDataByIndex(int i);
FBList * fbGetDataByName(string name);

void buyListAdd(string name, string type, int amount) {
    // Variables
    FBList * curFBData = fbGetDataByName(name);

    if(buyList == NULL) {
        buyList = new BuyList();
        buyList->name = name;
        buyList->type = type;
        buyList->amount = amount;
        buyList->totalPrice = curFBData->price * amount;
        buyList->next = NULL;
        return;
    }
    BuyList *curNode = buyList;
    while(true) {
        if(curNode->next == NULL) {
            break;
        }
        curNode = curNode->next;
    }
    BuyList *newNode = new BuyList();
    
    newNode->name = name;
    newNode->type = type;
    newNode->amount = amount;
    newNode->totalPrice = curFBData->price * amount;
    newNode->next = NULL;

    curNode->next = newNode;
    return;
}

void buyListEditAmount(string name, int amount) {
    // Variable
    BuyList * curNode = buyList;
    FBList * curFBData = fbGetDataByName(name);
    
    while(curNode != NULL) {
        if(curNode->name == name) {
            break;
        }
        curNode = curNode->next;
    }
    curNode->amount = amount;
    curNode->totalPrice = curFBData->price * amount;
}

bool buyListIsExistByName(string name) {
    BuyList *curNode = buyList;

    while(curNode != NULL) {
        if(curNode->name == name) {
            return true;
        }
        curNode = curNode->next;
    }

    return false;
}

void buyListDelete(string name) {
    BuyList *curNode = buyList, *beforeNode, *afterNode;
    
    while(curNode != NULL) {
        if(curNode->name == name) {
            beforeNode = curNode->prev;
            afterNode = curNode->next;
            break;
        }
        curNode = curNode->next;
    }
    
    if(beforeNode != NULL) {
        beforeNode->next = afterNode;
    }
    if(afterNode != NULL) {
        afterNode->prev = beforeNode;
    }
    
    if(curNode->prev == NULL) {
        if(afterNode != NULL) {
            buyList = afterNode;
            buyList->prev == NULL;
        } else if(afterNode == NULL) {
            buyList = NULL;
            delete buyList;
            return;
        }
    }

    curNode = NULL;
    delete curNode;
    return;
}

void buyListReset() {
    BuyList *curNode = buyList;
    
    while(curNode != NULL) {
        curNode = curNode->next;
        buyList = NULL;
        delete buyList;
    }
    return;
}

BuyList * buyListGetDataByName(string name) {
    BuyList * curNode = buyList;

    while(curNode != NULL) {
        if(curNode->name == name) break;
        curNode = curNode->next;
    }
    return curNode;
}

void printReceiptAndLogs(int totalPrice, int customerMoney) {
    ofstream dataBase;
    dataBase.open("logs.db", ios::trunc);
    dataBase << endl << "==================================================" << endl;
    for(int i = 1; i <= fbGetTotalData(); i++) {
        FBList * curData = fbGetDataByIndex(i);
        bool isExist = buyListIsExistByName(curData->name);
        if(isExist == true) {
            BuyList * buyDetails = buyListGetDataByName(curData->name);
            dataBase << " ~ Name: " << curData->name << endl;
            dataBase << "   Unit Price: " << curData->price << endl;
            dataBase << "   Amount: " << buyDetails->amount << endl;
            dataBase << "   Price quantity: " << curData->price * buyDetails->amount << endl; 
        }
    }
    dataBase << endl;
    dataBase << "  Total: " << totalPrice << endl;
    dataBase << "  Change: " << (customerMoney - totalPrice) << endl;
    dataBase << "==================================================" << endl;
    dataBase.close();
    return;
}
