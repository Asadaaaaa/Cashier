#include <iostream>

using namespace std;

void userSaveData();

void userCreateData(int permLevel, string password) {
    allUserData = new UserData();
    allUserData->permLevel = permLevel;
    allUserData->password = password;
    
    return;
}

void userAddData(int permLevel, string password) {
    if(allUserData == NULL) {
        userCreateData(permLevel, password);
        userSaveData();
        return;
    }

    UserData *curNode = allUserData;
    if(permLevel == 3) {
        UserData *newNode = new UserData();
        newNode->permLevel = permLevel;
        newNode->password = password;
        curNode->middle = newNode;
    } else if (permLevel == 2) {
        curNode = curNode->middle;
        UserData *newNode = new UserData();
        newNode->permLevel = permLevel;
        newNode->password = password;
        curNode->left = newNode;
    } else if (permLevel == 1) {
        curNode = curNode->middle;
        UserData *newNode = new UserData();
        newNode->permLevel = permLevel;
        newNode->password = password;
        curNode->right = newNode;
    }
    
    userSaveData();
    return;
}

UserData * userGetData(int permLevel) {
    // Variable
    UserData *curNode = allUserData;

    if(permLevel == 4) {
        return curNode;
    } else if(permLevel == 3) {
        curNode = curNode->middle;
        return curNode;
    } else if (permLevel == 2) {
        curNode = curNode->middle;
        curNode = curNode->left;
        return curNode;
    } else if (permLevel == 1) {
        curNode = curNode->middle;
        curNode = curNode->right;
        return curNode;
    }
}

void userSaveData() {
    // Variables
    ofstream userDatabase;

    userDatabase.open("Users.db", ios::trunc);
    if(allUserData == NULL) {
        return;
    }
    userDatabase << "{" << endl;
    userDatabase << "   PermissionLevel: " << allUserData->permLevel << endl;
    userDatabase << "   Password: " << allUserData->password << endl;
    userDatabase << "}" << endl;
    if(allUserData->middle != NULL) {
        userDatabase << "{" << endl;
        userDatabase << "   PermissionLevel: " << allUserData->middle->permLevel << endl;
        userDatabase << "   Password: " << allUserData->middle->password << endl;
        userDatabase << "}" << endl;
        if(allUserData->middle->left != NULL) {
            userDatabase << "{" << endl;
            userDatabase << "   PermissionLevel: " << allUserData->middle->left->permLevel << endl;
            userDatabase << "   Password: " << allUserData->middle->left->password << endl;
            userDatabase << "}" << endl;
        }
        if(allUserData->middle->right != NULL) {
            userDatabase << "{" << endl;
            userDatabase << "   PermissionLevel: " << allUserData->middle->right->permLevel << endl;
            userDatabase << "   Password: " << allUserData->middle->right->password << endl;
            userDatabase << "}" << endl;
        }
    }
    userDatabase.close();
    return;
}

void userLoadData() {
    // Variables
    ifstream userDB;
    string tempData;
    int permLevel;
    string password;
    
    // Algos
    userDB.open("Users.db");
    if(userDB.fail()) {
        userSaveData();
        return;
    }
    while(!userDB.eof()) {
        getline(userDB, tempData);
        if(tempData == "{") {
            getline(userDB, tempData);
            tempData.erase(0, 20);
            permLevel = stoi(tempData);

            getline(userDB, tempData);
            tempData.erase(0, 13);
            password = tempData;

            userAddData(permLevel, password);
        };
    }
    userDB.close();
    return;
}
