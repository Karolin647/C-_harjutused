#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    string nimi;
    Node<T>* jargmine;

    Node(const string& n) : nimi(n), jargmine(nullptr) {}
    string getElement() { return nimi; }
    Node<T>* getJargmine() { return jargmine; }
};

template <typename T>
class LinkedList {
private:
    Node<T>* pea;
    int suurus;

public:
    LinkedList() : pea(nullptr), suurus(0) {}
    ~LinkedList() { destroy(); }

    void addElement(const string& nimi) {
        Node<T>* uus = new Node<T>(nimi);
        uus->jargmine = pea;
        pea = uus;
        suurus++;
    }

    Node<T>* searchElement(const string& nimi) {
        Node<T>* current = pea;
        while (current) {
            if (current->getElement() == nimi) {
                return current;
            }
            current = current->getJargmine();
        }
        return nullptr;
    }

    void deleteElement(const string& nimi) {
        Node<T>* current = pea;
        Node<T>* previous = nullptr;

        while (current && current->getElement() != nimi) {
            previous = current;
            current = current->getJargmine();
        }

        if (!current) return; // Elementi ei leitud

        if (!previous) {
            pea = current->getJargmine();
        } else {
            previous->jargmine = current->getJargmine();
        }

        delete current;
        suurus--;
    }

    int getSize() const { return suurus; }

    void destroy() {
        while (pea) {
            Node<T>* temp = pea;
            pea = pea->getJargmine();
            delete temp;
        }
        suurus = 0;
    }

    void printList() const {
        Node<T>* current = pea;
        while (current) {
            cout << current->getElement() << " -> ";
            current = current->getJargmine();
        }
        cout << "NULL" << endl;
    }
};
