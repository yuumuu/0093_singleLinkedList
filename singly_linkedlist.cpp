// 0093_singleLinkedList
#include <iostream>
using namespace std;

class Node {
    public:
        int noMhs;
        Node *next;
};

class LinkedList {
    Node *START;

    public:
        LinkedList() {
            START = NULL;
        }

        void addNode() {
            int nim;
            cout << "\nMasukkan Nomor Mahasiswa: ";
            cin >> nim;

            Node *nodeBaru = new Node();
            nodeBaru->noMhs = nim;

            if (START == NULL || nim <= START->noMhs) {
                if (START != NULL && nim == START->noMhs) {
                    cout << "\nDuplikasi noMhs tidak diijinkan\n";
                    return;
                }
                nodeBaru->next = START;
                START = nodeBaru;
                return;
            }

            Node *previous = START;
            Node *current = START;

            while (current != NULL && nim >= current->noMhs) {
                if (nim == current->noMhs) {
                    cout << "\nDuplikasi noMhs tidak diijinkan\n";
                    return;
                }
                previous = current;
                current = current->next;
            }

            nodeBaru->next = current;
            previous->next = nodeBaru;
        }

        bool listEmpty() {
            return (START == NULL);
        }

        bool search(int nim, Node **previous, Node **current) {
            *previous = START;
            *current = START;

            while (*current != NULL && nim != (*current)->noMhs) {
                *previous = *current;
                *current = (*current)->next;
            }

            return (*current != NULL);
        }

        bool delNode(int nim) {
            Node *current, *previous;
            if (!search(nim, &previous, &current))
                return false;

            if (current == START)
                START = START->next;
            else
                previous->next = current->next;

            delete current;
            return true;
        }
};

int main() {
    return 0;
}