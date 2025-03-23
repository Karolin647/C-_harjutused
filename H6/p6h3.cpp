#include "p6h3.h"

int main() {
    LinkedList<Node<string>> list;

    list.addElement("Alice");
    list.addElement("Bob");
    list.addElement("Charlie");
    
    cout << "List after adding elements:" << endl;
    list.printList();
    
    cout << "Size: " << list.getSize() << endl;

    Node<string>* found = list.searchElement("Bob");
    if (found) {
        cout << "Found element: " << found->getElement() << endl;
    } else {
        cout << "Element not found" << endl;
    }

    list.deleteElement("Bob");
    cout << "List after deleting 'Bob':" << endl;
    list.printList();
    
    cout << "Size: " << list.getSize() << endl;

    list.destroy();
    cout << "List after destruction:" << endl;
    list.printList();
    
    return 0;
}