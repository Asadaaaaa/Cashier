#include <iostream>
#include <conio.h>
#include "UI.cpp"
#include "DataManager.cpp"

using namespace std;

void userIdentifierPage();
void cashierMainPage();
void cashierManageMenuPage();
void cashierEditMenuPage1();

void cashierBuyPage2(int index) {
    // Variable
    string input;
    string *menu = getMenu(index);

    // UI
    system("cls");
    borderUI();
    cout << " Name: " << menu[1] << endl;
    borderUI();
    cout << " [1] Ammount" << endl;
    cout << " [2] Ammount" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout <<  "> Choose menu: ";

    return;
}

void cashierBuyPage1() {
    // Variable
    string input;
    int index;
    bool isExist = false;

    // UI
    system("cls");
    borderUI();
    printAll(1);
    cout << " [-] Back" << endl;
    borderUI();
    cout <<  "> Choose menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        cashierBuyPage1();
        return;
    } else if(input == "-") {
        cashierMainPage();
        return;
    }
    try {
        index = stoi(input);
    } catch(exception &err) {
        notificatorUI("Input must be a Number", 2, 38, 50);
        cashierBuyPage1();
        return;
    }
    isExist = isMenuExist(index);

    if(isExist == true) {

        
    } else if(isExist == false) {

        
    }
    return;
}

void cashierEditMenuPage2(int index) {
    // Variable
    string input;
    string *menu = getMenu(index);

    //UI
    system("cls");
    cout << " Name : " << menu[1] << endl;
    cout << " Price: " << menu[2] << endl;
    cout << " Type : " << menu[0] << endl;
    borderUI();
    cout << " [1] Edit Name" << endl;
    cout << " [2] Edit Price" << endl;
    cout << " [3] Edit Type" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        cashierEditMenuPage2(index);
        return; 
    } else if(input == "1") {
        while(true) {
            system("cls");
            borderUI();
            cout << " Name : " << menu[1] << endl;
            cout << " Price: " << menu[2] << endl;
            cout << " Type : " << menu[0] << endl;
            borderUI();
            cout << "Type [-] for Back";
            cout << "> Input new name: ";

            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                cashierEditMenuPage2(index);
                return;
            }else {
                editMenu(index, menu[0], input, stoi(menu[2]));
                cashierEditMenuPage2(index);
                return;
            }
        }
    } else if(input == "2") {
        while(true) {
            system("cls");
            borderUI();
            cout << " Name : " << menu[1] << endl;
            cout << " Price: " << menu[2] << endl;
            cout << " Type : " << menu[0] << endl;
            borderUI();
            cout << "Type [-] for Back";
            cout << "> Input new price: ";

            int tempPrice;
            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                cashierEditMenuPage2(index);
                return;
            }
            try {
                tempPrice = stoi(input);
            } catch(exception &err) {
                notificatorUI("Input must be a Number", 2, 38, 50);
                continue;
            }
            editMenu(index, menu[0], menu[1], tempPrice);
            cashierEditMenuPage2(index);
            return;
        }
    } else if(input == "3") {
        while(true) {
            system("cls");
            borderUI();
            cout << " Name : " << menu[1] << endl;
            cout << " Price: " << menu[2] << endl;
            cout << " Type : " << menu[0] << endl;
            borderUI();
            cout << " [1] Food" << endl;
            cout << " [2] Drink" << endl;
            cout << " [-] Back" << endl;
            borderUI();
            cout << "Type [-] for Back";
            cout << "> Choose menu: ";
    
            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                cashierEditMenuPage2(index);
                return;
            } else if(input == "1") {
                editMenu(index, "food", menu[1], stoi(menu[2]));
                cashierEditMenuPage2(index);
                return;
            } else if(input == "2") {
                editMenu(index, "drink", menu[1], stoi(menu[2]));
                cashierEditMenuPage2(index);
                return;
            }
            return;
        }
    } else if(input == "-") {
        cashierEditMenuPage1();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierEditMenuPage2(index);
        return;
    }
    return;
}

void cashierEditMenuPage1() {
    // Variable
    string input;
    int index;
    
    // UI
    system("cls");
    borderUI();
    printAll(2);
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierEditMenuPage1();
        return;
    } else if(input == "-") {
        cashierManageMenuPage();
        return;
    }
    try {
        index = stoi(input);
    } catch(exception &err) {
        notificatorUI("Input must be a Number", 2, 38, 50);
        cashierEditMenuPage1();
        return;
    }
    bool isExist = isMenuExist(index);
    if(isExist == true) {
        cashierEditMenuPage2(index);
        return;
    } else if(isExist == false) {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierEditMenuPage1();
        return;
    }
    cout << "Test3" << endl;
    return;
}

