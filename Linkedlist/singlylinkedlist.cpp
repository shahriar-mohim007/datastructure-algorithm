#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
Node* head = NULL;
void insertNode(int val)
{
 Node* newnode = new Node(val);
 if (head==NULL)
 {
     head = newnode;
     return;
 }
 Node* temp = head;
 while(temp->next!= NULL)
 {
    temp = temp->next;
 }
 temp->next = newnode;
}

void deleteNode(int val)
{
Node* currentNode = head;
Node* previousNode = NULL;
while (currentNode->data!=val)
{
  previousNode = currentNode;
  currentNode = currentNode->next;
}
if(currentNode == head)
{
    Node* temp = head;
    head = head->next;
    delete(temp);
}
else
{
    previousNode->next = currentNode->next;
    delete(currentNode);
}
}
void printlist()
{
Node* currentNode = head;
while(currentNode!=NULL)
{
    cout<<currentNode->data<<endl;
    currentNode = currentNode->next;
}
}

int main()
{
insertNode(1);
insertNode(2);
insertNode(3);
insertNode(4);
deleteNode(2);
printlist();
}
