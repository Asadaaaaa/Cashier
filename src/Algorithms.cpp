#include <iostream>

using namespace std;

string toCapitalize(string text) {
	for (int i = 0; i < text.length(); i++)
	{
		if (i == 0)
		{
			text[i] = toupper(text[i]);
		}
		else if (text[i - 1] == ' ')
		{
			text[i] = toupper(text[i]);
		}
	}
    return text;
}

void themeChanger() {
    if(configs.theme == "Dark") {
        system("color 07");
    } else if(configs.theme == "Light") {
        system("color 70");
    }
    return;
}

bool symbolCheck(string text) {
    int userLen = text.length();
    int id;
    for(int i = 0; i < userLen; i++) {
        id = int(text[i]);
        if(id < 65) {
            return true;
        }
        if(id > 90 && id < 97) {
            return true;
        }
        if(id > 122) {
            return true;
        }
    }
    return false;
}

bool spaceCheck(string text) {
	for(int i = 0; i < text.length(); i++) {
		if(text[i] == ' ') {
			return true;
		}
	}

	return false;
}