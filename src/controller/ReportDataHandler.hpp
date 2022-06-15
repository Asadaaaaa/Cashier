#include <iostream>

using namespace std;

void reportCreateExpendData(string type, string name, int amount, int income, int time) {
    expendEstimated = new ExpendEstimated();
    expendEstimated->type = type;
    expendEstimated->name = name;
    expendEstimated->amount = amount;
    expendEstimated->income = income;
    expendEstimated->time = time;
    expendEstimated->next = NULL;
    expendEstimated->prev = NULL;
}

void reportAddExpendData(string type, string name, int amount, int income, int time) {
    if(expendEstimated == NULL) {
        reportCreateExpendData(type, name, amount, income, time);
        return;
    }

    ExpendEstimated *newNode = new ExpendEstimated();
    newNode->type = type;
    newNode->name = name;
    newNode->amount = amount;
    newNode->income = income;
    newNode->time = time;
    newNode->next = expendEstimated;
    newNode->prev = NULL;

    expendEstimated->prev = newNode;
    expendEstimated = newNode;
    return;
}

bool reportLoadExpendData(time_t startDate, time_t endDate) {
    ifstream dataBase;
    string type;
    string name;
    int amount;
    int income;
    int time;
    string tempData;
    bool isDataExist = false;

    dataBase.open("Expenditures.db");
    if(dataBase.fail()) {
        return isDataExist;
    }
    while(!dataBase.eof()) {
        getline(dataBase, tempData);
        if(tempData == "{") {
            getline(dataBase, tempData);
            tempData.erase(0, 9);
            type = tempData;

            getline(dataBase, tempData);
            tempData.erase(0, 9);
            name = tempData;

            getline(dataBase, tempData);
            tempData.erase(0, 11);
            amount = stoi(tempData);
            
            getline(dataBase, tempData);
            tempData.erase(0, 11);
            income = stoi(tempData);

            getline(dataBase, tempData);
            tempData.erase(0, 9);
            time = stoi(tempData);

            if(time >= startDate && time <= endDate) {
                reportAddExpendData(type, name, amount, income, time);
                isDataExist = true;
            }
        };
    }
    dataBase.close();

    if(isDataExist == false) {
        return isDataExist;
    }

    expendTail = new ExpendEstimated();
    while(true) {
        if(expendTail->next == NULL) break;
        expendTail = expendTail->next;
    }

    return isDataExist;
}

void reportSaveExpendData() {
    // Variable
    int totalIncome = 0;
    ofstream csv;
    ExpendEstimated *curNode = expendEstimated;
    
    csv.open("Report_Expenditures.csv", ios::trunc);
    csv << "Date,,,Type,Name,Amount,Income" << endl;
    while(curNode != NULL) {
        time_t tempTime = curNode->time;
        char * tempDate = ctime(&tempTime);
        tempDate[24] = '\0';
        csv << tempDate << ",,," << curNode->type << "," << curNode->name << "," << curNode->amount << "," << curNode->income << endl;
        totalIncome += curNode->income;

        ExpendEstimated *beforeNode = curNode;

        curNode = curNode->next;
        beforeNode = NULL;
        delete beforeNode;
    }
    expendEstimated = NULL;
    delete expendEstimated;
    csv << "," << endl;
    csv << "Total Income,,,,,,"<< totalIncome << endl;
    csv.close();
}

// food and beverage expenditure data
void reportFBExpendituresData() {
    // Variables
    ofstream dataBase;
    time_t timeNow = time(0);
    BuyList * curNode = buyList;

    dataBase.open("Expenditures.db", ios::app);
    while(curNode != NULL) {
        dataBase << "{" << endl;
        dataBase << "   Type: " << curNode->type << endl;
        dataBase << "   Name: " << curNode->name << endl;
        dataBase << "   Amount: " << curNode->amount << endl;
        dataBase << "   Income: " << curNode->totalPrice << endl;
        dataBase << "   Time: " << timeNow << endl;
        dataBase << "}" << endl;
        curNode = curNode->next;
    }
    dataBase.close();
    return;
}