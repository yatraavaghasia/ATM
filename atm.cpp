#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <regex>
using namespace std;

class Cash
{
private:
    map<int, int> notes;

public:
    Cash()
    {
        notes[500] = 0;
        notes[200] = 0;
        notes[100] = 0;
        notes[50] = 0;
        notes[20] = 0;
        notes[10] = 0;
        notes[5] = 0;
        notes[2] = 0;
        notes[1] = 0;
    }
    const map<int, int> &getNotes() const
    {
        return notes;
    }
    void setNotes(int denomination, int number_of_notes)
    {
        notes[denomination] = number_of_notes;
        return;
    }
};

class ATM
{
private:
    Cash atm_cash;
    vector<int> denoms;
    void initATM(string fname){
        ifstream inFile;
        inFile.open(fname);
        cout << "Init database file opened!🌮" << endl;
        string line;

        regex regex_pattern("(\\d+):(\\d+)");
        smatch match;
        while (getline(inFile, line))
        {
            if(regex_search(line,match,regex_pattern)){
                int denom_value = stoi(match[1]);
                int denom_notes = stoi(match[2]);
                cout << denom_value << "\t" << denom_notes << endl;
                atm_cash.setNotes(denom_value,denom_notes);
            }
            
        }
        inFile.close();
        cout << "ATM Initialized!" << endl;
    }

    void updateATM(string fname){
        ofstream outFile;
            string line;
            outFile.open(fname);
            cout << "New ATM state being written!" << endl;
            for(int denom: denoms){
                line = to_string(denom)+":"+to_string(atm_cash.getNotes().at(denom));
                outFile << line << endl;
            }
            cout << "ATM State updated!🍬" << endl;
            outFile.close();
    }

public:
    ATM()
    {
        initATM("cash.txt");

        denoms.push_back(500);
        denoms.push_back(200);
        denoms.push_back(100);
        denoms.push_back(50);
        denoms.push_back(20);
        denoms.push_back(10);
        denoms.push_back(5);
        denoms.push_back(2);
        denoms.push_back(1);
    }
    void showNotes()
    {
        std::cout << "Notes available in the ATM to dispense:" << std::endl;
        for (const auto &pair : atm_cash.getNotes())
        {

            std::cout << pair.first << " rupee note(s): " << pair.second << std::endl;
        }
    }
    Cash dispenseNotes(int amount)
    {
        Cash dispensed_notes;
        Cash cached_state = atm_cash;

        const map<int, int> &available_cash = atm_cash.getNotes();

        for (int denomination : denoms)
        {
            int available_notes = available_cash.at(denomination);
            if ((amount >= denomination) && (available_notes > 0))
            {
                int notes_to_dispense = amount / denomination;
                if (notes_to_dispense >= available_notes)
                {
                    notes_to_dispense = available_notes;
                }
                dispensed_notes.setNotes(denomination, notes_to_dispense);

                available_notes -= notes_to_dispense;
                atm_cash.setNotes(denomination, available_notes);

                amount -= notes_to_dispense * denomination;
            }
        }

        if (amount > 0)
        {
            cout << "Insufficient cash available in the ATM!\n"
                 << endl;
            for (int denom : denoms)
            {
                dispensed_notes.setNotes(denom, 0);
            }
            atm_cash = cached_state;
        } else {
            updateATM("cash.txt");
        }

        return dispensed_notes;
    }
    void depositNotes()
    {
        const map<int, int> &available_cash = atm_cash.getNotes();
        for (int denom : denoms)
        {
            int num_notes;
            cout << "Enter the number of notes for the " << denom << " denomination:" << endl;
            cin >> num_notes;
            int available_notes = available_cash.at(denom);
            atm_cash.setNotes(denom, available_notes + num_notes);
        }
        updateATM("cash.txt");
    }
};

int main()
{
    ATM atm;
    // int withdrawalAmount = 1000; // this one will show insufficient balance
    int withdrawalAmount = 148; // this one will result in deducted amount from the ATM

    cout << "Before withdrawal:\n";
    atm.showNotes();

    Cash dispensedNotesObject = atm.dispenseNotes(withdrawalAmount);
    map<int, int> dispensedNotes = dispensedNotesObject.getNotes();

    std::cout << "Notes to dispense:" << std::endl;
    for (const auto &pair : dispensedNotes)
    {
        if (pair.second > 0)
        {
            std::cout << pair.first << " rupee note(s): " << pair.second << std::endl;
        }
    }

    cout << "After withdrawal:" << endl;
    atm.showNotes();

    cout << "Starting deposition!" << endl;
    atm.depositNotes();

    cout << "After deposition:" << endl;
    atm.showNotes();

    return 0;
}