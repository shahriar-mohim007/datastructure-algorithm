#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int EoW;
    Node* children[26];

    Node() {
        EoW = 0;
        for (int i = 0; i < 26; i++) {
            this->children[i] = NULL;
        }
    }
};

void trie_insert(Node* root, string s) {
    Node* curr = root;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if (curr->children[id] == NULL) {
            curr->children[id] = new Node();
        }
        curr = curr->children[id];
    }
    curr->EoW = 1;
}

bool trie_search(Node* root, string s) {
    Node* curr = root;
    for (int i = 0; i < s.size(); i++) {
        int id = s[i] - 'a';
        if (curr->children[id] == NULL) {
            return false;
        }
        curr = curr->children[id];
    }
    return curr->EoW;
}

void printTRIE(Node* root, string current = "") {
    if (root->EoW) {
        cout << current << endl;
    }
    for (int i = 0; i < 26; i++) {
        if (root->children[i] != NULL) {

            char ch = 'a' + i;
            cout<<ch<<endl;
            printTRIE(root->children[i], current + ch);
        }
    }
}

int main() {
    Node* root = new Node();

    while (1) {
        cout << "1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. End" << endl << endl;
        int choice;
        string x;
        cin >> choice;
        if (choice == 1) {
            cout << "Insert String: ";
            cin >> x;
            trie_insert(root, x);
            cout << x << " is inserted in the trie" << endl;
        }
        else if (choice == 2) {
            cout << "Enter string to search: ";
            cin >> x;
            if (trie_search(root, x)) {
                cout << x << " FOUND " << endl;
            }
            else {
                cout << x << " NOT FOUND " << endl;
            }
        }
        else if (choice == 3) {
            cout << "Not yet implemented." << endl;
        }
        else if (choice == 4 || choice == 5) {
            cout << "Words in the Trie:" << endl;
            printTRIE(root);
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid Choice" << endl;
            break;
        }
        cout << endl;
    }

    return 0;
}
