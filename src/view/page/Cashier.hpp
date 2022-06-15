#include <iostream>

using namespace std;

void loginPage();

void cashierMainPage();
void cashierBuyPage();
void cashierEditMenuPage1();
void cashierPaymentPage();
void cashierManageMenuPage();
void cashierSettingMenuPage();

void cashierPaymentSuccessPage(int totalPrice, int customerMoney) {
    // Variables
    string input;

    reportFBExpendituresData();

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: ../Buy/Payments/Receipt/" << endl;
    borderUI();
    cout << "                 Payment Success" << endl;
    for(int i = 1; i <= fbGetTotalData(); i++) {
        FBList * curFBData = fbGetDataByIndex(i);
        bool isExist = buyListIsExistByName(curFBData->name);
        if(isExist == true) {
            BuyList * buyDetails = buyListGetDataByName(curFBData->name);
            cout << " ~ Name: " << curFBData->name << endl;
            cout << "   Unit Price: " << curFBData->price << endl;
            cout << "   Amount: " << buyDetails->amount << endl;
            cout << "   Price quantity: " << curFBData->price * buyDetails->amount << endl; 
        }
    }
    cout << endl;
    cout << "  Total: " << totalPrice << endl;
    cout << "  Change: " << (customerMoney - totalPrice) << endl;
    borderUI();
    cout << "Type [-] for back to Main Menu ";

    // Input Handler
    getline(cin, input);
    if(input == "-") {
        buyListReset();
        cashierMainPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierPaymentSuccessPage(totalPrice, customerMoney);
        return;
    }
    return;
}

void cashierPaymentPage() {
    // Variables
    string input;
    int customerMoney = 0;
    int totalPrice = 0;
    bool buyListExist = false;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Buy/Payments/" << endl;
    borderUI();
    for(int i = 1; i <= fbGetTotalData(); i++) {
        FBList * curFBData = fbGetDataByIndex(i);
        bool isExist = buyListIsExistByName(curFBData->name);
        if(isExist == true) {
            buyListExist = true;
            BuyList * buyDetails = buyListGetDataByName(curFBData->name);
            totalPrice += curFBData->price * buyDetails->amount;
            cout << " ~ Name: " << curFBData->name << endl;
            cout << "   Unit Price: " << curFBData->price << endl;
            cout << "   Amount: " << buyDetails->amount << endl;
            cout << "   Price quantity: " << curFBData->price * buyDetails->amount << endl << endl; 
        }
    }
    if(buyListExist == false) {
        notificatorUI("Buy List is Empty", 2, 38, 50);
        cashierBuyPage();
        return;
    }
    cout << endl;
    cout << " Total Price: " << totalPrice << endl;
    borderUI();
    cout << "Type [-] for Cancel" << endl;
    cout << "> Input customer money: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        cashierPaymentPage();
        return;
    } else if(input == "-") {
        cashierBuyPage();
        return;
    }
    try {
        customerMoney =  stoi(input);
    } catch(exception &err) {
        notificatorUI("Input must be a Number", 2, 38, 50);
        cashierPaymentPage();
        return;
    }
    if(customerMoney < 1) {
        notificatorUI("Input must be >= 1", 2, 38, 50);
        cashierPaymentPage();
        return;
    } else if(customerMoney < totalPrice) {
        notificatorUI("Customer money must be > Total Price", 2, 38, 50);
        cashierPaymentPage();
        return;
    } else {
        cashierPaymentSuccessPage(totalPrice, customerMoney);
        return;
    }
    return;
}

void cashierBuyEditPage(string name) {
    // Variables
    string input;
    BuyList * curBuyList = buyListGetDataByName(name);
    int amount;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Buy/Edit " + name + "/" << endl;
    borderUI();
    cout << " Name: " << curBuyList->name << endl;
    cout << " Amount: " << curBuyList->amount << endl;
    cout << " Total Price: " << curBuyList->amount << endl;
    borderUI();
    cout << " [1] Amount" << endl;
    cout << " [2] Delete" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "-") {
        cashierBuyPage();
        return;
    } else if(input == "1") {
        while(true) {
            system("cls");
            borderUI();
            titleUI();
            cout << endl << " Page: /Main/Buy/Edit " + name + "/" << endl;
            borderUI();
            cout << " Name: " << curBuyList->name << endl;
            cout << " Amount: " << curBuyList->amount << endl;
            cout << " Total Price: " << curBuyList->amount << endl;
            borderUI();
            cout << "Type [-] for Cancel" << endl;
            cout << "> Input amount: ";

            getline(cin, input);
            if(input == "") {
                notificatorUI("Input can't be empty", 2, 38, 50);
                continue;
            } else if(input == "-") {
                cashierBuyEditPage(name);
                return;
            }
            try {
                amount = stoi(input);
            } catch(exception &err) {
                notificatorUI("Input must be Number", 2, 38, 50);
                continue;
            }
            if(amount < 1) {
                amount = 0;
                notificatorUI("Input must be >= 1", 2, 38, 50);
                continue;
            }
            FBList * curFBData = fbGetDataByName(curBuyList->name);
            if(amount < curBuyList->amount) {
                int diff = curBuyList->amount - amount;
                curFBData->stock += diff;
            } else {
                int diff = amount - curBuyList->amount;
                if(diff > curFBData->stock) {
                    notificatorUI("This " + curFBData->type + " only left " + to_string(curFBData->stock), 2, 38, 50);
                    continue;
                } else {
                    curFBData->stock -= diff;
                }
            }
            
            buyListEditAmount(curBuyList->name, amount);
            notificatorUI("Successfully edited amount", 2, 38, 50);
            cashierBuyEditPage(curBuyList->name);
            return;
        }
    } else if(input == "2") {
        FBList * curFBData = fbGetDataByName(curBuyList->name);
        curFBData->stock += curBuyList->amount;
        buyListDelete(curBuyList->name);
        notificatorUI("Successfully deleted", 1, 38, 50);
        cashierBuyPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierBuyEditPage(name);
        return;
    }
    return;
}

