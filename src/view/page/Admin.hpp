#include <iostream>

using namespace std;

void loginPage();
void inventoryMainPage();
void cashierMainPage();

void adminMainPage();
void adminListUserPage();
void adminManageUserPage(int permLevel);
void adminSettingMenuPage();
void adminReportDataStartDatePage();

void adminSettingChangeThemePage() {
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
        adminSettingChangeThemePage();
        return;
    } else if(input == "2") {
        configChangeTheme("Light");
        adminSettingChangeThemePage();
        return;
    } else if(input == "-") {
        adminSettingMenuPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        adminSettingChangeThemePage();
        return;
    }
    return;
}

void adminSettingMenuPage() {
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
        adminSettingChangeThemePage();
        return;
    } else if(input == "-")  {
        adminMainPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        adminSettingMenuPage();
        return;
    }

    return;
}

void adminReportResultPage() {
    // Variable
    string input;
    
    reportSaveExpendData();

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Admin" << endl;
    cout << " Page: ../Report Data/Result/" << endl;
    borderUI();
    notificatorUI("Saved in file Report_Expenditures.csv", 1, 38, 50);
    adminMainPage();
    return;
}

void adminReportDataEndDatePage(int startYear, int startMonth, int startDay) {
    // Variable
    string input;
    int year;
    int month;
    int day;
    tm tm;
    time_t date = time(0);
    tm = *localtime(&date);

    // Step 1
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " User: Admin" << endl;
        cout << " Page: ../Report Data/End Date/" << endl;
        borderUI();
        cout << "Estimate: " << endl;
        cout << " - Start Date: " << startYear << ", " << startMonth << ", " << startDay << endl;
        cout << " - End Date Date: " << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input Year: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            adminReportDataStartDatePage();
            return;
        } else if(input == "#") {
            adminReportDataEndDatePage(startYear, startMonth, startDay);
            return;
        }
        try {
            year = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(year < 2022) {
            notificatorUI("Minimum year is 2022", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    // Step 2
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " User: Admin" << endl;
        cout << " Page: ../Report Data/End Date/" << endl;
        borderUI();
        cout << "Estimate: " << endl;
        cout << " - Start Date: " << startYear << ", " << startMonth << ", " << startDay << endl;
        cout << " - End Date Date: " << year << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input Month: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            adminReportDataStartDatePage();
            return;
        } else if(input == "#") {
            adminReportDataEndDatePage(startYear, startMonth, startDay);
            return;
        }
        try {
            month = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(month < 1) {
            notificatorUI("Minimum month is 1", 2, 38, 50);
            continue;
        } else if(month > 12) {
            notificatorUI("Maximum month is 12", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    // Step 3
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " User: Admin" << endl;
        cout << " Page: ../Report Data/End Date/" << endl;
        borderUI();
        cout << "Estimate: " << endl;
        cout << " - Start Date: " << startYear << ", " << startMonth << ", " << startDay << endl;
        cout << " - End Date Date: " << year << ", " << month << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input Day: ";

        // Input Handler
        getline(cin, input);
       if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            adminReportDataStartDatePage();
            return;
        } else if(input == "#") {
            adminReportDataEndDatePage(startYear, startMonth, startDay);
            return;
        }
        try {
            day = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(day < 1) {
            notificatorUI("Minimum day is 1", 2, 38, 50);
            continue;
        } else if(day > 31) {
            notificatorUI("Maximum day is 31", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    tm.tm_year = startYear - 1900;
    tm.tm_mon = startMonth - 1;
    tm.tm_mday = startDay;
    tm.tm_hour = 00;
    tm.tm_min = 00;
    tm.tm_sec = 00;
    time_t startDate = mktime(&tm);

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 23;
    tm.tm_min = 59;
    tm.tm_sec = 59;
    time_t endDate = mktime(&tm);
    
    if(endDate < startDate) {
        notificatorUI("End Date muse be > Start Date", 2, 38, 50);
        adminReportDataEndDatePage(startYear, startMonth, startDay);
        return;
    }

    bool load = reportLoadExpendData(startDate, endDate);
    if(load == false) {
        notificatorUI("Data not exists", 2, 38, 50);
        adminMainPage();
        return;
    }
    
    adminReportResultPage();
    return;
}

void adminReportDataStartDatePage() {
    // Variable
    string input;
    int year;
    int month;
    int day;

    // Step 1
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " User: Admin" << endl;
        cout << " Page: ../Report Data/Start Date/" << endl;
        borderUI();
        cout << "Estimate: " << endl;
        cout << " - Start Date: " << endl;
        cout << " - End Date Date: " << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input Year: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            adminMainPage();
            return;
        } else if(input == "#") {
            adminReportDataStartDatePage();
            return;
        }
        try {
            year = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(year < 2022) {
            notificatorUI("Minimum year is 2022", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    // Step 2
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " User: Admin" << endl;
        cout << " Page: ../Report Data/Start Date/" << endl;
        borderUI();
        cout << "Estimate: " << endl;
        cout << " - Start Date: " << year << endl;
        cout << " - End Date Date: " << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input Month: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            adminMainPage();
            return;
        } else if(input == "#") {
            adminReportDataStartDatePage();
            return;
        }
        try {
            month = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(month < 1) {
            notificatorUI("Minimum month is 1", 2, 38, 50);
            continue;
        } else if(month > 12) {
            notificatorUI("Maximum month is 12", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    // Step 3
    while(true) {
        // UI
        system("cls");
        borderUI();
        titleUI();
        cout << endl << " User: Admin" << endl;
        cout << " Page: ../Report Data/Start Date/" << endl;
        borderUI();
        cout << "Estimate: " << endl;
        cout << " - Start Date: " << year << ", " << month << endl;
        cout << " - End Date Date: " << endl;
        borderUI();
        cout << "Type [-] for Cancel or [#] for Retry" << endl;
        cout << "> Input Day: ";

        // Input Handler
        getline(cin, input);
        if(input == "") {
            notificatorUI("Input can't be empty", 2, 38, 50);
            continue;
        } else if(input == "-") {
            adminMainPage();
            return;
        } else if(input == "#") {
            adminReportDataStartDatePage();
            return;
        }
        try {
            day = stoi(input);
        } catch(exception &err) {
            notificatorUI("Input must be a number", 2, 38, 50);
            continue;
        }
        if(day < 1) {
            notificatorUI("Minimum day is 1", 2, 38, 50);
            continue;
        } else if(day > 31) {
            notificatorUI("Maximum day is 31", 2, 38, 50);
            continue;
        } else {
            break;
        }
    }

    adminReportDataEndDatePage(year, month, day);
    
    return;
}

void adminChangeUserPasswordPage(UserData * userData) {
    // Variable
    string input;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Admin" << endl;
    cout << " Page: ../Manage User/Change Password/" << endl;
    borderUI();
    if(userData->permLevel == 3) {
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
        adminChangeUserPasswordPage(userData);
        return;
    } else if(input.length() > 15) {
        notificatorUI("Maximum password length is 15", 2, 38, 50);
        adminChangeUserPasswordPage(userData);
        return;
    } else if (spaceCheck(input)) {
        notificatorUI("Don't use space in password", 2, 38, 50);
        adminChangeUserPasswordPage(userData);
        return;
    } else if(input == "#") { 
        adminManageUserPage(userData->permLevel);
        return;
    } else {
        userData->password = input;
        userSaveData();
        notificatorUI("Successfully changed password", 1, 38, 50);
        adminManageUserPage(userData->permLevel);
        return;
    }
    return;
}

void adminManageUserPage(int permLevel) {
    // Variable
    string input;
    string user;
    UserData * userData = userGetData(permLevel);

    if(permLevel == 2) {
        user = "Inventory";
    } else if(permLevel == 1) {
        user = "Cashier";
    }

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Admin" << endl;
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
        adminChangeUserPasswordPage(userData);
        return;
    } else if(input == "2") {
        if(permLevel == 2) {
            inventoryMainPage();
            return;
        } else if(permLevel == 1) {
            cashierMainPage();
            return;
        }
        return;
    } else if(input == "-") {
        adminListUserPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        adminManageUserPage(permLevel);
        return;
    }
    
    return;
}

void adminCreateUserPage(int permLevel) {
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
    cout << endl << " User: Admin" << endl;
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
        adminCreateUserPage(permLevel);
        return;
    } else if(input.length() > 15) {
        notificatorUI("Maximum password length is 15", 2, 38, 50);
        adminCreateUserPage(permLevel);
        return;
    } else if (spaceCheck(input)) {
        notificatorUI("Don't use space in password", 2, 38, 50);
        adminCreateUserPage(permLevel);
        return;
    } else if(input == "#") {
        adminListUserPage();
        return;
    } else {
        userAddData(permLevel, input);
        notificatorUI("Successfully created " + user, 1, 38, 50);
        adminListUserPage();
        return;
    }
}

void adminListUserPage() {
    // Variable
    string input;
    
    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Admin" << endl;
    cout << " Page: /Main/List User/" << endl;
    borderUI();
    cout << " [1] Inventory" << endl;
    cout << " [2] Cashier" << endl;
    cout << " [-] Back" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        if(allUserData->middle == NULL) {
            notificatorUI("Admin account must be crated", 2, 38, 50);
            adminListUserPage();
            return;
        } else if(allUserData->middle->left == NULL) {
            adminCreateUserPage(2);
            return;
        }
        adminManageUserPage(2);
        return;
    } else if(input == "2") {
        if(allUserData->middle == NULL) {
            notificatorUI("Admin account must be crated", 2, 38, 50);
            adminListUserPage();
            return;
        } else if(allUserData->middle->left == NULL) {
            notificatorUI("Inventory account must be crated", 2, 38, 50);
            adminListUserPage();
            return;
        }
        if(allUserData->middle->right == NULL) {
            adminCreateUserPage(1);
            return;
        }
        adminManageUserPage(1);
        return;
    } else if(input == "-") {
        adminMainPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        adminListUserPage();
        return;
    }
}

void adminMainPage() {
    // Variable
    string input;

    // UI
    system("cls");
    borderUI();
    titleUI();
    cout << endl << " User: Admin" << endl;
    cout << " Page: /Main/" << endl;
    borderUI();
    cout << " [1] Manage User" << endl;
    cout << " [2] Report Data" << endl;
    cout << " [3] Settings" << endl;
    cout << " [-] LogOut" << endl;
    borderUI();
    cout << "> Choose Menu: ";

    // Input Handler
    getline(cin, input);
    if(input == "1") {
        adminListUserPage();
        return;
    } else if(input == "2") {
        adminReportDataStartDatePage();
        return;
    } else if(input == "3") {
        adminSettingMenuPage();
        return;
    } else if(input == "-") {
        loginPage();
        return;
    } else {
        notificatorUI("Menu not found", 2, 38, 50);
        adminMainPage();
        return;
    }

    return;
}