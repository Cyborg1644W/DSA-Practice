#include <iostream>

using namespace std;


struct Account {
    string name;
    int accountID;
    double balance;
}

struct Node {
    Account data;
    node *next;

    Node(account x) : data(x), next(NULL) {};
}Node;


class Bank {
private:
    Node *head;

public:
    Bank() {
        head = NULL;
    }

    ~Bank() {
        Node *p;
        while (p != NULL) {
            p = head;
            head = head->next;
            delete(p);
        }
    }

    addAccount(Account info) {};
    deleteAccount(string name) {};
    save() {};
    Display() {}; 
}

Bank::addAccount(Account info) {
    Node *p, *q, *newNode;
    p = q = head;

    newNode = new Node(info);
    while(p != NULL && p->data.name < info.name) {
        q = p;
        p = p->next;
    }

    if(head == p) {
        head = newNode;
    } else {
        q->next = newNode;
    }
    newNode->next = p;   
}

Bank::deleteAccount(string name) {
    Node *p, *q;
    p = q = head;

    while (p != NULL && name != p->data.name) {
        q = p;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Not found\n";
    } else if (p == head) {
        head = head->next;
    } else {
        q->next = p->next;
    }
    delete(p);
}

Bank::save() {
    
}