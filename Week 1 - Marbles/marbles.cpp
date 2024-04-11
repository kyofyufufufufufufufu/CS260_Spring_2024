#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

int main() {
    //declaring and defining our lists and the max capacity
    list<int> bag = {};
    list<int> hand = {};
    int capacity = 20;

    //generating random marble as an int
    srand(time(nullptr));

    //filling bag with marbles
    while (bag.size() != capacity) {
        int marble = rand() % capacity + 1;
        bool checkDupe = false; //this will check for duplicate marble numbers

        //check for duplicates
        for (int number : bag) {
            if (number == marble) {
                checkDupe = true; //there is a dupe
                break;
            }
        }

        //adding nonduplicate marbles to bag
        if (!checkDupe) {
            bag.push_back(marble);
        }
    }

    //displaying marbles in bag
    cout << "Marbles in bag: ";
    for (int number : bag) {
        cout << number << " ";
    }
    cout << endl;

    //transferring marbles from bag to hand
    while (hand.size() != capacity) {
        int marble = bag.front();
        hand.push_back(marble);   //add marble to the hand
        bag.pop_front();          //remove marble from the bag
    }

    //displaying marbles in hand
    cout << "Marbles in hand: ";
    for (int number : hand) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}
