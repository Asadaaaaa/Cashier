#include <iostream>

using namespace std;

void loginPage();

void inventoryMainPage();
void inventoryManageMenuPage();
void inventoryEditMenuPage1();
void inventorySettingMenuPage();

void inventorySettingChangeThemePage() {
    // Variables
    string input;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Settings/Change Theme/" << endl;
    borderUI();
    cout << " [1] Dark Theme" << endl;
    cout << " [2] Light Theme" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        configChangeTheme("Dark");
        inventorySettingChangeThemePage();
        return;
    } else if(input == "2") {
        configChangeTheme("Light");
        inventorySettingChangeThemePage();
        return;
    } else if(input == "-") {
        inventorySettingMenuPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        inventorySettingChangeThemePage();
        return;
    }
    return;
}

void inventorySettingMenuPage() {
    // Variables
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Settings/" << endl;
    borderUI();
    cout << " [1] Change Theme" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        inventorySettingChangeThemePage();
        return;
    } else if(input == "-")  {
        inventoryMainPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        inventorySettingMenuPage();
        return;
    }

    return;
}

void inventoryEditMenuPage2(int index) {
    // Variable
    string input;
    FBList * fbData = fbGetDataByIndex(index);

    //UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Manage Menu/Edit Menu/" << endl;
    borderUI();
    cout << " Name : " << fbData->name << endl;
    cout << " Stock : " << to_string(fbData->stock) << endl;
    cout << " Price: " << to_string(fbData->price) << endl;
    cout << " Type : " << fbData->type << endl;
    borderUI();
    cout << " [1] Edit Name" << endl;
    cout << " [2] Edit Stock" << endl;
    cout << " [3] Edit Price" << endl;
    cout << " [4] Edit Type" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        inventoryEditMenuPage2(index);
        return; 
    } else if(input == "1") {
        while(true) {
            system("cls");
            borderUI();
            cout << " Name : " << fbData->name << endl;
            cout << " Stock : " << to_string(fbData->stock) << endl;
            cout << " Price: " << to_string(fbData->price) << endl;
            cout << " Type : " << fbData->type << endl;
            borderUI();
            cout << "Type [-] for Back" << endl;
            cout << "> Input new name: ";

            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                inventoryEditMenuPage2(index);
                return;
            } else if(fbIsDataExistByName(input) == true) {
                notificatorUI("Name is already exist", 2, 38, 50);
                continue;
            } else {
                fbEdit(index, fbData->type, input, fbData->stock, fbData->price);
                fbSaveToDB();
                inventoryEditMenuPage2(index);
                return;
            }
        }
    } else if(input == "2") {
        while(true) {
            system("cls");
            borderUI();
            cout << " Name : " << fbData->name << endl;
            cout << " Stock : " << to_string(fbData->stock) << endl;
            cout << " Price: " << to_string(fbData->price) << endl;
            cout << " Type : " << fbData->type << endl;
            borderUI();
            cout << "Type [-] for Back" << endl;
            cout << "> Input new Stock: ";

            int tempStock;
            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                inventoryEditMenuPage2(index);
                return;
            }
            try {
                tempStock = stoi(input);
            } catch(exception &err) {
                notificatorUI("Input must be a Number", 2, 38, 50);
                continue;
            }
            fbEdit(index, fbData->type, fbData->name, tempStock, fbData->price);
            fbSaveToDB();
            inventoryEditMenuPage2(index);
            return;
        }
    } else if(input == "3") {
        while(true) {
            system("cls");
            borderUI();
            cout << " Name : " << fbData->name << endl;
            cout << " Stock : " << to_string(fbData->stock) << endl;
            cout << " Price: " << to_string(fbData->price) << endl;
            cout << " Type : " << fbData->type << endl;
            borderUI();
            cout << "Type [-] for Back" << endl;
            cout << "> Input new price: ";

            int tempPrice;
            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                inventoryEditMenuPage2(index);
                return;
            }
            try {
                tempPrice = stoi(input);
            } catch(exception &err) {
                notificatorUI("Input must be a Number", 2, 38, 50);
                continue;
            }
            fbEdit(index, fbData->type, fbData->name, fbData->stock, tempPrice);
            fbSaveToDB();
            inventoryEditMenuPage2(index);
            return;
        }
    } else if(input == "4") {
        while(true) {
            system("cls");
            borderUI();
            cout << " Name : " << fbData->name << endl;
            cout << " Stock : " << to_string(fbData->stock) << endl;
            cout << " Price: " << to_string(fbData->price) << endl;
            cout << " Type : " << fbData->type << endl;
            borderUI();
            cout << " [1] Food" << endl;
            cout << " [2] Beverage" << endl;
            cout << " [-] Back" << endl;
            borderUI();
            cout << "Type [-] for Back" << endl;
            cout << "> Choose menu: ";
    
            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                inventoryEditMenuPage2(index);
                return;
            } else if(input == "1") {
                fbEdit(index, "Food", fbData->name, fbData->stock, fbData->price);
                fbSaveToDB();
                inventoryEditMenuPage2(index);
                return;
            } else if(input == "2") {
                fbEdit(index, "Beverage", fbData->name, fbData->stock, fbData->price);
                fbSaveToDB();
                inventoryEditMenuPage2(index);
                return;
            }
            return;
        }
    } else if(input == "-") {
        inventoryEditMenuPage1();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        inventoryEditMenuPage2(index);
        return;
    }
    return;
}

