#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <ctime>

#include "model/Record.hpp"
#include "controller/BuyListDataHandler.hpp"
#include "controller/UserHandler.hpp"
#include "controller/FBDataHandler.hpp"
#include "controller/ConfigHandler.hpp"
#include "controller/ReportDataHandler.hpp"
#include "view/View.hpp"
#include "Algorithms.cpp"
#include "view/page/Owner.hpp"
#include "view/page/Admin.hpp"
#include "view/page/Inventory.hpp"
#include "view/page/Cashier.hpp"
#include "view/PageHandler.hpp"

using namespace std;

int main() {
    configLoad();
    fbLoadDB();
    userLoadData();
    configChangeTheme(configGetTheme());
    pageHandler();
    return 0;
}