#include <iostream>

using namespace std;

void loginPage();
void adminMainPage();
void inventoryMainPage();
void cashierMainPage();

void ownerMainPage();
void ownerListUserPage();
void ownerManageUserPage(int permLevel);
void ownerManageRestaurant();

void ownerRenameTitle() {
    // Variable
    string input;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Owner" << endl;
    cout << " Page: ../Manage Restaurant/Rename Restaurant/" << endl;
    borderUI();
    cout << " Restaurant Name: " << configGetTitle()  << endl;
    borderUI();
    cout << "Type [#] for cancel" << endl;
    cout << "> Change Title: ";

    // Input
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        ownerRenameTitle();
        return;
    } else if(input == "#") {
        ownerManageRestaurant();
        return;
    } else if(input.length() > 25) {
        notificatorUI("Maximum name length is 15", 2, 38, 50);
        ownerRenameTitle();
        return;
    } else {
        configChangeTitle(input);
        notificatorUI("Successfully changed title", 1, 38, 50);
        ownerManageRestaurant();
        return;
    }
}

void ownerManageRestaurant() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Owner" << endl;
    cout << " Page: /Main/Manage Restaurant/" << endl;
    borderUI();
    cout << " [1] Change Restaurant Name" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        ownerRenameTitle();
        return;
    } else if(input == "-") {
        ownerMainPage();
        return;
    } else {
        notificatorUI("Menu not found!", 2, 38, 50);
        ownerManageRestaurant(); 
    }
    return;
}

void ownerChangeUserPasswordPage(UserData * userData) {
    // Variable
    string input;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Owner" << endl;
    cout << " Page: ../Manage User/Change Password/" << endl;
    borderUI();
    if(userData->permLevel == 4) {
        cout << " User: Owner";
    } else if(userData->permLevel == 3) {
        cout << " User: Admin";
    } else if(userData->permLevel == 2) {
        cout << " User: Inventory";
    } else if(userData->permLevel == 1) {
        cout << " User: Cashier";
    }
    cout << endl;
    cout << " Password: " << userData->password << endl;
    borderUI();
    cout << "Type [#] for cancel" << endl;
    cout << "> Change Password: ";

    // Input
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        ownerChangeUserPasswordPage(userData);
        return;
    } else if(input.length() > 15) {
        notificatorUI("Maximum password length is 15", 2, 38, 50);
        ownerChangeUserPasswordPage(userData);
        return;
    } else if (spaceCheck(input)) {
        notificatorUI("Don't use space in password", 2, 38, 50);
        ownerChangeUserPasswordPage(userData);
        return;
    } else if(input == "#") { 
        ownerManageUserPage(userData->permLevel);
        return;
    } else {
        userData->password = input;
        userSaveData();
        notificatorUI("Successfully changed password", 1, 38, 50);
        ownerManageUserPage(userData->permLevel);
        return;
    }
    return;
}

void ownerManageUserPage(int permLevel) {
    // Variable
    string input;
    string user;
    UserData * userData = userGetData(permLevel);

    if(permLevel == 4) {
        user = "Owner";
    } else if(permLevel == 3) {
        user = "Admin";
    } else if(permLevel == 2) {
        user = "Inventory";
    } else if(permLevel == 1) {
        user = "Cashier";
    }

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Owner" << endl;
    cout << " Page: ../List User/Manage User/" << endl;
    borderUI();
    cout << " User: " << user << endl;
    cout << " Password: " << userData->password << endl;
    borderUI();
    cout << " [1] Change Password" << endl;
    cout << " [2] Login as " << user << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";
    
    // Input
    getline(cin, input);
    if(input == "1") {
        ownerChangeUserPasswordPage(userData);
        return;
    } else if(input == "2") {
        if(permLevel == 4) {
            ownerMainPage();
        } else if(permLevel == 3) {
            adminMainPage();
        } else if(permLevel == 2) {
            inventoryMainPage();
            return;
        } else if(permLevel == 1) {
            cashierMainPage();
            return;
        }
        return;
    } else if(input == "-") {
        ownerListUserPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        ownerManageUserPage(permLevel);
        return;
    }
    
    return;
}

void ownerCreateUserPage(int permLevel) {
    // Variable
    string input;
    string user;

    if(permLevel == 3) {
        user = "Admin";
    } else if(permLevel == 2) {
        user = "Inventory";
    } else if(permLevel == 1) {
        user = "Cashier";
    }

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Owner" << endl;
    cout << " Page: ../Manage User/Create Account/" << endl;
    borderUI();
    cout << " Create Account for: " << user << endl;
    cout << " Password: " << endl;
    borderUI();
    cout << "Type [#] for cancel" << endl;
    cout << "> Type Password: ";

    // Input
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        ownerCreateUserPage(permLevel);
        return;
    } else if(input.length() > 15) {
        notificatorUI("Maximum password length is 15", 2, 38, 50);
        ownerCreateUserPage(permLevel);
        return;
    } else if (spaceCheck(input)) {
        notificatorUI("Don't use space in password", 2, 38, 50);
        ownerCreateUserPage(permLevel);
        return;
    } else if(input == "#") {
        ownerListUserPage();
        return;
    } else {
        userAddData(permLevel, input);
        notificatorUI("Successfully created " + user, 1, 38, 50);
        ownerListUserPage();
        return;
    }
}

void ownerListUserPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Owner" << endl;
    cout << " Page: /Main/List User/" << endl;
    borderUI();
    cout << " [1] Owner" << endl;
    cout << " [2] Admin" << endl;
    cout << " [3] Inventory" << endl;
    cout << " [4] Cashier" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        ownerManageUserPage(4);
        return;
    } else if(input == "2") {
        if(allUserData->middle == NULL) {
            ownerCreateUserPage(3);
            return;
        }
        ownerManageUserPage(3);
        return;
    } else if(input == "3") {
        if(allUserData->middle == NULL) {
            notificatorUI("Admin account must be crated", 2, 38, 50);
            ownerListUserPage();
            return;
        } else if(allUserData->middle->left == NULL) {
            ownerCreateUserPage(2);
            return;
        }
        ownerManageUserPage(2);
        return;
    } else if(input == "4") {
        if(allUserData->middle == NULL) {
            notificatorUI("Admin account must be crated", 2, 38, 50);
            ownerListUserPage();
            return;
        } else if(allUserData->middle->left == NULL) {
            notificatorUI("Inventory account must be crated", 2, 38, 50);
            ownerListUserPage();
            return;
        }
        if(allUserData->middle->right == NULL) {
            ownerCreateUserPage(1);
            return;
        }
        ownerManageUserPage(1);
        return;
    } else if(input == "-") {
        ownerMainPage();
        return;
    } else {
        notificatorUI("Menu not found!", 2, 38, 50);
        ownerListUserPage();
        return;
    }
}

void ownerMainPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Owner" << endl;
    cout << " Page: /Main/" << endl;
    borderUI();
    cout << " [1] Manage User" << endl;
    cout << " [2] Manage Restaurant" << endl;
    cout << " [-] LogOut" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        ownerListUserPage();
        return;
    } else if(input == "2") {
        ownerManageRestaurant();
        return;
    } else if(input == "-") {
        loginPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        ownerMainPage();
        return;
    }
    return;
}