void inventoryEditMenuPage1() {
    // Variable
    string input;
    int index;
    int totalData;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Manage Menu/Edit Menu/" << endl;
    borderUI();
    if(fbList == NULL) {
        notificatorUI("Menu is Empty", 2, 38, 50);
        inventoryManageMenuPage();
        return;
    }
    totalData = fbGetTotalData();
    for(int i = 1; i <= totalData; i++) {
        FBList * curData = fbGetDataByIndex(i);
        cout << setw(2) << " [" << to_string(i) << "] "  << setw(15) << curData->name;
        cout << setw(11) << to_string(curData->price) << setw(11) << curData->type;
        cout << endl;
    }
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Menu not found", 2, 38, 50);
        inventoryEditMenuPage1();
        return;
    } else if(input == "-") {
        inventoryManageMenuPage();
        return;
    }
    try {
        index = stoi(input);
    } catch(exception &err) {
        notificatorUI("Input must be a Number", 2, 38, 50);
        inventoryEditMenuPage1();
        return;
    }
    bool isExist = fbIsDataExistByIndex(index);
    if(isExist == true) {
        inventoryEditMenuPage2(index);
        return;
    } else if(isExist == false) {
        notificatorUI("Menu not found", 2, 38, 50);
        inventoryEditMenuPage1();
        return;
    }
    
    return;
}

void inventoryDeleteMenuPage() {
    // Variable
    string input;
    int index;
    bool isExist = false;
    int totalData = 0;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Manage Menu/Delete Menu/" << endl;
    borderUI();
    if(fbList == NULL) {
        notificatorUI("Menu is Empty", 2, 38, 50);
        inventoryManageMenuPage();
        return;
    }
    totalData = fbGetTotalData();
    for(int i = 1; i <= totalData; i++) {
        FBList * curData = fbGetDataByIndex(i);
        cout << setw(2) << " [" << to_string(i) << "] "  << setw(15) << curData->name;
        cout << setw(11) << to_string(curData->price) << setw(11) << curData->type;
        cout << endl;
    }
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Menu not found", 2, 38, 50);
        inventoryDeleteMenuPage();
        return;
    } else if(input == "-") {
        inventoryManageMenuPage();
        return;
    }
    try {
        index = stoi(input);
    } catch(exception &err) {
        notificatorUI("Menu not found", 2, 38, 50);
        inventoryDeleteMenuPage();
        return;
    }
    isExist = fbIsDataExistByIndex(index);
    if(isExist == true) {
        fbDelete(index);
        fbSaveToDB();
        notificatorUI("Successfully deleted a menu", 1, 38, 50);
        inventoryDeleteMenuPage();
        return;
    } else if(isExist == false) {
        notificatorUI("Menu not found", 2, 38, 50);
        inventoryDeleteMenuPage();
        return;
    }
    return;
}

