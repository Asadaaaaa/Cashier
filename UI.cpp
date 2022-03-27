#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void borderUI() {
    string strBorder = "";
    for(int i = 1; i <= 50; i++) {
		strBorder += 205;
	}
    cout << strBorder << endl;
    return;
}

void notificatorUI(string text, int color, int borderLen, int parentLen) {
	/* Colors:
		(1) = Green
		(2) = Red
	*/
	
	// variables
	char sym1 = 218; // ┌
	char sym2 = 196; // ─
	char sym3 = 191; // ┐
	char sym4 = 179; // │
	char sym5 = 192; // └
	char sym6 = 217; // ┘
	int textLen = text.length();
	int splitTextLen = textLen / 2;
	int splitBorderLen = borderLen / 2;
	int colorReset = 7;
	string confirm = "Press any key to continue...";
	int confirmLen = confirm.length();
	int splitConfirmLen = confirmLen / 2;
	int intPosition = (parentLen - (borderLen + 2)) / 2;
	string strPosition;


	// Check Param
	if(textLen <= 0) { 
		cout << "Error 1";
		return;
	} else if(!(color >= 1 && color <= 2)) {
		cout << "Error 2";
		return;
	} else if(borderLen <= 0) {
		cout << "Error 3";
		return;
	}
	
	if(textLen > borderLen) {
		cout << "Error 3";
		return;
	} else if(borderLen > parentLen) {
		cout << "Error 4";
		return;
	}

	if(color == 1) {
		color = 10;
	} else if(color == 2) {
		color = 12;
	}

	// Algo
    for(int i = 1; i <= intPosition; i++) {
        strPosition += " ";
    }
    cout << strPosition << sym1;
    for(int i = 1; i <= borderLen; i++) {
        cout << sym2;
    }
    cout << sym3 << endl;
    cout << strPosition << sym4;
    for(int i = 1; i <= (splitBorderLen - splitTextLen); i++) {
        cout << " ";
    }
    SetConsoleTextAttribute(h, color);
    cout << text;
    SetConsoleTextAttribute(h, colorReset);
    for(int i = 1; i <= (borderLen - ((splitBorderLen - splitTextLen) + textLen)); i++) {
        cout << " ";
    }
    cout << sym4 << endl;
    cout << strPosition << sym4;
    for(int i = 1; i <= (splitBorderLen - splitConfirmLen); i++) {
        cout << " ";
    }
    cout << confirm;
    for(int i = 1; i <= (borderLen - ((splitBorderLen - splitConfirmLen) + confirmLen)); i++) {
        cout << " ";
    }
    cout << sym4 << endl;
    cout << strPosition << sym5;
    for(int i = 1; i <= borderLen; i++) {
        cout << sym2;
    }
    cout << sym6 << endl;
    getch();
	return;
}