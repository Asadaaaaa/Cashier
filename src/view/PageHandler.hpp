#include <iostream>

using namespace std;

void loginPage();

void loginInputPage(int permLevel) {
    // Variable
    string input;
    UserData * userData = userGetData(permLevel);

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: Login" << endl;
    borderUI();
    if(permLevel == 4) {
        cout << " User: Owner";
    } else if(permLevel == 3) {
        cout << " User: Admin";
    } else if(permLevel == 2) {
        cout << " User: Inventory";
    } else if(permLevel == 1) {
        cout << " User: Cashier";
    }
    cout << endl;
    borderUI();
    cout << "Type [#] for back" << endl;
    cout << "> Input password: ";

    // Input
    getline(cin, input);
    if(input == "#") {
        loginPage();
        return;
    } else if(input != userData->password) {
        notificatorUI("Password is wrong", 2, 38, 50);
        loginInputPage(permLevel);
        return;
    } else {
        if(permLevel == 4) {
            cout << "test";
            ownerMainPage();
            return;
        } else if(permLevel == 3) {
            adminMainPage();
            return;
        } else if(permLevel == 2) {
            inventoryMainPage();
            return;
        } else if(permLevel == 1) {
            cashierMainPage();
            return;
        }
    }

    return;
}

void loginPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: Login" << endl;
    borderUI();
    cout << " [1] Owner" << endl;
    if(allUserData->middle != NULL) {
        cout << " [2] Admin" << endl;
        if(allUserData->middle->left != NULL) {
            cout << " [3] Inventory" << endl;
        }
        if(allUserData->middle->right != NULL) {
            cout << " [4] Cashier" << endl;
        }
    }
    cout << " [-] Exit" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        loginInputPage(4);
        return;
    } else if(input == "2" && allUserData->middle != NULL) {
        loginInputPage(3);
        return;
    } else if(input == "3" && allUserData->middle->left != NULL) {
        loginInputPage(2);
        return;
    } else if(input == "4" && allUserData->middle->right != NULL) {
        loginInputPage(1);
        return;
    } else if(input == "-") {
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        loginPage();
        return;
    }

    return;
}

void firstTimeMainPage() {
    // Variable
    string input;
    string title;
    // string ownerName;
    string ownerPassword;
    
    // Step 1 - Title
    while (true)
    {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " Name of your restaurant:" << endl;
        cout << " Password for owner account:" << endl;
        borderUI();
        cout << "Type a name for your restaurant: ";

        // Input
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input.length() > 25) {
            notificatorUI("Maximum name length is 15", 2, 38, 50);
            continue;
        } else {
            title = input;
            break;
        }
    }

    /* // Step 2 - Username
    while (true)
    {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << " Name of your restaurant: " << title << endl;
        cout << " Username for owner:" << endl;
        cout << " user password for owner:" << endl;
        borderUI();
        cout << "Type username for owner: " << endl;

        // Input
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input.length() > 15) {
            notificatorUI("Maximum name length is 15", 2, 38, 50);
            continue;
        } else if (symbolCheck(input)) {
            notificatorUI("Don't use any symbols or number in username", 2, 38, 50);
            continue;
        } else {
            ownerName = input;
            break;
        }
    } */

    // Step 3 - Password
    while (true)
    {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " Name of your restaurant: " << title << endl;
        cout << " Password for owner account:" << endl;
        borderUI();
        cout << "Type passowrd for owner: ";

        // Input
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input.length() > 15) {
            notificatorUI("Maximum password length is 15", 2, 38, 50);
            continue;
        } else if (spaceCheck(input)) {
            notificatorUI("Don't use space in password", 2, 38, 50);
            continue;
        } else {
            ownerPassword = input;
            break;
        }
    }
    
    userAddData(4, ownerPassword);
    configChangeTitle(title);
    configs.isFirstTime = false;
    configSave();

    ownerMainPage();

    return;
}

void pageHandler() {
    if(configs.isFirstTime == true) {
        firstTimeMainPage();
        return;
    }
    loginPage();
    return;
}