void cashierBuyAddPage(FBList * fbData) {
    // Variables
    string input;
    int amount = 0;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Buy/Add " + fbData->name + "/" << endl;
    borderUI();
    cout << " Name: " << fbData->name << endl;
    cout << " Amount: " << endl;
    borderUI();
    cout << "Type [-] for cancel" << endl;
    
    // Input Handler
    cout <<  "> Input amount: ";
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        cashierBuyAddPage(fbData);
        return;
    } else if(input == "-") {
        cashierBuyPage();
        return;
    }
    try {
        amount = stoi(input);
    } catch(exception &err) {
        notificatorUI("Input must be Number", 2, 38, 50);
        cashierBuyAddPage(fbData);
        return;
    }
    if(amount < 1) {
        amount = 0;
        notificatorUI("Input must be >= 1", 2, 38, 50);
        cashierBuyAddPage(fbData);
        return;
    } else if(amount > fbData->stock) {
        notificatorUI("This " + fbData->type + " only left " + to_string(fbData->stock), 2, 38, 50);
        cashierBuyAddPage(fbData);
        return;
    }

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Buy/Add " + fbData->name + "/" << endl;
    borderUI();
    cout << " Name: " << fbData->name << endl;
    cout << " Amount: " << amount << endl;
    borderUI();
    buyListAdd(fbData->name, fbData->type, amount);
    fbData->stock = fbData->stock - amount;
    notificatorUI("Successfully added " + fbData->name, 1, 38, 50);
    cashierBuyPage();
    return;
}

void cashierBuyPage() {
    // Variable
    string input;
    int index;
    bool isExist = false;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " Page: /Main/Buy/" << endl;
    borderUI();
    if(fbList == NULL) {
        notificatorUI("Menu is Empty", 2, 38, 50);
        cashierMainPage();
        return;
    }
    for(int i = 1; i <= fbGetTotalData(); i++) {
        FBList * curData = fbGetDataByIndex(i);
        cout << setw(2) << " [" << to_string(i) << "] "  << setw(15) << curData->name;
        cout << setw(11) << to_string(curData->price) << setw(5) << curData->stock << setw(11) << curData->type;
        cout << endl;
    }
    cout << endl;
    cout << " [#] Next to Payment Page" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout <<  "> Choose menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "") {
        notificatorUI("Input can't be empty", 2, 38, 50);
        cashierBuyPage();
        return;
    } else if(input == "-") {
        buyListReset();
        cashierMainPage();
        return;
    } else if(input == "#") {
        cashierPaymentPage();
        return;
    }
    try {
        index = stoi(input);
    } catch(exception &err) {
        notificatorUI("Input must be a Number", 2, 38, 50);
        cashierBuyPage();
        return;
    }
    isExist = fbIsDataExistByIndex(index);
    if(isExist == true) {
        FBList * fbData = fbGetDataByIndex(index);
        bool isInBuyList = buyListIsExistByName(fbData->name);
        if(isInBuyList == true) {
            cashierBuyEditPage(fbData->name);
            return;
        } else if(isInBuyList == false) {
            if(fbData->stock == 0) {
                notificatorUI("This " + fbData->type + "is out of stock", 2, 38, 50);
                cashierBuyPage();
                return;
            }
            cashierBuyAddPage(fbData);
            return;
        }
    } else if(isExist == false) {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierBuyPage();
        return;
    }
    return;
}

void cashierSettingChangeThemePage() {
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
        cashierSettingChangeThemePage();
        return;
    } else if(input == "2") {
        configChangeTheme("Light");
        cashierSettingChangeThemePage();
        return;
    } else if(input == "-") {
        cashierSettingMenuPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierSettingChangeThemePage();
        return;
    }
    return;
}

void cashierSettingMenuPage() {
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
        cashierSettingChangeThemePage();
        return;
    } else if(input == "-")  {
        cashierMainPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierSettingMenuPage();
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
    titleUI();
    cout << endl << " Page: /Main/" << endl;
    borderUI();
    cout << " [1] Buy" << endl;
    cout << " [2] Settings" << endl;
    cout << " [-] LogOut" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        cashierBuyPage();
        return;
    } else if(input == "2") {
        cashierSettingMenuPage();
        return;
    } else if(input == "-") {
        loginPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        cashierMainPage();
        return;
    }
    return;
}