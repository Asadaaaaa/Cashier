#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "DataList.cpp"

using namespace std;

void createMenu(string type, string name, int price) {
    menuDataList = new MenuDataList();
    menuDataList->type = type;
    menuDataList->name = name;
    menuDataList->price = price;
    menuDataList->next = NULL;
    menuDataList->prev = NULL;
}

bool isMenuExist(int index) {
    MenuDataList *curNode = menuDataList;
    int curNodeIndex = 1;

    while(curNode != NULL) {
        if(curNodeIndex == index) {
            return true;
        }
        curNodeIndex++;
        curNode = curNode->next;
    }

    return false;
}

void pushMenu(string type, string name, int price) {
    if(menuDataList == NULL) {
        createMenu(type, name, price);
        return;
    }
    MenuDataList *curNode = menuDataList;
    while(true) {
        if(curNode->next == NULL) {
            break;
        }
        curNode = curNode->next;
    }
    MenuDataList *newNode = new MenuDataList();
    
    newNode->type = type;
    newNode->name = name;
    newNode->price = price;
    newNode->next = NULL;
    newNode->prev = curNode;

    curNode->next = newNode;
    return;
}

void editMenu(int index, string type, string name, int price) {
    // Variable
    MenuDataList *curNode = menuDataList;
    int curNodeIndex = 1;
    
    while(curNode != NULL) {
        if(curNodeIndex == index) {
            break;
        }
        curNode = curNode->next;
        curNodeIndex++;
    }
    curNode->type = type;
    curNode->name = name;
    curNode->price = price;
}

bool deleteMenu(int index) {
    MenuDataList *curNode, *beforeNode, *afterNode;
    curNode = menuDataList;
    int curNodeIndex = 1;
    bool isFound = false;
    
    while(curNode != NULL) {
        if(curNodeIndex == index) {
            beforeNode = curNode->prev;
            afterNode = curNode->next;
            isFound = true;
            break;
        }
        curNode = curNode->next;
        curNodeIndex++;
    }
    
    if(isFound == true) {
        if(beforeNode != NULL) {
            beforeNode->next = afterNode;
        }
        if(afterNode != NULL) {
            afterNode->prev = beforeNode;
        }
        if(index == 1) {
            menuDataList = afterNode;
        }
        curNode = NULL;
        delete curNode;
        return true;
    } else if(isFound == false) {
        return false;
    }
    return false;
}

string *getMenu(int index) {
    MenuDataList *curNode = menuDataList;
    int curNodeIndex = 1;
    bool isFound = false;
    string * menu = new string[3];

    while(curNode != NULL) {
        if(curNodeIndex == index) break;
        curNode = curNode->next;
        curNodeIndex++;
    }

    menu[0] = curNode->type;
    menu[1] = curNode->name;
    menu[2] = to_string(curNode->price);
    return menu;
}

void printAll(int details) {
    MenuDataList *curNode;
    curNode = menuDataList;
    int curNodeIndex = 1;
    string result = "";
    while(curNode != NULL) {
        cout << setw(2) << " [" << to_string(curNodeIndex) << "] "  << setw(15) << curNode->name;
        if(details == 1) {
            cout << setw(11) << to_string(curNode->price);
        } else if(details == 2) {
            cout << setw(11) << to_string(curNode->price) << setw(11) << curNode->type;
        }
        cout << endl;
        result += "\n";
        curNode = curNode->next;
        curNodeIndex++;
    }
    return;
}

void saveDatabase() {
    // Variables
    MenuDataList *curNode = menuDataList;
    ofstream dataBase;

    dataBase.open("DataBase.txt", ios::trunc);
    while(curNode != NULL) {
        dataBase << "{" << endl;
        dataBase << "   Type: " << curNode->type << endl;
        dataBase << "   Name: " << curNode->name << endl;
        dataBase << "   Price: " << curNode->price << endl;
        dataBase << "}" << endl;
        curNode = curNode->next;
    }
    return;
}

void loadDatabase() {
    ifstream dataBase;
    string menuType;
    string menuName;
    int menuPrice;
    string tempData;

    dataBase.open("DataBase.txt");
    if(dataBase.fail()) {
        return;
    }
    while(!dataBase.eof()) {
        getline(dataBase, tempData);
        if(tempData == "{") {
            getline(dataBase, tempData);
            tempData.erase(tempData.begin() + 0, tempData.begin() + 9);
            menuType = tempData;

            getline(dataBase, tempData);
            tempData.erase(tempData.begin() + 0, tempData.begin() + 9);
            menuName = tempData;

            getline(dataBase, tempData);
            tempData.erase(tempData.begin() + 0, tempData.begin() + 10);
            menuPrice = stoi(tempData);

            pushMenu(menuType, menuName, menuPrice);
        };
    }
    return;
}

void pushBuyList(string name, string notes[], int index =  10) {
    // Variables
    if(buyList == NULL) {
        buyList = new BuyList();
        buyList->name = name;
        for(int i = 0; i < index; i++) {
            buyList->notes[i] = notes[i];
        }
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
    for(int i = 0; i < index; i++) {
        buyList->notes[i] = notes[i];
    }
    newNode->next = NULL;

    curNode->next = newNode;
    return;
}