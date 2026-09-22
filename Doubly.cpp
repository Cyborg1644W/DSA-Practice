#include <iostream>
#include <sstream>

struct Account {
    string name;
    int accountID;
    float balance;
};


struct Node {
    Account data;
    Node *next;
    Node *prev;

    Node(Account info) :Account(info), next(NULL), prev(NULL) {}
};

class Bank {
private:
    Node *head;
    Node *tail; // <-- Added tail pointer
public:
    Bank() {
        head = NULL;
        tail = NULL; // <-- Initialize to NULL
    }

    ~Bank() {
        Node *p;
        while(head != NULL) {
            p = head;
            head = head->next;
            delete(p);
        }
        // Tail is naturally destroyed as the nodes are deleted
    }

    void addAccount(Account info);
    void deleteAccount(string name);
    void displayForward();
    void displayBackward();
};

void Bank::addAccount(Account info) {
    Node *p, *q, *newNode;
    newNode = new Node(info);
    p = q = head;

    while(p != NULL && info.name < p->data.name) {
        q = p;
        p = p->next;
    }

    if (head == p) {
        head = newNode;
    } else {
        q->next = newNode;
        newNode->prev = q;
    }
    newNode->next = p;
    if (p != NULL) {
        p->prev = newNode;
    } else {
        tail = newNode;
    }
}



void Bank::deleteAccount(string name) {    
    Node *p, *q;
    p = q = head;

    while(p != NULL && name != p->data.name) {
        q = p;
        p = p->next;
    }
    if(p == NULL) {
        cout << "Not found\n";
    } else if (p == head) {
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete(p);
    } else {
        q->next = p->next;
        if(p->next != NULL) {
            p->next->prev = q;
        } else {
            tail = q;
        }
        delete(p);
    }
}

