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
        }
};

int main() {
    return 0;
}