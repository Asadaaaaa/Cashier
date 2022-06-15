#include <iostream>

using namespace std;

void configSave();
void themeChanger();

string configGetTitle() {
    if(configs.title == "") return "Set-Up";
    return configs.title;   
}

string configGetTheme() {
    return configs.theme;   
}

void configChangeTitle(string text) {
    configs.title = text;
    configSave();
    return;
}

void configChangeTheme(string text) {
    configs.theme = text;
    configSave();
    themeChanger();
    return;
}

void configSave() {
    // Variables
    ofstream configFile;

    // Algos
    configFile.open("Configs.txt", ios::trunc);
    configFile << configs.title << endl;
    configFile << configs.theme << endl;
    configFile << boolalpha << configs.isFirstTime << endl;
    configFile.close();
}

void configLoad() {
    // Variables
    ifstream configFile;
    string isFirstTime;
    // Algos
    configFile.open("Configs.txt");
    if(configFile.fail()) {
        configSave();
        return;
    }
    getline(configFile, configs.title);
    getline(configFile, configs.theme);
    getline(configFile, isFirstTime);

    if(isFirstTime == "false") {
        configs.isFirstTime = false;
    } else {
        configs.isFirstTime = true;
    }

    configFile.close();
}