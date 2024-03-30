#include <iostream>

using namespace std;

struct rectangle {
    int length;
    int breadth;
};

struct Card {
    // 52 cards in a deck
    // 4 suits: hearts=H, diamonds=D, clubs=C, spades=S
    // Faces: A=1, 2-10, J=11, Q=12, K=13
    // colors: red=0, black=1
    int cardFaceNum;
    char cardSuit;
    bool cardColor;
};

int main() {
    struct rectangle r = {10, 5};
    // cout << "Area of rectangle is " << r.length * r.breadth << endl;


    struct Card deck[52];
    // Initialize the deck of cards
    for(int i = 0; i < 52; i++) {
        deck[i].cardFaceNum = (i % 13) + 1;
        deck[i].cardSuit = (i % 4 == 0) ? 'H' : (i % 4 == 1) ? 'D' : (i % 4 == 2) ? 'C' : 'S';
        deck[i].cardColor = (deck[i].cardSuit == 'H' || deck[i].cardSuit == 'D') ? 0 : 1;
    }

    // Print the deck of cards
    for(int i = 0; i < 52; i++) {
        cout << "Card " << i+1 << ": " << deck[i].cardFaceNum << deck[i].cardSuit << " ";
        cout << (deck[i].cardColor == 0 ? "red" : "black") << endl;
    }
    
    return 0;
}