void cashierDeleteMenuPage() {
    // Variable
    string input;
    int index;

    // UI
    system("cls");
    borderUI();
    printAll(2);
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierDeleteMenuPage();
        return;
    } else if(input == "-") {
        cashierManageMenuPage();
        return;
    }
    try {
        index = stoi(input);
    } catch(exception &err) {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierDeleteMenuPage();
        return;
    }
    if(index < 1) {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierDeleteMenuPage();
        return;
    } else {
        bool isDeleted = deleteMenu(index);
        if(isDeleted == true) {
            notificatorUI("Successfully deleted a menu", 1, 38, 50);
            cashierDeleteMenuPage();
            return;
        } else if(isDeleted == false) {
            notificatorUI("Menu not found", 1, 38, 50);
            cashierDeleteMenuPage();
            return;
        }
    }
    return;
}

void cashierAddMenuPage() {
    // Variable
    string input;
    string type;
    string name;
    int price;

    // Step 1
    while(true) {
        // UI
        system("cls");
        borderUI();
        cout << " Type:" << endl;
        cout << " Name:" << endl;
        cout << " Price:" << endl;
        borderUI();
        cout << " [1] Food" << endl;
        cout << " [2] Drink" << endl;
        cout << " [-] Cancel" << endl;
        borderUI();
        cout << "> Choose Type: ";

        // Input Handler
        getline(cin, input);
        if(input == "1") {
            type = "food";
            break;
        } else if(input == "2") {
            type = "drink";
            break;
        } else if(input == "-") {
            cashierManageMenuPage();
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
        cout << " Type: " << type << endl;
        cout << " Name:" << endl;
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
            cashierManageMenuPage();
            return;
        } else if(input == "#") {
            cashierAddMenuPage();
            return;
        } else {
            name = input;
            break;
        }
    }

    // Step 3
    while(true) {
        // UI
        system("cls");
        borderUI();
        cout << " Type: " << type << endl;
        cout << " Name: " << name << endl;
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
            cashierManageMenuPage();
            return;
        } else if(input == "#") {
            cashierAddMenuPage();
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

    // Step 4
    while(true) {
        // UI
        system("cls");
        borderUI();
        cout << " Type: " << type << endl;
        cout << " Name: " << name << endl;
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
            pushMenu(type, name, price);
            cashierManageMenuPage();
            return;
        } else if(input == "2") {
            cashierAddMenuPage();
            return;
        } else if(input == "-") {
            cashierManageMenuPage();
            return;
        } else {
            notificatorUI("Menu not found", 2, 38, 50);
            continue;
        }
    }
    return;
}

void cashierManageMenuPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    cout << " [1] Add Menu" << endl;
    cout << " [2] Delete Menu" << endl;
    cout << " [3] Edit Menu" << endl;
    cout << " [4] Save Menu to DataBase" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        cashierAddMenuPage();
        return;
    } else if(input == "2") {
        cashierDeleteMenuPage();
        return;
    } else if(input == "3") {
        cashierEditMenuPage1();
        return;
    } else if(input == "4") {
        saveDatabase();
        notificatorUI("Successfully Save all Data", 1, 38, 50);
        cashierManageMenuPage();
        return;
    } else if(input == "-") {
        cashierMainPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        userIdentifierPage();
        return;
    }
    return;
}

void cashierMainPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    cout << " [1] Buy" << endl;
    cout << " [2] Manage Menu" << endl;
    cout << " [-] Logout" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        // TODO
        return;
    } else if(input == "2") {
        cashierManageMenuPage();
        return;
    } else if(input == "-") {
        userIdentifierPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        userIdentifierPage();
        return;
    }
    return;
}

void userIdentifierPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    cout << " [1] Cashier" << endl;
    cout << " [2] Customer" << endl;
    cout << " [-] Exit" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        cashierMainPage();
        return;
    } else if(input == "2") {
        // TODO
        return;
    } else if(input == "-") {
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        userIdentifierPage();
        return;
    }
    return;
}

int main() {
    loadDatabase();
    userIdentifierPage();
    return 0;
}