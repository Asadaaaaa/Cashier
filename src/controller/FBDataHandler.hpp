#include <iostream>

using namespace std;

void fbCreate(string type, string name, int stock, int price) {
    fbList = new FBList();
    fbList->type = type;
    fbList->name = name;
    fbList->stock = stock;
    fbList->price = price;
    fbList->next = NULL;
    fbList->prev = NULL;
}

void fbAdd(string type, string name, int stock, int price) {
    if(fbList == NULL) {
        fbCreate(type, name, stock, price);
        return;
    }
    FBList *curNode = fbList;
    while(true) {
        if(curNode->next == NULL) {
            break;
        }
        curNode = curNode->next;
    }
    FBList *newNode = new FBList();
    
    newNode->type = type;
    newNode->name = name;
    newNode->stock = stock;
    newNode->price = price;
    newNode->next = NULL;
    newNode->prev = curNode;

    curNode->next = newNode;
    return;
}

void fbDelete(int index) {
    FBList *curNode, *beforeNode, *afterNode;
    curNode = fbList;
    int curNodeIndex = 1;
    
    while(curNode != NULL) {
        if(curNodeIndex == index) {
            beforeNode = curNode->prev;
            afterNode = curNode->next;
            break;
        }
        curNode = curNode->next;
        curNodeIndex++;
    }
    
    if(beforeNode != NULL) {
        beforeNode->next = afterNode;
    }
    if(afterNode != NULL) {
        afterNode->prev = beforeNode;
    }

    if(index == 1) {
        if(afterNode != NULL) {
            fbList = afterNode;
            fbList->prev == NULL;
        } else if(afterNode == NULL) {
            fbList = NULL;
            delete fbList;
            return;
        }
        
    }

    curNode = NULL;
    delete curNode;
    return;
}

void fbEdit(int index, string type, string name, int stock, int price) {
    // Variable
    FBList *curNode = fbList;
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
    curNode->stock = stock;
    curNode->price = price;

    return;
}

FBList * fbGetDataByIndex(int index) {
    FBList *curNode = fbList;
    int curNodeIndex = 1;

    while(curNode != NULL) {
        if(curNodeIndex == index) break;
        curNode = curNode->next;
        curNodeIndex++;
    }
    return curNode;
}

FBList * fbGetDataByName(string name) {
    FBList *curNode = fbList;

    while(curNode != NULL) {
        if(curNode->name == name) break;
        curNode = curNode->next;
    }
    return curNode;
}

bool fbIsDataExistByIndex(int index) {
    FBList *curNode = fbList;
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

bool fbIsDataExistByName(string name) {
    FBList *curNode = fbList;

    while(curNode != NULL) {
        if(curNode->name == name) {
            return true;
        }
        curNode = curNode->next;
    }

    return false;
}

int fbGetTotalData() {
    FBList *curNode = fbList;
    int totalMenu = 0;
    while(curNode != NULL) {
        curNode = curNode->next;
        totalMenu++;
    }
    
    return totalMenu;
}

void fbPrintAllData(int details) {
    FBList *curNode;
    curNode = fbList;
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

void fbSaveToDB() {
    // Variables
    FBList *curNode = fbList;
    ofstream dataBase;

    dataBase.open("FB.db", ios::trunc);
    while(curNode != NULL) {
        dataBase << "{" << endl;
        dataBase << "   Type: " << curNode->type << endl;
        dataBase << "   Name: " << curNode->name << endl;
        dataBase << "   Stock: " << curNode->stock << endl;
        dataBase << "   Price: " << curNode->price << endl;
        dataBase << "}" << endl;
        curNode = curNode->next;
    }
    dataBase.close();
    return;
}

void fbLoadDB() {
    ifstream dataBase;
    string menuType;
    string menuName;
    int stock;
    int menuPrice;
    string tempData;

    dataBase.open("FB.db");
    if(dataBase.fail()) {
        return;
    }
    while(!dataBase.eof()) {
        getline(dataBase, tempData);
        if(tempData == "{") {
            getline(dataBase, tempData);
            tempData.erase(0, 9);
            menuType = tempData;

            getline(dataBase, tempData);
            tempData.erase(0, 9);
            menuName = tempData;

            getline(dataBase, tempData);
            tempData.erase(0, 10);
            stock = stoi(tempData);
            
            getline(dataBase, tempData);
            tempData.erase(0, 10);
            menuPrice = stoi(tempData);

            fbAdd(menuType, menuName, stock, menuPrice);
        };
    }
    dataBase.close();
    return;
}