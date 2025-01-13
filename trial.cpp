#include <iostream>
#include <map>
#include <vector>
using namespace std;

class ATM
{
private:
    std::vector<int> denominations;

public:
    ATM(){
        denominations.push_back(500);
        denominations.push_back(200);
        denominations.push_back(100);
        denominations.push_back(50);
        denominations.push_back(20);
        denominations.push_back(10);
        denominations.push_back(5);
        denominations.push_back(2);
        denominations.push_back(1);
    }
    std::map<int, int> dispenseNotes(int amount)
    {
        std::map<int, int> notes;

        for (int denomination : denominations)
        {
            if (amount >= denomination)
            {
                notes[denomination] = amount / denomination;
                amount %= denomination;
            }
        }

        return notes;
    }
};

int main()
{
    ATM atm;
    int withdrawalAmount = 148;

    std::map<int, int> dispensedNotes = atm.dispenseNotes(withdrawalAmount);

    std::cout << "Notes to dispense:" << std::endl;
    for (const auto &pair : dispensedNotes)
    {
        if (pair.second > 0)
        {
            std::cout << pair.first << " rupee note(s): " << pair.second << std::endl;
        }
    }

    return 0;
}