void inventoryAddMenuPage() {
    // Variable
    string input;
    string type;
    string name;
    int stock;
    int price;

    // Step 1
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " Page: /Main/Manage Menu/Add Menu/" << endl;
        borderUI();
        cout << " Type:" << endl;
        cout << " Name:" << endl;
        cout << " Stock:" << endl;
        cout << " Price:" << endl;
        borderUI();
        cout << " [1] Food" << endl;
        cout << " [2] Beverage" << endl;
        cout << " [-] Cancel" << endl;
        borderUI();
        cout << "> Choose Type: ";

        // Input Handler
        getline(cin, input);
        if(input == "1") {
            type = "Food";
            break;
        } else if(input == "2") {
            type = "Beverage";
            break;
        } else if(input == "-") {
            inventoryManageMenuPage();
            return;
        } else {
            notificatorUI("Menu not found", 2, 38, 50);
            continue;
        }
    }

    // Step 2
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " Page: /Main/Manage Menu/Add Menu/" << endl;
        borderUI();
        cout << " Type: " << type << endl;
        cout << " Name:" << endl;
        cout << " Stock:" << endl;
        cout << " Price:" << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input " << type << " name: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            inventoryManageMenuPage();
            return;
        } else if(input == "#") {
            inventoryAddMenuPage();
            return;
        } else if(input.length() > 15) {
            notificatorUI("Maximum name length is 15", 2, 38, 50);
            continue;
        } else if(fbIsDataExistByName(input) == true) {
            notificatorUI("Name is already exist", 2, 38, 50);
            continue;
        } else {
            name = toCapitalize(input);
            break;
        }
    }

    // Step 3
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " Page: /Main/Manage Menu/Add Menu/" << endl;
        borderUI();
        cout << " Type: " << type << endl;
        cout << " Name: " << name << endl;
        cout << " Stock: " << endl;
        cout << " Price:" << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input Stock: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            inventoryManageMenuPage();
            return;
        } else if(input == "#") {
            inventoryAddMenuPage();
            return;
        }
        try {
            stock = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(stock < 0) {
            notificatorUI("Number must be >= 0", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    // Step 4
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " Page: /Main/Manage Menu/Add Menu/" << endl;
        borderUI();
        cout << " Type: " << type << endl;
        cout << " Name: " << name << endl;
        cout << " Stock: " << stock << endl;
        cout << " Price:" << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input price: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            inventoryManageMenuPage();
            return;
        } else if(input == "#") {
            inventoryAddMenuPage();
            return;
        }
        try {
            price = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(price < 0) {
            notificatorUI("Number must be >= 0", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    // Step 5
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " Page: /Main/Manage Menu/Add Menu/" << endl;
        borderUI();
        cout << " Type: " << type << endl;
        cout << " Name: " << name << endl;
        cout << " Stock: " << stock << endl;
        cout << " Price: " << price << endl;
        borderUI();
        cout << " [1] Add Now" << endl;
        cout << " [2] Retry" << endl;
        cout << " [-] Cancel" << endl;
        borderUI();
        cout << "> Choose Type: ";

        // Input Handler
        getline(cin, input);
        if(input == "1") {
            fbAdd(type, name, stock, price);
            fbSaveToDB();
            notificatorUI("Successfully added item", 1, 38, 50);
            inventoryManageMenuPage();
            return;
        } else if(input == "2") {
            inventoryAddMenuPage();
            return;
        } else if(input == "-") {
            inventoryManageMenuPage();
            return;
        } else {
            notificatorUI("Menu not found", 2, 38, 50);
            continue;
        }
    }
    return;
}

void inventoryManageMenuPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Manage Menu/" << endl;
    borderUI();
    cout << " [1] Add Menu" << endl;
    cout << " [2] Delete Menu" << endl;
    cout << " [3] Edit Menu" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        inventoryAddMenuPage();
        return;
    } else if(input == "2") {
        inventoryDeleteMenuPage();
        return;
    } else if(input == "3") {
        inventoryEditMenuPage1();
        return;
    } else if(input == "-") {
        inventoryMainPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        inventoryManageMenuPage();
        return;
    }
    return;
}

void inventoryMainPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/" << endl;
    borderUI();
    cout << " [1] Manage Food and Beverage" << endl;
    cout << " [2] Settings" << endl;
    cout << " [-] LogOut" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "-") {
        loginPage();
        return;
    } else if(input == "1") {
        inventoryManageMenuPage();
        return;
    } else if(input == "2") {
        inventorySettingMenuPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        return;
    }
    
    return;
}