// 
// Created by Mahros on 12/31/2022.
// 
#include "../lib/Console.h"
#include "../lib/Animation.h"

void Animation::Text::writing(const string& text, const int& deley, const string& endLine) {
    // the speed unit = char/second
    for (int i = 0; i < text.size(); i++) {
        cout << text[i]; // replace this with print;
        Console::sleep(deley);
    }
    cout << endLine;
}