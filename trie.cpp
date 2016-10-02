#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node {
    public:
    Node* next[26];
    int count;
    bool end;
    
};

class Trie {
    public:
    Node *head;
    Trie() {
        head=new Node();
    }
    void add(string str,int index,Node *node);
    int find(string str,int index,Node *node);
};

void Trie::add(string str,int index,Node *node) {
    
    if(index < str.length()) {
        node->count++;
         cout << "Now in Index:" << index << endl; 
        cout << "Accessing next char" << str[index+1]-97 << endl;
        if(node->next[str[index+1]-97] == NULL) {
            cout << "Creating new " << str[index+1]-97 << endl;
            node->next[str[index+1]-97]=new Node();
        }
        cout << "Entering index" << index+1 << endl;
        add(str,index+1,node->next[str[index+1]-97]);
    }
    return ;
}

int Trie::find(string str,int index,Node *node) {
    if(index < str.length() -1 ) {
        cout << "Current index:" << index << " char" << str[index]-97 << "count:" << node->count << endl;
        if(node->next[str[index]-97] == NULL) {
            return 0;
        } 
        cout << "Entering index" << index+1 << endl;
        return find(str,index+1,node->next[str[index]-97]);
    } else if(index == str.length() -1 ) {
        return node->count;
    }
    return 0;
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N=0;
    string line,command,str;
    Trie *trie=new Trie();
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> command;
        cin >> str;
        cout << "Line Read:" << command << " " << str << " " ;
        if(command == "add") {
            cout << "ADD OPERATION" << endl;
            trie->add(str,-1,trie->head);
        } else if(command == "find") {
            cout << "FIND OPERATION" << endl;
            cout << trie->find(str,0,trie->head) << endl;
        }
    }
    return 0;
}
