#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int EoW;
Node* children[26];
Node()
{
 EoW = 0;
 for(int i=0;i<26;i++)
 {
   this->children[i] = NULL;
 }   
}
};

void trie_insert(Node* root,string s)
{
    Node* curr = root;
    for(int i=0;i<s.size();i++)
    {
     int id = s[i] - 'a';
     if(curr->children[id]==NULL)
     {
        curr->children[id] = new Node();

     }
     curr = curr->children[id];
    }
     curr->EoW =1;

}  

bool trie_search(Node* root,string s)
{
    Node* curr = root;
    for(int i=0;i<s.size();i++)
    {
        int id = s[i] - 'a';
        if(curr->children[id]==NULL)
        {
            return false;
        }
        curr=curr->children[id];
    }
    return curr->EoW;

}

void printTrie(Node* root,string current = "")
{
    if(root->EoW){
        cout<<current<<endl;
    }
    for(int i=0;i<26;i++)
    {
        if(root->children[i]!=NULL)
        {
            char ch =  'a' + i;
            cout<<ch<<endl;
            printTrie(root->children[i],current+ch);
        }

    }
}



int main()
{
Node* root = new Node();
string x;
cin>>x;

trie_insert(root,x);
cout<<trie_search(root,x)<<endl;
printTrie(root);
}