#include<iostream>
using namespace std;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char data){
            this->data = data;
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie{
        TrieNode* root;
    public:
        Trie() {
            root = new TrieNode('\0'); // Initialize root with a dummy character
        }
        void insertUtil(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = true;
                return;
            }
            //assuming word is all CAPS
            int index = word[0] - 'A';
            TrieNode* child;
            if(root->children[index] != NULL){
                //present
                child = root->children[index];
            }else{
                //absent
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }
            //next call
            insertUtil(child, word.substr(1));
        }
        void insert(string word){
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word){
            if(word.length() == 0){
                return root->isTerminal;
            }
            int index = word[0] - 'A';
            if(root->children[index]!=NULL){
                //present
                return searchUtil(root->children[index], word.substr(1));
            }else{
                return false;
            }
        }
        bool Search(string word){
            return searchUtil(root, word);
        }

        void deleteUtil(TrieNode* root, string word){
            if(word.length() == 0){
                root->isTerminal = false;
                return;
            }
            int index = word[0] - 'A';
            TrieNode* child;
            if(root->children[index]!=NULL){
                //present
                child = root->children[index];
            }else{
                return;
            }
            deleteUtil(child, word.substr(1));
        }
        void deleteWord(string word){
            deleteUtil(root, word);
        }
};



int main(){
    Trie t;
    t.insert("ABCD");
    t.insert("ABCDE");
    t.insert("ABCDEF");
    t.deleteWord("ABCD");
    bool present = t.Search("ABCD");
    cout<<present<<" "<<endl;
    return 1;
}