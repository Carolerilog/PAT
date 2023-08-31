#include <iostream>
#include <array>

using namespace std;

int main() {
    int k;
    cin >> k;

    array<int, 54> seq;
    for(int i = 0; i < 54; i++) {
        cin >> seq[i];
        seq[i]--;
    }
    
    array<int, 54> cards;
    for(int i = 0; i < 54; i++) {
        cards[i] = i;
    }

    array<int, 54> swap_cards;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < 54; j++) {
            swap_cards[seq[j]] = cards[j];
        }

        swap(cards, swap_cards);
    }

    for(int i = 0; i < 54; i++) {
        int a = cards[i] / 13;
        int b = cards[i] % 13;

        if(i > 0) {
            cout << ' ';
        }

        switch(a) {
            case 0: cout << 'S'; break;
            case 1: cout << 'H'; break;
            case 2: cout << 'C'; break;
            case 3: cout << 'D'; break;
            case 4: cout << 'J'; break;
        }

        cout << b + 1;
    }

    cout << endl;
    return 0;
}