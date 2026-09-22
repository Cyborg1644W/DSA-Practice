#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

#define MAX 10
#define FILE_PATH "Account.csv"

struct Account{
    string name;
    int accountID;
    float balance;
};

class Bank {
private:
    Account pd[MAX];
    int last = -1;
    void sortList() {

    }
public:
    void add(Account user);
    void deleteAcc(string name);
    void retrieve();
    void save();
}

void Bank::add(Account user) {
    if (last == MAX - 1) {
        cout << "Already full\n";
    } else {
        last++;
        pd[last] = user;
    }
}

void Bank::deleteAcc(string name) {
    if(last == -1) {
        cout << "the list is empty\n"
    } else {
        int index;
        for(int i = 0; i <= last; i++) {
            if(name == pd[i].name) {
                index = i;
            }
        }
        if (index < 0) {
            cout << "Name not found\n";
        } else {
            for(i = index; i <= last; i++) {
                pd[i] = pd[i+1];
            }
            last--;
        }
    }
}

void Bank::save() {
    ofstreama File(FILE_PATH);
    
    if(!File.is_open()) {
        cout << "Error saving the data\n";
        return;
    }

    for (int i = 0; i < last; i++) {
        File << pd[i].name << ',' << pd[i].accountID << ',' << pd[i].balance << endl;
    }
    File.close();
}

void Bank::retrieve() {
    ifstream File(FILE_PATH);

    if(!File.is_open()) {
        cout << "cannot retrieve data\n";
        return;
    }

    string line; 
    string n;
    Account fd;

    while(getline(File, line)) {
        if(line.empty()) {
            continue;
        }
    stringstream ss(line);
    getline(ss, fd.name, ',');
    getline(ss, n, ',');
    fd.accountID = stoi(n);
    getline(ss, n, ',');
    fd.balance = stof(n);

    add(fd);
    
    }
}